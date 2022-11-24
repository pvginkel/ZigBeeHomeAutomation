#include "ZigBee.h"
#include "Clusters.h"

void setup() {
}

void loop() {
}

//#include <Bounce2.h>
//#include <SoftwareSerial.h>
//#include "LevelControlOutputDevice.h"
//#include "Display.h"
//#include "StatusControl.h"
//#include "support.h"
//#include "ZHA_DeviceManager.h"
//#include "Clusters.h"
//
//U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0);
//
//#define SCREEN_HEIGHT 32
//#define SCREEN_WIDTH 128
//
//#define IO_XBEE_RX 2
//#define IO_XBEE_TX 3
//#define IO_PB 4
//#define IO_LED 5
//#define IO_STATUS_LED 6
//
//ZHA_DeviceManager device;
//SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
//LevelControlOutputDevice lightbulb(8);
//Display display;
//StatusControl status;
//
//static void updateButton();
//static void on(uintptr_t);
//static void off(uintptr_t);
//static void toggle(uintptr_t);
//static void setLevel(uint8_t level, uint16_t transitionTime, uintptr_t);
//static void reset(uintptr_t);
//static void resetCountdown(int remaining, uintptr_t);
//
//void setup()
//{
//    while (!Serial);
//
//    DEBUG("Serial ready");
//
//    u8g2.begin();
//    display.begin(u8g2, SCREEN_WIDTH, SCREEN_HEIGHT);
//
//    status.onClick(toggle);
//    status.onReset(reset);
//    status.onResetCountdown(resetCountdown);
//    status.setBounce(Bounce(IO_PB, 50));
//    status.setLed(IO_STATUS_LED);
//
//    pinMode(IO_PB, INPUT);
//    pinMode(IO_LED, OUTPUT);
//
//    lightbulb.getOnOffCluster()->setOnCallback(on);
//    lightbulb.getOnOffCluster()->setOffCallback(off);
//    lightbulb.getOnOffCluster()->setToggleCallback(toggle);
//    lightbulb.getLevelControlCluster()->setMoveToLevelWithOnOffCallback(setLevel);
//    lightbulb.getBasicCluster()->setManufacturerName(String("GE_Appliances"));
//    lightbulb.getBasicCluster()->setModelIdentifier(String("ZLL Light"));
//
//    device.addDevice(&lightbulb);
//
//    xbeeSerial.begin(9600);
//
//    device.addStatusCb(display);
//    device.addStatusCb(status);
//
//    device.begin(xbeeSerial);
//}
//
//void loop()
//{
//    status.update();
//    device.update();
//    display.update();
//}
//
//void on(uintptr_t) {
//    digitalWrite(IO_LED, HIGH);
//    display.setBrightness(255);
//}
//
//void off(uintptr_t) {
//    digitalWrite(IO_LED, LOW);
//    display.setBrightness(0);
//}
//
//void toggle(uintptr_t) {
//    bool on = !digitalRead(IO_LED);
//    digitalWrite(IO_LED, on);
//    display.setBrightness(on ? 255 : 0);
//}
//
//void setLevel(uint8_t level, uint16_t transitionTime, uintptr_t) {
//    analogWrite(IO_LED, level);
//    display.setBrightness(level);
//}
//
//void reset(uintptr_t) {
//    device.performReset();
//}
//
//void resetCountdown(int remaining, uintptr_t) {
//    if (remaining > 0) {
//        display.setStatus("Resetting in " + String(remaining));
//    }
//    else if (remaining == 0) {
//        display.setStatus("Resetting NOW");
//    }
//}
