#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Bounce2.h>
#include <SoftwareSerial.h>
#include "ZigBee.h"

#define IO_XBEE_RX 2
#define IO_XBEE_TX 3
#define IO_PB 4
#define IO_REPORT_PB 5
#define IO_STATUS_LED 6
#define IO_DHT 7
#define IO_PHOTO_RESISTOR_33 A0
#define IO_PHOTO_RESISTOR_60 A1
#define IO_PHOTO_RESISTOR_200 A2

//#define REPORT_INTERVAL_MS (1000 * 60)
#define REPORT_INTERVAL_MS 1000

#define MIN_TEMPERATURE (-20)
#define MAX_TEMPERATURE (60)
#define SCALE_TEMPERATURE (100)

#define MIN_HUMIDITY (5)
#define MAX_HUMIDITY (95)
#define SCALE_HUMIDITY (100)

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice dhtSensorDevice(1, 1, PowerSource::DCSource);
Device photoResistor33Device(2, 2);
Device photoResistor60Device(3, 3);
Device photoResistor200Device(4, 4);
StatusControl status;
DHT dht(IO_DHT, DHT22);
ConnectionStatus connectionStatus;

static void updateButton();
static void reset(uintptr_t);
static void onConnected(ConnectionStatus connectionStatus, uintptr_t);
static void reportSensors();
static uint32_t calculateResistance(int read, uint32_t r2);

class MyMsTemperatureMeasurementCluster : public MsTemperatureMeasurementCluster {
public:
	MyMsTemperatureMeasurementCluster() : MsTemperatureMeasurementCluster(ClusterType::Output) {
	}
};

MyMsTemperatureMeasurementCluster temperatureMeasurementCluster;

class MyMsRelativeHumidityCluster : public MsRelativeHumidityCluster {
public:
	MyMsRelativeHumidityCluster() : MsRelativeHumidityCluster(ClusterType::Output) {
	}
};

MyMsRelativeHumidityCluster relativeHumidityCluster;

class MyMsIlluminanceMeasurementCluster : public MsIlluminanceMeasurementCluster {
public:
	MyMsIlluminanceMeasurementCluster() : MsIlluminanceMeasurementCluster(ClusterType::Output) {
	}
};

MyMsIlluminanceMeasurementCluster photoResistor33Cluster;
MyMsIlluminanceMeasurementCluster photoResistor60Cluster;
MyMsIlluminanceMeasurementCluster photoResistor200Cluster;

void setup() {
	deviceManager.addDevice(dhtSensorDevice);

	dhtSensorDevice.getBasicCluster().getManufacturerName()->setValue(String(F("Pieter")));
	dhtSensorDevice.getBasicCluster().getModelId()->setValue(String(F("Sensors")));
	dhtSensorDevice.addCluster(temperatureMeasurementCluster);
	temperatureMeasurementCluster.getMinMeasuredValue()->setValue(MIN_TEMPERATURE * SCALE_TEMPERATURE);
	temperatureMeasurementCluster.getMaxMeasuredValue()->setValue(MAX_TEMPERATURE * SCALE_TEMPERATURE);
	dhtSensorDevice.addCluster(relativeHumidityCluster);
	relativeHumidityCluster.getMinMeasuredValue()->setValue(MIN_HUMIDITY * SCALE_HUMIDITY);
	relativeHumidityCluster.getMaxMeasuredValue()->setValue(MAX_HUMIDITY * SCALE_HUMIDITY);

	deviceManager.addDevice(photoResistor33Device);

	photoResistor33Device.addCluster(photoResistor33Cluster);
	photoResistor33Cluster.getMinMeasuredValue()->setValue(0);
	photoResistor33Cluster.getMaxMeasuredValue()->setValue(1023);

	deviceManager.addDevice(photoResistor60Device);

	photoResistor60Device.addCluster(photoResistor60Cluster);
	photoResistor60Cluster.getMinMeasuredValue()->setValue(0);
	photoResistor60Cluster.getMaxMeasuredValue()->setValue(1023);

	deviceManager.addDevice(photoResistor200Device);

	photoResistor200Device.addCluster(photoResistor200Cluster);
	photoResistor200Cluster.getMinMeasuredValue()->setValue(0);
	photoResistor200Cluster.getMaxMeasuredValue()->setValue(1023);

	while (!Serial);

	DEBUG(F("Serial ready"));

	status.onReset(reset);
	status.setBounce(Bounce(IO_PB, 50));
	status.setLed(IO_STATUS_LED);

	pinMode(IO_PB, INPUT);
	pinMode(IO_REPORT_PB, INPUT);
	pinMode(IO_PHOTO_RESISTOR_33, INPUT);
	pinMode(IO_PHOTO_RESISTOR_60, INPUT);
	pinMode(IO_PHOTO_RESISTOR_200, INPUT);

	xbeeSerial.begin(9600);

	deviceManager.setConnectedCallback(onConnected);

	deviceManager.begin(xbeeSerial);

	dht.begin();
}

void loop() {
	if (digitalRead(IO_REPORT_PB)) {
		reportSensors();
	}
	status.update();
	deviceManager.update();
}

time_t lastReport;

static void reportSensors() {
	if (connectionStatus != ConnectionStatus::Connected) {
		return;
	}

	auto currentMillis = millis();
	if (currentMillis - lastReport > REPORT_INTERVAL_MS) {
		lastReport = currentMillis;

		float temperature = dht.readTemperature();
		temperatureMeasurementCluster.getMeasuredValue()->setValue((int16_t)(temperature * SCALE_TEMPERATURE));

		float humidity = dht.readHumidity();
		relativeHumidityCluster.getMeasuredValue()->setValue((uint16_t)(humidity * SCALE_TEMPERATURE));

		auto photoResistor33 = analogRead(IO_PHOTO_RESISTOR_33);
		auto resistance33 = calculateResistance(photoResistor33, 10000);
		photoResistor33Cluster.getMeasuredValue()->setValue(photoResistor33);

		auto photoResistor60 = analogRead(IO_PHOTO_RESISTOR_60);
		auto resistance60 = calculateResistance(photoResistor60, 10000);
		photoResistor60Cluster.getMeasuredValue()->setValue(photoResistor60);

		auto photoResistor200 = analogRead(IO_PHOTO_RESISTOR_200);
		auto resistance200 = calculateResistance(photoResistor200, 10000);
		photoResistor200Cluster.getMeasuredValue()->setValue(photoResistor200);

		//DEBUG(photoResistor33, " ", photoResistor60, " ", photoResistor200);
		//DEBUG(resistance33, " ", resistance60, " ", resistance200);
	}
}

void reset(uintptr_t) {
	deviceManager.performReset();
}

static void onConnected(ConnectionStatus connectionStatus_, uintptr_t) {
	connectionStatus = connectionStatus_;

	status.setConnected(connectionStatus_);
}

static uint32_t calculateResistance(int read, uint32_t r2) {
	const int maxRead = 1023;
	const float vmax = 5;

	float vout = float(read) / float(maxRead) * vmax;
	float vin = vmax;

	auto r1 = float(r2) * (vin / vout - 1);

	return uint32_t(r1);
}
