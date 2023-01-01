#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>
#include "PioneerAmplifier.h"

#define IO_XBEE_RX 2
#define IO_XBEE_TX 3
#define IO_PB 4
#define IO_STATUS_LED 5

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice basicDevice(1, 1, PowerSource::DCSource);
StatusControl status;

Bounce button1(6, 50);
Bounce button2(7, 50);
Bounce button3(8, 50);
PioneerAmplifier amplifier(9);

void setup() {
	deviceManager.addDevice(basicDevice);

	basicDevice.getBasicCluster().getManufacturerName()->setValue(F("Pieter"));
	basicDevice.getBasicCluster().getModelId()->setValue(F("Amplifier Remote"));

	LOG_BEGIN();

	// Disable the onboard led.
	pinMode(LED_BUILTIN, OUTPUT);
	digitalWrite(LED_BUILTIN, LOW);

	// Force a report if the status button is clicked.
	status.onReset([](uintptr_t) { deviceManager.performReset(); });
	status.setBounce(Bounce(IO_PB, 50));
	status.setLed(IO_STATUS_LED);

	xbeeSerial.begin(9600);

	deviceManager.setConnectedCallback(
		[](ConnectionStatus connectionStatus, uintptr_t) { status.setConnected(connectionStatus); }
	);

	deviceManager.begin(xbeeSerial);
}

void loop() {
	status.update();
	deviceManager.update();

	if (button1.update() && button1.rose()) {
		INFO(F("Power"));
		amplifier.power();
	}
	if (button2.update() && button2.rose()) {
		INFO(F("Volume up"));
		amplifier.volumeUp();
	}
	if (button3.update() && button3.rose()) {
		INFO(F("Volume down"));
		amplifier.volumeDown();
	}
}
