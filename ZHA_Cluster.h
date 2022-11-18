#pragma once

#include "Arduino.h"
#include "ZHA_Attributes.h"
#include <LinkedList.h>
#include "Buffer.h"
#include "Zcl.h"

class ZHA_Cluster {
    LinkedList<ZHA_Attribute*> _attrs;
    uint16_t _clusterId;

public:
    ZHA_Cluster(uint16_t clusterId);

	uint16_t getClusterId();
	ZHA_Attribute* getAttrById(uint16_t attrId);
    int getAttrIndexById(uint16_t attrId);
    ZHA_Attribute* getAttrByIndex(int index);
    int numAttributes() { return _attrs.size(); }

	void setAttribute(uint16_t attrId, uint8_t dataType, uint64_t value);
	void setAttribute(uint16_t attrId, uint8_t dataType, String value);

    virtual Zcl::Status processCommand(Buffer& frameData) {
        return Zcl::Status::UnsupportedAttribute;
    }
};
