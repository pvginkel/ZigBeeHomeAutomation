#include "OpenThermMaster.h"

OpenThermMaster* OpenThermMaster::_instance = nullptr;

void IRAM_ATTR OpenThermMaster::handleInterrupt() {
	_instance->_ot.handleInterrupt();
}

OpenThermMaster::OpenThermMaster(uint8_t inPin, uint8_t outPin, Configuration* configuration)
	: _configuration(configuration), _ot(inPin, outPin, false),
	_nextParam(SYNC_PARAM_LOOP_START)
{
	_instance = this;
	_masterStatus.value = 0;

	if (configuration->getControlSetpoint() == 0) {
		configuration->setControlSetpoint(DEFAULT_CONTROL_SETPOINT);
	}

	_cluster.getControlSetpoint()->setValue(configuration->getControlSetpoint());

	// isOn defaults to false. Se need to mark the attribute
	// as dirty to force the attribute being reported.
	_cluster.getOnOff()->setValue(isOn());
}

void OpenThermMaster::begin(BasicDevice& device) {
	_cluster.onAttributeChanged(
		[](GenOnOffAttribute attribute, uintptr_t data) {
			((OpenThermMaster*)data)->processThermostatClusterAttributeChanged(attribute);
		},
		(uintptr_t)this
	);

	_cluster.onOffCommand(
		[](uintptr_t data) { ((OpenThermMaster*)data)->setOn(false); },
		(uintptr_t)this
	);
	_cluster.onOnCommand(
		[](uintptr_t data) { ((OpenThermMaster*)data)->setOn(true); },
		(uintptr_t)this
	);

	_cluster.onToggleCommand(
		[](uintptr_t data) {
			const auto self = (OpenThermMaster*)data;

			self->setOn(!self->isOn());
		},
		(uintptr_t)this
	);

	device.addCluster(_cluster);

	_ot.begin(handleInterrupt, [](OpenThermMessage message, OpenThermResponseStatus status) {
		_instance->processResponse(message, status);
	});
}

void OpenThermMaster::update() {
	startNextConversation();

	_ot.process();
}

void OpenThermMaster::processThermostatClusterAttributeChanged(GenOnOffAttribute attribute) {
	switch (attribute) {
	case (GenOnOffAttribute)OpenThermAttribute::ControlSetpoint:
		const auto newValue = _cluster.getControlSetpoint()->getValue();

		_configuration->setControlSetpoint(newValue);

		_nextParam = Param::ControlSetpoint;
		break;
	}
}

void OpenThermMaster::setOn(bool on) {
	INFO(F("Turning radiator "), on ? F("on") : F("off"));

	_cluster.getOnOff()->setValue(on);
	_cluster.getCHActive()->setValue(on);

	_masterStatus.chEnable = on;

	_nextParam = Param::Status;
}

void OpenThermMaster::startNextConversation() {
	//
	// isReady is false when:
	//
	// - A request is being sent.
	// - A response is being received.
	// - We're waiting for a response and haven't timed out yet.
	// - We're in the 100 ms delay period after receiving a response.
	//
	// We're expected to send a new request within a second. The
	// logic below keeps sending requests as fast as possible to
	// keep the parameters below up to date according to the specs.
	//
	// The normal loop is from Status onwards. There are two exceptions:
	//
	// - When data needs to be written. See the ControlSetpoint
	//   branch.
	// - When the master status changes. In that case, the method
	//   changing the status sets _nextParam to Status.
	//

	if (!_ot.isReady()) {
		return;
	}

	DEBUG(F("Starting conversation for "), (int)_nextParam);

	switch (_nextParam) {
	case Param::ControlSetpoint:
		_ot.trySendRequest(OpenThermMessage(
			OpenThermMessageID::TSet,
			OpenThermMessageType::WriteData,
			deserializeZclTemperature(_cluster.getControlSetpoint()->getValue())
		));
		break;

	case Param::Status:
		_ot.trySendRequest(OpenThermMessage(
			OpenThermMessageID::Status,
			OpenThermMessageType::ReadData,
			/* lb */ 0,
			/* hb */ _masterStatus.value
		));
		break;

	case Param::ASFFlags:
		_ot.trySendRequest(OpenThermMessage(
			OpenThermMessageID::ASFflags,
			OpenThermMessageType::ReadData
		));
		break;

	case Param::BoilerWaterTemperature:
		_ot.trySendRequest(OpenThermMessage(
			OpenThermMessageID::Tboiler,
			OpenThermMessageType::ReadData
		));
		break;

	case Param::BurnerOperationHours:
		_ot.trySendRequest(OpenThermMessage(
			OpenThermMessageID::BurnerOperationHours,
			OpenThermMessageType::ReadData
		));
		break;

	case Param::BurnerStarts:
		_ot.trySendRequest(OpenThermMessage(
			OpenThermMessageID::BurnerStarts,
			OpenThermMessageType::ReadData
		));
		break;

	case Param::CHWaterPressure:
		_ot.trySendRequest(OpenThermMessage(
			OpenThermMessageID::CHPressure,
			OpenThermMessageType::ReadData
		));
		break;

	case Param::DHWBurnerOperationHours:
		_ot.trySendRequest(OpenThermMessage(
			OpenThermMessageID::DHWBurnerOperationHours,
			OpenThermMessageType::ReadData
		));
		break;
	}

	_nextParam = (Param)((uint8_t)_nextParam + 1);

	if (_nextParam >= Param::MaxValue) {
		_nextParam = SYNC_PARAM_LOOP_START;
	}
}

void OpenThermMaster::processResponse(OpenThermMessage message, OpenThermResponseStatus status) {
	if (
		status != OpenThermResponseStatus::Success ||
		!(message.type == OpenThermMessageType::ReadAck || message.type == OpenThermMessageType::WriteAck)
	) {
		DEBUG(F("Skipping response because of invalid status or message type: status: "), (int)status, F(" type "), (int)message.type);
		return;
	}

	switch (message.id) {
	case OpenThermMessageID::Status:
		OpenThermSlaveStatus slaveStatus;
		slaveStatus.value = message.getLB();
		_cluster.getFault()->setValue(slaveStatus.faultIndication);
		_cluster.getDHWActive()->setValue(slaveStatus.dhwMode);
		_cluster.getFlameOn()->setValue(slaveStatus.flameStatus);
		break;

	case OpenThermMessageID::ASFflags:
		OpenThermASFPayload asfPayload;
		asfPayload.value = message.payload;
		_cluster.getOEMFaultCode()->setValue(asfPayload.oemFaultCode);
		_cluster.getASFServiceRequest()->setValue(asfPayload.serviceRequest);
		_cluster.getASFLockoutRequest()->setValue(asfPayload.lockoutRequest);
		_cluster.getASFLowWaterPressure()->setValue(asfPayload.lowWaterPressure);
		_cluster.getASFGasFlameFault()->setValue(asfPayload.gasFlameFault);
		_cluster.getASFAirPressureFault()->setValue(asfPayload.airPressureFault);
		_cluster.getASFWaterOverTemp()->setValue(asfPayload.waterOverTemp);
		break;

	case OpenThermMessageID::Tboiler:
		_cluster.getBoilerTemperature()->setValue(serializeZclTemperature(message.getFloat()));
		break;

	case OpenThermMessageID::BurnerStarts:
		_cluster.getBurnerStarts()->setValue(message.payload);
		break;

	case OpenThermMessageID::BurnerOperationHours:
		_cluster.getBurnerOperationHours()->setValue(message.payload);
		break;

	case OpenThermMessageID::CHPressure:
		_cluster.getCHWaterPressure()->setValue(serializeZclTemperature(message.getFloat()));
		break;

	case OpenThermMessageID::DHWBurnerOperationHours:
		_cluster.getDHWBurnerOperationHours()->setValue(message.payload);
		break;
	}
}

float OpenThermMaster::deserializeZclTemperature(int16_t value) {
	return (float)value / 100.0f;
}

int16_t OpenThermMaster::serializeZclTemperature(float value) {
	return (uint16_t)(value * 100.0f);
}