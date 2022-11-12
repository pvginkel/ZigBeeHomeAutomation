// #include "Zigbee.h"
#include "Button.h"
#include <XBee.h>
#include "XBeeConfig.h"
#include <Printers.h>
#include <SoftwareSerial.h>
#include "support.h"

#define IO_XBEE_RX 2
#define IO_XBEE_TX 3
#define IO_PB 4
#define IO_LED 5

XBee xbee;
SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
Button pb(IO_PB);

void setup()
{
    while (!Serial);

    LOG("Serial ready");

    pinMode(IO_PB, INPUT);
    pinMode(IO_LED, OUTPUT);

    xbeeSerial.begin(9600);

    LOG("Running configuration");

    XBeeConfig xbeeConfig(xbeeSerial);
    xbeeConfig.enterConfig();

    LOG("Writing configuration...");
/*
    //LOG("ATNR Network Reset: ", xbeeConfig.send("NR"));
    LOG("ATRE Restore Defaults: ", xbeeConfig.send("RE"));
    LOG("ATNI Node Identifier: ", xbeeConfig.send("NI TEST LAMP 1"));
    LOG("ATZS Zigbee Stack Profile: ", xbeeConfig.send("ZS 2"));
    LOG("ATNJ Node Join Time: ", xbeeConfig.send("NJ 5A"));
    LOG("ATNO Network Discovery Options: ", xbeeConfig.send("NO 3"));
    LOG("ATEE Encryption Enable: ", xbeeConfig.send("EE 1"));
    LOG("ATEO Encryption Options: ", xbeeConfig.send("EO 2"));
    LOG("ATSN Number of Cycles Between ON_SLEEP: ", xbeeConfig.send("SN AF0"));
    LOG("ATSP Sleep Period: ", xbeeConfig.send("SP 64"));
    LOG("ATKY Link Key: ", xbeeConfig.send("KY 5A6967426565416C6C69616E63653039"));
    //LOG("ATCH Operating Channel: ", xbeeConfig.send("CH B"));
    //LOG("ATID Extended PAN ID: ", xbeeConfig.send("ID 1A62"));
*/
    /** ANOTHER ATTEMPT **/

    LOG("ATRE Restore Defaults: ", xbeeConfig.send("RE"));
    LOG("ATNR Network Reset: ", xbeeConfig.send("NR 0"));
    LOG("ATNI Node Identifier: ", xbeeConfig.send("NI TEST LAMP 1"));
    LOG("ATZS Zigbee Stack Profile: ", xbeeConfig.send("ZS 2"));
    LOG("ATNJ Node Join Time: ", xbeeConfig.send("NJ 5A"));
    LOG("ATEE Encryption Enable: ", xbeeConfig.send("EE 1"));
    LOG("ATEO Encryption Options: ", xbeeConfig.send("EO 1"));
    LOG("ATKY Link Key: ", xbeeConfig.send("KY 5A6967426565416C6C69616E63653039"));
    LOG("ATEO D6 (DIO6/RTS): ", xbeeConfig.send("D6 0"));
    LOG("ATAP API Enable: ", xbeeConfig.send("AP"));
    LOG("ATAP API Enable: ", xbeeConfig.send("AP 1"));
    LOG("ATAP API Options: ", xbeeConfig.send("AO 3"));
    //LOG("ATSC Scan Channels: ", xbeeConfig.send("SC 0001"));
    LOG("ATSC Scan Channels: ", xbeeConfig.send("SC FFFF"));

    /** ANOTHER ATTEMPT **/

    //xbeeConfig.printConfig();

    LOG("Applying and writing...");

    //LOG("ATAC Apply Changes: ", xbeeConfig.send("AC"));
    LOG("ATWR Write: ", xbeeConfig.send("WR"));
    LOG("ATFR Software Reset: ", xbeeConfig.send("FR"));

    xbeeConfig.exitConfig();

    delay(2000);

    LOG("Verifying configuration...");

    xbeeConfig.enterConfig();

    LOG("ATNI Node Identifier: ", xbeeConfig.send("NI"));
    LOG("ATSC Scan Channels: ", xbeeConfig.send("SC"));
    LOG("ATID Extended PAN ID: ", xbeeConfig.send("ID"));

    while (true) {
        auto ai = xbeeConfig.send("AI");
        if (strtol(ai, 0, 16) == 0) {
            break;
        }

        LOG("ATAI Association Indication: ", ai);
        delay(1000);
    }

    xbeeConfig.exitConfig();

    LOG("Joined network");

    //xbee.begin(xbeeSerial);
}

int lastMode = 0;
bool lastLed;

void loop()
{
    if (xbeeSerial.available()) {
        LOG("0x", String(xbeeSerial.read(), 16));
    }

    /*
    if (pb.clicked()) {
        lastLed = !lastLed;
        digitalWrite(IO_LED, lastLed);
    }

    handleXbee();
    */
}

void handleXbee() {
    xbee.readPacket();
    if (!xbee.getResponse().isAvailable()) {
        return;
    }

    int frameType = xbee.getResponse().getApiId();
    LOG("Frame type: ", frameType);
}