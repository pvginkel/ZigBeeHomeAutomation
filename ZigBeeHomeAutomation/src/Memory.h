#pragma once

class Memory {
	uint8_t* _data;
    int _position;
	int _length;

public:
	explicit Memory(uint8_t* data, int length = 0) : _data(data), _position(0), _length(length) {
	}

	uint8_t* getData() {
		return _data;
	}

	int getLength() {
		return _length;
	}

	void setLength(int value) {
		_length = value;
	}

    int getPosition() {
        return _position;
    }

    void setPosition(int value) {
        _position = value;
    }

    int8_t readInt8() {
        return (int8_t)_data[_position++];
    }

	uint8_t readUInt8() {
		return _data[_position++];
	}

    void writeInt8(int8_t value) {
        _data[_position++] = value;
    }

    void writeUInt8(uint8_t value) {
        _data[_position++] = value;
    }

// GENERATION START

    int16_t readInt16Le();
    int16_t readInt16Be();
    int32_t readInt24Le();
    int32_t readInt24Be();
    int32_t readInt32Le();
    int32_t readInt32Be();
    int64_t readInt40Le();
    int64_t readInt40Be();
    int64_t readInt48Le();
    int64_t readInt48Be();
    int64_t readInt56Le();
    int64_t readInt56Be();
    int64_t readInt64Le();
    int64_t readInt64Be();
    uint16_t readUInt16Le();
    uint16_t readUInt16Be();
    uint32_t readUInt24Le();
    uint32_t readUInt24Be();
    uint32_t readUInt32Le();
    uint32_t readUInt32Be();
    uint64_t readUInt40Le();
    uint64_t readUInt40Be();
    uint64_t readUInt48Le();
    uint64_t readUInt48Be();
    uint64_t readUInt56Le();
    uint64_t readUInt56Be();
    uint64_t readUInt64Le();
    uint64_t readUInt64Be();
    void writeInt16Le(int16_t value);
    void writeInt16Be(int16_t value);
    void writeInt24Le(int32_t value);
    void writeInt24Be(int32_t value);
    void writeInt32Le(int32_t value);
    void writeInt32Be(int32_t value);
    void writeInt40Le(int64_t value);
    void writeInt40Be(int64_t value);
    void writeInt48Le(int64_t value);
    void writeInt48Be(int64_t value);
    void writeInt56Le(int64_t value);
    void writeInt56Be(int64_t value);
    void writeInt64Le(int64_t value);
    void writeInt64Be(int64_t value);
    void writeUInt16Le(uint16_t value);
    void writeUInt16Be(uint16_t value);
    void writeUInt24Le(uint32_t value);
    void writeUInt24Be(uint32_t value);
    void writeUInt32Le(uint32_t value);
    void writeUInt32Be(uint32_t value);
    void writeUInt40Le(uint64_t value);
    void writeUInt40Be(uint64_t value);
    void writeUInt48Le(uint64_t value);
    void writeUInt48Be(uint64_t value);
    void writeUInt56Le(uint64_t value);
    void writeUInt56Be(uint64_t value);
    void writeUInt64Le(uint64_t value);
    void writeUInt64Be(uint64_t value);
// GENERATION END

    float readSingle();
    double readDouble();
    void writeSingle(float value);
    void writeDouble(double value);

    Buffer readOctstr();
    Buffer readOctstr16Le();
    void writeOctstr(const Buffer& value);
    void writeOctstr16Le(const Buffer& value);
    String readString();
    String readString16Le();
    void writeString(const String& value);
    void writeString16Le(const String& value);

private:
    Buffer readOctstrData(int length);
    void writeOctstrData(const Buffer& value);
    String readStringData(int length);
    void writeStringData(const String& value);
};
