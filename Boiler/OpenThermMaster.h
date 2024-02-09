#pragma once

#include "ZigBeeHomeAutomation.h"
#include "OpenTherm.h"
#include "OpenThermCluster.h"
#include "Configuration.h"

union OpenThermASFPayload
{
	struct {
		uint8_t oemFaultCode;

		struct {
			bool serviceRequest : 1;
			bool lockoutRequest : 1;
			bool lowWaterPressure : 1;
			bool gasFlameFault : 1;
			bool airPressureFault : 1;
			bool waterOverTemp : 1;
		};
	};

	uint16_t value;
};

union OpenThermMasterStatus
{
	struct {
		bool chEnable : 1;
		bool dhwEnable : 1;
		bool coolingEnable : 1;
		bool otcActive : 1;
		bool ch2Enable : 1;
	};

	uint8_t value;
};

union OpenThermSlaveStatus
{
	struct {
		bool faultIndication : 1;
		bool chMode : 1;
		bool dhwMode : 1;
		bool flameStatus : 1;
		bool coolingStatus : 1;
		bool ch2Mode : 1;
		bool diagnosticIndication : 1;
	};

	uint8_t value;
};

class OpenThermMaster
{
	static constexpr int16_t DEFAULT_CONTROL_SETPOINT = 7500;

	enum class Param {
		ControlSetpoint,
		Status,
		ASFFlags,
		BoilerWaterTemperature,
		BurnerOperationHours,
		BurnerStarts,
		CHWaterPressure,
		DHWBurnerOperationHours,
		MaxValue
	};

	static constexpr auto SYNC_PARAM_LOOP_START = Param::Status;

	static OpenThermMaster* _instance;
	static void IRAM_ATTR handleInterrupt();

	Configuration* _configuration;
	OpenTherm _ot;
	OpenThermCluster _cluster;
	Param _nextParam;
	OpenThermMasterStatus _masterStatus;

public:
	OpenThermMaster(uint8_t inPin, uint8_t outPin, Configuration* configuration);

	void begin(BasicDevice& device);
	void update();

private:
	void processThermostatClusterAttributeChanged(GenOnOffAttribute attribute);
	void startNextConversation();
	void processResponse(OpenThermMessage message, OpenThermResponseStatus status);
	void setOn(bool on);
	bool isOn() const { return _masterStatus.chEnable; }

	static float deserializeZclTemperature(int16_t value);
	static int16_t serializeZclTemperature(float value);
};
