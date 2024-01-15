namespace ThermostatProxyListener;

internal class MessagesEventArgs(Message request, Message response) : EventArgs
{
    public Message Request { get; } = request;
    public Message Response { get; } = response;
}
