#include "Cluster.h"

Cluster::Cluster(uint16_t clusterId) : _clusterId(clusterId) {
}

uint16_t Cluster::getClusterId() {
	return _clusterId;
}

Attribute* Cluster::getAttributeById(uint16_t attributeId, bool add) {
	for (int i = 0; i < _attributes.size(); i++) {
		auto attribute = _attributes.get(i);
		if (attribute->getAttributeId() == attributeId) {
			return attribute;
		}
	}
	if (add) {
		auto attribute = new Attribute(attributeId);
		_attributes.add(attribute);
		return attribute;
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

// GENERATION START
uint8_t Cluster::getData8(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getData8();
    }
    return {};
}

void Cluster::setData8(uint16_t attributeId, uint8_t value) {
    getAttributeById(attributeId, true)->setData8(value);
}

uint16_t Cluster::getData16(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getData16();
    }
    return {};
}

void Cluster::setData16(uint16_t attributeId, uint16_t value) {
    getAttributeById(attributeId, true)->setData16(value);
}

uint32_t Cluster::getData24(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getData24();
    }
    return {};
}

void Cluster::setData24(uint16_t attributeId, uint32_t value) {
    getAttributeById(attributeId, true)->setData24(value);
}

uint32_t Cluster::getData32(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getData32();
    }
    return {};
}

void Cluster::setData32(uint16_t attributeId, uint32_t value) {
    getAttributeById(attributeId, true)->setData32(value);
}

uint64_t Cluster::getData40(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getData40();
    }
    return {};
}

void Cluster::setData40(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setData40(value);
}

uint64_t Cluster::getData48(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getData48();
    }
    return {};
}

void Cluster::setData48(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setData48(value);
}

uint64_t Cluster::getData56(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getData56();
    }
    return {};
}

void Cluster::setData56(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setData56(value);
}

uint64_t Cluster::getData64(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getData64();
    }
    return {};
}

void Cluster::setData64(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setData64(value);
}

bool Cluster::getBool(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getBool();
    }
    return {};
}

void Cluster::setBool(uint16_t attributeId, bool value) {
    getAttributeById(attributeId, true)->setBool(value);
}

uint8_t Cluster::getMap8(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getMap8();
    }
    return {};
}

void Cluster::setMap8(uint16_t attributeId, uint8_t value) {
    getAttributeById(attributeId, true)->setMap8(value);
}

uint16_t Cluster::getMap16(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getMap16();
    }
    return {};
}

void Cluster::setMap16(uint16_t attributeId, uint16_t value) {
    getAttributeById(attributeId, true)->setMap16(value);
}

uint32_t Cluster::getMap24(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getMap24();
    }
    return {};
}

void Cluster::setMap24(uint16_t attributeId, uint32_t value) {
    getAttributeById(attributeId, true)->setMap24(value);
}

uint32_t Cluster::getMap32(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getMap32();
    }
    return {};
}

void Cluster::setMap32(uint16_t attributeId, uint32_t value) {
    getAttributeById(attributeId, true)->setMap32(value);
}

uint64_t Cluster::getMap40(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getMap40();
    }
    return {};
}

void Cluster::setMap40(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setMap40(value);
}

uint64_t Cluster::getMap48(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getMap48();
    }
    return {};
}

void Cluster::setMap48(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setMap48(value);
}

uint64_t Cluster::getMap56(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getMap56();
    }
    return {};
}

void Cluster::setMap56(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setMap56(value);
}

uint64_t Cluster::getMap64(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getMap64();
    }
    return {};
}

void Cluster::setMap64(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setMap64(value);
}

uint8_t Cluster::getUInt8(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getUInt8();
    }
    return {};
}

void Cluster::setUInt8(uint16_t attributeId, uint8_t value) {
    getAttributeById(attributeId, true)->setUInt8(value);
}

uint16_t Cluster::getUInt16(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getUInt16();
    }
    return {};
}

void Cluster::setUInt16(uint16_t attributeId, uint16_t value) {
    getAttributeById(attributeId, true)->setUInt16(value);
}

uint32_t Cluster::getUInt24(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getUInt24();
    }
    return {};
}

void Cluster::setUInt24(uint16_t attributeId, uint32_t value) {
    getAttributeById(attributeId, true)->setUInt24(value);
}

uint32_t Cluster::getUInt32(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getUInt32();
    }
    return {};
}

void Cluster::setUInt32(uint16_t attributeId, uint32_t value) {
    getAttributeById(attributeId, true)->setUInt32(value);
}

uint64_t Cluster::getUInt40(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getUInt40();
    }
    return {};
}

void Cluster::setUInt40(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setUInt40(value);
}

uint64_t Cluster::getUInt48(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getUInt48();
    }
    return {};
}

void Cluster::setUInt48(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setUInt48(value);
}

uint64_t Cluster::getUInt56(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getUInt56();
    }
    return {};
}

void Cluster::setUInt56(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setUInt56(value);
}

uint64_t Cluster::getUInt64(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getUInt64();
    }
    return {};
}

void Cluster::setUInt64(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setUInt64(value);
}

int8_t Cluster::getInt8(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getInt8();
    }
    return {};
}

void Cluster::setInt8(uint16_t attributeId, int8_t value) {
    getAttributeById(attributeId, true)->setInt8(value);
}

int16_t Cluster::getInt16(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getInt16();
    }
    return {};
}

void Cluster::setInt16(uint16_t attributeId, int16_t value) {
    getAttributeById(attributeId, true)->setInt16(value);
}

int32_t Cluster::getInt24(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getInt24();
    }
    return {};
}

void Cluster::setInt24(uint16_t attributeId, int32_t value) {
    getAttributeById(attributeId, true)->setInt24(value);
}

int32_t Cluster::getInt32(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getInt32();
    }
    return {};
}

void Cluster::setInt32(uint16_t attributeId, int32_t value) {
    getAttributeById(attributeId, true)->setInt32(value);
}

int64_t Cluster::getInt40(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getInt40();
    }
    return {};
}

void Cluster::setInt40(uint16_t attributeId, int64_t value) {
    getAttributeById(attributeId, true)->setInt40(value);
}

int64_t Cluster::getInt48(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getInt48();
    }
    return {};
}

void Cluster::setInt48(uint16_t attributeId, int64_t value) {
    getAttributeById(attributeId, true)->setInt48(value);
}

int64_t Cluster::getInt56(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getInt56();
    }
    return {};
}

void Cluster::setInt56(uint16_t attributeId, int64_t value) {
    getAttributeById(attributeId, true)->setInt56(value);
}

int64_t Cluster::getInt64(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getInt64();
    }
    return {};
}

void Cluster::setInt64(uint16_t attributeId, int64_t value) {
    getAttributeById(attributeId, true)->setInt64(value);
}

uint8_t Cluster::getEnum8(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getEnum8();
    }
    return {};
}

void Cluster::setEnum8(uint16_t attributeId, uint8_t value) {
    getAttributeById(attributeId, true)->setEnum8(value);
}

uint16_t Cluster::getEnum16(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getEnum16();
    }
    return {};
}

void Cluster::setEnum16(uint16_t attributeId, uint16_t value) {
    getAttributeById(attributeId, true)->setEnum16(value);
}

float Cluster::getSemi(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getSemi();
    }
    return {};
}

void Cluster::setSemi(uint16_t attributeId, float value) {
    getAttributeById(attributeId, true)->setSemi(value);
}

float Cluster::getSingle(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getSingle();
    }
    return {};
}

void Cluster::setSingle(uint16_t attributeId, float value) {
    getAttributeById(attributeId, true)->setSingle(value);
}

double Cluster::getDouble(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getDouble();
    }
    return {};
}

void Cluster::setDouble(uint16_t attributeId, double value) {
    getAttributeById(attributeId, true)->setDouble(value);
}

Buffer Cluster::getOctstr(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getOctstr();
    }
    return {};
}

void Cluster::setOctstr(uint16_t attributeId, const Buffer& value) {
    getAttributeById(attributeId, true)->setOctstr(value);
}

String Cluster::getString(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getString();
    }
    return {};
}

void Cluster::setString(uint16_t attributeId, const String& value) {
    getAttributeById(attributeId, true)->setString(value);
}

DateTime Cluster::getDateTime(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getDateTime();
    }
    return {};
}

void Cluster::setDateTime(uint16_t attributeId, const DateTime& value) {
    getAttributeById(attributeId, true)->setDateTime(value);
}

uint32_t Cluster::getToD(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getToD();
    }
    return {};
}

void Cluster::setToD(uint16_t attributeId, uint32_t value) {
    getAttributeById(attributeId, true)->setToD(value);
}

uint32_t Cluster::getDate(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getDate();
    }
    return {};
}

void Cluster::setDate(uint16_t attributeId, uint32_t value) {
    getAttributeById(attributeId, true)->setDate(value);
}

uint32_t Cluster::getUTC(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getUTC();
    }
    return {};
}

void Cluster::setUTC(uint16_t attributeId, uint32_t value) {
    getAttributeById(attributeId, true)->setUTC(value);
}

uint16_t Cluster::getClusterId(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getClusterId();
    }
    return {};
}

void Cluster::setClusterId(uint16_t attributeId, uint16_t value) {
    getAttributeById(attributeId, true)->setClusterId(value);
}

uint16_t Cluster::getAttribId(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getAttribId();
    }
    return {};
}

void Cluster::setAttribId(uint16_t attributeId, uint16_t value) {
    getAttributeById(attributeId, true)->setAttribId(value);
}

uint32_t Cluster::getBacOID(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getBacOID();
    }
    return {};
}

void Cluster::setBacOID(uint16_t attributeId, uint32_t value) {
    getAttributeById(attributeId, true)->setBacOID(value);
}

uint64_t Cluster::getEUI64(uint16_t attributeId) {
    auto attribute = getAttributeById(attributeId);
    if (attribute) {
        return attribute->getEUI64();
    }
    return {};
}

void Cluster::setEUI64(uint16_t attributeId, uint64_t value) {
    getAttributeById(attributeId, true)->setEUI64(value);
}

// GENERATION END
