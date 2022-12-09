#pragma once

enum class ConnectionStatus {
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

	typedef AtCommandRequest(*command_builder_t)(int);

	enum class State {
		Connected,
		Resetting,
		RetrievingConfiguration,
		RetrievingAssociationIndication
	};

	class ReportingAttribute {
		Attribute* _attribute;
		time_t _defaultResponseExpiration;

	public:
		ReportingAttribute() : _attribute(nullptr), _defaultResponseExpiration(0) {
		}

		ReportingAttribute(Attribute* attribute, time_t defaultResponseExpiration)
			: _attribute(attribute), _defaultResponseExpiration(attribute ? defaultResponseExpiration : 0) {
		}

		Attribute* getAttribute() const { return _attribute; }
		time_t getDefaultResponseExpiration() const { return _defaultResponseExpiration; }
	};

	static constexpr int AT_COMMAND_RETRY_MS = 1000;
	static constexpr int ASSOCIATION_INDICATION_REFRESH_MS = 1000;
	static constexpr time_t WAIT_FOR_DEFAULT_RESPONSE_TIMEOUT_MS = 120000ul; // 2 minutes

	static XBeeAddress64 BROADCAST_ADDR64;
	static constexpr uint16_t BROADCAST_ADDR16 = 0;
	static constexpr uint16_t ANNOUNCE_BROADCAST_ADDR16 = 0xfffc;

	ArrayList<Device*> _deviceList;
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

	ReportingAttribute _reportingAttribute;

	CallbackArgs<const String&> _setStatus;
	CallbackArgs<ConnectionStatus> _setConnected;

public:
	static constexpr uint16_t ZHA_PROFILE_ID = 0x0104;

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
	void processZDO(XBeeAddress64 dst64, uint16_t dst16, uint16_t clusterId, uint8_t* frameData, uint8_t frameDataLength);

	Device* getDeviceByEndpoint(uint8_t endpointId);

	void sendAttributeReport();
	Attribute* reportAttribute();

	void atCommandCallback(AtCommandResponse& command);
	void modemStatusCallback(ModemStatusResponse& status);
	void explicitRxCallback(ZBExplicitRxResponse& resp);

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
