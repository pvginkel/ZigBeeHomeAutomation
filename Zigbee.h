#pragma once

#include "Arduino.h"
#include <XBee.h>
#include <SoftwareSerial.h>
#include <LinkedList.h>
#include "XBeeConfig.h"
#include "support.h"

class Zigbee
{
	static constexpr int STATE_CONNECTED = 0;
	static constexpr int STATE_RESETTING = 1;
	static constexpr int STATE_RETRIEVING_CONFIGURATION = 2;
	static constexpr int STATE_RETRIEVING_ASSOCIATION_INDICATION = 3;
	static constexpr int AT_COMMAND_RETRY_MS = 1000;
	static constexpr int ASSOCIATION_INDICATION_REFRESH_MS = 1000;

	static void atCommandCallbackThunk(AtCommandResponse& command, uintptr_t data) {
		((Zigbee*)data)->atCommandCallback(command);
	}

	XBeeWithCallbacks _xbee;
	command_builder_t _commandBuilder{};
	int _commandBuilderOffset{};
	int _state{};
	XBeeAddress64 _macAddr;
	uint16_t _netAddr{};
	time_t _lastSendMillis{};
	uint8_t _associationIndication{};
	time_t _associationIndicationMillis{};

public:
	Zigbee();
	void begin(Stream& stream);
	void performReset();
	void setCommandBuilder(command_builder_t commandBuilder);
	void loop();

private:
	bool sendNextCommand();
	void sendCurrentCommand();
	void atCommandCallback(AtCommandResponse& command);
	void retrieveAssociationIndication();
	void retrieveConfiguration();
	AT_BUILDER(associationIndicationCommand, "AI");
	static const char* getAssociationIndicationDescription(uint8_t associationIndication);
};
