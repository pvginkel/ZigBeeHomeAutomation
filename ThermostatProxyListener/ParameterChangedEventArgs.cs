namespace ThermostatProxyListener;

internal class ParameterChangedEventArgs(IParameter parameter) : EventArgs
{
    public IParameter Parameter { get; } = parameter;
}
