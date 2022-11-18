#include "ZHA_DeviceManager.h"
#include "Esp8266.h"
#include "support.h"
#include "Zcl.h"

using namespace Zcl;

#define IS_COMMAND(c, n) ((c).getCommand()[0] == (n)[0] && (c).getCommand()[1] == (n)[1])
AT_BUILDER(associationIndicationCommand, "AI");

ZHA_DeviceManager::ZHA_DeviceManager() : _addr64(0), _bcast64(0), _addr16(0), _buffer(_payload) {
	//    onResponse(printResponseCb, (uintptr_t) (Print * ) & Serial);
	_device.onZBExplicitRxResponse(explicitRxCallbackThunk, (uintptr_t)this);
	_device.onModemStatusResponse(modemStatusCallbackThunk, (uintptr_t)this);
	_device.onAtCommandResponse(atCommandCallbackThunk, (uintptr_t)this);
#if LOG_ERROR
	_device.onPacketError(printErrorCb, (uintptr_t)(Print*)&Serial);
#endif
}

/* Send the device announce command */
void ZHA_DeviceManager::sendAnnounce() {
	DEBUG("Sending announce");

	uint8_t capability = 0b00001000; /* For now, just receiver on during idle times */
	uint8_t announce_cluster = 0x13;
	_payload[0] = _device.getNextFrameId();
	unpackArrayLe(&_payload[1], _addr16);
	unpackArrayLe(&_payload[3], _addr64.getLsb());
	unpackArrayLe(&_payload[7], _addr64.getMsb());
	_payload[11] = capability;

	ZBExplicitTxRequest announce(_bcast64, 0xFFFC, 0, 0, (uint8_t*)&_payload, 12, _payload[0], 0, 0, announce_cluster, 0);
	_device.send(announce);
}

ZHA_Device* ZHA_DeviceManager::getDeviceByEndpoint(uint8_t endpointId) {
	for (auto i = 0; i < _deviceList.size(); i++) {
		if (endpointId == _deviceList.get(i)->getEndpointId()) {
			return _deviceList.get(i);
		}
	}
	return nullptr;
}

void ZHA_DeviceManager::processZDO(XBeeAddress64 dst64, uint16_t dst16, uint16_t clusterId, uint8_t* frameData, uint8_t frameDataLength) {
	if (clusterId == ZDO_SIMPLE_DESCRIPTOR_REQUEST) {
		DEBUG("ZDO Simple Descriptor Request");

		ZHA_Device* dev = getDeviceByEndpoint(frameData[3]);
		if (dev) {
			uint8_t numInClusters = dev->getNumInClusters();
			uint8_t numOutClusters = dev->getNumOutClusters();
			_payloadLength = 12;
			_payload[0] = frameData[0];
			_payload[1] = STATUS_SUCCESS;
			unpackArrayLe(&_payload[2], _addr16);
			_payload[5] = dev->getEndpointId();
			unpackArrayLe(&_payload[6], (uint16_t)0x0104);
			unpackArrayLe(&_payload[8], (uint16_t)dev->getDeviceId());
			_payload[10] = 0x40;
			_payload[11] = numInClusters;
			for (uint8_t i = 0; i < numInClusters; i++) {
				unpackArrayLe(&_payload[_payloadLength], dev->getInCluster(i)->getClusterId());
				_payloadLength += 2;
			}
			_payload[_payloadLength] = numOutClusters;
			_payloadLength++;
			for (uint8_t i = 0; i < numOutClusters; i++) {
				unpackArrayLe(&_payload[_payloadLength], dev->getOutCluster(i)->getClusterId());
				_payloadLength += 2;
			}
			_payload[4] = _payloadLength - 5;
			ZBExplicitTxRequest SDR(dst64, dst16, 0, 0, (uint8_t*)&_payload, _payloadLength, _device.getNextFrameId(), 0, 0,
				ZDO_SIMPLE_DESCRIPTOR_RESPONSE, 0);
			_device.send(SDR);
		}
	}
	else if (clusterId == ZDO_ACTIVE_ENDPOINTS_REQUEST) {
		DEBUG("ZDO Active Endpoints Request");

		_payload[0] = frameData[0];
		_payload[1] = STATUS_SUCCESS;
		unpackArrayLe(&_payload[2], _addr16);
		_payload[4] = _deviceList.size();
		for (auto i = 0; i < _deviceList.size(); i++) {
			_payload[5 + i] = _deviceList.get(i)->getEndpointId();
		}
		_payloadLength = 5 + _deviceList.size();
		ZBExplicitTxRequest endpoints(dst64, dst16, 0, 0, (uint8_t*)&_payload, _payloadLength, _device.getNextFrameId(), 0, 0,
			ZDO_ACTIVE_ENDPOINTS_RESPONSE, 0);

		_device.send(endpoints);
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
		_payload[0] = frameData[0];
		_payload[1] = STATUS_SUCCESS;
		unpackArrayLe(&_payload[2], _addr16);
		_payload[4] = 0;
		ZBExplicitTxRequest endpoints(dst64, dst16, 0, 0, (uint8_t*)&_payload, 5, _device.getNextFrameId(), 0, 0,
			(uint16_t)ZDO_MATCH_DESCRIPTOR_RESPONSE, 0);
		_device.send(endpoints);
	}
}

void ZHA_DeviceManager::atCommandCallback(AtCommandResponse& command) {
#if LOG_DEBUG
	printResponseCb(command, (uintptr_t)(Print*)&Serial);
#endif

	if (IS_COMMAND(command, "SH")) {
		_addr64.setMsb(packArray<uint32_t>(command.getValue()));
	}
	else if (IS_COMMAND(command, "SL")) {
		_addr64.setLsb(packArray<uint32_t>(command.getValue()));
	}
	else if (IS_COMMAND(command, "MY")) {
		_addr16 = packArray<uint16_t>(command.getValue());
	}
	else if (IS_COMMAND(command, "AI")) {
		_associationIndication = command.getValue()[0];
		DEBUG("Association indication is now: ", getAssociationIndicationDescription(_associationIndication));

		if (_display) {
			_display->setConnected(_associationIndication == 0);
			if (_associationIndication) {
				auto message = getShortAssociationIndicationDescription(_associationIndication);
				if (message) {
					_display->setMessage(message);
				}
				else {
					_display->setMessage("Unknown status 0x" + String(_associationIndication, HEX));
				}
			}
			else {
				_display->setMessage("");
			}
		}

		if (_state == STATE_RETRIEVING_ASSOCIATION_INDICATION && _associationIndication == 0) {
			retrieveConfiguration();
			return;
		}
	}

	if (sendNextCommand()) {
		return;
	}

	if (_state == STATE_RESETTING) {
		retrieveAssociationIndication();
	}
	else if (_state == STATE_RETRIEVING_CONFIGURATION) {
		_state = STATE_CONNECTED;

		sendAnnounce();
	}
}

void ZHA_DeviceManager::modemStatusCallback(ModemStatusResponse& status) {

	switch (status.getStatus()) {
		case HARDWARE_RESET:
			DEBUG("Modem reset.");
			break;
		case ASSOCIATED:
			DEBUG("Joined network.");
			if (_state == STATE_CONNECTED) {
				setCommandBuilder(buildReadDiagnosticsCommand);
				sendAnnounce();
			}
			break;
		case DISASSOCIATED:
			if (_display) {
				_display->setMessage("Disassociated");
			}
			break;
		default:
#if LOG_DEBUG
			printResponseCb(status, (uintptr_t)(Print*)&Serial);
#endif
			break;
	}
}

void ZHA_DeviceManager::explicitRxCallback(ZBExplicitRxResponse& resp) {
#if LOG_DEBUG
	printResponseCb(resp, (uintptr_t)(Print*)&Serial);
#endif

	uint16_t profileId = resp.getProfileId();
	uint16_t clusterId = resp.getClusterId();
	uint8_t srcEndpoint = resp.getSrcEndpoint();
	uint8_t dstEndpoint = resp.getDstEndpoint();
	uint8_t* frameData = resp.getFrameData() + resp.getDataOffset();
	int frameDataLength = resp.getFrameDataLength() - resp.getDataOffset();

	auto frameBuffer = Buffer(resp.getFrameData() + resp.getDataOffset(), resp.getFrameDataLength() - resp.getDataOffset());

	//DEBUG("profileId ", profileId, " srcEndpoint ", srcEndpoint, " dstEndpoint ", dstEndpoint, " clusterId ", clusterId, " remote addr ", resp.getRemoteAddress16());

	if (profileId == 0x0000 && srcEndpoint == 0x00 && dstEndpoint == 0x00) {
		/* ZDO command */
		processZDO(resp.getRemoteAddress64(), resp.getRemoteAddress16(), clusterId, frameData,
			frameDataLength);
	}
	else if (profileId == ZHA_PROFILE_ID) {
		ZHA_Device* device = getDeviceByEndpoint(dstEndpoint);
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

			auto request = Frame(frameBuffer);

			if (request.frameControl().frameType() == FrameType::Global) {
		        DEBUG("General command");

				if (device->processGeneralCommand(frameBuffer, resp, _buffer)) {
					ZBExplicitTxRequest message(
						resp.getRemoteAddress64(),
						resp.getRemoteAddress16(),
						0, // broadcastRadius
						0, // option
						(uint8_t*)&_payload,
						_buffer.length(),
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
				auto result = cluster->processCommand(frameBuffer);

				DEBUG("Sending result for cluster specific command: ", String((int)result, HEX));

				auto response = new DefaultResponseFrame(_buffer);

				response->frameControl(FrameControl(FrameType::Global, Direction::ToClient));
				response->transactionSequenceNumber(request.transactionSequenceNumber());
				response->commandIdentifier(CommandIdentifier::DefaultResponse);
				response->commandId(frameBuffer.get(2));
				response->status(result);

				ZBExplicitTxRequest message(
					resp.getRemoteAddress64(),
					resp.getRemoteAddress16(),
					0, // broadcastRadius
					0, // option
					_buffer.data(),
					response->length(),
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

void ZHA_DeviceManager::reportAttributes() {
	for (auto devs = 0; devs < _deviceList.size(); devs++) {
		auto dev = _deviceList.get(devs);
		for (auto ics = 0; ics < dev->getNumInClusters(); ics++) {
			auto ic = dev->getInCluster(ics);
			for (auto ats = 0; ats < ic->numAttributes(); ats++) {
				auto at = ic->getAttrByIndex(ats);
				if (at->isUnreported()) {
					DEBUG("Reporting attribute endpoint ", dev->getEndpointId(), " cluster ", ic->getClusterId(), " attribute ", at->getAttrId(), " value ", at->toString());

					auto response = ReportAttributesFrame(_buffer);
					response.frameControl(FrameControl(FrameType::Global, Direction::ToClient, true));
					response.transactionSequenceNumber(0);
					response.commandIdentifier(CommandIdentifier::ReportAttributes);
					response.appendAttribute(at->getAttrId(), at->dataType());
					at->writeValue(response);

					ZBExplicitTxRequest message(
						_bcast64,
						_bcast16,
						0, // broadcastRadius
						0, // option
						(uint8_t*)&_payload,
						response.length(),
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

void ZHA_DeviceManager::addDevice(ZHA_Device* dev) {
	_deviceList.add(dev);
}

void ZHA_DeviceManager::setDisplay(Display& display) {
	_display = &display;
	updateDisplay();
}

void ZHA_DeviceManager::begin(Stream& stream) {
	_device.begin(stream);

	retrieveConfiguration();
}

void ZHA_DeviceManager::performReset() {
	_state = STATE_RESETTING;

	setCommandBuilder(buildResetCommand);
}

void ZHA_DeviceManager::setCommandBuilder(command_builder_t commandBuilder) {
	_commandBuilder = commandBuilder;
	_commandBuilderOffset = 0;

	sendCurrentCommand();
}

void ZHA_DeviceManager::loop() {
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

	if (_state == STATE_RETRIEVING_ASSOCIATION_INDICATION) {
		const time_t currentMillis = millis();
		if (!_associationIndicationMillis || currentMillis - _associationIndicationMillis > ASSOCIATION_INDICATION_REFRESH_MS) {
			_associationIndicationMillis = currentMillis;

			auto command = associationIndicationCommand();
			_device.send(command);
		}
	}
}

bool ZHA_DeviceManager::sendNextCommand() {
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

void ZHA_DeviceManager::sendCurrentCommand() {
	auto command = _commandBuilder(_commandBuilderOffset);

	DEBUG("Sending command ", (char)command.getCommand()[0], (char)command.getCommand()[1]);

	_lastSendMillis = millis();
	_device.send(command);
}

void ZHA_DeviceManager::retrieveAssociationIndication() {
	_state = STATE_RETRIEVING_ASSOCIATION_INDICATION;
	_associationIndicationMillis = millis();

	DEBUG("Requesting association indication");

	auto command = associationIndicationCommand();
	_device.send(command);
}

void ZHA_DeviceManager::retrieveConfiguration() {
	DEBUG("Retrieving configuration");

	_state = STATE_RETRIEVING_CONFIGURATION;

	if (_display) {
		_display->setMessage("Connecting...");
	}

	setCommandBuilder(buildRetrieveConfigurationCommand);
}

const char* ZHA_DeviceManager::getAssociationIndicationDescription(uint8_t associationIndication) {
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

const char* ZHA_DeviceManager::getShortAssociationIndicationDescription(uint8_t associationIndication) {
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

void ZHA_DeviceManager::updateDisplay() {
	if (!_display) {
		return;
	}

}
