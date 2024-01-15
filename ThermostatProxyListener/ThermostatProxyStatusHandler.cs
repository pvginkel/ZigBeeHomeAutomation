namespace ThermostatProxyListener;

internal class ThermostatProxyStatusHandler
{
    public Parameters Parameters { get; } = new();

    public event EventHandler? Updated;

    public void Process(Message request, Message response, bool replay)
    {
        Parameters.Process(request, response);

        if (!replay)
            OnUpdated();
    }

    protected virtual void OnUpdated() => Updated?.Invoke(this, EventArgs.Empty);
}
