namespace ThermostatProxyListener;

internal interface IParameter
{
    Parameter Parameter { get; }
    MessageId MessageId { get; }
    object? Value { get; }
    DateTime LastUpdated { get; }
    MessageType? LastResponseType { get; }

    void Update(Message request, Message response, DateTime dateTime);
    event EventHandler? Changed;
}
