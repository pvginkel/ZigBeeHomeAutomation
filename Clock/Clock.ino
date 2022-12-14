#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>

#include "ClockDevice.h"

#define DATA_PIN  2  // DS
#define LATCH_PIN 3  // ST_CP
#define CLOCK_PIN 4 // SH_CP
#define OE_PIN 5

#define RTC_CLK 6
#define RTC_DAT 7
#define RTC_RST 8

#define IO_XBEE_RX 9
#define IO_XBEE_TX 10

#define IO_PB 11
#define IO_STATUS_LED 12

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice clockDevice(1, 1, PowerSource::DCSource);
StatusControl status;
ThreeWire rtcWires(RTC_DAT, RTC_CLK, RTC_RST);
ClockDevice clock(DATA_PIN, LATCH_PIN, CLOCK_PIN, OE_PIN, rtcWires);

static void updateDateTime();

class CurrentDate : public AttributeUInt32 {
public:
	CurrentDate()
		: AttributeUInt32(0x0201, DataType::UInt32) {
	}

    void readValue(Memory& memory) override {
        AttributeUInt32::readValue(memory);
        updateDateTime();
    }
};

class CurrentTime : public AttributeUInt32 {
public:
    CurrentTime()
        : AttributeUInt32(0x0202, DataType::UInt32) {
    }

    void readValue(Memory& memory) override {
        AttributeUInt32::readValue(memory);
        updateDateTime();
    }
};

CurrentDate currentDate;
CurrentTime currentTime;

class : public GenOnOffCluster {
public:
    Status offCommand() override {
        INFO(F("Clock off"));
        clock.setOn(false);
        return Status::Success;
    }

    Status onCommand() override {
        INFO(F("Clock on"));
        clock.setOn(true);
        return Status::Success;
    }

    Status toggleCommand() override {
        INFO(F("Clock toggle"));
        clock.setOn(!clock.isOn());
        return Status::Success;
    }
} onOffCluster;

class : public GenLevelCtrlCluster {
public:
    Status moveToLevelWithOnOffCommand(uint8_t level, uint16_t transtime) override {
        INFO(F("Level change to "), level, F(" transition time "), (transtime * 100), F(" ms"));
        clock.setLevel(level, transtime * time_t(100));
        return Status::Success;
    }
} levelCtrlCluster;

void setup() {
    clockDevice.getBasicCluster().addAttribute(&currentDate);
    clockDevice.getBasicCluster().addAttribute(&currentTime);

    deviceManager.addDevice(clockDevice);
    clockDevice.addCluster(onOffCluster);
    clockDevice.addCluster(levelCtrlCluster);
    clockDevice.getBasicCluster().getManufacturerName()->setValue(String(F("Pieter")));
    clockDevice.getBasicCluster().getModelId()->setValue(String(F("The Big Clock")));

    onOffCluster.getOnOff()->configureBroadcastReporting();
    levelCtrlCluster.getCurrentLevel()->configureBroadcastReporting();

    Serial.begin(115200);
    while (!Serial);

    DEBUG(F("Serial ready"));

    status.onClick([](uintptr_t) { clock.setOn(!clock.isOn()); });
    status.onReset([](uintptr_t) { deviceManager.performReset(); });
    status.setBounce(Bounce(IO_PB, 50));
    status.setLed(IO_STATUS_LED);

    xbeeSerial.begin(9600);

    deviceManager.setConnectedCallback([](ConnectionStatus connectionStatus, uintptr_t) { status.setConnected(connectionStatus); });

    deviceManager.begin(xbeeSerial);

    clock.onOnOffChanged([](bool on, uintptr_t) { onOffCluster.getOnOff()->setValue(on); });
    clock.onLevelChanged([](uint8_t level, uintptr_t) { levelCtrlCluster.getCurrentLevel()->setValue(level); });
    clock.onRequestTimeUpdate([](uintptr_t) { deviceManager.sendAnnounce(); });

    clock.begin();

    onOffCluster.getOnOff()->setValue(true);
    levelCtrlCluster.getCurrentLevel()->setValue(255    );

    clock.setLevel(255, 0);
    clock.setOn(true);
}

void loop() {
    clock.update();
    status.update();
    deviceManager.update();
}

void updateDateTime() {
    // DateTime doesn't really seem to be supported by zigbee2mqtt. Instead,
    // I've split up the date and time component into the two separate components.
    // The format is still as specified in the ZigBee specifications.

    auto date = currentDate.getValue();
    auto time = currentTime.getValue();

    if (date && time) {
        DateTime dateTime(date, time);
        clock.setDateTime(dateTime);

        currentDate.setValue(0);
        currentTime.setValue(0);
    }
}
