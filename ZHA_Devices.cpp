#include "ZHA_Devices.h"
#include "support.h"

using namespace Zcl;

ZHA_Device::ZHA_Device(uint8_t endpointId, uint16_t deviceId)
	: _endpointId(endpointId), _deviceId(deviceId) {
}

void ZHA_Device::addInCluster(ZHA_Cluster* inCluster) {
	_inClusters.add(inCluster);
}

void ZHA_Device::addOutCluster(ZHA_Cluster* outCluster) {
	_outClusters.add(outCluster);
}

int ZHA_Device::getNumInClusters() {
	return _inClusters.size();
}

int ZHA_Device::getNumOutClusters() {
	return _outClusters.size();
}

ZHA_Cluster* ZHA_Device::getInCluster(uint8_t num) {
	return _inClusters.get(num);
}

ZHA_Cluster* ZHA_Device::getOutCluster(uint8_t num) {
	return _outClusters.get(num);
}

uint8_t ZHA_Device::getEndpointId() {
	return _endpointId;
}

uint16_t ZHA_Device::getDeviceId() {
	return _deviceId;
}

ZHA_Cluster* ZHA_Device::getInClusterById(uint16_t clusterId) {
	for (uint8_t i = 0; i < _inClusters.size(); i++) {
		if (_inClusters.get(i)->getClusterId() == clusterId) {
			return _inClusters.get(i);
		}
	}
	return nullptr;
}

ZHA_Cluster* ZHA_Device::getOutClusterById(uint16_t clusterId) {
	for (uint8_t i = 0; i < _outClusters.size(); i++) {
		if (_outClusters.get(i)->getClusterId() == clusterId) {
			return _outClusters.get(i);
		}
	}
	return nullptr;
}

bool ZHA_Device::processGeneralCommand(Buffer& frameData, ZBExplicitRxResponse& message, Buffer& buffer) {
	auto commandIdentifier = Frame(frameData).commandIdentifier();

	switch (commandIdentifier) {
		case CommandIdentifier::ReadAttributes:
			return processGeneralReadAttributesCommand(frameData, message, buffer);
		case CommandIdentifier::DiscoverAttributes:
			return processGeneralDiscoverAttributesCommand(frameData, message, buffer);
		case CommandIdentifier::ConfigureReporting:
			return processGeneralConfigureReportingCommand(frameData, message, buffer);
		default:
			DEBUG("Received unimplemented command ", String((uint8_t)commandIdentifier, HEX));
			return false;
	}
}

bool ZHA_Device::processGeneralReadAttributesCommand(Buffer& frameData, ZBExplicitRxResponse& message, Buffer& buffer) {
	DEBUG("Reading attributes from cluster ", message.getClusterId());

	auto cluster = getInClusterById(message.getClusterId());

	auto frame = ReadAttributesFrame(frameData);

	auto response = ReadAttributesResponseFrame(buffer);
	response.frameControl(FrameControl(FrameType::Global, Direction::ToClient, true));
	response.transactionSequenceNumber(frame.transactionSequenceNumber());
	response.commandIdentifier(CommandIdentifier::ReadAttributesResponse);

	DEBUG("  Reading ", frame.attributeCount(), " attributes");

	for (int i = 0; i < frame.attributeCount(); i++) {
		auto attributeId = frame.attributeId(i);
		auto attribute = cluster->getAttrById(attributeId);

		if (attribute) {
			DEBUG("  Attribute ", attributeId, " reporting ", attribute->toString());

			response.appendAttribute(attributeId, Status::Success, attribute->dataType());

			attribute->writeValue(response);
		}
		else {
			DEBUG("  Attribute ", attributeId, " unsupported");
			response.appendAttribute(attributeId, Status::UnsupportedAttribute);
		}
	}

	DEBUG("  Done");

	buffer.length(response.length());

	return true;
}

bool ZHA_Device::processGeneralDiscoverAttributesCommand(Buffer& frameData, ZBExplicitRxResponse& message, Buffer& buffer) {
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

	auto frame = DiscoverAttributesFrame(frameData);

	auto response = DiscoverAttributesResponseFrame(buffer);
	response.frameControl(FrameControl(FrameType::Global, Direction::ToClient, true));
	response.transactionSequenceNumber(frame.transactionSequenceNumber());
	response.commandIdentifier(CommandIdentifier::DiscoverAttributesResponse);

	DEBUG("Discover attributes start ", frame.startAttributeId(), " maximum ", frame.maximumAttributeIds());

	auto index = cluster->getAttrIndexById(frame.startAttributeId());

	for (int i = 0; i < frame.maximumAttributeIds(); i++) {
		if (index == -1 || index >= cluster->numAttributes()) {
			DEBUG("  Discovery complete");
			response.discoveryComplete(true);
			break;
		}

		auto attribute = cluster->getAttrByIndex(index++);

		response.appendAttribute(attribute->getAttrId(), attribute->dataType());

		DEBUG("  Reporting ID ", attribute->getAttrId(), " data type ", String((int)attribute->dataType(), HEX));
	}

	buffer.length(response.length());

	DEBUG("  Done");
	return true;
}

bool ZHA_Device::processGeneralConfigureReportingCommand(Buffer& frameData, ZBExplicitRxResponse& message, Buffer& buffer) {

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

	DEBUG("Configure reporting for attribute");

	auto cluster = getInClusterById(message.getClusterId());

	auto frame = ConfigureReportingFrame(frameData);

	auto response = ConfigureReportingResponseFrame(buffer);
	response.frameControl(FrameControl(FrameType::Global, Direction::ToClient, true));
	response.transactionSequenceNumber(frame.transactionSequenceNumber());
	response.commandIdentifier(CommandIdentifier::ConfigureReportingResponse);

	while (true) {
		auto type = frame.readElementType();
		if (type == ConfigureReportingType::End) {
			break;
		}

		if (type == ConfigureReportingType::Receive) {
			DEBUG("NOT IMPLEMENTED");
			break;
		}

		if (type == ConfigureReportingType::Send) {
			auto element = frame.readSendElement();

			auto attribute = cluster->getAttrById(element.attributeId());

			if (attribute) {
				DEBUG("  Configuring reporting for attribute ", element.attributeId(), " data type ", String((int)element.dataType(), HEX), " minimum interval ", element.minimumInterval(), " maximum interval ", element.maximumInterval());

				attribute->configureReporting(
					element.dataType(),
					element.minimumInterval(),
					element.maximumInterval(),
					0,
					0
				);
				response.appendAttribute(Status::Success, type, element.attributeId());
			}
			else {
				DEBUG("  Unsupported attribute ", element.attributeId());

				response.appendAttribute(Status::UnsupportedAttribute, type, element.attributeId());
			}
		}
	}

	buffer.length(response.length());

	return true;
}
