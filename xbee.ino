#include "LevelControlOutputDevice.h"
#include "Button.h"
#include <XBee.h>
#include <SoftwareSerial.h>

#include "Display.h"
#include "support.h"
#include "ZHA_DeviceManager.h"

U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);

#define SCREEN_HEIGHT 32
#define SCREEN_WIDTH 128

#define IO_XBEE_RX 2
#define IO_XBEE_TX 3
#define IO_PB 4
#define IO_LED 5

ZHA_DeviceManager device;
SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
Button pb(IO_PB);
LevelControlOutputDevice lightbulb(0x8);
Display display;

void on(uintptr_t) {
    digitalWrite(IO_LED, HIGH);
    display.setBrightness(255);
}
void off(uintptr_t) {
    digitalWrite(IO_LED, LOW);
    display.setBrightness(0);
}
void toggle(uintptr_t) {
    bool on = !digitalRead(IO_LED);
    digitalWrite(IO_LED, on);
    display.setBrightness(on ? 255 : 0);
}
void setLevel(uint8_t level, uint16_t transitionTime, uintptr_t) {
    analogWrite(IO_LED, level);
    display.setBrightness(level);
}

void setup()
{
    while (!Serial);

    LOG("Serial ready");

    u8g2.begin();
    display.begin(u8g2, SCREEN_WIDTH, SCREEN_HEIGHT);

    pinMode(IO_PB, INPUT);
    pinMode(IO_LED, OUTPUT);

    lightbulb.getOnOffCluster()->setOnCallback(on);
    lightbulb.getOnOffCluster()->setOffCallback(off);
    lightbulb.getOnOffCluster()->setToggleCallback(toggle);
    lightbulb.getLevelControlCluster()->setMoveToLevelWithOnOffCallback(setLevel);
    lightbulb.getBasicCluster()->setManufacturerName(String("GE_Appliances"));
    lightbulb.getBasicCluster()->setModelIdentifier(String("ZLL Light"));

    device.addDevice(&lightbulb);

    xbeeSerial.begin(9600);

    device.setDisplay(display);
    device.begin(xbeeSerial);

    LOG("Running configuration");

    //device.performReset();
}

int lastMode = 0;
bool lastLed;

void loop()
{
    device.loop();

    if (pb.clicked()) {
        device.performReset();
    }

    display.loop();
}
