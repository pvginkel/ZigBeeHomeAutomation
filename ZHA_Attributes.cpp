#include "ZHA_Attributes.h"
#include "ZHA_Utils.h"
#include "Printers.h"
#include "ZHA_Devices.h"

ZHA_Attribute::ZHA_Attribute(uint16_t attrId, uint8_t dataType, uint64_t value) {
    _attrId = attrId;
    _datatype = dataType;
    _value = value;
    _reporting = false;
    _unreported = false;
};

ZHA_Attribute::ZHA_Attribute(uint16_t attrId, uint8_t dataType, String value) {
    _attrId = attrId;
    _datatype = dataType;
    _strValue = String(value);
    _reporting = false;
    _unreported = false;
};

uint16_t ZHA_Attribute::getAttrId() {
    return _attrId;
}

uint16_t ZHA_Attribute::getAttrSize() {
    /* if copyPayload is passed a NULL pointer, it simply returns the size */
    return copyPayload(NULL);
}

uint16_t ZHA_Attribute::copyPayload(uint8_t *payload) {
    switch (_datatype) {
        case ZHA_TYPE_NULL:
            return 0;
        case ZHA_TYPE_GENERALDATA8:
        case ZHA_TYPE_BOOL:
        case ZHA_TYPE_BITMAP8:
        case ZHA_TYPE_UINT8:
        case ZHA_TYPE_INT8:
        case ZHA_TYPE_ENUMERATION8:
            if (payload)
                payload[0] = (uint8_t) _value;
            return 1;
        case ZHA_TYPE_GENERALDATA16:
        case ZHA_TYPE_BITMAP16:
        case ZHA_TYPE_UINT16:
        case ZHA_TYPE_INT16:
        case ZHA_TYPE_ENUMERATION16:
        case ZHA_TYPE_FLOAT_SEMI:
            if (payload)
                unpackArrayLe(payload, (uint16_t) _value);
            return 2;
        case ZHA_TYPE_GENERALDATA24:
        case ZHA_TYPE_BITMAP24:
        case ZHA_TYPE_UINT24:
        case ZHA_TYPE_INT24:
            return 3;
        case ZHA_TYPE_GENERALDATA32:
        case ZHA_TYPE_BITMAP32:
        case ZHA_TYPE_UINT32:
        case ZHA_TYPE_INT32:
        case ZHA_TYPE_FLOAT_SINGLE:
            return 4;
        case ZHA_TYPE_GENERALDATA40:
        case ZHA_TYPE_BITMAP40:
        case ZHA_TYPE_UINT40:
        case ZHA_TYPE_INT40:
            return 5;
        case ZHA_TYPE_GENERALDATA48:
        case ZHA_TYPE_BITMAP48:
        case ZHA_TYPE_UINT48:
        case ZHA_TYPE_INT48:
            return 6;
        case ZHA_TYPE_GENERALDATA56:
        case ZHA_TYPE_BITMAP56:
        case ZHA_TYPE_UINT56:
        case ZHA_TYPE_INT56:
            return 7;
        case ZHA_TYPE_GENERALDATA64:
        case ZHA_TYPE_BITMAP64:
        case ZHA_TYPE_UINT64:
        case ZHA_TYPE_INT64:
        case ZHA_TYPE_FLOAT_DOUBLE:
            return 8;
        case ZHA_TYPE_OCTET_STRING:
        case ZHA_TYPE_CHAR_STRING:
            /* payload is length/size of value (1 byte), followed by value */
            if (payload) {
                payload[0] = (uint8_t) _strValue.length();
                _strValue.getBytes((byte * ) & payload[1], _strValue.length() + 1);
            }
            return _strValue.length() + 1;
        case ZHA_TYPE_LONG_OCTET_STRING:
        case ZHA_TYPE_LONG_CHAR_STRING:
            /* payload is length/size of value (2 bytes), followed by value */
            if (payload) {
                unpackArrayLe(&payload[0], (uint16_t) _strValue.length());
                _strValue.getBytes((byte * ) & payload[2], _strValue.length() + 1);
            }
            return _strValue.length() + 2;
        default:
            return 0;
    }
}

uint8_t ZHA_Attribute::getValueUINT8() {
    return (uint8_t) _value;
}

bool ZHA_Attribute::getValueBool() {
    return (bool) _value;
}

uint8_t ZHA_Attribute::getAttrType() {
    return _datatype;
}

bool ZHA_Attribute::isReporting() {
    return _reporting;
}

bool ZHA_Attribute::isUnreported() {
    return _unreported;
}

void ZHA_Attribute::markReported() {
    _unreported = false;
}

void ZHA_Attribute::set(uint64_t value) {
    _value = value;
    _unreported = true;
}

void ZHA_Attribute::set(String value) {
    _strValue = value;
    _unreported = true;
}

String ZHA_Attribute::toString() {
    switch (_datatype) {
        case ZHA_TYPE_NULL:
            return String("NULL");
        case ZHA_TYPE_BOOL:
        case ZHA_TYPE_UINT8:
        case ZHA_TYPE_ENUMERATION8:
        case ZHA_TYPE_BITMAP8:
            /* for simple types, size is known, payload is just value */
            return (String)((uint8_t) _value);
        case ZHA_TYPE_UINT16:
            return (String)((uint16_t) _value);
        case ZHA_TYPE_CHAR_STRING:
            /* payload is length/size of value, followed by value */
            return _strValue;
        default:
            return String("Attribute type not implemented yet.");
    }
}

uint8_t ZHA_Attribute::configureReporting(Zcl::DataType datatype, uint16_t minimumInterval, uint16_t maximumInterval,
                                          uint8_t reportableChange, uint16_t timeoutPeriod) {
    _lastReported = 0;
    _minimumReportingInterval = minimumInterval;
    _maximumReportingInterval = maximumInterval;
    _reportableChange = reportableChange;
    _timeoutPeriod = timeoutPeriod;
    _reporting = true;
}

void ZHA_Attribute::writeValue(Zcl::FrameAppender& frame) {
    switch (_datatype) {
    case ZHA_TYPE_GENERALDATA8:
    case ZHA_TYPE_BOOL:
    case ZHA_TYPE_BITMAP8:
    case ZHA_TYPE_UINT8:
    case ZHA_TYPE_INT8:
    case ZHA_TYPE_ENUMERATION8:
        frame.appendValue((uint8_t)_value);
        break;
    case ZHA_TYPE_GENERALDATA16:
    case ZHA_TYPE_BITMAP16:
    case ZHA_TYPE_UINT16:
    case ZHA_TYPE_INT16:
    case ZHA_TYPE_ENUMERATION16:
    case ZHA_TYPE_FLOAT_SEMI:
        frame.appendValueLe((uint16_t)_value);
        break;
    case ZHA_TYPE_OCTET_STRING:
    case ZHA_TYPE_CHAR_STRING:
        frame.appendShortString(_strValue);
        break;
    case ZHA_TYPE_LONG_OCTET_STRING:
    case ZHA_TYPE_LONG_CHAR_STRING:
        frame.appendLongString(_strValue);
        break;
    }
}

Zcl::DataType ZHA_Attribute::dataType() {
    return (Zcl::DataType)getAttrType();
}
