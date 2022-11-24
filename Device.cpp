#include "ZigBee.h"

Device::Device(uint8_t endpointId, uint16_t deviceId)
	: _endpointId(endpointId), _deviceId(deviceId) {
}

void Device::addInCluster(Cluster& cluster) {
	_inClusters.add(&cluster);
}

void Device::addOutCluster(Cluster& cluster) {
	_outClusters.add(&cluster);
}

int Device::getInClusterCount() {
	return _inClusters.size();
}

int Device::getOutClusterCount() {
	return _outClusters.size();
}

Cluster* Device::getInCluster(int index) {
	return _inClusters.get(index);
}

Cluster* Device::getOutCluster(int index) {
	return _outClusters.get(index);
}

uint8_t Device::getEndpointId() {
	return _endpointId;
}

uint16_t Device::getDeviceId() {
	return _deviceId;
}

Cluster* Device::getInClusterById(uint16_t clusterId) {
	for (uint8_t i = 0; i < _inClusters.size(); i++) {
		if (_inClusters.get(i)->getClusterId() == clusterId) {
			return _inClusters.get(i);
		}
	}
	return nullptr;
}

Cluster* Device::getOutClusterById(uint16_t clusterId) {
	for (uint8_t i = 0; i < _outClusters.size(); i++) {
		if (_outClusters.get(i)->getClusterId() == clusterId) {
			return _outClusters.get(i);
		}
	}
	return nullptr;
}

bool Device::processGeneralCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response) {
	auto commandIdentifier = (CommandIdentifier)frame.commandIdentifier();

	switch (commandIdentifier) {
		case CommandIdentifier::ReadAttributes:
			return processGeneralReadAttributesCommand(frame, request, message, response);
		case CommandIdentifier::DiscoverAttributes:
			return processGeneralDiscoverAttributesCommand(frame, request, message, response);
		case CommandIdentifier::ConfigureReporting:
			return processGeneralConfigureReportingCommand(frame, request, message, response);
		default:
			DEBUG(F("Received unimplemented command "), String((uint8_t)commandIdentifier, HEX));
			return false;
	}
}

bool Device::processGeneralReadAttributesCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response) {
	DEBUG(F("Reading attributes from cluster "), message.getClusterId());

	auto cluster = getInClusterById(message.getClusterId());

	Frame(
		FrameControl(FrameType::Global, Direction::ToClient, true),
		frame.transactionSequenceNumber(),
		(uint8_t)CommandIdentifier::ReadAttributesResponse
	).write(response);

	DEBUG(F("  Reading attributes"));

	uint16_t attributeId;
	while (ReadAttributesFrame::readNextAttributeId(request, attributeId)) {
		auto attribute = cluster->getAttributeById(attributeId);

		if (attribute) {
			DEBUG(F("  Attribute "), attributeId, F(" reporting "), attribute->toString());

			ReadAttributesResponseFrame::writeAttribute(response, attributeId, Status::Success, attribute->getDataType());

			attribute->write(response);
		}
		else {
			DEBUG(F("  Attribute "), attributeId, F(" unsupported"));

			ReadAttributesResponseFrame::writeAttribute(response, attributeId, Status::UnsupportedAttribute);
		}
	}

	DEBUG(F("  Done"));

	return true;
}

bool Device::processGeneralDiscoverAttributesCommand(Frame& frame, Memory& frameData, ZBExplicitRxResponse& message, Memory& buffer) {
	/*
	  Command
	  -----------------------------------------------------------
	  |  Bits: 24  |      Bits: 16      |        Bits: 8        |
	  |----------------------------------------------------------
	  | ZCL Header | Start Attribute ID | Maximum Attribute IDs |
	  -----------------------------------------------------------

	  Response payload
	  --------------------------------------------------------------------------------------------------
	  |  Bits: 24   |         8          |     Variable     |     Variable     | ... |     Variable     |
	  |-------------------------------------------------------------------------------------------------
	  | ZCL Header | Discovery Complete | Attribute Info 1 | Attribute Info 2 | ... | Attribute Info n |
	  --------------------------------------------------------------------------------------------------
	  Attribute Info
	  ----------------------------
	  |   Bits: 16   |     1     |
	  ----------------------------
	  | Attribute Id | Data Type |
	  ----------------------------
	*/

	auto cluster = getInClusterById(message.getClusterId());

	Frame(
		FrameControl(FrameType::Global, Direction::ToClient, true),
		frame.transactionSequenceNumber(),
		(uint8_t)CommandIdentifier::DiscoverAttributesResponse
	).write(buffer);

	// Write a temporary value and get back here at the end.

	auto position = buffer.getPosition();
	DiscoverAttributesResponseFrame(false).write(buffer);

	auto discoverAttributesFrame = DiscoverAttributesFrame::read(frameData);

	DEBUG(F("Discover attributes start "), discoverAttributesFrame.getStartAttributeId(), F(" maximum "), discoverAttributesFrame.getMaximumAttributeIds());

	auto index = cluster->getAttributeIndex(discoverAttributesFrame.getStartAttributeId());

	for (int i = 0; i < discoverAttributesFrame.getMaximumAttributeIds(); i++) {
		if (index == -1 || index >= cluster->getAttributeCount()) {
			DEBUG(F("  Discovery complete"));
			auto newPosition = buffer.getPosition();
			buffer.setPosition(position);
			DiscoverAttributesResponseFrame(true).write(buffer);
			buffer.setPosition(newPosition);
			break;
		}

		auto attribute = cluster->getAttributeByIndex(index++);

		DiscoverAttributesResponseFrame::writeAttribute(buffer, attribute->getAttributeId(), attribute->getDataType());

		DEBUG(F("  Reporting ID "), attribute->getAttributeId(), F(" data type "), String((int)attribute->getDataType(), HEX));
	}

	DEBUG(F("  Done"));
	return true;
}

bool Device::processGeneralConfigureReportingCommand(Frame& frame, Memory& frameData, ZBExplicitRxResponse& message, Memory& buffer) {

	/*
	  Command
	  --------------------------------------------------------------------------------------
	  |  Bits: 24  |      Variable       |      Variable       | ... |      Variable       |
	  |-------------------------------------------------------------------------------------
	  | ZCL Header |  Attribute Record 1 |  Attribute Record 2 | ... |  Attribute Record n |
	  --------------------------------------------------------------------------------------
	  Attribute Record
	  ----------------------------------------------------------------------------------------------------------------------------------------
	  |  Bits: 8  |     16       |    0/8    |           0/16             |            0/16            |     0/Variable     |      0/16      |
	  |---------------------------------------------------------------------------------------------------------------------------------------
	  | Direction | Attribute ID | Data Type | Minimum Reporting Interval | Maximum Reporting Interval | Reeportable Change | Timeout Period |
	  |---------------------------------------------------------------------------------------------------------------------------------------
	  If Direction is 0x00: Uses fields Attribute Id, Data Type, Minimum Reporting Interval, Maximum Reporting Interval, Reportable Change
							Doesn't use field Timeout Period
	  If Direction is 0x01: Uses field Timeout Period
							Doesn't use fields Data Type, Minimum Reporting Interval, Maximum Reporting Interval, Reportable Change
	  For discrete (non-analog) data types, Reportable Change field is omitted.

	  Response payload
	  -----------------------------------------------------------------------------------
	  |  Bits: 24  |         32         |         32         | ... |         32         |
	  |----------------------------------------------------------------------------------
	  | ZCL Header | Attribute Record 1 | Attribute Record 2 | ... | Attribute Record n |
	  -----------------------------------------------------------------------------------
	  Attribute Record
	  --------------------------------------
	  | Bits: 8 |     8     |      16      |
	  --------------------------------------
	  | Status  | Direction | Attribute ID |
	  --------------------------------------
	  TODO:
	  If all attributes are configured for reporting successfully, just return a single record with status SUCCESS.
	*/

	DEBUG(F("Configure reporting for attribute"));

	auto cluster = getInClusterById(message.getClusterId());

	Frame(
		FrameControl(FrameType::Global, Direction::ToClient, true),
		frame.transactionSequenceNumber(),
		(uint8_t)CommandIdentifier::ConfigureReportingResponse
	).write(buffer);

	ConfigureReportingType type;
	while (ConfigureReportingFrame::readNextElementType(frameData, type)) {
		if (type == ConfigureReportingType::Receive) {
			ERROR(F("NOT IMPLEMENTED"));
			break;
		}

		if (type == ConfigureReportingType::Send) {
			auto element = ConfigureReportingFrame::readSendElement(frameData);

			auto attribute = cluster->getAttributeById(element.getAttributeId());

			if (attribute) {
				DEBUG(F("  Configuring reporting for attribute "), element.getAttributeId(), F(" data type "), String((int)element.getDataType(), HEX), F(" minimum interval "), element.getMinimumInterval(), F(" maximum interval "), element.getMaximumInterval());

				// TODO: We're ignoring element.dataType()!

				attribute->configureReporting(
					element.getMinimumInterval(),
					element.getMaximumInterval(),
					0,
					0
				);
				ConfigureReportingResponseFrame::writeAttribute(buffer, Status::Success, type, element.getAttributeId());
			}
			else {
				DEBUG(F("  Unsupported attribute "), element.getAttributeId());

				ConfigureReportingResponseFrame::writeAttribute(buffer, Status::UnsupportedAttribute, type, element.getAttributeId());
			}
		}
	}

	return true;
}
