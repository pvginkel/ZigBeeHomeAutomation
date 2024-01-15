namespace ThermostatProxyListener;

[Flags]
internal enum SlaveConfiguration
{
    DHWPresent = 1,
    ControlType = 2,
    CoolingConfig = 4,
    DHWConfig = 8,
    MasterLowOffPumpControlFunction = 16,
    CH2Present = 32
}
