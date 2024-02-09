#include <ZigBeeHomeAutomation.h>

#include "Configuration.h"
#include "OpenThermMaster.h"

constexpr uint8_t IO_XBEE_RESET = 2;
constexpr uint8_t IO_PB = 8;
constexpr uint8_t IO_STATUS_LED = 9;
constexpr uint8_t IO_BOILER_IN = 4;
constexpr uint8_t IO_BOILER_OUT = 5;
constexpr uint8_t IO_THERMOSTAT_IN = 7;
constexpr uint8_t IO_THERMOSTAT_OUT = 6;

DeviceManager deviceManager;
BasicDevice boilerDevice(1, 1, PowerSource::DCSource);
StatusControl status;
Configuration configuration;
OpenThermMaster boiler(IO_BOILER_IN, IO_BOILER_OUT, &configuration);

void setup() {
	deviceManager.addDevice(boilerDevice);

	boilerDevice.getBasicCluster().getManufacturerName()->setValue(F("Pieter"));
	boilerDevice.getBasicCluster().getModelId()->setValue(F("Boiler"));

	// Add custom attributes.

	LOG_BEGIN();

	status.onReset([](uintptr_t) { deviceManager.performReset(); });
	status.setBounce(Bounce(IO_PB, 50));
	status.setLed(IO_STATUS_LED);

	Serial1.begin(9600);

	deviceManager.setConnectedCallback(
		[](ConnectionStatus connectionStatus, uintptr_t) { status.setConnected(connectionStatus); }
	);

	deviceManager.resetDevice(IO_XBEE_RESET);
	deviceManager.begin(Serial1);

	boiler.begin(boilerDevice);
}

void loop() {
	status.update();
	deviceManager.update();
	boiler.update();
}
