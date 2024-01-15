namespace ThermostatProxyListener;

[Flags]
internal enum MasterStatus
{
    CHEnable = 1,
    DHWEnable = 2,
    CoolingEnable = 4,
    OTCActive = 8,
    CH2Enable = 16,
    All = 31
}
