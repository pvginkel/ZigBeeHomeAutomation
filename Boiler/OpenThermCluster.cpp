#include "OpenThermMaster.h"

OpenThermCluster::OpenThermCluster()
	: _fault((uint16_t)OpenThermAttribute::Fault, DataType::Bool),
	_chActive((uint16_t)OpenThermAttribute::CHActive, DataType::Bool),
	_dhwActive((uint16_t)OpenThermAttribute::DHWActive, DataType::Bool),
	_flameOn((uint16_t)OpenThermAttribute::FlameOn, DataType::Bool),
	_controlSetpoint((uint16_t)OpenThermAttribute::ControlSetpoint, DataType::Int16),
	_chWaterPressure((uint16_t)OpenThermAttribute::CHWaterPressure, DataType::UInt16),
	_burnerOperationHours((uint16_t)OpenThermAttribute::BurnerOperationHours, DataType::UInt16),
	_burnerStarts((uint16_t)OpenThermAttribute::BurnerStarts, DataType::UInt16),
	_dhwBurnerOperationHours((uint16_t)OpenThermAttribute::DHWBurnerOperationHours, DataType::UInt16),
	_asfServiceRequest((uint16_t)OpenThermAttribute::ASFServiceRequest, DataType::Bool),
	_asfLockoutRequest((uint16_t)OpenThermAttribute::ASFLockoutRequest, DataType::Bool),
	_asfLowWaterPressure((uint16_t)OpenThermAttribute::ASFLowWaterPressure, DataType::Bool),
	_asfGasFlameFault((uint16_t)OpenThermAttribute::ASFGasFlameFault, DataType::Bool),
	_asfAirPressureFault((uint16_t)OpenThermAttribute::ASFAirPressureFault, DataType::Bool),
	_asfWaterOverTemp((uint16_t)OpenThermAttribute::ASFWaterOverTemp, DataType::Bool),
	_oemFaultCode((uint16_t)OpenThermAttribute::OEMFaultCode, DataType::UInt8),
	_boilerTemperature((uint16_t)OpenThermAttribute::BoilerTemperature, DataType::Int16)
{
	addAttribute(&_fault);
	addAttribute(&_chActive);
	addAttribute(&_dhwActive);
	addAttribute(&_flameOn);
	addAttribute(&_controlSetpoint);
	addAttribute(&_chWaterPressure);
	addAttribute(&_burnerOperationHours);
	addAttribute(&_burnerStarts);
	addAttribute(&_dhwBurnerOperationHours);
	addAttribute(&_asfServiceRequest);
	addAttribute(&_asfLockoutRequest);
	addAttribute(&_asfLowWaterPressure);
	addAttribute(&_asfGasFlameFault);
	addAttribute(&_asfAirPressureFault);
	addAttribute(&_asfWaterOverTemp);
	addAttribute(&_oemFaultCode);
	addAttribute(&_boilerTemperature);
}

Status OpenThermCluster::processWriteAttributeValue(uint16_t attributeId, DataType dataType, Memory& buffer) {
	const auto status = GenOnOffCluster::processWriteAttributeValue(attributeId, dataType, buffer);

	if (status == Status::Success) {
		_attributeChanged.call((GenOnOffAttribute)attributeId);
	}

	return status;
}
