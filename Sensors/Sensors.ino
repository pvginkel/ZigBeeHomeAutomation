#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Bounce2.h>
#include <SoftwareSerial.h>
#include "ZigBee.h"

#define IO_XBEE_RX 2
#define IO_XBEE_TX 3
#define IO_PB 4
#define IO_STATUS_LED 6
#define IO_DHT 7
#define IO_DIP_1 10
#define IO_DIP_2 11
#define IO_DIP_3 12
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
Bounce dip1(IO_DIP_1, 50);
Bounce dip2(IO_DIP_2, 50);
Bounce dip3(IO_DIP_3, 50);

static void reportSensors();

MsTemperatureMeasurementCluster temperatureMeasurementCluster(ClusterType::Output);
MsRelativeHumidityCluster relativeHumidityCluster(ClusterType::Output);
MsIlluminanceMeasurementCluster photoResistorCluster(ClusterType::Output);

AttributeUInt16* photoResistor33kMeasuredValue;
AttributeUInt16* photoResistor60kMeasuredValue;
AttributeUInt16* photoResistor200kMeasuredValue;

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
	sensorDevice.addCluster(photoResistorCluster);
	photoResistorCluster.getMinMeasuredValue()->setValue(0);
	photoResistorCluster.getMaxMeasuredValue()->setValue(1023);

	photoResistor33kMeasuredValue = new AttributeUInt16(0x0201, DataType::UInt16);
	photoResistorCluster.addAttribute(photoResistor33kMeasuredValue);
	photoResistor60kMeasuredValue = new AttributeUInt16(0x0202, DataType::UInt16);
	photoResistorCluster.addAttribute(photoResistor60kMeasuredValue);
	photoResistor200kMeasuredValue = new AttributeUInt16(0x0203, DataType::UInt16);
	photoResistorCluster.addAttribute(photoResistor200kMeasuredValue);

	while (!Serial);

	DEBUG(F("Serial ready"));

	status.onReset([](uintptr_t) { deviceManager.performReset(); });
	status.setBounce(Bounce(IO_PB, 50));
	status.setLed(IO_STATUS_LED);

	pinMode(IO_PB, INPUT);
	pinMode(IO_DIP_1, INPUT);
	pinMode(IO_DIP_2, INPUT);
	pinMode(IO_DIP_3, INPUT);
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

void loop() {
	reportSensors();
	status.update();
	deviceManager.update();
}

static void reportSensors() {
	dip1.update();
	dip2.update();
	dip3.update();

	// Verify that just one of the dip switches is in the on position.
	if ((dip1.read() ? 1 : 0) + (dip2.read() ? 1 : 0) + (dip3.read() ? 1 : 0) != 1) {
		// Reset last report so we report immediately when the DIP switches change.
		lastReport = 0;
		return;
	}

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
	photoResistor33kMeasuredValue->setValue(photoResistor33);

	auto photoResistor60 = analogRead(IO_PHOTO_RESISTOR_60);
	photoResistor60kMeasuredValue->setValue(photoResistor60);

	auto photoResistor200 = analogRead(IO_PHOTO_RESISTOR_200);
	photoResistor200kMeasuredValue->setValue(photoResistor200);

	auto photoResistorReport =
		dip1.read()
		? photoResistor33
		: (dip2.read() ? photoResistor60 : photoResistor200);
	photoResistorCluster.getMeasuredValue()->setValue(photoResistorReport);
}
