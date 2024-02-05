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

void Cluster::addAttribute(Attribute* attribute) {
	_attributes.add(attribute);
}

Status Cluster::processWriteAttributeValue(uint16_t attributeId, DataType dataType, Memory& buffer) {
	auto attribute = getAttributeById(attributeId);

	if (!attribute) {
		return Status::UnsupportedAttribute;
	}

	if (dataType != attribute->getDataType()) {
		return Status::InvalidDataType;
	}

	auto attributeDataType = attribute->getDataType();
	if (attributeDataType == DataType::String) {
		((AttributeString*)attribute)->readStringValue(buffer, dataType);
	}
	else if (attributeDataType == DataType::Octstr) {
		((AttributeOctstr*)attribute)->readOctstrValue(buffer, dataType);
	}
	else {
		attribute->readValue(buffer);
	}

	return Status::Success;
}
