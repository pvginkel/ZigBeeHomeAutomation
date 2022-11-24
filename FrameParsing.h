#pragma once

enum class FrameType {
	Global = 0,
	Cluster = 1
};

enum class Direction {
	ToServer = 0,
	ToClient = 1
};

class FrameControl {
	union {
		struct {
			uint8_t frameType : 2;
			uint8_t manufacturerSpecific : 1;
			uint8_t direction : 1;
			uint8_t disableDefaultResponse : 1;
			uint8_t reserved : 3;
		};
		uint8_t flags;
	} _data{};

public:
	FrameControl() = default;

	FrameControl(uint8_t flags) {
		_data.flags = flags;
	}

	FrameControl(FrameType frameType, Direction direction, bool disableDefaultResponse = false) {
		this->frameType(frameType);
		this->direction(direction);
		this->disableDefaultResponse(disableDefaultResponse);
	}

	FrameType frameType() {
		return (FrameType)_data.frameType;
	}

	void frameType(FrameType value) {
		_data.frameType = (uint8_t)value;
	}

	bool manufacturerSpecific() {
		return _data.manufacturerSpecific;
	}

	void manufacturerSpecific(bool value) {
		_data.manufacturerSpecific = value;
	}

	Direction direction() {
		return (Direction)_data.direction;
	}

	void direction(Direction value) {
		_data.direction = (uint8_t)value;
	}

	bool disableDefaultResponse() {
		return _data.disableDefaultResponse;
	}

	void disableDefaultResponse(bool value) {
		_data.disableDefaultResponse = value;
	}

	uint8_t flags() {
		return _data.flags;
	}

	void flags(uint8_t value) {
		_data.flags = value;
	}
};

enum class CommandIdentifier {
	ReadAttributes = 0x00,
	ReadAttributesResponse = 0x01,
	WriteAttributes = 0x02,
	WriteAttributesUndivided = 0x03,
	WriteAttributesResponse = 0x04,
	WriteAttributesNoResponse = 0x05,
	ConfigureReporting = 0x06,
	ConfigureReportingResponse = 0x07,
	ReadReportingConfiguration = 0x08,
	ReadReportingConfigurationResponse = 0x09,
	ReportAttributes = 0x0a,
	DefaultResponse = 0x0b,
	DiscoverAttributes = 0x0c,
	DiscoverAttributesResponse = 0x0d,
	ReadAttributesStructured = 0x0e,
	WriteAttributesStructured = 0x0f,
	WriteAttributesStructuredResponse = 0x10,
	DiscoverCommandsReceived = 0x11,
	DiscoverCommandsReceivedResponse = 0x12,
	DiscoverCommandsGenerated = 0x13,
	DiscoverCommandsGeneratedResponse = 0x14,
	DiscoverAttributesExtended = 0x15,
	DiscoverAttributesExtendedResponse = 0x16,
};

class Frame {
public:
	static Frame read(Memory& buffer) {
		return {
			FrameControl(buffer.readUInt8()),
			buffer.readUInt8(),
			(CommandIdentifier)buffer.readUInt8()
		};
	}

private:
	FrameControl _frameControl;
	uint8_t _transactionSequenceNumber;
	CommandIdentifier _commandIdentifier;

public:
	Frame(FrameControl frameControl, uint8_t transactionSequenceNumber, CommandIdentifier commandIdentifier)
		: _frameControl(frameControl),
		  _transactionSequenceNumber(transactionSequenceNumber),
		  _commandIdentifier(commandIdentifier) {
	}

	FrameControl frameControl() const {
		return _frameControl;
	}

	void frameControl(const FrameControl& frameControl) {
		_frameControl = frameControl;
	}

	uint8_t transactionSequenceNumber() const {
		return _transactionSequenceNumber;
	}

	void transactionSequenceNumber(uint8_t transactionSequenceNumber) {
		_transactionSequenceNumber = transactionSequenceNumber;
	}

	CommandIdentifier commandIdentifier() const {
		return _commandIdentifier;
	}

	void commandIdentifier(CommandIdentifier commandIdentifier) {
		_commandIdentifier = commandIdentifier;
	}

	void write(Memory& buffer) {
		buffer.writeUInt8(_frameControl.flags());
		buffer.writeUInt8(_transactionSequenceNumber);
		buffer.writeUInt8((uint8_t)_commandIdentifier);
	}
};

class DefaultResponseFrame {
public:
	static DefaultResponseFrame read(Memory& buffer) {
		return {
			buffer.readUInt8(),
			(Status)buffer.readUInt8()
		};
	}

private:
	uint8_t _commandId;
	Status _status;

public:
	DefaultResponseFrame(uint8_t commandId, Status status)
		: _commandId(commandId),
		  _status(status) {
	}

	uint8_t getCommandId() const {
		return _commandId;
	}

	void setCommandId(uint8_t commandId) {
		_commandId = commandId;
	}

	Status getStatus() const {
		return _status;
	}

	void setStatus(Status status) {
		_status = status;
	}

	void write(Memory& buffer) {
		buffer.writeUInt8(_commandId);
		buffer.writeUInt8((uint8_t)_status);
	}
};

/*
  Command
  -------------------------------------------------------------------------
  |  Bits: 24  |    Bits: 16    |    Bits: 16    |  ...  |    Bits: 16    |
  |-----------------------------------------------------------------------|
  | ZCL Header | Attribute ID 1 | Attribute ID 2 |  ...  | Attribute ID n |
  -------------------------------------------------------------------------
*/

class ReadAttributesFrame {
public:
	static bool readNextAttributeId(Memory& buffer, uint16_t& attributeId) {
		if (buffer.getPosition() < buffer.getLength()) {
			attributeId = buffer.readUInt16Le();
			return true;
		}
		return false;
	}
};

/*
  Response payload
  ---------------------------------------------------------------------------
  |  Bits: 8   |    Variable     |    Variable     | ... |     Variable     |
  |-------------------------------------------------------------------------|
  | ZCL Header | Read Attribute  | Read Attribute  | ... |  Read Attribute  |
  |            | Status Record 1 | Status Record 2 |     | Status Record n  |
  ---------------------------------------------------------------------------
  Read Attribute Status Record
  --------------------------------------------------
  |   Bits: 16   |   1    |    0/1    | 0/Variable |
  --------------------------------------------------
  | Attribute Id | Status | Data Type |   Value    |
  --------------------------------------------------
  */

class ReadAttributesResponseFrame {
public:
	static void writeAttribute(Memory& buffer, uint16_t attributeId, Status status) {
		buffer.writeUInt16Le(attributeId);
		buffer.writeUInt8((uint8_t)status);
	}

	static void writeAttribute(Memory& buffer, uint16_t attributeId, Status status, DataType dataType) {
		writeAttribute(buffer, attributeId, status);
		buffer.writeUInt8((uint8_t)dataType);
	}
};

class DiscoverAttributesFrame {
public:
	static DiscoverAttributesFrame read(Memory& buffer) {
		return {
			buffer.readUInt16Le(),
			buffer.readUInt8()
		};
	}

private:
	uint16_t _startAttributeId;
	uint8_t _maximumAttributeIds;

public:
	DiscoverAttributesFrame(uint16_t startAttributeId, uint8_t maximumAttributeIds)
		: _startAttributeId(startAttributeId),
		  _maximumAttributeIds(maximumAttributeIds) {
	}

	uint16_t getStartAttributeId() const {
		return _startAttributeId;
	}

	void setStartAttributeId(uint16_t startAttributeId) {
		_startAttributeId = startAttributeId;
	}

	uint8_t getMaximumAttributeIds() const {
		return _maximumAttributeIds;
	}

	void setMaximumAttributeIds(uint8_t maximumAttributeIds) {
		_maximumAttributeIds = maximumAttributeIds;
	}
};

class DiscoverAttributesResponseFrame {
	bool _discoveryComplete;

public:
	explicit DiscoverAttributesResponseFrame(bool discoveryComplete)
		: _discoveryComplete(discoveryComplete) {
	}

	bool getDiscoveryComplete() const {
		return _discoveryComplete;
	}

	void setDiscoveryComplete(bool discoveryComplete) {
		_discoveryComplete = discoveryComplete;
	}

	void write(Memory& buffer) {
		buffer.writeUInt8(_discoveryComplete);
	}

	static void writeAttribute(Memory& buffer, uint16_t attributeId, DataType dataType) {
		buffer.writeUInt16Le(attributeId);
		buffer.writeUInt8((uint8_t)dataType);
	}
};

enum class ConfigureReportingType {
	Send = 0,
	Receive = 1
};

class ConfigureReportingSendElement {
	uint16_t _attributeId;
	DataType _dataType;
	uint16_t _minimumInterval;
	uint16_t _maximumInterval;

public:
	ConfigureReportingSendElement(uint16_t attributeId, DataType dataType, uint16_t minimumInterval,
		uint16_t maximumInterval)
		: _attributeId(attributeId),
		  _dataType(dataType),
		  _minimumInterval(minimumInterval),
		  _maximumInterval(maximumInterval) {
	}

	uint16_t getAttributeId() {
		return _attributeId;
	}

	DataType getDataType() {
		return _dataType;
	}

	uint16_t getMinimumInterval() {
		return _minimumInterval;
	}

	uint16_t getMaximumInterval() {
		return _maximumInterval;
	}
};

class ConfigureReportingFrame {
public:
	static bool readNextElementType(Memory& buffer, ConfigureReportingType& configureReportingType) {
		if (buffer.getPosition() < buffer.getLength()) {
			configureReportingType = (ConfigureReportingType)buffer.readUInt8();
			return true;
		}
		return false;
	}

	static ConfigureReportingSendElement readSendElement(Memory& buffer) {
		return {
			buffer.readUInt16Le(),
			(DataType)buffer.readUInt8(),
			buffer.readUInt16Le(),
			buffer.readUInt16Le()
		};
	}
};

class ConfigureReportingResponseFrame {
public:
	static void writeAttribute(Memory& buffer, Status status, ConfigureReportingType type, uint16_t attributeId) {
		buffer.writeUInt8((uint8_t)status);
		buffer.writeUInt8((uint8_t)type);
		buffer.writeUInt16Le(attributeId);
	}
};

class ReportAttributesFrame {
public:
	static void writeAttribute(Memory& buffer, uint16_t attributeId, DataType dataType) {
		buffer.writeUInt16Le(attributeId);
		buffer.writeUInt8((uint8_t)dataType);
	}
};
