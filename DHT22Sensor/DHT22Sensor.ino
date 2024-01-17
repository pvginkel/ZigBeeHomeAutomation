#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>

constexpr uint8_t IO_PB = 4;
constexpr uint8_t IO_STATUS_LED = 3;
constexpr uint8_t IO_DHT = 5;
constexpr uint8_t IO_XBEE_RESET = 9;

constexpr uint16_t REPORT_INTERVAL_MS = 60000ul;

constexpr int MIN_TEMPERATURE = -40;
constexpr int MAX_TEMPERATURE = 80;
constexpr int SCALE_TEMPERATURE = 100;

constexpr int MIN_HUMIDITY = 0;
constexpr int MAX_HUMIDITY = 100;
constexpr int SCALE_HUMIDITY = 100;

DeviceManager deviceManager;
BasicDevice sensorDevice(1, 1, PowerSource::DCSource);
StatusControl status;
DHT dht(IO_DHT, DHT22);
time_t lastReport;

static void reportSensors();

MsTemperatureMeasurementCluster temperatureMeasurementCluster(ClusterType::Output);
MsRelativeHumidityCluster relativeHumidityCluster(ClusterType::Output);

void setup() {
	deviceManager.addDevice(sensorDevice);

	sensorDevice.getBasicCluster().getManufacturerName()->setValue(F("Pieter"));
	sensorDevice.getBasicCluster().getModelId()->setValue(F("DHT22 Sensor"));
	sensorDevice.addCluster(temperatureMeasurementCluster);
	temperatureMeasurementCluster.getMinMeasuredValue()->setValue(MIN_TEMPERATURE * SCALE_TEMPERATURE);
	temperatureMeasurementCluster.getMaxMeasuredValue()->setValue(MAX_TEMPERATURE * SCALE_TEMPERATURE);
	sensorDevice.addCluster(relativeHumidityCluster);
	relativeHumidityCluster.getMinMeasuredValue()->setValue(MIN_HUMIDITY * SCALE_HUMIDITY);
	relativeHumidityCluster.getMaxMeasuredValue()->setValue(MAX_HUMIDITY * SCALE_HUMIDITY);

	LOG_BEGIN();

	// Force a report if the status button is clicked.
	status.onClick([](uintptr_t) { lastReport = 0; });
	status.onReset([](uintptr_t) { deviceManager.performReset(); });
	status.setBounce(Bounce(IO_PB, 50));
	status.setLed(IO_STATUS_LED);

	Serial1.begin(9600);

	deviceManager.setConnectedCallback(
		[](ConnectionStatus connectionStatus, uintptr_t) { status.setConnected(connectionStatus); }
	);

	deviceManager.resetDevice(IO_XBEE_RESET);

	deviceManager.begin(Serial1);

	dht.begin();
}

void loop() {
	reportSensors();
	status.update();
	deviceManager.update();
}

static void reportSensors() {
	const auto currentMillis = millis();
	if (lastReport != 0 && currentMillis - lastReport < REPORT_INTERVAL_MS) {
		return;
	}

	lastReport = currentMillis;

	const float temperature = dht.readTemperature();
	temperatureMeasurementCluster.getMeasuredValue()->setValue((int16_t)(temperature * SCALE_TEMPERATURE));

	const float humidity = dht.readHumidity();
	relativeHumidityCluster.getMeasuredValue()->setValue((uint16_t)(humidity * SCALE_TEMPERATURE));

	INFO(F("Temperature "), temperature, F(", humidity "), humidity);
}
