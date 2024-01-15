namespace ThermostatProxyListener.Types;

internal record KiloWatt(byte Value)
{
    public override string ToString() => $"{Value} kW";
}
