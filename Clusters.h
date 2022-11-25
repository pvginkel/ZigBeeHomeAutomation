#pragma once

class GenBasicCluster: public Cluster {
public:
    GenBasicCluster() : Cluster(0) {
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

    virtual Status resetFactDefaultCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GenPowerCfgCluster: public Cluster {
public:
    GenPowerCfgCluster() : Cluster(1) {
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

class GenDeviceTempCfgCluster: public Cluster {
public:
    GenDeviceTempCfgCluster() : Cluster(2) {
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

class GenIdentifyCluster: public Cluster {
public:
    GenIdentifyCluster() : Cluster(3) {
    }
    AttributeUInt16* getIdentifyTime();

    virtual Status identifyCommand(uint16_t identifytime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status identifyQueryCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status ezmodeInvokeCommand(uint8_t action) {
        return Status::UnsupportedAttribute;
    }

    virtual Status updateCommissionStateCommand(uint8_t action, uint8_t commstatemask) {
        return Status::UnsupportedAttribute;
    }

    virtual Status triggerEffectCommand(uint8_t effectid, uint8_t effectvariant) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GenGroupsCluster: public Cluster {
public:
    GenGroupsCluster() : Cluster(4) {
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

    virtual Status addCommand(uint16_t groupid, String groupname, AddCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status viewCommand(uint16_t groupid) {
        return Status::UnsupportedAttribute;
    }

    class RemoveCommandResponse {
        uint8_t _status{};
        uint16_t _groupid{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

        uint16_t getGroupid() { return _groupid; }
        void setGroupid(uint16_t groupid) { _groupid = groupid; }

    };

    virtual Status removeCommand(uint16_t groupid, RemoveCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status removeAllCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status addIfIdentifyingCommand(uint16_t groupid, String groupname) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GenScenesCluster: public Cluster {
public:
    GenScenesCluster() : Cluster(5) {
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

    virtual Status removeCommand(uint16_t groupid, uint8_t sceneid, RemoveCommandResponse& response) {
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

    virtual Status removeAllCommand(uint16_t groupid, RemoveAllCommandResponse& response) {
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

    virtual Status storeCommand(uint16_t groupid, uint8_t sceneid, StoreCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status recallCommand(uint16_t groupid, uint8_t sceneid) {
        return Status::UnsupportedAttribute;
    }

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

    virtual Status copyCommand(uint8_t mode, uint16_t groupidfrom, uint8_t sceneidfrom, uint16_t groupidto, uint8_t sceneidto, CopyCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status tradfriArrowSingleCommand(uint16_t value, uint16_t value2) {
        return Status::UnsupportedAttribute;
    }

    virtual Status tradfriArrowHoldCommand(uint16_t value) {
        return Status::UnsupportedAttribute;
    }

    virtual Status tradfriArrowReleaseCommand(uint16_t value) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GenOnOffCluster: public Cluster {
public:
    GenOnOffCluster() : Cluster(6) {
    }
    AttributeUInt8* getOnOff();
    AttributeUInt8* getGlobalSceneCtrl();
    AttributeUInt16* getOnTime();
    AttributeUInt16* getOffWaitTime();
    AttributeUInt8* getStartUpOnOff();
    AttributeUInt8* getMoesStartUpOnOff();

    virtual Status offCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status onCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status toggleCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status offWithEffectCommand(uint8_t effectid, uint8_t effectvariant) {
        return Status::UnsupportedAttribute;
    }

    virtual Status onWithRecallGlobalSceneCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status onWithTimedOffCommand(uint8_t ctrlbits, uint16_t ontime, uint16_t offwaittime) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GenOnOffSwitchCfgCluster: public Cluster {
public:
    GenOnOffSwitchCfgCluster() : Cluster(7) {
    }
    AttributeUInt8* getSwitchType();
    AttributeUInt8* getSwitchActions();
};

class GenLevelCtrlCluster: public Cluster {
public:
    GenLevelCtrlCluster() : Cluster(8) {
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

    virtual Status moveToLevelCommand(uint8_t level, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveCommand(uint8_t movemode, uint8_t rate) {
        return Status::UnsupportedAttribute;
    }

    virtual Status stepCommand(uint8_t stepmode, uint8_t stepsize, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status stopCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveToLevelWithOnOffCommand(uint8_t level, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveWithOnOffCommand(uint8_t movemode, uint8_t rate) {
        return Status::UnsupportedAttribute;
    }

    virtual Status stepWithOnOffCommand(uint8_t stepmode, uint8_t stepsize, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status stopWithOnOffCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveToLevelTuyaCommand(uint16_t level, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GenAlarmsCluster: public Cluster {
public:
    GenAlarmsCluster() : Cluster(9) {
    }
    AttributeUInt16* getAlarmCount();

    virtual Status resetCommand(uint8_t alarmcode, uint16_t clusterid) {
        return Status::UnsupportedAttribute;
    }

    virtual Status resetAllCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status getAlarmCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status resetLogCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status publishEventLogCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GenTimeCluster: public Cluster {
public:
    GenTimeCluster() : Cluster(10) {
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

class GenRssiLocationCluster: public Cluster {
public:
    GenRssiLocationCluster() : Cluster(11) {
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

    virtual Status setAbsoluteCommand(int16_t coord1, int16_t coord2, int16_t coord3, int16_t power, uint16_t pathlossexponent) {
        return Status::UnsupportedAttribute;
    }

    virtual Status setDevCfgCommand(int16_t power, uint16_t pathlossexponent, uint16_t calperiod, uint8_t numrssimeasurements, uint16_t reportingperiod) {
        return Status::UnsupportedAttribute;
    }

    virtual Status getDevCfgCommand(uint64_t targetaddr) {
        return Status::UnsupportedAttribute;
    }

    virtual Status getDataCommand(uint8_t getdatainfo, uint8_t numrsp, uint64_t targetaddr) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GenAnalogInputCluster: public Cluster {
public:
    GenAnalogInputCluster() : Cluster(12) {
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

class GenAnalogOutputCluster: public Cluster {
public:
    GenAnalogOutputCluster() : Cluster(13) {
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

class GenAnalogValueCluster: public Cluster {
public:
    GenAnalogValueCluster() : Cluster(14) {
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

class GenBinaryInputCluster: public Cluster {
public:
    GenBinaryInputCluster() : Cluster(15) {
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

class GenBinaryOutputCluster: public Cluster {
public:
    GenBinaryOutputCluster() : Cluster(16) {
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

class GenBinaryValueCluster: public Cluster {
public:
    GenBinaryValueCluster() : Cluster(17) {
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

class GenMultistateInputCluster: public Cluster {
public:
    GenMultistateInputCluster() : Cluster(18) {
    }
    AttributeString* getDescription();
    AttributeUInt16* getNumberOfStates();
    AttributeUInt8* getOutOfService();
    AttributeUInt16* getPresentValue();
    AttributeUInt8* getReliability();
    AttributeUInt8* getStatusFlags();
    AttributeUInt32* getApplicationType();
};

class GenMultistateOutputCluster: public Cluster {
public:
    GenMultistateOutputCluster() : Cluster(19) {
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

class GenMultistateValueCluster: public Cluster {
public:
    GenMultistateValueCluster() : Cluster(20) {
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

class GenCommissioningCluster: public Cluster {
public:
    GenCommissioningCluster() : Cluster(21) {
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

    virtual Status restartDeviceCommand(uint8_t options, uint8_t delay, uint8_t jitter) {
        return Status::UnsupportedAttribute;
    }

    virtual Status saveStartupParamsCommand(uint8_t options, uint8_t index) {
        return Status::UnsupportedAttribute;
    }

    virtual Status restoreStartupParamsCommand(uint8_t options, uint8_t index) {
        return Status::UnsupportedAttribute;
    }

    virtual Status resetStartupParamsCommand(uint8_t options, uint8_t index) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GenOtaCluster: public Cluster {
public:
    GenOtaCluster() : Cluster(25) {
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

    virtual Status queryNextImageRequestCommand(uint8_t fieldControl, uint16_t manufacturerCode, uint16_t imageType, uint32_t fileVersion, QueryNextImageRequestCommandResponse& response) {
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

    virtual Status upgradeEndRequestCommand(uint8_t status, uint16_t manufacturerCode, uint16_t imageType, uint32_t fileVersion, UpgradeEndRequestCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GenPollCtrlCluster: public Cluster {
public:
    GenPollCtrlCluster() : Cluster(32) {
    }
    AttributeUInt32* getCheckinInterval();
    AttributeUInt32* getLongPollInterval();
    AttributeUInt16* getShortPollInterval();
    AttributeUInt16* getFastPollTimeout();
    AttributeUInt32* getCheckinIntervalMin();
    AttributeUInt32* getLongPollIntervalMin();
    AttributeUInt16* getFastPollTimeoutMax();

    virtual Status checkinRspCommand(bool startFastPolling, uint16_t fastPollTimeout) {
        return Status::UnsupportedAttribute;
    }

    virtual Status fastPollStopCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status setLongPollIntervalCommand(uint32_t newLongPollInterval) {
        return Status::UnsupportedAttribute;
    }

    virtual Status setShortPollIntervalCommand(uint16_t newShortPollInterval) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GreenPowerCluster: public Cluster {
public:
    GreenPowerCluster() : Cluster(33) {
    }
};

class MobileDeviceCfgCluster: public Cluster {
public:
    MobileDeviceCfgCluster() : Cluster(34) {
    }
    AttributeUInt16* getKeepAliveTime();
    AttributeUInt16* getRejoinTimeout();
};

class NeighborCleaningCluster: public Cluster {
public:
    NeighborCleaningCluster() : Cluster(35) {
    }
    AttributeUInt16* getNeighborCleaningTimeout();
};

class NearestGatewayCluster: public Cluster {
public:
    NearestGatewayCluster() : Cluster(36) {
    }
    AttributeUInt16* getNearestGateway();
    AttributeUInt16* getNewMobileNode();
};

class ClosuresShadeCfgCluster: public Cluster {
public:
    ClosuresShadeCfgCluster() : Cluster(256) {
    }
    AttributeUInt16* getPhysicalClosedLimit();
    AttributeUInt8* getMotorStepSize();
    AttributeUInt8* getStatus();
    AttributeUInt16* getLosedLimit();
    AttributeUInt8* getMode();
};

class ClosuresDoorLockCluster: public Cluster {
public:
    ClosuresDoorLockCluster() : Cluster(257) {
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

    virtual Status lockDoorCommand(String pincodevalue, LockDoorCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class UnlockDoorCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status unlockDoorCommand(String pincodevalue, UnlockDoorCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ToggleDoorCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status toggleDoorCommand(String pincodevalue, ToggleDoorCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class UnlockWithTimeoutCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status unlockWithTimeoutCommand(uint16_t timeout, String pincodevalue, UnlockWithTimeoutCommandResponse& response) {
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

    virtual Status getLogRecordCommand(uint16_t logindex, GetLogRecordCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetPinCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status setPinCodeCommand(uint16_t userid, uint8_t userstatus, uint8_t usertype, String pincodevalue, SetPinCodeCommandResponse& response) {
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

    virtual Status getPinCodeCommand(uint16_t userid, GetPinCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearPinCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status clearPinCodeCommand(uint16_t userid, ClearPinCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearAllPinCodesCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status clearAllPinCodesCommand(ClearAllPinCodesCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetUserStatusCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status setUserStatusCommand(uint16_t userid, uint8_t userstatus, SetUserStatusCommandResponse& response) {
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

    virtual Status getUserStatusCommand(uint16_t userid, GetUserStatusCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetWeekDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status setWeekDayScheduleCommand(uint8_t scheduleid, uint16_t userid, uint8_t daysmask, uint8_t starthour, uint8_t startminute, uint8_t endhour, uint8_t endminute, SetWeekDayScheduleCommandResponse& response) {
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

    virtual Status getWeekDayScheduleCommand(uint8_t scheduleid, uint16_t userid, GetWeekDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearWeekDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status clearWeekDayScheduleCommand(uint8_t scheduleid, uint16_t userid, ClearWeekDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetYearDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status setYearDayScheduleCommand(uint8_t scheduleid, uint16_t userid, uint32_t zigbeelocalstarttime, uint32_t zigbeelocalendtime, SetYearDayScheduleCommandResponse& response) {
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

    virtual Status getYearDayScheduleCommand(uint8_t scheduleid, uint16_t userid, GetYearDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearYearDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status clearYearDayScheduleCommand(uint8_t scheduleid, uint16_t userid, ClearYearDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetHolidayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status setHolidayScheduleCommand(uint8_t holidayscheduleid, uint32_t zigbeelocalstarttime, uint32_t zigbeelocalendtime, uint8_t opermodelduringholiday, SetHolidayScheduleCommandResponse& response) {
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

    virtual Status getHolidayScheduleCommand(uint8_t holidayscheduleid, GetHolidayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearHolidayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status clearHolidayScheduleCommand(uint8_t holidayscheduleid, ClearHolidayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetUserTypeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status setUserTypeCommand(uint16_t userid, uint8_t usertype, SetUserTypeCommandResponse& response) {
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

    virtual Status getUserTypeCommand(uint16_t userid, GetUserTypeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetRfidCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status setRfidCodeCommand(uint16_t userid, uint8_t userstatus, uint8_t usertype, String pincodevalue, SetRfidCodeCommandResponse& response) {
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

    virtual Status getRfidCodeCommand(uint16_t userid, GetRfidCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearRfidCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status clearRfidCodeCommand(uint16_t userid, ClearRfidCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearAllRfidCodesCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t status) { _status = status; }

    };

    virtual Status clearAllRfidCodesCommand(ClearAllRfidCodesCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class ClosuresWindowCoveringCluster: public Cluster {
public:
    ClosuresWindowCoveringCluster() : Cluster(258) {
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

    virtual Status upOpenCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status downCloseCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status stopCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status goToLiftValueCommand(uint16_t liftvalue) {
        return Status::UnsupportedAttribute;
    }

    virtual Status goToLiftPercentageCommand(uint8_t percentageliftvalue) {
        return Status::UnsupportedAttribute;
    }

    virtual Status goToTiltValueCommand(uint16_t tiltvalue) {
        return Status::UnsupportedAttribute;
    }

    virtual Status goToTiltPercentageCommand(uint8_t percentagetiltvalue) {
        return Status::UnsupportedAttribute;
    }

    virtual Status elkoStopOrStepLiftPercentageCommand(uint16_t direction, uint16_t stepvalue) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class BarrierControlCluster: public Cluster {
public:
    BarrierControlCluster() : Cluster(259) {
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

    virtual Status goToPercentCommand(uint8_t percentOpen) {
        return Status::UnsupportedAttribute;
    }

    virtual Status stopCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class HvacPumpCfgCtrlCluster: public Cluster {
public:
    HvacPumpCfgCtrlCluster() : Cluster(512) {
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

class HvacThermostatCluster: public Cluster {
public:
    HvacThermostatCluster() : Cluster(513) {
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

    virtual Status setpointRaiseLowerCommand(uint8_t mode, int8_t amount) {
        return Status::UnsupportedAttribute;
    }

    virtual Status getWeeklyScheduleCommand(uint8_t daystoreturn, uint8_t modetoreturn) {
        return Status::UnsupportedAttribute;
    }

    virtual Status clearWeeklyScheduleCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status getRelayStatusLogCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status danfossSetpointCommandCommand(uint8_t setpointType, int16_t setpoint) {
        return Status::UnsupportedAttribute;
    }

    virtual Status schneiderWiserThermostatBoostCommand(uint8_t command, uint8_t enable, uint16_t temperature, uint16_t duration) {
        return Status::UnsupportedAttribute;
    }

    virtual Status wiserSmartSetSetpointCommand(uint8_t operatingmode, uint8_t zonemode, int16_t setpoint, uint8_t reserved) {
        return Status::UnsupportedAttribute;
    }

    virtual Status wiserSmartCalibrateValveCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status plugwiseCalibrateValveCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class HvacFanCtrlCluster: public Cluster {
public:
    HvacFanCtrlCluster() : Cluster(514) {
    }
    AttributeUInt8* getFanMode();
    AttributeUInt8* getFanModeSequence();
};

class HvacDehumidificationCtrlCluster: public Cluster {
public:
    HvacDehumidificationCtrlCluster() : Cluster(515) {
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

class HvacUserInterfaceCfgCluster: public Cluster {
public:
    HvacUserInterfaceCfgCluster() : Cluster(516) {
    }
    AttributeUInt8* getTempDisplayMode();
    AttributeUInt8* getKeypadLockout();
    AttributeUInt8* getProgrammingVisibility();
};

class LightingColorCtrlCluster: public Cluster {
public:
    LightingColorCtrlCluster() : Cluster(768) {
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

    virtual Status moveToHueCommand(uint8_t hue, uint8_t direction, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveHueCommand(uint8_t movemode, uint8_t rate) {
        return Status::UnsupportedAttribute;
    }

    virtual Status stepHueCommand(uint8_t stepmode, uint8_t stepsize, uint8_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveToSaturationCommand(uint8_t saturation, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveSaturationCommand(uint8_t movemode, uint8_t rate) {
        return Status::UnsupportedAttribute;
    }

    virtual Status stepSaturationCommand(uint8_t stepmode, uint8_t stepsize, uint8_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveToHueAndSaturationCommand(uint8_t hue, uint8_t saturation, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveToColorCommand(uint16_t colorx, uint16_t colory, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveColorCommand(int16_t ratex, int16_t ratey) {
        return Status::UnsupportedAttribute;
    }

    virtual Status stepColorCommand(int16_t stepx, int16_t stepy, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveToColorTempCommand(uint16_t colortemp, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status enhancedMoveToHueCommand(uint16_t enhancehue, uint8_t direction, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status enhancedMoveHueCommand(uint8_t movemode, uint16_t rate) {
        return Status::UnsupportedAttribute;
    }

    virtual Status enhancedStepHueCommand(uint8_t stepmode, uint16_t stepsize, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status enhancedMoveToHueAndSaturationCommand(uint16_t enhancehue, uint8_t saturation, uint16_t transtime) {
        return Status::UnsupportedAttribute;
    }

    virtual Status colorLoopSetCommand(uint8_t updateflags, uint8_t action, uint8_t direction, uint16_t time, uint16_t starthue) {
        return Status::UnsupportedAttribute;
    }

    virtual Status stopMoveStepCommand(uint8_t bits, uint8_t bytee, uint8_t action, uint8_t direction, uint16_t time, uint16_t starthue) {
        return Status::UnsupportedAttribute;
    }

    virtual Status moveColorTempCommand(uint8_t movemode, uint16_t rate, uint16_t minimum, uint16_t maximum) {
        return Status::UnsupportedAttribute;
    }

    virtual Status stepColorTempCommand(uint8_t stepmode, uint16_t stepsize, uint16_t transtime, uint16_t minimum, uint16_t maximum) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class LightingBallastCfgCluster: public Cluster {
public:
    LightingBallastCfgCluster() : Cluster(769) {
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

class MsIlluminanceMeasurementCluster: public Cluster {
public:
    MsIlluminanceMeasurementCluster() : Cluster(1024) {
    }
    AttributeUInt16* getMeasuredValue();
    AttributeUInt16* getMinMeasuredValue();
    AttributeUInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
    AttributeUInt8* getLightSensorType();
};

class MsIlluminanceLevelSensingCluster: public Cluster {
public:
    MsIlluminanceLevelSensingCluster() : Cluster(1025) {
    }
    AttributeUInt8* getLevelStatus();
    AttributeUInt8* getLightSensorType();
    AttributeUInt16* getIlluminanceTargetLevel();
};

class MsTemperatureMeasurementCluster: public Cluster {
public:
    MsTemperatureMeasurementCluster() : Cluster(1026) {
    }
    AttributeInt16* getMeasuredValue();
    AttributeInt16* getMinMeasuredValue();
    AttributeInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
};

class MsPressureMeasurementCluster: public Cluster {
public:
    MsPressureMeasurementCluster() : Cluster(1027) {
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

class MsFlowMeasurementCluster: public Cluster {
public:
    MsFlowMeasurementCluster() : Cluster(1028) {
    }
    AttributeUInt16* getMeasuredValue();
    AttributeUInt16* getMinMeasuredValue();
    AttributeUInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
};

class MsRelativeHumidityCluster: public Cluster {
public:
    MsRelativeHumidityCluster() : Cluster(1029) {
    }
    AttributeUInt16* getMeasuredValue();
    AttributeUInt16* getMinMeasuredValue();
    AttributeUInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
};

class MsOccupancySensingCluster: public Cluster {
public:
    MsOccupancySensingCluster() : Cluster(1030) {
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

class MsSoilMoistureCluster: public Cluster {
public:
    MsSoilMoistureCluster() : Cluster(1032) {
    }
    AttributeUInt16* getMeasuredValue();
    AttributeUInt16* getMinMeasuredValue();
    AttributeUInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
};

class PHMeasurementCluster: public Cluster {
public:
    PHMeasurementCluster() : Cluster(1033) {
    }
    AttributeUInt16* getMeasuredValue();
    AttributeUInt16* getMinMeasuredValue();
    AttributeUInt16* getMaxMeasuredValue();
    AttributeUInt16* getTolerance();
};

class MsCO2Cluster: public Cluster {
public:
    MsCO2Cluster() : Cluster(1037) {
    }
    AttributeSingle* getMeasuredValue();
    AttributeSingle* getMinMeasuredValue();
    AttributeSingle* getMaxMeasuredValue();
};

class SsIasZoneCluster: public Cluster {
public:
    SsIasZoneCluster() : Cluster(1280) {
    }
    AttributeUInt8* getZoneState();
    AttributeUInt16* getZoneType();
    AttributeUInt16* getZoneStatus();
    AttributeUInt64* getIasCieAddr();
    AttributeUInt8* getZoneId();
    AttributeUInt8* getNumZoneSensitivityLevelsSupported();
    AttributeUInt8* getCurrentZoneSensitivityLevel();

    virtual Status enrollRspCommand(uint8_t enrollrspcode, uint8_t zoneid) {
        return Status::UnsupportedAttribute;
    }

    virtual Status initNormalOpModeCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status initTestModeCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class SsIasAceCluster: public Cluster {
public:
    SsIasAceCluster() : Cluster(1281) {
    }

    class ArmCommandResponse {
        uint8_t _armnotification{};

    public:
        uint8_t getArmnotification() { return _armnotification; }
        void setArmnotification(uint8_t armnotification) { _armnotification = armnotification; }

    };

    virtual Status armCommand(uint8_t armmode, String code, uint8_t zoneid, ArmCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status emergencyCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status fireCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status panicCommand() {
        return Status::UnsupportedAttribute;
    }

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

    virtual Status getZoneIDMapCommand(GetZoneIDMapCommandResponse& response) {
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

    virtual Status getZoneInfoCommand(uint8_t zoneid, GetZoneInfoCommandResponse& response) {
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

    virtual Status getPanelStatusCommand(GetPanelStatusCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status getBypassedZoneListCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class SsIasWdCluster: public Cluster {
public:
    SsIasWdCluster() : Cluster(1282) {
    }
    AttributeUInt16* getMaxDuration();

    virtual Status startWarningCommand(uint8_t startwarninginfo, uint16_t warningduration, uint8_t strobedutycycle, uint8_t strobelevel) {
        return Status::UnsupportedAttribute;
    }

    virtual Status squawkCommand(uint8_t squawkinfo) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class PiGenericTunnelCluster: public Cluster {
public:
    PiGenericTunnelCluster() : Cluster(1536) {
    }
    AttributeUInt16* getMaxIncomeTransSize();
    AttributeUInt16* getMaxOutgoTransSize();
    AttributeOctstr* getProtocolAddr();

    virtual Status matchProtocolAddrCommand(String protocoladdr) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class PiBacnetProtocolTunnelCluster: public Cluster {
public:
    PiBacnetProtocolTunnelCluster() : Cluster(1537) {
    }

    virtual Status transferNpduCommand(uint8_t npdu) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class PiAnalogInputRegCluster: public Cluster {
public:
    PiAnalogInputRegCluster() : Cluster(1538) {
    }
    AttributeSingle* getCovIncrement();
    AttributeString* getDeviceType();
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeUInt8* getUpdateInterval();
    AttributeString* getProfileName();
};

class PiAnalogInputExtCluster: public Cluster {
public:
    PiAnalogInputExtCluster() : Cluster(1539) {
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

    virtual Status transferApduCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status connectReqCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status disconnectReqCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status connectStatusNotiCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class PiAnalogOutputRegCluster: public Cluster {
public:
    PiAnalogOutputRegCluster() : Cluster(1540) {
    }
    AttributeSingle* getCovIncrement();
    AttributeString* getDeviceType();
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeUInt8* getUpdateInterval();
    AttributeString* getProfileName();
};

class PiAnalogOutputExtCluster: public Cluster {
public:
    PiAnalogOutputExtCluster() : Cluster(1541) {
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

class PiAnalogValueRegCluster: public Cluster {
public:
    PiAnalogValueRegCluster() : Cluster(1542) {
    }
    AttributeSingle* getCovIncrement();
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeString* getProfileName();
};

class PiAnalogValueExtCluster: public Cluster {
public:
    PiAnalogValueExtCluster() : Cluster(1543) {
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

class PiBinaryInputRegCluster: public Cluster {
public:
    PiBinaryInputRegCluster() : Cluster(1544) {
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

class PiBinaryInputExtCluster: public Cluster {
public:
    PiBinaryInputExtCluster() : Cluster(1545) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt8* getAlarmValue();
    AttributeUInt16* getNotificationClass();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

class PiBinaryOutputRegCluster: public Cluster {
public:
    PiBinaryOutputRegCluster() : Cluster(1546) {
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

class PiBinaryOutputExtCluster: public Cluster {
public:
    PiBinaryOutputExtCluster() : Cluster(1547) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt16* getNotificationClass();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

class PiBinaryValueRegCluster: public Cluster {
public:
    PiBinaryValueRegCluster() : Cluster(1548) {
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

class PiBinaryValueExtCluster: public Cluster {
public:
    PiBinaryValueExtCluster() : Cluster(1549) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt8* getAlarmValue();
    AttributeUInt16* getNotificationClass();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

class PiMultistateInputRegCluster: public Cluster {
public:
    PiMultistateInputRegCluster() : Cluster(1550) {
    }
    AttributeString* getDeviceType();
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeString* getProfileName();
};

class PiMultistateInputExtCluster: public Cluster {
public:
    PiMultistateInputExtCluster() : Cluster(1551) {
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

class PiMultistateOutputRegCluster: public Cluster {
public:
    PiMultistateOutputRegCluster() : Cluster(1552) {
    }
    AttributeString* getDeviceType();
    AttributeUInt8* getFeedBackValue();
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeString* getProfileName();
};

class PiMultistateOutputExtCluster: public Cluster {
public:
    PiMultistateOutputExtCluster() : Cluster(1553) {
    }
    AttributeUInt8* getAckedTransitions();
    AttributeUInt16* getNotificationClass();
    AttributeUInt8* getEventEnable();
    AttributeUInt8* getEventState();
    AttributeUInt8* getNotifyType();
    AttributeUInt8* getTimeDelay();
};

class PiMultistateValueRegCluster: public Cluster {
public:
    PiMultistateValueRegCluster() : Cluster(1554) {
    }
    AttributeUInt32* getObjectId();
    AttributeString* getObjectName();
    AttributeUInt16* getObjectType();
    AttributeString* getProfileName();
};

class PiMultistateValueExtCluster: public Cluster {
public:
    PiMultistateValueExtCluster() : Cluster(1555) {
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

class Pi11073ProtocolTunnelCluster: public Cluster {
public:
    Pi11073ProtocolTunnelCluster() : Cluster(1556) {
    }
    AttributeUInt64* getManagerTarget();
    AttributeUInt8* getManagerEndpoint();
    AttributeUInt8* getConnected();
    AttributeUInt8* getPreemptible();
    AttributeUInt16* getIdleTimeout();

    virtual Status transferApduCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status connectReqCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status disconnectReqCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status connectStatusNotiCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class PiIso7818ProtocolTunnelCluster: public Cluster {
public:
    PiIso7818ProtocolTunnelCluster() : Cluster(1557) {
    }
    AttributeUInt8* getStatus();
};

class PiRetailTunnelCluster: public Cluster {
public:
    PiRetailTunnelCluster() : Cluster(1559) {
    }
    AttributeUInt16* getManufacturerCode();
    AttributeUInt16* getMsProfile();
};

class SeMeteringCluster: public Cluster {
public:
    SeMeteringCluster() : Cluster(1794) {
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

    virtual Status getProfileCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status reqMirrorCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status mirrorRemCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status reqFastPollModeCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status getSnapshotCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status takeSnapshotCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status mirrorReportAttrRspCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status owonGetHistoryRecordCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status owonStopSendingHistoricalRecordCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class TelecommunicationsInformationCluster: public Cluster {
public:
    TelecommunicationsInformationCluster() : Cluster(2304) {
    }
    AttributeString* getNodeDescription();
    AttributeUInt8* getDeliveryEnable();
    AttributeUInt32* getPushInformationTimer();
    AttributeUInt8* getEnableSecureConfiguration();
    AttributeUInt16* getNumberOfContents();
    AttributeUInt16* getContentRootID();
};

class TelecommunicationsVoiceOverZigbeeCluster: public Cluster {
public:
    TelecommunicationsVoiceOverZigbeeCluster() : Cluster(2308) {
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

class TelecommunicationsChattingCluster: public Cluster {
public:
    TelecommunicationsChattingCluster() : Cluster(2309) {
    }
    AttributeUInt16* getUID();
    AttributeString* getNickname();
    AttributeUInt16* getCID();
    AttributeString* getName();
    AttributeUInt8* getEnableAddChat();
};

class HaApplianceIdentificationCluster: public Cluster {
public:
    HaApplianceIdentificationCluster() : Cluster(2816) {
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

class HaMeterIdentificationCluster: public Cluster {
public:
    HaMeterIdentificationCluster() : Cluster(2817) {
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

class HaApplianceEventsAlertsCluster: public Cluster {
public:
    HaApplianceEventsAlertsCluster() : Cluster(2818) {
    }

    virtual Status getAlertsCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class HaApplianceStatisticsCluster: public Cluster {
public:
    HaApplianceStatisticsCluster() : Cluster(2819) {
    }
    AttributeUInt32* getLogMaxSize();
    AttributeUInt8* getLogQueueMaxSize();

    virtual Status logCommand(uint32_t logid) {
        return Status::UnsupportedAttribute;
    }

    virtual Status logQueueCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class HaElectricalMeasurementCluster: public Cluster {
public:
    HaElectricalMeasurementCluster() : Cluster(2820) {
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

    virtual Status getProfileInfoCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status getMeasurementProfileCommand(uint16_t attrId, uint32_t starttime, uint8_t numofuntervals) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class HaDiagnosticCluster: public Cluster {
public:
    HaDiagnosticCluster() : Cluster(2821) {
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

class TouchlinkCluster: public Cluster {
public:
    TouchlinkCluster() : Cluster(4096) {
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

    virtual Status scanRequestCommand(uint32_t transactionID, uint8_t zigbeeInformation, uint8_t touchlinkInformation, ScanRequestCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status identifyRequestCommand(uint32_t transactionID, uint16_t duration) {
        return Status::UnsupportedAttribute;
    }

    virtual Status resetToFactoryNewCommand(uint32_t transactionID) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class WiserDeviceInfoCluster: public Cluster {
public:
    WiserDeviceInfoCluster() : Cluster(65027) {
    }
    AttributeString* getDeviceInfo();
};

class ZosungIRTransmitCluster: public Cluster {
public:
    ZosungIRTransmitCluster() : Cluster(60672) {
    }

    virtual Status zosungSendIRCode00Command(uint16_t seq, uint32_t length, uint32_t unk1, uint16_t unk2, uint8_t unk3, uint8_t cmd, uint16_t unk4) {
        return Status::UnsupportedAttribute;
    }

    virtual Status zosungSendIRCode01Command(uint8_t zero, uint16_t seq, uint32_t length, uint32_t unk1, uint16_t unk2, uint8_t unk3, uint8_t cmd, uint16_t unk4) {
        return Status::UnsupportedAttribute;
    }

    virtual Status zosungSendIRCode02Command(uint16_t seq, uint32_t position, uint8_t maxlen) {
        return Status::UnsupportedAttribute;
    }

    virtual Status zosungSendIRCode03Command(uint8_t zero, uint16_t seq, uint32_t position, Buffer msgpart, uint8_t msgpartcrc) {
        return Status::UnsupportedAttribute;
    }

    virtual Status zosungSendIRCode04Command(uint8_t zero0, uint16_t seq, uint16_t zero1) {
        return Status::UnsupportedAttribute;
    }

    virtual Status zosungSendIRCode05Command(uint16_t seq, uint16_t zero) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class ZosungIRControlCluster: public Cluster {
public:
    ZosungIRControlCluster() : Cluster(57348) {
    }
};
