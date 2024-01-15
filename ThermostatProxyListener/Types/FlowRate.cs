namespace ThermostatProxyListener.Types;

internal record FlowRate(float Value)
{
    public override string ToString() => $"{Value} l/min";
}
