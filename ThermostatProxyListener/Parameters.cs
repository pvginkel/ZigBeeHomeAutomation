using System.Collections.Immutable;
using ThermostatProxyListener.Types;

namespace ThermostatProxyListener;

internal class Parameters
{
    private static IParameter CreateParameter(
        Parameter parameter,
        MessageId messageId,
        Func<Message, Message, object?> handler
    )
    {
        return new ParameterValue(parameter, messageId, handler);
    }

    private static IParameter CreateFlagParameter(
        Parameter parameter,
        MessageId messageId,
        Func<Message, Message, bool> handler,
        Func<Message, Message, bool>? requestedHandler = null
    )
    {
        ParameterValue self = null!;

        self = new ParameterValue(
            parameter,
            messageId,
            (request, response) =>
            {
                var value = handler(request, response);
                var requestedValue = requestedHandler?.Invoke(request, response) ?? value;
                if (value == requestedValue)
                    return value ? "YES" : (self.Value == null ? null : "NO");

                return (value ? "YES" : "NO") + " (requested " + (requestedValue ? "YES" : "NO");
            }
        );

        return self;
    }

    private readonly Dictionary<MessageId, List<IParameter>> _parametersByMessageId;

    public ImmutableArray<IParameter> AllParameters { get; }

    // Master status
    public IParameter CHEnabled { get; } =
        CreateFlagParameter(
            Parameter.CHEnabled,
            MessageId.Status,
            (request, response) =>
                ((MasterStatus)response.PayloadHBU8).HasFlag(MasterStatus.CHEnable),
            (request, response) =>
                ((MasterStatus)request.PayloadHBU8).HasFlag(MasterStatus.CHEnable)
        );
    public IParameter DHWEnabled { get; } =
        CreateFlagParameter(
            Parameter.DHWEnabled,
            MessageId.Status,
            (request, response) =>
                ((MasterStatus)response.PayloadHBU8).HasFlag(MasterStatus.DHWEnable),
            (request, response) =>
                ((MasterStatus)request.PayloadHBU8).HasFlag(MasterStatus.DHWEnable)
        );
    public IParameter CoolingEnabled { get; } =
        CreateFlagParameter(
            Parameter.CoolingEnabled,
            MessageId.Status,
            (request, response) =>
                ((MasterStatus)response.PayloadHBU8).HasFlag(MasterStatus.CoolingEnable),
            (request, response) =>
                ((MasterStatus)request.PayloadHBU8).HasFlag(MasterStatus.CoolingEnable)
        );
    public IParameter OTCActive { get; } =
        CreateFlagParameter(
            Parameter.OTCActive,
            MessageId.Status,
            (request, response) =>
                ((MasterStatus)response.PayloadHBU8).HasFlag(MasterStatus.OTCActive),
            (request, response) =>
                ((MasterStatus)request.PayloadHBU8).HasFlag(MasterStatus.OTCActive)
        );
    public IParameter CH2Enabled { get; } =
        CreateFlagParameter(
            Parameter.CH2Enabled,
            MessageId.Status,
            (request, response) =>
                ((MasterStatus)response.PayloadHBU8).HasFlag(MasterStatus.CH2Enable),
            (request, response) =>
                ((MasterStatus)request.PayloadHBU8).HasFlag(MasterStatus.CH2Enable)
        );

    // Slave status
    public IParameter Fault { get; } =
        CreateFlagParameter(
            Parameter.Fault,
            MessageId.Status,
            (request, response) =>
                ((SlaveStatus)response.PayloadLBU8).HasFlag(SlaveStatus.FaultIndication)
        );
    public IParameter CHActive { get; } =
        CreateFlagParameter(
            Parameter.CHActive,
            MessageId.Status,
            (request, response) => ((SlaveStatus)response.PayloadLBU8).HasFlag(SlaveStatus.CHMode)
        );
    public IParameter DHWActive { get; } =
        CreateFlagParameter(
            Parameter.DHWActive,
            MessageId.Status,
            (request, response) => ((SlaveStatus)response.PayloadLBU8).HasFlag(SlaveStatus.DHWMode)
        );
    public IParameter FlameOn { get; } =
        CreateFlagParameter(
            Parameter.FlameOn,
            MessageId.Status,
            (request, response) =>
                ((SlaveStatus)response.PayloadLBU8).HasFlag(SlaveStatus.FlameStatus)
        );
    public IParameter CoolingModeActive { get; } =
        CreateFlagParameter(
            Parameter.CoolingModeActive,
            MessageId.Status,
            (request, response) =>
                ((SlaveStatus)response.PayloadLBU8).HasFlag(SlaveStatus.CoolingStatus)
        );
    public IParameter CH2Active { get; } =
        CreateFlagParameter(
            Parameter.CH2Active,
            MessageId.Status,
            (request, response) => ((SlaveStatus)response.PayloadLBU8).HasFlag(SlaveStatus.CH2Mode)
        );
    public IParameter DiagnosticEvent { get; } =
        CreateFlagParameter(
            Parameter.DiagnosticEvent,
            MessageId.Status,
            (request, response) =>
                ((SlaveStatus)response.PayloadLBU8).HasFlag(SlaveStatus.DiagnosticIndication)
        );

    // Application specific fault flags
    public IParameter ServiceRequired { get; } =
        CreateFlagParameter(
            Parameter.ServiceRequired,
            MessageId.ASFflags,
            (request, response) => ((ASFFlags)response.PayloadHBU8).HasFlag(ASFFlags.ServiceRequest)
        );
    public IParameter RemoteResetEnabled { get; } =
        CreateFlagParameter(
            Parameter.RemoteResetEnabled,
            MessageId.ASFflags,
            (request, response) => ((ASFFlags)response.PayloadHBU8).HasFlag(ASFFlags.LockoutRequest)
        );
    public IParameter WaterPressureFault { get; } =
        CreateFlagParameter(
            Parameter.WaterPressureFault,
            MessageId.ASFflags,
            (request, response) =>
                ((ASFFlags)response.PayloadHBU8).HasFlag(ASFFlags.LowWaterPressure)
        );
    public IParameter GasFlameFault { get; } =
        CreateFlagParameter(
            Parameter.GasFlameFault,
            MessageId.ASFflags,
            (request, response) => ((ASFFlags)response.PayloadHBU8).HasFlag(ASFFlags.GasFlameFault)
        );
    public IParameter AirPressureFault { get; } =
        CreateFlagParameter(
            Parameter.AirPressureFault,
            MessageId.ASFflags,
            (request, response) =>
                ((ASFFlags)response.PayloadHBU8).HasFlag(ASFFlags.AirPressureFault)
        );
    public IParameter OverTemperatureFault { get; } =
        CreateFlagParameter(
            Parameter.OverTemperatureFault,
            MessageId.ASFflags,
            (request, response) => ((ASFFlags)response.PayloadHBU8).HasFlag(ASFFlags.WaterOverTemp)
        );
    public IParameter OEMFaultCode { get; } =
        CreateParameter(
            Parameter.OEMFaultCode,
            MessageId.ASFflags,
            (request, response) => response.PayloadLBU8
        );

    // Slave configuration
    public IParameter DHWPresent { get; } =
        CreateFlagParameter(
            Parameter.DHWPresent,
            MessageId.SConfigSMemberIDcode,
            (request, response) =>
                ((SlaveConfiguration)response.PayloadHBU8).HasFlag(SlaveConfiguration.DHWPresent)
        );
    public IParameter ControlType { get; } =
        CreateParameter(
            Parameter.ControlType,
            MessageId.SConfigSMemberIDcode,
            (request, response) =>
                ((SlaveConfiguration)response.PayloadHBU8).HasFlag(SlaveConfiguration.ControlType)
                    ? SlaveControlType.OnOff
                    : SlaveControlType.Modulating
        );
    public IParameter CoolingSupported { get; } =
        CreateFlagParameter(
            Parameter.CoolingSupported,
            MessageId.SConfigSMemberIDcode,
            (request, response) =>
                ((SlaveConfiguration)response.PayloadHBU8).HasFlag(SlaveConfiguration.CoolingConfig)
        );
    public IParameter DHWConfig { get; } =
        CreateFlagParameter(
            Parameter.DHWConfig,
            MessageId.SConfigSMemberIDcode,
            (request, response) =>
                ((SlaveConfiguration)response.PayloadHBU8).HasFlag(SlaveConfiguration.DHWConfig)
        );
    public IParameter MasterLowOffPumpControlFunctionNotAllowed { get; } =
        CreateFlagParameter(
            Parameter.MasterLowOffPumpControlFunctionNotAllowed,
            MessageId.SConfigSMemberIDcode,
            (request, response) =>
                ((SlaveConfiguration)response.PayloadHBU8).HasFlag(
                    SlaveConfiguration.MasterLowOffPumpControlFunction
                )
        );
    public IParameter DHWCH2PresentPresent { get; } =
        CreateFlagParameter(
            Parameter.CH2Present,
            MessageId.SConfigSMemberIDcode,
            (request, response) =>
                ((SlaveConfiguration)response.PayloadHBU8).HasFlag(SlaveConfiguration.CH2Present)
        );

    // Remote parameter transfer enable
    public IParameter DHWSetpointTransferEnabled { get; } =
        CreateFlagParameter(
            Parameter.DHWSetpointTransferEnabled,
            MessageId.RBPflags,
            (request, response) => ((RBPFlags)response.PayloadHBU8).HasFlag(RBPFlags.DHWSetpoint)
        );
    public IParameter MaxCHSetpointTransferEnabled { get; } =
        CreateFlagParameter(
            Parameter.MaxCHSetpointTransferEnabled,
            MessageId.RBPflags,
            (request, response) => ((RBPFlags)response.PayloadHBU8).HasFlag(RBPFlags.MaxCHSetpoint)
        );

    // Remote parameter read/write flags
    public IParameter DHWSetpointReadWrite { get; } =
        CreateFlagParameter(
            Parameter.DHWSetpointReadWrite,
            MessageId.RBPflags,
            (request, response) => ((RBPFlags)response.PayloadLBU8).HasFlag(RBPFlags.DHWSetpoint)
        );
    public IParameter MaxCHSetpointReadWrite { get; } =
        CreateFlagParameter(
            Parameter.MaxCHSetpointReadWrite,
            MessageId.RBPflags,
            (request, response) => ((RBPFlags)response.PayloadLBU8).HasFlag(RBPFlags.MaxCHSetpoint)
        );

    // Messages
    public IParameter ControlSetpoint { get; } =
        CreateParameter(
            Parameter.ControlSetpoint,
            MessageId.TSet,
            (request, response) => new Temperature(request.PayloadFloat)
        );
    public IParameter ControlSetpoint2 { get; } =
        CreateParameter(
            Parameter.ControlSetpoint2,
            MessageId.TsetCH2,
            (request, response) => new Temperature(request.PayloadFloat)
        );
    public IParameter OEMDiagnosticCode { get; } =
        CreateParameter(
            Parameter.OEMDiagnosticCode,
            MessageId.OEMDiagnosticCode,
            (request, response) => response.PayloadU16
        );
    public IParameter MasterMemberIDCode { get; } =
        CreateParameter(
            Parameter.MasterMemberIDCode,
            MessageId.MConfigMMemberIDcode,
            (request, response) => request.PayloadLBU8
        );
    public IParameter SlaveMemberIDCode { get; } =
        CreateParameter(
            Parameter.SlaveMemberIDCode,
            MessageId.SConfigSMemberIDcode,
            (request, response) => response.PayloadLBU8
        );
    public IParameter MasterOpenThermVersion { get; } =
        CreateParameter(
            Parameter.MasterOpenThermVersion,
            MessageId.OpenThermVersionMaster,
            (request, response) => new ProductVersion(request.PayloadHBU8, request.PayloadLBU8)
        );
    public IParameter SlaveOpenThermVersion { get; } =
        CreateParameter(
            Parameter.SlaveOpenThermVersion,
            MessageId.OpenThermVersionSlave,
            (request, response) => new ProductVersion(response.PayloadHBU8, response.PayloadLBU8)
        );
    public IParameter RoomSetpoint { get; } =
        CreateParameter(
            Parameter.RoomSetpoint,
            MessageId.TrSet,
            (request, response) => new Temperature(request.PayloadFloat)
        );
    public IParameter RelativeModulationLevel { get; } =
        CreateParameter(
            Parameter.RelativeModulationLevel,
            MessageId.RelModLevel,
            (request, response) => new Percentage(response.PayloadFloat)
        );
    public IParameter CHWaterPressure { get; } =
        CreateParameter(
            Parameter.CHWaterPressure,
            MessageId.CHPressure,
            (request, response) => new Bar(response.PayloadFloat)
        );
    public IParameter DHWFlowRate { get; } =
        CreateParameter(
            Parameter.DHWFlowRate,
            MessageId.DHWFlowRate,
            (request, response) => new FlowRate(response.PayloadFloat)
        );
    public IParameter RoomSetpointCH2 { get; } =
        CreateParameter(
            Parameter.RoomSetpointCH2,
            MessageId.TrSetCH2,
            (request, response) => new Temperature(request.PayloadFloat)
        );
    public IParameter RoomTemperature { get; } =
        CreateParameter(
            Parameter.RoomTemperature,
            MessageId.Tr,
            (request, response) => new Temperature(request.PayloadFloat)
        );
    public IParameter BoilerWaterTemperature { get; } =
        CreateParameter(
            Parameter.BoilerWaterTemperature,
            MessageId.Tboiler,
            (request, response) => new Temperature(response.PayloadFloat)
        );
    public IParameter DHWTemperature { get; } =
        CreateParameter(
            Parameter.DHWTemperature,
            MessageId.Tdhw,
            (request, response) => new Temperature(response.PayloadFloat)
        );
    public IParameter OutsideTemperature { get; } =
        CreateParameter(
            Parameter.OutsideTemperature,
            MessageId.Toutside,
            (request, response) => new Temperature(response.PayloadFloat)
        );
    public IParameter ReturnWaterTemperature { get; } =
        CreateParameter(
            Parameter.ReturnWaterTemperature,
            MessageId.Tret,
            (request, response) => new Temperature(response.PayloadFloat)
        );
    public IParameter SolarStorageTemperature { get; } =
        CreateParameter(
            Parameter.SolarStorageTemperature,
            MessageId.Tstorage,
            (request, response) => new Temperature(response.PayloadFloat)
        );
    public IParameter SolarCollectorTemperature { get; } =
        CreateParameter(
            Parameter.SolarCollectorTemperature,
            MessageId.Tcollector,
            (request, response) => new Temperature(response.PayloadS16)
        );
    public IParameter FlowTemperatureCH2 { get; } =
        CreateParameter(
            Parameter.FlowTemperatureCH2,
            MessageId.TflowCH2,
            (request, response) => new Temperature(response.PayloadFloat)
        );
    public IParameter DHW2Temperature { get; } =
        CreateParameter(
            Parameter.DHW2Temperature,
            MessageId.Tdhw2,
            (request, response) => new Temperature(response.PayloadFloat)
        );
    public IParameter ExhaustTemperature { get; } =
        CreateParameter(
            Parameter.ExhaustTemperature,
            MessageId.Texhaust,
            (request, response) => new Temperature(response.PayloadS16)
        );
    public IParameter BurnerStarts { get; } =
        CreateParameter(
            Parameter.BurnerStarts,
            MessageId.BurnerStarts,
            (request, response) => response.PayloadU16
        );
    public IParameter CHPumpStarts { get; } =
        CreateParameter(
            Parameter.CHPumpStarts,
            MessageId.CHPumpStarts,
            (request, response) => response.PayloadU16
        );
    public IParameter DHWPumpValveStarts { get; } =
        CreateParameter(
            Parameter.DHWPumpValveStarts,
            MessageId.DHWPumpValveStarts,
            (request, response) => response.PayloadU16
        );
    public IParameter DHWBurnerStarts { get; } =
        CreateParameter(
            Parameter.DHWBurnerStarts,
            MessageId.DHWBurnerStarts,
            (request, response) => response.PayloadU16
        );
    public IParameter BurnerOperationHours { get; } =
        CreateParameter(
            Parameter.BurnerOperationHours,
            MessageId.BurnerOperationHours,
            (request, response) => response.PayloadU16
        );
    public IParameter CHPumpOperationHours { get; } =
        CreateParameter(
            Parameter.CHPumpOperationHours,
            MessageId.CHPumpOperationHours,
            (request, response) => response.PayloadU16
        );
    public IParameter DHWPumpValveOperationHours { get; } =
        CreateParameter(
            Parameter.DHWPumpValveOperationHours,
            MessageId.DHWPumpValveOperationHours,
            (request, response) => response.PayloadU16
        );
    public IParameter DHWBurnerOperationHours { get; } =
        CreateParameter(
            Parameter.DHWBurnerOperationHours,
            MessageId.DHWBurnerOperationHours,
            (request, response) => response.PayloadU16
        );
    public IParameter DHWSetpointBound { get; } =
        CreateParameter(
            Parameter.DHWSetpointBound,
            MessageId.TdhwSetUBTdhwSetLB,
            (request, response) =>
                new SetpointBound(
                    new Temperature((sbyte)response.PayloadLBU8),
                    new Temperature((sbyte)response.PayloadHBU8)
                )
        );
    public IParameter MaxCHSetpointBound { get; } =
        CreateParameter(
            Parameter.MaxCHSetpointBound,
            MessageId.MaxTSetUBMaxTSetLB,
            (request, response) =>
                new SetpointBound(
                    new Temperature((sbyte)response.PayloadLBU8),
                    new Temperature((sbyte)response.PayloadHBU8)
                )
        );
    public IParameter DHWSetpoint { get; } =
        CreateParameter(
            Parameter.DHWSetpoint,
            MessageId.TdhwSet,
            (request, response) => new Temperature(response.PayloadFloat)
        );
    public IParameter MaxCHWaterSetpoint { get; } =
        CreateParameter(
            Parameter.MaxCHWaterSetpoint,
            MessageId.TdhwSet,
            (request, response) => new Temperature(response.PayloadFloat)
        );
    public IParameter CoolingControlSignal { get; } =
        CreateParameter(
            Parameter.CoolingControlSignal,
            MessageId.CoolingControl,
            (request, response) => new Percentage(response.PayloadFloat)
        );
    public IParameter MaximumRelativeModulationLevelSetting { get; } =
        CreateParameter(
            Parameter.MaximumRelativeModulationLevelSetting,
            MessageId.MaxRelModLevelSetting,
            (request, response) => new Percentage(response.PayloadFloat)
        );
    public IParameter MaximumBoilerCapacity { get; } =
        CreateParameter(
            Parameter.MaximumBoilerCapacity,
            MessageId.MaxCapacityMinModLevel,
            (request, response) => new KiloWatt(response.PayloadHBU8)
        );
    public IParameter MinimumModulationLevel { get; } =
        CreateParameter(
            Parameter.MinimumModulationLevel,
            MessageId.MaxCapacityMinModLevel,
            (request, response) => new Percentage(response.PayloadLBU8)
        );
    public IParameter RemoteOverrideRoomSetpoint { get; } =
        CreateFlagParameter(
            Parameter.RemoteOverrideRoomSetpoint,
            MessageId.TrOverride,
            (request, response) => response.PayloadFloat > 0
        );
    public IParameter EnableOverrulingRemoteSetpointByManualSetpointChange { get; } =
        CreateFlagParameter(
            Parameter.EnableOverrulingRemoteSetpointByManualSetpointChange,
            MessageId.RemoteOverrideFunction,
            (request, response) =>
                ((RemoteOverrideFunction)response.PayloadLBU8).HasFlag(
                    RemoteOverrideFunction.OverrulingRemoteSetpointByManualSetpointChange
                )
        );
    public IParameter EnableOverrulingRemoteSetpointByProgramSetpointChange { get; } =
        CreateFlagParameter(
            Parameter.EnableOverrulingRemoteSetpointByProgramSetpointChange,
            MessageId.RemoteOverrideFunction,
            (request, response) =>
                ((RemoteOverrideFunction)response.PayloadLBU8).HasFlag(
                    RemoteOverrideFunction.OverrulingRemoteSetpointByProgramSetpointChange
                )
        );

    public event EventHandler<ParameterChangedEventArgs>? ParameterChanged;

    public Parameters()
    {
        AllParameters = GetType()
            .GetProperties()
            .Where(p => p.PropertyType == typeof(IParameter))
            .Select(p => (IParameter)p.GetValue(this)!)
            .ToImmutableArray();

        foreach (var parameter in AllParameters)
        {
            parameter.Changed += (_, _) =>
                OnParameterChanged(new ParameterChangedEventArgs(parameter));
        }

        _parametersByMessageId = AllParameters
            .GroupBy(p => p.MessageId)
            .ToDictionary(p => p.Key, p => p.ToList());
    }

    private void Parameter_Changed(object? sender, EventArgs e) { }

    public void Process(Message request, Message response, DateTime dateTime)
    {
        if (_parametersByMessageId.TryGetValue(request.Id, out var parameters))
        {
            foreach (var parameter in parameters)
            {
                parameter.Update(request, response, dateTime);
            }
        }
    }

    protected virtual void OnParameterChanged(ParameterChangedEventArgs e) =>
        ParameterChanged?.Invoke(this, e);

    private class ParameterValue(
        Parameter parameter,
        MessageId messageId,
        Func<Message, Message, object?> handler
    ) : IParameter
    {
        public Parameter Parameter => parameter;
        public MessageId MessageId => messageId;
        public DateTime LastUpdated { get; private set; } = DateTime.MinValue;
        public MessageType? LastResponseType { get; private set; }
        public object? Value { get; private set; }

        public event EventHandler? Changed;

        public void Update(Message request, Message response, DateTime dateTime)
        {
            if (
                request.Type == MessageType.READ_DATA
                && response.Type == MessageType.UNKNOWN_DATA_ID
            )
                return;

            var value = handler(request, response);
            if (!Equals(value, Value))
            {
                Value = value;
                LastUpdated = dateTime;
                LastResponseType = response.Type;

                OnChanged();
            }
        }

        public override string? ToString() => Value?.ToString();

        protected virtual void OnChanged() => Changed?.Invoke(this, EventArgs.Empty);
    }
}
