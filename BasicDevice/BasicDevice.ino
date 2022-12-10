#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>

#define IO_XBEE_RX 2
#define IO_XBEE_TX 3
#define IO_PB 4
#define IO_STATUS_LED 6

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice basicDevice(1, 1, PowerSource::DCSource);
StatusControl status;

void setup() {
	deviceManager.addDevice(basicDevice);

	basicDevice.getBasicCluster().getManufacturerName()->setValue(String(F("Pieter")));
	basicDevice.getBasicCluster().getModelId()->setValue(String(F("Basic Device")));

	Serial.begin(115200);
	while (!Serial);

	DEBUG(F("Serial ready"));

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

int lastFreeMemory = 0;

void loop() {
	int currentFreeMemory = freeMemory();
	if (currentFreeMemory != lastFreeMemory) {
		ERROR(currentFreeMemory);
		lastFreeMemory = currentFreeMemory;
	}

	status.update();
	deviceManager.update();
}
