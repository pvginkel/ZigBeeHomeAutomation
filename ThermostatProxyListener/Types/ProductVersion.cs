namespace ThermostatProxyListener.Types;

internal record ProductVersion(byte Type, byte Version)
{
    public override string ToString() => $"Type = {Type}, Version = {Version}";
}
