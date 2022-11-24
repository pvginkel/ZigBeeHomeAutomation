#pragma once

class Cluster {
    LinkedList<Attribute*> _attributes;
    uint16_t _clusterId;

public:
    Cluster(uint16_t clusterId);

	uint16_t getClusterId();
	Attribute* getAttributeById(uint16_t attributeId, bool add = false);
    int getAttributeIndex(uint16_t attrId);
    Attribute* getAttributeByIndex(int index);
    int getAttributeCount() { return _attributes.size(); }

    virtual void processCommand(uint8_t commandId, Memory& request, Memory& response) {
        response.writeUInt8((uint8_t)Status::UnsupportedAttribute);
    }

protected:
// GENERATION START
    uint8_t getData8(uint16_t attributeId);
    void setData8(uint16_t attributeId, uint8_t value);
    uint16_t getData16(uint16_t attributeId);
    void setData16(uint16_t attributeId, uint16_t value);
    uint32_t getData24(uint16_t attributeId);
    void setData24(uint16_t attributeId, uint32_t value);
    uint32_t getData32(uint16_t attributeId);
    void setData32(uint16_t attributeId, uint32_t value);
    uint64_t getData40(uint16_t attributeId);
    void setData40(uint16_t attributeId, uint64_t value);
    uint64_t getData48(uint16_t attributeId);
    void setData48(uint16_t attributeId, uint64_t value);
    uint64_t getData56(uint16_t attributeId);
    void setData56(uint16_t attributeId, uint64_t value);
    uint64_t getData64(uint16_t attributeId);
    void setData64(uint16_t attributeId, uint64_t value);
    bool getBool(uint16_t attributeId);
    void setBool(uint16_t attributeId, bool value);
    uint8_t getMap8(uint16_t attributeId);
    void setMap8(uint16_t attributeId, uint8_t value);
    uint16_t getMap16(uint16_t attributeId);
    void setMap16(uint16_t attributeId, uint16_t value);
    uint32_t getMap24(uint16_t attributeId);
    void setMap24(uint16_t attributeId, uint32_t value);
    uint32_t getMap32(uint16_t attributeId);
    void setMap32(uint16_t attributeId, uint32_t value);
    uint64_t getMap40(uint16_t attributeId);
    void setMap40(uint16_t attributeId, uint64_t value);
    uint64_t getMap48(uint16_t attributeId);
    void setMap48(uint16_t attributeId, uint64_t value);
    uint64_t getMap56(uint16_t attributeId);
    void setMap56(uint16_t attributeId, uint64_t value);
    uint64_t getMap64(uint16_t attributeId);
    void setMap64(uint16_t attributeId, uint64_t value);
    uint8_t getUInt8(uint16_t attributeId);
    void setUInt8(uint16_t attributeId, uint8_t value);
    uint16_t getUInt16(uint16_t attributeId);
    void setUInt16(uint16_t attributeId, uint16_t value);
    uint32_t getUInt24(uint16_t attributeId);
    void setUInt24(uint16_t attributeId, uint32_t value);
    uint32_t getUInt32(uint16_t attributeId);
    void setUInt32(uint16_t attributeId, uint32_t value);
    uint64_t getUInt40(uint16_t attributeId);
    void setUInt40(uint16_t attributeId, uint64_t value);
    uint64_t getUInt48(uint16_t attributeId);
    void setUInt48(uint16_t attributeId, uint64_t value);
    uint64_t getUInt56(uint16_t attributeId);
    void setUInt56(uint16_t attributeId, uint64_t value);
    uint64_t getUInt64(uint16_t attributeId);
    void setUInt64(uint16_t attributeId, uint64_t value);
    int8_t getInt8(uint16_t attributeId);
    void setInt8(uint16_t attributeId, int8_t value);
    int16_t getInt16(uint16_t attributeId);
    void setInt16(uint16_t attributeId, int16_t value);
    int32_t getInt24(uint16_t attributeId);
    void setInt24(uint16_t attributeId, int32_t value);
    int32_t getInt32(uint16_t attributeId);
    void setInt32(uint16_t attributeId, int32_t value);
    int64_t getInt40(uint16_t attributeId);
    void setInt40(uint16_t attributeId, int64_t value);
    int64_t getInt48(uint16_t attributeId);
    void setInt48(uint16_t attributeId, int64_t value);
    int64_t getInt56(uint16_t attributeId);
    void setInt56(uint16_t attributeId, int64_t value);
    int64_t getInt64(uint16_t attributeId);
    void setInt64(uint16_t attributeId, int64_t value);
    uint8_t getEnum8(uint16_t attributeId);
    void setEnum8(uint16_t attributeId, uint8_t value);
    uint16_t getEnum16(uint16_t attributeId);
    void setEnum16(uint16_t attributeId, uint16_t value);
    float getSemi(uint16_t attributeId);
    void setSemi(uint16_t attributeId, float value);
    float getSingle(uint16_t attributeId);
    void setSingle(uint16_t attributeId, float value);
    double getDouble(uint16_t attributeId);
    void setDouble(uint16_t attributeId, double value);
    Buffer getOctstr(uint16_t attributeId);
    void setOctstr(uint16_t attributeId, const Buffer& value);
    String getString(uint16_t attributeId);
    void setString(uint16_t attributeId, const String& value);
    DateTime getDateTime(uint16_t attributeId);
    void setDateTime(uint16_t attributeId, const DateTime& value);
    uint32_t getToD(uint16_t attributeId);
    void setToD(uint16_t attributeId, uint32_t value);
    uint32_t getDate(uint16_t attributeId);
    void setDate(uint16_t attributeId, uint32_t value);
    uint32_t getUTC(uint16_t attributeId);
    void setUTC(uint16_t attributeId, uint32_t value);
    uint16_t getClusterId(uint16_t attributeId);
    void setClusterId(uint16_t attributeId, uint16_t value);
    uint16_t getAttribId(uint16_t attributeId);
    void setAttribId(uint16_t attributeId, uint16_t value);
    uint32_t getBacOID(uint16_t attributeId);
    void setBacOID(uint16_t attributeId, uint32_t value);
    uint64_t getEUI64(uint16_t attributeId);
    void setEUI64(uint16_t attributeId, uint64_t value);
// GENERATION END
};
