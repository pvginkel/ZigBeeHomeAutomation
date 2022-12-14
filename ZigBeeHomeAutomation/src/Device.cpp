#include "ZigBeeHomeAutomation.h"

Device::Device(uint8_t endpointId, uint16_t deviceId)
	: _endpointId(endpointId), _deviceId(deviceId) {
}

void Device::addCluster(Cluster& cluster) {
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

Status Device::processGeneralCommand(DeviceManager& deviceManager, Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response) {
	auto commandIdentifier = (CommandIdentifier)frame.commandIdentifier();

	switch (commandIdentifier) {
		case CommandIdentifier::ReadAttributes:
			return processGeneralReadAttributesCommand(frame, request, message, response);
		case CommandIdentifier::WriteAttributes:
			return processGeneralWriteAttributesCommand(frame, request, message, response);
		case CommandIdentifier::DiscoverAttributes:
			return processGeneralDiscoverAttributesCommand(frame, request, message, response);
		case CommandIdentifier::ConfigureReporting:
			return processGeneralConfigureReportingCommand(deviceManager, frame, request, message, response);
		default:
			DEBUG(F("Received unimplemented command "), String((uint8_t)commandIdentifier, HEX));
			return Status::UnsupportedGeneralCommand;
	}
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

Status Device::processGeneralWriteAttributesCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response) {
	DEBUG(F("Write attributes command"));

	auto cluster = getClusterById(message.getClusterId());

	uint16_t attributeId;
	DataType dataType;

	Frame(
		FrameControl(FrameType::Global, Direction::ToClient, true),
		frame.transactionSequenceNumber(),
		(uint8_t)CommandIdentifier::WriteAttributesResponse
	).write(response);

	while (WriteAttributesFrame::readNextWriteAttribute(request, attributeId, dataType)) {
		auto attribute = cluster->getAttributeById(attributeId);

		if (!attribute) {
			WARN(F("Tried to write non-existing attribute "), attributeId, F(" on cluster "), message.getClusterId());

			skipValue(request, dataType);

			WriteAttributeResponseFrame::writeAttributeResponse(response, Status::UnsupportedAttribute, attributeId);
		}
		else if (dataType != attribute->getDataType()) {
			WARN(F("Tried to write attribute "), attributeId, F(" on cluster "), message.getClusterId(), F(" with incorrect data type "), (int)dataType);

			skipValue(request, dataType);

			WriteAttributeResponseFrame::writeAttributeResponse(response, Status::InvalidDataType, attributeId);
		}
		else {
			DEBUG(F("Writing value to attribute "), attributeId, F(" on cluster "), message.getClusterId());

			attribute->readValue(request);

			WriteAttributeResponseFrame::writeAttributeResponse(response, Status::Success, attributeId);
		}
	}

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

Status Device::processGeneralConfigureReportingCommand(DeviceManager& deviceManager, Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response) {

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

			DEBUG(F("  Configuring reporting for attribute "), element.getAttributeId(), F(" data type "), String((int)element.getDataType(), HEX), F(" minimum interval "), element.getMinimumInterval(), F(" maximum interval "), element.getMaximumInterval());

			auto attribute = cluster->getAttributeById(element.getAttributeId());

			if (!attribute) {
				DEBUG(F("  Unsupported attribute "), element.getAttributeId());

				ConfigureReportingResponseFrame::writeAttribute(response, Status::UnsupportedAttribute, type, element.getAttributeId());
			}
			else if (
				element.getDataType() != DataType::NoData &&
				element.getDataType() != attribute->getDataType()
			) {
				DEBUG(F("  Requested data type "), (int)element.getDataType(), F(" did not match attribute data type "), (int)attribute->getDataType());

				ConfigureReportingResponseFrame::writeAttribute(response, Status::InvalidDataType, type, element.getAttributeId());
			}
			else if (element.getMinimumInterval() == 0 && element.getMaximumInterval() == 0xffff) {
				DEBUG(F("  Disabling attribute reporting"));

				attribute->setReportingEndpointId(0);
			}
			else {
				auto operatingPanId = deviceManager.getOperatingPanId();

				if (
					message.getRemoteAddress64().getMsb() == operatingPanId->getMsb() &&
					message.getRemoteAddress64().getLsb() == operatingPanId->getLsb() &&
					message.getRemoteAddress16() == 0 &&
					message.getSrcEndpoint() != 0
				) {
					DEBUG(F("  Configuring reporting to coordinator endpoint "), message.getSrcEndpoint());
					attribute->setReportingEndpointId(message.getSrcEndpoint());
				}
				else {
					DEBUG(F("  Configure report request did not match the default criteria; configuring broadcast reporting"));
					attribute->setReportingEndpointId(Attribute::REPORT_BROADCAST);
				}

				ConfigureReportingResponseFrame::writeAttribute(response, Status::Success, type, element.getAttributeId());
			}

			skipValue(request, element.getDataType());
		}
	}

	return Status::Success;
}
