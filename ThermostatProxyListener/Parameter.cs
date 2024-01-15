namespace ThermostatProxyListener;

internal enum Parameter
{
    // Master status
    CHEnabled,
    DHWEnabled,
    CoolingEnabled,
    OTCActive,
    CH2Enabled,

    // Slave status
    Fault,
    CHActive,
    DHWActive,
    FlameOn,
    CoolingModeActive,
    CH2Active,
    DiagnosticEvent,

    // Application specific fault flags
    ServiceRequired,
    RemoteResetEnabled,
    WaterPressureFault,
    GasFlameFault,
    AirPressureFault,
    OverTemperatureFault,
    OEMFaultCode,

    // Slave configuration
    DHWPresent,
    ControlType,
    CoolingSupported,
    DHWConfig,
    MasterLowOffPumpControlFunctionNotAllowed,
    CH2Present,

    // Remote parameter transfer enable
    DHWSetpointTransferEnabled,
    MaxCHSetpointTransferEnabled,

    // Remote parameter read/write flags
    DHWSetpointReadWrite,
    MaxCHSetpointReadWrite,

    // Messages
    ControlSetpoint,
    ControlSetpoint2,
    OEMDiagnosticCode,
    MasterMemberIDCode,
    SlaveMemberIDCode,
    MasterOpenThermVersion,
    SlaveOpenThermVersion,
    RoomSetpoint,
    RelativeModulationLevel,
    CHWaterPressure,
    DHWFlowRate,

    //DayOfWeek,
    //TimeOfDay,
    //Date,
    //Year,
    RoomSetpointCH2,
    RoomTemperature,
    BoilerWaterTemperature,
    DHWTemperature,
    OutsideTemperature,
    ReturnWaterTemperature,
    SolarStorageTemperature,
    SolarCollectorTemperature,
    FlowTemperatureCH2,
    DHW2Temperature,
    ExhaustTemperature,
    BurnerStarts,
    CHPumpStarts,
    DHWPumpValveStarts,
    DHWBurnerStarts,
    BurnerOperationHours,
    CHPumpOperationHours,
    DHWPumpValveOperationHours,
    DHWBurnerOperationHours,
    DHWSetpointBound,
    MaxCHSetpointBound,
    DHWSetpoint,
    MaxCHWaterSetpoint,
    CoolingControlSignal,
    MaximumRelativeModulationLevelSetting,
    MaximumBoilerCapacity,
    MinimumModulationLevel,
    RemoteOverrideRoomSetpoint,
    EnableOverrulingRemoteSetpointByManualSetpointChange,
    EnableOverrulingRemoteSetpointByProgramSetpointChange
}
