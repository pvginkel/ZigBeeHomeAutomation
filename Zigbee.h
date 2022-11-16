#pragma once

#include "arduino.h"
#include <XBee.h>
#include <SoftwareSerial.h>
#include <LinkedList.h>
#include "XBeeConfig.h"
#include "support.h"

class Zigbee
{
	static constexpr int STATE_CONNECTED = 0;
	static constexpr int STATE_RESETTING = 1;
	static constexpr int STATE_RETRIEVING_CONFIGURATION = 2;
	static constexpr int STATE_RETRIEVING_ASSOCIATION_INDICATION = 3;
	static constexpr int AT_COMMAND_RETRY_MS = 1000;
	static const uint8_t ASSOCIATION_INDICATION[];
	static constexpr int ASSOCIATION_INDICATION_REFRESH_MS = 1000;

	static void atCommandCallbackThunk(AtCommandResponse& command, uintptr_t data) {
		((Zigbee*)data)->atCommandCallback(command);
	}

	XBeeWithCallbacks _xbee;
	LinkedList<AtCommandRequest> _commands;
	int _state;
	XBeeAddress64 _macAddr;
	uint16_t _netAddr;
	AtCommandRequest _lastSend;
	time_t _lastSendMillis;
	uint8_t _associationIndication;
	time_t _associationIndicationMillis;

public:
	void begin(Stream& stream) {
		_xbee.onAtCommandResponse(atCommandCallbackThunk, (uintptr_t)this);

		_xbee.begin(stream);

		retrieveConfiguration();
	}

	void performReset() {
		_state = STATE_RESETTING;

		_commands.clear();
		buildResetCommands(_commands);

		sendNextCommand();
	}

	void loop() {
		_xbee.loop();

		// Retry any pending at command.

		if (_lastSend.getCommand()) {
			const auto currentMillis = millis();
			if (currentMillis - _lastSendMillis > AT_COMMAND_RETRY_MS) {
				LOG("Retrying ", (char)_lastSend.getCommand()[0], (char)_lastSend.getCommand()[1]);
				sendAtCommand(_lastSend);
			}
		}

		// Refresh association indication.

		if (_state == STATE_RETRIEVING_ASSOCIATION_INDICATION) {
			const time_t currentMillis = millis();
			if (!_associationIndicationMillis || currentMillis - _associationIndicationMillis > ASSOCIATION_INDICATION_REFRESH_MS) {
				_associationIndicationMillis = currentMillis;

				auto command = AtCommandRequest((uint8_t*)ASSOCIATION_INDICATION);
				sendAtCommand(command);
			}
		}
	}

private:
	bool sendNextCommand() {
		if (_commands.size() == 0) {
			return false;
		}

		auto command = _commands.shift();
		sendAtCommand(command);

		return true;
	}

	void atCommandCallback(AtCommandResponse& command) {
		_lastSend = AtCommandRequest();

		LOG("Command response ", command.getStatus() == AT_OK ? "OK" : "ERROR");

		for (int i = 0; i < command.getValueLength(); i++) {
			LOG("Value [", i, "] = ", command.getValue()[i], " 0x", String(command.getValue()[i], HEX));
		}

		if (command.getCommand()[0] == 'S' && command.getCommand()[1] == 'H') {
			_macAddr.setMsb(packArray<uint32_t>(command.getValue()));
		}
		else if (command.getCommand()[0] == 'S' && command.getCommand()[1] == 'L') {
			_macAddr.setLsb(packArray<uint32_t>(command.getValue()));
		}
		else if (command.getCommand()[0] == 'M' && command.getCommand()[1] == 'Y') {
			_netAddr = packArray<uint16_t>(command.getValue());
		}
		else if (command.getCommand()[0] == 'A' && command.getCommand()[1] == 'I') {
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

	void retrieveAssociationIndication() {
		_state = STATE_RETRIEVING_ASSOCIATION_INDICATION;
		_associationIndicationMillis = millis();

		auto command = AtCommandRequest((uint8_t*)ASSOCIATION_INDICATION);
		sendAtCommand(command);
	}

	void sendAtCommand(AtCommandRequest& command) {
		LOG("Sending command ", (char)command.getCommand()[0], (char)command.getCommand()[1]);

		_lastSend = command;
		_lastSendMillis = millis();
		_xbee.send(_lastSend);
	}

	template <class T>
	T packArray(uint8_t* val) {
		T res = 0;
		for (int i = 0; i < sizeof(T); i++) {
			res = res << 8 | val[i];
		}
		return res;
	}

	void retrieveConfiguration() {
		LOG("Retrieving configuration");

		_state = STATE_RETRIEVING_CONFIGURATION;
		_commands.clear();
		buildRetrieveConfigurationCommands(_commands);

		sendNextCommand();
	}

	static const char* getAssociationIndicationDescription(uint8_t associationIndication) {
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
};
