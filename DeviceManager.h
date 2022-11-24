#pragma once

#include "Memory.h"
#include "Device.h"
#include "StatusCb.h"
#include "Support.h"

#define ZHA_PROFILE_ID 0x0104

#define ZDO_SIMPLE_DESCRIPTOR_REQUEST             0x0004
#define ZDO_SIMPLE_DESCRIPTOR_RESPONSE            0x8004
#define ZDO_ACTIVE_ENDPOINTS_REQUEST              0x0005
#define ZDO_ACTIVE_ENDPOINTS_RESPONSE             0x8005
#define ZDO_MATCH_DESCRIPTOR_REQUEST              0x0006
#define ZDO_MATCH_DESCRIPTOR_RESPONSE             0x8006
#define ZDO_DEVICE_ANNOUNCE                       0x0013

class DeviceManager {
	typedef AtCommandRequest(*command_builder_t)(int);

	enum class State {
		Connected,
		Resetting,
		RetrievingConfiguration,
		RetrievingAssociationIndication
	};

	static constexpr int AT_COMMAND_RETRY_MS = 1000;
	static constexpr int ASSOCIATION_INDICATION_REFRESH_MS = 1000;

	static void atCommandCallbackThunk(AtCommandResponse& command, uintptr_t data) {
		((DeviceManager*)data)->atCommandCallback(command);
	}
	static void modemStatusCallbackThunk(ModemStatusResponse& status, uintptr_t data) {
		((DeviceManager*)data)->modemStatusCallback(status);
	}
	static void explicitRxCallbackThunk(ZBExplicitRxResponse& status, uintptr_t data) {
		((DeviceManager*)data)->explicitRxCallback(status);
	}

	LinkedList<Device*> _deviceList;
	XBeeAddress64 _address;
	uint16_t _shortAddress;

	XBeeAddress64 _broadcastAddress;
	uint16_t _shortBroadcastAddress;

	/* reusable data payload */
	Memory _buffer;
	uint8_t _payload[MAX_FRAME_DATA_SIZE];

	XBeeWithCallbacks _device;

	command_builder_t _commandBuilder;
	int _commandBuilderOffset;
	State _state;
	time_t _lastSendMillis;
	uint8_t _associationIndication;
	time_t _associationIndicationMillis;
	LinkedList<StatusCb*> _statusCbs;

public:
	DeviceManager();
	void begin(Stream& stream);
	void performReset();
	void update();

	void addDevice(Device* dev);
	void addStatusCb(StatusCb& statusCb);

private:
	void sendAnnounce();
	void processZDO(XBeeAddress64 remoteAddr64, uint16_t remoteAddr16, uint16_t clusterId, uint8_t* frameData, uint8_t frameDataLength);

	Device* getDeviceByEndpoint(uint8_t endpointId);

	void reportAttributes();

	void atCommandCallback(AtCommandResponse& at);
	void modemStatusCallback(ModemStatusResponse& status);
	void explicitRxCallback(ZBExplicitRxResponse& status);

	void setCommandBuilder(command_builder_t commandBuilder);
	bool sendNextCommand();
	void sendCurrentCommand();
	void retrieveAssociationIndication();	
	void retrieveConfiguration();
	void setStatus(const String& status);
	void setConnected(ConnectionStatus connected);

	static const char* getAssociationIndicationDescription(uint8_t associationIndication);
	static const char* getShortAssociationIndicationDescription(uint8_t associationIndication);
};
