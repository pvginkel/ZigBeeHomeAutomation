#include "ZigBee.h"

Attribute::~Attribute() {
	delete _reporting;
}

void Attribute::configureReporting(const XBeeAddress64& destinationAddress, uint16_t destinationShortAddress, uint8_t destinationEndpoint, uint16_t minimumInterval, uint16_t maximumInterval, Memory& memory) {
	if (!_reporting) {
		_reporting = new Reporting();
	}
	_reporting->destinationAddress = destinationAddress;
	_reporting->destinationShortAddress = destinationShortAddress;
	_reporting->destinationEndpoint = destinationEndpoint;
	_reporting->minimumInterval = minimumInterval;
	_reporting->maximumInterval = maximumInterval;

	configureReportableChange(memory);
}

void Attribute::report(XBee& device, uint8_t endpointId, uint16_t clusterId, Memory& buffer) {
	if (!_reporting) {
		return;
	}

	// TODO: Resend

	if (!_dirty) {
		return;
	}

	DEBUG(
		F("Reporting attribute endpoint "), endpointId,
		F(" cluster "), clusterId,
		F(" attribute "), getAttributeId(),
		F(" value "), toString(),
		F(" to "), String(_reporting->destinationAddress.getMsb(), HEX), String(_reporting->destinationAddress.getLsb(), HEX),
		F(" short "), String(_reporting->destinationShortAddress, HEX),
		F(" endpoint "), _reporting->destinationEndpoint);

	buffer.setPosition(0);

	Frame(
		FrameControl(FrameType::Global, Direction::ToClient, false),
		0,
		(uint8_t)CommandIdentifier::ReportAttributes
	).write(buffer);

	ReportAttributesFrame::writeAttribute(buffer, getAttributeId(), getDataType());
	writeValue(buffer);

	_dirty = false;

	ZBExplicitTxRequest message(
		_reporting->destinationAddress,
		_reporting->destinationShortAddress,
		0, // broadcastRadius
		0, // option
		buffer.getData(),
		buffer.getPosition(),
		device.getNextFrameId(),
		endpointId,
		_reporting->destinationEndpoint,
		clusterId,
		DeviceManager::ZHA_PROFILE_ID
	);
	device.send(message);
}
