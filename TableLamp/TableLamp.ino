#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>

#include "ButtonArray.h"
#include "Configuration.h"
#include "DualTemperatureLight.h"

constexpr uint8_t IO_PB = 2;
constexpr uint8_t IO_STATUS_LED = 3;
constexpr uint8_t IO_TOUCH_IRQ = 4;
constexpr uint8_t IO_LAMP_LOW_COLD = 5;
constexpr uint8_t IO_LAMP_LOW_WARM = 6;
constexpr uint8_t IO_XBEE_TX = 7;
constexpr uint8_t IO_XBEE_RX = 8;
constexpr uint8_t IO_LAMP_HIGH_COLD = 9;
constexpr uint8_t IO_LAMP_HIGH_WARM = 10;

constexpr uint16_t MINIMUM_TEMPERATURE = 270;
constexpr uint16_t MAXIMUM_TEMPERATURE = 650;

constexpr float LIGHT_LOW_MINIMUM_LEVEL_DEFAULT = 0.02f;
constexpr float LIGHT_LOW_MAXIMUM_LEVEL_DEFAULT = 1.0f;
constexpr float LIGHT_HIGH_MINIMUM_LEVEL_DEFAULT = 0.02f;
constexpr float LIGHT_HIGH_MAXIMUM_LEVEL_DEFAULT = 1.0f;
constexpr float LIGHT_BREAK_START_DEFAULT = 0.04f;
constexpr float LIGHT_BREAK_END_DEFAULT = 0.07f;

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice lightBulb(1, 1, PowerSource::MainsSinglePhase);
StatusControl status;
NaturalTemperatureLight lightLow(MINIMUM_TEMPERATURE, MAXIMUM_TEMPERATURE);
NaturalTemperatureLight lightHigh(MINIMUM_TEMPERATURE, MAXIMUM_TEMPERATURE);
NaturalDualTemperatureLight light(lightLow, lightHigh);
ButtonArray<4> buttons;
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

LightConfigurationAttributeUInt8 lightLowMinimumLevel(0x0201, DataType::UInt8);
LightConfigurationAttributeUInt8 lightLowMaximumLevel(0x0202, DataType::UInt8);
LightConfigurationAttributeUInt8 lightHighMinimumLevel(0x0203, DataType::UInt8);
LightConfigurationAttributeUInt8 lightHighMaximumLevel(0x0204, DataType::UInt8);
LightConfigurationAttributeUInt8 lightBreakStart(0x0205, DataType::UInt8);
LightConfigurationAttributeUInt8 lightBreakEnd(0x0206, DataType::UInt8);

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

class : public LightingColorCtrlCluster {
public:
    Status onMoveToColorTempCommand(uint16_t colortemp, uint16_t transtime) override {
        INFO(F("Color change to "), (colortemp * 10), F(" K transition time "), (transtime * 100), F(" ms"));
        light.setTemperature(colortemp, transtime * 100);
        return Status::Success;
    }
} lightingColorCtrlCluster;

void setup() {
    LOG_BEGIN();

    // Default address is 0x5A (tied to GND), if tied to 3.3V its 0x5B
    // If tied to SDA its 0x5C and if SCL then 0x5D
    if (!buttons.begin(IO_TOUCH_IRQ, 0x5A)) {
        ERROR(F("MPR121 not found, check wiring?"));
    }

    setupConfiguration();

    deviceManager.addDevice(lightBulb);
    lightBulb.addCluster(onOffCluster);
    lightBulb.addCluster(levelCtrlCluster);
    lightBulb.addCluster(lightingColorCtrlCluster);
    lightBulb.getBasicCluster().getManufacturerName()->setValue(F("Pieter"));
    lightBulb.getBasicCluster().getModelId()->setValue(F("Table Lamp"));

    // Add custom attributes.

    levelCtrlCluster.addAttribute(&lightLowMinimumLevel);
    lightLowMinimumLevel.configureBroadcastReporting();
    lightLowMinimumLevel.setValue(configuration.getLightLowMinimumLevel());
    levelCtrlCluster.addAttribute(&lightLowMaximumLevel);
    lightLowMaximumLevel.configureBroadcastReporting();
    lightLowMaximumLevel.setValue(configuration.getLightLowMaximumLevel());
    levelCtrlCluster.addAttribute(&lightHighMinimumLevel);
    lightHighMinimumLevel.configureBroadcastReporting();
    lightHighMinimumLevel.setValue(configuration.getLightHighMinimumLevel());
    levelCtrlCluster.addAttribute(&lightHighMaximumLevel);
    lightHighMaximumLevel.configureBroadcastReporting();
    lightHighMaximumLevel.setValue(configuration.getLightHighMaximumLevel());
    levelCtrlCluster.addAttribute(&lightBreakStart);
    lightBreakStart.configureBroadcastReporting();
    lightBreakStart.setValue(configuration.getLightBreakStart());
    levelCtrlCluster.addAttribute(&lightBreakEnd);
    lightBreakEnd.configureBroadcastReporting();
    lightBreakEnd.setValue(configuration.getLightBreakEnd());

    // Setup static attributes.

    lightingColorCtrlCluster.getColorTempPhysicalMin()->setValue(MINIMUM_TEMPERATURE);
    lightingColorCtrlCluster.getColorTempPhysicalMin()->configureBroadcastReporting();
    lightingColorCtrlCluster.getColorTempPhysicalMax()->setValue(MAXIMUM_TEMPERATURE);
    lightingColorCtrlCluster.getColorTempPhysicalMax()->configureBroadcastReporting();

    // Setup operational attributes.

    onOffCluster.getOnOff()->configureBroadcastReporting();
    levelCtrlCluster.getCurrentLevel()->configureBroadcastReporting();
    lightingColorCtrlCluster.getColorTemperature()->configureBroadcastReporting();

    light.onLevelChanged([](float level, uintptr_t) {
        onOffCluster.getOnOff()->setValue(level > 0);
		levelCtrlCluster.getCurrentLevel()->setValue(uint8_t(level * 254.0f));
    });
    light.onTemperatureChanged([](uint16_t temperature, uintptr_t) {
        lightingColorCtrlCluster.getColorTemperature()->setValue(temperature);
		configuration.setTemperature(temperature);
    });

    light.setLevel(0);
	light.setTemperature(configuration.getTemperature());

    status.onClick([](uintptr_t) {
        light.setLevel(isOn() ? 0 : 1, 1000);
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

    light.begin(IO_LAMP_LOW_COLD, IO_LAMP_LOW_WARM, IO_LAMP_HIGH_COLD, IO_LAMP_HIGH_WARM);
    light.setLevel(0);
}

void setupConfiguration() {
    configuration.begin();

    if (!configuration.isInitialized()) {
        configuration.setTemperature(MINIMUM_TEMPERATURE);
        configuration.setLightLowMinimumLevel(uint8_t(LIGHT_LOW_MINIMUM_LEVEL_DEFAULT * 255));
        configuration.setLightLowMaximumLevel(uint8_t(LIGHT_LOW_MAXIMUM_LEVEL_DEFAULT * 255));
        configuration.setLightHighMinimumLevel(uint8_t(LIGHT_HIGH_MINIMUM_LEVEL_DEFAULT * 255));
        configuration.setLightHighMaximumLevel(uint8_t(LIGHT_HIGH_MAXIMUM_LEVEL_DEFAULT * 255));
        configuration.setLightBreakStart(uint8_t(LIGHT_BREAK_START_DEFAULT * 255));
        configuration.setLightBreakEnd(uint8_t(LIGHT_BREAK_END_DEFAULT * 255));
        configuration.setInitialized(true);
    }

    auto temperature = configuration.getTemperature();
    if (temperature < MINIMUM_TEMPERATURE || temperature > MAXIMUM_TEMPERATURE) {
        configuration.setTemperature(MINIMUM_TEMPERATURE);
    }
}

void reconfigureLight(time_t time) {
    DEBUG(F("Reconfiguring light"));
    DEBUG(F("  Low minimum level "), lightLowMinimumLevel.getValue());
    DEBUG(F("  Low maximum level "), lightLowMaximumLevel.getValue());
    DEBUG(F("  High minimum level "), lightHighMinimumLevel.getValue());
    DEBUG(F("  High maximum level "), lightHighMaximumLevel.getValue());
    DEBUG(F("  Break start level "), lightBreakStart.getValue());
    DEBUG(F("  Break end level "), lightBreakEnd.getValue());

    lightLow.reconfigure(
        float(lightLowMinimumLevel.getValue()) / 255.0f,
        float(lightLowMaximumLevel.getValue()) / 255.0f,
        time
    );
    lightHigh.reconfigure(
        float(lightHighMinimumLevel.getValue()) / 255.0f,
        float(lightHighMaximumLevel.getValue()) / 255.0f,
        time
    );
    light.reconfigure(
        float(lightBreakStart.getValue()) / 255.0f,
        float(lightBreakEnd.getValue()) / 255.0f,
        time
    );
}

void saveLightConfiguration() {
    configuration.setLightLowMinimumLevel(lightLowMinimumLevel.getValue());
    configuration.setLightLowMaximumLevel(lightLowMaximumLevel.getValue());
    configuration.setLightHighMinimumLevel(lightHighMinimumLevel.getValue());
    configuration.setLightHighMaximumLevel(lightHighMaximumLevel.getValue());
    configuration.setLightBreakStart(lightBreakStart.getValue());
    configuration.setLightBreakEnd(lightBreakEnd.getValue());
}

void loop() {
    status.update();
    light.update();
    deviceManager.update();
    buttons.update();

    if (buttons.rose(0)) {
        DEBUG(F("Button 0 pressed, sending on command"));
        onOffCluster.sendOnCommand(deviceManager, 1);
    }
    if (buttons.rose(1)) {
        DEBUG(F("Button 1 pressed, sending off command"));
        onOffCluster.sendOffCommand(deviceManager, 1);
    }
    if (buttons.rose(2)) {
        DEBUG(F("Button 2 pressed, sending move up command"));
        levelCtrlCluster.sendMoveCommand(deviceManager, 1, 0 /* up */, 0xff /* default rate */);
    }
    if (buttons.rose(3)) {
        DEBUG(F("Button 3 pressed, sending move down command"));
        levelCtrlCluster.sendMoveCommand(deviceManager, 1, 1 /* down */, 0xff /* default rate */);
    }
}

bool isOn() {
    return onOffCluster.getOnOff()->getValue();
}
