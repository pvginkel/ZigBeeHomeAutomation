#include "ZigBeeHomeAutomation.h"

// GENERATION START
bool skipValue(Memory& memory, DataType dataType) {
    switch (dataType) {
    case DataType::Data8:
    case DataType::Bool:
    case DataType::Map8:
    case DataType::UInt8:
    case DataType::Int8:
    case DataType::Enum8:
        memory.setPosition(memory.getPosition() + 1);
        return true;
    case DataType::Data16:
    case DataType::Map16:
    case DataType::UInt16:
    case DataType::Int16:
    case DataType::Enum16:
    case DataType::ClusterId:
    case DataType::AttribId:
        memory.setPosition(memory.getPosition() + 2);
        return true;
    case DataType::Data24:
    case DataType::Map24:
    case DataType::UInt24:
    case DataType::Int24:
        memory.setPosition(memory.getPosition() + 3);
        return true;
    case DataType::Data32:
    case DataType::Map32:
    case DataType::UInt32:
    case DataType::Int32:
    case DataType::Single:
    case DataType::ToD:
    case DataType::Date:
    case DataType::UTC:
    case DataType::BacOID:
        memory.setPosition(memory.getPosition() + 4);
        return true;
    case DataType::Data40:
    case DataType::Map40:
    case DataType::UInt40:
    case DataType::Int40:
        memory.setPosition(memory.getPosition() + 5);
        return true;
    case DataType::Data48:
    case DataType::Map48:
    case DataType::UInt48:
    case DataType::Int48:
        memory.setPosition(memory.getPosition() + 6);
        return true;
    case DataType::Data56:
    case DataType::Map56:
    case DataType::UInt56:
    case DataType::Int56:
        memory.setPosition(memory.getPosition() + 7);
        return true;
    case DataType::Data64:
    case DataType::Map64:
    case DataType::UInt64:
    case DataType::Int64:
    case DataType::Double:
    case DataType::EUI64:
        memory.setPosition(memory.getPosition() + 8);
        return true;
    case DataType::NoData:
        return true;
    case DataType::DateTime:
        memory.setPosition(memory.getPosition() + 10);
        return true;
    case DataType::String:
    case DataType::Octstr:
        memory.setPosition(memory.getPosition() + memory.readUInt8());
        return true;
    case DataType::String16:
    case DataType::Octstr16:
        memory.setPosition(memory.getPosition() + memory.readUInt16Le());
        return true;
    default:
        return false;
    }
}
// GENERATION END
