#include "ZigBeeHomeAutomation.h"

Device::Device(uint8_t endpointId, uint16_t deviceId)
	: _endpointId(endpointId), _deviceId(deviceId) {
}

void Device::addCluster(Cluster& cluster) {
	cluster._device = this;
	_clusters.add(&cluster);
}

int Device::getClusterCount() {
	return _clusters.size();
}

Cluster* Device::getClusterByIndex(int index) {
	return _clusters[index];
}

Cluster* Device::getClusterById(uint16_t clusterId) {
	for (auto cluster : _clusters) {
		if (cluster->getClusterId() == clusterId) {
			return cluster;
		}
	}
	return nullptr;
}

Status Device::processGeneralCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response) {
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
			return Status::UnsupportedGeneralCommand;
	}
}

Attribute* Device::reportAttribute(XBee& device, Memory& buffer) {
	for (auto cluster : _clusters) {
		auto attribute = cluster->reportAttribute(device, buffer);
		if (attribute) {
			return attribute;
		}
	}

	return nullptr;
}

Status Device::processGeneralReadAttributesCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response) {
	DEBUG(F("Reading attributes from cluster "), message.getClusterId());

	auto cluster = getClusterById(message.getClusterId());

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

			attribute->writeValue(response);
		}
		else {
			DEBUG(F("  Attribute "), attributeId, F(" unsupported"));

			ReadAttributesResponseFrame::writeAttribute(response, attributeId, Status::UnsupportedAttribute);
		}
	}

	DEBUG(F("  Done"));

	return Status::Success;
}

Status Device::processGeneralDiscoverAttributesCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response) {
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

	auto cluster = getClusterById(message.getClusterId());

	Frame(
		FrameControl(FrameType::Global, Direction::ToClient, true),
		frame.transactionSequenceNumber(),
		(uint8_t)CommandIdentifier::DiscoverAttributesResponse
	).write(response);

	// Write a temporary value and get back here at the end.

	auto position = response.getPosition();
	DiscoverAttributesResponseFrame(false).write(response);

	auto discoverAttributesFrame = DiscoverAttributesFrame::read(request);

	DEBUG(F("Discover attributes start "), discoverAttributesFrame.getStartAttributeId(), F(" maximum "), discoverAttributesFrame.getMaximumAttributeIds());

	auto index = cluster->getAttributeIndex(discoverAttributesFrame.getStartAttributeId());

	for (int i = 0; i < discoverAttributesFrame.getMaximumAttributeIds(); i++) {
		if (index == -1 || index >= cluster->getAttributeCount()) {
			DEBUG(F("  Discovery complete"));
			auto newPosition = response.getPosition();
			response.setPosition(position);
			DiscoverAttributesResponseFrame(true).write(response);
			response.setPosition(newPosition);
			break;
		}

		auto attribute = cluster->getAttributeByIndex(index++);

		DiscoverAttributesResponseFrame::writeAttribute(response, attribute->getAttributeId(), attribute->getDataType());

		DEBUG(F("  Reporting ID "), attribute->getAttributeId(), F(" data type "), String((int)attribute->getDataType(), HEX));
	}

	DEBUG(F("  Done"));

	return Status::Success;
}

Status Device::processGeneralConfigureReportingCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response) {

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

	auto cluster = getClusterById(message.getClusterId());

	Frame(
		FrameControl(FrameType::Global, Direction::ToClient, true),
		frame.transactionSequenceNumber(),
		(uint8_t)CommandIdentifier::ConfigureReportingResponse
	).write(response);

	ConfigureReportingType type;
	while (ConfigureReportingFrame::readNextElementType(request, type)) {
		if (type == ConfigureReportingType::Receive) {
			ERROR(F("NOT IMPLEMENTED"));
			break;
		}

		if (type == ConfigureReportingType::Send) {
			auto element = ConfigureReportingFrame::readSendElement(request);

			auto attribute = cluster->getAttributeById(element.getAttributeId());

			if (attribute) {
				DEBUG(F("  Configuring reporting for attribute "), element.getAttributeId(), F(" data type "), String((int)element.getDataType(), HEX), F(" minimum interval "), element.getMinimumInterval(), F(" maximum interval "), element.getMaximumInterval());

				if (element.getDataType() != attribute->getDataType()) {
					ConfigureReportingResponseFrame::writeAttribute(response, Status::InvalidDataType, type, element.getAttributeId());
				}
				else {
					attribute->configureReporting(
						message.getRemoteAddress64(),
						message.getRemoteAddress16(),
						message.getSrcEndpoint(),
						element.getMinimumInterval(),
						element.getMaximumInterval(),
						request
					);
					ConfigureReportingResponseFrame::writeAttribute(response, Status::Success, type, element.getAttributeId());
				}
			}
			else {
				DEBUG(F("  Unsupported attribute "), element.getAttributeId());

				ConfigureReportingResponseFrame::writeAttribute(response, Status::UnsupportedAttribute, type, element.getAttributeId());
			}
		}
	}

	return Status::Success;
}
