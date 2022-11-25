#pragma once

class Cluster {
    LinkedList<Attribute*> _attributes;
    uint16_t _clusterId;

public:
    Cluster(uint16_t clusterId);
    Cluster(const Cluster&) = delete;
    virtual ~Cluster();

	uint16_t getClusterId();
	Attribute* getAttributeById(uint16_t attributeId);
    int getAttributeIndex(uint16_t attrId);
    Attribute* getAttributeByIndex(int index);
    int getAttributeCount() { return _attributes.size(); }

    virtual void processCommand(uint8_t commandId, Memory& request, Memory& response) {
        response.writeUInt8((uint8_t)Status::UnsupportedAttribute);
    }

    Cluster& operator=(const Cluster&) = delete;

protected:
    void addAttribute(Attribute* attribute);
};
