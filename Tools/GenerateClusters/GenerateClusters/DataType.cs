using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenerateClusters;

public class DataType
{
    public static readonly IList<DataType> AllTypes = new ReadOnlyCollection<DataType>(new[]
    {
        new DataType("nodata", "NoData", 0x00, 0, null, "DataType.noData"),
        new DataType("data8", "Data8", 0x08, 1, "uint8_t", "DataType.data8"),
        new DataType("data16", "Data16", 0x09, 2, "uint16_t", "DataType.data16"),
        new DataType("data24", "Data24", 0x0a, 3, "uint32_t", "DataType.data24"),
        new DataType("data32", "Data32", 0x0b, 4, "uint32_t", "DataType.data32"),
        new DataType("data40", "Data40", 0x0c, 5, "uint64_t", "DataType.data40"),
        new DataType("data48", "Data48", 0x0d, 6, "uint64_t", "DataType.data48"),
        new DataType("data56", "Data56", 0x0e, 7, "uint64_t", "DataType.data56"),
        new DataType("data64", "Data64", 0x0f, 8, "uint64_t", "DataType.data64"),
        new DataType("bool", "Bool", 0x10, 1, "bool", "DataType.boolean"),
        new DataType("map8", "Map8", 0x18, 1, "uint8_t", "DataType.bitmap8"),
        new DataType("map16", "Map16", 0x19, 2, "uint16_t", "DataType.bitmap16"),
        new DataType("map24", "Map24", 0x1a, 3, "uint32_t", "DataType.bitmap24"),
        new DataType("map32", "Map32", 0x1b, 4, "uint32_t", "DataType.bitmap32"),
        new DataType("map40", "Map40", 0x1c, 5, "uint64_t", "DataType.bitmap40"),
        new DataType("map48", "Map48", 0x1d, 6, "uint64_t", "DataType.bitmap48"),
        new DataType("map56", "Map56", 0x1e, 7, "uint64_t", "DataType.bitmap56"),
        new DataType("map64", "Map64", 0x1f, 8, "uint64_t", "DataType.bitmap64"),
        new DataType("uint8", "UInt8", 0x20, 1, "uint8_t", "DataType.uint8"),
        new DataType("uint16", "UInt16", 0x21, 2, "uint16_t", "DataType.uint16"),
        new DataType("uint24", "UInt24", 0x22, 3, "uint32_t", "DataType.uint24"),
        new DataType("uint32", "UInt32", 0x23, 4, "uint32_t", "DataType.uint32"),
        new DataType("uint40", "UInt40", 0x24, 5, "uint64_t", "DataType.uint40"),
        new DataType("uint48", "UInt48", 0x25, 6, "uint64_t", "DataType.uint48"),
        new DataType("uint56", "UInt56", 0x26, 7, "uint64_t", "DataType.uint56"),
        new DataType("uint64", "UInt64", 0x27, 8, "uint64_t", "DataType.uint64"),
        new DataType("int8", "Int8", 0x28, 1, "int8_t", "DataType.int8"),
        new DataType("int16", "Int16", 0x29, 2, "int16_t", "DataType.int16"),
        new DataType("int24", "Int24", 0x2a, 3, "int32_t", "DataType.int24"),
        new DataType("int32", "Int32", 0x2b, 4, "int32_t", "DataType.int32"),
        new DataType("int40", "Int40", 0x2c, 5, "int64_t", "DataType.int40"),
        new DataType("int48", "Int48", 0x2d, 6, "int64_t", "DataType.int48"),
        new DataType("int56", "Int56", 0x2e, 7, "int64_t", "DataType.int56"),
        new DataType("int64", "Int64", 0x2f, 8, "int64_t", "DataType.int64"),
        new DataType("enum8", "Enum8", 0x30, 1, "uint8_t", "DataType.enum8"),
        new DataType("enum16", "Enum16", 0x31, 2, "uint16_t", "DataType.enum16"),
        new DataType("semi", "Semi", 0x38, 2, "float", "DataType.semiPrec"),
        new DataType("single", "Single", 0x39, 4, "float", "DataType.singlePrec"),
        new DataType("double", "Double", 0x3a, 8, "double", "DataType.doublePrec"),
        new DataType("octstr", "Octstr", 0x41, -1, "Buffer", "DataType.octetStr"),
        new DataType("string", "String", 0x42, -1, "String", "DataType.charStr"),
        new DataType("octstr16", "Octstr16", 0x43, -1, "Buffer", "DataType.longOctetStr"),
        new DataType("string16", "String16", 0x44, -1, "String", "DataType.longCharStr"),
        //new DataType("struct", "Struct", 0x4c, -1, "Struct", "DataType.struct"),
        new DataType("DateTime", "DateTime", 0x4c, -1, "DateTime", "DateTime"),
        new DataType("ToD", "ToD", 0xe0, 4, "uint32_t", "DataType.tod"),
        new DataType("date", "Date", 0xe1, 4, "uint32_t", "DataType.date"),
        new DataType("UTC", "UTC", 0xe2, 4, "uint32_t", "DataType.utc"),
        new DataType("clusterId", "ClusterId", 0xe8, 2, "uint16_t", "DataType.clusterId"),
        new DataType("attribId", "AttribId", 0xe9, 2, "uint16_t", "DataType.attrId"),
        new DataType("bacOID", "BacOID", 0xea, 4, "uint32_t", "DataType.bacOid"),
        new DataType("EUI64", "EUI64", 0xf0, 8, "uint64_t", "DataType.ieeeAddr"),
        new DataType("key128", "Key128", 0xf1, 16, null, "DataType.secKey"),
        new DataType("unk", "Unk", 0xff, 0, null, "DataType.unknown"),

        new DataType("array", "Array", 0x48, -1, null, "DataType.array"),
        new DataType("set", "Set", 0x50, -1, null, "DataType.set"),
        new DataType("bag", "Bag", 0x51, -1, null, "DataType.bag"),

        new DataType("USE_DATA_TYPE", "USE_DATA_TYPE", 1000, -1, null, "BuffaloZclDataType.USE_DATA_TYPE"),
        new DataType("LIST_UINT8", "LIST_UINT8", 1001, -1, null, "BuffaloZclDataType.LIST_UINT8"),
        new DataType("LIST_UINT16", "LIST_UINT16", 1002, -1, null, "BuffaloZclDataType.LIST_UINT16"),
        new DataType("LIST_UINT24", "LIST_UINT24", 1003, -1, null, "BuffaloZclDataType.LIST_UINT24"),
        new DataType("LIST_UINT32", "LIST_UINT32", 1004, -1, null, "BuffaloZclDataType.LIST_UINT32"),
        new DataType("LIST_ZONEINFO", "LIST_ZONEINFO", 1005, -1, null, "BuffaloZclDataType.LIST_ZONEINFO"),
        new DataType("EXTENSION_FIELD_SETS", "EXTENSION_FIELD_SETS", 1006, -1, null, "BuffaloZclDataType.EXTENSION_FIELD_SETS"),
        new DataType("LIST_THERMO_TRANSITIONS", "LIST_THERMO_TRANSITIONS", 1007, -1, null, "BuffaloZclDataType.LIST_THERMO_TRANSITIONS"),
        new DataType("BUFFER", "BUFFER", 1008, -1, null, "BuffaloZclDataType.BUFFER"),
        new DataType("GDP_FRAME", "GDP_FRAME", 1009, -1, null, "BuffaloZclDataType.GDP_FRAME"),
        new DataType("STRUCTURED_SELECTOR", "STRUCTURED_SELECTOR", 1010, -1, null, "BuffaloZclDataType.STRUCTURED_SELECTOR"),
        new DataType("LIST_TUYA_DATAPOINT_VALUES", "LIST_TUYA_DATAPOINT_VALUES", 1011, -1, null, "BuffaloZclDataType.LIST_TUYA_DATAPOINT_VALUES"),
        new DataType("LIST_MIBOXER_ZONES", "LIST_MIBOXER_ZONES", 1012, -1, null, "BuffaloZclDataType.LIST_MIBOXER_ZONES"),

    });

    private static readonly Dictionary<string, DataType> byHerdsmanName = AllTypes.ToDictionary(p => p.HerdsmanName, p => p, StringComparer.OrdinalIgnoreCase);

    public static DataType GetByHerdsmanName(string name)
    {
        byHerdsmanName.TryGetValue(name, out var result);
        return result;
    }

    public string SpecName { get; }
    public string DataTypeName { get; }
    public int Id { get; }
    public int Length { get; }
    public string TypeName { get; }
    public string HerdsmanName { get; }
    public string MemoryMethodName { get; }

    public DataType(string specName, string dataTypeName, int id, int length, string typeName, string herdsmanName)
    {
        SpecName = specName;
        DataTypeName = dataTypeName;
        Id = id;
        Length = length;
        TypeName = typeName;
        HerdsmanName = herdsmanName;

        if (TypeName == null)
        {
            MemoryMethodName = null;
        }
        else if (DataTypeName == "String16" || DataTypeName == "Octstr16")
        {
            MemoryMethodName = DataTypeName + "Le";
        }
        else if (TypeName.StartsWith("int"))
        {
            MemoryMethodName = "Int" + (Length * 8);
            if (Length > 1)
                MemoryMethodName += "Le";
        }
        else if (TypeName.StartsWith("uint"))
        {
            MemoryMethodName = "UInt" + (Length * 8);
            if (Length > 1)
                MemoryMethodName += "Le";
        }
        else if (TypeName == "bool")
        {
            MemoryMethodName = "UInt8";
        }
        else
        {
            MemoryMethodName = DataTypeName;
        }
    }
}
