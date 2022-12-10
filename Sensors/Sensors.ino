#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>

#define IO_XBEE_RX 2
#define IO_XBEE_TX 3
#define IO_PB 4
#define IO_STATUS_LED 6
#define IO_DHT 7
#define IO_PHOTO_RESISTOR_33 A0
#define IO_PHOTO_RESISTOR_60 A1
#define IO_PHOTO_RESISTOR_200 A2

//#define REPORT_INTERVAL_MS 1000
#define REPORT_INTERVAL_MS 60000ul

#define MIN_TEMPERATURE (-40)
#define MAX_TEMPERATURE (80)
#define SCALE_TEMPERATURE (100)

#define MIN_HUMIDITY (0)
#define MAX_HUMIDITY (100)
#define SCALE_HUMIDITY (100)

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice sensorDevice(1, 1, PowerSource::DCSource);
StatusControl status;
DHT dht(IO_DHT, DHT22);
time_t lastReport;

static void reportSensors();

MsTemperatureMeasurementCluster temperatureMeasurementCluster(ClusterType::Output);
MsRelativeHumidityCluster relativeHumidityCluster(ClusterType::Output);

Device photoResistorDevice33k(2, 2);
MsIlluminanceMeasurementCluster photoResistorCluster33k(ClusterType::Output);

Device photoResistorDevice60k(3, 2);
MsIlluminanceMeasurementCluster photoResistorCluster60k(ClusterType::Output);

Device photoResistorDevice200k(4, 2);
MsIlluminanceMeasurementCluster photoResistorCluster200k(ClusterType::Output);

void setup() {
	deviceManager.addDevice(sensorDevice);

	sensorDevice.getBasicCluster().getManufacturerName()->setValue(String(F("Pieter")));
	sensorDevice.getBasicCluster().getModelId()->setValue(String(F("Sensors")));
	sensorDevice.addCluster(temperatureMeasurementCluster);
	temperatureMeasurementCluster.getMinMeasuredValue()->setValue(MIN_TEMPERATURE * SCALE_TEMPERATURE);
	temperatureMeasurementCluster.getMaxMeasuredValue()->setValue(MAX_TEMPERATURE * SCALE_TEMPERATURE);
	sensorDevice.addCluster(relativeHumidityCluster);
	relativeHumidityCluster.getMinMeasuredValue()->setValue(MIN_HUMIDITY * SCALE_HUMIDITY);
	relativeHumidityCluster.getMaxMeasuredValue()->setValue(MAX_HUMIDITY * SCALE_HUMIDITY);

	deviceManager.addDevice(photoResistorDevice33k);

	photoResistorDevice33k.addCluster(photoResistorCluster33k);
	photoResistorCluster33k.getMinMeasuredValue()->setValue(0);
	photoResistorCluster33k.getMaxMeasuredValue()->setValue(1023);

	deviceManager.addDevice(photoResistorDevice60k);

	photoResistorDevice60k.addCluster(photoResistorCluster60k);
	photoResistorCluster60k.getMinMeasuredValue()->setValue(0);
	photoResistorCluster60k.getMaxMeasuredValue()->setValue(1023);

	deviceManager.addDevice(photoResistorDevice200k);

	photoResistorDevice200k.addCluster(photoResistorCluster200k);
	photoResistorCluster200k.getMinMeasuredValue()->setValue(0);
	photoResistorCluster200k.getMaxMeasuredValue()->setValue(1023);

	Serial.begin(115200);
	while (!Serial);

	DEBUG(F("Serial ready"));

	// Force a report if the status button is clicked.
	status.onClick([](uintptr_t) { lastReport = 0; });
	status.onReset([](uintptr_t) { deviceManager.performReset(); });
	status.setBounce(Bounce(IO_PB, 50));
	status.setLed(IO_STATUS_LED);

	pinMode(IO_PHOTO_RESISTOR_33, INPUT);
	pinMode(IO_PHOTO_RESISTOR_60, INPUT);
	pinMode(IO_PHOTO_RESISTOR_200, INPUT);

	xbeeSerial.begin(9600);

	deviceManager.setConnectedCallback(
		[](ConnectionStatus connectionStatus, uintptr_t) { status.setConnected(connectionStatus); }
	);

	deviceManager.begin(xbeeSerial);

	dht.begin();
}

int lastFreeMemory = 0;

void loop() {
	int currentFreeMemory = freeMemory();
	if (currentFreeMemory != lastFreeMemory) {
		ERROR(F("Free memory: "), currentFreeMemory);
		lastFreeMemory = currentFreeMemory;
	}

	reportSensors();
	status.update();
	deviceManager.update();
}

static void reportSensors() {
	auto currentMillis = millis();
	if (lastReport != 0 && currentMillis - lastReport < REPORT_INTERVAL_MS) {
		return;
	}

	lastReport = currentMillis;

	float temperature = dht.readTemperature();
	temperatureMeasurementCluster.getMeasuredValue()->setValue((int16_t)(temperature * SCALE_TEMPERATURE));

	float humidity = dht.readHumidity();
	relativeHumidityCluster.getMeasuredValue()->setValue((uint16_t)(humidity * SCALE_TEMPERATURE));

	DEBUG(F("Temperature "), temperature, F(", humidity "), humidity);

	auto photoResistor33 = analogRead(IO_PHOTO_RESISTOR_33);
	photoResistorCluster33k.getMeasuredValue()->setValue(photoResistor33);

	auto photoResistor60 = analogRead(IO_PHOTO_RESISTOR_60);
	photoResistorCluster60k.getMeasuredValue()->setValue(photoResistor60);

	auto photoResistor200 = analogRead(IO_PHOTO_RESISTOR_200);
	photoResistorCluster200k.getMeasuredValue()->setValue(photoResistor200);
}
