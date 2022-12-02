#pragma once

class Attribute {
    struct Reporting {
        XBeeAddress64 destinationAddress;
        uint16_t destinationShortAddress;
        uint8_t destinationEndpoint;
        uint16_t minimumInterval;
        uint16_t maximumInterval;
    };

    DataType _dataType;
	uint16_t _attributeId;
    bool _dirty;
    Reporting* _reporting;

public:
	Attribute(uint16_t attributeId, DataType dataType) :
		_dataType(dataType), _attributeId(attributeId), _dirty(false), _reporting(nullptr) {
	}
	Attribute(const Attribute&) = delete;
	virtual ~Attribute();

	uint16_t getAttributeId() { return _attributeId; }
	DataType getDataType() { return _dataType; }

	virtual String toString() = 0;

    void configureReporting(const XBeeAddress64& destinationAddress, uint16_t destinationShortAddress, uint8_t destinationEndpoint, uint16_t minimumInterval, uint16_t maximumInterval, Memory& memory);
    void report(XBee& device, uint8_t endpointId, uint16_t clusterId, Memory& buffer);
    virtual void writeValue(Memory& memory) = 0;

	Attribute& operator=(const Attribute&) = delete;

protected:
	void markDirty() { _dirty = true; }
    virtual void configureReportableChange(Memory& memory) = 0;
};

// GENERATION START
class AttributeUInt8: public Attribute {
    uint8_t _value{};

public:
    AttributeUInt8(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    uint8_t getValue() { return _value; }

    void setValue(uint8_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((uint32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt8(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 1);
    }
};

class AttributeUInt16: public Attribute {
    uint16_t _value{};

public:
    AttributeUInt16(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    uint16_t getValue() { return _value; }

    void setValue(uint16_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((uint32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt16Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 2);
    }
};

class AttributeUInt24: public Attribute {
    uint32_t _value{};

public:
    AttributeUInt24(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    uint32_t getValue() { return _value; }

    void setValue(uint32_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((uint32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt24Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 3);
    }
};

class AttributeUInt32: public Attribute {
    uint32_t _value{};

public:
    AttributeUInt32(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    uint32_t getValue() { return _value; }

    void setValue(uint32_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((uint32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt32Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 4);
    }
};

class AttributeUInt40: public Attribute {
    uint64_t _value{};

public:
    AttributeUInt40(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    uint64_t getValue() { return _value; }

    void setValue(uint64_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((uint32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt40Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 5);
    }
};

class AttributeUInt48: public Attribute {
    uint64_t _value{};

public:
    AttributeUInt48(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    uint64_t getValue() { return _value; }

    void setValue(uint64_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((uint32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt48Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 6);
    }
};

class AttributeUInt56: public Attribute {
    uint64_t _value{};

public:
    AttributeUInt56(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    uint64_t getValue() { return _value; }

    void setValue(uint64_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((uint32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt56Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 7);
    }
};

class AttributeUInt64: public Attribute {
    uint64_t _value{};

public:
    AttributeUInt64(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    uint64_t getValue() { return _value; }

    void setValue(uint64_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((uint32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt64Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 8);
    }
};

class AttributeInt8: public Attribute {
    int8_t _value{};

public:
    AttributeInt8(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    int8_t getValue() { return _value; }

    void setValue(int8_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((int32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeInt8(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 1);
    }
};

class AttributeInt16: public Attribute {
    int16_t _value{};

public:
    AttributeInt16(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    int16_t getValue() { return _value; }

    void setValue(int16_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((int32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeInt16Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 2);
    }
};

class AttributeInt24: public Attribute {
    int32_t _value{};

public:
    AttributeInt24(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    int32_t getValue() { return _value; }

    void setValue(int32_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((int32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeInt24Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 3);
    }
};

class AttributeInt32: public Attribute {
    int32_t _value{};

public:
    AttributeInt32(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    int32_t getValue() { return _value; }

    void setValue(int32_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((int32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeInt32Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 4);
    }
};

class AttributeInt40: public Attribute {
    int64_t _value{};

public:
    AttributeInt40(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    int64_t getValue() { return _value; }

    void setValue(int64_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((int32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeInt40Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 5);
    }
};

class AttributeInt48: public Attribute {
    int64_t _value{};

public:
    AttributeInt48(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    int64_t getValue() { return _value; }

    void setValue(int64_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((int32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeInt48Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 6);
    }
};

class AttributeInt56: public Attribute {
    int64_t _value{};

public:
    AttributeInt56(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    int64_t getValue() { return _value; }

    void setValue(int64_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((int32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeInt56Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 7);
    }
};

class AttributeInt64: public Attribute {
    int64_t _value{};

public:
    AttributeInt64(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    int64_t getValue() { return _value; }

    void setValue(int64_t value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String((int32_t)_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeInt64Le(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 8);
    }
};

class AttributeSingle: public Attribute {
    float _value{};

public:
    AttributeSingle(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    float getValue() { return _value; }

    void setValue(float value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String(_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeSingle(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 4);
    }
};

class AttributeDouble: public Attribute {
    double _value{};

public:
    AttributeDouble(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    double getValue() { return _value; }

    void setValue(double value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return String(_value);
    }

    void writeValue(Memory& memory) override {
        memory.writeDouble(_value);
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 8);
    }
};

class AttributeOctstr: public Attribute {
    Buffer _value{};

public:
    AttributeOctstr(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    Buffer getValue() { return _value; }

    void setValue(Buffer value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return F("BUFFER");
    }

    void writeValue(Memory& memory) override {
        if (_value.length() > 254) {
            memory.writeOctstr16Le(_value);
        }
        else {
            memory.writeOctstr(_value);
        }
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        // TODO: No proper support for String16/Octstr16 yet.
        auto length = memory.readUInt8();
        memory.setPosition(memory.getPosition() + length);
    }
};

class AttributeString: public Attribute {
    String _value{};

public:
    AttributeString(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    String getValue() { return _value; }

    void setValue(String value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return _value;
    }

    void writeValue(Memory& memory) override {
        if (_value.length() > 254) {
            memory.writeString16Le(_value);
        }
        else {
            memory.writeString(_value);
        }
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        // TODO: No proper support for String16/Octstr16 yet.
        auto length = memory.readUInt8();
        memory.setPosition(memory.getPosition() + length);
    }
};

class AttributeDateTime: public Attribute {
    DateTime _value{};

public:
    AttributeDateTime(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {
    }

    DateTime getValue() { return _value; }

    void setValue(DateTime value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return F("DATETIME");
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt8((uint8_t)DataType::Date);
        memory.writeUInt32Le(_value.getDate());
        memory.writeUInt8((uint8_t)DataType::ToD);
        memory.writeUInt32Le(_value.getTime());
    }

protected:
    void configureReportableChange(Memory& memory) override {
        // TODO: Store reportable change value somewhere.
        memory.setPosition(memory.getPosition() + 10);
    }
};

// GENERATION END
