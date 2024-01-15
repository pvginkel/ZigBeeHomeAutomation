namespace ThermostatProxyListener;

[Flags]
internal enum ASFFlags
{
    ServiceRequest = 1,
    LockoutRequest = 2,
    LowWaterPressure = 4,
    GasFlameFault = 8,
    AirPressureFault = 16,
    WaterOverTemp = 32
}
