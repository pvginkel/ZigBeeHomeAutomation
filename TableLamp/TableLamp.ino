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

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice lightBulb(1, 1, PowerSource::MainsSinglePhase);
StatusControl status;
NaturalDualTemperatureLight light(
    NaturalTemperatureLight(0.02f, 1.0f, MINIMUM_TEMPERATURE, MAXIMUM_TEMPERATURE),
    NaturalTemperatureLight(0.02f, 1.0f, MINIMUM_TEMPERATURE, MAXIMUM_TEMPERATURE),
    0.04f /* breakStart */,
    0.07f /* breakEnd */
);
ButtonArray<4> buttons;
Configuration configuration;

static bool isOn();
static void updateButton();
static void setupConfiguration();

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

    light.begin(IO_LAMP_LOW_COLD, IO_LAMP_LOW_WARM, IO_LAMP_HIGH_COLD, IO_LAMP_HIGH_WARM);
    light.setLevel(0);
}

void setupConfiguration() {
    configuration.begin();

    if (!configuration.isInitialized()) {
        configuration.setTemperature(MINIMUM_TEMPERATURE);
        configuration.setInitialized(true);
    }

    auto temperature = configuration.getTemperature();
    if (temperature < MINIMUM_TEMPERATURE || temperature > MAXIMUM_TEMPERATURE) {
        configuration.setTemperature(MINIMUM_TEMPERATURE);
    }
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
