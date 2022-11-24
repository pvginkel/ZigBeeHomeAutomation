#include "DeviceManager.h"
#include "Esp8266.h"
#include "support.h"
#include "Printers.h"

#define IS_COMMAND(c, n) ((c).getCommand()[0] == (n)[0] && (c).getCommand()[1] == (n)[1])

static AtCommandRequest buildResetCommand(int index);
static AtCommandRequest buildRetrieveConfigurationCommand(int index);
static AtCommandRequest buildReadDiagnosticsCommand(int index);
static AtCommandRequest associationIndicationCommand();

DeviceManager::DeviceManager() : _address(0), _shortAddress(0), _broadcastAddress(0), _buffer(_payload) {
	//    onResponse(printResponseCb, (uintptr_t) (Print * ) & Serial);
	_device.onZBExplicitRxResponse(explicitRxCallbackThunk, (uintptr_t)this);
	_device.onModemStatusResponse(modemStatusCallbackThunk, (uintptr_t)this);
	_device.onAtCommandResponse(atCommandCallbackThunk, (uintptr_t)this);
#if LOG_ERROR
	_device.onPacketError(printErrorCb, (uintptr_t)(Print*)&Serial);
#endif
}

/* Send the device announce command */
void DeviceManager::sendAnnounce() {
	DEBUG("Sending announce");

	auto frameId = _device.getNextFrameId();

	uint8_t capability = 0b00001000; /* For now, just receiver on during idle times */
	uint8_t announce_cluster = 0x13;
	Memory memory(_payload, 0);
	memory.writeUInt8(frameId);
	memory.writeUInt16Le(_shortAddress);
	memory.writeUInt32Le(_address.getLsb());
	memory.writeUInt32Le(_address.getMsb());
	memory.writeUInt8(capability);

	ZBExplicitTxRequest announce(
		_broadcastAddress,
		0xFFFC,
		0,
		0,
		memory.getData(),
		memory.getPosition(),
		frameId,
		0,
		0,
		announce_cluster,
		0
	);
	_device.send(announce);
}

Device* DeviceManager::getDeviceByEndpoint(uint8_t endpointId) {
	for (auto i = 0; i < _deviceList.size(); i++) {
		if (endpointId == _deviceList.get(i)->getEndpointId()) {
			return _deviceList.get(i);
		}
	}
	return nullptr;
}

void DeviceManager::processZDO(XBeeAddress64 dst64, uint16_t dst16, uint16_t clusterId, uint8_t* frameData, uint8_t frameDataLength) {
	if (clusterId == ZDO_SIMPLE_DESCRIPTOR_REQUEST) {
		DEBUG("ZDO Simple Descriptor Request");

		Device* dev = getDeviceByEndpoint(frameData[3]);
		if (dev) {
			uint8_t numInClusters = dev->getInClusterCount();
			uint8_t numOutClusters = dev->getOutClusterCount();
			Memory memory(_payload);
			memory.writeUInt8(frameData[0]);
			memory.writeUInt8((uint8_t)Status::Success);
			memory.writeUInt16Le(_shortAddress);
			auto lengthPosition = memory.getPosition();
			memory.writeUInt8(0);
			memory.writeUInt8(dev->getEndpointId());
			memory.writeUInt16Le((uint16_t)0x0104);
			memory.writeUInt16Le(dev->getDeviceId());
			memory.writeUInt8(0x40);
			memory.writeUInt8(numInClusters);
			for (uint8_t i = 0; i < numInClusters; i++) {
				memory.writeUInt16Le(dev->getInCluster(i)->getClusterId());
			}
			memory.writeUInt8(numOutClusters);
			for (uint8_t i = 0; i < numOutClusters; i++) {
				memory.writeUInt16Le(dev->getOutCluster(i)->getClusterId());
			}
			auto length = memory.getPosition();
			memory.setPosition(lengthPosition);
			memory.writeUInt8(length - 5);

			ZBExplicitTxRequest message(
				dst64,
				dst16,
				0,
				0,
				memory.getData(),
				length,
				_device.getNextFrameId(),
				0,
				0,
				ZDO_SIMPLE_DESCRIPTOR_RESPONSE,
				0
			);
			_device.send(message);
		}
	}
	else if (clusterId == ZDO_ACTIVE_ENDPOINTS_REQUEST) {
		DEBUG("ZDO Active Endpoints Request");

		Memory memory(_payload);

		memory.writeUInt8(frameData[0]);
		memory.writeUInt8((uint8_t)Status::Success);
		memory.writeUInt16Le(_shortAddress);
		memory.writeUInt8(_deviceList.size());
		for (auto i = 0; i < _deviceList.size(); i++) {
			memory.writeUInt8(_deviceList.get(i)->getEndpointId());
		}

		ZBExplicitTxRequest message(
			dst64,
			dst16,
			0,
			0,
			memory.getData(),
			memory.getPosition(),
			_device.getNextFrameId(),
			0,
			0,
			ZDO_ACTIVE_ENDPOINTS_RESPONSE,
			0
		);
		_device.send(message);
	}
	else if (clusterId == ZDO_MATCH_DESCRIPTOR_REQUEST) {
		DEBUG("ZDO Match Descriptor Request");

		uint16_t profile_id = ((uint16_t)frameData[4] << 8) | frameData[3];
		uint8_t numInClusters = frameData[5];
		for (uint8_t i = 1; i <= numInClusters; i++) {
			uint16_t cluster = ((uint16_t)frameData[5 + 2 * i] << 8) | frameData[4 + (2 * i)];
			Serial.println(cluster, HEX);
		}
		uint8_t numOutClusters = frameData[6 + 2 * numInClusters];
		for (uint8_t i = 1; i <= numOutClusters; i++) {
			uint16_t cluster =
				((uint16_t)frameData[7 + 2 * (i + numInClusters)] << 8) | frameData[6 + 2 * (i + numInClusters)];
			Serial.println(cluster, HEX);
		}

		Memory memory(_payload);

		memory.writeUInt8(frameData[0]);
		memory.writeUInt8((uint8_t)Status::Success);
		memory.writeUInt16Le(_shortAddress);
		memory.writeUInt8(0);

		ZBExplicitTxRequest message(
			dst64,
			dst16,
			0,
			0,
			memory.getData(),
			memory.getPosition(),
			_device.getNextFrameId(),
			0,
			0,
			ZDO_MATCH_DESCRIPTOR_RESPONSE,
			0
		);
		_device.send(message);
	}
}

void DeviceManager::atCommandCallback(AtCommandResponse& command) {
#if LOG_DEBUG
	printResponseCb(command, (uintptr_t)(Print*)&Serial);
#endif

	Memory memory(command.getValue(), command.getValueLength());

	if (IS_COMMAND(command, "SH")) {
		_address.setMsb(memory.readUInt32Be());
	}
	else if (IS_COMMAND(command, "SL")) {
		_address.setLsb(memory.readUInt32Be());
	}
	else if (IS_COMMAND(command, "MY")) {
		_shortAddress = memory.readUInt16Be();
	}
	else if (IS_COMMAND(command, "AI")) {
		_associationIndication = memory.readUInt8();
		DEBUG("Association indication is now: ", getAssociationIndicationDescription(_associationIndication));

		setConnected(_associationIndication == 0 ? ConnectionStatus::Connected : ConnectionStatus::Connecting);

		if (_associationIndication) {
			auto message = getShortAssociationIndicationDescription(_associationIndication);
			if (message) {
				setStatus(message);
			}
			else {
				setStatus("Unknown status 0x" + String(_associationIndication, HEX));
			}
		}
		else {
			setStatus("");
		}

		if (_state == State::RetrievingAssociationIndication && _associationIndication == 0) {
			retrieveConfiguration();
			return;
		}
	}

	if (sendNextCommand()) {
		return;
	}

	if (_state == State::Resetting) {
		retrieveAssociationIndication();
	}
	else if (_state == State::RetrievingConfiguration) {
		_state = State::Connected;

		sendAnnounce();
	}
}

void DeviceManager::modemStatusCallback(ModemStatusResponse& status) {

	switch (status.getStatus()) {
		case HARDWARE_RESET:
			DEBUG("Modem reset.");
			break;
		case ASSOCIATED:
			DEBUG("Joined network.");
			if (_state == State::Connected) {
				setCommandBuilder(buildReadDiagnosticsCommand);
				sendAnnounce();
			}
			break;
		case DISASSOCIATED:
			setStatus("Disassociated");
			break;
		default:
#if LOG_DEBUG
			printResponseCb(status, (uintptr_t)(Print*)&Serial);
#endif
			break;
	}
}

void DeviceManager::explicitRxCallback(ZBExplicitRxResponse& resp) {
#if LOG_DEBUG
	printResponseCb(resp, (uintptr_t)(Print*)&Serial);
#endif

	uint16_t profileId = resp.getProfileId();
	uint16_t clusterId = resp.getClusterId();
	uint8_t srcEndpoint = resp.getSrcEndpoint();
	uint8_t dstEndpoint = resp.getDstEndpoint();
	uint8_t* frameData = resp.getFrameData() + resp.getDataOffset();
	int frameDataLength = resp.getFrameDataLength() - resp.getDataOffset();

	auto frameBuffer = Memory(resp.getFrameData() + resp.getDataOffset(), resp.getFrameDataLength() - resp.getDataOffset());

	//DEBUG("profileId ", profileId, " srcEndpoint ", srcEndpoint, " dstEndpoint ", dstEndpoint, " clusterId ", clusterId, " remote addr ", resp.getRemoteAddress16());

	if (profileId == 0x0000 && srcEndpoint == 0x00 && dstEndpoint == 0x00) {
		/* ZDO command */
		processZDO(resp.getRemoteAddress64(), resp.getRemoteAddress16(), clusterId, frameData,
			frameDataLength);
	}
	else if (profileId == ZHA_PROFILE_ID) {
		Device* device = getDeviceByEndpoint(dstEndpoint);
		if (device) {
			/* Frame layout
		  ---------------------------------------------------------------------
		  |    Bits: 8     |   0/16   |    8     |    8       |   Variable    |
		  |-------------------------------------------------------------------|
		  | Frame Control  | MFR code | Frame ID | Command ID | Frame Payload |
		  Frame Control Field
		  ---------------------------------------------------------------------
		  --------------------------------------------------------------------------------
		  }  Bits: 3  |            1             |     1     |       1      |      2     |
		  |------------------------------------------------------------------------------|
		  | Reserverd | Disable Default Response | Direction | MFR specific | Frame Type |
		  --------------------------------------------------------------------------------
		*/
			auto request = Frame::read(frameBuffer);

			if (request.frameControl().frameType() == FrameType::Global) {
		        DEBUG("General command");

				if (device->processGeneralCommand(frameBuffer, resp, _buffer)) {
					ZBExplicitTxRequest message(
						resp.getRemoteAddress64(),
						resp.getRemoteAddress16(),
						0, // broadcastRadius
						0, // option
						(uint8_t*)&_payload,
						_buffer.getPosition(),
						_device.getNextFrameId(),
						dstEndpoint,
						srcEndpoint,
						clusterId,
						profileId
					);

					_device.send(message);
				}
			}
			if (request.frameControl().frameType() == FrameType::Cluster) {
		        DEBUG("Cluster specific command");

				auto cluster = device->getInClusterById(clusterId);
				auto commandId = frameBuffer.readUInt8();

				Frame(
					FrameControl(FrameType::Global, Direction::ToClient),
					request.transactionSequenceNumber(),
					CommandIdentifier::DefaultResponse
				).write(_buffer);

				_buffer.writeUInt8(commandId);

				cluster->processCommand(commandId, frameBuffer, _buffer);

				ZBExplicitTxRequest message(
					resp.getRemoteAddress64(),
					resp.getRemoteAddress16(),
					0, // broadcastRadius
					0, // option
					_buffer.getData(),
					_buffer.getPosition(),
					_device.getNextFrameId(),
					dstEndpoint,
					srcEndpoint,
					clusterId,
					profileId
				);

				_device.send(message);
			}	
		}
	}
}

void DeviceManager::reportAttributes() {
	for (auto devs = 0; devs < _deviceList.size(); devs++) {
		auto dev = _deviceList.get(devs);
		for (auto ics = 0; ics < dev->getInClusterCount(); ics++) {
			auto ic = dev->getInCluster(ics);
			for (auto ats = 0; ats < ic->getAttributeCount(); ats++) {
				auto at = ic->getAttributeByIndex(ats);
				if (at->isUnreported()) {
					DEBUG("Reporting attribute endpoint ", dev->getEndpointId(), " cluster ", ic->getClusterId(), " attribute ", at->getAttributeId(), " value ", at->toString());

					auto response = Frame::read(_buffer);
					response.frameControl(FrameControl(FrameType::Global, Direction::ToClient, true));
					response.transactionSequenceNumber(0);
					response.commandIdentifier(CommandIdentifier::ReportAttributes);
					ReportAttributesFrame::writeAttribute(_buffer, at->getAttributeId(), at->getDataType());
					at->write(_buffer);

					ZBExplicitTxRequest message(
						_broadcastAddress,
						_shortBroadcastAddress,
						0, // broadcastRadius
						0, // option
						(uint8_t*)&_payload,
						_buffer.getPosition(),
						_device.getNextFrameId(),
						dev->getEndpointId(),
						1, // destination endpoint
						ic->getClusterId(),
						ZHA_PROFILE_ID
					);
					_device.send(message);

					at->markReported();
				}
			}
		}
	}
}

void DeviceManager::addDevice(Device* dev) {
	_deviceList.add(dev);
}

void DeviceManager::addStatusCb(StatusCb& statusCb) {
	_statusCbs.add(&statusCb);
}

void DeviceManager::begin(Stream& stream) {
	_device.begin(stream);

	retrieveConfiguration();
}

void DeviceManager::performReset() {
	_state = State::Resetting;

	setCommandBuilder(buildResetCommand);
}

void DeviceManager::setCommandBuilder(command_builder_t commandBuilder) {
	_commandBuilder = commandBuilder;
	_commandBuilderOffset = 0;

	sendCurrentCommand();
}

void DeviceManager::update() {
	_device.loop();

	reportAttributes();

	esp8266_yield();

	// Retry any pending at command.

	if (_commandBuilder) {
		if (millis() - _lastSendMillis > AT_COMMAND_RETRY_MS) {
			DEBUG("Retrying...");
			sendCurrentCommand();
		}
	}

	// Refresh association indication.

	if (_state == State::RetrievingAssociationIndication) {
		const time_t currentMillis = millis();
		if (!_associationIndicationMillis || currentMillis - _associationIndicationMillis > ASSOCIATION_INDICATION_REFRESH_MS) {
			_associationIndicationMillis = currentMillis;

			auto command = associationIndicationCommand();
			_device.send(command);
		}
	}
}

bool DeviceManager::sendNextCommand() {
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

void DeviceManager::sendCurrentCommand() {
	auto command = _commandBuilder(_commandBuilderOffset);

	DEBUG("Sending command ", (char)command.getCommand()[0], (char)command.getCommand()[1]);

	_lastSendMillis = millis();
	_device.send(command);
}

void DeviceManager::retrieveAssociationIndication() {
	_state = State::RetrievingAssociationIndication;
	_associationIndicationMillis = millis();

	DEBUG("Requesting association indication");

	auto command = associationIndicationCommand();
	_device.send(command);
}

void DeviceManager::retrieveConfiguration() {
	DEBUG("Retrieving configuration");

	_state = State::RetrievingConfiguration;

	setStatus("Connecting...");

	setCommandBuilder(buildRetrieveConfigurationCommand);
}

void DeviceManager::setStatus(const String& status) {
	for (int i = 0; i < _statusCbs.size(); i++) {
		_statusCbs[i]->setStatus(status);
	}
}

void DeviceManager::setConnected(ConnectionStatus connected) {
	for (int i = 0; i < _statusCbs.size(); i++) {
		_statusCbs[i]->setConnected(connected);
	}
}

const char* DeviceManager::getAssociationIndicationDescription(uint8_t associationIndication) {
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

const char* DeviceManager::getShortAssociationIndicationDescription(uint8_t associationIndication) {
	switch (associationIndication) {
	case 0x21: return "No PANs found";
	case 0x22: return "No valid PANs found";
	case 0x23: return "Join time expired";
	case 0x24: return "No beacons found";
	case 0x25: return "Unexpected state";
	case 0x27: return "Join attempt failed";
	case 0x2A: return "Coordinator start failed";
	case 0x2B: return "Finding coordinator";
	case 0x2C: return "Leave network failed";
	case 0xAB: return "Device not responding";
	case 0xAC:
	case 0xAD:
	case 0xAF:
		return "Secure join error";
	case 0xFF: return "Scanning";
	default: return nullptr;
	}
}

#define AT_BUILDER(n, c, ...) \
	static AtCommandRequest n() { \
		static uint8_t value[] = { __VA_ARGS__ }; \
		return AtCommandRequest((uint8_t*)(c), (uint8_t*)value, ARRAY_LENGTH(value)); \
	}

#define AT_BUILDER_STR(n, c, v) \
	static AtCommandRequest n() { \
		return AtCommandRequest((uint8_t*)(c), (uint8_t*)(v), strlen(v)); \
	}

AT_BUILDER(restoreDefaultsCommand, "RE");
AT_BUILDER(apiOptionsCommand, "AO", 3);
AT_BUILDER(networkResetCommand, "NR", 0);
AT_BUILDER_STR(nodeIdentifierCommand, "NI", "TEST LAMP");
AT_BUILDER(zigbeeStackProfileCommand, "ZS", 2);
AT_BUILDER(nodeJoinTimeCommand, "NJ", 0x5A);
AT_BUILDER(encryptionEnableCommand, "EE", 1);
AT_BUILDER(encryptionOptionsCommand, "EO", 1);
AT_BUILDER(linkKeyCommand, "KY", 0x5A, 0x69, 0x67, 0x42, 0x65, 0x65, 0x41, 0x6C, 0x6C, 0x69, 0x61, 0x6E, 0x63, 0x65, 0x30, 0x39);
AT_BUILDER(dio6RtsCommand, "D6", 0);
AT_BUILDER(scanChannelsCommand, "SC", 0xff, 0xff);
AT_BUILDER(writeCommand, "WR");
AT_BUILDER(softwareResetCommand, "FR");
AT_BUILDER(serialNumberHighCommand, "SH");
AT_BUILDER(serialNumberLowCommand, "SL");
AT_BUILDER(networkAddressCommand, "MY");
AT_BUILDER(apiModeCommand, "AP", 2);
AT_BUILDER(operatingChannelCommand, "CH");
AT_BUILDER(operatingPanIdCommand, "OI");
AT_BUILDER(associationIndicationCommand, "AI");
AT_BUILDER(parentNetworkAddressCommand, "MP");

AtCommandRequest buildResetCommand(int index) {
	switch (index) {
	case 0: return restoreDefaultsCommand();
	case 1: return apiOptionsCommand();
	case 2: return networkResetCommand();
	case 3: return nodeIdentifierCommand();
	case 4: return zigbeeStackProfileCommand();
	case 5: return nodeJoinTimeCommand();
	case 6: return encryptionEnableCommand();
	case 7: return encryptionOptionsCommand();
	case 8: return linkKeyCommand();
	case 9: return dio6RtsCommand();
	case 10: return scanChannelsCommand();
	case 11: return apiModeCommand();
	case 12: return writeCommand();
	case 13: return softwareResetCommand();
	default: return {};
	}
}

AtCommandRequest buildRetrieveConfigurationCommand(int index) {
	switch (index) {
	case 0: return serialNumberHighCommand();
	case 1: return serialNumberLowCommand();
	case 2: return networkAddressCommand();
	case 3: return associationIndicationCommand();
	default: return {};
	}
}

AtCommandRequest buildReadDiagnosticsCommand(int index) {
	switch (index) {
	case 0: return associationIndicationCommand();
	case 1: return operatingChannelCommand();
	case 2: return operatingPanIdCommand();
	case 3: return parentNetworkAddressCommand();
	default: return {};
	}
}
