#pragma once

enum class ClusterType {
    Input,
    Output
};

class Device;

class Cluster {
    ArrayList<Attribute*> _attributes;
    uint16_t _clusterId;
    ClusterType _type;
    Device* _device;

    friend Device;

public:
    Cluster(uint16_t clusterId, ClusterType type);
    Cluster(const Cluster&) = delete;
    virtual ~Cluster();

    Device* getDevice() { return _device; }
    ClusterType getType() { return _type; }
    uint16_t getClusterId() { return _clusterId; }

    void addAttribute(Attribute* attribute);
    Attribute* getAttributeById(uint16_t attributeId);
    int getAttributeIndex(uint16_t attrId);
    Attribute* getAttributeByIndex(int index);
    int getAttributeCount() { return _attributes.size(); }

    virtual void processCommand(uint8_t commandId, Memory& request, Memory& response) {
        response.writeUInt8((uint8_t)Status::UnsupportedAttribute);
    }

    Attribute* reportAttribute(XBee& device, Memory& buffer);

    Cluster& operator=(const Cluster&) = delete;
};
