namespace ThermostatProxyListener.Types;

internal record Temperature(float Value)
{
    public override string ToString() => $"{Value}°C";
}
