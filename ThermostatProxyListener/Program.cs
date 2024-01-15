using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;
using MQTTnet;
using MQTTnet.Client;
using Newtonsoft.Json.Linq;

var mqttFactory = new MqttFactory();
float boilerTemperature = 0;
float waterPressure = 0;
uint burnerStarts = 0;
uint chPumpStarts = 0;
uint burnerOperationHours = 0;
uint dhwBurnerOperationHours = 0;
float dhwFlowRate = 0;
byte asfFlags = 0;
MasterStatus? masterStatus = null;
SlaveStatus? slaveStatus = null;

using (var mqttClient = mqttFactory.CreateMqttClient())
{
    var mqttClientOptions = new MqttClientOptionsBuilder()
        .WithTcpServer("192.168.178.5")
        .WithCredentials("mqtt", Environment.GetEnvironmentVariable("MQTT_PASSWORD"))
        .Build();

    mqttClient.ApplicationMessageReceivedAsync += e =>
    {
        try
        {
            var data = Encoding.UTF8.GetString(e.ApplicationMessage.PayloadSegment);
            var obj = JObject.Parse(data);

            ProcessData((string)obj["log"]!);
        }
        catch (Exception ex)
        {
            Console.WriteLine("Failure: " + ex);
        }

        return Task.CompletedTask;
    };

    await mqttClient.ConnectAsync(mqttClientOptions);

    var mqttSubscribeOptions = mqttFactory
        .CreateSubscribeOptionsBuilder()
        .WithTopicFilter(f => f.WithTopic("zigbee2mqtt/Thermostat Proxy"))
        .Build();

    await mqttClient.SubscribeAsync(mqttSubscribeOptions, CancellationToken.None);

    Console.WriteLine("Listening...");

    Console.ReadLine();

    var mqttClientDisconnectOptions = mqttFactory.CreateClientDisconnectOptionsBuilder().Build();

    await mqttClient.DisconnectAsync(mqttClientDisconnectOptions, CancellationToken.None);
}

void ProcessData(string log)
{
    var match = Regex.Match(log, @"^T:(\S+)(?: B:0:3)?(?: B:(\S+))?$");
    if (!match.Success)
    {
        Console.WriteLine(log);
        throw new InvalidOperationException("Unexpected data");
    }

    //Console.WriteLine(log);

    var request = Message.Parse(match.Groups[1].Value)!;
    var response = Message.Parse(match.Groups[2].Value);
    if (response == null)
        return;

    File.AppendAllText("log.txt", $"""
{DateTime.Now:O} {log}
{request}
{response}

""");

    HandleRequestResponse(request, response);
}

void HandleRequestResponse(Message request, Message response)
{
    if (request.Status != 1)
    {
        Console.WriteLine("=====");
        Console.WriteLine("Invalid thermostat request " + request);
        return;
    }
    if (response.Status != 1)
    {
        Console.WriteLine("=====");
        Console.WriteLine("Invalid boiler response " + response);
        return;
    }

    switch (request)
    {
        case { Type: OpenThermMessageType.READ_DATA, Id: OpenThermMessageID.Status }:
            masterStatus = (MasterStatus)request.Payload & MasterStatus.All;
            slaveStatus = (SlaveStatus)response.Payload & SlaveStatus.All;
            break;
        case { Type: OpenThermMessageType.READ_DATA, Id: OpenThermMessageID.Tboiler }:
            boilerTemperature = response.FloatPayload;
            break;
        case { Type: OpenThermMessageType.READ_DATA, Id: OpenThermMessageID.CHPressure }:
            waterPressure = response.FloatPayload;
            break;
        case { Type: OpenThermMessageType.READ_DATA, Id: OpenThermMessageID.BurnerStarts }:
            burnerStarts = response.Payload;
            break;
        case { Type: OpenThermMessageType.READ_DATA, Id: OpenThermMessageID.CHPumpStarts }:
            chPumpStarts = response.Payload;
            break;
        case { Type: OpenThermMessageType.READ_DATA, Id: OpenThermMessageID.BurnerOperationHours }:
            burnerOperationHours = response.Payload;
            break;
        case {
            Type: OpenThermMessageType.READ_DATA,
            Id: OpenThermMessageID.DHWBurnerOperationHours
        }:
            dhwBurnerOperationHours = response.Payload;
            break;
        case { Type: OpenThermMessageType.READ_DATA, Id: OpenThermMessageID.DHWFlowRate }:
            dhwFlowRate = response.FloatPayload;
            break;
        case { Type: OpenThermMessageType.READ_DATA, Id: OpenThermMessageID.ASFflags }:
            asfFlags = (byte)response.Payload;
            break;
        case { Type: OpenThermMessageType.READ_DATA, Id: (OpenThermMessageID)113 }:
        case { Type: OpenThermMessageType.READ_DATA, Id: (OpenThermMessageID)114 }:
            // Ignore.
            break;
    }

    Console.WriteLine("=====");
    Console.WriteLine($"Master status: {masterStatus}");
    Console.WriteLine($"Slave status: {slaveStatus}");
    Console.WriteLine($"Boiler temperature: {boilerTemperature}");
    Console.WriteLine($"Water pressure: {waterPressure}");
    Console.WriteLine($"Burner starts: {burnerStarts}");
    Console.WriteLine($"CH pump starts: {chPumpStarts}");
    Console.WriteLine($"Burner operation hours: {burnerOperationHours}");
    Console.WriteLine($"DHW burner operation hours: {dhwBurnerOperationHours}");
    Console.WriteLine($"DHW flow rate: {dhwFlowRate}");
    Console.WriteLine($"ASF flags: {asfFlags}");
    Console.WriteLine();
    Console.WriteLine($"T: {request}");
    Console.WriteLine($"B: {response}");
}

record Message(OpenThermMessageType Type, OpenThermMessageID Id, ushort Payload, int Status)
{
    public static Message? Parse(string data)
    {
        if (data.Length == 0)
            return null;

        var parts = data.Split(':');
        var value = uint.Parse(parts[0], NumberStyles.HexNumber);
        if (value == 0)
            return null;
        var status = int.Parse(parts[1]);

        var type = (value >> 28) & 0b111;
        var id = (value >> 16) & 0xff;
        var payload = (ushort)(value & 0xffff);

        return new Message((OpenThermMessageType)type, (OpenThermMessageID)id, payload, status);
    }

    public float FloatPayload =>
        (Payload & 0x8000) != 0 ? -(0x10000L - Payload) / 256.0f : Payload / 256.0f;
}

enum OpenThermMessageType : byte
{
    /*  Master to Slave */
    READ_DATA = 0B000,
    READ = READ_DATA, // for backwared compatibility
    WRITE_DATA = 0B001,
    WRITE = WRITE_DATA, // for backwared compatibility
    INVALID_DATA = 0B010,
    RESERVED = 0B011,

    /* Slave to Master */
    READ_ACK = 0B100,
    WRITE_ACK = 0B101,
    DATA_INVALID = 0B110,
    UNKNOWN_DATA_ID = 0B111
};

enum OpenThermMessageID : byte
{
    Status, // flag8 / flag8  Master and Slave Status flags.
    TSet, // f8.8  Control setpoint  ie CH  water temperature setpoint (°C)
    MConfigMMemberIDcode, // flag8 / u8  Master Configuration Flags /  Master MemberID Code
    SConfigSMemberIDcode, // flag8 / u8  Slave Configuration Flags /  Slave MemberID Code
    Command, // u8 / u8  Remote Command
    ASFflags, // / OEM-fault-code  flag8 / u8  Application-specific fault flags and OEM fault code
    RBPflags, // flag8 / flag8  Remote boiler parameter transfer-enable & read/write flags
    CoolingControl, // f8.8  Cooling control signal (%)
    TsetCH2, // f8.8  Control setpoint for 2e CH circuit (°C)
    TrOverride, // f8.8  Remote override room setpoint
    TSP, // u8 / u8  Number of Transparent-Slave-Parameters supported by slave
    TSPindexTSPvalue, // u8 / u8  Index number / Value of referred-to transparent slave parameter.
    FHBsize, // u8 / u8  Size of Fault-History-Buffer supported by slave
    FHBindexFHBvalue, // u8 / u8  Index number / Value of referred-to fault-history buffer entry.
    MaxRelModLevelSetting, // f8.8  Maximum relative modulation level setting (%)
    MaxCapacityMinModLevel, // u8 / u8  Maximum boiler capacity (kW) / Minimum boiler modulation level(%)
    TrSet, // f8.8  Room Setpoint (°C)
    RelModLevel, // f8.8  Relative Modulation Level (%)
    CHPressure, // f8.8  Water pressure in CH circuit  (bar)
    DHWFlowRate, // f8.8  Water flow rate in DHW circuit. (litres/minute)
    DayTime, // special / u8  Day of Week and Time of Day
    Date, // u8 / u8  Calendar date
    Year, // u16  Calendar year
    TrSetCH2, // f8.8  Room Setpoint for 2nd CH circuit (°C)
    Tr, // f8.8  Room temperature (°C)
    Tboiler, // f8.8  Boiler flow water temperature (°C)
    Tdhw, // f8.8  DHW temperature (°C)
    Toutside, // f8.8  Outside temperature (°C)
    Tret, // f8.8  Return water temperature (°C)
    Tstorage, // f8.8  Solar storage temperature (°C)
    Tcollector, // f8.8  Solar collector temperature (°C)
    TflowCH2, // f8.8  Flow water temperature CH2 circuit (°C)
    Tdhw2, // f8.8  Domestic hot water temperature 2 (°C)
    Texhaust, // s16  Boiler exhaust temperature (°C)
    TdhwSetUBTdhwSetLB = 48, // s8 / s8  DHW setpoint upper & lower bounds for adjustment  (°C)
    MaxTSetUBMaxTSetLB, // s8 / s8  Max CH water setpoint upper & lower bounds for adjustment  (°C)
    HcratioUBHcratioLB, // s8 / s8  OTC heat curve ratio upper & lower bounds for adjustment
    TdhwSet = 56, // f8.8  DHW setpoint (°C)    (Remote parameter 1)
    MaxTSet, // f8.8  Max CH water setpoint (°C)  (Remote parameters 2)
    Hcratio, // f8.8  OTC heat curve ratio (°C)  (Remote parameter 3)
    RemoteOverrideFunction = 100, // flag8 / -  Function of manual and program changes in master and remote room setpoint.
    OEMDiagnosticCode = 115, // u16  OEM-specific diagnostic/service code
    BurnerStarts, // u16  Number of starts burner
    CHPumpStarts, // u16  Number of starts CH pump
    DHWPumpValveStarts, // u16  Number of starts DHW pump/valve
    DHWBurnerStarts, // u16  Number of starts burner during DHW mode
    BurnerOperationHours, // u16  Number of hours that burner is in operation (i.e. flame on)
    CHPumpOperationHours, // u16  Number of hours that CH pump has been running
    DHWPumpValveOperationHours, // u16  Number of hours that DHW pump has been running or DHW valve has been opened
    DHWBurnerOperationHours, // u16  Number of hours that burner is in operation during DHW mode
    OpenThermVersionMaster, // f8.8  The implemented version of the OpenTherm Protocol Specification in the master.
    OpenThermVersionSlave, // f8.8  The implemented version of the OpenTherm Protocol Specification in the slave.
    MasterVersion, // u8 / u8  Master product version number and type
    SlaveVersion, // u8 / u8  Slave product version number and type
}

[Flags]
enum MasterStatus
{
    CHEnable = 1,
    DHWEnable = 2,
    CoolingEnable = 4,
    OTCActive = 8,
    CH2Enable = 16,
    All = 31
}

[Flags]
enum SlaveStatus
{
    FaultIndication = 1,
    CHMode = 2,
    DHWMode = 4,
    FlameStatus = 8,
    CoolingStatus = 16,
    CH2Mode = 32,
    DiagnosticIndication = 64,
    All = 127
}
