using System.Text;
using System.Text.RegularExpressions;
using MQTTnet;
using MQTTnet.Client;
using Newtonsoft.Json.Linq;

namespace ThermostatProxyListener;

internal class ThermostatProxyMQTTClient : IAsyncDisposable
{
    private readonly ThermostatProxyStatusHandler _statusHandler;
    private readonly MqttFactory _factory = new();
    private readonly IMqttClient _client;

    public ThermostatProxyMQTTClient(ThermostatProxyStatusHandler statusHandler)
    {
        _statusHandler = statusHandler;
        _client = _factory.CreateMqttClient();
    }

    public async Task Connect()
    {
        ReplayLog();

        var mqttClientOptions = new MqttClientOptionsBuilder()
            .WithTcpServer("192.168.178.5")
            .WithCredentials("mqtt", Environment.GetEnvironmentVariable("MQTT_PASSWORD"))
            .Build();

        _client.ApplicationMessageReceivedAsync += e =>
        {
            try
            {
                var data = Encoding.UTF8.GetString(e.ApplicationMessage.PayloadSegment);
                var obj = JObject.Parse(data);

                ProcessData((string)obj["log"]!, false);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Failure: " + ex);
            }

            return Task.CompletedTask;
        };

        await _client.ConnectAsync(mqttClientOptions);

        var mqttSubscribeOptions = _factory
            .CreateSubscribeOptionsBuilder()
            .WithTopicFilter(f => f.WithTopic("zigbee2mqtt/Thermostat Proxy"))
            .Build();

        await _client.SubscribeAsync(mqttSubscribeOptions, CancellationToken.None);
    }

    private void ReplayLog()
    {
        foreach (var line in File.ReadAllLines("log.txt"))
        {
            var match = Regex.Match(line, @" (T:\S+ B:\S+)$");
            if (match.Success)
                ProcessData(match.Groups[1].Value, true);
        }
    }

    private void ProcessData(string log, bool replay)
    {
        var match = Regex.Match(log, @"^T:(\S+)(?: B:0:3)?(?: B:(\S+))?$");
        if (!match.Success)
        {
            Console.WriteLine(log);
            throw new InvalidOperationException("Unexpected data");
        }

        var request = Message.Parse(match.Groups[1].Value);
        var response = Message.Parse(match.Groups[2].Value);
        if (request == null || response == null)
            return;

        File.AppendAllText("log.txt", $"""
{DateTime.Now:O} {log}
{request}
{response}

""");

        HandleRequestResponse(request, response, replay);
    }

    private void HandleRequestResponse(Message request, Message response, bool replay)
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

        _statusHandler.Process(request, response, replay);
    }

    public async ValueTask DisposeAsync()
    {
        var mqttClientDisconnectOptions = _factory.CreateClientDisconnectOptionsBuilder().Build();

        await _client.DisconnectAsync(mqttClientDisconnectOptions, CancellationToken.None);

        _client.Dispose();
    }
}
