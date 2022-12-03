#include "ZigBeeHomeAutomation.h"

// GENERATION START

int16_t Memory::readInt16Le() {
    const int16_t result = ((int16_t)_data[_position + 0] << 0) | ((int16_t)_data[_position + 1] << 8);
    _position += 2;
    return result;
}

int16_t Memory::readInt16Be() {
    const int16_t result = ((int16_t)_data[_position + 0] << 8) | ((int16_t)_data[_position + 1] << 0);
    _position += 2;
    return result;
}

int32_t Memory::readInt24Le() {
    const int32_t result = ((int32_t)_data[_position + 0] << 0) | ((int32_t)_data[_position + 1] << 8) | ((int32_t)_data[_position + 2] << 16);
    _position += 3;
    return result;
}

int32_t Memory::readInt24Be() {
    const int32_t result = ((int32_t)_data[_position + 0] << 16) | ((int32_t)_data[_position + 1] << 8) | ((int32_t)_data[_position + 2] << 0);
    _position += 3;
    return result;
}

int32_t Memory::readInt32Le() {
    const int32_t result = ((int32_t)_data[_position + 0] << 0) | ((int32_t)_data[_position + 1] << 8) | ((int32_t)_data[_position + 2] << 16) | ((int32_t)_data[_position + 3] << 24);
    _position += 4;
    return result;
}

int32_t Memory::readInt32Be() {
    const int32_t result = ((int32_t)_data[_position + 0] << 24) | ((int32_t)_data[_position + 1] << 16) | ((int32_t)_data[_position + 2] << 8) | ((int32_t)_data[_position + 3] << 0);
    _position += 4;
    return result;
}

int64_t Memory::readInt40Le() {
    const int64_t result = ((int64_t)_data[_position + 0] << 0) | ((int64_t)_data[_position + 1] << 8) | ((int64_t)_data[_position + 2] << 16) | ((int64_t)_data[_position + 3] << 24) | ((int64_t)_data[_position + 4] << 32);
    _position += 5;
    return result;
}

int64_t Memory::readInt40Be() {
    const int64_t result = ((int64_t)_data[_position + 0] << 32) | ((int64_t)_data[_position + 1] << 24) | ((int64_t)_data[_position + 2] << 16) | ((int64_t)_data[_position + 3] << 8) | ((int64_t)_data[_position + 4] << 0);
    _position += 5;
    return result;
}

int64_t Memory::readInt48Le() {
    const int64_t result = ((int64_t)_data[_position + 0] << 0) | ((int64_t)_data[_position + 1] << 8) | ((int64_t)_data[_position + 2] << 16) | ((int64_t)_data[_position + 3] << 24) | ((int64_t)_data[_position + 4] << 32) | ((int64_t)_data[_position + 5] << 40);
    _position += 6;
    return result;
}

int64_t Memory::readInt48Be() {
    const int64_t result = ((int64_t)_data[_position + 0] << 40) | ((int64_t)_data[_position + 1] << 32) | ((int64_t)_data[_position + 2] << 24) | ((int64_t)_data[_position + 3] << 16) | ((int64_t)_data[_position + 4] << 8) | ((int64_t)_data[_position + 5] << 0);
    _position += 6;
    return result;
}

int64_t Memory::readInt56Le() {
    const int64_t result = ((int64_t)_data[_position + 0] << 0) | ((int64_t)_data[_position + 1] << 8) | ((int64_t)_data[_position + 2] << 16) | ((int64_t)_data[_position + 3] << 24) | ((int64_t)_data[_position + 4] << 32) | ((int64_t)_data[_position + 5] << 40) | ((int64_t)_data[_position + 6] << 48);
    _position += 7;
    return result;
}

int64_t Memory::readInt56Be() {
    const int64_t result = ((int64_t)_data[_position + 0] << 48) | ((int64_t)_data[_position + 1] << 40) | ((int64_t)_data[_position + 2] << 32) | ((int64_t)_data[_position + 3] << 24) | ((int64_t)_data[_position + 4] << 16) | ((int64_t)_data[_position + 5] << 8) | ((int64_t)_data[_position + 6] << 0);
    _position += 7;
    return result;
}

int64_t Memory::readInt64Le() {
    const int64_t result = ((int64_t)_data[_position + 0] << 0) | ((int64_t)_data[_position + 1] << 8) | ((int64_t)_data[_position + 2] << 16) | ((int64_t)_data[_position + 3] << 24) | ((int64_t)_data[_position + 4] << 32) | ((int64_t)_data[_position + 5] << 40) | ((int64_t)_data[_position + 6] << 48) | ((int64_t)_data[_position + 7] << 56);
    _position += 8;
    return result;
}

int64_t Memory::readInt64Be() {
    const int64_t result = ((int64_t)_data[_position + 0] << 56) | ((int64_t)_data[_position + 1] << 48) | ((int64_t)_data[_position + 2] << 40) | ((int64_t)_data[_position + 3] << 32) | ((int64_t)_data[_position + 4] << 24) | ((int64_t)_data[_position + 5] << 16) | ((int64_t)_data[_position + 6] << 8) | ((int64_t)_data[_position + 7] << 0);
    _position += 8;
    return result;
}

uint16_t Memory::readUInt16Le() {
    const uint16_t result = ((uint16_t)_data[_position + 0] << 0) | ((uint16_t)_data[_position + 1] << 8);
    _position += 2;
    return result;
}

uint16_t Memory::readUInt16Be() {
    const uint16_t result = ((uint16_t)_data[_position + 0] << 8) | ((uint16_t)_data[_position + 1] << 0);
    _position += 2;
    return result;
}

uint32_t Memory::readUInt24Le() {
    const uint32_t result = ((uint32_t)_data[_position + 0] << 0) | ((uint32_t)_data[_position + 1] << 8) | ((uint32_t)_data[_position + 2] << 16);
    _position += 3;
    return result;
}

uint32_t Memory::readUInt24Be() {
    const uint32_t result = ((uint32_t)_data[_position + 0] << 16) | ((uint32_t)_data[_position + 1] << 8) | ((uint32_t)_data[_position + 2] << 0);
    _position += 3;
    return result;
}

uint32_t Memory::readUInt32Le() {
    const uint32_t result = ((uint32_t)_data[_position + 0] << 0) | ((uint32_t)_data[_position + 1] << 8) | ((uint32_t)_data[_position + 2] << 16) | ((uint32_t)_data[_position + 3] << 24);
    _position += 4;
    return result;
}

uint32_t Memory::readUInt32Be() {
    const uint32_t result = ((uint32_t)_data[_position + 0] << 24) | ((uint32_t)_data[_position + 1] << 16) | ((uint32_t)_data[_position + 2] << 8) | ((uint32_t)_data[_position + 3] << 0);
    _position += 4;
    return result;
}

uint64_t Memory::readUInt40Le() {
    const uint64_t result = ((uint64_t)_data[_position + 0] << 0) | ((uint64_t)_data[_position + 1] << 8) | ((uint64_t)_data[_position + 2] << 16) | ((uint64_t)_data[_position + 3] << 24) | ((uint64_t)_data[_position + 4] << 32);
    _position += 5;
    return result;
}

uint64_t Memory::readUInt40Be() {
    const uint64_t result = ((uint64_t)_data[_position + 0] << 32) | ((uint64_t)_data[_position + 1] << 24) | ((uint64_t)_data[_position + 2] << 16) | ((uint64_t)_data[_position + 3] << 8) | ((uint64_t)_data[_position + 4] << 0);
    _position += 5;
    return result;
}

uint64_t Memory::readUInt48Le() {
    const uint64_t result = ((uint64_t)_data[_position + 0] << 0) | ((uint64_t)_data[_position + 1] << 8) | ((uint64_t)_data[_position + 2] << 16) | ((uint64_t)_data[_position + 3] << 24) | ((uint64_t)_data[_position + 4] << 32) | ((uint64_t)_data[_position + 5] << 40);
    _position += 6;
    return result;
}

uint64_t Memory::readUInt48Be() {
    const uint64_t result = ((uint64_t)_data[_position + 0] << 40) | ((uint64_t)_data[_position + 1] << 32) | ((uint64_t)_data[_position + 2] << 24) | ((uint64_t)_data[_position + 3] << 16) | ((uint64_t)_data[_position + 4] << 8) | ((uint64_t)_data[_position + 5] << 0);
    _position += 6;
    return result;
}

uint64_t Memory::readUInt56Le() {
    const uint64_t result = ((uint64_t)_data[_position + 0] << 0) | ((uint64_t)_data[_position + 1] << 8) | ((uint64_t)_data[_position + 2] << 16) | ((uint64_t)_data[_position + 3] << 24) | ((uint64_t)_data[_position + 4] << 32) | ((uint64_t)_data[_position + 5] << 40) | ((uint64_t)_data[_position + 6] << 48);
    _position += 7;
    return result;
}

uint64_t Memory::readUInt56Be() {
    const uint64_t result = ((uint64_t)_data[_position + 0] << 48) | ((uint64_t)_data[_position + 1] << 40) | ((uint64_t)_data[_position + 2] << 32) | ((uint64_t)_data[_position + 3] << 24) | ((uint64_t)_data[_position + 4] << 16) | ((uint64_t)_data[_position + 5] << 8) | ((uint64_t)_data[_position + 6] << 0);
    _position += 7;
    return result;
}

uint64_t Memory::readUInt64Le() {
    const uint64_t result = ((uint64_t)_data[_position + 0] << 0) | ((uint64_t)_data[_position + 1] << 8) | ((uint64_t)_data[_position + 2] << 16) | ((uint64_t)_data[_position + 3] << 24) | ((uint64_t)_data[_position + 4] << 32) | ((uint64_t)_data[_position + 5] << 40) | ((uint64_t)_data[_position + 6] << 48) | ((uint64_t)_data[_position + 7] << 56);
    _position += 8;
    return result;
}

uint64_t Memory::readUInt64Be() {
    const uint64_t result = ((uint64_t)_data[_position + 0] << 56) | ((uint64_t)_data[_position + 1] << 48) | ((uint64_t)_data[_position + 2] << 40) | ((uint64_t)_data[_position + 3] << 32) | ((uint64_t)_data[_position + 4] << 24) | ((uint64_t)_data[_position + 5] << 16) | ((uint64_t)_data[_position + 6] << 8) | ((uint64_t)_data[_position + 7] << 0);
    _position += 8;
    return result;
}

void Memory::writeInt16Le(int16_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _position += 2;
}

void Memory::writeInt16Be(int16_t value) {
    _data[_position + 0] = (value >> 8) & 0xff;
    _data[_position + 1] = (value >> 0) & 0xff;
    _position += 2;
}

void Memory::writeInt24Le(int32_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _position += 3;
}

void Memory::writeInt24Be(int32_t value) {
    _data[_position + 0] = (value >> 16) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 0) & 0xff;
    _position += 3;
}

void Memory::writeInt32Le(int32_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _position += 4;
}

void Memory::writeInt32Be(int32_t value) {
    _data[_position + 0] = (value >> 24) & 0xff;
    _data[_position + 1] = (value >> 16) & 0xff;
    _data[_position + 2] = (value >> 8) & 0xff;
    _data[_position + 3] = (value >> 0) & 0xff;
    _position += 4;
}

void Memory::writeInt40Le(int64_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _data[_position + 4] = (value >> 32) & 0xff;
    _position += 5;
}

void Memory::writeInt40Be(int64_t value) {
    _data[_position + 0] = (value >> 32) & 0xff;
    _data[_position + 1] = (value >> 24) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 8) & 0xff;
    _data[_position + 4] = (value >> 0) & 0xff;
    _position += 5;
}

void Memory::writeInt48Le(int64_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _data[_position + 4] = (value >> 32) & 0xff;
    _data[_position + 5] = (value >> 40) & 0xff;
    _position += 6;
}

void Memory::writeInt48Be(int64_t value) {
    _data[_position + 0] = (value >> 40) & 0xff;
    _data[_position + 1] = (value >> 32) & 0xff;
    _data[_position + 2] = (value >> 24) & 0xff;
    _data[_position + 3] = (value >> 16) & 0xff;
    _data[_position + 4] = (value >> 8) & 0xff;
    _data[_position + 5] = (value >> 0) & 0xff;
    _position += 6;
}

void Memory::writeInt56Le(int64_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _data[_position + 4] = (value >> 32) & 0xff;
    _data[_position + 5] = (value >> 40) & 0xff;
    _data[_position + 6] = (value >> 48) & 0xff;
    _position += 7;
}

void Memory::writeInt56Be(int64_t value) {
    _data[_position + 0] = (value >> 48) & 0xff;
    _data[_position + 1] = (value >> 40) & 0xff;
    _data[_position + 2] = (value >> 32) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _data[_position + 4] = (value >> 16) & 0xff;
    _data[_position + 5] = (value >> 8) & 0xff;
    _data[_position + 6] = (value >> 0) & 0xff;
    _position += 7;
}

void Memory::writeInt64Le(int64_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _data[_position + 4] = (value >> 32) & 0xff;
    _data[_position + 5] = (value >> 40) & 0xff;
    _data[_position + 6] = (value >> 48) & 0xff;
    _data[_position + 7] = (value >> 56) & 0xff;
    _position += 8;
}

void Memory::writeInt64Be(int64_t value) {
    _data[_position + 0] = (value >> 56) & 0xff;
    _data[_position + 1] = (value >> 48) & 0xff;
    _data[_position + 2] = (value >> 40) & 0xff;
    _data[_position + 3] = (value >> 32) & 0xff;
    _data[_position + 4] = (value >> 24) & 0xff;
    _data[_position + 5] = (value >> 16) & 0xff;
    _data[_position + 6] = (value >> 8) & 0xff;
    _data[_position + 7] = (value >> 0) & 0xff;
    _position += 8;
}

void Memory::writeUInt16Le(uint16_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _position += 2;
}

void Memory::writeUInt16Be(uint16_t value) {
    _data[_position + 0] = (value >> 8) & 0xff;
    _data[_position + 1] = (value >> 0) & 0xff;
    _position += 2;
}

void Memory::writeUInt24Le(uint32_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _position += 3;
}

void Memory::writeUInt24Be(uint32_t value) {
    _data[_position + 0] = (value >> 16) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 0) & 0xff;
    _position += 3;
}

void Memory::writeUInt32Le(uint32_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _position += 4;
}

void Memory::writeUInt32Be(uint32_t value) {
    _data[_position + 0] = (value >> 24) & 0xff;
    _data[_position + 1] = (value >> 16) & 0xff;
    _data[_position + 2] = (value >> 8) & 0xff;
    _data[_position + 3] = (value >> 0) & 0xff;
    _position += 4;
}

void Memory::writeUInt40Le(uint64_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _data[_position + 4] = (value >> 32) & 0xff;
    _position += 5;
}

void Memory::writeUInt40Be(uint64_t value) {
    _data[_position + 0] = (value >> 32) & 0xff;
    _data[_position + 1] = (value >> 24) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 8) & 0xff;
    _data[_position + 4] = (value >> 0) & 0xff;
    _position += 5;
}

void Memory::writeUInt48Le(uint64_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _data[_position + 4] = (value >> 32) & 0xff;
    _data[_position + 5] = (value >> 40) & 0xff;
    _position += 6;
}

void Memory::writeUInt48Be(uint64_t value) {
    _data[_position + 0] = (value >> 40) & 0xff;
    _data[_position + 1] = (value >> 32) & 0xff;
    _data[_position + 2] = (value >> 24) & 0xff;
    _data[_position + 3] = (value >> 16) & 0xff;
    _data[_position + 4] = (value >> 8) & 0xff;
    _data[_position + 5] = (value >> 0) & 0xff;
    _position += 6;
}

void Memory::writeUInt56Le(uint64_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _data[_position + 4] = (value >> 32) & 0xff;
    _data[_position + 5] = (value >> 40) & 0xff;
    _data[_position + 6] = (value >> 48) & 0xff;
    _position += 7;
}

void Memory::writeUInt56Be(uint64_t value) {
    _data[_position + 0] = (value >> 48) & 0xff;
    _data[_position + 1] = (value >> 40) & 0xff;
    _data[_position + 2] = (value >> 32) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _data[_position + 4] = (value >> 16) & 0xff;
    _data[_position + 5] = (value >> 8) & 0xff;
    _data[_position + 6] = (value >> 0) & 0xff;
    _position += 7;
}

void Memory::writeUInt64Le(uint64_t value) {
    _data[_position + 0] = (value >> 0) & 0xff;
    _data[_position + 1] = (value >> 8) & 0xff;
    _data[_position + 2] = (value >> 16) & 0xff;
    _data[_position + 3] = (value >> 24) & 0xff;
    _data[_position + 4] = (value >> 32) & 0xff;
    _data[_position + 5] = (value >> 40) & 0xff;
    _data[_position + 6] = (value >> 48) & 0xff;
    _data[_position + 7] = (value >> 56) & 0xff;
    _position += 8;
}

void Memory::writeUInt64Be(uint64_t value) {
    _data[_position + 0] = (value >> 56) & 0xff;
    _data[_position + 1] = (value >> 48) & 0xff;
    _data[_position + 2] = (value >> 40) & 0xff;
    _data[_position + 3] = (value >> 32) & 0xff;
    _data[_position + 4] = (value >> 24) & 0xff;
    _data[_position + 5] = (value >> 16) & 0xff;
    _data[_position + 6] = (value >> 8) & 0xff;
    _data[_position + 7] = (value >> 0) & 0xff;
    _position += 8;
}

// GENERATION END

float Memory::readSingle() {
    float result;
    memcpy(&result, _data, sizeof(float));
    _position += sizeof(float);
    return result;
}

double Memory::readDouble() {
    double result;
    memcpy(&result, _data, sizeof(double));
    _position += sizeof(double);
    return result;
}

void Memory::writeSingle(float value) {
    memcpy(_data, &value, sizeof(float));
    _position += sizeof(float);
}

void Memory::writeDouble(double value) {
    memcpy(_data, &value, sizeof(double));
    _position += sizeof(double);
}

Buffer Memory::readOctstr() {
    return readOctstrData(readUInt8());
}

Buffer Memory::readOctstr16Le() {
    return readOctstrData(readUInt16Le());
}

Buffer Memory::readOctstrData(int length) {
    auto result = Buffer(_data + _position, length);
    _position += length;
    return result;
}

void Memory::writeOctstr(const Buffer& value) {
	int length = value.length();
    if (length > 254) {
        ERROR(F("Writing octstr of more than 254 bytes"));
    }
    writeUInt8(length);
    writeOctstrData(value);
}

void Memory::writeOctstr16Le(const Buffer& value) {
    int length = value.length();
    writeUInt16Le(length);
    writeOctstrData(value);
}

void Memory::writeOctstrData(const Buffer& value) {
    value.getBytes(_data + _position);
    _position += value.length();
}

String Memory::readString() {
    return readStringData(readUInt8());
}

String Memory::readString16Le() {
    return readStringData(readUInt16Le());
}

String Memory::readStringData(int length) {
    auto result = String();

    // See https://github.com/arduino/ArduinoCore-sam/blob/790ff2c852bf159787a9966bddee4d9f55352d15/cores/arduino/WString.cpp#L159.
    // Reserve reserves the maximum string length, not the number of bytes.
    // It'll actually allocate one extra byte.
    result.reserve(length);

    for (int i = 0; i < length; i++) {
        result += (char)readUInt8();
    }
    return result;
}

void Memory::writeString(const String& value) {
    int length = value.length();
    if (length > 254) {
        ERROR(F("Writing string of more than 254 bytes"));
    }
    writeUInt8(length);
    writeStringData(value);
}

void Memory::writeString16Le(const String& value) {
    int length = value.length();
    writeUInt16Le(length);
    writeStringData(value);
}

void Memory::writeStringData(const String& value) {
	int length = value.length();
    memcpy(_data + _position, value.c_str(), length);
    _position += length;
}
