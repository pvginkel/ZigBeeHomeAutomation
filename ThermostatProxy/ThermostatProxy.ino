#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>
#include "opentherm.h"

constexpr uint8_t IO_XBEE_RX = 2;
constexpr uint8_t IO_XBEE_TX = 3;
constexpr uint8_t IO_PB = 8;
constexpr uint8_t IO_STATUS_LED = 9;
constexpr uint8_t IO_BOILER_IN = 4;
constexpr uint8_t IO_BOILER_OUT = 5;
constexpr uint8_t IO_THERMOSTAT_IN = 7;
constexpr uint8_t IO_THERMOSTAT_OUT = 6;

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice thermostatDevice(1, 1, PowerSource::DCSource);
StatusControl status;

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

	xbeeSerial.begin(9600);

	deviceManager.setConnectedCallback(
		[](ConnectionStatus connectionStatus, uintptr_t) { status.setConnected(connectionStatus); }
	);

	deviceManager.begin(xbeeSerial);
}

time_t lastMessage = 0;

void loop() {
	status.update();
	deviceManager.update();

	auto currentMillis = millis();
	if (currentMillis - lastMessage > 1000) {
		lastMessage = currentMillis;

		logAttribute.setValue(String(F("It is now ")) + String(currentMillis));
	}
}
