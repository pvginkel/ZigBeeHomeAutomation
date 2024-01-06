#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>

#include "Light.h"
#include "Bounce2.h"

constexpr uint8_t IO_PB = 2;
constexpr uint8_t IO_STATUS_LED = 3;
constexpr uint8_t IO_DHT = 4;
constexpr uint8_t IO_LAMP = 5;
constexpr uint8_t IO_XBEE_TX = 8;
constexpr uint8_t IO_XBEE_RX = 9;

constexpr uint16_t REPORT_INTERVAL_MS = 60000ul;

constexpr int MIN_TEMPERATURE = -40;
constexpr int MAX_TEMPERATURE = 80;
constexpr int SCALE_TEMPERATURE = 100;

constexpr int MIN_HUMIDITY = 0;
constexpr int MAX_HUMIDITY = 100;
constexpr int SCALE_HUMIDITY = 100;

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice testDevice(1, 1, PowerSource::MainsSinglePhase);
StatusControl status;
NaturalLight light;
DHT dht(IO_DHT, DHT22);
time_t lastReport;

static bool isOn();
static void reconfigureLight(time_t time = 0);

static void reportSensors();

MsTemperatureMeasurementCluster temperatureMeasurementCluster(ClusterType::Output);
MsRelativeHumidityCluster relativeHumidityCluster(ClusterType::Output);

// Custom attributes to configure the lamp.

class LightConfigurationAttributeUInt8 : public AttributeUInt8 {
public:
    LightConfigurationAttributeUInt8(uint16_t attributeId, DataType dataType)
        : AttributeUInt8(attributeId, dataType) {
    }

    void readValue(Memory& memory) override {
        AttributeUInt8::readValue(memory);

        reconfigureLight(1000);
    }
};

class : public GenOnOffCluster {
public:
    Status onOffCommand() override {
        INFO(F("Lamp on"));
        light.setLevel(0, 1000);
        return Status::Success;
    }

    Status onOnCommand() override {
        INFO(F("Lamp off"));
        light.setLevel(1, 1000);
        return Status::Success;
    }

    Status onToggleCommand() override {
        INFO(F("Lamp toggle"));
        light.setLevel(isOn() ? 0 : 1, 1000);
        return Status::Success;
    }
} onOffCluster;

class : public GenLevelCtrlCluster {
public:
    Status onMoveToLevelWithOnOffCommand(uint8_t level, uint16_t transtime) override {
        INFO(F("Level change to "), level, F(" transition time "), (transtime * 100), F(" ms"));
        light.setLevel(float(level) / 254.0f, transtime * 100);
        return Status::Success;
    }
} levelCtrlCluster;

void setup() {
    LOG_BEGIN();

    deviceManager.addDevice(testDevice);
    testDevice.addCluster(onOffCluster);
    testDevice.addCluster(levelCtrlCluster);
    testDevice.getBasicCluster().getManufacturerName()->setValue(F("Pieter"));
    testDevice.getBasicCluster().getModelId()->setValue(F("Low Power Test"));
    testDevice.addCluster(temperatureMeasurementCluster);
    temperatureMeasurementCluster.getMinMeasuredValue()->setValue(MIN_TEMPERATURE * SCALE_TEMPERATURE);
    temperatureMeasurementCluster.getMaxMeasuredValue()->setValue(MAX_TEMPERATURE * SCALE_TEMPERATURE);
    testDevice.addCluster(relativeHumidityCluster);
    relativeHumidityCluster.getMinMeasuredValue()->setValue(MIN_HUMIDITY * SCALE_HUMIDITY);
    relativeHumidityCluster.getMaxMeasuredValue()->setValue(MAX_HUMIDITY * SCALE_HUMIDITY);

    // Setup operational attributes.

    onOffCluster.getOnOff()->configureBroadcastReporting();
    levelCtrlCluster.getCurrentLevel()->configureBroadcastReporting();

    light.onLevelChanged([](float level, uintptr_t) {
        onOffCluster.getOnOff()->setValue(level > 0);
        levelCtrlCluster.getCurrentLevel()->setValue(uint8_t(level * 254.0f));
    });

    light.setLevel(0);

    status.onClick([](uintptr_t) {
        light.setLevel(isOn() ? 0 : 1, 1000);

        // Force a report.
        lastReport = 0;
    });

    status.onReset([](uintptr_t) {
        deviceManager.performReset();
    });

    status.setBounce(Bounce(IO_PB, 50));
    status.setLed(IO_STATUS_LED);

    xbeeSerial.begin(9600);

    deviceManager.setConnectedCallback([](ConnectionStatus connectionStatus, uintptr_t) {
        status.setConnected(connectionStatus);
    });

    deviceManager.begin(xbeeSerial);

    reconfigureLight();

    light.begin(IO_LAMP);
    light.setLevel(0);

    dht.begin();
}

void reconfigureLight(time_t time) {
    light.reconfigure(0.2f, 1.0f, time);
}

void loop() {
    reportSensors();
    status.update();
    light.update();
    deviceManager.update();
}

bool isOn() {
    return onOffCluster.getOnOff()->getValue();
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

    DEBUG(F("Temperature "), temperature, F(", humidity "), humidity);
}
