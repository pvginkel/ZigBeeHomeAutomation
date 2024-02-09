#pragma once

#include "ZigBeeHomeAutomation.h"

enum class OpenThermAttribute : uint16_t {
	Fault = 0x0201,
	CHActive,
	DHWActive,
	FlameOn,
	ControlSetpoint,
	CHWaterPressure,
	BurnerOperationHours,
	BurnerStarts,
	DHWBurnerOperationHours,
	ASFServiceRequest,
	ASFLockoutRequest,
	ASFLowWaterPressure,
	ASFGasFlameFault,
	ASFAirPressureFault,
	ASFWaterOverTemp,
	OEMFaultCode,
	BoilerTemperature
};

class OpenThermCluster : public GenOnOffCluster
{
	CallbackArgs<GenOnOffAttribute> _attributeChanged;
	Callback _onCommand;
	Callback _offCommand;
	Callback _toggleCommand;
	AttributeUInt8 _fault;
	AttributeUInt8 _chActive;
	AttributeUInt8 _dhwActive;
	AttributeUInt8 _flameOn;
	AttributeInt16 _controlSetpoint;
	AttributeUInt16 _chWaterPressure;
	AttributeUInt16 _burnerOperationHours;
	AttributeUInt16 _burnerStarts;
	AttributeUInt16 _dhwBurnerOperationHours;
	AttributeUInt8 _asfServiceRequest;
	AttributeUInt8 _asfLockoutRequest;
	AttributeUInt8 _asfLowWaterPressure;
	AttributeUInt8 _asfGasFlameFault;
	AttributeUInt8 _asfAirPressureFault;
	AttributeUInt8 _asfWaterOverTemp;
	AttributeUInt8 _oemFaultCode;
	AttributeInt16 _boilerTemperature;

public:
	OpenThermCluster();

	Status processWriteAttributeValue(uint16_t attributeId, DataType dataType, Memory& buffer) override;

	void onAttributeChanged(CallbackArgs<GenOnOffAttribute>::Func func, uintptr_t data = 0) {
		_attributeChanged.set(func, data);
	}
	void onOffCommand(Callback::Func func, uintptr_t data = 0) {
		_offCommand.set(func, data);
	}
	void onOnCommand(Callback::Func func, uintptr_t data = 0) {
		_onCommand.set(func, data);
	}
	void onToggleCommand(Callback::Func func, uintptr_t data = 0) {
		_toggleCommand.set(func, data);
	}

	Status onOffCommand() override {
		_offCommand.call();
		return Status::Success;
	}
	Status onOnCommand() override {
		_onCommand.call();
		return Status::Success;
	}
	Status onToggleCommand() override {
		_toggleCommand.call();
		return Status::Success;
	}

	AttributeUInt8* getFault() {
		return &_fault;
	}
	AttributeUInt8* getCHActive() {
		return &_chActive;
	}
	AttributeUInt8* getDHWActive() {
		return &_dhwActive;
	}
	AttributeUInt8* getFlameOn() {
		return &_flameOn;
	}
	AttributeInt16* getControlSetpoint() {
		return &_controlSetpoint;
	}
	AttributeUInt16* getCHWaterPressure() {
		return &_chWaterPressure;
	}
	AttributeUInt16* getBurnerOperationHours() {
		return &_burnerOperationHours;
	}
	AttributeUInt16* getBurnerStarts() {
		return &_burnerStarts;
	}
	AttributeUInt16* getDHWBurnerOperationHours() {
		return &_dhwBurnerOperationHours;
	}
	AttributeUInt8* getASFServiceRequest() {
		return &_asfServiceRequest;
	}
	AttributeUInt8* getASFLockoutRequest() {
		return &_asfLockoutRequest;
	}
	AttributeUInt8* getASFLowWaterPressure() {
		return &_asfLowWaterPressure;
	}
	AttributeUInt8* getASFGasFlameFault() {
		return &_asfGasFlameFault;
	}
	AttributeUInt8* getASFAirPressureFault() {
		return &_asfAirPressureFault;
	}
	AttributeUInt8* getASFWaterOverTemp() {
		return &_asfWaterOverTemp;
	}
	AttributeUInt8* getOEMFaultCode() {
		return &_oemFaultCode;
	}
	AttributeInt16* getBoilerTemperature() {
		return &_boilerTemperature;
	}
};
