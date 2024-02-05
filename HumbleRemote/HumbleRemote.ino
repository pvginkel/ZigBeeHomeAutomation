#include <ZigBeeHomeAutomation.h>
#include "Remote.h"
#include "HumbleLight.h"

constexpr uint8_t IO_PB = 2;
constexpr uint8_t IO_STATUS_LED = 3;
constexpr uint8_t IO_XBEE_RESET = 15;
constexpr uint8_t IO_POT = A3;
constexpr uint8_t IO_BUTTON_1 = 10;
constexpr uint8_t IO_BUTTON_2 = 16;
constexpr uint8_t IO_BUTTON_3 = 9;
constexpr uint8_t IO_BUTTON_4 = 8;
constexpr uint8_t IO_BUTTON_5 = 7;

DeviceManager deviceManager;
BasicDevice remoteDevice(1, 1, PowerSource::DCSource);
StatusControl status;
HumbleLight light(Remote(IO_BUTTON_1, IO_BUTTON_2, IO_BUTTON_3, IO_BUTTON_4, IO_BUTTON_5, IO_POT));

class : public GenOnOffCluster {
public:
	Status onOffCommand() override {
		INFO(F("Lamp off"));
		light.setLevel(0);
		return Status::Success;
	}

	Status onOnCommand() override {
		INFO(F("Lamp on"));
		light.setLevel(1);
		return Status::Success;
	}

	Status onToggleCommand() override {
		INFO(F("Lamp toggle"));
		light.setLevel(light.isOn() ? 0 : 1);
		return Status::Success;
	}
} onOffCluster;

class : public GenLevelCtrlCluster {
public:
	Status onMoveToLevelWithOnOffCommand(uint8_t level, uint16_t transtime) override {
		INFO(F("Level change to "), level);
		light.setLevel(float(level) / 254.0f);
		return Status::Success;
	}
} levelCtrlCluster;


void setup() {
	deviceManager.addDevice(remoteDevice);
	remoteDevice.addCluster(onOffCluster);
	remoteDevice.addCluster(levelCtrlCluster);

	remoteDevice.getBasicCluster().getManufacturerName()->setValue(F("Pieter"));
	remoteDevice.getBasicCluster().getModelId()->setValue(F("Humble Remote"));

	LOG_BEGIN();

	status.onClick([](uintptr_t) { light.setLevel(light.isOn() ? 0 : 1); });
	status.onReset([](uintptr_t) { deviceManager.performReset(); });
	status.setBounce(Bounce(IO_PB, 50));
	status.setLed(IO_STATUS_LED);

	Serial1.begin(9600);

	deviceManager.setConnectedCallback(
		[](ConnectionStatus connectionStatus, uintptr_t) { status.setConnected(connectionStatus); }
	);

	deviceManager.resetDevice(IO_XBEE_RESET);

	deviceManager.begin(Serial1);

	onOffCluster.getOnOff()->configureBroadcastReporting();
	levelCtrlCluster.getCurrentLevel()->configureBroadcastReporting();

	light.onLevelChanged([](float level, uintptr_t) {
		onOffCluster.getOnOff()->setValue(level > 0);
		levelCtrlCluster.getCurrentLevel()->setValue(uint8_t(level * 254.0f));
	});

	light.begin();

	light.setLevel(0);
}

void loop() {
	light.update();
	status.update();
	deviceManager.update();
}
