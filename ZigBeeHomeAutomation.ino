#define DISPLAY 1

#include <Bounce2.h>
#include <SoftwareSerial.h>
#include "ZigBee.h"

#if DISPLAY
#include "Display.h"

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

#define SCREEN_HEIGHT 32
#define SCREEN_WIDTH 128

Display display;
#endif

#define IO_XBEE_RX 2
#define IO_XBEE_TX 3
#define IO_PB 4
#define IO_LED 5
#define IO_STATUS_LED 6

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice lightBulb(1, 1, PowerSource::DCSource);
StatusControl status;

static bool isOn();
static void setLevel(int level);
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
        setLevel(0);
        return Status::Success;
    }

    Status onCommand() override {
        INFO(F("Lamp off"));
        setLevel(255);
        return Status::Success;
    }

    Status toggleCommand() override {
        INFO(F("Lamp toggle"));
        setLevel(isOn() ? 0 : 255);
        return Status::Success;
    }
} onOffCluster;

class : public GenLevelCtrlCluster {
public:
    Status moveToLevelWithOnOffCommand(uint8_t level, uint16_t transtime) override {
        INFO(F("Level change to "), level);
        setLevel(level);
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

    while (!Serial);

    DEBUG(F("Serial ready"));

#if DISPLAY
    u8g2.begin();
    display.begin(u8g2, SCREEN_WIDTH, SCREEN_HEIGHT);
#endif

    status.onClick(toggle);
    status.onReset(reset);
    status.onResetCountdown(resetCountdown);
    status.setBounce(Bounce(IO_PB, 50));
    status.setLed(IO_STATUS_LED);

    pinMode(IO_PB, INPUT);
    pinMode(IO_LED, OUTPUT);

    xbeeSerial.begin(9600);

    deviceManager.setConnectedCallback(onConnected);
    deviceManager.setStatusCallback(onStatus);

    deviceManager.begin(xbeeSerial);

    setLevel(255);
}

void loop() {
    status.update();
    deviceManager.update();
#if DISPLAY
    display.update();
#endif
}

void toggle(uintptr_t) {
    setLevel(isOn() ? 0 : 255);
}

bool isOn() {
    return onOffCluster.getOnOff()->getValue();
}

void setLevel(int level) {
    onOffCluster.getOnOff()->setValue(!!level);
    levelCtrlCluster.getCurrentLevel()->setValue(level);
    analogWrite(IO_LED, level);
#if DISPLAY
    display.setBrightness(level);
#endif
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
