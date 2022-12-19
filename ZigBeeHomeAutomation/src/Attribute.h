#pragma once

class Cluster;

class Attribute {
    DataType _dataType;
	uint16_t _attributeId;
    bool _dirty;
    uint8_t _reportingEndpointId;

public:
    static constexpr uint8_t REPORT_BROADCAST = 0xff;

	Attribute(uint16_t attributeId, DataType dataType) :
		_dataType(dataType), _attributeId(attributeId), _dirty(false), _reportingEndpointId(0) {
	}
	Attribute(const Attribute&) = delete;
    virtual ~Attribute() = default;

    uint16_t getAttributeId() { return _attributeId; }
	DataType getDataType() { return _dataType; }

    uint8_t getReportingEndpointId() { return _reportingEndpointId; }
    void setReportingEndpointId(uint8_t reportingEndpointId) { _reportingEndpointId = reportingEndpointId; }
    void configureBroadcastReporting() { setReportingEndpointId(REPORT_BROADCAST); }
    bool isDirty() { return _dirty; }
    void markClean() { _dirty = false; }

	virtual String toString() = 0;

    virtual void readValue(Memory& memory) = 0;
    virtual void writeValue(Memory& memory) = 0;

	Attribute& operator=(const Attribute&) = delete;

protected:
	void markDirty() { _dirty = true; }
};

enum class AttributeStringType : uint8_t {
    Empty,
    CStr,
    FlashString
};

class AttributeString : public Attribute {
    AttributeStringType _type;
    void* _value;

public:
    AttributeString(uint16_t attributeId)
		: Attribute(attributeId, DataType::String), _type(AttributeStringType::Empty), _value(nullptr) {
    }
    ~AttributeString() override {
        clearValue();
    }

    void clearValue() {
        if (_type == AttributeStringType::CStr) {
            free(_value);
        }
        _type = AttributeStringType::Empty;
        _value = nullptr;
    }
    AttributeStringType getType() const {
        return _type;
    }
    const char* getCString() const {
        return _type == AttributeStringType::CStr ? (char*)_value : nullptr;
    }
    const __FlashStringHelper* getFlashString() const {
        return _type == AttributeStringType::FlashString ? (__FlashStringHelper*)_value : nullptr;
    }
    void setValue(const String& value) {
        setValue(value.c_str());
    }
    void setValue(const char* value) {
        auto length = strlen(value);

        char* buffer = nullptr;
        if (_type == AttributeStringType::CStr) {
            auto currentLength = strlen(_value);
            if (length == currentLength) {
                buffer = (char*)_value;
            }
        }

        if (!buffer) {
            clearValue();
            buffer = (char*)malloc(length + 1);
        }

        _type = AttributeStringType::CStr;
        _value = buffer;

        strcpy(buffer, value);
    }
    void setValue(const __FlashStringHelper* value) {
        clearValue();
        _type = AttributeStringType::FlashString;
        _value = (void*)value;
    }

    String toString() override {
        if (_type == AttributeStringType::CStr) {
            return String(getCString());
        }
        if (_type == AttributeStringType::FlashString) {
            return String(getFlashString());
        }
        return String();
    }

    void readValue(Memory& memory) override {
        // Unsupported.
    }

    void readStringValue(Memory& memory, DataType dataType) {
        uint16_t length;
        if (dataType == DataType::String16) {
            length = memory.readUInt16Le();
        }
        else {
            length = memory.readUInt8();
        }

        char* buffer = nullptr;

        if (_type == AttributeStringType::CStr) {
            auto currentLength = strlen(_value);
            if (currentLength == length) {
                buffer = (char*)_value;
            }
        }

        if (!buffer) {
            clearValue();
            buffer = (char*)malloc(length + 1);
        }

        _type = AttributeStringType::CStr;
        _value = buffer;

        while (length--) {
            *buffer++ = (char)memory.readUInt8();
        }
        *buffer = 0;
    }

    void writeValue(Memory& memory) override {
        uint16_t length;

        if (_type == AttributeStringType::CStr) {
            length = strlen(getCString());
        }
        else if (_type == AttributeStringType::FlashString) {
            length = 0;
            auto value = (PGM_P)getFlashString();
            for (;;) {
				auto c = pgm_read_byte(value++);
                if (!c) {
                    break;
                }
                length++;
            }
        }
        else {
            length = 0;
        }

        // We only support long strings to keep program size down.
        memory.writeUInt16Le(length);

        if (_type == AttributeStringType::CStr) {
            auto value = getCString();
            for (;;) {
				auto c = *value++;
                if (!c) {
                    break;
                }
                memory.writeUInt8(c);
            }
        }
        else if (_type == AttributeStringType::FlashString) {
            auto value = (PGM_P)getFlashString();
            for (;;) {
				auto c = pgm_read_byte(value++);
                if (!c) {
                    break;
                }
                memory.writeUInt8(c);
            }
        }
    }
};

class AttributeOctstr : public Attribute {
    Buffer _value{};

public:
    AttributeOctstr(uint16_t attributeId) : Attribute(attributeId, DataType::Octstr) {
    }

    const Buffer& getValue() { return _value; }

    void setValue(Buffer value) {
        _value = value;
        markDirty();
    }

    String toString() override {
        return F("BUFFER");
    }

    void readValue(Memory& memory) override {
        // Unsupported.
    }

    void readOctstrValue(Memory& memory, DataType dataType) {
        if (dataType == DataType::Octstr16) {
            _value = memory.readOctstr16Le();
        }
        else {
            _value = memory.readOctstr();
        }
    }

    void writeValue(Memory& memory) override {
        // We only support long octstrs to keep program size down.
        memory.writeOctstr16Le(_value);
    }
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

    void readValue(Memory& memory) override {
        _value = memory.readUInt8();
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt8(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readUInt16Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt16Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readUInt24Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt24Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readUInt32Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt32Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readUInt40Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt40Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readUInt48Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt48Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readUInt56Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt56Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readUInt64Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt64Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readInt8();
    }

    void writeValue(Memory& memory) override {
        memory.writeInt8(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readInt16Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeInt16Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readInt24Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeInt24Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readInt32Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeInt32Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readInt40Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeInt40Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readInt48Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeInt48Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readInt56Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeInt56Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readInt64Le();
    }

    void writeValue(Memory& memory) override {
        memory.writeInt64Le(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readSingle();
    }

    void writeValue(Memory& memory) override {
        memory.writeSingle(_value);
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

    void readValue(Memory& memory) override {
        _value = memory.readDouble();
    }

    void writeValue(Memory& memory) override {
        memory.writeDouble(_value);
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

    void readValue(Memory& memory) override {
        // Has the date data type.
        memory.readUInt8();
        auto date = memory.readUInt32Le();
        // Has the time of day data type.
        memory.readUInt8();
        auto time = memory.readUInt32Le();
        _value = DateTime(date, time);
    }

    void writeValue(Memory& memory) override {
        memory.writeUInt8((uint8_t)DataType::Date);
        memory.writeUInt32Le(_value.getDate());
        memory.writeUInt8((uint8_t)DataType::ToD);
        memory.writeUInt32Le(_value.getTime());
    }
};

// GENERATION END
