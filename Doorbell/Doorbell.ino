#include <SoftwareSerial.h>
#include "ZigBeeHomeAutomation.h"
#include "Bounce2.h"
#include "Configuration.h"
#include "Doorbell.h"

constexpr uint8_t IO_XBEE_RX = 11;
constexpr uint8_t IO_XBEE_TX = 12;
constexpr uint8_t IO_STATUS_LED = 3;
constexpr uint8_t IO_PB = 2;
constexpr uint8_t IO_RELAY = 4;
constexpr uint8_t IO_DOORBELL = 5;

constexpr bool DEFAULT_DOORBELL_ON = true;

SoftwareSerial xbeeSerial(IO_XBEE_RX, IO_XBEE_TX);
DeviceManager deviceManager;
BasicDevice doorbellDevice(1, 1, PowerSource::MainsSinglePhase);
StatusControl status;
Configuration configuration;
Doorbell doorbell(Bounce(IO_DOORBELL, 50), IO_RELAY);

static void setEnabled(bool enabled);
static bool isEnabled();
void setRinging(bool ringing);
static void setupConfiguration();
static void saveConfiguration();

class : public GenOnOffCluster {
public:
    Status onOnCommand() override {
        INFO(F("Doorbell enabled"));
        setEnabled(true);
        return Status::Success;
    }

    Status onOffCommand() override {
        INFO(F("Doorbell disabled"));
        setEnabled(false);
        return Status::Success;
    }

    Status onToggleCommand() override {
        INFO(F("Doorbell toggle"));
        setEnabled(!isEnabled());
        return Status::Success;
    }
} onOffCluster;

void setup() {
    LOG_BEGIN();

    setupConfiguration();

    deviceManager.addDevice(doorbellDevice);
    doorbellDevice.addCluster(onOffCluster);
    doorbellDevice.getBasicCluster().getManufacturerName()->setValue(F("Pieter"));
    doorbellDevice.getBasicCluster().getModelId()->setValue(F("Doorbell"));

    // Setup operational attributes.

    onOffCluster.getOnOff()->configureBroadcastReporting();

    // Setup status.

    status.onClick([](uintptr_t) {
        // No default action.
    });

    status.onReset([](uintptr_t) {
        deviceManager.performReset();
    });

    status.setBounce(Bounce(IO_PB, 50));
    status.setLed(IO_STATUS_LED);

    // Start XBee.

    xbeeSerial.begin(9600);

    deviceManager.setConnectedCallback([](ConnectionStatus connectionStatus, uintptr_t) {
        status.setConnected(connectionStatus);
    });

    deviceManager.begin(xbeeSerial);

    // Set the default mode of the doorbell.

    doorbell.onRing([](uintptr_t) {
        DEBUG(F("Doorbell is ringing, sending on command"));

        onOffCluster.sendOnCommand(deviceManager, 1);
    });

    setEnabled(configuration.getDoorbellEnabled());
}

void setupConfiguration() {
    configuration.begin();

    if (!configuration.isInitialized()) {
        configuration.setDoorbellEnabled(DEFAULT_DOORBELL_ON);
        configuration.setInitialized(true);
    }
}

void saveConfiguration() {
    configuration.setDoorbellEnabled(onOffCluster.getOnOff()->getValue());
}

void loop() {
    doorbell.update();
    status.update();
    deviceManager.update();
}

bool isEnabled() {
    return onOffCluster.getOnOff()->getValue();
}

void setEnabled(bool enabled) {
    DEBUG(F("Setting doorbell to "), enabled ? F("enabled") : F("disabled"));

    onOffCluster.getOnOff()->setValue(enabled);
    doorbell.setEnabled(enabled);

    saveConfiguration();
}
