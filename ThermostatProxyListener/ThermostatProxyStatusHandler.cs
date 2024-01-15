namespace ThermostatProxyListener;

internal class ThermostatProxyStatusHandler
{
    public Parameters Parameters { get; } = new();

    public event EventHandler<MessagesEventArgs>? Updated;

    public void Process(Message request, Message response, bool replay)
    {
        Parameters.Process(request, response);

        if (!replay)
            OnUpdated(new MessagesEventArgs(request, response));
    }

    protected virtual void OnUpdated(MessagesEventArgs e) => Updated?.Invoke(this, e);
}
