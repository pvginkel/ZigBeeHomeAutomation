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
	return _clusters.get(index);
}

Cluster* Device::getClusterById(uint16_t clusterId) {
	for (uint8_t i = 0; i < _clusters.size(); i++) {
		if (_clusters.get(i)->getClusterId() == clusterId) {
			return _clusters.get(i);
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

			attribute->write(response);
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
