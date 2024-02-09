#pragma once

enum class ConnectionStatus : uint8_t {
	NotConnected,
	Connecting,
	Connected
};

class DeviceManager {
	enum class ZdoCommand : uint16_t {
		SimpleDescriptorRequest = 0x0004,
		SimpleDescriptorResponse = 0x8004,
		ActiveEndpointsRequest = 0x0005,
		ActiveEndpointsResponse = 0x8005,
		MatchDescriptorRequest = 0x0006,
		MatchDescriptorResponse = 0x8006,
		DeviceAnnounce = 0x0013,
	};

	typedef AtCommandRequest(*command_builder_t)(uint8_t);

	enum class State : uint8_t {
		Connected,
		Resetting,
		RetrievingConfiguration,
		RetrievingAssociationIndication
	};

	class PendingZDORequest {
	public:
		PendingZDORequest(const XBeeAddress64& dst64, uint16_t dst16, uint16_t clusterId, uint8_t* frameData,
			uint8_t frameDataLength)
			: dst64(dst64),
			  dst16(dst16),
			  clusterId(clusterId),
			  frameDataLength(frameDataLength) {
			this->frameData = malloc(frameDataLength);
			memcpy(this->frameData, frameData, frameDataLength);
		}

		~PendingZDORequest() {
			free(frameData);
		}

		XBeeAddress64 dst64;
		uint16_t dst16;
		uint16_t clusterId;
		uint8_t* frameData;
		uint8_t frameDataLength;
	};

	static constexpr int AT_COMMAND_RETRY_MS = 1000;
	static constexpr int ASSOCIATION_INDICATION_REFRESH_MS = 1000;
	static constexpr time_t WAIT_FOR_DEFAULT_RESPONSE_TIMEOUT_MS = 120000ul; // 2 minutes

	ArrayList<Device*> _deviceList;
	uint16_t _shortAddress;
	XBeeAddress64 _operatingPanId;

	/* reusable data payload */
	uint8_t _payload[MAX_FRAME_DATA_SIZE];

	XBeeWithCallbacks _device;

	command_builder_t _commandBuilder;
	uint8_t _commandBuilderOffset;
	State _state;
	time_t _lastSendMillis;
	uint8_t _associationIndication;
	time_t _associationIndicationMillis;
	PendingZDORequest* _pendingZDORequest;

	CallbackArgs<const __FlashStringHelper*> _setStatus;
	CallbackArgs<ConnectionStatus> _setConnected;

public:
    static constexpr uint8_t REPORT_BROADCAST = 0xff;

	static constexpr uint16_t ZHA_PROFILE_ID = 0x0104;

	static constexpr XBeeAddress64 BROADCAST_ADDR64 = {};
	static constexpr uint16_t BROADCAST_ADDR16 = 0;
	static constexpr uint16_t ANNOUNCE_BROADCAST_ADDR16 = 0xfffc;

	DeviceManager();
	~DeviceManager();

	void resetDevice(uint8_t pin);
	void begin(Stream& stream);
	void sendAnnounce();
	void performReset();
	void update();

	void addDevice(Device& device);

	void setStatusCallback(CallbackArgs<const __FlashStringHelper*>::Func func, uintptr_t data = 0) {
		_setStatus.set(func, data);
	}
	void setConnectedCallback(CallbackArgs<ConnectionStatus>::Func func, uintptr_t data = 0) {
		_setConnected.set(func, data);
	}
	XBeeAddress64* getOperatingPanId() {
		return &_operatingPanId;
	}

	Memory getBuffer() {
		return Memory(_payload);
	}

	void sendMessage(Cluster* cluster, uint8_t endpointId, Memory& buffer);
	void sendMessage(Device* device, Cluster* cluster, uint8_t endpointId, Memory& buffer);

private:
	void processZDO(XBeeAddress64 dst64, uint16_t dst16, uint16_t clusterId, uint8_t* frameData, uint8_t frameDataLength);

	Device* getDeviceByEndpoint(uint8_t endpointId);

	void reportAttributes();
	void reportAttribute(Device* device, Cluster* cluster, Attribute* attribute);

	void atCommandCallback(AtCommandResponse& command);
	void modemStatusCallback(ModemStatusResponse& status);
	void explicitRxCallback(ZBExplicitRxResponse& resp);
	void processZHAGlobal(ZBExplicitRxResponse& resp, Device* device, Frame& request, Memory& frameBuffer);
	void processZHACluster(ZBExplicitRxResponse& resp, Device* device, Frame& request, Memory& frameBuffer);

	void setCommandBuilder(command_builder_t commandBuilder);
	bool sendNextCommand();
	void sendCurrentCommand();
	void sendNotFound(ZBExplicitRxResponse& resp);
	void retrieveAssociationIndication();
	void retrieveConfiguration();

	XBeeAddress64 getAddress();

	void setStatus(const __FlashStringHelper* status) {
		_setStatus.call(status);
	}
	void setConnected(ConnectionStatus connected) {
		_setConnected.call(connected);
	}

	static const __FlashStringHelper* getAssociationIndicationDescription(uint8_t associationIndication);
	static const __FlashStringHelper* getShortAssociationIndicationDescription(uint8_t associationIndication);
};
