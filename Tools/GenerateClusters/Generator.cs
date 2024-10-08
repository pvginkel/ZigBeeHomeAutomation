﻿#pragma warning disable SYSLIB0014

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.WebSockets;
using System.Security.Claims;
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
                    cw.WriteLine(
                        $"_data[_position + {bytes - i - 1}] = (value >> {i * 8}) & 0xff;"
                    );
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

    public void GenerateAttributes()
    {
        var cwh = new CodeWriter();
        var seen = new HashSet<string>();

        foreach (var type in DataType.AllTypes)
        {
            if (
                type.TypeName == null
                || type.DataTypeName == "String16"
                || type.DataTypeName == "String"
                || type.DataTypeName == "Octstr16"
                || type.DataTypeName == "Octstr"
                || type.DataTypeName == "Semi"
            )
                continue;
            if (!seen.Add(type.MemoryMethodName))
                continue;

            cwh.WriteLine($"class Attribute{type.MemoryMethodName}: public Attribute {{");

            cwh.Indent();
            cwh.WriteLine($"{type.TypeName} _value{{}};");
            cwh.UnIndent();
            cwh.WriteLine();

            cwh.WriteLine("public:");
            cwh.Indent();

            cwh.WriteLine(
                $"Attribute{type.MemoryMethodName}(uint16_t attributeId, DataType dataType) : Attribute(attributeId, dataType) {{"
            );
            cwh.WriteLine("}");
            cwh.WriteLine();

            cwh.WriteLine($"{type.TypeName} getValue() {{ return _value; }}");
            cwh.WriteLine();
            cwh.WriteLine($"void setValue({type.TypeName} value) {{");
            cwh.Indent();
            cwh.WriteLine("if (_value != value) {");
            cwh.Indent();
            cwh.WriteLine("_value = value;");
            cwh.WriteLine("markDirty();");
            cwh.UnIndent();
            cwh.WriteLine("}");
            cwh.UnIndent();
            cwh.WriteLine("}");
            cwh.WriteLine();

            cwh.WriteLine("String toString() override {");
            cwh.Indent();

            switch (type.TypeName)
            {
                case "float":
                    cwh.WriteLine("return String(_value);");
                    break;
                case "double":
                    cwh.WriteLine("return String(_value);");
                    break;
                case "String":
                    cwh.WriteLine("return _value;");
                    break;
                case "Buffer":
                    cwh.WriteLine("return F(\"BUFFER\");");
                    break;
                case "DateTime":
                    cwh.WriteLine("return F(\"DATETIME\");");
                    break;
                default:
                    if (type.TypeName.StartsWith("uint"))
                        cwh.WriteLine("return String((uint32_t)_value);");
                    else if (type.TypeName.StartsWith("int") || type.TypeName == "bool")
                        cwh.WriteLine("return String((int32_t)_value);");
                    else
                        throw new NotSupportedException();
                    break;
            }

            cwh.UnIndent();
            cwh.WriteLine("}");
            cwh.WriteLine();

            cwh.WriteLine("void readValue(Memory& memory) override {");
            cwh.Indent();

            switch (type.EndianMemoryMethodName)
            {
                case "DateTime":
                    cwh.WriteLine("// Has the date data type.");
                    cwh.WriteLine("memory.readUInt8();");
                    cwh.WriteLine("auto date = memory.readUInt32Le();");
                    cwh.WriteLine("// Has the time of day data type.");
                    cwh.WriteLine("memory.readUInt8();");
                    cwh.WriteLine("auto time = memory.readUInt32Le();");
                    cwh.WriteLine("_value = DateTime(date, time);");
                    break;
                case "Octstr":
                    cwh.WriteLine("if (dataType == DataType::Octstr16) {");
                    cwh.Indent();
                    cwh.WriteLine("_value = memory.readOctstr16Le();");
                    cwh.UnIndent();
                    cwh.WriteLine("}");
                    cwh.WriteLine("else {");
                    cwh.Indent();
                    cwh.WriteLine("_value = memory.readOctstr();");
                    cwh.UnIndent();
                    cwh.WriteLine("}");
                    break;
                default:
                    cwh.WriteLine($"_value = memory.read{type.EndianMemoryMethodName}();");
                    break;
            }

            cwh.UnIndent();
            cwh.WriteLine("}");

            cwh.WriteLine();
            cwh.WriteLine("void writeValue(Memory& memory) override {");
            cwh.Indent();

            switch (type.EndianMemoryMethodName)
            {
                case "DateTime":
                    cwh.WriteLine("memory.writeUInt8((uint8_t)DataType::Date);");
                    cwh.WriteLine("memory.writeUInt32Le(_value.getDate());");
                    cwh.WriteLine("memory.writeUInt8((uint8_t)DataType::ToD);");
                    cwh.WriteLine("memory.writeUInt32Le(_value.getTime());");
                    break;
                case "Octstr":
                    cwh.WriteLine("memory.writeOctstr16Le(_value);");
                    break;
                default:
                    cwh.WriteLine($"memory.write{type.EndianMemoryMethodName}(_value);");
                    break;
            }

            cwh.UnIndent();
            cwh.WriteLine("}");

            cwh.UnIndent();
            cwh.WriteLine("};");
            cwh.WriteLine();
        }

        WriteFile("Attribute.h", cwh.ToString(), true);
    }

    public void GenerateDataType()
    {
        var cw = new CodeWriter();

        cw.WriteLine("bool skipValue(Memory& memory, DataType dataType) {");

        cw.Indent();
        cw.WriteLine("switch (dataType) {");

        foreach (
            var typeGroup in DataType
                .AllTypes.Where(p =>
                    p.Length != -1 && p.TypeName != null && p.DataTypeName != "Semi"
                )
                .GroupBy(p => p.Length)
        )
        {
            foreach (var type in typeGroup)
            {
                cw.WriteLine($"case DataType::{type.DataTypeName}:");
            }

            cw.Indent();
            cw.WriteLine($"memory.setPosition(memory.getPosition() + {typeGroup.Key});");
            cw.WriteLine("return true;");
            cw.UnIndent();
        }

        cw.WriteLine("case DataType::NoData:");
        cw.Indent();
        cw.WriteLine("return true;");
        cw.UnIndent();

        cw.WriteLine("case DataType::DateTime:");
        cw.Indent();
        cw.WriteLine($"memory.setPosition(memory.getPosition() + 10);");
        cw.WriteLine("return true;");
        cw.UnIndent();

        cw.WriteLine("case DataType::String:");
        cw.WriteLine("case DataType::Octstr:");
        cw.Indent();
        cw.WriteLine($"memory.setPosition(memory.getPosition() + memory.readUInt8());");
        cw.WriteLine("return true;");
        cw.UnIndent();

        cw.WriteLine("case DataType::String16:");
        cw.WriteLine("case DataType::Octstr16:");
        cw.Indent();
        cw.WriteLine($"memory.setPosition(memory.getPosition() + memory.readUInt16Le());");
        cw.WriteLine("return true;");
        cw.UnIndent();

        cw.WriteLine("default:");
        cw.Indent();
        cw.WriteLine("return false;");
        cw.UnIndent();

        cw.WriteLine("}");
        cw.UnIndent();

        cw.WriteLine("}");

        WriteFile("DataType.cpp", cw.ToString(), true);
    }

    public void GenerateClusters()
    {
        string content = GetData();

        int start = content.IndexOf("= {") + 2;
        int end = content.LastIndexOf("}") + 1;

        string data = content.Substring(start, end - start);
        data = Regex.Replace(
            data,
            @"(DataType|ManufacturerCode|BuffaloZclDataType)\.\w+",
            p => $"'{p.Value}'"
        );
        data = Regex.Replace(data, "0b[01]+", p => BitToHex(p.Value));

        var obj = JObject.Parse(data);

        var cwh = new CodeWriter();
        var cw = new CodeWriter();

        cwh.WriteLine("#pragma once");

        cw.WriteLine("#include \"ZigBeeHomeAutomation.h\"");

        cw.WriteLine();
        cw.WriteLine("// Zigbee2mqtt deduplicates commands based on the transaction id.");
        cw.WriteLine("// We generate this transaction ID using the field below. Every time");
        cw.WriteLine("// we send out a command, we bump this value by one.");
        cw.WriteLine("static uint8_t nextTransactionSequenceNumber = 0;");

        foreach (var (key, _) in obj)
        {
            var cluster = (JObject)obj[key];
            if (
                key.StartsWith("manuSpecific")
                || !String.IsNullOrEmpty((string)cluster["manufacturerCode"])
            )
                continue;

            // Parse the commands.

            var responses = ParseCommands((JObject)cluster["commandsResponse"])
                .ToDictionary(p => p.Id, p => p);
            var commands = ParseCommands((JObject)cluster["commands"], responses);

            commands.RemoveAll(p =>
                p.Parameters.Any(p1 => p1.TypeName == null)
                || (p.Response != null && p.Response.Parameters.Any(p1 => p1.TypeName == null))
            );

            cwh.WriteLine();

            // Attribute enum definition.

            cwh.WriteLine($"enum class {key.ToUpperFirst()}Attribute: uint16_t {{");
            cwh.Indent();

            foreach (var (attributeName, _) in (JObject)cluster["attributes"]!)
            {
                var attribute = (JObject)cluster["attributes"][attributeName];
                cwh.WriteLine($"{attributeName.ToUpperFirst()} = {attribute["ID"]},");
            }

            cwh.UnIndent();
            cwh.WriteLine("};");
            cwh.WriteLine();

            // Class definition.

            cwh.WriteLine($"class {key.ToUpperFirst()}Cluster: public Cluster {{");
            cwh.WriteLine("public:");
            cwh.Indent();

            // Constructor.

            cwh.WriteLine(
                $"{key.ToUpperFirst()}Cluster(ClusterType type = ClusterType::Input) : Cluster({cluster["ID"]}, type) {{"
            );
            cwh.WriteLine("}");

            // Attribute getters and setters.

            foreach (var (attributeName, _) in (JObject)cluster["attributes"]!)
            {
                var attribute = (JObject)cluster["attributes"][attributeName];
                if (
                    attributeName.StartsWith("tuya")
                    || !String.IsNullOrEmpty((string)attribute["manufacturerCode"])
                )
                    continue;

                var attributeType = (string)attribute["type"];

                var type = GetDataType(attributeType, attributeName);
                if (type?.TypeName == null)
                    continue;

                cwh.WriteLine(
                    $"Attribute{type.MemoryMethodName}* get{attributeName.ToUpperFirst()}();"
                );

                cw.WriteLine();
                cw.WriteLine(
                    $"Attribute{type.MemoryMethodName}* {key.ToUpperFirst()}Cluster::get{attributeName.ToUpperFirst()}() {{"
                );
                cw.Indent();
                cw.WriteLine(
                    $"auto result = (Attribute{type.MemoryMethodName}*)getAttributeById((uint16_t){key.ToUpperFirst()}Attribute::{attributeName.ToUpperFirst()});"
                );
                cw.WriteLine("if (result == nullptr) {");
                cw.Indent();
                if (type.DataTypeName == "String" || type.DataTypeName == "Octstr")
                    cw.WriteLine(
                        $"result = new Attribute{type.MemoryMethodName}({attribute["ID"]});"
                    );
                else
                    cw.WriteLine(
                        $"result = new Attribute{type.MemoryMethodName}({attribute["ID"]}, DataType::{type.DataTypeName});"
                    );
                cw.WriteLine("addAttribute(result);");
                cw.UnIndent();
                cw.WriteLine("}");
                cw.WriteLine("return result;");
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
                    cwh.WriteLine();
                    cwh.WriteLine($"class {responseClassName} {{");
                    cwh.Indent();

                    foreach (var parameter in command.Response.Parameters)
                    {
                        cwh.WriteLine($"{parameter.TypeName} _{parameter.Name}{{}};");
                    }

                    cwh.WriteLine();
                    cwh.UnIndent();
                    cwh.WriteLine("public:");
                    cwh.Indent();

                    foreach (var parameter in command.Response.Parameters)
                    {
                        string argumentTypeName = GetArgumentTypeName(parameter.TypeName);

                        cwh.WriteLine(
                            $"{parameter.TypeName} get{parameter.Name.ToUpperFirst()}() {{ return _{parameter.Name}; }}"
                        );
                        cwh.WriteLine(
                            $"void set{parameter.Name.ToUpperFirst()}({argumentTypeName} {parameter.Name}) {{ _{parameter.Name} = {parameter.Name}; }}"
                        );
                        cwh.WriteLine();
                    }

                    cwh.UnIndent();
                    cwh.WriteLine("};");
                }

                // Virtual command method.

                cwh.WriteLine();
                cwh.Write($"virtual Status on{command.Name.ToUpperFirst()}Command(");

                for (var i = 0; i < command.Parameters.Count; i++)
                {
                    if (i > 0)
                        cwh.Write(", ");

                    var parameter = command.Parameters[i];
                    cwh.Write($"{parameter.TypeName} {parameter.Name}");
                }

                if (command.Response != null)
                {
                    if (command.Parameters.Count > 0)
                        cwh.Write(", ");
                    cwh.Write($"{responseClassName}& response");
                }

                cwh.WriteLine(") {");
                cwh.Indent();
                cwh.WriteLine("return Status::UnsupportedAttribute;");
                cwh.UnIndent();
                cwh.WriteLine("}");

                // Raise command method. We don't (yet) support responses.

                if (command.Response == null)
                {
                    cwh.WriteLine();
                    cwh.Write(
                        $"void send{command.Name.ToUpperFirst()}Command(DeviceManager& deviceManager, uint8_t endpointId"
                    );

                    for (var i = 0; i < command.Parameters.Count; i++)
                    {
                        var parameter = command.Parameters[i];
                        cwh.Write($", {parameter.TypeName} {parameter.Name}");
                    }

                    cwh.WriteLine(");");

                    cw.WriteLine();
                    cw.Write(
                        $"void {key.ToUpperFirst()}Cluster::send{command.Name.ToUpperFirst()}Command(DeviceManager& deviceManager, uint8_t endpointId"
                    );

                    for (var i = 0; i < command.Parameters.Count; i++)
                    {
                        var parameter = command.Parameters[i];
                        cw.Write($", {parameter.TypeName} {parameter.Name}");
                    }

                    cw.WriteLine(") {");
                    cw.Indent();

                    cw.WriteLine("auto buffer = deviceManager.getBuffer();");
                    cw.WriteLine();
                    cw.WriteLine("Frame(");
                    cw.Indent();
                    cw.WriteLine("FrameControl(FrameType::Cluster, Direction::ToServer, true),");
                    cw.WriteLine("nextTransactionSequenceNumber++,");
                    cw.WriteLine($"{command.Id}");
                    cw.UnIndent();
                    cw.WriteLine(").write(buffer);");
                    cw.WriteLine();

                    foreach (var parameter in command.Parameters)
                    {
                        var type = GetDataType(parameter.DataType, parameter.Name);
                        cw.WriteLine(
                            $"buffer.write{type.EndianMemoryMethodName}({parameter.Name});"
                        );
                    }

                    cw.WriteLine();
                    cw.WriteLine("deviceManager.sendMessage(this, endpointId, buffer);");

                    cw.UnIndent();
                    cw.WriteLine("}");
                }
            }

            // Command parser.

            if (commands.Count > 0)
            {
                cwh.WriteLine();
                cwh.WriteLine(
                    "void processCommand(uint8_t commandId, Memory& request, Memory& response) override;"
                );

                cw.WriteLine();
                cw.WriteLine(
                    $"void {key.ToUpperFirst()}Cluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {{"
                );
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
                        cw.WriteLine(
                            $"auto {parameter.Name} = request.read{type.EndianMemoryMethodName}();"
                        );
                    }

                    if (command.Response != null)
                    {
                        cw.WriteLine($"{responseClassName} response_;");
                    }

                    cw.Write($"auto status_ = on{command.Name.ToUpperFirst()}Command(");

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
                            cw.WriteLine(
                                $"response.write{type.EndianMemoryMethodName}(response_.get{parameter.Name.ToUpperFirst()}());"
                            );
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

            cwh.UnIndent();
            cwh.WriteLine("};");
        }

        WriteFile("Clusters.h", cwh.ToString());
        WriteFile("Clusters.cpp", cw.ToString());
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

            parsed.Parameters.AddRange(
                parameters.Select(p =>
                    (
                        (string)p["type"],
                        GetDataType((string)p["type"], (string)p["name"]).TypeName,
                        (string)p["name"]
                    )
                )
            );
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
        string target = Path.Combine(
            Path.GetDirectoryName(GetType().Assembly.Location),
            "..",
            "..",
            "..",
            "..",
            "..",
            "ZigBeeHomeAutomation",
            "src",
            fileName
        );

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

        string data = new WebClient().DownloadString(
            "https://raw.githubusercontent.com/Koenkk/zigbee-herdsman/master/src/zcl/definition/cluster.ts"
        );

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
            type == "DataType.struct"
            && name is "changeOfStateTime" or "timeOfATReset" or "timeOfSCReset"
        )
            return DataType.GetByHerdsmanName("DateTime");

        return DataType.GetByHerdsmanName(type);
    }
}
