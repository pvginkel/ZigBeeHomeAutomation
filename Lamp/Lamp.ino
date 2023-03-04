#define DISPLAY 1

#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>

#include "Light.h"
#include "Configuration.h"
#if DISPLAY
#include "Display.h"

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

constexpr int SCREEN_HEIGHT = 32;
constexpr int SCREEN_WIDTH = 128;

Display display;
#endif

constexpr uint8_t IO_XBEE_RX = 6;
constexpr uint8_t IO_XBEE_TX = 5;
constexpr uint8_t IO_PB = 7;
constexpr uint8_t IO_LED = 3;
constexpr uint8_t IO_STATUS_LED = 11;

constexpr float LIGHT_MINIMUM_LEVEL_DEFAULT = 0.02f;
constexpr float LIGHT_MAXIMUM_LEVEL_DEFAULT = 1.0f;

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice lightBulb(1, 1, PowerSource::MainsSinglePhase);
NaturalLight light;
StatusControl status;
Configuration configuration;

static bool isOn();
static void updateButton();
static void setupConfiguration();
static void reconfigureLight(time_t time = 0);
static void saveLightConfiguration();

// Custom attributes to configure the lamp.

class LightConfigurationAttributeUInt8 : public AttributeUInt8 {
public:
    LightConfigurationAttributeUInt8(uint16_t attributeId, DataType dataType)
        : AttributeUInt8(attributeId, dataType) {
    }

    void readValue(Memory& memory) override {
        AttributeUInt8::readValue(memory);

        reconfigureLight(1000);
        saveLightConfiguration();
    }
};

LightConfigurationAttributeUInt8 lightMinimumLevel(0x0201, DataType::UInt8);
LightConfigurationAttributeUInt8 lightMaximumLevel(0x0202, DataType::UInt8);

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

    setupConfiguration();

    deviceManager.addDevice(lightBulb);
    lightBulb.addCluster(onOffCluster);
    lightBulb.addCluster(levelCtrlCluster);
    lightBulb.getBasicCluster().getManufacturerName()->setValue(F("Pieter"));
    lightBulb.getBasicCluster().getModelId()->setValue(F("Lamp"));

    // Add custom attributes.

    levelCtrlCluster.addAttribute(&lightMinimumLevel);
    lightMinimumLevel.configureBroadcastReporting();
    lightMinimumLevel.setValue(configuration.getLightMinimumLevel());
    levelCtrlCluster.addAttribute(&lightMaximumLevel);
    lightMaximumLevel.configureBroadcastReporting();
    lightMaximumLevel.setValue(configuration.getLightMaximumLevel());

    // Setup operational attributes.

    onOffCluster.getOnOff()->configureBroadcastReporting();
    levelCtrlCluster.getCurrentLevel()->configureBroadcastReporting();

    light.onLevelChanged([](float level, uintptr_t) {
        onOffCluster.getOnOff()->setValue(level > 0);
	    levelCtrlCluster.getCurrentLevel()->setValue(uint8_t(level * 254.0f));
#if DISPLAY
        display.setBrightness(uint8_t(level * 254.0f));
#endif
    });

    light.setLevel(0);

#if DISPLAY
    u8g2.begin();
    display.begin(u8g2, SCREEN_WIDTH, SCREEN_HEIGHT, 5000ul);
#endif

    status.onClick([](uintptr_t) {
        light.setLevel(isOn() ? 0 : 1, 1000);
    });

    status.onReset([](uintptr_t) {
        deviceManager.performReset();
    });

#if DISPLAY
    status.onResetCountdown([](int remaining, uintptr_t) {
        if (remaining > 0) {
            display.setStatus(String(F("Resetting in ")) + remaining);
        }
        else if (remaining == 0) {
            display.setStatus(F("Resetting NOW"));
        }
        else {
            display.setStatus(String());
        }
    });
#endif

    status.setBounce(Bounce(IO_PB, 50));
    status.setLed(IO_STATUS_LED);

    xbeeSerial.begin(9600);

    deviceManager.setConnectedCallback([](ConnectionStatus connectionStatus, uintptr_t) {
#if DISPLAY
        display.setConnected(connectionStatus);
#endif
        status.setConnected(connectionStatus);
    });

#if DISPLAY
    deviceManager.setStatusCallback([](const __FlashStringHelper* message, uintptr_t) {
        display.setStatus(message);
    });
#endif

    deviceManager.begin(xbeeSerial);

    reconfigureLight();

    light.begin(IO_LED);
    light.setLevel(0);
}

void setupConfiguration() {
    configuration.begin();

    if (!configuration.isInitialized()) {
        configuration.setLightMinimumLevel(uint8_t(LIGHT_MINIMUM_LEVEL_DEFAULT * 255));
        configuration.setLightMaximumLevel(uint8_t(LIGHT_MAXIMUM_LEVEL_DEFAULT * 255));
        configuration.setInitialized(true);
    }
}

void reconfigureLight(time_t time) {
    DEBUG(F("Reconfiguring light"));
    DEBUG(F("  Minimum level "), lightMinimumLevel.getValue());
    DEBUG(F("  Maximum level "), lightMaximumLevel.getValue());

    light.reconfigure(
        float(lightMinimumLevel.getValue()) / 255.0f,
        float(lightMaximumLevel.getValue()) / 255.0f,
        time
    );
}

void saveLightConfiguration() {
    configuration.setLightMinimumLevel(lightMinimumLevel.getValue());
    configuration.setLightMaximumLevel(lightMaximumLevel.getValue());
}

void loop() {
    status.update();
    light.update();
    deviceManager.update();

#if DISPLAY
    display.update();
#endif
}

bool isOn() {
    return onOffCluster.getOnOff()->getValue();
}
