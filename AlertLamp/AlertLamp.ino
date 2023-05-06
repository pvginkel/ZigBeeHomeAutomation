#include <SoftwareSerial.h>
#include "ZigBeeHomeAutomation.h"
#include "Bounce2.h"
#include "Configuration.h"

constexpr uint8_t IO_XBEE_RX = 2;
constexpr uint8_t IO_XBEE_TX = 3;
constexpr uint8_t IO_STATUS_LED = 10;
constexpr uint8_t IO_PB = 9;
constexpr uint8_t IO_RELAY = 5;

constexpr uint16_t DEFAULT_ALERT_LIGHT_SECONDS_ON = 10;

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice lightBulb(1, 1, PowerSource::MainsSinglePhase);
StatusControl status;
Configuration configuration;

time_t lastOn = 0;

static void setOn(bool on);
static bool isOn();
static void autoOff();
static void setupConfiguration();
static void saveLightConfiguration();

class AlertLightSecondsOnAttribute : public AttributeUInt16 {
public:
    AlertLightSecondsOnAttribute()
        : AttributeUInt16(0x0201, DataType::UInt16) {
    }

    void readValue(Memory& memory) override {
        AttributeUInt16::readValue(memory);

        saveLightConfiguration();
    }
};

AlertLightSecondsOnAttribute alertLightSecondsOn;

class : public GenOnOffCluster {
public:
    Status onOnCommand() override {
        INFO(F("Alert lamp on"));
        setOn(true);
        return Status::Success;
    }

    Status onOffCommand() override {
        INFO(F("Alert lamp off"));
        setOn(false);
        return Status::Success;
    }

    Status onToggleCommand() override {
        INFO(F("Alert lamp toggle"));
        setOn(!isOn());
        return Status::Success;
    }
} onOffCluster;

void setup() {
	LOG_BEGIN();

    setupConfiguration();

    deviceManager.addDevice(lightBulb);
    lightBulb.addCluster(onOffCluster);
    lightBulb.getBasicCluster().getManufacturerName()->setValue(F("Pieter"));
    lightBulb.getBasicCluster().getModelId()->setValue(F("Alert Lamp"));

    // Add custom attributes.

    onOffCluster.addAttribute(&alertLightSecondsOn);
    alertLightSecondsOn.configureBroadcastReporting();
    alertLightSecondsOn.setValue(configuration.getAlertLightSecondsOn());

    // Setup operational attributes.

    onOffCluster.getOnOff()->configureBroadcastReporting();

    // Setup the relay.

	pinMode(IO_RELAY, OUTPUT);

    // Setup status.

	status.onClick([](uintptr_t) {
        setOn(!isOn());
	});

    status.onReset([](uintptr_t) {
        deviceManager.performReset();
    });

	status.setBounce(Bounce(IO_PB, 50));
	status.setLed(IO_STATUS_LED);

    // Start XBee.

    xbeeSerial.begin(9600);

    deviceManager.setConnectedCallback([](ConnectionStatus connectionStatus, uintptr_t) {
        status.setConnected(connectionStatus);
    });

    deviceManager.begin(xbeeSerial);
}

void setupConfiguration() {
    configuration.begin();

    if (!configuration.isInitialized()) {
        configuration.setAlertLightSecondsOn(DEFAULT_ALERT_LIGHT_SECONDS_ON);
        configuration.setInitialized(true);
    }
}

void saveLightConfiguration() {
    configuration.setAlertLightSecondsOn(alertLightSecondsOn.getValue());
}

void loop() {
    autoOff();
	status.update();
    deviceManager.update();
}

bool isOn() {
    return digitalRead(IO_RELAY);
}

void setOn(bool on) {
    if (on) {
        lastOn = millis();
    }

    digitalWrite(IO_RELAY, on);

    onOffCluster.getOnOff()->setValue(on);
}

void autoOff() {
    if (lastOn != 0) {
        auto maxOn = time_t(alertLightSecondsOn.getValue()) * 1000;
        auto currentMillis = millis();

        if (currentMillis - lastOn >= maxOn) {
            DEBUG("Automatically turning the light off again");

            lastOn = 0;
            setOn(false);
        }
    }
}
