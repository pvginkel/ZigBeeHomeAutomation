namespace ThermostatProxyListener.Types;

internal record Percentage(float Value)
{
    public override string ToString() => $"{Value}%";
}
