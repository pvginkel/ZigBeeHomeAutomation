#pragma once

#include <XBee.h>

#include "Arduino.h"
#include "Buffer.h"
#include "ZHA_Attributes.h"

namespace Zcl {

	enum class DataType {
		Bool = 0x10,
		UInt8 = 0x18,
		UInt16 = 0x19,
	};

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

	enum class Status {
		// Operation was successful.
		Success = 0x00,
		// Operation was not successful.
		Failure = 0x01,
		// The sender of the command does not have authorization to carry out this command.
		NotAuthorized = 0x7e,
		// A reserved field/subfield/bit contains a non-zero value.
		ReservedFieldNotZero = 0x7f,
		// The command appears to contain the wrong fields, as detected either by the presence of one or more invalid field entries or by there being missing fields. Command not carried out. Implementer has discretion as to whether to return this error or INVALID_FIELD.
		MalformedCommand = 0x80,
		// The specified cluster command is not supported on the device. Command not carried out.
		UnsupportedClusterCommand = 0x81,
		// The specified general ZCL command is not supported on the device.
		UnsupportedGeneralCommand = 0x82,
		// A manufacturer specific unicast, cluster specific command was received with an unknown manufacturer code, or the manufacturer code was recognized but the command is not supported.
		UnsupportedManufacturerClusterCommand = 0x83,
		// A manufacturer specific unicast, ZCL specific command was received with an unknown manufacturer code, or the manufacturer code was recognized but the command is not supported.
		UnsupportedManufacturerGeneralCommand = 0x84,
		// At least one field of the command contains an incorrect value, according to the specification the device is implemented to.
		InvalidField = 0x85,
		// The specified attribute does not exist on the device.
		UnsupportedAttribute = 0x86,
		// Out of range error, or set to a reserved value. Attribute keeps its old value.ZigBee Cluster Library Specification Chapter 2. Note that an attribute value may be out of range if an attribute is related to another, e.g., with minimum and maximum attributes. See the individual attribute descriptions for specific details.
		InvalidValue = 0x87,
		// Attempt to write a read only attribute.
		ReadOnly = 0x88,
		// An operation failed due to an insufficient amount of free space available.
		InsufficientSpace = 0x89,
		// An attempt to create an entry in a table failed due to a duplicate entry already being present in the table.
		DuplicateExists = 0x8a,
		// The requested information (e.g., table entry) could not be found.
		NotFound = 0x8b,
		// Periodic reports cannot be issued for this attribute.
		UnreportableAttribute= 0x8c,
		// The data type given for an attribute is incorrect. Command not carried out.
		InvalidDataType = 0x8d,
		// The selector for an attribute is incorrect.
		InvalidSelector= 0x8e,
		// A request has been made to read an attribute that the requestor is not authorized to read. No action taken.
		WriteOnly = 0x8f,
		// Setting the requested values would put the device in an inconsistent state on startup. No action taken.
		InconsistentStartupState = 0x90,
		// An attempt has been made to write an attribute that is present but is defined using an out-of-band method and not over the air.
		DefinedOutOfBand = 0x91,
		// The supplied values (e.g., contents of table cells) are inconsistent.
		Inconsistent = 0x92,
		// The credentials presented by the device sending the command are not sufficient to perform this action.
		ActionDenied = 0x93,
		// The exchange was aborted due to excessive response time.
		Timeout = 0x94,
		// Failed case when a client or a server decides to abort the upgrade process.
		Abort = 0x95,
		// Invalid OTA upgrade image (ex. failed signature validation or signer information check or CRC check).
		InvalidImage = 0x96,
		// Server does not have data block available yet.
		WaitForData = 0x97,
		// No OTA upgrade image available for a particular client.
		NoImageAvailable = 0x98,
		// The client still requires more OTA upgrade image files in order to successfully upgrade.
		RequireMoreImage = 0x99,
		// The command has been received and is being processed.
		NotificationPending = 0x9a,
		// An operation was unsuccessful due to a hardware failure.
		HardwareFailure = 0xc0,
		// An operation was unsuccessful due to a software failure.
		SoftwareFailure = 0xc1,
		// An error occurred during calibration.
		CalibrationError = 0xc2,
		// The cluster is not supported
		UnsupportedCluster = 0xc3,
	};

	class Frame {
	protected:
		static constexpr int FrameSize = 3;

		Buffer* _buffer;

	public:
		explicit Frame(Buffer& buffer)
			: _buffer(&buffer) {
		}

		FrameControl frameControl() {
			return { _buffer->get(0) };
		}

		void frameControl(FrameControl value) {
			_buffer->set(0, value.flags());
		}

		uint8_t transactionSequenceNumber() {
			return _buffer->get(1);
		}

		void transactionSequenceNumber(uint8_t value) {
			_buffer->set(1, value);
		}

		CommandIdentifier commandIdentifier() {
			return (CommandIdentifier)_buffer->get(2);
		}

		void commandIdentifier(CommandIdentifier value) {
			_buffer->set(2, (uint8_t)value);
		}

		virtual int length() {
			return FrameSize;
		}
	};

	class DefaultResponseFrame : public Frame {
	public:
		explicit DefaultResponseFrame(Buffer& buffer)
			: Frame(buffer) {
		}

		uint8_t commandId() {
			return _buffer->get(FrameSize);
		}

		void commandId(uint8_t value) {
			_buffer->set(FrameSize, value);
		}

		Status status() {
			return (Status)_buffer->get(FrameSize + 1);
		}

		void status(Status value) {
			_buffer->set(FrameSize + 1, (uint8_t)value);
		}

		int length() override {
			return FrameSize + 2;
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

	class ReadAttributesFrame : public Frame {
	public:
		explicit ReadAttributesFrame(Buffer& buffer)
			: Frame(buffer) {
		}

		int attributeCount() {
			return (_buffer->length() - FrameSize) / 2;
		}

		uint16_t attributeId(int index) {
			return _buffer->getLe<uint16_t>(FrameSize + index * 2);
		}

		int length() override {
			return _buffer->length();
		}
	};

	class FrameAppender {
	public:
		virtual void appendValue(uint8_t value) = 0;
		virtual void appendValueLe(uint16_t value) = 0;
		virtual void appendShortString(const String& string) = 0;
		virtual void appendLongString(const String& string) = 0;
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

	class ReadAttributesResponseFrame : public Frame, public FrameAppender {
		int _offset;

	public:
		explicit ReadAttributesResponseFrame(Buffer& buffer)
			: Frame(buffer), _offset(FrameSize) {
		}

		void appendAttribute(uint16_t attributeId, Status status) {
			_buffer->setLe(_offset, attributeId);
			_offset += 2;
			_buffer->set(_offset++, (uint8_t)status);
		}

		void appendAttribute(uint16_t attributeId, Status status, DataType dataType) {
			appendAttribute(attributeId, status);
			_buffer->set(_offset++, (uint8_t)dataType);
		}

		void appendValue(uint8_t value) override {
			_buffer->set(_offset++, value);
		}

		void appendValueLe(uint16_t value) override {
			_buffer->setLe<uint16_t>(_offset, value);
			_offset += 2;
		}

		void appendShortString(const String& value) override {
			auto length = value.length();
			_buffer->set(_offset++, length);
			value.getBytes((unsigned char *)_buffer->data(), MAX_FRAME_DATA_SIZE, _offset);
			_offset += length;
		}

		void appendLongString(const String& value) override {
			auto length = value.length();
			_buffer->setLe(_offset++, (uint16_t)length);
			value.getBytes((unsigned char*)_buffer->data(), MAX_FRAME_DATA_SIZE, _offset);
			_offset += length;
		}

		int length() override {
			return _offset;
		}
	};

	class DiscoverAttributesFrame : public Frame {
	public:
		explicit DiscoverAttributesFrame(Buffer& buffer)
			: Frame(buffer) {
		}

		uint16_t startAttributeId() {
			return _buffer->getLe<uint16_t>(FrameSize);
		}

		int maximumAttributeIds() {
			return (int)_buffer->get(FrameSize + 2);
		}

		int length() override {
			return FrameSize + 3;
		}
	};

	class DiscoverAttributesResponseFrame : public Frame {
		int _offset;

	public:
		explicit DiscoverAttributesResponseFrame(Buffer& buffer)
			: Frame(buffer), _offset(FrameSize + 1) {
		}

		void discoveryComplete(bool value) {
			_buffer->set(FrameSize, value);
		}

		void appendAttribute(uint16_t attributeId, DataType dataType) {
			_buffer->setLe(_offset, attributeId);
			_offset += 2;
			_buffer->set(_offset++, (uint8_t)dataType);
		}

		int length() override {
			return _offset;
		}
	};

	enum class ConfigureReportingType {
		End = -1,
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

		uint16_t attributeId() {
			return _attributeId;
		}

		DataType dataType() {
			return _dataType;
		}

		uint16_t minimumInterval() {
			return _minimumInterval;
		}

		uint16_t maximumInterval() {
			return _maximumInterval;
		}
	};

	class ConfigureReportingFrame : public Frame {
		int _offset;

	public:
		explicit ConfigureReportingFrame(Buffer& buffer)
			: Frame(buffer), _offset(FrameSize) {
		}

		ConfigureReportingType readElementType() {
			if (_offset < _buffer->length()) {
				return ConfigureReportingType::End;
			}
			return (ConfigureReportingType)_buffer->get(_offset++);
		}

		ConfigureReportingSendElement readSendElement() {
			auto attributeId = _buffer->getLe<uint16_t>(_offset);
			_offset += 2;
			auto dataType = (DataType)_buffer->get(_offset++);
			auto minimumInterval = _buffer->getLe<uint16_t>(_offset);
			_offset += 2;
			auto maximumInterval = _buffer->getLe<uint16_t>(_offset);
			_offset += 2;

			return { attributeId, dataType, minimumInterval, maximumInterval };
		}
	};

	class ConfigureReportingResponseFrame : public Frame {
		int _offset;

	public:
		explicit ConfigureReportingResponseFrame(Buffer& buffer)
			: Frame(buffer), _offset(FrameSize) {
		}

		void appendAttribute(Status status, ConfigureReportingType type, uint16_t attributeId) {
			_buffer->set(_offset++, (uint8_t)status);
			_buffer->set(_offset++, (uint8_t)type);
			_buffer->setLe(_offset, attributeId);
			_offset += 2;
		}

		int length() override {
			return _offset;
		}
	};

	class ReportAttributesFrame : public Frame, public FrameAppender {
		int _offset;

	public:
		explicit ReportAttributesFrame(Buffer& buffer)
			: Frame(buffer), _offset(FrameSize) {
		}

		void appendAttribute(uint16_t attributeId, DataType dataType) {
			_buffer->setLe(_offset, attributeId);
			_offset += 2;
			_buffer->set(_offset++, (uint8_t)dataType);
		}

		void appendValue(uint8_t value) override {
			_buffer->set(_offset++, value);
		}

		void appendValueLe(uint16_t value) override {
			_buffer->setLe<uint16_t>(_offset, value);
			_offset += 2;
		}

		void appendShortString(const String& value) override {
			auto length = value.length();
			_buffer->set(_offset++, length);
			value.getBytes((unsigned char*)_buffer->data(), MAX_FRAME_DATA_SIZE, _offset);
			_offset += length;
		}

		void appendLongString(const String& value) override {
			auto length = value.length();
			_buffer->setLe(_offset++, (uint16_t)length);
			value.getBytes((unsigned char*)_buffer->data(), MAX_FRAME_DATA_SIZE, _offset);
			_offset += length;
		}

		int length() override {
			return _offset;
		}
	};
}
