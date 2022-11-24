#pragma warning disable SYSLIB0014

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using Newtonsoft.Json.Linq;

namespace GenerateClusters;

public class Generator
{
    public void Generate()
    {
        GenerateClusters();
        GenerateReadersWriters();
    }

    public void GenerateReadersWriters()
    {
        var cw = new CodeWriter();
        var cwh = new CodeWriter();

        cw.WriteLine();
        cwh.WriteLine();
        cwh.Indent();

        var types = new List<(int Length, int NativeLength)>
        {
            (16, 16),
            (24, 32),
            (32, 32),
            (40, 64),
            (48, 64),
            (56, 64),
            (64, 64),
        };

        foreach (bool isSigned in new[] { true, false })
        {
            foreach (var type in types)
            {
                int bytes = type.Length / 8;

                string methodName = "read";
                string typeName = "";
                if (!isSigned)
                {
                    methodName += "U";
                    typeName += "u";
                }
                methodName += "Int" + type.Length;
                typeName += "int" + type.NativeLength + "_t";

                cwh.WriteLine($"{typeName} {methodName}Le();");
                cw.WriteLine($"{typeName} Memory::{methodName}Le() {{");

                cw.Indent();

                cw.Write($"const {typeName} result = ");

                for (int i = 0; i < bytes; i++)
                {
                    if (i > 0)
                        cw.Write(" | ");
                    cw.Write($"(({typeName})_data[_position + {i}] << {i * 8})");
                }

                cw.WriteLine(";");
                cw.WriteLine($"_position += {bytes};");
                cw.WriteLine("return result;");

                cw.UnIndent();
                cw.WriteLine("}");
                cw.WriteLine();

                cwh.WriteLine($"{typeName} {methodName}Be();");
                cw.WriteLine($"{typeName} Memory::{methodName}Be() {{");

                cw.Indent();

                cw.Write($"const {typeName} result = ");

                for (int i = bytes - 1; i >= 0; i--)
                {
                    cw.Write($"(({typeName})_data[_position + {bytes - i - 1}] << {i * 8})");
                    if (i > 0)
                        cw.Write(" | ");
                }

                cw.WriteLine(";");
                cw.WriteLine($"_position += {bytes};");
                cw.WriteLine("return result;");

                cw.UnIndent();
                cw.WriteLine("}");
                cw.WriteLine();
            }
        }

        foreach (bool isSigned in new[] { true, false })
        {
            foreach (var type in types)
            {
                int bytes = type.Length / 8;

                string methodName = "write";
                string typeName = "";
                if (!isSigned)
                {
                    methodName += "U";
                    typeName += "u";
                }
                methodName += "Int" + type.Length;
                typeName += "int" + type.NativeLength + "_t";

                cwh.WriteLine($"void {methodName}Le({typeName} value);");
                cw.WriteLine($"void Memory::{methodName}Le({typeName} value) {{");

                cw.Indent();

                for (int i = 0; i < bytes; i++)
                {
                    cw.WriteLine($"_data[_position + {i}] = (value >> {i * 8}) & 0xff;");
                }

                cw.WriteLine($"_position += {bytes};");

                cw.UnIndent();
                cw.WriteLine("}");
                cw.WriteLine();

                cwh.WriteLine($"void {methodName}Be({typeName} value);");
                cw.WriteLine($"void Memory::{methodName}Be({typeName} value) {{");

                cw.Indent();

                for (int i = bytes - 1; i >= 0; i--)
                {
                    cw.WriteLine($"_data[_position + {bytes - i - 1}] = (value >> {i * 8}) & 0xff;");
                }

                cw.WriteLine($"_position += {bytes};");

                cw.UnIndent();
                cw.WriteLine("}");
                cw.WriteLine();
            }
        }

        cwh.UnIndent();

        WriteFile("Memory.cpp", cw.ToString(), true);
        WriteFile("Memory.h", cwh.ToString(), true);
    }

    public void GenerateAttributeAccessors()
    {
        var cw = new CodeWriter();
        var cwh = new CodeWriter();
        cwh.Indent();

        cwh.WriteLine("String toString();");
        cw.WriteLine("String Attribute::toString() {");
        cw.Indent();
        cw.WriteLine("switch (_dataType) {");
        cw.Indent();

        foreach (var type in DataType.AllTypes)
        {
            if (type.TypeName == null || type.DataTypeName == "String16" || type.DataTypeName == "Octstr16")
                continue;

            cw.WriteLine($"case DataType::{type.DataTypeName}:");
            cw.Indent();

            switch (type.TypeName)
            {
                case "float":
                    cw.WriteLine("return String(_value.f16);");
                    break;
                case "double":
                    cw.WriteLine("return String(_value.f32);");
                    break;
                case "String":
                    cw.WriteLine("if (_dataType == DataType::String || _dataType == DataType::String16) {");
                    cw.Indent();
                    cw.WriteLine("return _value.string;");
                    cw.UnIndent();
                    cw.WriteLine("}");
                    cw.WriteLine("return \"\";");
                    break;
                case "Buffer":
                    cw.WriteLine("return \"BUFFER\";");
                    break;
                case "DateTime":
                    cw.WriteLine("return \"DATETIME\";");
                    break;
                default:
                    if (type.TypeName.StartsWith("uint"))
                        cw.WriteLine("return String((uint32_t)_value.ui64);");
                    else if (type.TypeName.StartsWith("int") || type.TypeName == "bool")
                        cw.WriteLine("return String((int32_t)_value.i64);");
                    else
                        throw new NotSupportedException();
                    break;
            }
            cw.UnIndent();
        }
        cw.WriteLine("default:");
        cw.Indent();
        cw.WriteLine("return \"NULL\";");
        cw.UnIndent();
        cw.UnIndent();
        cw.WriteLine("}");
        cw.UnIndent();
        cw.WriteLine("}");
        cw.WriteLine();

        cwh.WriteLine("void write(Memory& memory);");
        cw.WriteLine("void Attribute::write(Memory& memory) {");
        cw.Indent();
        cw.WriteLine("switch (_dataType) {");
        cw.Indent();

        foreach (var type in DataType.AllTypes)
        {
            if (type.TypeName == null || type.DataTypeName == "Semi")
                continue;

            cw.WriteLine($"case DataType::{type.DataTypeName}:");
            cw.Indent();

            switch (type.TypeName)
            {
                case "float":
                    cw.WriteLine($"memory.write{type.DataTypeName}(_value.f16);");
                    break;
                case "double":
                    cw.WriteLine($"memory.write{type.DataTypeName}(_value.f32);");
                    break;
                case "String":
                    cw.WriteLine($"memory.write{type.MemoryMethodName}(_value.string);");
                    break;
                case "Buffer":
                    cw.WriteLine($"memory.write{type.MemoryMethodName}(_value.buffer);");
                    break;
                case "DateTime":
                    cw.WriteLine("memory.writeUInt8((uint8_t)DataType::Date);");
                    cw.WriteLine("memory.writeUInt32Le(_value.dateTime.getDate());");
                    cw.WriteLine("memory.writeUInt8((uint8_t)DataType::ToD);");
                    cw.WriteLine("memory.writeUInt32Le(_value.dateTime.getTime());");
                    break;
                default:
                    if (type.TypeName.StartsWith("uint"))
                        cw.WriteLine($"memory.write{type.MemoryMethodName}(_value.ui64);");
                    else if (type.TypeName.StartsWith("int") || type.TypeName == "bool")
                        cw.WriteLine($"memory.write{type.MemoryMethodName}(_value.i64);");
                    else
                        throw new NotSupportedException();
                    break;
            }
            cw.WriteLine("break;");
            cw.UnIndent();
        }
        cw.UnIndent();
        cw.WriteLine("}");
        cw.UnIndent();
        cw.WriteLine("}");
        cw.WriteLine();

        foreach (var type in DataType.AllTypes)
        {
            if (type.TypeName == null || type.DataTypeName == "String16" || type.DataTypeName == "Octstr16")
                continue;

            cwh.WriteLine($"{type.TypeName} get{type.DataTypeName}();");
            cw.WriteLine($"{type.TypeName} Attribute::get{type.DataTypeName}() {{");
            cw.Indent();

            switch (type.TypeName)
            {
                case "float":
                    cw.WriteLine("return _value.f16;");
                    break;
                case "double":
                    cw.WriteLine("return _value.f32;");
                    break;
                case "String":
                    cw.WriteLine("if (_dataType == DataType::String || _dataType == DataType::String16) {");
                    cw.Indent();
                    cw.WriteLine("return _value.string;");
                    cw.UnIndent();
                    cw.WriteLine("}");
                    cw.WriteLine("return String();");
                    break;
                case "Buffer":
                    cw.WriteLine("if (_dataType == DataType::Octstr || _dataType == DataType::Octstr16) {");
                    cw.Indent();
                    cw.WriteLine("return _value.buffer;");
                    cw.UnIndent();
                    cw.WriteLine("}");
                    cw.WriteLine("return Buffer();");
                    break;
                case "DateTime":
                    cw.WriteLine("return _value.dateTime;");
                    break;
                default:
                    if (type.TypeName.StartsWith("uint"))
                        cw.WriteLine("return _value.ui64;");
                    else if (type.TypeName.StartsWith("int") || type.TypeName == "bool")
                        cw.WriteLine("return _value.i64;");
                    else
                        throw new NotSupportedException();
                    break;
            }

            cw.UnIndent();
            cw.WriteLine("}");
            cw.WriteLine();

            string argumentTypeName = GetArgumentTypeName(type.TypeName);

            cwh.WriteLine($"void set{type.DataTypeName}({argumentTypeName} value);");
            cw.WriteLine($"void Attribute::set{type.DataTypeName}({argumentTypeName} value) {{");
            cw.Indent();

            cw.WriteLine($"setDataType(DataType::{type.DataTypeName});");

            switch (type.TypeName)
            {
                case "float":
                    cw.WriteLine("_value.f16 = value;");
                    break;
                case "double":
                    cw.WriteLine("_value.f32 = value;");
                    break;
                case "String":
                    cw.WriteLine("_value.string = value;");
                    break;
                case "Buffer":
                    cw.WriteLine("_value.buffer = value;");
                    break;
                case "DateTime":
                    cw.WriteLine("_value.dateTime = value;");
                    break;
                default:
                    if (type.TypeName.StartsWith("uint"))
                        cw.WriteLine("_value.ui64 = value;");
                    else if (type.TypeName.StartsWith("int") || type.TypeName == "bool")
                        cw.WriteLine("_value.i64 = value;");
                    else
                        throw new NotSupportedException();
                    break;
            }

            cw.WriteLine("_unreported = true;");
            cw.UnIndent();
            cw.WriteLine("}");
            cw.WriteLine();
        }

        WriteFile("Attribute.cpp", cw.ToString(), true);
        WriteFile("Attribute.h", cwh.ToString(), true);
    }

    public void GenerateClusterAttributeAccessors()
    {
        var cw = new CodeWriter();
        var cwh = new CodeWriter();
        cwh.Indent();

        foreach (var type in DataType.AllTypes)
        {
            if (type.TypeName == null || type.DataTypeName == "String16" || type.DataTypeName == "Octstr16")
                continue;

            cwh.WriteLine($"{type.TypeName} get{type.DataTypeName}(uint16_t attributeId);");

            cw.WriteLine($"{type.TypeName} Cluster::get{type.DataTypeName}(uint16_t attributeId) {{");
            cw.Indent();
            cw.WriteLine("auto attribute = getAttributeById(attributeId);");
            cw.WriteLine("if (attribute) {");
            cw.Indent();
            cw.WriteLine($"return attribute->get{type.DataTypeName}();");
            cw.UnIndent();
            cw.WriteLine("}");
            cw.WriteLine("return {};");
            cw.UnIndent();
            cw.WriteLine("}");
            cw.WriteLine();

            string argumentTypeName = GetArgumentTypeName(type.TypeName);

            cwh.WriteLine($"void set{type.DataTypeName}(uint16_t attributeId, {argumentTypeName} value);");

            cw.WriteLine($"void Cluster::set{type.DataTypeName}(uint16_t attributeId, {argumentTypeName} value) {{");
            cw.Indent();
            cw.WriteLine($"getAttributeById(attributeId, true)->set{type.DataTypeName}(value);");
            cw.UnIndent();
            cw.WriteLine("}");
            cw.WriteLine();
        }

        WriteFile("Cluster.cpp", cw.ToString(), true);
        WriteFile("Cluster.h", cwh.ToString(), true);
    }

    public void GenerateClusters()
    {
        string content = GetData();

        int start = content.IndexOf("= {") + 2;
        int end = content.LastIndexOf("}") + 1;

        string data = content.Substring(start, end - start);
        data = Regex.Replace(data, @"(DataType|ManufacturerCode|BuffaloZclDataType)\.\w+", p => $"'{p.Value}'");
        data = Regex.Replace(data, "0b[01]+", p => BitToHex(p.Value));

        var obj = JObject.Parse(data);

        var cw = new CodeWriter();

        cw.WriteLine("#pragma once");

        foreach (var (key, _) in obj)
        {
            var cluster = (JObject)obj[key];
            if (key.StartsWith("manuSpecific") || !String.IsNullOrEmpty((string)cluster["manufacturerCode"]))
                continue;

            // Parse the commands.

            var responses = ParseCommands((JObject)cluster["commandsResponse"]).ToDictionary(p => p.Id, p => p);
            var commands = ParseCommands((JObject)cluster["commands"], responses);

            commands.RemoveAll(p =>
                p.Parameters.Any(p1 => p1.TypeName == null) || (
                    p.Response != null &&
                    p.Response.Parameters.Any(p1 => p1.TypeName == null)
                )
            );

            cw.WriteLine();

            // Class definition.

            cw.WriteLine($"class {key.ToUpperFirst()}Cluster: public Cluster {{");
            cw.WriteLine("public:");
            cw.Indent();

            // Constructor.

            cw.WriteLine($"{key.ToUpperFirst()}Cluster() : Cluster({cluster["ID"]}) {{");
            cw.WriteLine("}");

            // Attribute getters and setters.

            foreach (var (attributeName, _) in (JObject)cluster["attributes"]!)
            {
                var attribute = (JObject)cluster["attributes"][attributeName];
                if (attributeName.StartsWith("tuya") || !String.IsNullOrEmpty((string)attribute["manufacturerCode"]))
                    continue;

                var attributeType = (string)attribute["type"];

                var dataType = GetDataType(attributeType, attributeName);
                if (dataType?.TypeName == null)
                    continue;

                string argumentTypeName = GetArgumentTypeName(dataType.TypeName);
                string methodTypeName = dataType.DataTypeName;
                if (methodTypeName == "String16" || methodTypeName == "Octstr16")
                    methodTypeName = methodTypeName.Substring(0, methodTypeName.Length - 2);

                cw.WriteLine();
                cw.WriteLine($"{dataType.TypeName} get{attributeName.ToUpperFirst()}() {{");
                cw.Indent();
                cw.WriteLine($"return get{methodTypeName}({attribute["ID"]});");
                cw.UnIndent();
                cw.WriteLine("}");
                cw.WriteLine();
                cw.WriteLine($"void set{attributeName.ToUpperFirst()}({argumentTypeName} value) {{");
                cw.Indent();
                cw.WriteLine($"set{methodTypeName}({attribute["ID"]}, value);");
                cw.UnIndent();
                cw.WriteLine("}");
            }

            // Commands.

            foreach (var command in commands)
            {
                // Generate the response class, if any.

                string responseClassName = $"{command.Name.ToUpperFirst()}CommandResponse";

                if (command.Response != null)
                {
                    cw.WriteLine();
                    cw.WriteLine($"class {responseClassName} {{");
                    cw.Indent();

                    foreach (var parameter in command.Response.Parameters)
                    {
                        cw.WriteLine($"{parameter.TypeName} _{parameter.Name}{{}};");
                    }

                    cw.WriteLine();
                    cw.UnIndent();
                    cw.WriteLine("public:");
                    cw.Indent();

                    foreach (var parameter in command.Response.Parameters)
                    {
                        string argumentTypeName = GetArgumentTypeName(parameter.TypeName);

                        cw.WriteLine($"{parameter.TypeName} get{parameter.Name.ToUpperFirst()}() {{ return _{parameter.Name}; }}");
                        cw.WriteLine($"void set{parameter.Name.ToUpperFirst()}({argumentTypeName} value) {{ _{parameter.Name} = value; }}");
                        cw.WriteLine();
                    }

                    cw.UnIndent();
                    cw.WriteLine("};");
                }

                // Virtual command method.

                cw.WriteLine();
                cw.Write($"virtual Status {command.Name}Command(");

                for (var i = 0; i < command.Parameters.Count; i++)
                {
                    if (i > 0)
                        cw.Write(", ");

                    var parameter = command.Parameters[i];
                    cw.Write($"{parameter.TypeName} {parameter.Name}");
                }

                if (command.Response != null)
                {
                    if (command.Parameters.Count > 0)
                        cw.Write(", ");
                    cw.Write($"{responseClassName}& response");
                }

                cw.WriteLine(") {");
                cw.Indent();
                cw.WriteLine("return Status::UnsupportedAttribute;");
                cw.UnIndent();
                cw.WriteLine("}");
            }

            // Command parser.

            if (commands.Count > 0)
            {
                cw.WriteLine();
                cw.WriteLine("void processCommand(uint8_t commandId, Memory& request, Memory& response) override {");
                cw.Indent();

                cw.WriteLine("switch (commandId) {");
                cw.Indent();

                foreach (var command in commands)
                {
                    string responseClassName = $"{command.Name.ToUpperFirst()}CommandResponse";

                    cw.WriteLine($"case {command.Id}: {{");
                    cw.Indent();

                    foreach (var parameter in command.Parameters)
                    {
                        var type = GetDataType(parameter.DataType, parameter.Name);
                        cw.WriteLine($"auto {parameter.Name} = request.read{type.MemoryMethodName}();");
                    }

                    if (command.Response != null)
                    {
                        cw.WriteLine($"{responseClassName} response_;");
                    }

                    cw.Write($"auto status_ = {command.Name}Command(");

                    for (var i = 0; i < command.Parameters.Count; i++)
                    {
                        if (i > 0)
                            cw.Write(", ");
                        cw.Write(command.Parameters[i].Name);
                    }

                    if (command.Response != null)
                    {
                        if (command.Parameters.Count > 0)
                            cw.Write(", ");
                        cw.Write("response_");
                    }

                    cw.WriteLine(");");

                    cw.WriteLine("response.writeUInt8((uint8_t)status_);");

                    if (command.Response != null)
                    {
                        cw.WriteLine("if (status_ == Status::Success) {");
                        cw.Indent();

                        foreach (var parameter in command.Response.Parameters)
                        {
                            var type = GetDataType(parameter.DataType, parameter.Name);
                            cw.WriteLine($"response.write{type.MemoryMethodName}(response_.get{parameter.Name.ToUpperFirst()}());");
                        }

                        cw.UnIndent();
                        cw.WriteLine("}");
                    }

                    cw.WriteLine("return;");

                    cw.UnIndent();
                    cw.WriteLine("}");
                }

                cw.WriteLine("default:");
                cw.Indent();
                cw.WriteLine("Cluster::processCommand(commandId, request, response);");
                cw.WriteLine("return;");
                cw.UnIndent();

                cw.UnIndent();
                cw.WriteLine("}");

                cw.UnIndent();
                cw.WriteLine("}");
            }

            cw.UnIndent();
            cw.WriteLine("};");
        }

        WriteFile("Clusters.h", cw.ToString());
    }

    private List<Command> ParseCommands(JObject obj, Dictionary<int, Command> responses = null)
    {
        var commands = new List<Command>();

        foreach (var (commandName, _) in obj)
        {
            if (commandName.StartsWith("tuya"))
                continue;

            var command = (JObject)obj[commandName];
            var parameters = (JArray)command["parameters"];

            Command response = null;

            if (responses != null)
            {
                int? responseId = (int?)command["response"];
                if (responseId.HasValue)
                    response = responses[responseId.Value];
            }

            var parsed = new Command((int)command["ID"], commandName, response);
            commands.Add(parsed);

            parsed.Parameters.AddRange(parameters.Select(p =>
                ((string)p["type"], GetDataType((string)p["type"], (string)p["name"]).TypeName, (string)p["name"])
            ));
        }

        return commands;
    }

    private string GetArgumentTypeName(string typeName)
    {
        if (Char.IsUpper(typeName[0]))
            return $"const {typeName}&";
        return typeName;
    }

    private void WriteFile(string fileName, string code, bool rewrite = false)
    {
        string target = Path.Combine(Path.GetDirectoryName(GetType().Assembly.Location), "..", "..", "..", "..", "..", "..", fileName);

        if (rewrite)
        {
            string source = File.ReadAllText(target);

            code = Regex.Replace(
                source,
                "(// GENERATION START\r?\n)(.*)(// GENERATION END)",
                p => $"{p.Groups[1].Value}{code}{p.Groups[3].Value}",
                RegexOptions.Singleline
            );
        }

        File.WriteAllText(target, code);
    }

    private static string GetData()
    {
#if DEBUG
        string cacheFileName = "cache";
        if (File.Exists(cacheFileName))
            return File.ReadAllText(cacheFileName);
#endif

        string data = new WebClient().DownloadString("https://raw.githubusercontent.com/Koenkk/zigbee-herdsman/master/src/zcl/definition/cluster.ts");

#if DEBUG
        File.WriteAllText(cacheFileName, data);
#endif

        return data;
    }

    private string BitToHex(string value)
    {
        int parsed = 0;

        foreach (char c in value.Skip(2))
        {
            parsed <<= 1;
            if (c == '1')
                parsed += 1;
        }

        return $"0x{parsed:x}";
    }

    private DataType GetDataType(string type, string name)
    {
        if (
            type == "DataType.struct" &&
            name is "changeOfStateTime" or "timeOfATReset" or "timeOfSCReset"
        )
            return DataType.GetByHerdsmanName("DateTime");

        return DataType.GetByHerdsmanName(type);
    }
}
