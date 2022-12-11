#include <SoftwareSerial.h>
#include <ZigBeeHomeAutomation.h>

#define IO_XBEE_TX 2
#define IO_XBEE_RX 3
#define IO_STATUS_LED 4
#define IO_PB 5
#define IO_LED 6

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice clockDevice(1, 1, PowerSource::DCSource);
StatusControl status;

static bool isOn();
static void setOn(bool on);
static void toggle();
static void updateButton();

class : public GenOnOffCluster {
public:
    Status offCommand() override {
        INFO(F("Clock on"));
        setOn(false);
        return Status::Success;
    }

    Status onCommand() override {
        INFO(F("Clock off"));
        setOn(true);
        return Status::Success;
    }

    Status toggleCommand() override {
        INFO(F("Clock toggle"));
        toggle();
        return Status::Success;
    }
} onOffCluster;

void setup() {
    deviceManager.addDevice(clockDevice);
    clockDevice.addCluster(onOffCluster);
    clockDevice.getBasicCluster().getManufacturerName()->setValue(String(F("Pieter")));
    clockDevice.getBasicCluster().getModelId()->setValue(String(F("The Big Clock")));

    onOffCluster.getOnOff()->configureBroadcastReporting();

    Serial.begin(115200);
    while (!Serial);

    DEBUG(F("Serial ready"));

    status.onClick([](uintptr_t) { toggle(); });
    status.onReset([](uintptr_t) { deviceManager.performReset(); });
    status.setBounce(Bounce(IO_PB, 50));
    status.setLed(IO_STATUS_LED);

    pinMode(IO_PB, INPUT);
    pinMode(IO_LED, OUTPUT);

    xbeeSerial.begin(9600);

    deviceManager.setConnectedCallback(
        [](ConnectionStatus connectionStatus, uintptr_t) { status.setConnected(connectionStatus); }
    );

    deviceManager.begin(xbeeSerial);

    setOn(true);
}

void loop() {
    status.update();
    deviceManager.update();
}

void toggle() {
    setOn(!isOn());
}

bool isOn() {
    return onOffCluster.getOnOff()->getValue();
}

void setOn(bool on) {
    onOffCluster.getOnOff()->setValue(on);
    digitalWrite(IO_LED, on);
}
