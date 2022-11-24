#include "DataType.h"

int getDataTypeLength(DataType dataType) {
	switch (dataType) {
	case DataType::NoData: return 0;
	case DataType::Data8: return 1;
	case DataType::Data16: return 2;
	case DataType::Data24: return 3;
	case DataType::Data32: return 4;
	case DataType::Data40: return 5;
	case DataType::Data48: return 6;
	case DataType::Data56: return 7;
	case DataType::Data64: return 8;
	case DataType::Bool: return 1;
	case DataType::Map8: return 1;
	case DataType::Map16: return 2;
	case DataType::Map24: return 3;
	case DataType::Map32: return 4;
	case DataType::Map40: return 5;
	case DataType::Map48: return 6;
	case DataType::Map56: return 7;
	case DataType::Map64: return 8;
	case DataType::UInt8: return 1;
	case DataType::UInt16: return 2;
	case DataType::UInt24: return 3;
	case DataType::UInt32: return 4;
	case DataType::UInt40: return 5;
	case DataType::UInt48: return 6;
	case DataType::UInt56: return 7;
	case DataType::UInt64: return 8;
	case DataType::Int8: return 1;
	case DataType::Int16: return 2;
	case DataType::Int24: return 3;
	case DataType::Int32: return 4;
	case DataType::Int40: return 5;
	case DataType::Int48: return 6;
	case DataType::Int56: return 7;
	case DataType::Int64: return 8;
	case DataType::Enum8: return 1;
	case DataType::Enum16: return 2;
	case DataType::Semi: return 2;
	case DataType::Single: return 4;
	case DataType::Double: return 8;
	case DataType::Octstr: return -1;
	case DataType::String: return -1;
	case DataType::Octstr16: return -1;
	case DataType::String16: return -1;
	case DataType::Array: return -1;
	case DataType::Struct: return -1;
	case DataType::Set: return -1;
	case DataType::Bag: return -1;
	case DataType::ToD: return 4;
	case DataType::Date: return 4;
	case DataType::UTC: return 4;
	case DataType::ClusterId: return 2;
	case DataType::AttribId: return 2;
	case DataType::BacOID: return 4;
	case DataType::EUI64: return 8;
	case DataType::Key128: return 16;
	case DataType::Unk: return 0;
	}
	return -1;
}
