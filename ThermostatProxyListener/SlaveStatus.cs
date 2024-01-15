namespace ThermostatProxyListener;

[Flags]
internal enum SlaveStatus
{
    FaultIndication = 1,
    CHMode = 2,
    DHWMode = 4,
    FlameStatus = 8,
    CoolingStatus = 16,
    CH2Mode = 32,
    DiagnosticIndication = 64,
    All = 127
}
