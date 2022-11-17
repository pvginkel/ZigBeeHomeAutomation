#include "Zigbee.h"

#define IS_COMMAND(c, n) (c.getCommand()[0] == n[0] && c.getCommand()[1] == n[1])

template <class T>
T packArray(uint8_t* val) {
	T res = 0;
	for (int i = 0; i < sizeof(T); i++) {
		res = res << 8 | val[i];
	}
	return res;
}

Zigbee::Zigbee() {
}

void Zigbee::begin(Stream& stream) {
	_xbee.onAtCommandResponse(atCommandCallbackThunk, (uintptr_t)this);

	_xbee.begin(stream);

	retrieveConfiguration();
}

void Zigbee::performReset() {
	_state = STATE_RESETTING;

	setCommandBuilder(buildResetCommand);
	sendCurrentCommand();
}

void Zigbee::setCommandBuilder(command_builder_t commandBuilder) {
	_commandBuilder = commandBuilder;
	_commandBuilderOffset = 0;
}

void Zigbee::loop() {
	_xbee.loop();

	// Retry any pending at command.

	if (_commandBuilder) {
		if (millis() - _lastSendMillis > AT_COMMAND_RETRY_MS) {
			LOG("Retrying...");
			sendCurrentCommand();
		}
	}

	// Refresh association indication.

	if (_state == STATE_RETRIEVING_ASSOCIATION_INDICATION) {
		const time_t currentMillis = millis();
		if (!_associationIndicationMillis || currentMillis - _associationIndicationMillis > ASSOCIATION_INDICATION_REFRESH_MS) {
			_associationIndicationMillis = currentMillis;

			auto command = associationIndicationCommand();
			_xbee.send(command);
		}
	}
}

bool Zigbee::sendNextCommand() {
	if (!_commandBuilder) {
		return false;
	}

	auto command = _commandBuilder(++_commandBuilderOffset);
	if (!command.getCommand()) {
		_commandBuilder = nullptr;
		_commandBuilderOffset = 0;
		return false;
	}

	sendCurrentCommand();

	return true;
}

void Zigbee::sendCurrentCommand() {
	auto command = _commandBuilder(_commandBuilderOffset);

	LOG("Sending command ", (char)command.getCommand()[0], (char)command.getCommand()[1]);

	_lastSendMillis = millis();
	_xbee.send(command);
}

void Zigbee::atCommandCallback(AtCommandResponse& command) {
	LOG("Command response ", command.getStatus() == AT_OK ? "OK" : "ERROR");

	for (int i = 0; i < command.getValueLength(); i++) {
		LOG("Value [", i, "] = ", command.getValue()[i], " 0x", String(command.getValue()[i], HEX));
	}

	if (IS_COMMAND(command, "SH")) {
		_macAddr.setMsb(packArray<uint32_t>(command.getValue()));
	}
	else if (IS_COMMAND(command, "SL")) {
		_macAddr.setLsb(packArray<uint32_t>(command.getValue()));
	}
	else if (IS_COMMAND(command, "MY")) {
		_netAddr = packArray<uint16_t>(command.getValue());
	}
	else if (IS_COMMAND(command, "AI")) {
		_associationIndication = command.getValue()[0];
		LOG("Assocation indication is now: ", getAssociationIndicationDescription(_associationIndication));
	}

	if (sendNextCommand()) {
		return;
	}

	if (_state == STATE_RESETTING) {
		retrieveConfiguration();
	}
	else if (_state == STATE_RETRIEVING_CONFIGURATION) {
		retrieveAssociationIndication();
	}
}

void Zigbee::retrieveAssociationIndication() {
	_state = STATE_RETRIEVING_ASSOCIATION_INDICATION;
	_associationIndicationMillis = millis();

	LOG("Requesting association indication");

	auto command = associationIndicationCommand();
	_xbee.send(command);
}

void Zigbee::retrieveConfiguration() {
	LOG("Retrieving configuration");

	_state = STATE_RETRIEVING_CONFIGURATION;

	setCommandBuilder(buildRetrieveConfigurationCommand);
	sendCurrentCommand();
}

const char* Zigbee::getAssociationIndicationDescription(uint8_t associationIndication) {
	switch (associationIndication) {
	case 0x00: return "Successfully formed or joined a network. (Coordinators form a network, routers and end devices join a network.)";
	case 0x21: return "Scan found no PANs";
	case 0x22: return "Scan found no valid PANs based on current SC and ID settings";
	case 0x23: return "Valid Coordinator or Routers found, but they are not allowing joining (NJ expired)";
	case 0x24: return "No joinable beacons were found";
	case 0x25: return "Unexpected state, node should not be attempting to join at this time";
	case 0x27: return "Node Joining attempt failed (typically due to incompatible security settings)";
	case 0x2A: return "Coordinator Start attempt failed";
	case 0x2B: return "Checking for an existing coordinator";
	case 0x2C: return "Attempt to leave the network failed";
	case 0xAB: return "Attempted to join a device that did not respond.";
	case 0xAC: return "Secure join error - network security key received unsecured";
	case 0xAD: return "Secure join error - network security key not received";
	case 0xAF: return "Secure join error - joining device does not have the right preconfigured link key";
	case 0xFF: return "Scanning for a ZigBee network (routers and end devices)";
	default: return nullptr;
	}
}
