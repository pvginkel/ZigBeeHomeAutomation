#pragma once

enum class GenBasicAttribute: uint16_t {
    ZclVersion = 0,
    AppVersion = 1,
    StackVersion = 2,
    HwVersion = 3,
    ManufacturerName = 4,
    ModelId = 5,
    DateCode = 6,
    PowerSource = 7,
    AppProfileVersion = 8,
    SwBuildId = 16384,
    LocationDesc = 16,
    PhysicalEnv = 17,
    DeviceEnabled = 18,
    AlarmMask = 19,
    DisableLocalConfig = 20,
    DevelcoPrimarySwVersion = 32768,
    DevelcoPrimaryHwVersion = 32800,
    DevelcoLedControl = 33024,
    SchneiderMeterRadioPower = 57856,
};

class GenBasicCluster: public Cluster {
public:
    GenBasicCluster(ClusterType type = ClusterType::Input) : Cluster(0, type) {
    }
    AttributeUInt8* getZclVersion();
    AttributeUInt8* getAppVersion();
    AttributeUInt8* getStackVersion();
    AttributeUInt8* getHwVersion();
    AttributeString* getManufacturerName();
    AttributeString* getModelId();
    AttributeString* getDateCode();
    AttributeUInt8* getPowerSource();
    AttributeUInt8* getAppProfileVersion();
    AttributeString* getSwBuildId();
    AttributeString* getLocationDesc();
    AttributeUInt8* getPhysicalEnv();
    AttributeUInt8* getDeviceEnabled();
    AttributeUInt8* getAlarmMask();
    AttributeUInt8* getDisableLocalConfig();

    virtual Status onResetFactDefaultCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendResetFactDefaultCommand(DeviceManager& deviceManager, uint8_t endpointId);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class GenPowerCfgAttribute: uint16_t {
    MainsVoltage = 0,
    MainsFrequency = 1,
    MainsAlarmMask = 16,
    MainsVoltMinThres = 17,
    MainsVoltMaxThres = 18,
    MainsVoltageDwellTripPoint = 19,
    BatteryVoltage = 32,
    BatteryPercentageRemaining = 33,
    BatteryManufacturer = 48,
    BatterySize = 49,
    BatteryAHrRating = 50,
    BatteryQuantity = 51,
    BatteryRatedVoltage = 52,
    BatteryAlarmMask = 53,
    BatteryVoltMinThres = 54,
    BatteryVoltThres1 = 55,
    BatteryVoltThres2 = 56,
    BatteryVoltThres3 = 57,
    BatteryPercentMinThres = 58,
    BatteryPercentThres1 = 59,
    BatteryPercentThres2 = 60,
    BatteryPercentThres3 = 61,
    BatteryAlarmState = 62,
};

class GenPowerCfgCluster: public Cluster {
public:
    GenPowerCfgCluster(ClusterType type = ClusterType::Input) : Cluster(1, type) {
    }
    AttributeUInt16* getMainsVoltage();
    AttributeUInt8* getMainsFrequency();
    AttributeUInt8* getMainsAlarmMask();
    AttributeUInt16* getMainsVoltMinThres();
    AttributeUInt16* getMainsVoltMaxThres();
    AttributeUInt16* getMainsVoltageDwellTripPoint();
    AttributeUInt8* getBatteryVoltage();
    AttributeUInt8* getBatteryPercentageRemaining();
    AttributeString* getBatteryManufacturer();
    AttributeUInt8* getBatterySize();
    AttributeUInt16* getBatteryAHrRating();
    AttributeUInt8* getBatteryQuantity();
    AttributeUInt8* getBatteryRatedVoltage();
    AttributeUInt8* getBatteryAlarmMask();
    AttributeUInt8* getBatteryVoltMinThres();
    AttributeUInt8* getBatteryVoltThres1();
    AttributeUInt8* getBatteryVoltThres2();
    AttributeUInt8* getBatteryVoltThres3();
    AttributeUInt8* getBatteryPercentMinThres();
    AttributeUInt8* getBatteryPercentThres1();
    AttributeUInt8* getBatteryPercentThres2();
    AttributeUInt8* getBatteryPercentThres3();
    AttributeUInt32* getBatteryAlarmState();
};

enum class GenDeviceTempCfgAttribute: uint16_t {
    CurrentTemperature = 0,
    MinTempExperienced = 1,
    MaxTempExperienced = 2,
    OverTempTotalDwell = 3,
    DevTempAlarmMask = 16,
    LowTempThres = 17,
    HighTempThres = 18,
    LowTempDwellTripPoint = 19,
    HighTempDwellTripPoint = 20,
};

class GenDeviceTempCfgCluster: public Cluster {
public:
    GenDeviceTempCfgCluster(ClusterType type = ClusterType::Input) : Cluster(2, type) {
    }
    AttributeInt16* getCurrentTemperature();
    AttributeInt16* getMinTempExperienced();
    AttributeInt16* getMaxTempExperienced();
    AttributeUInt16* getOverTempTotalDwell();
    AttributeUInt8* getDevTempAlarmMask();
    AttributeInt16* getLowTempThres();
    AttributeInt16* getHighTempThres();
    AttributeUInt24* getLowTempDwellTripPoint();
    AttributeUInt24* getHighTempDwellTripPoint();
};

enum class GenIdentifyAttribute: uint16_t {
    IdentifyTime = 0,
    IdentifyCommissionState = 1,
};

class GenIdentifyCluster: public Cluster {
public:
    GenIdentifyCluster(ClusterType type = ClusterType::Input) : Cluster(3, type) {
    }
    AttributeUInt16* getIdentifyTime();

    virtual Status onIdentifyCommand(uint16_t identifytime) {
        return Status::UnsupportedAttribute;
    }

    void sendIdentifyCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t identifytime);

    virtual Status onIdentifyQueryCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendIdentifyQueryCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onEzmodeInvokeCommand(uint8_t action) {
        return Status::UnsupportedAttribute;
    }

    void sendEzmodeInvokeCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t action);

    virtual Status onUpdateCommissionStateCommand(uint8_t action, uint8_t commstatemask) {
        return Status::UnsupportedAttribute;
    }

    void sendUpdateCommissionStateCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t action, uint8_t commstatemask);

    virtual Status onTriggerEffectCommand(uint8_t effectid, uint8_t effectvariant) {
        return Status::UnsupportedAttribute;
    }

    void sendTriggerEffectCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t effectid, uint8_t effectvariant);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class GenGroupsAttribute: uint16_t {
    NameSupport = 0,
};

class GenGroupsCluster: public Cluster {
public:
    GenGroupsCluster(ClusterType type = ClusterType::Input) : Cluster(4, type) {
    }
    AttributeUInt8* getNameSupport();

    class AddCommandResponse {
        uint8_t _status{};
        uint16_t _groupid{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

        uint16_t getGroupid() { return _groupid; }
        void setGroupid(uint16_t groupid) { _groupid = groupid; }

    };

    virtual Status onAddCommand(uint16_t groupid, String groupname, AddCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status onViewCommand(uint16_t groupid) {
        return Status::UnsupportedAttribute;
    }

    void sendViewCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t groupid);

    class RemoveCommandResponse {
        uint8_t _status{};
        uint16_t _groupid{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

        uint16_t getGroupid() { return _groupid; }
        void setGroupid(uint16_t groupid) { _groupid = groupid; }

    };

    virtual Status onRemoveCommand(uint16_t groupid, RemoveCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status onRemoveAllCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendRemoveAllCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onAddIfIdentifyingCommand(uint16_t groupid, String groupname) {
        return Status::UnsupportedAttribute;
    }

    void sendAddIfIdentifyingCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t groupid, String groupname);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class GenScenesAttribute: uint16_t {
    Count = 0,
    CurrentScene = 1,
    CurrentGroup = 2,
    SceneValid = 3,
    NameSupport = 4,
    LastCfgBy = 5,
};

class GenScenesCluster: public Cluster {
public:
    GenScenesCluster(ClusterType type = ClusterType::Input) : Cluster(5, type) {
    }
    AttributeUInt8* getCount();
    AttributeUInt8* getCurrentScene();
    AttributeUInt16* getCurrentGroup();
    AttributeUInt8* getSceneValid();
    AttributeUInt8* getNameSupport();
    AttributeUInt64* getLastCfgBy();

    class RemoveCommandResponse {
        uint8_t _status{};
        uint16_t _groupid{};
        uint8_t _sceneid{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

        uint16_t getGroupid() { return _groupid; }
        void setGroupid(uint16_t groupid) { _groupid = groupid; }

        uint8_t getSceneid() { return _sceneid; }
        void setSceneid(uint8_t sceneid) { _sceneid = sceneid; }

    };

    virtual Status onRemoveCommand(uint16_t groupid, uint8_t sceneid, RemoveCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class RemoveAllCommandResponse {
        uint8_t _status{};
        uint16_t _groupid{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

        uint16_t getGroupid() { return _groupid; }
        void setGroupid(uint16_t groupid) { _groupid = groupid; }

    };

    virtual Status onRemoveAllCommand(uint16_t groupid, RemoveAllCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class StoreCommandResponse {
        uint8_t _status{};
        uint16_t _groupid{};
        uint8_t _sceneid{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

        uint16_t getGroupid() { return _groupid; }
        void setGroupid(uint16_t groupid) { _groupid = groupid; }

        uint8_t getSceneid() { return _sceneid; }
        void setSceneid(uint8_t sceneid) { _sceneid = sceneid; }

    };

    virtual Status onStoreCommand(uint16_t groupid, uint8_t sceneid, StoreCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status onRecallCommand(uint16_t groupid, uint8_t sceneid) {
        return Status::UnsupportedAttribute;
    }

    void sendRecallCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t groupid, uint8_t sceneid);

    class CopyCommandResponse {
        uint8_t _status{};
        uint16_t _groupidfrom{};
        uint8_t _sceneidfrom{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

        uint16_t getGroupidfrom() { return _groupidfrom; }
        void setGroupidfrom(uint16_t groupidfrom) { _groupidfrom = groupidfrom; }

        uint8_t getSceneidfrom() { return _sceneidfrom; }
        void setSceneidfrom(uint8_t sceneidfrom) { _sceneidfrom = sceneidfrom; }

    };

    virtual Status onCopyCommand(uint8_t mode, uint16_t groupidfrom, uint8_t sceneidfrom, uint16_t groupidto, uint8_t sceneidto, CopyCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status onTradfriArrowSingleCommand(uint16_t value, uint16_t value2) {
        return Status::UnsupportedAttribute;
    }

    void sendTradfriArrowSingleCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t value, uint16_t value2);

    virtual Status onTradfriArrowHoldCommand(uint16_t value) {
        return Status::UnsupportedAttribute;
    }

    void sendTradfriArrowHoldCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t value);

    virtual Status onTradfriArrowReleaseCommand(uint16_t value) {
        return Status::UnsupportedAttribute;
    }

    void sendTradfriArrowReleaseCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t value);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class GenOnOffAttribute: uint16_t {
    OnOff = 0,
    GlobalSceneCtrl = 16384,
    OnTime = 16385,
    OffWaitTime = 16386,
    StartUpOnOff = 16387,
    TuyaBacklightSwitch = 20480,
    TuyaBacklightMode = 32769,
    MoesStartUpOnOff = 32770,
    TuyaOperationMode = 32772,
    ElkoPreWarningTime = 57344,
    ElkoOnTimeReload = 57345,
    ElkoOnTimeReloadOptions = 57346,
    NodonTransitionTime = 1,
};

class GenOnOffCluster: public Cluster {
public:
    GenOnOffCluster(ClusterType type = ClusterType::Input) : Cluster(6, type) {
    }
    AttributeUInt8* getOnOff();
    AttributeUInt8* getGlobalSceneCtrl();
    AttributeUInt16* getOnTime();
    AttributeUInt16* getOffWaitTime();
    AttributeUInt8* getStartUpOnOff();
    AttributeUInt8* getMoesStartUpOnOff();

    virtual Status onOffCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendOffCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onOnCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendOnCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onToggleCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendToggleCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onOffWithEffectCommand(uint8_t effectid, uint8_t effectvariant) {
        return Status::UnsupportedAttribute;
    }

    void sendOffWithEffectCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t effectid, uint8_t effectvariant);

    virtual Status onOnWithRecallGlobalSceneCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendOnWithRecallGlobalSceneCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onOnWithTimedOffCommand(uint8_t ctrlbits, uint16_t ontime, uint16_t offwaittime) {
        return Status::UnsupportedAttribute;
    }

    void sendOnWithTimedOffCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t ctrlbits, uint16_t ontime, uint16_t offwaittime);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class GenOnOffSwitchCfgAttribute: uint16_t {
    SwitchType = 0,
    SwitchMultiFunction = 2,
    SwitchActions = 16,
};

class GenOnOffSwitchCfgCluster: public Cluster {
public:
    GenOnOffSwitchCfgCluster(ClusterType type = ClusterType::Input) : Cluster(7, type) {
    }
    AttributeUInt8* getSwitchType();
    AttributeUInt8* getSwitchActions();
};

enum class GenLevelCtrlAttribute: uint16_t {
    CurrentLevel = 0,
    RemainingTime = 1,
    MinLevel = 2,
    MaxLevel = 3,
    Options = 15,
    OnOffTransitionTime = 16,
    OnLevel = 17,
    OnTransitionTime = 18,
    OffTransitionTime = 19,
    DefaultMoveRate = 20,
    StartUpCurrentLevel = 16384,
    ElkoStartUpCurrentLevel = 16384,
    UbisysMinimumOnLevel = 0,
    UbisysValveType = 1,
    UbisysCyclePeriod = 2,
    UbisysSeason = 3,
    UbisysBackupLevel = 4,
    UbisysAlternateBackupLevel = 5,
    UbisysLowerRange = 6,
    UbisysUpperRange = 7,
    UbisysPumpThresholdOn = 8,
    UbisysPumpThresholdOff = 9,
    UbisysHeatingDemandEnableThreshold = 10,
    UbisysHeatingDemandDisableThreshold = 11,
    UbisysCoolingDemandEnableThreshold = 12,
    UbisysCoolingDemandDisableThreshold = 13,
};

class GenLevelCtrlCluster: public Cluster {
public:
    GenLevelCtrlCluster(ClusterType type = ClusterType::Input) : Cluster(8, type) {
    }
    AttributeUInt8* getCurrentLevel();
    AttributeUInt16* getRemainingTime();
    AttributeUInt8* getMinLevel();
    AttributeUInt8* getMaxLevel();
    AttributeUInt8* getOptions();
    AttributeUInt16* getOnOffTransitionTime();
    AttributeUInt8* getOnLevel();
    AttributeUInt16* getOnTransitionTime();
    AttributeUInt16* getOffTransitionTime();
    AttributeUInt16* getDefaultMoveRate();
    AttributeUInt8* getStartUpCurrentLevel();

    virtual Status onMoveToLevelCommand(uint8_t level, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveToLevelCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t level, uint16_t transtime);

    virtual Status onMoveCommand(uint8_t movemode, uint8_t rate) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t movemode, uint8_t rate);

    virtual Status onStepCommand(uint8_t stepmode, uint8_t stepsize, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendStepCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t stepmode, uint8_t stepsize, uint16_t transtime);

    virtual Status onStopCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendStopCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onMoveToLevelWithOnOffCommand(uint8_t level, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveToLevelWithOnOffCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t level, uint16_t transtime);

    virtual Status onMoveWithOnOffCommand(uint8_t movemode, uint8_t rate) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveWithOnOffCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t movemode, uint8_t rate);

    virtual Status onStepWithOnOffCommand(uint8_t stepmode, uint8_t stepsize, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendStepWithOnOffCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t stepmode, uint8_t stepsize, uint16_t transtime);

    virtual Status onStopWithOnOffCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendStopWithOnOffCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onMoveToLevelTuyaCommand(uint16_t level, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveToLevelTuyaCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t level, uint16_t transtime);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class GenAlarmsAttribute: uint16_t {
    AlarmCount = 0,
};

class GenAlarmsCluster: public Cluster {
public:
    GenAlarmsCluster(ClusterType type = ClusterType::Input) : Cluster(9, type) {
    }
    AttributeUInt16* getAlarmCount();

    virtual Status onResetCommand(uint8_t alarmcode, uint16_t clusterid) {
        return Status::UnsupportedAttribute;
    }

    void sendResetCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t alarmcode, uint16_t clusterid);

    virtual Status onResetAllCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendResetAllCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onGetAlarmCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendGetAlarmCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onResetLogCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendResetLogCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onPublishEventLogCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendPublishEventLogCommand(DeviceManager& deviceManager, uint8_t endpointId);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class GenTimeAttribute: uint16_t {
    Time = 0,
    TimeStatus = 1,
    TimeZone = 2,
    DstStart = 3,
    DstEnd = 4,
    DstShift = 5,
    StandardTime = 6,
    LocalTime = 7,
    LastSetTime = 8,
    ValidUntilTime = 9,
};

class GenTimeCluster: public Cluster {
public:
    GenTimeCluster(ClusterType type = ClusterType::Input) : Cluster(10, type) {
    }
    AttributeUInt32* getTime();
    AttributeUInt8* getTimeStatus();
    AttributeInt32* getTimeZone();
    AttributeUInt32* getDstStart();
    AttributeUInt32* getDstEnd();
    AttributeInt32* getDstShift();
    AttributeUInt32* getStandardTime();
    AttributeUInt32* getLocalTime();
    AttributeUInt32* getLastSetTime();
    AttributeUInt32* getValidUntilTime();
};

enum class GenRssiLocationAttribute: uint16_t {
    Type = 0,
    Method = 1,
    Age = 2,
    QualityMeasure = 3,
    NumOfDevices = 4,
    Coordinate1 = 16,
    Coordinate2 = 17,
    Coordinate3 = 18,
    Power = 19,
    PathLossExponent = 20,
    ReportingPeriod = 21,
    CalcPeriod = 22,
    NumRSSIMeasurements = 23,
};

class GenRssiLocationCluster: public Cluster {
public:
    GenRssiLocationCluster(ClusterType type = ClusterType::Input) : Cluster(11, type) {
    }
    AttributeUInt8* getType();
    AttributeUInt8* getMethod();
    AttributeUInt16* getAge();
    AttributeUInt8* getQualityMeasure();
    AttributeUInt8* getNumOfDevices();
    AttributeInt16* getCoordinate1();
    AttributeInt16* getCoordinate2();
    AttributeInt16* getCoordinate3();
    AttributeInt16* getPower();
    AttributeUInt16* getPathLossExponent();
    AttributeUInt16* getReportingPeriod();
    AttributeUInt16* getCalcPeriod();
    AttributeUInt16* getNumRSSIMeasurements();

    virtual Status onSetAbsoluteCommand(int16_t coord1, int16_t coord2, int16_t coord3, int16_t power, uint16_t pathlossexponent) {
        return Status::UnsupportedAttribute;
    }

    void sendSetAbsoluteCommand(DeviceManager& deviceManager, uint8_t endpointId, int16_t coord1, int16_t coord2, int16_t coord3, int16_t power, uint16_t pathlossexponent);

    virtual Status onSetDevCfgCommand(int16_t power, uint16_t pathlossexponent, uint16_t calperiod, uint8_t numrssimeasurements, uint16_t reportingperiod) {
        return Status::UnsupportedAttribute;
    }

    void sendSetDevCfgCommand(DeviceManager& deviceManager, uint8_t endpointId, int16_t power, uint16_t pathlossexponent, uint16_t calperiod, uint8_t numrssimeasurements, uint16_t reportingperiod);

    virtual Status onGetDevCfgCommand(uint64_t targetaddr) {
        return Status::UnsupportedAttribute;
    }

    void sendGetDevCfgCommand(DeviceManager& deviceManager, uint8_t endpointId, uint64_t targetaddr);

    virtual Status onGetDataCommand(uint8_t getdatainfo, uint8_t numrsp, uint64_t targetaddr) {
        return Status::UnsupportedAttribute;
    }

    void sendGetDataCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t getdatainfo, uint8_t numrsp, uint64_t targetaddr);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class GenAnalogInputAttribute: uint16_t {
    Description = 28,
    MaxPresentValue = 65,
    MinPresentValue = 69,
    OutOfService = 81,
    PresentValue = 85,
    Reliability = 103,
    Resolution = 106,
    StatusFlags = 111,
    EngineeringUnits = 117,
    ApplicationType = 256,
};

class GenAnalogInputCluster: public Cluster {
public:
    GenAnalogInputCluster(ClusterType type = ClusterType::Input) : Cluster(12, type) {
    }
    AttributeString* getDescription();
    AttributeSingle* getMaxPresentValue();
    AttributeSingle* getMinPresentValue();
    AttributeUInt8* getOutOfService();
    AttributeSingle* getPresentValue();
    AttributeUInt8* getReliability();
    AttributeSingle* getResolution();
    AttributeUInt8* getStatusFlags();
    AttributeUInt16* getEngineeringUnits();
    AttributeUInt32* getApplicationType();
};

enum class GenAnalogOutputAttribute: uint16_t {
    Description = 28,
    MaxPresentValue = 65,
    MinPresentValue = 69,
    OutOfService = 81,
    PresentValue = 85,
    PriorityArray = 87,
    Reliability = 103,
    RelinquishDefault = 104,
    Resolution = 106,
    StatusFlags = 111,
    EngineeringUnits = 117,
    ApplicationType = 256,
};

class GenAnalogOutputCluster: public Cluster {
public:
    GenAnalogOutputCluster(ClusterType type = ClusterType::Input) : Cluster(13, type) {
    }
    AttributeString* getDescription();
    AttributeSingle* getMaxPresentValue();
    AttributeSingle* getMinPresentValue();
    AttributeUInt8* getOutOfService();
    AttributeSingle* getPresentValue();
    AttributeUInt8* getReliability();
    AttributeSingle* getRelinquishDefault();
    AttributeSingle* getResolution();
    AttributeUInt8* getStatusFlags();
    AttributeUInt16* getEngineeringUnits();
    AttributeUInt32* getApplicationType();
};

enum class GenAnalogValueAttribute: uint16_t {
    Description = 28,
    OutOfService = 81,
    PresentValue = 85,
    PriorityArray = 87,
    Reliability = 103,
    RelinquishDefault = 104,
    StatusFlags = 111,
    EngineeringUnits = 117,
    ApplicationType = 256,
};

class GenAnalogValueCluster: public Cluster {
public:
    GenAnalogValueCluster(ClusterType type = ClusterType::Input) : Cluster(14, type) {
    }
    AttributeString* getDescription();
    AttributeUInt8* getOutOfService();
    AttributeSingle* getPresentValue();
    AttributeUInt8* getReliability();
    AttributeSingle* getRelinquishDefault();
    AttributeUInt8* getStatusFlags();
    AttributeUInt16* getEngineeringUnits();
    AttributeUInt32* getApplicationType();
};

enum class GenBinaryInputAttribute: uint16_t {
    ActiveText = 4,
    Description = 28,
    InactiveText = 46,
    OutOfService = 81,
    Polarity = 84,
    PresentValue = 85,
    Reliability = 103,
    StatusFlags = 111,
    ApplicationType = 256,
};

class GenBinaryInputCluster: public Cluster {
public:
    GenBinaryInputCluster(ClusterType type = ClusterType::Input) : Cluster(15, type) {
    }
    AttributeString* getActiveText();
    AttributeString* getDescription();
    AttributeString* getInactiveText();
    AttributeUInt8* getOutOfService();
    AttributeUInt8* getPolarity();
    AttributeUInt8* getPresentValue();
    AttributeUInt8* getReliability();
    AttributeUInt8* getStatusFlags();
    AttributeUInt32* getApplicationType();
};

enum class GenBinaryOutputAttribute: uint16_t {
    ActiveText = 4,
    Description = 28,
    InactiveText = 46,
    MinimumOffTime = 66,
    MinimumOnTime = 67,
    OutOfService = 81,
    Polarity = 84,
    PresentValue = 85,
    PriorityArray = 87,
    Reliability = 103,
    RelinquishDefault = 104,
    StatusFlags = 111,
    ApplicationType = 256,
};

class GenBinaryOutputCluster: public Cluster {
public:
    GenBinaryOutputCluster(ClusterType type = ClusterType::Input) : Cluster(16, type) {
    }
    AttributeString* getActiveText();
    AttributeString* getDescription();
    AttributeString* getInactiveText();
    AttributeUInt32* getMinimumOffTime();
    AttributeUInt32* getMinimumOnTime();
    AttributeUInt8* getOutOfService();
    AttributeUInt8* getPolarity();
    AttributeUInt8* getPresentValue();
    AttributeUInt8* getReliability();
    AttributeUInt8* getRelinquishDefault();
    AttributeUInt8* getStatusFlags();
    AttributeUInt32* getApplicationType();
};

enum class GenBinaryValueAttribute: uint16_t {
    ActiveText = 4,
    Description = 28,
    InactiveText = 46,
    MinimumOffTime = 66,
    MinimumOnTime = 67,
    OutOfService = 81,
    PresentValue = 85,
    PriorityArray = 87,
    Reliability = 103,
    RelinquishDefault = 104,
    StatusFlags = 111,
    ApplicationType = 256,
};

class GenBinaryValueCluster: public Cluster {
public:
    GenBinaryValueCluster(ClusterType type = ClusterType::Input) : Cluster(17, type) {
    }
    AttributeString* getActiveText();
    AttributeString* getDescription();
    AttributeString* getInactiveText();
    AttributeUInt32* getMinimumOffTime();
    AttributeUInt32* getMinimumOnTime();
    AttributeUInt8* getOutOfService();
    AttributeUInt8* getPresentValue();
    AttributeUInt8* getReliability();
    AttributeUInt8* getRelinquishDefault();
    AttributeUInt8* getStatusFlags();
    AttributeUInt32* getApplicationType();
};

enum class GenMultistateInputAttribute: uint16_t {
    StateText = 14,
    Description = 28,
    NumberOfStates = 74,
    OutOfService = 81,
    PresentValue = 85,
    Reliability = 103,
    StatusFlags = 111,
    ApplicationType = 256,
};

class GenMultistateInputCluster: public Cluster {
public:
    GenMultistateInputCluster(ClusterType type = ClusterType::Input) : Cluster(18, type) {
    }
    AttributeString* getDescription();
    AttributeUInt16* getNumberOfStates();
    AttributeUInt8* getOutOfService();
    AttributeUInt16* getPresentValue();
    AttributeUInt8* getReliability();
    AttributeUInt8* getStatusFlags();
    AttributeUInt32* getApplicationType();
};

enum class GenMultistateOutputAttribute: uint16_t {
    StateText = 14,
    Description = 28,
    NumberOfStates = 74,
    OutOfService = 81,
    PresentValue = 85,
    PriorityArray = 87,
    Reliability = 103,
    RelinquishDefault = 104,
    StatusFlags = 111,
    ApplicationType = 256,
};

class GenMultistateOutputCluster: public Cluster {
public:
    GenMultistateOutputCluster(ClusterType type = ClusterType::Input) : Cluster(19, type) {
    }
    AttributeString* getDescription();
    AttributeUInt16* getNumberOfStates();
    AttributeUInt8* getOutOfService();
    AttributeUInt16* getPresentValue();
    AttributeUInt8* getReliability();
    AttributeUInt16* getRelinquishDefault();
    AttributeUInt8* getStatusFlags();
    AttributeUInt32* getApplicationType();
};

enum class GenMultistateValueAttribute: uint16_t {
    StateText = 14,
    Description = 28,
    NumberOfStates = 74,
    OutOfService = 81,
    PresentValue = 85,
    PriorityArray = 87,
    Reliability = 103,
    RelinquishDefault = 104,
    StatusFlags = 111,
    ApplicationType = 256,
};

class GenMultistateValueCluster: public Cluster {
public:
    GenMultistateValueCluster(ClusterType type = ClusterType::Input) : Cluster(20, type) {
    }
    AttributeString* getDescription();
    AttributeUInt16* getNumberOfStates();
    AttributeUInt8* getOutOfService();
    AttributeUInt16* getPresentValue();
    AttributeUInt8* getReliability();
    AttributeUInt16* getRelinquishDefault();
    AttributeUInt8* getStatusFlags();
    AttributeUInt32* getApplicationType();
};

enum class GenCommissioningAttribute: uint16_t {
    Shortress = 0,
    ExtendedPANId = 1,
    PanId = 2,
    Channelmask = 3,
    ProtocolVersion = 4,
    StackProfile = 5,
    StartupControl = 6,
    TrustCenterress = 16,
    TrustCenterMasterKey = 17,
    NetworkKey = 18,
    UseInsecureJoin = 19,
    PreconfiguredLinkKey = 20,
    NetworkKeySeqNum = 21,
    NetworkKeyType = 22,
    NetworkManagerress = 23,
    ScanAttempts = 32,
    TimeBetweenScans = 33,
    RejoinInterval = 34,
    MaxRejoinInterval = 35,
    IndirectPollRate = 48,
    ParentRetryThreshold = 49,
    ConcentratorFlag = 64,
    ConcentratorRus = 65,
    ConcentratorDiscoveryTime = 66,
};

class GenCommissioningCluster: public Cluster {
public:
    GenCommissioningCluster(ClusterType type = ClusterType::Input) : Cluster(21, type) {
    }
    AttributeUInt16* getShortress();
    AttributeUInt64* getExtendedPANId();
    AttributeUInt16* getPanId();
    AttributeUInt32* getChannelmask();
    AttributeUInt8* getProtocolVersion();
    AttributeUInt8* getStackProfile();
    AttributeUInt8* getStartupControl();
    AttributeUInt64* getTrustCenterress();
    AttributeUInt8* getUseInsecureJoin();
    AttributeUInt8* getNetworkKeySeqNum();
    AttributeUInt8* getNetworkKeyType();
    AttributeUInt16* getNetworkManagerress();
    AttributeUInt8* getScanAttempts();
    AttributeUInt16* getTimeBetweenScans();
    AttributeUInt16* getRejoinInterval();
    AttributeUInt16* getMaxRejoinInterval();
    AttributeUInt16* getIndirectPollRate();
    AttributeUInt8* getParentRetryThreshold();
    AttributeUInt8* getConcentratorFlag();
    AttributeUInt8* getConcentratorRus();
    AttributeUInt8* getConcentratorDiscoveryTime();

    virtual Status onRestartDeviceCommand(uint8_t options, uint8_t delay, uint8_t jitter) {
        return Status::UnsupportedAttribute;
    }

    void sendRestartDeviceCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t options, uint8_t delay, uint8_t jitter);

    virtual Status onSaveStartupParamsCommand(uint8_t options, uint8_t index) {
        return Status::UnsupportedAttribute;
    }

    void sendSaveStartupParamsCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t options, uint8_t index);

    virtual Status onRestoreStartupParamsCommand(uint8_t options, uint8_t index) {
        return Status::UnsupportedAttribute;
    }

    void sendRestoreStartupParamsCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t options, uint8_t index);

    virtual Status onResetStartupParamsCommand(uint8_t options, uint8_t index) {
        return Status::UnsupportedAttribute;
    }

    void sendResetStartupParamsCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t options, uint8_t index);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class GenOtaAttribute: uint16_t {
    UpgradeServerId = 0,
    FileOffset = 1,
    CurrentFileVersion = 2,
    CurrentZigbeeStackVersion = 3,
    DownloadedFileVersion = 4,
    DownloadedZigbeeStackVersion = 5,
    ImageUpgradeStatus = 6,
    ManufacturerId = 7,
    ImageTypeId = 8,
    MinimumBlockReqDelay = 9,
    ImageStamp = 10,
};

class GenOtaCluster: public Cluster {
public:
    GenOtaCluster(ClusterType type = ClusterType::Input) : Cluster(25, type) {
    }
    AttributeUInt64* getUpgradeServerId();
    AttributeUInt32* getFileOffset();
    AttributeUInt32* getCurrentFileVersion();
    AttributeUInt16* getCurrentZigbeeStackVersion();
    AttributeUInt32* getDownloadedFileVersion();
    AttributeUInt16* getDownloadedZigbeeStackVersion();
    AttributeUInt8* getImageUpgradeStatus();
    AttributeUInt16* getManufacturerId();
    AttributeUInt16* getImageTypeId();
    AttributeUInt16* getMinimumBlockReqDelay();
    AttributeUInt32* getImageStamp();

    class QueryNextImageRequestCommandResponse {
        uint8_t _status{};
        uint16_t _manufacturerCode{};
        uint16_t _imageType{};
        uint32_t _fileVersion{};
        uint32_t _imageSize{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

        uint16_t getManufacturerCode() { return _manufacturerCode; }
        void setManufacturerCode(uint16_t manufacturerCode) { _manufacturerCode = manufacturerCode; }

        uint16_t getImageType() { return _imageType; }
        void setImageType(uint16_t imageType) { _imageType = imageType; }

        uint32_t getFileVersion() { return _fileVersion; }
        void setFileVersion(uint32_t fileVersion) { _fileVersion = fileVersion; }

        uint32_t getImageSize() { return _imageSize; }
        void setImageSize(uint32_t imageSize) { _imageSize = imageSize; }

    };

    virtual Status onQueryNextImageRequestCommand(uint8_t fieldControl, uint16_t manufacturerCode, uint16_t imageType, uint32_t fileVersion, QueryNextImageRequestCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class UpgradeEndRequestCommandResponse {
        uint16_t _manufacturerCode{};
        uint16_t _imageType{};
        uint32_t _fileVersion{};
        uint32_t _currentTime{};
        uint32_t _upgradeTime{};

    public:
        uint16_t getManufacturerCode() { return _manufacturerCode; }
        void setManufacturerCode(uint16_t manufacturerCode) { _manufacturerCode = manufacturerCode; }

        uint16_t getImageType() { return _imageType; }
        void setImageType(uint16_t imageType) { _imageType = imageType; }

        uint32_t getFileVersion() { return _fileVersion; }
        void setFileVersion(uint32_t fileVersion) { _fileVersion = fileVersion; }

        uint32_t getCurrentTime() { return _currentTime; }
        void setCurrentTime(uint32_t currentTime) { _currentTime = currentTime; }

        uint32_t getUpgradeTime() { return _upgradeTime; }
        void setUpgradeTime(uint32_t upgradeTime) { _upgradeTime = upgradeTime; }

    };

    virtual Status onUpgradeEndRequestCommand(uint8_t status, uint16_t manufacturerCode, uint16_t imageType, uint32_t fileVersion, UpgradeEndRequestCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class GenPollCtrlAttribute: uint16_t {
    CheckinInterval = 0,
    LongPollInterval = 1,
    ShortPollInterval = 2,
    FastPollTimeout = 3,
    CheckinIntervalMin = 4,
    LongPollIntervalMin = 5,
    FastPollTimeoutMax = 6,
};

class GenPollCtrlCluster: public Cluster {
public:
    GenPollCtrlCluster(ClusterType type = ClusterType::Input) : Cluster(32, type) {
    }
    AttributeUInt32* getCheckinInterval();
    AttributeUInt32* getLongPollInterval();
    AttributeUInt16* getShortPollInterval();
    AttributeUInt16* getFastPollTimeout();
    AttributeUInt32* getCheckinIntervalMin();
    AttributeUInt32* getLongPollIntervalMin();
    AttributeUInt16* getFastPollTimeoutMax();

    virtual Status onCheckinRspCommand(bool startFastPolling, uint16_t fastPollTimeout) {
        return Status::UnsupportedAttribute;
    }

    void sendCheckinRspCommand(DeviceManager& deviceManager, uint8_t endpointId, bool startFastPolling, uint16_t fastPollTimeout);

    virtual Status onFastPollStopCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendFastPollStopCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onSetLongPollIntervalCommand(uint32_t newLongPollInterval) {
        return Status::UnsupportedAttribute;
    }

    void sendSetLongPollIntervalCommand(DeviceManager& deviceManager, uint8_t endpointId, uint32_t newLongPollInterval);

    virtual Status onSetShortPollIntervalCommand(uint16_t newShortPollInterval) {
        return Status::UnsupportedAttribute;
    }

    void sendSetShortPollIntervalCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t newShortPollInterval);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class GreenPowerAttribute: uint16_t {
};

class GreenPowerCluster: public Cluster {
public:
    GreenPowerCluster(ClusterType type = ClusterType::Input) : Cluster(33, type) {
    }
};

enum class MobileDeviceCfgAttribute: uint16_t {
    KeepAliveTime = 0,
    RejoinTimeout = 1,
};

class MobileDeviceCfgCluster: public Cluster {
public:
    MobileDeviceCfgCluster(ClusterType type = ClusterType::Input) : Cluster(34, type) {
    }
    AttributeUInt16* getKeepAliveTime();
    AttributeUInt16* getRejoinTimeout();
};

enum class NeighborCleaningAttribute: uint16_t {
    NeighborCleaningTimeout = 0,
};

class NeighborCleaningCluster: public Cluster {
public:
    NeighborCleaningCluster(ClusterType type = ClusterType::Input) : Cluster(35, type) {
    }
    AttributeUInt16* getNeighborCleaningTimeout();
};

enum class NearestGatewayAttribute: uint16_t {
    NearestGateway = 0,
    NewMobileNode = 1,
};

class NearestGatewayCluster: public Cluster {
public:
    NearestGatewayCluster(ClusterType type = ClusterType::Input) : Cluster(36, type) {
    }
    AttributeUInt16* getNearestGateway();
    AttributeUInt16* getNewMobileNode();
};

enum class ClosuresShadeCfgAttribute: uint16_t {
    PhysicalClosedLimit = 0,
    MotorStepSize = 1,
    Status = 2,
    LosedLimit = 16,
    Mode = 18,
};

class ClosuresShadeCfgCluster: public Cluster {
public:
    ClosuresShadeCfgCluster(ClusterType type = ClusterType::Input) : Cluster(256, type) {
    }
    AttributeUInt16* getPhysicalClosedLimit();
    AttributeUInt8* getMotorStepSize();
    AttributeUInt8* getStatus();
    AttributeUInt16* getLosedLimit();
    AttributeUInt8* getMode();
};

enum class ClosuresDoorLockAttribute: uint16_t {
    LockState = 0,
    LockType = 38,
    ActuatorEnabled = 2,
    DoorState = 3,
    DoorOpenEvents = 4,
    DoorClosedEvents = 5,
    OpenPeriod = 6,
    NumOfLockRecordsSupported = 16,
    NumOfTotalUsersSupported = 17,
    NumOfPinUsersSupported = 18,
    NumOfRfidUsersSupported = 19,
    NumOfWeekDaySchedulesSupportedPerUser = 20,
    NumOfYearDaySchedulesSupportedPerUser = 21,
    NumOfHolidayScheduledsSupported = 22,
    MaxPinLen = 23,
    MinPinLen = 24,
    MaxRfidLen = 25,
    MinRfidLen = 26,
    EnableLogging = 32,
    Language = 33,
    LedSettings = 34,
    AutoRelockTime = 35,
    SoundVolume = 36,
    OperatingMode = 37,
    DefaultConfigurationRegister = 39,
    EnableLocalProgramming = 40,
    EnableOneTouchLocking = 41,
    EnableInsideStatusLed = 42,
    EnablePrivacyModeButton = 43,
    WrongCodeEntryLimit = 48,
    UserCodeTemporaryDisableTime = 49,
    SendPinOta = 50,
    RequirePinForRfOperation = 51,
    ZigbeeSecurityLevel = 52,
    AlarmMask = 64,
    KeypadOperationEventMask = 65,
    RfOperationEventMask = 66,
    ManualOperationEventMask = 67,
    RfidOperationEventMask = 68,
    KeypadProgrammingEventMask = 69,
    RfProgrammingEventMask = 70,
    RfidProgrammingEventMask = 71,
};

class ClosuresDoorLockCluster: public Cluster {
public:
    ClosuresDoorLockCluster(ClusterType type = ClusterType::Input) : Cluster(257, type) {
    }
    AttributeUInt8* getLockState();
    AttributeUInt16* getLockType();
    AttributeUInt8* getActuatorEnabled();
    AttributeUInt8* getDoorState();
    AttributeUInt32* getDoorOpenEvents();
    AttributeUInt32* getDoorClosedEvents();
    AttributeUInt16* getOpenPeriod();
    AttributeUInt16* getNumOfLockRecordsSupported();
    AttributeUInt16* getNumOfTotalUsersSupported();
    AttributeUInt16* getNumOfPinUsersSupported();
    AttributeUInt16* getNumOfRfidUsersSupported();
    AttributeUInt8* getNumOfWeekDaySchedulesSupportedPerUser();
    AttributeUInt8* getNumOfYearDaySchedulesSupportedPerUser();
    AttributeUInt8* getNumOfHolidayScheduledsSupported();
    AttributeUInt8* getMaxPinLen();
    AttributeUInt8* getMinPinLen();
    AttributeUInt8* getMaxRfidLen();
    AttributeUInt8* getMinRfidLen();
    AttributeUInt8* getEnableLogging();
    AttributeString* getLanguage();
    AttributeUInt8* getLedSettings();
    AttributeUInt32* getAutoRelockTime();
    AttributeUInt8* getSoundVolume();
    AttributeUInt32* getOperatingMode();
    AttributeUInt16* getDefaultConfigurationRegister();
    AttributeUInt8* getEnableLocalProgramming();
    AttributeUInt8* getEnableOneTouchLocking();
    AttributeUInt8* getEnableInsideStatusLed();
    AttributeUInt8* getEnablePrivacyModeButton();
    AttributeUInt8* getWrongCodeEntryLimit();
    AttributeUInt8* getUserCodeTemporaryDisableTime();
    AttributeUInt8* getSendPinOta();
    AttributeUInt8* getRequirePinForRfOperation();
    AttributeUInt8* getZigbeeSecurityLevel();
    AttributeUInt16* getAlarmMask();
    AttributeUInt16* getKeypadOperationEventMask();
    AttributeUInt16* getRfOperationEventMask();
    AttributeUInt16* getManualOperationEventMask();
    AttributeUInt16* getRfidOperationEventMask();
    AttributeUInt16* getKeypadProgrammingEventMask();
    AttributeUInt16* getRfProgrammingEventMask();
    AttributeUInt16* getRfidProgrammingEventMask();

    class LockDoorCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onLockDoorCommand(String pincodevalue, LockDoorCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class UnlockDoorCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onUnlockDoorCommand(String pincodevalue, UnlockDoorCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ToggleDoorCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onToggleDoorCommand(String pincodevalue, ToggleDoorCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class UnlockWithTimeoutCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onUnlockWithTimeoutCommand(uint16_t timeout, String pincodevalue, UnlockWithTimeoutCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetLogRecordCommandResponse {
        uint16_t _logentryid{};
        uint32_t _timestamp{};
        uint8_t _eventtype{};
        uint8_t _source{};
        uint8_t _eventidalarmcode{};
        uint16_t _userid{};
        String _pincodevalue{};

    public:
        uint16_t getLogentryid() { return _logentryid; }
        void setLogentryid(uint16_t logentryid) { _logentryid = logentryid; }

        uint32_t getTimestamp() { return _timestamp; }
        void setTimestamp(uint32_t timestamp) { _timestamp = timestamp; }

        uint8_t getEventtype() { return _eventtype; }
        void setEventtype(uint8_t eventtype) { _eventtype = eventtype; }

        uint8_t getSource() { return _source; }
        void setSource(uint8_t source) { _source = source; }

        uint8_t getEventidalarmcode() { return _eventidalarmcode; }
        void setEventidalarmcode(uint8_t eventidalarmcode) { _eventidalarmcode = eventidalarmcode; }

        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t userid) { _userid = userid; }

        String getPincodevalue() { return _pincodevalue; }
        void setPincodevalue(const String& pincodevalue) { _pincodevalue = pincodevalue; }

    };

    virtual Status onGetLogRecordCommand(uint16_t logindex, GetLogRecordCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetPinCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onSetPinCodeCommand(uint16_t userid, uint8_t userstatus, uint8_t usertype, String pincodevalue, SetPinCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetPinCodeCommandResponse {
        uint16_t _userid{};
        uint8_t _userstatus{};
        uint8_t _usertype{};
        String _pincodevalue{};

    public:
        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t userid) { _userid = userid; }

        uint8_t getUserstatus() { return _userstatus; }
        void setUserstatus(uint8_t userstatus) { _userstatus = userstatus; }

        uint8_t getUsertype() { return _usertype; }
        void setUsertype(uint8_t usertype) { _usertype = usertype; }

        String getPincodevalue() { return _pincodevalue; }
        void setPincodevalue(const String& pincodevalue) { _pincodevalue = pincodevalue; }

    };

    virtual Status onGetPinCodeCommand(uint16_t userid, GetPinCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearPinCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onClearPinCodeCommand(uint16_t userid, ClearPinCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearAllPinCodesCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onClearAllPinCodesCommand(ClearAllPinCodesCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetUserStatusCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onSetUserStatusCommand(uint16_t userid, uint8_t userstatus, SetUserStatusCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetUserStatusCommandResponse {
        uint16_t _userid{};
        uint8_t _userstatus{};

    public:
        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t userid) { _userid = userid; }

        uint8_t getUserstatus() { return _userstatus; }
        void setUserstatus(uint8_t userstatus) { _userstatus = userstatus; }

    };

    virtual Status onGetUserStatusCommand(uint16_t userid, GetUserStatusCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetWeekDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onSetWeekDayScheduleCommand(uint8_t scheduleid, uint16_t userid, uint8_t daysmask, uint8_t starthour, uint8_t startminute, uint8_t endhour, uint8_t endminute, SetWeekDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetWeekDayScheduleCommandResponse {
        uint8_t _scheduleid{};
        uint16_t _userid{};
        uint8_t _status{};
        uint8_t _daysmask{};
        uint8_t _starthour{};
        uint8_t _startminute{};
        uint8_t _endhour{};
        uint8_t _endminute{};

    public:
        uint8_t getScheduleid() { return _scheduleid; }
        void setScheduleid(uint8_t scheduleid) { _scheduleid = scheduleid; }

        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t userid) { _userid = userid; }

        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

        uint8_t getDaysmask() { return _daysmask; }
        void setDaysmask(uint8_t daysmask) { _daysmask = daysmask; }

        uint8_t getStarthour() { return _starthour; }
        void setStarthour(uint8_t starthour) { _starthour = starthour; }

        uint8_t getStartminute() { return _startminute; }
        void setStartminute(uint8_t startminute) { _startminute = startminute; }

        uint8_t getEndhour() { return _endhour; }
        void setEndhour(uint8_t endhour) { _endhour = endhour; }

        uint8_t getEndminute() { return _endminute; }
        void setEndminute(uint8_t endminute) { _endminute = endminute; }

    };

    virtual Status onGetWeekDayScheduleCommand(uint8_t scheduleid, uint16_t userid, GetWeekDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearWeekDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onClearWeekDayScheduleCommand(uint8_t scheduleid, uint16_t userid, ClearWeekDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetYearDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onSetYearDayScheduleCommand(uint8_t scheduleid, uint16_t userid, uint32_t zigbeelocalstarttime, uint32_t zigbeelocalendtime, SetYearDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetYearDayScheduleCommandResponse {
        uint8_t _scheduleid{};
        uint16_t _userid{};
        uint8_t _status{};
        uint32_t _zigbeelocalstarttime{};
        uint32_t _zigbeelocalendtime{};

    public:
        uint8_t getScheduleid() { return _scheduleid; }
        void setScheduleid(uint8_t scheduleid) { _scheduleid = scheduleid; }

        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t userid) { _userid = userid; }

        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

        uint32_t getZigbeelocalstarttime() { return _zigbeelocalstarttime; }
        void setZigbeelocalstarttime(uint32_t zigbeelocalstarttime) { _zigbeelocalstarttime = zigbeelocalstarttime; }

        uint32_t getZigbeelocalendtime() { return _zigbeelocalendtime; }
        void setZigbeelocalendtime(uint32_t zigbeelocalendtime) { _zigbeelocalendtime = zigbeelocalendtime; }

    };

    virtual Status onGetYearDayScheduleCommand(uint8_t scheduleid, uint16_t userid, GetYearDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearYearDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onClearYearDayScheduleCommand(uint8_t scheduleid, uint16_t userid, ClearYearDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetHolidayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onSetHolidayScheduleCommand(uint8_t holidayscheduleid, uint32_t zigbeelocalstarttime, uint32_t zigbeelocalendtime, uint8_t opermodelduringholiday, SetHolidayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetHolidayScheduleCommandResponse {
        uint8_t _holidayscheduleid{};
        uint8_t _status{};
        uint32_t _zigbeelocalstarttime{};
        uint32_t _zigbeelocalendtime{};
        uint8_t _opermodelduringholiday{};

    public:
        uint8_t getHolidayscheduleid() { return _holidayscheduleid; }
        void setHolidayscheduleid(uint8_t holidayscheduleid) { _holidayscheduleid = holidayscheduleid; }

        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

        uint32_t getZigbeelocalstarttime() { return _zigbeelocalstarttime; }
        void setZigbeelocalstarttime(uint32_t zigbeelocalstarttime) { _zigbeelocalstarttime = zigbeelocalstarttime; }

        uint32_t getZigbeelocalendtime() { return _zigbeelocalendtime; }
        void setZigbeelocalendtime(uint32_t zigbeelocalendtime) { _zigbeelocalendtime = zigbeelocalendtime; }

        uint8_t getOpermodelduringholiday() { return _opermodelduringholiday; }
        void setOpermodelduringholiday(uint8_t opermodelduringholiday) { _opermodelduringholiday = opermodelduringholiday; }

    };

    virtual Status onGetHolidayScheduleCommand(uint8_t holidayscheduleid, GetHolidayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearHolidayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onClearHolidayScheduleCommand(uint8_t holidayscheduleid, ClearHolidayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetUserTypeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onSetUserTypeCommand(uint16_t userid, uint8_t usertype, SetUserTypeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetUserTypeCommandResponse {
        uint16_t _userid{};
        uint8_t _usertype{};

    public:
        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t userid) { _userid = userid; }

        uint8_t getUsertype() { return _usertype; }
        void setUsertype(uint8_t usertype) { _usertype = usertype; }

    };

    virtual Status onGetUserTypeCommand(uint16_t userid, GetUserTypeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetRfidCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onSetRfidCodeCommand(uint16_t userid, uint8_t userstatus, uint8_t usertype, String pincodevalue, SetRfidCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetRfidCodeCommandResponse {
        uint16_t _userid{};
        uint8_t _userstatus{};
        uint8_t _usertype{};
        String _pincodevalue{};

    public:
        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t userid) { _userid = userid; }

        uint8_t getUserstatus() { return _userstatus; }
        void setUserstatus(uint8_t userstatus) { _userstatus = userstatus; }

        uint8_t getUsertype() { return _usertype; }
        void setUsertype(uint8_t usertype) { _usertype = usertype; }

        String getPincodevalue() { return _pincodevalue; }
        void setPincodevalue(const String& pincodevalue) { _pincodevalue = pincodevalue; }

    };

    virtual Status onGetRfidCodeCommand(uint16_t userid, GetRfidCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearRfidCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onClearRfidCodeCommand(uint16_t userid, ClearRfidCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearAllRfidCodesCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status onClearAllRfidCodesCommand(ClearAllRfidCodesCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class ClosuresWindowCoveringAttribute: uint16_t {
    WindowCoveringType = 0,
    PhysicalClosedLimitLiftCm = 1,
    PhysicalClosedLimitTiltDdegree = 2,
    CurrentPositionLiftCm = 3,
    CurrentPositionTiltDdegree = 4,
    NumOfActuationsLift = 5,
    NumOfActuationsTilt = 6,
    ConfigStatus = 7,
    CurrentPositionLiftPercentage = 8,
    CurrentPositionTiltPercentage = 9,
    OperationalStatus = 10,
    InstalledOpenLimitLiftCm = 16,
    InstalledClosedLimitLiftCm = 17,
    InstalledOpenLimitTiltDdegree = 18,
    InstalledClosedLimitTiltDdegree = 19,
    VelocityLift = 20,
    AccelerationTimeLift = 21,
    DecelerationTimeLift = 22,
    WindowCoveringMode = 23,
    IntermediateSetpointsLift = 24,
    IntermediateSetpointsTilt = 25,
    UbisysTurnaroundGuardTime = 4096,
    UbisysLiftToTiltTransitionSteps = 4097,
    UbisysTotalSteps = 4098,
    UbisysLiftToTiltTransitionSteps2 = 4099,
    UbisysTotalSteps2 = 4100,
    UbisysAdditionalSteps = 4101,
    UbisysInactivePowerThreshold = 4102,
    UbisysStartupSteps = 4103,
    TuyaMovingState = 61440,
    TuyaCalibration = 61441,
    StepPositionLift = 61441,
    TuyaMotorReversal = 61442,
    CalibrationMode = 61442,
    MoesCalibrationTime = 61443,
    TargetPositionTiltPercentage = 61443,
    StepPositionTilt = 61444,
    ElkoDriveCloseDuration = 57344,
    ElkoProtectionStatus = 57360,
    ElkoProtectionSensor = 57363,
    ElkoSunProtectionIlluminanceThreshold = 57362,
    ElkoLiftDriveUpTime = 57364,
    ElkoLiftDriveDownTime = 57365,
    ElkoTiltOpenCloseAndStepTime = 57366,
    ElkoTiltPositionPercentageAfterMoveToLevel = 57367,
};

class ClosuresWindowCoveringCluster: public Cluster {
public:
    ClosuresWindowCoveringCluster(ClusterType type = ClusterType::Input) : Cluster(258, type) {
    }
    AttributeUInt8* getWindowCoveringType();
    AttributeUInt16* getPhysicalClosedLimitLiftCm();
    AttributeUInt16* getPhysicalClosedLimitTiltDdegree();
    AttributeUInt16* getCurrentPositionLiftCm();
    AttributeUInt16* getCurrentPositionTiltDdegree();
    AttributeUInt16* getNumOfActuationsLift();
    AttributeUInt16* getNumOfActuationsTilt();
    AttributeUInt8* getConfigStatus();
    AttributeUInt8* getCurrentPositionLiftPercentage();
    AttributeUInt8* getCurrentPositionTiltPercentage();
    AttributeUInt8* getOperationalStatus();
    AttributeUInt16* getInstalledOpenLimitLiftCm();
    AttributeUInt16* getInstalledClosedLimitLiftCm();
    AttributeUInt16* getInstalledOpenLimitTiltDdegree();
    AttributeUInt16* getInstalledClosedLimitTiltDdegree();
    AttributeUInt16* getVelocityLift();
    AttributeUInt16* getAccelerationTimeLift();
    AttributeUInt16* getDecelerationTimeLift();
    AttributeUInt8* getWindowCoveringMode();
    AttributeOctstr* getIntermediateSetpointsLift();
    AttributeOctstr* getIntermediateSetpointsTilt();
    AttributeUInt16* getMoesCalibrationTime();

    virtual Status onUpOpenCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendUpOpenCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onDownCloseCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendDownCloseCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onStopCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendStopCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onGoToLiftValueCommand(uint16_t liftvalue) {
        return Status::UnsupportedAttribute;
    }

    void sendGoToLiftValueCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t liftvalue);

    virtual Status onGoToLiftPercentageCommand(uint8_t percentageliftvalue) {
        return Status::UnsupportedAttribute;
    }

    void sendGoToLiftPercentageCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t percentageliftvalue);

    virtual Status onGoToTiltValueCommand(uint16_t tiltvalue) {
        return Status::UnsupportedAttribute;
    }

    void sendGoToTiltValueCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t tiltvalue);

    virtual Status onGoToTiltPercentageCommand(uint8_t percentagetiltvalue) {
        return Status::UnsupportedAttribute;
    }

    void sendGoToTiltPercentageCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t percentagetiltvalue);

    virtual Status onElkoStopOrStepLiftPercentageCommand(uint16_t direction, uint16_t stepvalue) {
        return Status::UnsupportedAttribute;
    }

    void sendElkoStopOrStepLiftPercentageCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t direction, uint16_t stepvalue);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class BarrierControlAttribute: uint16_t {
    MovingState = 1,
    SafetyStatus = 2,
    Capabilities = 3,
    OpenEvents = 4,
    CloseEvents = 5,
    CommandOpenEvents = 6,
    CommandCloseEvents = 7,
    OpenPeriod = 8,
    ClosePeriod = 9,
    BarrierPosition = 10,
};

class BarrierControlCluster: public Cluster {
public:
    BarrierControlCluster(ClusterType type = ClusterType::Input) : Cluster(259, type) {
    }
    AttributeUInt8* getMovingState();
    AttributeUInt16* getSafetyStatus();
    AttributeUInt8* getCapabilities();
    AttributeUInt16* getOpenEvents();
    AttributeUInt16* getCloseEvents();
    AttributeUInt16* getCommandOpenEvents();
    AttributeUInt16* getCommandCloseEvents();
    AttributeUInt16* getOpenPeriod();
    AttributeUInt16* getClosePeriod();
    AttributeUInt8* getBarrierPosition();

    virtual Status onGoToPercentCommand(uint8_t percentOpen) {
        return Status::UnsupportedAttribute;
    }

    void sendGoToPercentCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t percentOpen);

    virtual Status onStopCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendStopCommand(DeviceManager& deviceManager, uint8_t endpointId);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class HvacPumpCfgCtrlAttribute: uint16_t {
    MaxPressure = 0,
    MaxSpeed = 1,
    MaxFlow = 2,
    MinConstPressure = 3,
    MaxConstPressure = 4,
    MinCompPressure = 5,
    MaxCompPressure = 6,
    MinConstSpeed = 7,
    MaxConstSpeed = 8,
    MinConstFlow = 9,
    MaxConstFlow = 10,
    MinConstTemp = 11,
    MaxConstTemp = 12,
    PumpStatus = 16,
    EffectiveOperationMode = 17,
    EffectiveControlMode = 18,
    Capacity = 19,
    Speed = 20,
    LifetimeRunningHours = 21,
    Power = 22,
    LifetimeEnergyConsumed = 23,
    OperationMode = 32,
    ControlMode = 33,
    AlarmMask = 34,
};

class HvacPumpCfgCtrlCluster: public Cluster {
public:
    HvacPumpCfgCtrlCluster(ClusterType type = ClusterType::Input) : Cluster(512, type) {
    }
    AttributeInt16* getMaxPressure();
    AttributeUInt16* getMaxSpeed();
    AttributeUInt16* getMaxFlow();
    AttributeInt16* getMinConstPressure();
    AttributeInt16* getMaxConstPressure();
    AttributeInt16* getMinCompPressure();
    AttributeInt16* getMaxCompPressure();
    AttributeUInt16* getMinConstSpeed();
    AttributeUInt16* getMaxConstSpeed();
    AttributeUInt16* getMinConstFlow();
    AttributeUInt16* getMaxConstFlow();
    AttributeInt16* getMinConstTemp();
    AttributeInt16* getMaxConstTemp();
    AttributeUInt16* getPumpStatus();
    AttributeUInt8* getEffectiveOperationMode();
    AttributeUInt8* getEffectiveControlMode();
    AttributeInt16* getCapacity();
    AttributeUInt16* getSpeed();
    AttributeUInt24* getLifetimeRunningHours();
    AttributeUInt24* getPower();
    AttributeUInt32* getLifetimeEnergyConsumed();
    AttributeUInt8* getOperationMode();
    AttributeUInt8* getControlMode();
    AttributeUInt16* getAlarmMask();
};

enum class HvacThermostatAttribute: uint16_t {
    LocalTemp = 0,
    OutdoorTemp = 1,
    Occupancy = 2,
    AbsMinHeatSetpointLimit = 3,
    AbsMaxHeatSetpointLimit = 4,
    AbsMinCoolSetpointLimit = 5,
    AbsMaxCoolSetpointLimit = 6,
    PICoolingDemand = 7,
    PIHeatingDemand = 8,
    SystemTypeConfig = 9,
    LocalTemperatureCalibration = 16,
    OccupiedCoolingSetpoint = 17,
    OccupiedHeatingSetpoint = 18,
    UnoccupiedCoolingSetpoint = 19,
    UnoccupiedHeatingSetpoint = 20,
    MinHeatSetpointLimit = 21,
    MaxHeatSetpointLimit = 22,
    MinCoolSetpointLimit = 23,
    MaxCoolSetpointLimit = 24,
    MinSetpointDeadBand = 25,
    RemoteSensing = 26,
    CtrlSeqeOfOper = 27,
    SystemMode = 28,
    AlarmMask = 29,
    RunningMode = 30,
    StartOfWeek = 32,
    NumberOfWeeklyTrans = 33,
    NumberOfDailyTrans = 34,
    TempSetpointHold = 35,
    TempSetpointHoldDuration = 36,
    ProgramingOperMode = 37,
    RunningState = 41,
    SetpointChangeSource = 48,
    SetpointChangeAmount = 49,
    SetpointChangeSourceTimeStamp = 50,
    AcType = 64,
    AcCapacity = 65,
    AcRefrigerantType = 66,
    AcConpressorType = 67,
    AcErrorCode = 68,
    AcLouverPosition = 69,
    AcCollTemp = 70,
    AcCapacityFormat = 71,
    SinopeOccupancy = 1024,
    SinopeMainCycleOutput = 1025,
    SinopeBacklight = 1026,
    SinopeAuxCycleOutput = 1028,
    StelproSystemMode = 16412,
    StelproOutdoorTemp = 16385,
    ViessmannWindowOpenInternal = 16384,
    ViessmannWindowOpenForce = 16387,
    ViessmannAssemblyMode = 16402,
    SchneiderWiserSpecific = 57616,
    DanfossWindowOpenInternal = 16384,
    DanfossWindowOpenExternal = 16387,
    DanfossDayOfWeek = 16400,
    DanfossTriggerTime = 16401,
    DanfossMountedModeActive = 16402,
    DanfossMountedModeControl = 16403,
    DanfossThermostatOrientation = 16404,
    DanfossExternalMeasuredRoomSensor = 16405,
    DanfossRadiatorCovered = 16406,
    DanfossAlgorithmScaleFactor = 16416,
    DanfossHeatAvailable = 16432,
    DanfossHeatRequired = 16433,
    DanfossLoadBalancingEnable = 16434,
    DanfossLoadRoomMean = 16448,
    DanfossLoadEstimate = 16458,
    DanfossRegulationSetpointOffset = 16459,
    DanfossAdaptionRunControl = 16460,
    DanfossAdaptionRunStatus = 16461,
    DanfossAdaptionRunSettings = 16462,
    DanfossPreheatStatus = 16463,
    DanfossPreheatTime = 16464,
    DanfossWindowOpenFeatureEnable = 16465,
    DanfossRoomStatusCode = 16640,
    DanfossOutputStatus = 16656,
    DanfossRoomFloorSensorMode = 16672,
    DanfossFloorMinSetpoint = 16673,
    DanfossFloorMaxSetpoint = 16674,
    ElkoLoad = 1025,
    ElkoDisplayText = 1026,
    ElkoSensor = 1027,
    ElkoRegulatorTime = 1028,
    ElkoRegulatorMode = 1029,
    ElkoPowerStatus = 1030,
    ElkoDateTime = 1031,
    ElkoMeanPower = 1032,
    ElkoExternalTemp = 1033,
    ElkoNightSwitching = 1041,
    ElkoFrostGuard = 1042,
    ElkoChildLock = 1043,
    ElkoMaxFloorTemp = 1044,
    ElkoRelayState = 1045,
    ElkoVersion = 1046,
    ElkoCalibration = 1047,
    ElkoLastMessageId = 1048,
    ElkoLastMessageStatus = 1049,
    FourNoksHysteresisHigh = 257,
    FourNoksHysteresisLow = 258,
    UbisysClassBTemperatureOffset = 0,
    UbisysReturnFlowTemperatureWeight = 1,
    UbisysRawOutdoorTemperature = 2,
    UbisysRawLocalTemperatureA = 3,
    UbisysRawLocalTemperatureB = 4,
    UbisysRawForwardFlowTemperature = 5,
    UbisysRawReturnFlowTemperature = 6,
    UbisysInstalledExtensions = 7,
    UbisysTemperatureOffset = 16,
    UbisysDefaultOccupiedHeatingSetpoint = 17,
    UbisysVacationMode = 18,
    UbisysRemoteTemperature = 19,
    UbisysRemoteTemperatureValidDuration = 20,
    UbisysProportionalGain = 32,
    UbisysProportionalShift = 33,
    UbisysIntegralFactor = 34,
};

class HvacThermostatCluster: public Cluster {
public:
    HvacThermostatCluster(ClusterType type = ClusterType::Input) : Cluster(513, type) {
    }
    AttributeInt16* getLocalTemp();
    AttributeInt16* getOutdoorTemp();
    AttributeUInt8* getOccupancy();
    AttributeInt16* getAbsMinHeatSetpointLimit();
    AttributeInt16* getAbsMaxHeatSetpointLimit();
    AttributeInt16* getAbsMinCoolSetpointLimit();
    AttributeInt16* getAbsMaxCoolSetpointLimit();
    AttributeUInt8* getPICoolingDemand();
    AttributeUInt8* getPIHeatingDemand();
    AttributeUInt8* getSystemTypeConfig();
    AttributeInt8* getLocalTemperatureCalibration();
    AttributeInt16* getOccupiedCoolingSetpoint();
    AttributeInt16* getOccupiedHeatingSetpoint();
    AttributeInt16* getUnoccupiedCoolingSetpoint();
    AttributeInt16* getUnoccupiedHeatingSetpoint();
    AttributeInt16* getMinHeatSetpointLimit();
    AttributeInt16* getMaxHeatSetpointLimit();
    AttributeInt16* getMinCoolSetpointLimit();
    AttributeInt16* getMaxCoolSetpointLimit();
    AttributeInt8* getMinSetpointDeadBand();
    AttributeUInt8* getRemoteSensing();
    AttributeUInt8* getCtrlSeqeOfOper();
    AttributeUInt8* getSystemMode();
    AttributeUInt8* getAlarmMask();
    AttributeUInt8* getRunningMode();
    AttributeUInt8* getStartOfWeek();
    AttributeUInt8* getNumberOfWeeklyTrans();
    AttributeUInt8* getNumberOfDailyTrans();
    AttributeUInt8* getTempSetpointHold();
    AttributeUInt16* getTempSetpointHoldDuration();
    AttributeUInt8* getProgramingOperMode();
    AttributeUInt16* getRunningState();
    AttributeUInt8* getSetpointChangeSource();
    AttributeInt16* getSetpointChangeAmount();
    AttributeUInt32* getSetpointChangeSourceTimeStamp();
    AttributeUInt8* getAcType();
    AttributeUInt16* getAcCapacity();
    AttributeUInt8* getAcRefrigerantType();
    AttributeUInt8* getAcConpressorType();
    AttributeUInt32* getAcErrorCode();
    AttributeUInt8* getAcLouverPosition();
    AttributeInt16* getAcCollTemp();
    AttributeUInt8* getAcCapacityFormat();
    AttributeUInt8* getStelproSystemMode();
    AttributeUInt16* getElkoLoad();
    AttributeString* getElkoDisplayText();
    AttributeUInt8* getElkoSensor();
    AttributeUInt8* getElkoRegulatorTime();
    AttributeUInt8* getElkoRegulatorMode();
    AttributeUInt8* getElkoPowerStatus();
    AttributeOctstr* getElkoDateTime();
    AttributeUInt16* getElkoMeanPower();
    AttributeInt16* getElkoExternalTemp();
    AttributeUInt8* getElkoNightSwitching();
    AttributeUInt8* getElkoFrostGuard();
    AttributeUInt8* getElkoChildLock();
    AttributeUInt8* getElkoMaxFloorTemp();
    AttributeUInt8* getElkoRelayState();
    AttributeOctstr* getElkoVersion();
    AttributeInt8* getElkoCalibration();
    AttributeUInt8* getElkoLastMessageId();
    AttributeUInt8* getElkoLastMessageStatus();

    virtual Status onSetpointRaiseLowerCommand(uint8_t mode, int8_t amount) {
        return Status::UnsupportedAttribute;
    }

    void sendSetpointRaiseLowerCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t mode, int8_t amount);

    virtual Status onGetWeeklyScheduleCommand(uint8_t daystoreturn, uint8_t modetoreturn) {
        return Status::UnsupportedAttribute;
    }

    void sendGetWeeklyScheduleCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t daystoreturn, uint8_t modetoreturn);

    virtual Status onClearWeeklyScheduleCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendClearWeeklyScheduleCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onGetRelayStatusLogCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendGetRelayStatusLogCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onDanfossSetpointCommandCommand(uint8_t setpointType, int16_t setpoint) {
        return Status::UnsupportedAttribute;
    }

    void sendDanfossSetpointCommandCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t setpointType, int16_t setpoint);

    virtual Status onSchneiderWiserThermostatBoostCommand(uint8_t command, uint8_t enable, uint16_t temperature, uint16_t duration) {
        return Status::UnsupportedAttribute;
    }

    void sendSchneiderWiserThermostatBoostCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t command, uint8_t enable, uint16_t temperature, uint16_t duration);

    virtual Status onWiserSmartSetSetpointCommand(uint8_t operatingmode, uint8_t zonemode, int16_t setpoint, uint8_t reserved) {
        return Status::UnsupportedAttribute;
    }

    void sendWiserSmartSetSetpointCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t operatingmode, uint8_t zonemode, int16_t setpoint, uint8_t reserved);

    virtual Status onWiserSmartSetFipModeCommand(uint8_t zonemode, uint8_t fipmode, uint8_t reserved) {
        return Status::UnsupportedAttribute;
    }

    void sendWiserSmartSetFipModeCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t zonemode, uint8_t fipmode, uint8_t reserved);

    virtual Status onWiserSmartCalibrateValveCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendWiserSmartCalibrateValveCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onPlugwiseCalibrateValveCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendPlugwiseCalibrateValveCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onBoschCalibrateValveCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendBoschCalibrateValveCommand(DeviceManager& deviceManager, uint8_t endpointId);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class HvacFanCtrlAttribute: uint16_t {
    FanMode = 0,
    FanModeSequence = 1,
};

class HvacFanCtrlCluster: public Cluster {
public:
    HvacFanCtrlCluster(ClusterType type = ClusterType::Input) : Cluster(514, type) {
    }
    AttributeUInt8* getFanMode();
    AttributeUInt8* getFanModeSequence();
};

enum class HvacDehumidificationCtrlAttribute: uint16_t {
    RelativeHumidity = 0,
    DehumidCooling = 1,
    RhDehumidSetpoint = 16,
    RelativeHumidityMode = 17,
    DehumidLockout = 18,
    DehumidHysteresis = 19,
    DehumidMaxCool = 20,
    RelativeHumidDisplay = 21,
};

class HvacDehumidificationCtrlCluster: public Cluster {
public:
    HvacDehumidificationCtrlCluster(ClusterType type = ClusterType::Input) : Cluster(515, type) {
    }
    AttributeUInt8* getRelativeHumidity();
    AttributeUInt8* getDehumidCooling();
    AttributeUInt8* getRhDehumidSetpoint();
    AttributeUInt8* getRelativeHumidityMode();
    AttributeUInt8* getDehumidLockout();
    AttributeUInt8* getDehumidHysteresis();
    AttributeUInt8* getDehumidMaxCool();
    AttributeUInt8* getRelativeHumidDisplay();
};

enum class HvacUserInterfaceCfgAttribute: uint16_t {
    TempDisplayMode = 0,
    KeypadLockout = 1,
    ProgrammingVisibility = 2,
    DanfossViewingDirection = 16384,
};

class HvacUserInterfaceCfgCluster: public Cluster {
public:
    HvacUserInterfaceCfgCluster(ClusterType type = ClusterType::Input) : Cluster(516, type) {
    }
    AttributeUInt8* getTempDisplayMode();
    AttributeUInt8* getKeypadLockout();
    AttributeUInt8* getProgrammingVisibility();
};

enum class LightingColorCtrlAttribute: uint16_t {
    CurrentHue = 0,
    CurrentSaturation = 1,
    RemainingTime = 2,
    CurrentX = 3,
    CurrentY = 4,
    DriftCompensation = 5,
    CompensationText = 6,
    ColorTemperature = 7,
    ColorMode = 8,
    Options = 15,
    NumPrimaries = 16,
    Primary1X = 17,
    Primary1Y = 18,
    Primary1Intensity = 19,
    Primary2X = 21,
    Primary2Y = 22,
    Primary2Intensity = 23,
    Primary3X = 25,
    Primary3Y = 26,
    Primary3Intensity = 27,
    Primary4X = 32,
    Primary4Y = 33,
    Primary4Intensity = 34,
    Primary5X = 36,
    Primary5Y = 37,
    Primary5Intensity = 38,
    Primary6X = 40,
    Primary6Y = 41,
    Primary6Intensity = 42,
    WhitePointX = 48,
    WhitePointY = 49,
    ColorPointRX = 50,
    ColorPointRY = 51,
    ColorPointRIntensity = 52,
    ColorPointGX = 54,
    ColorPointGY = 55,
    ColorPointGIntensity = 56,
    ColorPointBX = 58,
    ColorPointBY = 59,
    ColorPointBIntensity = 60,
    EnhancedCurrentHue = 16384,
    EnhancedColorMode = 16385,
    ColorLoopActive = 16386,
    ColorLoopDirection = 16387,
    ColorLoopTime = 16388,
    ColorLoopStartEnhancedHue = 16389,
    ColorLoopStoredEnhancedHue = 16390,
    ColorCapabilities = 16394,
    ColorTempPhysicalMin = 16395,
    ColorTempPhysicalMax = 16396,
    CoupleColorTempToLevelMin = 16397,
    StartUpColorTemperature = 16400,
    TuyaBrightness = 61441,
    TuyaRgbMode = 61440,
};

class LightingColorCtrlCluster: public Cluster {
public:
    LightingColorCtrlCluster(ClusterType type = ClusterType::Input) : Cluster(768, type) {
    }
    AttributeUInt8* getCurrentHue();
    AttributeUInt8* getCurrentSaturation();
    AttributeUInt16* getRemainingTime();
    AttributeUInt16* getCurrentX();
    AttributeUInt16* getCurrentY();
    AttributeUInt8* getDriftCompensation();
    AttributeString* getCompensationText();
    AttributeUInt16* getColorTemperature();
    AttributeUInt8* getColorMode();
    AttributeUInt8* getOptions();
    AttributeUInt8* getNumPrimaries();
    AttributeUInt16* getPrimary1X();
    AttributeUInt16* getPrimary1Y();
    AttributeUInt8* getPrimary1Intensity();
    AttributeUInt16* getPrimary2X();
    AttributeUInt16* getPrimary2Y();
    AttributeUInt8* getPrimary2Intensity();
    AttributeUInt16* getPrimary3X();
    AttributeUInt16* getPrimary3Y();
    AttributeUInt8* getPrimary3Intensity();
    AttributeUInt16* getPrimary4X();
    AttributeUInt16* getPrimary4Y();
    AttributeUInt8* getPrimary4Intensity();
    AttributeUInt16* getPrimary5X();
    AttributeUInt16* getPrimary5Y();
    AttributeUInt8* getPrimary5Intensity();
    AttributeUInt16* getPrimary6X();
    AttributeUInt16* getPrimary6Y();
    AttributeUInt8* getPrimary6Intensity();
    AttributeUInt16* getWhitePointX();
    AttributeUInt16* getWhitePointY();
    AttributeUInt16* getColorPointRX();
    AttributeUInt16* getColorPointRY();
    AttributeUInt8* getColorPointRIntensity();
    AttributeUInt16* getColorPointGX();
    AttributeUInt16* getColorPointGY();
    AttributeUInt8* getColorPointGIntensity();
    AttributeUInt16* getColorPointBX();
    AttributeUInt16* getColorPointBY();
    AttributeUInt8* getColorPointBIntensity();
    AttributeUInt16* getEnhancedCurrentHue();
    AttributeUInt8* getEnhancedColorMode();
    AttributeUInt8* getColorLoopActive();
    AttributeUInt8* getColorLoopDirection();
    AttributeUInt16* getColorLoopTime();
    AttributeUInt16* getColorLoopStartEnhancedHue();
    AttributeUInt16* getColorLoopStoredEnhancedHue();
    AttributeUInt16* getColorCapabilities();
    AttributeUInt16* getColorTempPhysicalMin();
    AttributeUInt16* getColorTempPhysicalMax();
    AttributeUInt16* getCoupleColorTempToLevelMin();
    AttributeUInt16* getStartUpColorTemperature();

    virtual Status onMoveToHueCommand(uint8_t hue, uint8_t direction, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveToHueCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t hue, uint8_t direction, uint16_t transtime);

    virtual Status onMoveHueCommand(uint8_t movemode, uint8_t rate) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveHueCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t movemode, uint8_t rate);

    virtual Status onStepHueCommand(uint8_t stepmode, uint8_t stepsize, uint8_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendStepHueCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t stepmode, uint8_t stepsize, uint8_t transtime);

    virtual Status onMoveToSaturationCommand(uint8_t saturation, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveToSaturationCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t saturation, uint16_t transtime);

    virtual Status onMoveSaturationCommand(uint8_t movemode, uint8_t rate) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveSaturationCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t movemode, uint8_t rate);

    virtual Status onStepSaturationCommand(uint8_t stepmode, uint8_t stepsize, uint8_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendStepSaturationCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t stepmode, uint8_t stepsize, uint8_t transtime);

    virtual Status onMoveToHueAndSaturationCommand(uint8_t hue, uint8_t saturation, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveToHueAndSaturationCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t hue, uint8_t saturation, uint16_t transtime);

    virtual Status onMoveToColorCommand(uint16_t colorx, uint16_t colory, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveToColorCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t colorx, uint16_t colory, uint16_t transtime);

    virtual Status onMoveColorCommand(int16_t ratex, int16_t ratey) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveColorCommand(DeviceManager& deviceManager, uint8_t endpointId, int16_t ratex, int16_t ratey);

    virtual Status onStepColorCommand(int16_t stepx, int16_t stepy, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendStepColorCommand(DeviceManager& deviceManager, uint8_t endpointId, int16_t stepx, int16_t stepy, uint16_t transtime);

    virtual Status onMoveToColorTempCommand(uint16_t colortemp, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveToColorTempCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t colortemp, uint16_t transtime);

    virtual Status onEnhancedMoveToHueCommand(uint16_t enhancehue, uint8_t direction, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendEnhancedMoveToHueCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t enhancehue, uint8_t direction, uint16_t transtime);

    virtual Status onEnhancedMoveHueCommand(uint8_t movemode, uint16_t rate) {
        return Status::UnsupportedAttribute;
    }

    void sendEnhancedMoveHueCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t movemode, uint16_t rate);

    virtual Status onEnhancedStepHueCommand(uint8_t stepmode, uint16_t stepsize, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendEnhancedStepHueCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t stepmode, uint16_t stepsize, uint16_t transtime);

    virtual Status onEnhancedMoveToHueAndSaturationCommand(uint16_t enhancehue, uint8_t saturation, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void sendEnhancedMoveToHueAndSaturationCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t enhancehue, uint8_t saturation, uint16_t transtime);

    virtual Status onColorLoopSetCommand(uint8_t updateflags, uint8_t action, uint8_t direction, uint16_t time, uint16_t starthue) {
        return Status::UnsupportedAttribute;
    }

    void sendColorLoopSetCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t updateflags, uint8_t action, uint8_t direction, uint16_t time, uint16_t starthue);

    virtual Status onStopMoveStepCommand(uint8_t bits, uint8_t bytee, uint8_t action, uint8_t direction, uint16_t time, uint16_t starthue) {
        return Status::UnsupportedAttribute;
    }

    void sendStopMoveStepCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t bits, uint8_t bytee, uint8_t action, uint8_t direction, uint16_t time, uint16_t starthue);

    virtual Status onMoveColorTempCommand(uint8_t movemode, uint16_t rate, uint16_t minimum, uint16_t maximum) {
        return Status::UnsupportedAttribute;
    }

    void sendMoveColorTempCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t movemode, uint16_t rate, uint16_t minimum, uint16_t maximum);

    virtual Status onStepColorTempCommand(uint8_t stepmode, uint16_t stepsize, uint16_t transtime, uint16_t minimum, uint16_t maximum) {
        return Status::UnsupportedAttribute;
    }

    void sendStepColorTempCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t stepmode, uint16_t stepsize, uint16_t transtime, uint16_t minimum, uint16_t maximum);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class LightingBallastCfgAttribute: uint16_t {
    PhysicalMinLevel = 0,
    PhysicalMaxLevel = 1,
    BallastStatus = 2,
    MinLevel = 16,
    MaxLevel = 17,
    PowerOnLevel = 18,
    PowerOnFadeTime = 19,
    IntrinsicBallastFactor = 20,
    BallastFactorAdjustment = 21,
    LampQuantity = 32,
    LampType = 48,
    LampManufacturer = 49,
    LampRatedHours = 50,
    LampBurnHours = 51,
    LampAlarmMode = 52,
    LampBurnHoursTripPoint = 53,
    ElkoControlMode = 57344,
    WiserControlMode = 57344,
};

class LightingBallastCfgCluster: public Cluster {
public:
    LightingBallastCfgCluster(ClusterType type = ClusterType::Input) : Cluster(769, type) {
    }
    AttributeUInt8* getPhysicalMinLevel();
    AttributeUInt8* getPhysicalMaxLevel();
    AttributeUInt8* getBallastStatus();
    AttributeUInt8* getMinLevel();
    AttributeUInt8* getMaxLevel();
    AttributeUInt8* getPowerOnLevel();
    AttributeUInt16* getPowerOnFadeTime();
    AttributeUInt8* getIntrinsicBallastFactor();
    AttributeUInt8* getBallastFactorAdjustment();
    AttributeUInt8* getLampQuantity();
    AttributeString* getLampType();
    AttributeString* getLampManufacturer();
    AttributeUInt24* getLampRatedHours();
    AttributeUInt24* getLampBurnHours();
    AttributeUInt8* getLampAlarmMode();
    AttributeUInt24* getLampBurnHoursTripPoint();
};

enum class MsIlluminanceMeasurementAttribute: uint16_t {
    MeasuredValue = 0,
    MinMeasuredValue = 1,
    MaxMeasuredValue = 2,
    Tolerance = 3,
    LightSensorType = 4,
};

class MsIlluminanceMeasurementCluster: public Cluster {
public:
    MsIlluminanceMeasurementCluster(ClusterType type = ClusterType::Input) : Cluster(1024, type) {
    }
    AttributeUInt16* getMeasuredValue();
    AttributeUInt16* getMinMeasuredValue();
    AttributeUInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
    AttributeUInt8* getLightSensorType();
};

enum class MsIlluminanceLevelSensingAttribute: uint16_t {
    LevelStatus = 0,
    LightSensorType = 1,
    IlluminanceTargetLevel = 16,
};

class MsIlluminanceLevelSensingCluster: public Cluster {
public:
    MsIlluminanceLevelSensingCluster(ClusterType type = ClusterType::Input) : Cluster(1025, type) {
    }
    AttributeUInt8* getLevelStatus();
    AttributeUInt8* getLightSensorType();
    AttributeUInt16* getIlluminanceTargetLevel();
};

enum class MsTemperatureMeasurementAttribute: uint16_t {
    MeasuredValue = 0,
    MinMeasuredValue = 1,
    MaxMeasuredValue = 2,
    Tolerance = 3,
    MinPercentChange = 16,
    MinAbsoluteChange = 17,
    SprutTemperatureOffset = 26112,
};

class MsTemperatureMeasurementCluster: public Cluster {
public:
    MsTemperatureMeasurementCluster(ClusterType type = ClusterType::Input) : Cluster(1026, type) {
    }
    AttributeInt16* getMeasuredValue();
    AttributeInt16* getMinMeasuredValue();
    AttributeInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
};

enum class MsPressureMeasurementAttribute: uint16_t {
    MeasuredValue = 0,
    MinMeasuredValue = 1,
    MaxMeasuredValue = 2,
    Tolerance = 3,
    ScaledValue = 16,
    MinScaledValue = 17,
    MaxScaledValue = 18,
    ScaledTolerance = 19,
    Scale = 20,
};

class MsPressureMeasurementCluster: public Cluster {
public:
    MsPressureMeasurementCluster(ClusterType type = ClusterType::Input) : Cluster(1027, type) {
    }
    AttributeInt16* getMeasuredValue();
    AttributeInt16* getMinMeasuredValue();
    AttributeInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
    AttributeInt16* getScaledValue();
    AttributeInt16* getMinScaledValue();
    AttributeInt16* getMaxScaledValue();
    AttributeUInt16* getScaledTolerance();
    AttributeInt8* getScale();
};

enum class MsFlowMeasurementAttribute: uint16_t {
    MeasuredValue = 0,
    MinMeasuredValue = 1,
    MaxMeasuredValue = 2,
    Tolerance = 3,
};

class MsFlowMeasurementCluster: public Cluster {
public:
    MsFlowMeasurementCluster(ClusterType type = ClusterType::Input) : Cluster(1028, type) {
    }
    AttributeUInt16* getMeasuredValue();
    AttributeUInt16* getMinMeasuredValue();
    AttributeUInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
};

enum class MsRelativeHumidityAttribute: uint16_t {
    MeasuredValue = 0,
    MinMeasuredValue = 1,
    MaxMeasuredValue = 2,
    Tolerance = 3,
    SprutHeater = 26112,
};

class MsRelativeHumidityCluster: public Cluster {
public:
    MsRelativeHumidityCluster(ClusterType type = ClusterType::Input) : Cluster(1029, type) {
    }
    AttributeUInt16* getMeasuredValue();
    AttributeUInt16* getMinMeasuredValue();
    AttributeUInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
};

enum class MsOccupancySensingAttribute: uint16_t {
    Occupancy = 0,
    OccupancySensorType = 1,
    PirOToUDelay = 16,
    PirUToODelay = 17,
    PirUToOThreshold = 18,
    UltrasonicOToUDelay = 32,
    UltrasonicUToODelay = 33,
    UltrasonicUToOThreshold = 34,
    ElkoOccupancyDfltOperationMode = 57344,
    ElkoOccupancyOperationMode = 57345,
    ElkoForceOffTimeout = 57346,
    ElkoOccupancySensitivity = 57347,
    SprutOccupancyLevel = 26112,
    SprutOccupancySensitivity = 26113,
};

class MsOccupancySensingCluster: public Cluster {
public:
    MsOccupancySensingCluster(ClusterType type = ClusterType::Input) : Cluster(1030, type) {
    }
    AttributeUInt8* getOccupancy();
    AttributeUInt8* getOccupancySensorType();
    AttributeUInt16* getPirOToUDelay();
    AttributeUInt16* getPirUToODelay();
    AttributeUInt8* getPirUToOThreshold();
    AttributeUInt16* getUltrasonicOToUDelay();
    AttributeUInt16* getUltrasonicUToODelay();
    AttributeUInt8* getUltrasonicUToOThreshold();
};

enum class MsSoilMoistureAttribute: uint16_t {
    MeasuredValue = 0,
    MinMeasuredValue = 1,
    MaxMeasuredValue = 2,
    Tolerance = 3,
};

class MsSoilMoistureCluster: public Cluster {
public:
    MsSoilMoistureCluster(ClusterType type = ClusterType::Input) : Cluster(1032, type) {
    }
    AttributeUInt16* getMeasuredValue();
    AttributeUInt16* getMinMeasuredValue();
    AttributeUInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
};

enum class PHMeasurementAttribute: uint16_t {
    MeasuredValue = 0,
    MinMeasuredValue = 1,
    MaxMeasuredValue = 2,
    Tolerance = 3,
};

class PHMeasurementCluster: public Cluster {
public:
    PHMeasurementCluster(ClusterType type = ClusterType::Input) : Cluster(1033, type) {
    }
    AttributeUInt16* getMeasuredValue();
    AttributeUInt16* getMinMeasuredValue();
    AttributeUInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
};

enum class MsCO2Attribute: uint16_t {
    MeasuredValue = 0,
    MinMeasuredValue = 1,
    MaxMeasuredValue = 2,
    SprutCO2Calibration = 26112,
    SprutCO2AutoCalibration = 26113,
};

class MsCO2Cluster: public Cluster {
public:
    MsCO2Cluster(ClusterType type = ClusterType::Input) : Cluster(1037, type) {
    }
    AttributeSingle* getMeasuredValue();
    AttributeSingle* getMinMeasuredValue();
    AttributeSingle* getMaxMeasuredValue();
};

enum class Pm25MeasurementAttribute: uint16_t {
    MeasuredValueIkea = 0,
    MeasuredValue = 0,
    MeasuredMinValue = 1,
    MeasuredMaxValue = 2,
    MeasuredTolerance = 3,
};

class Pm25MeasurementCluster: public Cluster {
public:
    Pm25MeasurementCluster(ClusterType type = ClusterType::Input) : Cluster(1066, type) {
    }
    AttributeUInt16* getMeasuredValue();
    AttributeUInt16* getMeasuredMinValue();
    AttributeUInt16* getMeasuredMaxValue();
    AttributeUInt16* getMeasuredTolerance();
};

enum class SsIasZoneAttribute: uint16_t {
    ZoneState = 0,
    ZoneType = 1,
    ZoneStatus = 2,
    IasCieAddr = 16,
    ZoneId = 17,
    NumZoneSensitivityLevelsSupported = 18,
    CurrentZoneSensitivityLevel = 19,
    DevelcoAlarmOffDelay = 32769,
};

class SsIasZoneCluster: public Cluster {
public:
    SsIasZoneCluster(ClusterType type = ClusterType::Input) : Cluster(1280, type) {
    }
    AttributeUInt8* getZoneState();
    AttributeUInt16* getZoneType();
    AttributeUInt16* getZoneStatus();
    AttributeUInt64* getIasCieAddr();
    AttributeUInt8* getZoneId();
    AttributeUInt8* getNumZoneSensitivityLevelsSupported();
    AttributeUInt8* getCurrentZoneSensitivityLevel();

    virtual Status onEnrollRspCommand(uint8_t enrollrspcode, uint8_t zoneid) {
        return Status::UnsupportedAttribute;
    }

    void sendEnrollRspCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t enrollrspcode, uint8_t zoneid);

    virtual Status onInitNormalOpModeCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendInitNormalOpModeCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onInitTestModeCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendInitTestModeCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onBoschTestTamperCommand(uint8_t data) {
        return Status::UnsupportedAttribute;
    }

    void sendBoschTestTamperCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t data);

    virtual Status onBoschSmokeDetectorSirenCommand(uint16_t data) {
        return Status::UnsupportedAttribute;
    }

    void sendBoschSmokeDetectorSirenCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t data);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class SsIasAceAttribute: uint16_t {
};

class SsIasAceCluster: public Cluster {
public:
    SsIasAceCluster(ClusterType type = ClusterType::Input) : Cluster(1281, type) {
    }

    class ArmCommandResponse {
        uint8_t _armnotification{};

    public:
        uint8_t getArmnotification() { return _armnotification; }
        void setArmnotification(uint8_t armnotification) { _armnotification = armnotification; }

    };

    virtual Status onArmCommand(uint8_t armmode, String code, uint8_t zoneid, ArmCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status onEmergencyCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendEmergencyCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onFireCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendFireCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onPanicCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendPanicCommand(DeviceManager& deviceManager, uint8_t endpointId);

    class GetZoneIDMapCommandResponse {
        uint16_t _zoneidmapsection0{};
        uint16_t _zoneidmapsection1{};
        uint16_t _zoneidmapsection2{};
        uint16_t _zoneidmapsection3{};
        uint16_t _zoneidmapsection4{};
        uint16_t _zoneidmapsection5{};
        uint16_t _zoneidmapsection6{};
        uint16_t _zoneidmapsection7{};
        uint16_t _zoneidmapsection8{};
        uint16_t _zoneidmapsection9{};
        uint16_t _zoneidmapsection10{};
        uint16_t _zoneidmapsection11{};
        uint16_t _zoneidmapsection12{};
        uint16_t _zoneidmapsection13{};
        uint16_t _zoneidmapsection14{};
        uint16_t _zoneidmapsection15{};

    public:
        uint16_t getZoneidmapsection0() { return _zoneidmapsection0; }
        void setZoneidmapsection0(uint16_t zoneidmapsection0) { _zoneidmapsection0 = zoneidmapsection0; }

        uint16_t getZoneidmapsection1() { return _zoneidmapsection1; }
        void setZoneidmapsection1(uint16_t zoneidmapsection1) { _zoneidmapsection1 = zoneidmapsection1; }

        uint16_t getZoneidmapsection2() { return _zoneidmapsection2; }
        void setZoneidmapsection2(uint16_t zoneidmapsection2) { _zoneidmapsection2 = zoneidmapsection2; }

        uint16_t getZoneidmapsection3() { return _zoneidmapsection3; }
        void setZoneidmapsection3(uint16_t zoneidmapsection3) { _zoneidmapsection3 = zoneidmapsection3; }

        uint16_t getZoneidmapsection4() { return _zoneidmapsection4; }
        void setZoneidmapsection4(uint16_t zoneidmapsection4) { _zoneidmapsection4 = zoneidmapsection4; }

        uint16_t getZoneidmapsection5() { return _zoneidmapsection5; }
        void setZoneidmapsection5(uint16_t zoneidmapsection5) { _zoneidmapsection5 = zoneidmapsection5; }

        uint16_t getZoneidmapsection6() { return _zoneidmapsection6; }
        void setZoneidmapsection6(uint16_t zoneidmapsection6) { _zoneidmapsection6 = zoneidmapsection6; }

        uint16_t getZoneidmapsection7() { return _zoneidmapsection7; }
        void setZoneidmapsection7(uint16_t zoneidmapsection7) { _zoneidmapsection7 = zoneidmapsection7; }

        uint16_t getZoneidmapsection8() { return _zoneidmapsection8; }
        void setZoneidmapsection8(uint16_t zoneidmapsection8) { _zoneidmapsection8 = zoneidmapsection8; }

        uint16_t getZoneidmapsection9() { return _zoneidmapsection9; }
        void setZoneidmapsection9(uint16_t zoneidmapsection9) { _zoneidmapsection9 = zoneidmapsection9; }

        uint16_t getZoneidmapsection10() { return _zoneidmapsection10; }
        void setZoneidmapsection10(uint16_t zoneidmapsection10) { _zoneidmapsection10 = zoneidmapsection10; }

        uint16_t getZoneidmapsection11() { return _zoneidmapsection11; }
        void setZoneidmapsection11(uint16_t zoneidmapsection11) { _zoneidmapsection11 = zoneidmapsection11; }

        uint16_t getZoneidmapsection12() { return _zoneidmapsection12; }
        void setZoneidmapsection12(uint16_t zoneidmapsection12) { _zoneidmapsection12 = zoneidmapsection12; }

        uint16_t getZoneidmapsection13() { return _zoneidmapsection13; }
        void setZoneidmapsection13(uint16_t zoneidmapsection13) { _zoneidmapsection13 = zoneidmapsection13; }

        uint16_t getZoneidmapsection14() { return _zoneidmapsection14; }
        void setZoneidmapsection14(uint16_t zoneidmapsection14) { _zoneidmapsection14 = zoneidmapsection14; }

        uint16_t getZoneidmapsection15() { return _zoneidmapsection15; }
        void setZoneidmapsection15(uint16_t zoneidmapsection15) { _zoneidmapsection15 = zoneidmapsection15; }

    };

    virtual Status onGetZoneIDMapCommand(GetZoneIDMapCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetZoneInfoCommandResponse {
        uint8_t _zoneid{};
        uint16_t _zonetype{};
        uint64_t _ieeeaddr{};
        String _zonelabel{};

    public:
        uint8_t getZoneid() { return _zoneid; }
        void setZoneid(uint8_t zoneid) { _zoneid = zoneid; }

        uint16_t getZonetype() { return _zonetype; }
        void setZonetype(uint16_t zonetype) { _zonetype = zonetype; }

        uint64_t getIeeeaddr() { return _ieeeaddr; }
        void setIeeeaddr(uint64_t ieeeaddr) { _ieeeaddr = ieeeaddr; }

        String getZonelabel() { return _zonelabel; }
        void setZonelabel(const String& zonelabel) { _zonelabel = zonelabel; }

    };

    virtual Status onGetZoneInfoCommand(uint8_t zoneid, GetZoneInfoCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetPanelStatusCommandResponse {
        uint8_t _panelstatus{};
        uint8_t _secondsremain{};
        uint8_t _audiblenotif{};
        uint8_t _alarmstatus{};

    public:
        uint8_t getPanelstatus() { return _panelstatus; }
        void setPanelstatus(uint8_t panelstatus) { _panelstatus = panelstatus; }

        uint8_t getSecondsremain() { return _secondsremain; }
        void setSecondsremain(uint8_t secondsremain) { _secondsremain = secondsremain; }

        uint8_t getAudiblenotif() { return _audiblenotif; }
        void setAudiblenotif(uint8_t audiblenotif) { _audiblenotif = audiblenotif; }

        uint8_t getAlarmstatus() { return _alarmstatus; }
        void setAlarmstatus(uint8_t alarmstatus) { _alarmstatus = alarmstatus; }

    };

    virtual Status onGetPanelStatusCommand(GetPanelStatusCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status onGetBypassedZoneListCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendGetBypassedZoneListCommand(DeviceManager& deviceManager, uint8_t endpointId);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class SsIasWdAttribute: uint16_t {
    MaxDuration = 0,
};

class SsIasWdCluster: public Cluster {
public:
    SsIasWdCluster(ClusterType type = ClusterType::Input) : Cluster(1282, type) {
    }
    AttributeUInt16* getMaxDuration();

    virtual Status onStartWarningCommand(uint8_t startwarninginfo, uint16_t warningduration, uint8_t strobedutycycle, uint8_t strobelevel) {
        return Status::UnsupportedAttribute;
    }

    void sendStartWarningCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t startwarninginfo, uint16_t warningduration, uint8_t strobedutycycle, uint8_t strobelevel);

    virtual Status onSquawkCommand(uint8_t squawkinfo) {
        return Status::UnsupportedAttribute;
    }

    void sendSquawkCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t squawkinfo);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class PiGenericTunnelAttribute: uint16_t {
    MaxIncomeTransSize = 1,
    MaxOutgoTransSize = 2,
    ProtocolAddr = 3,
};

class PiGenericTunnelCluster: public Cluster {
public:
    PiGenericTunnelCluster(ClusterType type = ClusterType::Input) : Cluster(1536, type) {
    }
    AttributeUInt16* getMaxIncomeTransSize();
    AttributeUInt16* getMaxOutgoTransSize();
    AttributeOctstr* getProtocolAddr();

    virtual Status onMatchProtocolAddrCommand(String protocoladdr) {
        return Status::UnsupportedAttribute;
    }

    void sendMatchProtocolAddrCommand(DeviceManager& deviceManager, uint8_t endpointId, String protocoladdr);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class PiBacnetProtocolTunnelAttribute: uint16_t {
};

class PiBacnetProtocolTunnelCluster: public Cluster {
public:
    PiBacnetProtocolTunnelCluster(ClusterType type = ClusterType::Input) : Cluster(1537, type) {
    }

    virtual Status onTransferNpduCommand(uint8_t npdu) {
        return Status::UnsupportedAttribute;
    }

    void sendTransferNpduCommand(DeviceManager& deviceManager, uint8_t endpointId, uint8_t npdu);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class PiAnalogInputRegAttribute: uint16_t {
    CovIncrement = 22,
    DeviceType = 31,
    ObjectId = 75,
    ObjectName = 77,
    ObjectType = 79,
    UpdateInterval = 118,
    ProfileName = 168,
};

class PiAnalogInputRegCluster: public Cluster {
public:
    PiAnalogInputRegCluster(ClusterType type = ClusterType::Input) : Cluster(1538, type) {
    }
    AttributeSingle* getCovIncrement();
    AttributeString* getDeviceType();
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeUInt8* getUpdateInterval();
    AttributeString* getProfileName();
};

enum class PiAnalogInputExtAttribute: uint16_t {
    AckedTransitions = 0,
    NotificationClass = 17,
    Deadband = 25,
    EventEnable = 35,
    EventState = 36,
    HighLimit = 45,
    LimitEnable = 52,
    LowLimit = 59,
    NotifyType = 72,
    TimeDelay = 113,
    EventTimeStamps = 130,
};

class PiAnalogInputExtCluster: public Cluster {
public:
    PiAnalogInputExtCluster(ClusterType type = ClusterType::Input) : Cluster(1539, type) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt16* getNotificationClass();
    AttributeSingle* getDeadband();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeSingle* getHighLimit();
    AttributeUInt8* getLimitEnable();
    AttributeSingle* getLowLimit();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();

    virtual Status onTransferApduCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendTransferApduCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onConnectReqCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendConnectReqCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onDisconnectReqCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendDisconnectReqCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onConnectStatusNotiCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendConnectStatusNotiCommand(DeviceManager& deviceManager, uint8_t endpointId);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class PiAnalogOutputRegAttribute: uint16_t {
    CovIncrement = 22,
    DeviceType = 31,
    ObjectId = 75,
    ObjectName = 77,
    ObjectType = 79,
    UpdateInterval = 118,
    ProfileName = 168,
};

class PiAnalogOutputRegCluster: public Cluster {
public:
    PiAnalogOutputRegCluster(ClusterType type = ClusterType::Input) : Cluster(1540, type) {
    }
    AttributeSingle* getCovIncrement();
    AttributeString* getDeviceType();
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeUInt8* getUpdateInterval();
    AttributeString* getProfileName();
};

enum class PiAnalogOutputExtAttribute: uint16_t {
    AckedTransitions = 0,
    NotificationClass = 17,
    Deadband = 25,
    EventEnable = 35,
    EventState = 36,
    HighLimit = 45,
    LimitEnable = 52,
    LowLimit = 59,
    NotifyType = 72,
    TimeDelay = 113,
    EventTimeStamps = 130,
};

class PiAnalogOutputExtCluster: public Cluster {
public:
    PiAnalogOutputExtCluster(ClusterType type = ClusterType::Input) : Cluster(1541, type) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt16* getNotificationClass();
    AttributeSingle* getDeadband();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeSingle* getHighLimit();
    AttributeUInt8* getLimitEnable();
    AttributeSingle* getLowLimit();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

enum class PiAnalogValueRegAttribute: uint16_t {
    CovIncrement = 22,
    ObjectId = 75,
    ObjectName = 77,
    ObjectType = 79,
    ProfileName = 168,
};

class PiAnalogValueRegCluster: public Cluster {
public:
    PiAnalogValueRegCluster(ClusterType type = ClusterType::Input) : Cluster(1542, type) {
    }
    AttributeSingle* getCovIncrement();
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeString* getProfileName();
};

enum class PiAnalogValueExtAttribute: uint16_t {
    AckedTransitions = 0,
    NotificationClass = 17,
    Deadband = 25,
    EventEnable = 35,
    EventState = 36,
    HighLimit = 45,
    LimitEnable = 52,
    LowLimit = 59,
    NotifyType = 72,
    TimeDelay = 113,
    EventTimeStamps = 130,
};

class PiAnalogValueExtCluster: public Cluster {
public:
    PiAnalogValueExtCluster(ClusterType type = ClusterType::Input) : Cluster(1543, type) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt16* getNotificationClass();
    AttributeSingle* getDeadband();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeSingle* getHighLimit();
    AttributeUInt8* getLimitEnable();
    AttributeSingle* getLowLimit();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

enum class PiBinaryInputRegAttribute: uint16_t {
    ChangeOfStateCount = 15,
    ChangeOfStateTime = 16,
    DeviceType = 31,
    ElapsedActiveTime = 33,
    ObjectIdentifier = 75,
    ObjectName = 77,
    ObjectType = 79,
    TimeOfATReset = 114,
    TimeOfSCReset = 115,
    ProfileName = 168,
};

class PiBinaryInputRegCluster: public Cluster {
public:
    PiBinaryInputRegCluster(ClusterType type = ClusterType::Input) : Cluster(1544, type) {
    }
    AttributeUInt32* getChangeOfStateCount();
    AttributeDateTime* getChangeOfStateTime();
    AttributeString* getDeviceType();
    AttributeUInt32* getElapsedActiveTime();
    AttributeUInt32* getObjectIdentifier();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeDateTime* getTimeOfATReset();
    AttributeDateTime* getTimeOfSCReset();
    AttributeString* getProfileName();
};

enum class PiBinaryInputExtAttribute: uint16_t {
    AckedTransitions = 0,
    AlarmValue = 6,
    NotificationClass = 17,
    EventEnable = 35,
    EventState = 36,
    NotifyType = 72,
    TimeDelay = 113,
    EventTimeStamps = 130,
};

class PiBinaryInputExtCluster: public Cluster {
public:
    PiBinaryInputExtCluster(ClusterType type = ClusterType::Input) : Cluster(1545, type) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt8* getAlarmValue();
    AttributeUInt16* getNotificationClass();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

enum class PiBinaryOutputRegAttribute: uint16_t {
    ChangeOfStateCount = 15,
    ChangeOfStateTime = 16,
    DeviceType = 31,
    ElapsedActiveTime = 33,
    FeedBackValue = 40,
    ObjectIdentifier = 75,
    ObjectName = 77,
    ObjectType = 79,
    TimeOfATReset = 114,
    TimeOfSCReset = 115,
    ProfileName = 168,
};

class PiBinaryOutputRegCluster: public Cluster {
public:
    PiBinaryOutputRegCluster(ClusterType type = ClusterType::Input) : Cluster(1546, type) {
    }
    AttributeUInt32* getChangeOfStateCount();
    AttributeDateTime* getChangeOfStateTime();
    AttributeString* getDeviceType();
    AttributeUInt32* getElapsedActiveTime();
    AttributeUInt8* getFeedBackValue();
    AttributeUInt32* getObjectIdentifier();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeDateTime* getTimeOfATReset();
    AttributeDateTime* getTimeOfSCReset();
    AttributeString* getProfileName();
};

enum class PiBinaryOutputExtAttribute: uint16_t {
    AckedTransitions = 0,
    NotificationClass = 17,
    EventEnable = 35,
    EventState = 36,
    NotifyType = 72,
    TimeDelay = 113,
    EventTimeStamps = 130,
};

class PiBinaryOutputExtCluster: public Cluster {
public:
    PiBinaryOutputExtCluster(ClusterType type = ClusterType::Input) : Cluster(1547, type) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt16* getNotificationClass();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

enum class PiBinaryValueRegAttribute: uint16_t {
    ChangeOfStateCount = 15,
    ChangeOfStateTime = 16,
    ElapsedActiveTime = 33,
    ObjectIdentifier = 75,
    ObjectName = 77,
    ObjectType = 79,
    TimeOfATReset = 114,
    TimeOfSCReset = 115,
    ProfileName = 168,
};

class PiBinaryValueRegCluster: public Cluster {
public:
    PiBinaryValueRegCluster(ClusterType type = ClusterType::Input) : Cluster(1548, type) {
    }
    AttributeUInt32* getChangeOfStateCount();
    AttributeDateTime* getChangeOfStateTime();
    AttributeUInt32* getElapsedActiveTime();
    AttributeUInt32* getObjectIdentifier();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeDateTime* getTimeOfATReset();
    AttributeDateTime* getTimeOfSCReset();
    AttributeString* getProfileName();
};

enum class PiBinaryValueExtAttribute: uint16_t {
    AckedTransitions = 0,
    AlarmValue = 6,
    NotificationClass = 17,
    EventEnable = 35,
    EventState = 36,
    NotifyType = 72,
    TimeDelay = 113,
    EventTimeStamps = 130,
};

class PiBinaryValueExtCluster: public Cluster {
public:
    PiBinaryValueExtCluster(ClusterType type = ClusterType::Input) : Cluster(1549, type) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt8* getAlarmValue();
    AttributeUInt16* getNotificationClass();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

enum class PiMultistateInputRegAttribute: uint16_t {
    DeviceType = 31,
    ObjectId = 75,
    ObjectName = 77,
    ObjectType = 79,
    ProfileName = 168,
};

class PiMultistateInputRegCluster: public Cluster {
public:
    PiMultistateInputRegCluster(ClusterType type = ClusterType::Input) : Cluster(1550, type) {
    }
    AttributeString* getDeviceType();
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeString* getProfileName();
};

enum class PiMultistateInputExtAttribute: uint16_t {
    AckedTransitions = 0,
    AlarmValue = 6,
    NotificationClass = 17,
    EventEnable = 35,
    EventState = 36,
    FaultValues = 37,
    NotifyType = 72,
    TimeDelay = 113,
    EventTimeStamps = 130,
};

class PiMultistateInputExtCluster: public Cluster {
public:
    PiMultistateInputExtCluster(ClusterType type = ClusterType::Input) : Cluster(1551, type) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt16* getAlarmValue();
    AttributeUInt16* getNotificationClass();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeUInt16* getFaultValues();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

enum class PiMultistateOutputRegAttribute: uint16_t {
    DeviceType = 31,
    FeedBackValue = 40,
    ObjectId = 75,
    ObjectName = 77,
    ObjectType = 79,
    ProfileName = 168,
};

class PiMultistateOutputRegCluster: public Cluster {
public:
    PiMultistateOutputRegCluster(ClusterType type = ClusterType::Input) : Cluster(1552, type) {
    }
    AttributeString* getDeviceType();
    AttributeUInt8* getFeedBackValue();
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeString* getProfileName();
};

enum class PiMultistateOutputExtAttribute: uint16_t {
    AckedTransitions = 0,
    NotificationClass = 17,
    EventEnable = 35,
    EventState = 36,
    NotifyType = 72,
    TimeDelay = 113,
    EventTimeStamps = 130,
};

class PiMultistateOutputExtCluster: public Cluster {
public:
    PiMultistateOutputExtCluster(ClusterType type = ClusterType::Input) : Cluster(1553, type) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt16* getNotificationClass();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

enum class PiMultistateValueRegAttribute: uint16_t {
    ObjectId = 75,
    ObjectName = 77,
    ObjectType = 79,
    ProfileName = 168,
};

class PiMultistateValueRegCluster: public Cluster {
public:
    PiMultistateValueRegCluster(ClusterType type = ClusterType::Input) : Cluster(1554, type) {
    }
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeString* getProfileName();
};

enum class PiMultistateValueExtAttribute: uint16_t {
    AckedTransitions = 0,
    AlarmValue = 6,
    NotificationClass = 17,
    EventEnable = 35,
    EventState = 36,
    FaultValues = 37,
    NotifyType = 72,
    TimeDelay = 113,
    EventTimeStamps = 130,
};

class PiMultistateValueExtCluster: public Cluster {
public:
    PiMultistateValueExtCluster(ClusterType type = ClusterType::Input) : Cluster(1555, type) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt16* getAlarmValue();
    AttributeUInt16* getNotificationClass();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeUInt16* getFaultValues();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

enum class Pi11073ProtocolTunnelAttribute: uint16_t {
    DeviceidList = 0,
    ManagerTarget = 1,
    ManagerEndpoint = 2,
    Connected = 3,
    Preemptible = 4,
    IdleTimeout = 5,
};

class Pi11073ProtocolTunnelCluster: public Cluster {
public:
    Pi11073ProtocolTunnelCluster(ClusterType type = ClusterType::Input) : Cluster(1556, type) {
    }
    AttributeUInt64* getManagerTarget();
    AttributeUInt8* getManagerEndpoint();
    AttributeUInt8* getConnected();
    AttributeUInt8* getPreemptible();
    AttributeUInt16* getIdleTimeout();

    virtual Status onTransferApduCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendTransferApduCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onConnectReqCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendConnectReqCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onDisconnectReqCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendDisconnectReqCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onConnectStatusNotiCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendConnectStatusNotiCommand(DeviceManager& deviceManager, uint8_t endpointId);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class PiIso7818ProtocolTunnelAttribute: uint16_t {
    Status = 0,
};

class PiIso7818ProtocolTunnelCluster: public Cluster {
public:
    PiIso7818ProtocolTunnelCluster(ClusterType type = ClusterType::Input) : Cluster(1557, type) {
    }
    AttributeUInt8* getStatus();
};

enum class PiRetailTunnelAttribute: uint16_t {
    ManufacturerCode = 0,
    MsProfile = 1,
};

class PiRetailTunnelCluster: public Cluster {
public:
    PiRetailTunnelCluster(ClusterType type = ClusterType::Input) : Cluster(1559, type) {
    }
    AttributeUInt16* getManufacturerCode();
    AttributeUInt16* getMsProfile();
};

enum class SeMeteringAttribute: uint16_t {
    CurrentSummDelivered = 0,
    CurrentSummReceived = 1,
    CurrentMaxDemandDelivered = 2,
    CurrentMaxDemandReceived = 3,
    DftSumm = 4,
    DailyFreezeTime = 5,
    PowerFactor = 6,
    ReadingSnapshotTime = 7,
    CurrentMaxDemandDeliverdTime = 8,
    CurrentMaxDemandReceivedTime = 9,
    DefaultUpdatePeriod = 10,
    FastPollUpdatePeriod = 11,
    CurrentBlockPeriodConsumpDelivered = 12,
    DailyConsumpTarget = 13,
    CurrentBlock = 14,
    ProfileIntervalPeriod = 15,
    IntervalReadReportingPeriod = 16,
    PresetReadingTime = 17,
    VolumePerReport = 18,
    FlowRestriction = 19,
    SupplyStatus = 20,
    CurrentInEnergyCarrierSumm = 21,
    CurrentOutEnergyCarrierSumm = 22,
    InletTempreature = 23,
    OutletTempreature = 24,
    ControlTempreature = 25,
    CurrentInEnergyCarrierDemand = 26,
    CurrentOutEnergyCarrierDemand = 27,
    CurrentBlockPeriodConsumpReceived = 29,
    CurrentBlockReceived = 30,
    DFTSummationReceived = 31,
    ActiveRegisterTierDelivered = 32,
    ActiveRegisterTierReceived = 33,
    CurrentTier1SummDelivered = 256,
    CurrentTier1SummReceived = 257,
    CurrentTier2SummDelivered = 258,
    CurrentTier2SummReceived = 259,
    CurrentTier3SummDelivered = 260,
    CurrentTier3SummReceived = 261,
    CurrentTier4SummDelivered = 262,
    CurrentTier4SummReceived = 263,
    CurrentTier5SummDelivered = 264,
    CurrentTier5SummReceived = 265,
    CurrentTier6SummDelivered = 266,
    CurrentTier6SummReceived = 267,
    CurrentTier7SummDelivered = 268,
    CurrentTier7SummReceived = 269,
    CurrentTier8SummDelivered = 270,
    CurrentTier8SummReceived = 271,
    CurrentTier9SummDelivered = 272,
    CurrentTier9SummReceived = 273,
    CurrentTier10SummDelivered = 274,
    CurrentTier10SummReceived = 275,
    CurrentTier11SummDelivered = 276,
    CurrentTier11SummReceived = 277,
    CurrentTier12SummDelivered = 278,
    CurrentTier12SummReceived = 279,
    CurrentTier13SummDelivered = 280,
    CurrentTier13SummReceived = 281,
    CurrentTier14SummDelivered = 282,
    CurrentTier14SummReceived = 283,
    CurrentTier15SummDelivered = 284,
    CurrentTier15SummReceived = 285,
    Status = 512,
    RemainingBattLife = 513,
    HoursInOperation = 514,
    HoursInFault = 515,
    ExtendedStatus = 516,
    UnitOfMeasure = 768,
    Multiplier = 769,
    Divisor = 770,
    SummaFormatting = 771,
    DemandFormatting = 772,
    HistoricalConsumpFormatting = 773,
    MeteringDeviceType = 774,
    SiteId = 775,
    MeterSerialNumber = 776,
    EnergyCarrierUnitOfMeas = 777,
    EnergyCarrierSummFormatting = 778,
    EnergyCarrierDemandFormatting = 779,
    TemperatureUnitOfMeas = 780,
    TemperatureFormatting = 781,
    ModuleSerialNumber = 782,
    OperatingTariffLevel = 783,
    InstantaneousDemand = 1024,
    CurrentdayConsumpDelivered = 1025,
    CurrentdayConsumpReceived = 1026,
    PreviousdayConsumpDelivered = 1027,
    PreviousdayConsumpReceived = 1028,
    CurPartProfileIntStartTimeDelivered = 1029,
    CurPartProfileIntStartTimeReceived = 1030,
    CurPartProfileIntValueDelivered = 1031,
    CurPartProfileIntValueReceived = 1032,
    CurrentDayMaxPressure = 1033,
    CurrentDayMinPressure = 1034,
    PreviousDayMaxPressure = 1035,
    PreviousDayMinPressure = 1036,
    CurrentDayMaxDemand = 1037,
    PreviousDayMaxDemand = 1038,
    CurrentMonthMaxDemand = 1039,
    CurrentYearMaxDemand = 1040,
    CurrentdayMaxEnergyCarrDemand = 1041,
    PreviousdayMaxEnergyCarrDemand = 1042,
    CurMonthMaxEnergyCarrDemand = 1043,
    CurMonthMinEnergyCarrDemand = 1044,
    CurYearMaxEnergyCarrDemand = 1045,
    CurYearMinEnergyCarrDemand = 1046,
    MaxNumberOfPeriodsDelivered = 1280,
    CurrentDemandDelivered = 1536,
    DemandLimit = 1537,
    DemandIntegrationPeriod = 1538,
    NumberOfDemandSubintervals = 1539,
    DemandLimitArmDuration = 1540,
    GenericAlarmMask = 2048,
    ElectricityAlarmMask = 2049,
    GenFlowPressureAlarmMask = 2050,
    WaterSpecificAlarmMask = 2051,
    HeatCoolSpecificAlarmMASK = 2052,
    GasSpecificAlarmMask = 2053,
    ExtendedGenericAlarmMask = 2054,
    ManufactureAlarmMask = 2055,
    BillToDate = 2560,
    BillToDateTimeStamp = 2561,
    ProjectedBill = 2562,
    ProjectedBillTimeStamp = 2563,
    NotificationControlFlags = 0,
    NotificationFlags = 1,
    PriceNotificationFlags = 2,
    CalendarNotificationFlags = 3,
    PrePayNotificationFlags = 4,
    DeviceManagementFlags = 5,
    ChangeReportingProfile = 256,
    DevelcoPulseConfiguration = 768,
    DevelcoCurrentSummation = 769,
    DevelcoInterfaceMode = 770,
    OwonL1PhasePower = 8192,
    OwonL2PhasePower = 8193,
    OwonL3PhasePower = 8194,
    OwonL1PhaseReactivePower = 8448,
    OwonL2PhaseReactivePower = 8449,
    OwonL3PhaseReactivePower = 8450,
    OwonReactivePowerSum = 8451,
    OwonL1PhaseVoltage = 12288,
    OwonL2PhaseVoltage = 12289,
    OwonL3PhaseVoltage = 12290,
    OwonL1PhaseCurrent = 12544,
    OwonL2PhaseCurrent = 12545,
    OwonL3PhaseCurrent = 12546,
    OwonCurrentSum = 12547,
    OwonLeakageCurrent = 12548,
    OwonL1Energy = 16384,
    OwonL2Energy = 16385,
    OwonL3Energy = 16386,
    OwonL1ReactiveEnergy = 16640,
    OwonL2ReactiveEnergy = 16641,
    OwonL3ReactiveEnergy = 16642,
    OwonReactiveEnergySum = 16643,
    OwonL1PowerFactor = 16644,
    OwonL2PowerFactor = 16645,
    OwonL3PowerFactor = 16646,
    OwonFrequency = 20485,
    OwonReportMap = 4096,
    OwonLastHistoricalRecordTime = 20480,
    OwonOldestHistoricalRecordTime = 20481,
    OwonMinimumReportCycle = 20482,
    OwonMaximumReportCycle = 20483,
    OwonSentHistoricalRecordState = 20484,
    OwonAccumulativeEnergyThreshold = 20486,
    OwonReportMode = 20487,
    OwonPercentChangeInPower = 20487,
    SchneiderActiveEnergyTotal = 16400,
    SchneiderReactiveEnergyTotal = 16401,
    SchneiderApparentEnergyTotal = 16402,
    SchneiderPartialActiveEnergyTotal = 16404,
    SchneiderPartialReactiveEnergyTotal = 16405,
    SchneiderPartialApparentEnergyTotal = 16406,
    SchneiderPartialActiveEnergyL1Phase = 16640,
    SchneiderPartialReactiveEnergyL1Phase = 16641,
    SchneiderPartialApparentEnergyL1Phase = 16642,
    SchneiderActiveEnergyL1Phase = 16643,
    SchneiderReactiveEnergyL1Phase = 16644,
    SchneiderApparentEnergyL1Phase = 16645,
    SchneiderPartialActiveEnergyL2Phase = 16896,
    SchneiderPartialReactiveEnergyL2Phase = 16897,
    SchneiderPartialApparentEnergyL2Phase = 16898,
    SchneiderActiveEnergyL2Phase = 16899,
    SchneiderReactiveEnergyL2Phase = 16900,
    SchneiderApparentEnergyL2Phase = 16901,
    SchneiderPartialActiveEnergyL3Phase = 17152,
    SchneiderPartialReactiveEnergyL3Phase = 17153,
    SchneiderPartialApparentEnergyL3Phase = 17154,
    SchneiderActiveEnergyL3Phase = 17155,
    SchneiderReactiveEnergyL3Phase = 17156,
    SchneiderApparentEnergyL3Phase = 17157,
    SchneiderActiveEnergyMultiplier = 17408,
    SchneiderActiveEnergyDivisor = 17409,
    SchneiderReactiveEnergyMultiplier = 17410,
    SchneiderReactiveEnergyDivisor = 17411,
    SchneiderApparentEnergyMultiplier = 17412,
    SchneiderApparentEnergyDivisor = 17413,
    SchneiderEnergyResetDateTime = 17665,
    SchneiderEnergyCountersReportingPeriod = 17920,
};

class SeMeteringCluster: public Cluster {
public:
    SeMeteringCluster(ClusterType type = ClusterType::Input) : Cluster(1794, type) {
    }
    AttributeUInt48* getCurrentSummDelivered();
    AttributeUInt48* getCurrentSummReceived();
    AttributeUInt48* getCurrentMaxDemandDelivered();
    AttributeUInt48* getCurrentMaxDemandReceived();
    AttributeUInt48* getDftSumm();
    AttributeUInt16* getDailyFreezeTime();
    AttributeInt8* getPowerFactor();
    AttributeUInt32* getReadingSnapshotTime();
    AttributeUInt32* getCurrentMaxDemandDeliverdTime();
    AttributeUInt32* getCurrentMaxDemandReceivedTime();
    AttributeUInt8* getDefaultUpdatePeriod();
    AttributeUInt8* getFastPollUpdatePeriod();
    AttributeUInt48* getCurrentBlockPeriodConsumpDelivered();
    AttributeUInt24* getDailyConsumpTarget();
    AttributeUInt8* getCurrentBlock();
    AttributeUInt8* getProfileIntervalPeriod();
    AttributeUInt16* getIntervalReadReportingPeriod();
    AttributeUInt16* getPresetReadingTime();
    AttributeUInt16* getVolumePerReport();
    AttributeUInt8* getFlowRestriction();
    AttributeUInt8* getSupplyStatus();
    AttributeUInt48* getCurrentInEnergyCarrierSumm();
    AttributeUInt48* getCurrentOutEnergyCarrierSumm();
    AttributeInt24* getInletTempreature();
    AttributeInt24* getOutletTempreature();
    AttributeInt24* getControlTempreature();
    AttributeInt24* getCurrentInEnergyCarrierDemand();
    AttributeInt24* getCurrentOutEnergyCarrierDemand();
    AttributeUInt48* getCurrentBlockPeriodConsumpReceived();
    AttributeUInt48* getCurrentBlockReceived();
    AttributeUInt48* getDFTSummationReceived();
    AttributeUInt8* getActiveRegisterTierDelivered();
    AttributeUInt8* getActiveRegisterTierReceived();
    AttributeUInt48* getCurrentTier1SummDelivered();
    AttributeUInt48* getCurrentTier1SummReceived();
    AttributeUInt48* getCurrentTier2SummDelivered();
    AttributeUInt48* getCurrentTier2SummReceived();
    AttributeUInt48* getCurrentTier3SummDelivered();
    AttributeUInt48* getCurrentTier3SummReceived();
    AttributeUInt48* getCurrentTier4SummDelivered();
    AttributeUInt48* getCurrentTier4SummReceived();
    AttributeUInt48* getCurrentTier5SummDelivered();
    AttributeUInt48* getCurrentTier5SummReceived();
    AttributeUInt48* getCurrentTier6SummDelivered();
    AttributeUInt48* getCurrentTier6SummReceived();
    AttributeUInt48* getCurrentTier7SummDelivered();
    AttributeUInt48* getCurrentTier7SummReceived();
    AttributeUInt48* getCurrentTier8SummDelivered();
    AttributeUInt48* getCurrentTier8SummReceived();
    AttributeUInt48* getCurrentTier9SummDelivered();
    AttributeUInt48* getCurrentTier9SummReceived();
    AttributeUInt48* getCurrentTier10SummDelivered();
    AttributeUInt48* getCurrentTier10SummReceived();
    AttributeUInt48* getCurrentTier11SummDelivered();
    AttributeUInt48* getCurrentTier11SummReceived();
    AttributeUInt48* getCurrentTier12SummDelivered();
    AttributeUInt48* getCurrentTier12SummReceived();
    AttributeUInt48* getCurrentTier13SummDelivered();
    AttributeUInt48* getCurrentTier13SummReceived();
    AttributeUInt48* getCurrentTier14SummDelivered();
    AttributeUInt48* getCurrentTier14SummReceived();
    AttributeUInt48* getCurrentTier15SummDelivered();
    AttributeUInt48* getCurrentTier15SummReceived();
    AttributeUInt8* getStatus();
    AttributeUInt8* getRemainingBattLife();
    AttributeUInt24* getHoursInOperation();
    AttributeUInt24* getHoursInFault();
    AttributeUInt64* getExtendedStatus();
    AttributeUInt8* getUnitOfMeasure();
    AttributeUInt24* getMultiplier();
    AttributeUInt24* getDivisor();
    AttributeUInt8* getSummaFormatting();
    AttributeUInt8* getDemandFormatting();
    AttributeUInt8* getHistoricalConsumpFormatting();
    AttributeUInt8* getMeteringDeviceType();
    AttributeOctstr* getSiteId();
    AttributeOctstr* getMeterSerialNumber();
    AttributeUInt8* getEnergyCarrierUnitOfMeas();
    AttributeUInt8* getEnergyCarrierSummFormatting();
    AttributeUInt8* getEnergyCarrierDemandFormatting();
    AttributeUInt8* getTemperatureUnitOfMeas();
    AttributeUInt8* getTemperatureFormatting();
    AttributeOctstr* getModuleSerialNumber();
    AttributeOctstr* getOperatingTariffLevel();
    AttributeInt24* getInstantaneousDemand();
    AttributeUInt24* getCurrentdayConsumpDelivered();
    AttributeUInt24* getCurrentdayConsumpReceived();
    AttributeUInt24* getPreviousdayConsumpDelivered();
    AttributeUInt24* getPreviousdayConsumpReceived();
    AttributeUInt32* getCurPartProfileIntStartTimeDelivered();
    AttributeUInt32* getCurPartProfileIntStartTimeReceived();
    AttributeUInt24* getCurPartProfileIntValueDelivered();
    AttributeUInt24* getCurPartProfileIntValueReceived();
    AttributeUInt48* getCurrentDayMaxPressure();
    AttributeUInt48* getCurrentDayMinPressure();
    AttributeUInt48* getPreviousDayMaxPressure();
    AttributeUInt48* getPreviousDayMinPressure();
    AttributeInt24* getCurrentDayMaxDemand();
    AttributeInt24* getPreviousDayMaxDemand();
    AttributeInt24* getCurrentMonthMaxDemand();
    AttributeInt24* getCurrentYearMaxDemand();
    AttributeInt24* getCurrentdayMaxEnergyCarrDemand();
    AttributeInt24* getPreviousdayMaxEnergyCarrDemand();
    AttributeInt24* getCurMonthMaxEnergyCarrDemand();
    AttributeInt24* getCurMonthMinEnergyCarrDemand();
    AttributeInt24* getCurYearMaxEnergyCarrDemand();
    AttributeInt24* getCurYearMinEnergyCarrDemand();
    AttributeUInt8* getMaxNumberOfPeriodsDelivered();
    AttributeUInt24* getCurrentDemandDelivered();
    AttributeUInt24* getDemandLimit();
    AttributeUInt8* getDemandIntegrationPeriod();
    AttributeUInt8* getNumberOfDemandSubintervals();
    AttributeUInt16* getDemandLimitArmDuration();
    AttributeUInt16* getGenericAlarmMask();
    AttributeUInt32* getElectricityAlarmMask();
    AttributeUInt16* getGenFlowPressureAlarmMask();
    AttributeUInt16* getWaterSpecificAlarmMask();
    AttributeUInt16* getHeatCoolSpecificAlarmMASK();
    AttributeUInt16* getGasSpecificAlarmMask();
    AttributeUInt48* getExtendedGenericAlarmMask();
    AttributeUInt16* getManufactureAlarmMask();
    AttributeUInt32* getBillToDate();
    AttributeUInt32* getBillToDateTimeStamp();
    AttributeUInt32* getProjectedBill();
    AttributeUInt32* getProjectedBillTimeStamp();
    AttributeUInt32* getNotificationControlFlags();
    AttributeUInt32* getNotificationFlags();
    AttributeUInt32* getPriceNotificationFlags();
    AttributeUInt32* getCalendarNotificationFlags();
    AttributeUInt32* getPrePayNotificationFlags();
    AttributeUInt32* getDeviceManagementFlags();

    virtual Status onGetProfileCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendGetProfileCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onReqMirrorCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendReqMirrorCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onMirrorRemCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendMirrorRemCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onReqFastPollModeCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendReqFastPollModeCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onGetSnapshotCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendGetSnapshotCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onTakeSnapshotCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendTakeSnapshotCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onMirrorReportAttrRspCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendMirrorReportAttrRspCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onOwonGetHistoryRecordCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendOwonGetHistoryRecordCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onOwonStopSendingHistoricalRecordCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendOwonStopSendingHistoricalRecordCommand(DeviceManager& deviceManager, uint8_t endpointId);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class TunnelingAttribute: uint16_t {
};

class TunnelingCluster: public Cluster {
public:
    TunnelingCluster(ClusterType type = ClusterType::Input) : Cluster(1796, type) {
    }
};

enum class TelecommunicationsInformationAttribute: uint16_t {
    NodeDescription = 0,
    DeliveryEnable = 1,
    PushInformationTimer = 2,
    EnableSecureConfiguration = 3,
    NumberOfContents = 16,
    ContentRootID = 17,
};

class TelecommunicationsInformationCluster: public Cluster {
public:
    TelecommunicationsInformationCluster(ClusterType type = ClusterType::Input) : Cluster(2304, type) {
    }
    AttributeString* getNodeDescription();
    AttributeUInt8* getDeliveryEnable();
    AttributeUInt32* getPushInformationTimer();
    AttributeUInt8* getEnableSecureConfiguration();
    AttributeUInt16* getNumberOfContents();
    AttributeUInt16* getContentRootID();
};

enum class TelecommunicationsVoiceOverZigbeeAttribute: uint16_t {
    CodecType = 0,
    SamplingFrequency = 1,
    Codecrate = 2,
    EstablishmentTimeout = 3,
    CodecTypeSub1 = 4,
    CodecTypeSub2 = 5,
    CodecTypeSub3 = 6,
    CompressionType = 7,
    CompressionRate = 8,
    OptionFlags = 9,
    Threshold = 10,
};

class TelecommunicationsVoiceOverZigbeeCluster: public Cluster {
public:
    TelecommunicationsVoiceOverZigbeeCluster(ClusterType type = ClusterType::Input) : Cluster(2308, type) {
    }
    AttributeUInt8* getCodecType();
    AttributeUInt8* getSamplingFrequency();
    AttributeUInt8* getCodecrate();
    AttributeUInt8* getEstablishmentTimeout();
    AttributeUInt8* getCodecTypeSub1();
    AttributeUInt8* getCodecTypeSub2();
    AttributeUInt8* getCodecTypeSub3();
    AttributeUInt8* getCompressionType();
    AttributeUInt8* getCompressionRate();
    AttributeUInt8* getOptionFlags();
    AttributeUInt8* getThreshold();
};

enum class TelecommunicationsChattingAttribute: uint16_t {
    UID = 0,
    Nickname = 1,
    CID = 16,
    Name = 17,
    EnableAddChat = 18,
};

class TelecommunicationsChattingCluster: public Cluster {
public:
    TelecommunicationsChattingCluster(ClusterType type = ClusterType::Input) : Cluster(2309, type) {
    }
    AttributeUInt16* getUID();
    AttributeString* getNickname();
    AttributeUInt16* getCID();
    AttributeString* getName();
    AttributeUInt8* getEnableAddChat();
};

enum class HaApplianceIdentificationAttribute: uint16_t {
    BasicIdentification = 0,
    CompanyName = 16,
    CompanyId = 17,
    BrandName = 18,
    BrandId = 19,
    Model = 20,
    PartNumber = 21,
    ProductRevision = 22,
    SoftwareRevision = 23,
    ProductTypeName = 24,
    ProductTypeId = 25,
    CecedSpecificationVersion = 26,
};

class HaApplianceIdentificationCluster: public Cluster {
public:
    HaApplianceIdentificationCluster(ClusterType type = ClusterType::Input) : Cluster(2816, type) {
    }
    AttributeUInt56* getBasicIdentification();
    AttributeString* getCompanyName();
    AttributeUInt16* getCompanyId();
    AttributeString* getBrandName();
    AttributeUInt16* getBrandId();
    AttributeOctstr* getModel();
    AttributeOctstr* getPartNumber();
    AttributeOctstr* getProductRevision();
    AttributeOctstr* getSoftwareRevision();
    AttributeOctstr* getProductTypeName();
    AttributeUInt16* getProductTypeId();
    AttributeUInt8* getCecedSpecificationVersion();
};

enum class HaMeterIdentificationAttribute: uint16_t {
    CompanyName = 0,
    MeterTypeId = 1,
    DataQualityId = 4,
    CustomerName = 5,
    Model = 6,
    PartNumber = 7,
    ProductRevision = 8,
    SoftwareRevision = 10,
    UtilityName = 11,
    Pod = 12,
    AvailablePower = 13,
    PowerThreshold = 14,
};

class HaMeterIdentificationCluster: public Cluster {
public:
    HaMeterIdentificationCluster(ClusterType type = ClusterType::Input) : Cluster(2817, type) {
    }
    AttributeString* getCompanyName();
    AttributeUInt16* getMeterTypeId();
    AttributeUInt16* getDataQualityId();
    AttributeString* getCustomerName();
    AttributeString* getModel();
    AttributeString* getPartNumber();
    AttributeString* getProductRevision();
    AttributeString* getSoftwareRevision();
    AttributeString* getUtilityName();
    AttributeString* getPod();
    AttributeInt24* getAvailablePower();
    AttributeInt24* getPowerThreshold();
};

enum class HaApplianceEventsAlertsAttribute: uint16_t {
};

class HaApplianceEventsAlertsCluster: public Cluster {
public:
    HaApplianceEventsAlertsCluster(ClusterType type = ClusterType::Input) : Cluster(2818, type) {
    }

    virtual Status onGetAlertsCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendGetAlertsCommand(DeviceManager& deviceManager, uint8_t endpointId);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class HaApplianceStatisticsAttribute: uint16_t {
    LogMaxSize = 0,
    LogQueueMaxSize = 1,
};

class HaApplianceStatisticsCluster: public Cluster {
public:
    HaApplianceStatisticsCluster(ClusterType type = ClusterType::Input) : Cluster(2819, type) {
    }
    AttributeUInt32* getLogMaxSize();
    AttributeUInt8* getLogQueueMaxSize();

    virtual Status onLogCommand(uint32_t logid) {
        return Status::UnsupportedAttribute;
    }

    void sendLogCommand(DeviceManager& deviceManager, uint8_t endpointId, uint32_t logid);

    virtual Status onLogQueueCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendLogQueueCommand(DeviceManager& deviceManager, uint8_t endpointId);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class HaElectricalMeasurementAttribute: uint16_t {
    MeasurementType = 0,
    DcVoltage = 256,
    DcVoltageMin = 257,
    Dcvoltagemax = 258,
    DcCurrent = 259,
    DcCurrentMin = 260,
    DcCurrentMax = 261,
    DcPower = 262,
    DcPowerMin = 263,
    DcPowerMax = 264,
    DcVoltageMultiplier = 512,
    DcVoltageDivisor = 513,
    DcCurrentMultiplier = 514,
    DcCurrentDivisor = 515,
    DcPowerMultiplier = 516,
    DcPowerDivisor = 517,
    AcFrequency = 768,
    AcFrequencyMin = 769,
    AcFrequencyMax = 770,
    NeutralCurrent = 771,
    TotalActivePower = 772,
    TotalReactivePower = 773,
    TotalApparentPower = 774,
    Meas1stHarmonicCurrent = 775,
    Meas3rdHarmonicCurrent = 776,
    Meas5thHarmonicCurrent = 777,
    Meas7thHarmonicCurrent = 778,
    Meas9thHarmonicCurrent = 779,
    Meas11thHarmonicCurrent = 780,
    MeasPhase1stHarmonicCurrent = 781,
    MeasPhase3rdHarmonicCurrent = 782,
    MeasPhase5thHarmonicCurrent = 783,
    MeasPhase7thHarmonicCurrent = 784,
    MeasPhase9thHarmonicCurrent = 785,
    MeasPhase11thHarmonicCurrent = 786,
    AcFrequencyMultiplier = 1024,
    AcFrequencyDivisor = 1025,
    PowerMultiplier = 1026,
    PowerDivisor = 1027,
    HarmonicCurrentMultiplier = 1028,
    PhaseHarmonicCurrentMultiplier = 1029,
    InstantaneousVoltage = 1280,
    InstantaneousLineCurrent = 1281,
    InstantaneousActiveCurrent = 1282,
    InstantaneousReactiveCurrent = 1283,
    InstantaneousPower = 1284,
    RmsVoltage = 1285,
    RmsVoltageMin = 1286,
    RmsVoltageMax = 1287,
    RmsCurrent = 1288,
    RmsCurrentMin = 1289,
    RmsCurrentMax = 1290,
    ActivePower = 1291,
    ActivePowerMin = 1292,
    ActivePowerMax = 1293,
    ReactivePower = 1294,
    ApparentPower = 1295,
    PowerFactor = 1296,
    AverageRmsVoltageMeasPeriod = 1297,
    AverageRmsOverVoltageCounter = 1298,
    AverageRmsUnderVoltageCounter = 1299,
    RmsExtremeOverVoltagePeriod = 1300,
    RmsExtremeUnderVoltagePeriod = 1301,
    RmsVoltageSagPeriod = 1302,
    RmsVoltageSwellPeriod = 1303,
    AcVoltageMultiplier = 1536,
    AcVoltageDivisor = 1537,
    AcCurrentMultiplier = 1538,
    AcCurrentDivisor = 1539,
    AcPowerMultiplier = 1540,
    AcPowerDivisor = 1541,
    DcOverloadAlarmsMask = 1792,
    DcVoltageOverload = 1793,
    DcCurrentOverload = 1794,
    AcAlarmsMask = 2048,
    AcVoltageOverload = 2049,
    AcCurrentOverload = 2050,
    AcActivePowerOverload = 2051,
    AcReactivePowerOverload = 2052,
    AverageRmsOverVoltage = 2053,
    AverageRmsUnderVoltage = 2054,
    RmsExtremeOverVoltage = 2055,
    RmsExtremeUnderVoltage = 2056,
    RmsVoltageSag = 2057,
    RmsVoltageSwell = 2058,
    LineCurrentPhB = 2305,
    ActiveCurrentPhB = 2306,
    ReactiveCurrentPhB = 2307,
    RmsVoltagePhB = 2309,
    RmsVoltageMinPhB = 2310,
    RmsVoltageMaxPhB = 2311,
    RmsCurrentPhB = 2312,
    RmsCurrentMinPhB = 2313,
    RmsCurrentMaxPhB = 2314,
    ActivePowerPhB = 2315,
    ActivePowerMinPhB = 2316,
    ActivePowerMaxPhB = 2317,
    ReactivePowerPhB = 2318,
    ApparentPowerPhB = 2319,
    PowerFactorPhB = 2320,
    AverageRmsVoltageMeasurePeriodPhB = 2321,
    AverageRmsOverVoltageCounterPhB = 2322,
    AverageUnderVoltageCounterPhB = 2323,
    RmsExtremeOverVoltagePeriodPhB = 2324,
    RmsExtremeUnderVoltagePeriodPhB = 2325,
    RmsVoltageSagPeriodPhB = 2326,
    RmsVoltageSwellPeriodPhB = 2327,
    LineCurrentPhC = 2561,
    ActiveCurrentPhC = 2562,
    ReactiveCurrentPhC = 2563,
    RmsVoltagePhC = 2565,
    RmsVoltageMinPhC = 2566,
    RmsVoltageMaxPhC = 2567,
    RmsCurrentPhC = 2568,
    RmsCurrentMinPhC = 2569,
    RmsCurrentMaxPhC = 2570,
    ActivePowerPhC = 2571,
    ActivePowerMinPhC = 2572,
    ActivePowerMaxPhC = 2573,
    ReactivePowerPhC = 2574,
    ApparentPowerPhC = 2575,
    PowerFactorPhC = 2576,
    AverageRmsVoltageMeasPeriodPhC = 2577,
    AverageRmsOverVoltageCounterPhC = 2578,
    AverageUnderVoltageCounterPhC = 2579,
    RmsExtremeOverVoltagePeriodPhC = 2580,
    RmsExtremeUnderVoltagePeriodPhC = 2581,
    RmsVoltageSagPeriodPhC = 2582,
    RmsVoltageSwellPeriodPhC = 2583,
    SchneiderActivePowerDemandTotal = 17152,
    SchneiderReactivePowerDemandTotal = 17155,
    SchneiderApparentPowerDemandTotal = 17176,
    SchneiderDemandIntervalDuration = 17177,
    SchneiderDemandDateTime = 17184,
    SchneiderActivePowerDemandPhase1 = 17673,
    SchneiderReactivePowerDemandPhase1 = 17674,
    SchneiderApparentPowerDemandPhase1 = 17675,
    SchneiderDemandIntervalMinimalVoltageL1 = 17680,
    SchneiderDemandIntervalMaximalCurrentI1 = 17683,
    SchneiderActivePowerDemandPhase2 = 18697,
    SchneiderReactivePowerDemandPhase2 = 18698,
    SchneiderApparentPowerDemandPhase2 = 18699,
    SchneiderDemandIntervalMinimalVoltageL2 = 18704,
    SchneiderDemandIntervalMaximalCurrentI2 = 18707,
    SchneiderActivePowerDemandPhase3 = 18953,
    SchneiderReactivePowerDemandPhase3 = 18954,
    SchneiderApparentPowerDemandPhase3 = 18955,
    SchneiderDemandIntervalMinimalVoltageL3 = 18960,
    SchneiderDemandIntervalMaximalCurrentI3 = 18963,
    SchneiderCurrentSensorMultiplier = 19968,
};

class HaElectricalMeasurementCluster: public Cluster {
public:
    HaElectricalMeasurementCluster(ClusterType type = ClusterType::Input) : Cluster(2820, type) {
    }
    AttributeUInt32* getMeasurementType();
    AttributeInt16* getDcVoltage();
    AttributeInt16* getDcVoltageMin();
    AttributeInt16* getDcvoltagemax();
    AttributeInt16* getDcCurrent();
    AttributeInt16* getDcCurrentMin();
    AttributeInt16* getDcCurrentMax();
    AttributeInt16* getDcPower();
    AttributeInt16* getDcPowerMin();
    AttributeInt16* getDcPowerMax();
    AttributeUInt16* getDcVoltageMultiplier();
    AttributeUInt16* getDcVoltageDivisor();
    AttributeUInt16* getDcCurrentMultiplier();
    AttributeUInt16* getDcCurrentDivisor();
    AttributeUInt16* getDcPowerMultiplier();
    AttributeUInt16* getDcPowerDivisor();
    AttributeUInt16* getAcFrequency();
    AttributeUInt16* getAcFrequencyMin();
    AttributeUInt16* getAcFrequencyMax();
    AttributeUInt16* getNeutralCurrent();
    AttributeInt32* getTotalActivePower();
    AttributeInt32* getTotalReactivePower();
    AttributeUInt32* getTotalApparentPower();
    AttributeInt16* getMeas1stHarmonicCurrent();
    AttributeInt16* getMeas3rdHarmonicCurrent();
    AttributeInt16* getMeas5thHarmonicCurrent();
    AttributeInt16* getMeas7thHarmonicCurrent();
    AttributeInt16* getMeas9thHarmonicCurrent();
    AttributeInt16* getMeas11thHarmonicCurrent();
    AttributeInt16* getMeasPhase1stHarmonicCurrent();
    AttributeInt16* getMeasPhase3rdHarmonicCurrent();
    AttributeInt16* getMeasPhase5thHarmonicCurrent();
    AttributeInt16* getMeasPhase7thHarmonicCurrent();
    AttributeInt16* getMeasPhase9thHarmonicCurrent();
    AttributeInt16* getMeasPhase11thHarmonicCurrent();
    AttributeUInt16* getAcFrequencyMultiplier();
    AttributeUInt16* getAcFrequencyDivisor();
    AttributeUInt32* getPowerMultiplier();
    AttributeUInt32* getPowerDivisor();
    AttributeInt8* getHarmonicCurrentMultiplier();
    AttributeInt8* getPhaseHarmonicCurrentMultiplier();
    AttributeInt16* getInstantaneousVoltage();
    AttributeUInt16* getInstantaneousLineCurrent();
    AttributeInt16* getInstantaneousActiveCurrent();
    AttributeInt16* getInstantaneousReactiveCurrent();
    AttributeInt16* getInstantaneousPower();
    AttributeUInt16* getRmsVoltage();
    AttributeUInt16* getRmsVoltageMin();
    AttributeUInt16* getRmsVoltageMax();
    AttributeUInt16* getRmsCurrent();
    AttributeUInt16* getRmsCurrentMin();
    AttributeUInt16* getRmsCurrentMax();
    AttributeInt16* getActivePower();
    AttributeInt16* getActivePowerMin();
    AttributeInt16* getActivePowerMax();
    AttributeInt16* getReactivePower();
    AttributeUInt16* getApparentPower();
    AttributeInt8* getPowerFactor();
    AttributeUInt16* getAverageRmsVoltageMeasPeriod();
    AttributeUInt16* getAverageRmsOverVoltageCounter();
    AttributeUInt16* getAverageRmsUnderVoltageCounter();
    AttributeUInt16* getRmsExtremeOverVoltagePeriod();
    AttributeUInt16* getRmsExtremeUnderVoltagePeriod();
    AttributeUInt16* getRmsVoltageSagPeriod();
    AttributeUInt16* getRmsVoltageSwellPeriod();
    AttributeUInt16* getAcVoltageMultiplier();
    AttributeUInt16* getAcVoltageDivisor();
    AttributeUInt16* getAcCurrentMultiplier();
    AttributeUInt16* getAcCurrentDivisor();
    AttributeUInt16* getAcPowerMultiplier();
    AttributeUInt16* getAcPowerDivisor();
    AttributeUInt8* getDcOverloadAlarmsMask();
    AttributeInt16* getDcVoltageOverload();
    AttributeInt16* getDcCurrentOverload();
    AttributeUInt16* getAcAlarmsMask();
    AttributeInt16* getAcVoltageOverload();
    AttributeInt16* getAcCurrentOverload();
    AttributeInt16* getAcActivePowerOverload();
    AttributeInt16* getAcReactivePowerOverload();
    AttributeInt16* getAverageRmsOverVoltage();
    AttributeInt16* getAverageRmsUnderVoltage();
    AttributeInt16* getRmsExtremeOverVoltage();
    AttributeInt16* getRmsExtremeUnderVoltage();
    AttributeInt16* getRmsVoltageSag();
    AttributeInt16* getRmsVoltageSwell();
    AttributeUInt16* getLineCurrentPhB();
    AttributeInt16* getActiveCurrentPhB();
    AttributeInt16* getReactiveCurrentPhB();
    AttributeUInt16* getRmsVoltagePhB();
    AttributeUInt16* getRmsVoltageMinPhB();
    AttributeUInt16* getRmsVoltageMaxPhB();
    AttributeUInt16* getRmsCurrentPhB();
    AttributeUInt16* getRmsCurrentMinPhB();
    AttributeUInt16* getRmsCurrentMaxPhB();
    AttributeInt16* getActivePowerPhB();
    AttributeInt16* getActivePowerMinPhB();
    AttributeInt16* getActivePowerMaxPhB();
    AttributeInt16* getReactivePowerPhB();
    AttributeUInt16* getApparentPowerPhB();
    AttributeInt8* getPowerFactorPhB();
    AttributeUInt16* getAverageRmsVoltageMeasurePeriodPhB();
    AttributeUInt16* getAverageRmsOverVoltageCounterPhB();
    AttributeUInt16* getAverageUnderVoltageCounterPhB();
    AttributeUInt16* getRmsExtremeOverVoltagePeriodPhB();
    AttributeUInt16* getRmsExtremeUnderVoltagePeriodPhB();
    AttributeUInt16* getRmsVoltageSagPeriodPhB();
    AttributeUInt16* getRmsVoltageSwellPeriodPhB();
    AttributeUInt16* getLineCurrentPhC();
    AttributeInt16* getActiveCurrentPhC();
    AttributeInt16* getReactiveCurrentPhC();
    AttributeUInt16* getRmsVoltagePhC();
    AttributeUInt16* getRmsVoltageMinPhC();
    AttributeUInt16* getRmsVoltageMaxPhC();
    AttributeUInt16* getRmsCurrentPhC();
    AttributeUInt16* getRmsCurrentMinPhC();
    AttributeUInt16* getRmsCurrentMaxPhC();
    AttributeInt16* getActivePowerPhC();
    AttributeInt16* getActivePowerMinPhC();
    AttributeInt16* getActivePowerMaxPhC();
    AttributeInt16* getReactivePowerPhC();
    AttributeUInt16* getApparentPowerPhC();
    AttributeInt8* getPowerFactorPhC();
    AttributeUInt16* getAverageRmsVoltageMeasPeriodPhC();
    AttributeUInt16* getAverageRmsOverVoltageCounterPhC();
    AttributeUInt16* getAverageUnderVoltageCounterPhC();
    AttributeUInt16* getRmsExtremeOverVoltagePeriodPhC();
    AttributeUInt16* getRmsExtremeUnderVoltagePeriodPhC();
    AttributeUInt16* getRmsVoltageSagPeriodPhC();
    AttributeUInt16* getRmsVoltageSwellPeriodPhC();

    virtual Status onGetProfileInfoCommand() {
        return Status::UnsupportedAttribute;
    }

    void sendGetProfileInfoCommand(DeviceManager& deviceManager, uint8_t endpointId);

    virtual Status onGetMeasurementProfileCommand(uint16_t attrId, uint32_t starttime, uint8_t numofuntervals) {
        return Status::UnsupportedAttribute;
    }

    void sendGetMeasurementProfileCommand(DeviceManager& deviceManager, uint8_t endpointId, uint16_t attrId, uint32_t starttime, uint8_t numofuntervals);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class HaDiagnosticAttribute: uint16_t {
    NumberOfResets = 0,
    PersistentMemoryWrites = 1,
    MacRxBcast = 256,
    MacTxBcast = 257,
    MacRxUcast = 258,
    MacTxUcast = 259,
    MacTxUcastRetry = 260,
    MacTxUcastFail = 261,
    APSRxBcast = 262,
    APSTxBcast = 263,
    APSRxUcast = 264,
    APSTxUcastSuccess = 265,
    APSTxUcastRetry = 266,
    APSTxUcastFail = 267,
    RouteDiscInitiated = 268,
    NeighborAdded = 269,
    NeighborRemoved = 270,
    NeighborStale = 271,
    JoinIndication = 272,
    ChildMoved = 273,
    NwkFcFailure = 274,
    ApsFcFailure = 275,
    ApsUnauthorizedKey = 276,
    NwkDecryptFailures = 277,
    ApsDecryptFailures = 278,
    PacketBufferAllocateFailures = 279,
    RelayedUcast = 280,
    PhyToMacQueueLimitReached = 281,
    PacketValidateDropCount = 282,
    AverageMacRetryPerApsMessageSent = 283,
    LastMessageLqi = 284,
    LastMessageRssi = 285,
    DanfossSystemStatusCode = 16384,
    DanfossSystemStatusWater = 16896,
    DanfossMultimasterRole = 16897,
    SchneiderMeterStatus = 65281,
    SchneiderDiagnosticRegister1 = 65282,
    SchneiderCommunicationQuality = 16384,
};

class HaDiagnosticCluster: public Cluster {
public:
    HaDiagnosticCluster(ClusterType type = ClusterType::Input) : Cluster(2821, type) {
    }
    AttributeUInt16* getNumberOfResets();
    AttributeUInt16* getPersistentMemoryWrites();
    AttributeUInt32* getMacRxBcast();
    AttributeUInt32* getMacTxBcast();
    AttributeUInt32* getMacRxUcast();
    AttributeUInt32* getMacTxUcast();
    AttributeUInt16* getMacTxUcastRetry();
    AttributeUInt16* getMacTxUcastFail();
    AttributeUInt16* getAPSRxBcast();
    AttributeUInt16* getAPSTxBcast();
    AttributeUInt16* getAPSRxUcast();
    AttributeUInt16* getAPSTxUcastSuccess();
    AttributeUInt16* getAPSTxUcastRetry();
    AttributeUInt16* getAPSTxUcastFail();
    AttributeUInt16* getRouteDiscInitiated();
    AttributeUInt16* getNeighborAdded();
    AttributeUInt16* getNeighborRemoved();
    AttributeUInt16* getNeighborStale();
    AttributeUInt16* getJoinIndication();
    AttributeUInt16* getChildMoved();
    AttributeUInt16* getNwkFcFailure();
    AttributeUInt16* getApsFcFailure();
    AttributeUInt16* getApsUnauthorizedKey();
    AttributeUInt16* getNwkDecryptFailures();
    AttributeUInt16* getApsDecryptFailures();
    AttributeUInt16* getPacketBufferAllocateFailures();
    AttributeUInt16* getRelayedUcast();
    AttributeUInt16* getPhyToMacQueueLimitReached();
    AttributeUInt16* getPacketValidateDropCount();
    AttributeUInt16* getAverageMacRetryPerApsMessageSent();
    AttributeUInt8* getLastMessageLqi();
    AttributeInt8* getLastMessageRssi();
};

enum class TouchlinkAttribute: uint16_t {
};

class TouchlinkCluster: public Cluster {
public:
    TouchlinkCluster(ClusterType type = ClusterType::Input) : Cluster(4096, type) {
    }

    class ScanRequestCommandResponse {
        uint32_t _transactionID{};
        uint8_t _rssiCorrection{};
        uint8_t _zigbeeInformation{};
        uint8_t _touchlinkInformation{};
        uint16_t _keyBitmask{};
        uint32_t _responseID{};
        uint64_t _extendedPanID{};
        uint8_t _networkUpdateID{};
        uint8_t _logicalChannel{};
        uint16_t _panID{};
        uint16_t _networkAddress{};
        uint8_t _numberOfSubDevices{};
        uint8_t _totalGroupIdentifiers{};

    public:
        uint32_t getTransactionID() { return _transactionID; }
        void setTransactionID(uint32_t transactionID) { _transactionID = transactionID; }

        uint8_t getRssiCorrection() { return _rssiCorrection; }
        void setRssiCorrection(uint8_t rssiCorrection) { _rssiCorrection = rssiCorrection; }

        uint8_t getZigbeeInformation() { return _zigbeeInformation; }
        void setZigbeeInformation(uint8_t zigbeeInformation) { _zigbeeInformation = zigbeeInformation; }

        uint8_t getTouchlinkInformation() { return _touchlinkInformation; }
        void setTouchlinkInformation(uint8_t touchlinkInformation) { _touchlinkInformation = touchlinkInformation; }

        uint16_t getKeyBitmask() { return _keyBitmask; }
        void setKeyBitmask(uint16_t keyBitmask) { _keyBitmask = keyBitmask; }

        uint32_t getResponseID() { return _responseID; }
        void setResponseID(uint32_t responseID) { _responseID = responseID; }

        uint64_t getExtendedPanID() { return _extendedPanID; }
        void setExtendedPanID(uint64_t extendedPanID) { _extendedPanID = extendedPanID; }

        uint8_t getNetworkUpdateID() { return _networkUpdateID; }
        void setNetworkUpdateID(uint8_t networkUpdateID) { _networkUpdateID = networkUpdateID; }

        uint8_t getLogicalChannel() { return _logicalChannel; }
        void setLogicalChannel(uint8_t logicalChannel) { _logicalChannel = logicalChannel; }

        uint16_t getPanID() { return _panID; }
        void setPanID(uint16_t panID) { _panID = panID; }

        uint16_t getNetworkAddress() { return _networkAddress; }
        void setNetworkAddress(uint16_t networkAddress) { _networkAddress = networkAddress; }

        uint8_t getNumberOfSubDevices() { return _numberOfSubDevices; }
        void setNumberOfSubDevices(uint8_t numberOfSubDevices) { _numberOfSubDevices = numberOfSubDevices; }

        uint8_t getTotalGroupIdentifiers() { return _totalGroupIdentifiers; }
        void setTotalGroupIdentifiers(uint8_t totalGroupIdentifiers) { _totalGroupIdentifiers = totalGroupIdentifiers; }

    };

    virtual Status onScanRequestCommand(uint32_t transactionID, uint8_t zigbeeInformation, uint8_t touchlinkInformation, ScanRequestCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status onIdentifyRequestCommand(uint32_t transactionID, uint16_t duration) {
        return Status::UnsupportedAttribute;
    }

    void sendIdentifyRequestCommand(DeviceManager& deviceManager, uint8_t endpointId, uint32_t transactionID, uint16_t duration);

    virtual Status onResetToFactoryNewCommand(uint32_t transactionID) {
        return Status::UnsupportedAttribute;
    }

    void sendResetToFactoryNewCommand(DeviceManager& deviceManager, uint8_t endpointId, uint32_t transactionID);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class WiserDeviceInfoAttribute: uint16_t {
    DeviceInfo = 32,
};

class WiserDeviceInfoCluster: public Cluster {
public:
    WiserDeviceInfoCluster(ClusterType type = ClusterType::Input) : Cluster(65027, type) {
    }
    AttributeString* getDeviceInfo();
};

enum class ZosungIRTransmitAttribute: uint16_t {
};

class ZosungIRTransmitCluster: public Cluster {
public:
    ZosungIRTransmitCluster(ClusterType type = ClusterType::Input) : Cluster(60672, type) {
    }

    virtual Status onZosungSendIRCode00Command(uint16_t seq, uint32_t length, uint32_t unk1, uint16_t unk2, uint8_t unk3, uint8_t cmd, uint16_t unk4) {
        return Status::UnsupportedAttribute;
    }

    void sendZosungSendIRCode00Command(DeviceManager& deviceManager, uint8_t endpointId, uint16_t seq, uint32_t length, uint32_t unk1, uint16_t unk2, uint8_t unk3, uint8_t cmd, uint16_t unk4);

    virtual Status onZosungSendIRCode01Command(uint8_t zero, uint16_t seq, uint32_t length, uint32_t unk1, uint16_t unk2, uint8_t unk3, uint8_t cmd, uint16_t unk4) {
        return Status::UnsupportedAttribute;
    }

    void sendZosungSendIRCode01Command(DeviceManager& deviceManager, uint8_t endpointId, uint8_t zero, uint16_t seq, uint32_t length, uint32_t unk1, uint16_t unk2, uint8_t unk3, uint8_t cmd, uint16_t unk4);

    virtual Status onZosungSendIRCode02Command(uint16_t seq, uint32_t position, uint8_t maxlen) {
        return Status::UnsupportedAttribute;
    }

    void sendZosungSendIRCode02Command(DeviceManager& deviceManager, uint8_t endpointId, uint16_t seq, uint32_t position, uint8_t maxlen);

    virtual Status onZosungSendIRCode03Command(uint8_t zero, uint16_t seq, uint32_t position, Buffer msgpart, uint8_t msgpartcrc) {
        return Status::UnsupportedAttribute;
    }

    void sendZosungSendIRCode03Command(DeviceManager& deviceManager, uint8_t endpointId, uint8_t zero, uint16_t seq, uint32_t position, Buffer msgpart, uint8_t msgpartcrc);

    virtual Status onZosungSendIRCode04Command(uint8_t zero0, uint16_t seq, uint16_t zero1) {
        return Status::UnsupportedAttribute;
    }

    void sendZosungSendIRCode04Command(DeviceManager& deviceManager, uint8_t endpointId, uint8_t zero0, uint16_t seq, uint16_t zero1);

    virtual Status onZosungSendIRCode05Command(uint16_t seq, uint16_t zero) {
        return Status::UnsupportedAttribute;
    }

    void sendZosungSendIRCode05Command(DeviceManager& deviceManager, uint8_t endpointId, uint16_t seq, uint16_t zero);

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

enum class ZosungIRControlAttribute: uint16_t {
};

class ZosungIRControlCluster: public Cluster {
public:
    ZosungIRControlCluster(ClusterType type = ClusterType::Input) : Cluster(57348, type) {
    }
};
