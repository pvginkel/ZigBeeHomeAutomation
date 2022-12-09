#include "ZigBeeHomeAutomation.h"

Cluster::Cluster(uint16_t clusterId, ClusterType type) : _clusterId(clusterId), _type(type) {
}

Cluster::~Cluster() {
	for (auto attribute : _attributes) {
		delete attribute;
	}
}

Attribute* Cluster::getAttributeById(uint16_t attributeId) {
	for (auto attribute : _attributes) {
		if (attribute->getAttributeId() == attributeId) {
			return attribute;
		}
	}
	return nullptr;
}

int Cluster::getAttributeIndex(uint16_t attrId) {
	for (int i = 0; i < _attributes.size(); i++) {
		auto attribute = _attributes[i];
		if (attribute->getAttributeId() == attrId) {
			return i;
		}
	}
	return -1;
}

Attribute* Cluster::getAttributeByIndex(int index) {
	return _attributes[index];
}

Attribute* Cluster::reportAttribute(XBee& device, Memory& buffer) {
	for (auto attribute : _attributes) {
		if (attribute->report(device, buffer) == AttributeReportStatus::Reported) {
			return attribute;
		}
	}

	return nullptr;
}

void Cluster::addAttribute(Attribute* attribute) {
	attribute->_cluster = this;
	_attributes.add(attribute);
}
