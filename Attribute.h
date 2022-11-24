#pragma once

#include "Arduino.h"
#include "Buffer.h"
#include "DataType.h"
#include "DateTime.h"
#include "Memory.h"

class Attribute {
	DataType _dataType;
	uint16_t _attributeId;

	union Value {
		uint64_t ui64;
		int64_t i64;
		String string;
		Buffer buffer;
		float f16;
		double f32;
		DateTime dateTime;

        ~Value() { }
    } _value = {};

	// Reporting configuration

	bool _reporting;
	bool _unreported;
	uint16_t _minimumReportingInterval;
	uint16_t _maximumReportingInterval;
	uint64_t _reportableChange;
	uint16_t _timeoutPeriod;

	unsigned long _lastReported;

public:
	Attribute(uint16_t attributeId);
	~Attribute();
	uint16_t getAttributeId();

	bool isReporting();
	bool isUnreported();
	void markReported();

	uint8_t configureReporting(uint16_t minimumInterval, uint16_t maximumInterval, uint8_t reportableChange, uint16_t timeoutPeriod);
	DataType getDataType();

// GENERATION START
    String toString();
    void write(Memory& memory);
    uint8_t getData8();
    void setData8(uint8_t value);
    uint16_t getData16();
    void setData16(uint16_t value);
    uint32_t getData24();
    void setData24(uint32_t value);
    uint32_t getData32();
    void setData32(uint32_t value);
    uint64_t getData40();
    void setData40(uint64_t value);
    uint64_t getData48();
    void setData48(uint64_t value);
    uint64_t getData56();
    void setData56(uint64_t value);
    uint64_t getData64();
    void setData64(uint64_t value);
    bool getBool();
    void setBool(bool value);
    uint8_t getMap8();
    void setMap8(uint8_t value);
    uint16_t getMap16();
    void setMap16(uint16_t value);
    uint32_t getMap24();
    void setMap24(uint32_t value);
    uint32_t getMap32();
    void setMap32(uint32_t value);
    uint64_t getMap40();
    void setMap40(uint64_t value);
    uint64_t getMap48();
    void setMap48(uint64_t value);
    uint64_t getMap56();
    void setMap56(uint64_t value);
    uint64_t getMap64();
    void setMap64(uint64_t value);
    uint8_t getUInt8();
    void setUInt8(uint8_t value);
    uint16_t getUInt16();
    void setUInt16(uint16_t value);
    uint32_t getUInt24();
    void setUInt24(uint32_t value);
    uint32_t getUInt32();
    void setUInt32(uint32_t value);
    uint64_t getUInt40();
    void setUInt40(uint64_t value);
    uint64_t getUInt48();
    void setUInt48(uint64_t value);
    uint64_t getUInt56();
    void setUInt56(uint64_t value);
    uint64_t getUInt64();
    void setUInt64(uint64_t value);
    int8_t getInt8();
    void setInt8(int8_t value);
    int16_t getInt16();
    void setInt16(int16_t value);
    int32_t getInt24();
    void setInt24(int32_t value);
    int32_t getInt32();
    void setInt32(int32_t value);
    int64_t getInt40();
    void setInt40(int64_t value);
    int64_t getInt48();
    void setInt48(int64_t value);
    int64_t getInt56();
    void setInt56(int64_t value);
    int64_t getInt64();
    void setInt64(int64_t value);
    uint8_t getEnum8();
    void setEnum8(uint8_t value);
    uint16_t getEnum16();
    void setEnum16(uint16_t value);
    float getSemi();
    void setSemi(float value);
    float getSingle();
    void setSingle(float value);
    double getDouble();
    void setDouble(double value);
    Buffer getOctstr();
    void setOctstr(const Buffer& value);
    String getString();
    void setString(const String& value);
    DateTime getDateTime();
    void setDateTime(const DateTime& value);
    uint32_t getToD();
    void setToD(uint32_t value);
    uint32_t getDate();
    void setDate(uint32_t value);
    uint32_t getUTC();
    void setUTC(uint32_t value);
    uint16_t getClusterId();
    void setClusterId(uint16_t value);
    uint16_t getAttribId();
    void setAttribId(uint16_t value);
    uint32_t getBacOID();
    void setBacOID(uint32_t value);
    uint64_t getEUI64();
    void setEUI64(uint64_t value);
// GENERATION END

private:
    void setDataType(DataType dataType);
};
