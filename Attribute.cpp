#include "ZigBee.h"

Attribute::Attribute(uint16_t attributeId) :
	_dataType(DataType::NoData), _attributeId(attributeId), _reporting(false), _unreported(false),
	_minimumReportingInterval(false), _maximumReportingInterval(false), _reportableChange(0), _timeoutPeriod(0),
	_lastReported(0) {
}

Attribute::~Attribute() {
    setDataType(DataType::NoData);
}

void Attribute::setDataType(DataType dataType) {
    if (dataType != _dataType) {
        // Cleanly destruct the string or buffer in the union.
        switch (_dataType) {
        case DataType::String:
        case DataType::String16:
            auto string = _value.string;
            break;
        case DataType::Octstr:
        case DataType::Octstr16:
            auto buffer = _value.buffer;
            break;
        }
        memset(&_value, 0, sizeof(_value));

        _dataType = dataType;
    }
}

uint16_t Attribute::getAttributeId() {
    return _attributeId;
}

bool Attribute::isReporting() {
    return _reporting;
}

bool Attribute::isUnreported() {
    return _unreported;
}

void Attribute::markReported() {
    _unreported = false;
}

uint8_t Attribute::configureReporting(uint16_t minimumInterval, uint16_t maximumInterval, uint8_t reportableChange, uint16_t timeoutPeriod) {
    _lastReported = 0;
    _minimumReportingInterval = minimumInterval;
    _maximumReportingInterval = maximumInterval;
    _reportableChange = reportableChange;
    _timeoutPeriod = timeoutPeriod;
    _reporting = true;
}

DataType Attribute::getDataType() {
    return _dataType;
}

// GENERATION START
String Attribute::toString() {
    switch (_dataType) {
        case DataType::Data8:
            return String((uint32_t)_value.ui64);
        case DataType::Data16:
            return String((uint32_t)_value.ui64);
        case DataType::Data24:
            return String((uint32_t)_value.ui64);
        case DataType::Data32:
            return String((uint32_t)_value.ui64);
        case DataType::Data40:
            return String((uint32_t)_value.ui64);
        case DataType::Data48:
            return String((uint32_t)_value.ui64);
        case DataType::Data56:
            return String((uint32_t)_value.ui64);
        case DataType::Data64:
            return String((uint32_t)_value.ui64);
        case DataType::Bool:
            return String((int32_t)_value.i64);
        case DataType::Map8:
            return String((uint32_t)_value.ui64);
        case DataType::Map16:
            return String((uint32_t)_value.ui64);
        case DataType::Map24:
            return String((uint32_t)_value.ui64);
        case DataType::Map32:
            return String((uint32_t)_value.ui64);
        case DataType::Map40:
            return String((uint32_t)_value.ui64);
        case DataType::Map48:
            return String((uint32_t)_value.ui64);
        case DataType::Map56:
            return String((uint32_t)_value.ui64);
        case DataType::Map64:
            return String((uint32_t)_value.ui64);
        case DataType::UInt8:
            return String((uint32_t)_value.ui64);
        case DataType::UInt16:
            return String((uint32_t)_value.ui64);
        case DataType::UInt24:
            return String((uint32_t)_value.ui64);
        case DataType::UInt32:
            return String((uint32_t)_value.ui64);
        case DataType::UInt40:
            return String((uint32_t)_value.ui64);
        case DataType::UInt48:
            return String((uint32_t)_value.ui64);
        case DataType::UInt56:
            return String((uint32_t)_value.ui64);
        case DataType::UInt64:
            return String((uint32_t)_value.ui64);
        case DataType::Int8:
            return String((int32_t)_value.i64);
        case DataType::Int16:
            return String((int32_t)_value.i64);
        case DataType::Int24:
            return String((int32_t)_value.i64);
        case DataType::Int32:
            return String((int32_t)_value.i64);
        case DataType::Int40:
            return String((int32_t)_value.i64);
        case DataType::Int48:
            return String((int32_t)_value.i64);
        case DataType::Int56:
            return String((int32_t)_value.i64);
        case DataType::Int64:
            return String((int32_t)_value.i64);
        case DataType::Enum8:
            return String((uint32_t)_value.ui64);
        case DataType::Enum16:
            return String((uint32_t)_value.ui64);
        case DataType::Semi:
            return String(_value.f16);
        case DataType::Single:
            return String(_value.f16);
        case DataType::Double:
            return String(_value.f32);
        case DataType::Octstr:
            return "BUFFER";
        case DataType::String:
            if (_dataType == DataType::String || _dataType == DataType::String16) {
                return _value.string;
            }
            return "";
        case DataType::DateTime:
            return "DATETIME";
        case DataType::ToD:
            return String((uint32_t)_value.ui64);
        case DataType::Date:
            return String((uint32_t)_value.ui64);
        case DataType::UTC:
            return String((uint32_t)_value.ui64);
        case DataType::ClusterId:
            return String((uint32_t)_value.ui64);
        case DataType::AttribId:
            return String((uint32_t)_value.ui64);
        case DataType::BacOID:
            return String((uint32_t)_value.ui64);
        case DataType::EUI64:
            return String((uint32_t)_value.ui64);
        default:
            return "NULL";
    }
}

void Attribute::write(Memory& memory) {
    switch (_dataType) {
        case DataType::Data8:
            memory.writeUInt8(_value.ui64);
            break;
        case DataType::Data16:
            memory.writeUInt16Le(_value.ui64);
            break;
        case DataType::Data24:
            memory.writeUInt24Le(_value.ui64);
            break;
        case DataType::Data32:
            memory.writeUInt32Le(_value.ui64);
            break;
        case DataType::Data40:
            memory.writeUInt40Le(_value.ui64);
            break;
        case DataType::Data48:
            memory.writeUInt48Le(_value.ui64);
            break;
        case DataType::Data56:
            memory.writeUInt56Le(_value.ui64);
            break;
        case DataType::Data64:
            memory.writeUInt64Le(_value.ui64);
            break;
        case DataType::Bool:
            memory.writeUInt8(_value.i64);
            break;
        case DataType::Map8:
            memory.writeUInt8(_value.ui64);
            break;
        case DataType::Map16:
            memory.writeUInt16Le(_value.ui64);
            break;
        case DataType::Map24:
            memory.writeUInt24Le(_value.ui64);
            break;
        case DataType::Map32:
            memory.writeUInt32Le(_value.ui64);
            break;
        case DataType::Map40:
            memory.writeUInt40Le(_value.ui64);
            break;
        case DataType::Map48:
            memory.writeUInt48Le(_value.ui64);
            break;
        case DataType::Map56:
            memory.writeUInt56Le(_value.ui64);
            break;
        case DataType::Map64:
            memory.writeUInt64Le(_value.ui64);
            break;
        case DataType::UInt8:
            memory.writeUInt8(_value.ui64);
            break;
        case DataType::UInt16:
            memory.writeUInt16Le(_value.ui64);
            break;
        case DataType::UInt24:
            memory.writeUInt24Le(_value.ui64);
            break;
        case DataType::UInt32:
            memory.writeUInt32Le(_value.ui64);
            break;
        case DataType::UInt40:
            memory.writeUInt40Le(_value.ui64);
            break;
        case DataType::UInt48:
            memory.writeUInt48Le(_value.ui64);
            break;
        case DataType::UInt56:
            memory.writeUInt56Le(_value.ui64);
            break;
        case DataType::UInt64:
            memory.writeUInt64Le(_value.ui64);
            break;
        case DataType::Int8:
            memory.writeInt8(_value.i64);
            break;
        case DataType::Int16:
            memory.writeInt16Le(_value.i64);
            break;
        case DataType::Int24:
            memory.writeInt24Le(_value.i64);
            break;
        case DataType::Int32:
            memory.writeInt32Le(_value.i64);
            break;
        case DataType::Int40:
            memory.writeInt40Le(_value.i64);
            break;
        case DataType::Int48:
            memory.writeInt48Le(_value.i64);
            break;
        case DataType::Int56:
            memory.writeInt56Le(_value.i64);
            break;
        case DataType::Int64:
            memory.writeInt64Le(_value.i64);
            break;
        case DataType::Enum8:
            memory.writeUInt8(_value.ui64);
            break;
        case DataType::Enum16:
            memory.writeUInt16Le(_value.ui64);
            break;
        case DataType::Single:
            memory.writeSingle(_value.f16);
            break;
        case DataType::Double:
            memory.writeDouble(_value.f32);
            break;
        case DataType::Octstr:
            memory.writeOctstr(_value.buffer);
            break;
        case DataType::String:
            memory.writeString(_value.string);
            break;
        case DataType::Octstr16:
            memory.writeOctstr16Le(_value.buffer);
            break;
        case DataType::String16:
            memory.writeString16Le(_value.string);
            break;
        case DataType::DateTime:
            memory.writeUInt8((uint8_t)DataType::Date);
            memory.writeUInt32Le(_value.dateTime.getDate());
            memory.writeUInt8((uint8_t)DataType::ToD);
            memory.writeUInt32Le(_value.dateTime.getTime());
            break;
        case DataType::ToD:
            memory.writeUInt32Le(_value.ui64);
            break;
        case DataType::Date:
            memory.writeUInt32Le(_value.ui64);
            break;
        case DataType::UTC:
            memory.writeUInt32Le(_value.ui64);
            break;
        case DataType::ClusterId:
            memory.writeUInt16Le(_value.ui64);
            break;
        case DataType::AttribId:
            memory.writeUInt16Le(_value.ui64);
            break;
        case DataType::BacOID:
            memory.writeUInt32Le(_value.ui64);
            break;
        case DataType::EUI64:
            memory.writeUInt64Le(_value.ui64);
            break;
    }
}

uint8_t Attribute::getData8() {
    return _value.ui64;
}

void Attribute::setData8(uint8_t value) {
    setDataType(DataType::Data8);
    _value.ui64 = value;
    _unreported = true;
}

uint16_t Attribute::getData16() {
    return _value.ui64;
}

void Attribute::setData16(uint16_t value) {
    setDataType(DataType::Data16);
    _value.ui64 = value;
    _unreported = true;
}

uint32_t Attribute::getData24() {
    return _value.ui64;
}

void Attribute::setData24(uint32_t value) {
    setDataType(DataType::Data24);
    _value.ui64 = value;
    _unreported = true;
}

uint32_t Attribute::getData32() {
    return _value.ui64;
}

void Attribute::setData32(uint32_t value) {
    setDataType(DataType::Data32);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getData40() {
    return _value.ui64;
}

void Attribute::setData40(uint64_t value) {
    setDataType(DataType::Data40);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getData48() {
    return _value.ui64;
}

void Attribute::setData48(uint64_t value) {
    setDataType(DataType::Data48);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getData56() {
    return _value.ui64;
}

void Attribute::setData56(uint64_t value) {
    setDataType(DataType::Data56);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getData64() {
    return _value.ui64;
}

void Attribute::setData64(uint64_t value) {
    setDataType(DataType::Data64);
    _value.ui64 = value;
    _unreported = true;
}

bool Attribute::getBool() {
    return _value.i64;
}

void Attribute::setBool(bool value) {
    setDataType(DataType::Bool);
    _value.i64 = value;
    _unreported = true;
}

uint8_t Attribute::getMap8() {
    return _value.ui64;
}

void Attribute::setMap8(uint8_t value) {
    setDataType(DataType::Map8);
    _value.ui64 = value;
    _unreported = true;
}

uint16_t Attribute::getMap16() {
    return _value.ui64;
}

void Attribute::setMap16(uint16_t value) {
    setDataType(DataType::Map16);
    _value.ui64 = value;
    _unreported = true;
}

uint32_t Attribute::getMap24() {
    return _value.ui64;
}

void Attribute::setMap24(uint32_t value) {
    setDataType(DataType::Map24);
    _value.ui64 = value;
    _unreported = true;
}

uint32_t Attribute::getMap32() {
    return _value.ui64;
}

void Attribute::setMap32(uint32_t value) {
    setDataType(DataType::Map32);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getMap40() {
    return _value.ui64;
}

void Attribute::setMap40(uint64_t value) {
    setDataType(DataType::Map40);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getMap48() {
    return _value.ui64;
}

void Attribute::setMap48(uint64_t value) {
    setDataType(DataType::Map48);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getMap56() {
    return _value.ui64;
}

void Attribute::setMap56(uint64_t value) {
    setDataType(DataType::Map56);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getMap64() {
    return _value.ui64;
}

void Attribute::setMap64(uint64_t value) {
    setDataType(DataType::Map64);
    _value.ui64 = value;
    _unreported = true;
}

uint8_t Attribute::getUInt8() {
    return _value.ui64;
}

void Attribute::setUInt8(uint8_t value) {
    setDataType(DataType::UInt8);
    _value.ui64 = value;
    _unreported = true;
}

uint16_t Attribute::getUInt16() {
    return _value.ui64;
}

void Attribute::setUInt16(uint16_t value) {
    setDataType(DataType::UInt16);
    _value.ui64 = value;
    _unreported = true;
}

uint32_t Attribute::getUInt24() {
    return _value.ui64;
}

void Attribute::setUInt24(uint32_t value) {
    setDataType(DataType::UInt24);
    _value.ui64 = value;
    _unreported = true;
}

uint32_t Attribute::getUInt32() {
    return _value.ui64;
}

void Attribute::setUInt32(uint32_t value) {
    setDataType(DataType::UInt32);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getUInt40() {
    return _value.ui64;
}

void Attribute::setUInt40(uint64_t value) {
    setDataType(DataType::UInt40);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getUInt48() {
    return _value.ui64;
}

void Attribute::setUInt48(uint64_t value) {
    setDataType(DataType::UInt48);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getUInt56() {
    return _value.ui64;
}

void Attribute::setUInt56(uint64_t value) {
    setDataType(DataType::UInt56);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getUInt64() {
    return _value.ui64;
}

void Attribute::setUInt64(uint64_t value) {
    setDataType(DataType::UInt64);
    _value.ui64 = value;
    _unreported = true;
}

int8_t Attribute::getInt8() {
    return _value.i64;
}

void Attribute::setInt8(int8_t value) {
    setDataType(DataType::Int8);
    _value.i64 = value;
    _unreported = true;
}

int16_t Attribute::getInt16() {
    return _value.i64;
}

void Attribute::setInt16(int16_t value) {
    setDataType(DataType::Int16);
    _value.i64 = value;
    _unreported = true;
}

int32_t Attribute::getInt24() {
    return _value.i64;
}

void Attribute::setInt24(int32_t value) {
    setDataType(DataType::Int24);
    _value.i64 = value;
    _unreported = true;
}

int32_t Attribute::getInt32() {
    return _value.i64;
}

void Attribute::setInt32(int32_t value) {
    setDataType(DataType::Int32);
    _value.i64 = value;
    _unreported = true;
}

int64_t Attribute::getInt40() {
    return _value.i64;
}

void Attribute::setInt40(int64_t value) {
    setDataType(DataType::Int40);
    _value.i64 = value;
    _unreported = true;
}

int64_t Attribute::getInt48() {
    return _value.i64;
}

void Attribute::setInt48(int64_t value) {
    setDataType(DataType::Int48);
    _value.i64 = value;
    _unreported = true;
}

int64_t Attribute::getInt56() {
    return _value.i64;
}

void Attribute::setInt56(int64_t value) {
    setDataType(DataType::Int56);
    _value.i64 = value;
    _unreported = true;
}

int64_t Attribute::getInt64() {
    return _value.i64;
}

void Attribute::setInt64(int64_t value) {
    setDataType(DataType::Int64);
    _value.i64 = value;
    _unreported = true;
}

uint8_t Attribute::getEnum8() {
    return _value.ui64;
}

void Attribute::setEnum8(uint8_t value) {
    setDataType(DataType::Enum8);
    _value.ui64 = value;
    _unreported = true;
}

uint16_t Attribute::getEnum16() {
    return _value.ui64;
}

void Attribute::setEnum16(uint16_t value) {
    setDataType(DataType::Enum16);
    _value.ui64 = value;
    _unreported = true;
}

float Attribute::getSemi() {
    return _value.f16;
}

void Attribute::setSemi(float value) {
    setDataType(DataType::Semi);
    _value.f16 = value;
    _unreported = true;
}

float Attribute::getSingle() {
    return _value.f16;
}

void Attribute::setSingle(float value) {
    setDataType(DataType::Single);
    _value.f16 = value;
    _unreported = true;
}

double Attribute::getDouble() {
    return _value.f32;
}

void Attribute::setDouble(double value) {
    setDataType(DataType::Double);
    _value.f32 = value;
    _unreported = true;
}

Buffer Attribute::getOctstr() {
    if (_dataType == DataType::Octstr || _dataType == DataType::Octstr16) {
        return _value.buffer;
    }
    return Buffer();
}

void Attribute::setOctstr(const Buffer& value) {
    setDataType(DataType::Octstr);
    _value.buffer = value;
    _unreported = true;
}

String Attribute::getString() {
    if (_dataType == DataType::String || _dataType == DataType::String16) {
        return _value.string;
    }
    return String();
}

void Attribute::setString(const String& value) {
    setDataType(DataType::String);
    _value.string = value;
    _unreported = true;
}

DateTime Attribute::getDateTime() {
    return _value.dateTime;
}

void Attribute::setDateTime(const DateTime& value) {
    setDataType(DataType::DateTime);
    _value.dateTime = value;
    _unreported = true;
}

uint32_t Attribute::getToD() {
    return _value.ui64;
}

void Attribute::setToD(uint32_t value) {
    setDataType(DataType::ToD);
    _value.ui64 = value;
    _unreported = true;
}

uint32_t Attribute::getDate() {
    return _value.ui64;
}

void Attribute::setDate(uint32_t value) {
    setDataType(DataType::Date);
    _value.ui64 = value;
    _unreported = true;
}

uint32_t Attribute::getUTC() {
    return _value.ui64;
}

void Attribute::setUTC(uint32_t value) {
    setDataType(DataType::UTC);
    _value.ui64 = value;
    _unreported = true;
}

uint16_t Attribute::getClusterId() {
    return _value.ui64;
}

void Attribute::setClusterId(uint16_t value) {
    setDataType(DataType::ClusterId);
    _value.ui64 = value;
    _unreported = true;
}

uint16_t Attribute::getAttribId() {
    return _value.ui64;
}

void Attribute::setAttribId(uint16_t value) {
    setDataType(DataType::AttribId);
    _value.ui64 = value;
    _unreported = true;
}

uint32_t Attribute::getBacOID() {
    return _value.ui64;
}

void Attribute::setBacOID(uint32_t value) {
    setDataType(DataType::BacOID);
    _value.ui64 = value;
    _unreported = true;
}

uint64_t Attribute::getEUI64() {
    return _value.ui64;
}

void Attribute::setEUI64(uint64_t value) {
    setDataType(DataType::EUI64);
    _value.ui64 = value;
    _unreported = true;
}

// GENERATION END
