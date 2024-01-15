namespace ThermostatProxyListener.Types;

internal record Bar(float Value)
{
    public override string ToString() => $"{Value} bar";
}
