#define DISPLAY 1

#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>

#include "Light.h"
#if DISPLAY
#include "Display.h"

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

#define SCREEN_HEIGHT 32
#define SCREEN_WIDTH 128

Display display;
#endif

#define IO_XBEE_RX 6
#define IO_XBEE_TX 5
#define IO_PB 7
#define IO_LED 3
#define IO_STATUS_LED 11

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice lightBulb(1, 1, PowerSource::DCSource);
StatusControl status;
Light light(5);

static bool isOn();
static void toggle(uintptr_t);
static void updateButton();
static void reset(uintptr_t);
static void resetCountdown(int remaining, uintptr_t);
static void onConnected(ConnectionStatus connectionStatus, uintptr_t);
static void onStatus(const String& message, uintptr_t);

class : public GenOnOffCluster {
public:
    Status offCommand() override {
        INFO(F("Lamp on"));
        light.setLevel(0, 1000);
        return Status::Success;
    }

    Status onCommand() override {
        INFO(F("Lamp off"));
        light.setLevel(255, 1000);
        return Status::Success;
    }

    Status toggleCommand() override {
        INFO(F("Lamp toggle"));
        light.setLevel(isOn() ? 0 : 255, 1000);
        return Status::Success;
    }
} onOffCluster;

class : public GenLevelCtrlCluster {
public:
    Status moveToLevelWithOnOffCommand(uint8_t level, uint16_t transtime) override {
        INFO(F("Level change to "), level, F(" transition time "), (transtime * 100), F(" ms"));
        light.setLevel(level, transtime * 100);
        return Status::Success;
    }
} levelCtrlCluster;

void setup()
{
    deviceManager.addDevice(lightBulb);
    lightBulb.addCluster(onOffCluster);
    lightBulb.addCluster(levelCtrlCluster);
    lightBulb.getBasicCluster().getManufacturerName()->setValue(String(F("Pieter")));
    lightBulb.getBasicCluster().getModelId()->setValue(String(F("Lamp")));

    onOffCluster.getOnOff()->configureBroadcastReporting();
    levelCtrlCluster.getCurrentLevel()->configureBroadcastReporting();

    light.onLevelChanged([](int level, uintptr_t) {
        onOffCluster.getOnOff()->setValue(!!level);
        levelCtrlCluster.getCurrentLevel()->setValue(level);
#if DISPLAY
        display.setBrightness(level);
#endif
    });

    Serial.begin(115200);
    while (!Serial);

    DEBUG(F("Serial ready"));

#if DISPLAY
    u8g2.begin();
    display.begin(u8g2, SCREEN_WIDTH, SCREEN_HEIGHT, 5000ul);
#endif

    status.onClick(toggle);
    status.onReset(reset);
    status.onResetCountdown(resetCountdown);
    status.setBounce(Bounce(IO_PB, 50));
    status.setLed(IO_STATUS_LED);

    xbeeSerial.begin(9600);

    deviceManager.setConnectedCallback(onConnected);
    deviceManager.setStatusCallback(onStatus);

    deviceManager.begin(xbeeSerial);

    light.begin(IO_LED);
    light.setLevel(0);
}

void loop() {
    status.update();
    light.update();
    deviceManager.update();
#if DISPLAY
    display.update();
#endif
}

void toggle(uintptr_t) {
    light.setLevel(isOn() ? 0 : 255, 1000);
}

bool isOn() {
    return onOffCluster.getOnOff()->getValue();
}

void reset(uintptr_t) {
    deviceManager.performReset();
}

void resetCountdown(int remaining, uintptr_t) {
#if DISPLAY
    if (remaining > 0) {
        display.setStatus(String(F("Resetting in ")) + remaining);
    }
    else if (remaining == 0) {
        display.setStatus(F("Resetting NOW"));
    }
    else {
        display.setStatus(String());
    }
#endif
}

static void onConnected(ConnectionStatus connectionStatus, uintptr_t) {
#if DISPLAY
    display.setConnected(connectionStatus);
#endif
    status.setConnected(connectionStatus);
}

static void onStatus(const String& message, uintptr_t) {
#if DISPLAY
    display.setStatus(message);
#endif
}
