namespace ThermostatProxyListener;

[Flags]
internal enum RemoteOverrideFunction
{
    OverrulingRemoteSetpointByManualSetpointChange = 1,
    OverrulingRemoteSetpointByProgramSetpointChange = 2
}
