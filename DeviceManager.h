#pragma once

enum class ConnectionStatus {
	NotConnected,
	Connecting,
	Connected
};

class DeviceManager {
	static constexpr uint16_t ZhaProfileId = 0x0104;

	enum class ZdoCommand : uint16_t {
		SimpleDescriptorRequest = 0x0004,
		SimpleDescriptorResponse = 0x8004,
		ActiveEndpointsRequest = 0x0005,
		ActiveEndpointsResponse = 0x8005,
		MatchDescriptorRequest = 0x0006,
		MatchDescriptorResponse = 0x8006,
		DeviceAnnounce = 0x0013,
	};

	typedef AtCommandRequest(*command_builder_t)(int);

	enum class State {
		Connected,
		Resetting,
		RetrievingConfiguration,
		RetrievingAssociationIndication
	};

	static constexpr int AT_COMMAND_RETRY_MS = 1000;
	static constexpr int ASSOCIATION_INDICATION_REFRESH_MS = 1000;

	static XBeeAddress64 BROADCAST_ADDR64;
	static constexpr uint16_t BROADCAST_ADDR16 = 0;
	static constexpr uint16_t ANNOUNCE_BROADCAST_ADDR16 = 0xfffc;

	LinkedList<Device*> _deviceList;
	XBeeAddress64 _address;
	uint16_t _shortAddress;

	/* reusable data payload */
	uint8_t _payload[MAX_FRAME_DATA_SIZE];

	XBeeWithCallbacks _device;

	command_builder_t _commandBuilder;
	int _commandBuilderOffset;
	State _state;
	time_t _lastSendMillis;
	uint8_t _associationIndication;
	time_t _associationIndicationMillis;

	CallbackArgs<const String&> _setStatus;
	CallbackArgs<ConnectionStatus> _setConnected;

public:
	DeviceManager();
	void begin(Stream& stream);
	void performReset();
	void update();

	void addDevice(Device& device);

	void setStatusCallback(CallbackArgs<const String&>::Func func, uintptr_t data = 0) {
		_setStatus.set(func, data);
	}
	void setConnectedCallback(CallbackArgs<ConnectionStatus>::Func func, uintptr_t data = 0) {
		_setConnected.set(func, data);
	}

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

	void setStatus(const String& status) {
		_setStatus.call(status);
	}
	void setConnected(ConnectionStatus connected) {
		_setConnected.call(connected);
	}

	static String getAssociationIndicationDescription(uint8_t associationIndication);
	static String getShortAssociationIndicationDescription(uint8_t associationIndication);
};
