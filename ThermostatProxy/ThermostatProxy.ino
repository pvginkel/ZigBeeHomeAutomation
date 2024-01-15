#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>
#include "Thermostat.h"

constexpr uint8_t IO_XBEE_RESET = 2;
constexpr uint8_t IO_PB = 8;
constexpr uint8_t IO_STATUS_LED = 9;
constexpr uint8_t IO_BOILER_IN = 4;
constexpr uint8_t IO_BOILER_OUT = 5;
constexpr uint8_t IO_THERMOSTAT_IN = 7;
constexpr uint8_t IO_THERMOSTAT_OUT = 6;

DeviceManager deviceManager;
BasicDevice thermostatDevice(1, 1, PowerSource::DCSource);
StatusControl status;
Thermostat thermostat(IO_BOILER_IN, IO_BOILER_OUT, IO_THERMOSTAT_IN, IO_THERMOSTAT_OUT);

AttributeString logAttribute(0x0201);

void setup() {
	deviceManager.addDevice(thermostatDevice);

	thermostatDevice.getBasicCluster().getManufacturerName()->setValue(F("Pieter"));
	thermostatDevice.getBasicCluster().getModelId()->setValue(F("Thermostat Proxy"));
	
	// Add custom attributes.

	thermostatDevice.getBasicCluster().addAttribute(&logAttribute);
	logAttribute.configureBroadcastReporting();

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

	thermostat.eventOccurredCallback(
		[](const String& message, uintptr_t) { logAttribute.setValue(message); }
	);

	thermostat.begin();
}

void loop() {
	status.update();
	deviceManager.update();
	thermostat.update();
}
