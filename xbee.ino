// #include "Zigbee.h"
#include "Zigbee.h"
#include "Button.h"
#include <XBee.h>
#include <SoftwareSerial.h>
#include "support.h"

#define IO_XBEE_RX 2
#define IO_XBEE_TX 3
#define IO_PB 4
#define IO_LED 5

Zigbee device;
SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
Button pb(IO_PB);

void setup()
{
    while (!Serial);

    LOG("Serial ready");

    pinMode(IO_PB, INPUT);
    pinMode(IO_LED, OUTPUT);

    xbeeSerial.begin(9600);

    device.begin(xbeeSerial);

    LOG("Running configuration");

    device.performReset();

    //xbee.begin(xbeeSerial);
}

int lastMode = 0;
bool lastLed;

void loop()
{
    device.loop();

    /*
    if (pb.clicked()) {
        lastLed = !lastLed;
        digitalWrite(IO_LED, lastLed);
    }

    handleXbee();
    */
}
