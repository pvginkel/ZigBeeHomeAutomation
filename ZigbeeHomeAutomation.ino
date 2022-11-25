#include <Bounce2.h>
#include <SoftwareSerial.h>
#include "ZigBee.h"
#include "Display.h"

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

#define SCREEN_HEIGHT 32
#define SCREEN_WIDTH 128

#define IO_XBEE_RX 2
#define IO_XBEE_TX 3
#define IO_PB 4
#define IO_LED 5
#define IO_STATUS_LED 6

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice lightBulb(1, 1, PowerSource::DCSource);
Display display;
StatusControl status;

static bool isOn();
static void setLevel(int level);
static void toggle(uintptr_t);
static void updateButton();
static void reset(uintptr_t);
static void resetCountdown(int remaining, uintptr_t);

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
    lightBulb.addInCluster(onOffCluster);
    lightBulb.addInCluster(levelCtrlCluster);
    lightBulb.getBasicCluster().getManufacturerName()->setValue(String(F("GE_Appliances")));
    lightBulb.getBasicCluster().getModelId()->setValue(String(F("ZLL Light")));

    while (!Serial);

    DEBUG(F("Serial ready"));

    u8g2.begin();
    display.begin(u8g2, SCREEN_WIDTH, SCREEN_HEIGHT);

    status.onClick(toggle);
    status.onReset(reset);
    status.onResetCountdown(resetCountdown);
    status.setBounce(Bounce(IO_PB, 50));
    status.setLed(IO_STATUS_LED);

    pinMode(IO_PB, INPUT);
    pinMode(IO_LED, OUTPUT);

    xbeeSerial.begin(9600);

    deviceManager.addStatusCb(display);
    deviceManager.addStatusCb(status);

    deviceManager.begin(xbeeSerial);

    setLevel(255);
}

void loop() {
    status.update();
    deviceManager.update();
    display.update();
}

void toggle(uintptr_t) {
    setLevel(isOn() ? 0 : 255);
}

bool isOn() {
    return onOffCluster.getOnOff();
}

void setLevel(int level) {
    onOffCluster.getOnOff()->setValue(!!level);
    levelCtrlCluster.getCurrentLevel()->setValue(level);
    analogWrite(IO_LED, level);
    display.setBrightness(level);
}

void reset(uintptr_t) {
    deviceManager.performReset();
}

void resetCountdown(int remaining, uintptr_t) {
    if (remaining > 0) {
        display.setStatus(String(F("Resetting in ")) + remaining);
    }
    else if (remaining == 0) {
        display.setStatus(F("Resetting NOW"));
    }
    else {
        display.setStatus(String());
    }
}
