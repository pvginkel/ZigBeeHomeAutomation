#pragma once

#include "Buffer.h"
#include "XBeeConfig.h"
#include "ZHA_Devices.h"
#include "ZHA_Utils.h"

#define ZHA_PROFILE_ID 0x0104

/* ZDOs */
#define ZDO_SIMPLE_DESCRIPTOR_REQUEST             0x0004
#define ZDO_SIMPLE_DESCRIPTOR_RESPONSE            0x8004
#define ZDO_ACTIVE_ENDPOINTS_REQUEST              0x0005
#define ZDO_ACTIVE_ENDPOINTS_RESPONSE             0x8005
#define ZDO_MATCH_DESCRIPTOR_REQUEST              0x0006
#define ZDO_MATCH_DESCRIPTOR_RESPONSE             0x8006
#define ZDO_DEVICE_ANNOUNCE                       0x0013

class ZHA_DeviceManager {
	static constexpr int STATE_CONNECTED = 0;
	static constexpr int STATE_RESETTING = 1;
	static constexpr int STATE_RETRIEVING_CONFIGURATION = 2;
	static constexpr int STATE_RETRIEVING_ASSOCIATION_INDICATION = 3;
	static constexpr int AT_COMMAND_RETRY_MS = 1000;
	static constexpr int ASSOCIATION_INDICATION_REFRESH_MS = 1000;

	static void atCommandCallbackThunk(AtCommandResponse& command, uintptr_t data) {
		((ZHA_DeviceManager*)data)->atCommandCallback(command);
	}
	static void modemStatusCallbackThunk(ModemStatusResponse& status, uintptr_t data) {
		((ZHA_DeviceManager*)data)->modemStatusCallback(status);
	}
	static void explicitRxCallbackThunk(ZBExplicitRxResponse& status, uintptr_t data) {
		((ZHA_DeviceManager*)data)->explicitRxCallback(status);
	}

	LinkedList<ZHA_Device*> _deviceList;
	XBeeAddress64 _addr64;
	uint16_t _addr16;

	XBeeAddress64 _bcast64;
	uint16_t _bcast16;

	/* reusable data payload */
	Buffer _buffer;
	uint8_t _payload[MAX_FRAME_DATA_SIZE];
	uint8_t _payloadLength;

	XBeeWithCallbacks _device;

	command_builder_t _commandBuilder;
	int _commandBuilderOffset;
	int _state;
	time_t _lastSendMillis;
	uint8_t _associationIndication;
	time_t _associationIndicationMillis;

public:
	ZHA_DeviceManager();
	void begin(Stream& stream);
	void performReset();
	void loop();

	void addDevice(ZHA_Device* dev);

private:
	void sendAnnounce();
	void sendAT(String at);
	void processZDO(XBeeAddress64 remoteAddr64, uint16_t remoteAddr16, uint16_t clusterId, uint8_t* frameData, uint8_t frameDataLength);

	void processGeneralFrame(XBeeAddress64 remoteAddr64, uint16_t remoteAddr16, uint16_t clusterId, uint8_t dstEndpoint, uint8_t srcEndpoint, uint16_t profileId, uint8_t* frameData, uint8_t frameDataLength);

	ZHA_Device* getDeviceByEndpoint(uint8_t endpointId);

	void reportAttributes();

	void atCommandCallback(AtCommandResponse& at);
	void modemStatusCallback(ModemStatusResponse& status);
	void explicitRxCallback(ZBExplicitRxResponse& status);

	void setCommandBuilder(command_builder_t commandBuilder);
	bool sendNextCommand();
	void sendCurrentCommand();
	void retrieveAssociationIndication();	
	void retrieveConfiguration();
	static const char* getAssociationIndicationDescription(uint8_t associationIndication);
};
