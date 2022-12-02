#include "ZigBeeHomeAutomation.h"

Cluster::Cluster(uint16_t clusterId, ClusterType type) : _clusterId(clusterId), _type(type) {
}

Cluster::~Cluster() {
	while (_attributes.size() > 0) {
		delete _attributes.shift();
	}
}

Attribute* Cluster::getAttributeById(uint16_t attributeId) {
	for (int i = 0; i < _attributes.size(); i++) {
		auto attribute = _attributes.get(i);
		if (attribute->getAttributeId() == attributeId) {
			return attribute;
		}
	}
	return nullptr;
}

int Cluster::getAttributeIndex(uint16_t attrId) {
	for (int i = 0; i < _attributes.size(); i++) {
		Attribute* cur = _attributes.get(i);
			if (cur->getAttributeId() == attrId) {
				return i;
			}
	}
	return -1;
}

Attribute* Cluster::getAttributeByIndex(int index) {
	return _attributes.get(index);
}

void Cluster::reportAttributes(XBee& device, uint8_t endpointId, Memory& buffer) {
	for (auto i = 0; i < getAttributeCount(); i++) {
		getAttributeByIndex(i)->report(device, endpointId, _clusterId, buffer);
	}
}

void Cluster::addAttribute(Attribute* attribute) {
	_attributes.add(attribute);
}
