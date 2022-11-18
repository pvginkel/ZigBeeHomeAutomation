#include "LevelControlOutputDevice.h"
#include "Button.h"
#include <XBee.h>
#include <SoftwareSerial.h>
#include "support.h"
#include "ZHA_DeviceManager.h"

#define IO_XBEE_RX 2
#define IO_XBEE_TX 3
#define IO_PB 4
#define IO_LED 5

void on(uintptr_t) { digitalWrite(IO_LED, HIGH); }
void off(uintptr_t) { digitalWrite(IO_LED, LOW); }
void toggle(uintptr_t) { digitalWrite(IO_LED, !digitalRead(IO_LED)); }

void setLevel(uint8_t level, uint16_t transitionTime, uintptr_t) {
    analogWrite(IO_LED, level);
}

ZHA_DeviceManager device;
SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
Button pb(IO_PB);
LevelControlOutputDevice lightbulb(0x8);

void setup()
{
    while (!Serial);

    LOG("Serial ready");

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
}
