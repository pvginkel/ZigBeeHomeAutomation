#pragma once

class GenBasicCluster: public Cluster {
public:
    GenBasicCluster() : Cluster(0) {
    }

    uint8_t getZclVersion() { return getUInt8(0); }
    void setZclVersion(uint8_t zclVersion) { setUInt8(0, zclVersion); }

    uint8_t getAppVersion() { return getUInt8(1); }
    void setAppVersion(uint8_t appVersion) { setUInt8(1, appVersion); }

    uint8_t getStackVersion() { return getUInt8(2); }
    void setStackVersion(uint8_t stackVersion) { setUInt8(2, stackVersion); }

    uint8_t getHwVersion() { return getUInt8(3); }
    void setHwVersion(uint8_t hwVersion) { setUInt8(3, hwVersion); }

    String getManufacturerName() { return getString(4); }
    void setManufacturerName(const String& manufacturerName) { setString(4, manufacturerName); }

    String getModelId() { return getString(5); }
    void setModelId(const String& modelId) { setString(5, modelId); }

    String getDateCode() { return getString(6); }
    void setDateCode(const String& dateCode) { setString(6, dateCode); }

    uint8_t getPowerSource() { return getEnum8(7); }
    void setPowerSource(uint8_t powerSource) { setEnum8(7, powerSource); }

    uint8_t getAppProfileVersion() { return getEnum8(8); }
    void setAppProfileVersion(uint8_t appProfileVersion) { setEnum8(8, appProfileVersion); }

    String getSwBuildId() { return getString(16384); }
    void setSwBuildId(const String& swBuildId) { setString(16384, swBuildId); }

    String getLocationDesc() { return getString(16); }
    void setLocationDesc(const String& locationDesc) { setString(16, locationDesc); }

    uint8_t getPhysicalEnv() { return getEnum8(17); }
    void setPhysicalEnv(uint8_t physicalEnv) { setEnum8(17, physicalEnv); }

    bool getDeviceEnabled() { return getBool(18); }
    void setDeviceEnabled(bool deviceEnabled) { setBool(18, deviceEnabled); }

    uint8_t getAlarmMask() { return getMap8(19); }
    void setAlarmMask(uint8_t alarmMask) { setMap8(19, alarmMask); }

    uint8_t getDisableLocalConfig() { return getMap8(20); }
    void setDisableLocalConfig(uint8_t disableLocalConfig) { setMap8(20, disableLocalConfig); }

    virtual Status resetFactDefaultCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override;
};

class GenPowerCfgCluster: public Cluster {
public:
    GenPowerCfgCluster() : Cluster(1) {
    }

    uint16_t getMainsVoltage() { return getUInt16(0); }
    void setMainsVoltage(uint16_t mainsVoltage) { setUInt16(0, mainsVoltage); }

    uint8_t getMainsFrequency() { return getUInt8(1); }
    void setMainsFrequency(uint8_t mainsFrequency) { setUInt8(1, mainsFrequency); }

    uint8_t getMainsAlarmMask() { return getMap8(16); }
    void setMainsAlarmMask(uint8_t mainsAlarmMask) { setMap8(16, mainsAlarmMask); }

    uint16_t getMainsVoltMinThres() { return getUInt16(17); }
    void setMainsVoltMinThres(uint16_t mainsVoltMinThres) { setUInt16(17, mainsVoltMinThres); }

    uint16_t getMainsVoltMaxThres() { return getUInt16(18); }
    void setMainsVoltMaxThres(uint16_t mainsVoltMaxThres) { setUInt16(18, mainsVoltMaxThres); }

    uint16_t getMainsVoltageDwellTripPoint() { return getUInt16(19); }
    void setMainsVoltageDwellTripPoint(uint16_t mainsVoltageDwellTripPoint) { setUInt16(19, mainsVoltageDwellTripPoint); }

    uint8_t getBatteryVoltage() { return getUInt8(32); }
    void setBatteryVoltage(uint8_t batteryVoltage) { setUInt8(32, batteryVoltage); }

    uint8_t getBatteryPercentageRemaining() { return getUInt8(33); }
    void setBatteryPercentageRemaining(uint8_t batteryPercentageRemaining) { setUInt8(33, batteryPercentageRemaining); }

    String getBatteryManufacturer() { return getString(48); }
    void setBatteryManufacturer(const String& batteryManufacturer) { setString(48, batteryManufacturer); }

    uint8_t getBatterySize() { return getEnum8(49); }
    void setBatterySize(uint8_t batterySize) { setEnum8(49, batterySize); }

    uint16_t getBatteryAHrRating() { return getUInt16(50); }
    void setBatteryAHrRating(uint16_t batteryAHrRating) { setUInt16(50, batteryAHrRating); }

    uint8_t getBatteryQuantity() { return getUInt8(51); }
    void setBatteryQuantity(uint8_t batteryQuantity) { setUInt8(51, batteryQuantity); }

    uint8_t getBatteryRatedVoltage() { return getUInt8(52); }
    void setBatteryRatedVoltage(uint8_t batteryRatedVoltage) { setUInt8(52, batteryRatedVoltage); }

    uint8_t getBatteryAlarmMask() { return getMap8(53); }
    void setBatteryAlarmMask(uint8_t batteryAlarmMask) { setMap8(53, batteryAlarmMask); }

    uint8_t getBatteryVoltMinThres() { return getUInt8(54); }
    void setBatteryVoltMinThres(uint8_t batteryVoltMinThres) { setUInt8(54, batteryVoltMinThres); }

    uint8_t getBatteryVoltThres1() { return getUInt8(55); }
    void setBatteryVoltThres1(uint8_t batteryVoltThres1) { setUInt8(55, batteryVoltThres1); }

    uint8_t getBatteryVoltThres2() { return getUInt8(56); }
    void setBatteryVoltThres2(uint8_t batteryVoltThres2) { setUInt8(56, batteryVoltThres2); }

    uint8_t getBatteryVoltThres3() { return getUInt8(57); }
    void setBatteryVoltThres3(uint8_t batteryVoltThres3) { setUInt8(57, batteryVoltThres3); }

    uint8_t getBatteryPercentMinThres() { return getUInt8(58); }
    void setBatteryPercentMinThres(uint8_t batteryPercentMinThres) { setUInt8(58, batteryPercentMinThres); }

    uint8_t getBatteryPercentThres1() { return getUInt8(59); }
    void setBatteryPercentThres1(uint8_t batteryPercentThres1) { setUInt8(59, batteryPercentThres1); }

    uint8_t getBatteryPercentThres2() { return getUInt8(60); }
    void setBatteryPercentThres2(uint8_t batteryPercentThres2) { setUInt8(60, batteryPercentThres2); }

    uint8_t getBatteryPercentThres3() { return getUInt8(61); }
    void setBatteryPercentThres3(uint8_t batteryPercentThres3) { setUInt8(61, batteryPercentThres3); }

    uint32_t getBatteryAlarmState() { return getMap32(62); }
    void setBatteryAlarmState(uint32_t batteryAlarmState) { setMap32(62, batteryAlarmState); }
};

class GenDeviceTempCfgCluster: public Cluster {
public:
    GenDeviceTempCfgCluster() : Cluster(2) {
    }

    int16_t getCurrentTemperature() { return getInt16(0); }
    void setCurrentTemperature(int16_t currentTemperature) { setInt16(0, currentTemperature); }

    int16_t getMinTempExperienced() { return getInt16(1); }
    void setMinTempExperienced(int16_t minTempExperienced) { setInt16(1, minTempExperienced); }

    int16_t getMaxTempExperienced() { return getInt16(2); }
    void setMaxTempExperienced(int16_t maxTempExperienced) { setInt16(2, maxTempExperienced); }

    uint16_t getOverTempTotalDwell() { return getUInt16(3); }
    void setOverTempTotalDwell(uint16_t overTempTotalDwell) { setUInt16(3, overTempTotalDwell); }

    uint8_t getDevTempAlarmMask() { return getMap8(16); }
    void setDevTempAlarmMask(uint8_t devTempAlarmMask) { setMap8(16, devTempAlarmMask); }

    int16_t getLowTempThres() { return getInt16(17); }
    void setLowTempThres(int16_t lowTempThres) { setInt16(17, lowTempThres); }

    int16_t getHighTempThres() { return getInt16(18); }
    void setHighTempThres(int16_t highTempThres) { setInt16(18, highTempThres); }

    uint32_t getLowTempDwellTripPoint() { return getUInt24(19); }
    void setLowTempDwellTripPoint(uint32_t lowTempDwellTripPoint) { setUInt24(19, lowTempDwellTripPoint); }

    uint32_t getHighTempDwellTripPoint() { return getUInt24(20); }
    void setHighTempDwellTripPoint(uint32_t highTempDwellTripPoint) { setUInt24(20, highTempDwellTripPoint); }
};

class GenIdentifyCluster: public Cluster {
public:
    GenIdentifyCluster() : Cluster(3) {
    }

    uint16_t getIdentifyTime() { return getUInt16(0); }
    void setIdentifyTime(uint16_t identifyTime) { setUInt16(0, identifyTime); }

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

    uint8_t getNameSupport() { return getMap8(0); }
    void setNameSupport(uint8_t nameSupport) { setMap8(0, nameSupport); }

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

    uint8_t getCount() { return getUInt8(0); }
    void setCount(uint8_t count) { setUInt8(0, count); }

    uint8_t getCurrentScene() { return getUInt8(1); }
    void setCurrentScene(uint8_t currentScene) { setUInt8(1, currentScene); }

    uint16_t getCurrentGroup() { return getUInt16(2); }
    void setCurrentGroup(uint16_t currentGroup) { setUInt16(2, currentGroup); }

    bool getSceneValid() { return getBool(3); }
    void setSceneValid(bool sceneValid) { setBool(3, sceneValid); }

    uint8_t getNameSupport() { return getMap8(4); }
    void setNameSupport(uint8_t nameSupport) { setMap8(4, nameSupport); }

    uint64_t getLastCfgBy() { return getEUI64(5); }
    void setLastCfgBy(uint64_t lastCfgBy) { setEUI64(5, lastCfgBy); }

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

    bool getOnOff() { return getBool(0); }
    void setOnOff(bool onOff) { setBool(0, onOff); }

    bool getGlobalSceneCtrl() { return getBool(16384); }
    void setGlobalSceneCtrl(bool globalSceneCtrl) { setBool(16384, globalSceneCtrl); }

    uint16_t getOnTime() { return getUInt16(16385); }
    void setOnTime(uint16_t onTime) { setUInt16(16385, onTime); }

    uint16_t getOffWaitTime() { return getUInt16(16386); }
    void setOffWaitTime(uint16_t offWaitTime) { setUInt16(16386, offWaitTime); }

    uint8_t getStartUpOnOff() { return getEnum8(16387); }
    void setStartUpOnOff(uint8_t startUpOnOff) { setEnum8(16387, startUpOnOff); }

    uint8_t getMoesStartUpOnOff() { return getEnum8(32770); }
    void setMoesStartUpOnOff(uint8_t moesStartUpOnOff) { setEnum8(32770, moesStartUpOnOff); }

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

    uint8_t getSwitchType() { return getEnum8(0); }
    void setSwitchType(uint8_t switchType) { setEnum8(0, switchType); }

    uint8_t getSwitchActions() { return getEnum8(16); }
    void setSwitchActions(uint8_t switchActions) { setEnum8(16, switchActions); }
};

class GenLevelCtrlCluster: public Cluster {
public:
    GenLevelCtrlCluster() : Cluster(8) {
    }

    uint8_t getCurrentLevel() { return getUInt8(0); }
    void setCurrentLevel(uint8_t currentLevel) { setUInt8(0, currentLevel); }

    uint16_t getRemainingTime() { return getUInt16(1); }
    void setRemainingTime(uint16_t remainingTime) { setUInt16(1, remainingTime); }

    uint8_t getMinLevel() { return getUInt8(2); }
    void setMinLevel(uint8_t minLevel) { setUInt8(2, minLevel); }

    uint8_t getMaxLevel() { return getUInt8(3); }
    void setMaxLevel(uint8_t maxLevel) { setUInt8(3, maxLevel); }

    uint8_t getOptions() { return getMap8(15); }
    void setOptions(uint8_t options) { setMap8(15, options); }

    uint16_t getOnOffTransitionTime() { return getUInt16(16); }
    void setOnOffTransitionTime(uint16_t onOffTransitionTime) { setUInt16(16, onOffTransitionTime); }

    uint8_t getOnLevel() { return getUInt8(17); }
    void setOnLevel(uint8_t onLevel) { setUInt8(17, onLevel); }

    uint16_t getOnTransitionTime() { return getUInt16(18); }
    void setOnTransitionTime(uint16_t onTransitionTime) { setUInt16(18, onTransitionTime); }

    uint16_t getOffTransitionTime() { return getUInt16(19); }
    void setOffTransitionTime(uint16_t offTransitionTime) { setUInt16(19, offTransitionTime); }

    uint16_t getDefaultMoveRate() { return getUInt16(20); }
    void setDefaultMoveRate(uint16_t defaultMoveRate) { setUInt16(20, defaultMoveRate); }

    uint8_t getStartUpCurrentLevel() { return getUInt8(16384); }
    void setStartUpCurrentLevel(uint8_t startUpCurrentLevel) { setUInt8(16384, startUpCurrentLevel); }

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

    uint16_t getAlarmCount() { return getUInt16(0); }
    void setAlarmCount(uint16_t alarmCount) { setUInt16(0, alarmCount); }

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

    uint32_t getTime() { return getUTC(0); }
    void setTime(uint32_t time) { setUTC(0, time); }

    uint8_t getTimeStatus() { return getMap8(1); }
    void setTimeStatus(uint8_t timeStatus) { setMap8(1, timeStatus); }

    int32_t getTimeZone() { return getInt32(2); }
    void setTimeZone(int32_t timeZone) { setInt32(2, timeZone); }

    uint32_t getDstStart() { return getUInt32(3); }
    void setDstStart(uint32_t dstStart) { setUInt32(3, dstStart); }

    uint32_t getDstEnd() { return getUInt32(4); }
    void setDstEnd(uint32_t dstEnd) { setUInt32(4, dstEnd); }

    int32_t getDstShift() { return getInt32(5); }
    void setDstShift(int32_t dstShift) { setInt32(5, dstShift); }

    uint32_t getStandardTime() { return getUInt32(6); }
    void setStandardTime(uint32_t standardTime) { setUInt32(6, standardTime); }

    uint32_t getLocalTime() { return getUInt32(7); }
    void setLocalTime(uint32_t localTime) { setUInt32(7, localTime); }

    uint32_t getLastSetTime() { return getUTC(8); }
    void setLastSetTime(uint32_t lastSetTime) { setUTC(8, lastSetTime); }

    uint32_t getValidUntilTime() { return getUTC(9); }
    void setValidUntilTime(uint32_t validUntilTime) { setUTC(9, validUntilTime); }
};

class GenRssiLocationCluster: public Cluster {
public:
    GenRssiLocationCluster() : Cluster(11) {
    }

    uint8_t getType() { return getData8(0); }
    void setType(uint8_t type) { setData8(0, type); }

    uint8_t getMethod() { return getEnum8(1); }
    void setMethod(uint8_t method) { setEnum8(1, method); }

    uint16_t getAge() { return getUInt16(2); }
    void setAge(uint16_t age) { setUInt16(2, age); }

    uint8_t getQualityMeasure() { return getUInt8(3); }
    void setQualityMeasure(uint8_t qualityMeasure) { setUInt8(3, qualityMeasure); }

    uint8_t getNumOfDevices() { return getUInt8(4); }
    void setNumOfDevices(uint8_t numOfDevices) { setUInt8(4, numOfDevices); }

    int16_t getCoordinate1() { return getInt16(16); }
    void setCoordinate1(int16_t coordinate1) { setInt16(16, coordinate1); }

    int16_t getCoordinate2() { return getInt16(17); }
    void setCoordinate2(int16_t coordinate2) { setInt16(17, coordinate2); }

    int16_t getCoordinate3() { return getInt16(18); }
    void setCoordinate3(int16_t coordinate3) { setInt16(18, coordinate3); }

    int16_t getPower() { return getInt16(19); }
    void setPower(int16_t power) { setInt16(19, power); }

    uint16_t getPathLossExponent() { return getUInt16(20); }
    void setPathLossExponent(uint16_t pathLossExponent) { setUInt16(20, pathLossExponent); }

    uint16_t getReportingPeriod() { return getUInt16(21); }
    void setReportingPeriod(uint16_t reportingPeriod) { setUInt16(21, reportingPeriod); }

    uint16_t getCalcPeriod() { return getUInt16(22); }
    void setCalcPeriod(uint16_t calcPeriod) { setUInt16(22, calcPeriod); }

    uint16_t getNumRSSIMeasurements() { return getUInt16(23); }
    void setNumRSSIMeasurements(uint16_t numRSSIMeasurements) { setUInt16(23, numRSSIMeasurements); }

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

    String getDescription() { return getString(28); }
    void setDescription(const String& description) { setString(28, description); }

    float getMaxPresentValue() { return getSingle(65); }
    void setMaxPresentValue(float maxPresentValue) { setSingle(65, maxPresentValue); }

    float getMinPresentValue() { return getSingle(69); }
    void setMinPresentValue(float minPresentValue) { setSingle(69, minPresentValue); }

    bool getOutOfService() { return getBool(81); }
    void setOutOfService(bool outOfService) { setBool(81, outOfService); }

    float getPresentValue() { return getSingle(85); }
    void setPresentValue(float presentValue) { setSingle(85, presentValue); }

    uint8_t getReliability() { return getEnum8(103); }
    void setReliability(uint8_t reliability) { setEnum8(103, reliability); }

    float getResolution() { return getSingle(106); }
    void setResolution(float resolution) { setSingle(106, resolution); }

    uint8_t getStatusFlags() { return getMap8(111); }
    void setStatusFlags(uint8_t statusFlags) { setMap8(111, statusFlags); }

    uint16_t getEngineeringUnits() { return getEnum16(117); }
    void setEngineeringUnits(uint16_t engineeringUnits) { setEnum16(117, engineeringUnits); }

    uint32_t getApplicationType() { return getUInt32(256); }
    void setApplicationType(uint32_t applicationType) { setUInt32(256, applicationType); }
};

class GenAnalogOutputCluster: public Cluster {
public:
    GenAnalogOutputCluster() : Cluster(13) {
    }

    String getDescription() { return getString(28); }
    void setDescription(const String& description) { setString(28, description); }

    float getMaxPresentValue() { return getSingle(65); }
    void setMaxPresentValue(float maxPresentValue) { setSingle(65, maxPresentValue); }

    float getMinPresentValue() { return getSingle(69); }
    void setMinPresentValue(float minPresentValue) { setSingle(69, minPresentValue); }

    bool getOutOfService() { return getBool(81); }
    void setOutOfService(bool outOfService) { setBool(81, outOfService); }

    float getPresentValue() { return getSingle(85); }
    void setPresentValue(float presentValue) { setSingle(85, presentValue); }

    uint8_t getReliability() { return getEnum8(103); }
    void setReliability(uint8_t reliability) { setEnum8(103, reliability); }

    float getRelinquishDefault() { return getSingle(104); }
    void setRelinquishDefault(float relinquishDefault) { setSingle(104, relinquishDefault); }

    float getResolution() { return getSingle(106); }
    void setResolution(float resolution) { setSingle(106, resolution); }

    uint8_t getStatusFlags() { return getMap8(111); }
    void setStatusFlags(uint8_t statusFlags) { setMap8(111, statusFlags); }

    uint16_t getEngineeringUnits() { return getEnum16(117); }
    void setEngineeringUnits(uint16_t engineeringUnits) { setEnum16(117, engineeringUnits); }

    uint32_t getApplicationType() { return getUInt32(256); }
    void setApplicationType(uint32_t applicationType) { setUInt32(256, applicationType); }
};

class GenAnalogValueCluster: public Cluster {
public:
    GenAnalogValueCluster() : Cluster(14) {
    }

    String getDescription() { return getString(28); }
    void setDescription(const String& description) { setString(28, description); }

    bool getOutOfService() { return getBool(81); }
    void setOutOfService(bool outOfService) { setBool(81, outOfService); }

    float getPresentValue() { return getSingle(85); }
    void setPresentValue(float presentValue) { setSingle(85, presentValue); }

    uint8_t getReliability() { return getEnum8(103); }
    void setReliability(uint8_t reliability) { setEnum8(103, reliability); }

    float getRelinquishDefault() { return getSingle(104); }
    void setRelinquishDefault(float relinquishDefault) { setSingle(104, relinquishDefault); }

    uint8_t getStatusFlags() { return getMap8(111); }
    void setStatusFlags(uint8_t statusFlags) { setMap8(111, statusFlags); }

    uint16_t getEngineeringUnits() { return getEnum16(117); }
    void setEngineeringUnits(uint16_t engineeringUnits) { setEnum16(117, engineeringUnits); }

    uint32_t getApplicationType() { return getUInt32(256); }
    void setApplicationType(uint32_t applicationType) { setUInt32(256, applicationType); }
};

class GenBinaryInputCluster: public Cluster {
public:
    GenBinaryInputCluster() : Cluster(15) {
    }

    String getActiveText() { return getString(4); }
    void setActiveText(const String& activeText) { setString(4, activeText); }

    String getDescription() { return getString(28); }
    void setDescription(const String& description) { setString(28, description); }

    String getInactiveText() { return getString(46); }
    void setInactiveText(const String& inactiveText) { setString(46, inactiveText); }

    bool getOutOfService() { return getBool(81); }
    void setOutOfService(bool outOfService) { setBool(81, outOfService); }

    uint8_t getPolarity() { return getEnum8(84); }
    void setPolarity(uint8_t polarity) { setEnum8(84, polarity); }

    bool getPresentValue() { return getBool(85); }
    void setPresentValue(bool presentValue) { setBool(85, presentValue); }

    uint8_t getReliability() { return getEnum8(103); }
    void setReliability(uint8_t reliability) { setEnum8(103, reliability); }

    uint8_t getStatusFlags() { return getMap8(111); }
    void setStatusFlags(uint8_t statusFlags) { setMap8(111, statusFlags); }

    uint32_t getApplicationType() { return getUInt32(256); }
    void setApplicationType(uint32_t applicationType) { setUInt32(256, applicationType); }
};

class GenBinaryOutputCluster: public Cluster {
public:
    GenBinaryOutputCluster() : Cluster(16) {
    }

    String getActiveText() { return getString(4); }
    void setActiveText(const String& activeText) { setString(4, activeText); }

    String getDescription() { return getString(28); }
    void setDescription(const String& description) { setString(28, description); }

    String getInactiveText() { return getString(46); }
    void setInactiveText(const String& inactiveText) { setString(46, inactiveText); }

    uint32_t getMinimumOffTime() { return getUInt32(66); }
    void setMinimumOffTime(uint32_t minimumOffTime) { setUInt32(66, minimumOffTime); }

    uint32_t getMinimumOnTime() { return getUInt32(67); }
    void setMinimumOnTime(uint32_t minimumOnTime) { setUInt32(67, minimumOnTime); }

    bool getOutOfService() { return getBool(81); }
    void setOutOfService(bool outOfService) { setBool(81, outOfService); }

    uint8_t getPolarity() { return getEnum8(84); }
    void setPolarity(uint8_t polarity) { setEnum8(84, polarity); }

    bool getPresentValue() { return getBool(85); }
    void setPresentValue(bool presentValue) { setBool(85, presentValue); }

    uint8_t getReliability() { return getEnum8(103); }
    void setReliability(uint8_t reliability) { setEnum8(103, reliability); }

    bool getRelinquishDefault() { return getBool(104); }
    void setRelinquishDefault(bool relinquishDefault) { setBool(104, relinquishDefault); }

    uint8_t getStatusFlags() { return getMap8(111); }
    void setStatusFlags(uint8_t statusFlags) { setMap8(111, statusFlags); }

    uint32_t getApplicationType() { return getUInt32(256); }
    void setApplicationType(uint32_t applicationType) { setUInt32(256, applicationType); }
};

class GenBinaryValueCluster: public Cluster {
public:
    GenBinaryValueCluster() : Cluster(17) {
    }

    String getActiveText() { return getString(4); }
    void setActiveText(const String& activeText) { setString(4, activeText); }

    String getDescription() { return getString(28); }
    void setDescription(const String& description) { setString(28, description); }

    String getInactiveText() { return getString(46); }
    void setInactiveText(const String& inactiveText) { setString(46, inactiveText); }

    uint32_t getMinimumOffTime() { return getUInt32(66); }
    void setMinimumOffTime(uint32_t minimumOffTime) { setUInt32(66, minimumOffTime); }

    uint32_t getMinimumOnTime() { return getUInt32(67); }
    void setMinimumOnTime(uint32_t minimumOnTime) { setUInt32(67, minimumOnTime); }

    bool getOutOfService() { return getBool(81); }
    void setOutOfService(bool outOfService) { setBool(81, outOfService); }

    bool getPresentValue() { return getBool(85); }
    void setPresentValue(bool presentValue) { setBool(85, presentValue); }

    uint8_t getReliability() { return getEnum8(103); }
    void setReliability(uint8_t reliability) { setEnum8(103, reliability); }

    bool getRelinquishDefault() { return getBool(104); }
    void setRelinquishDefault(bool relinquishDefault) { setBool(104, relinquishDefault); }

    uint8_t getStatusFlags() { return getMap8(111); }
    void setStatusFlags(uint8_t statusFlags) { setMap8(111, statusFlags); }

    uint32_t getApplicationType() { return getUInt32(256); }
    void setApplicationType(uint32_t applicationType) { setUInt32(256, applicationType); }
};

class GenMultistateInputCluster: public Cluster {
public:
    GenMultistateInputCluster() : Cluster(18) {
    }

    String getDescription() { return getString(28); }
    void setDescription(const String& description) { setString(28, description); }

    uint16_t getNumberOfStates() { return getUInt16(74); }
    void setNumberOfStates(uint16_t numberOfStates) { setUInt16(74, numberOfStates); }

    bool getOutOfService() { return getBool(81); }
    void setOutOfService(bool outOfService) { setBool(81, outOfService); }

    uint16_t getPresentValue() { return getUInt16(85); }
    void setPresentValue(uint16_t presentValue) { setUInt16(85, presentValue); }

    uint8_t getReliability() { return getEnum8(103); }
    void setReliability(uint8_t reliability) { setEnum8(103, reliability); }

    uint8_t getStatusFlags() { return getMap8(111); }
    void setStatusFlags(uint8_t statusFlags) { setMap8(111, statusFlags); }

    uint32_t getApplicationType() { return getUInt32(256); }
    void setApplicationType(uint32_t applicationType) { setUInt32(256, applicationType); }
};

class GenMultistateOutputCluster: public Cluster {
public:
    GenMultistateOutputCluster() : Cluster(19) {
    }

    String getDescription() { return getString(28); }
    void setDescription(const String& description) { setString(28, description); }

    uint16_t getNumberOfStates() { return getUInt16(74); }
    void setNumberOfStates(uint16_t numberOfStates) { setUInt16(74, numberOfStates); }

    bool getOutOfService() { return getBool(81); }
    void setOutOfService(bool outOfService) { setBool(81, outOfService); }

    uint16_t getPresentValue() { return getUInt16(85); }
    void setPresentValue(uint16_t presentValue) { setUInt16(85, presentValue); }

    uint8_t getReliability() { return getEnum8(103); }
    void setReliability(uint8_t reliability) { setEnum8(103, reliability); }

    uint16_t getRelinquishDefault() { return getUInt16(104); }
    void setRelinquishDefault(uint16_t relinquishDefault) { setUInt16(104, relinquishDefault); }

    uint8_t getStatusFlags() { return getMap8(111); }
    void setStatusFlags(uint8_t statusFlags) { setMap8(111, statusFlags); }

    uint32_t getApplicationType() { return getUInt32(256); }
    void setApplicationType(uint32_t applicationType) { setUInt32(256, applicationType); }
};

class GenMultistateValueCluster: public Cluster {
public:
    GenMultistateValueCluster() : Cluster(20) {
    }

    String getDescription() { return getString(28); }
    void setDescription(const String& description) { setString(28, description); }

    uint16_t getNumberOfStates() { return getUInt16(74); }
    void setNumberOfStates(uint16_t numberOfStates) { setUInt16(74, numberOfStates); }

    bool getOutOfService() { return getBool(81); }
    void setOutOfService(bool outOfService) { setBool(81, outOfService); }

    uint16_t getPresentValue() { return getUInt16(85); }
    void setPresentValue(uint16_t presentValue) { setUInt16(85, presentValue); }

    uint8_t getReliability() { return getEnum8(103); }
    void setReliability(uint8_t reliability) { setEnum8(103, reliability); }

    uint16_t getRelinquishDefault() { return getUInt16(104); }
    void setRelinquishDefault(uint16_t relinquishDefault) { setUInt16(104, relinquishDefault); }

    uint8_t getStatusFlags() { return getMap8(111); }
    void setStatusFlags(uint8_t statusFlags) { setMap8(111, statusFlags); }

    uint32_t getApplicationType() { return getUInt32(256); }
    void setApplicationType(uint32_t applicationType) { setUInt32(256, applicationType); }
};

class GenCommissioningCluster: public Cluster {
public:
    GenCommissioningCluster() : Cluster(21) {
    }

    uint16_t getShortress() { return getUInt16(0); }
    void setShortress(uint16_t shortress) { setUInt16(0, shortress); }

    uint64_t getExtendedPANId() { return getEUI64(1); }
    void setExtendedPANId(uint64_t extendedPANId) { setEUI64(1, extendedPANId); }

    uint16_t getPanId() { return getUInt16(2); }
    void setPanId(uint16_t panId) { setUInt16(2, panId); }

    uint32_t getChannelmask() { return getMap32(3); }
    void setChannelmask(uint32_t channelmask) { setMap32(3, channelmask); }

    uint8_t getProtocolVersion() { return getUInt8(4); }
    void setProtocolVersion(uint8_t protocolVersion) { setUInt8(4, protocolVersion); }

    uint8_t getStackProfile() { return getUInt8(5); }
    void setStackProfile(uint8_t stackProfile) { setUInt8(5, stackProfile); }

    uint8_t getStartupControl() { return getEnum8(6); }
    void setStartupControl(uint8_t startupControl) { setEnum8(6, startupControl); }

    uint64_t getTrustCenterress() { return getEUI64(16); }
    void setTrustCenterress(uint64_t trustCenterress) { setEUI64(16, trustCenterress); }

    bool getUseInsecureJoin() { return getBool(19); }
    void setUseInsecureJoin(bool useInsecureJoin) { setBool(19, useInsecureJoin); }

    uint8_t getNetworkKeySeqNum() { return getUInt8(21); }
    void setNetworkKeySeqNum(uint8_t networkKeySeqNum) { setUInt8(21, networkKeySeqNum); }

    uint8_t getNetworkKeyType() { return getEnum8(22); }
    void setNetworkKeyType(uint8_t networkKeyType) { setEnum8(22, networkKeyType); }

    uint16_t getNetworkManagerress() { return getUInt16(23); }
    void setNetworkManagerress(uint16_t networkManagerress) { setUInt16(23, networkManagerress); }

    uint8_t getScanAttempts() { return getUInt8(32); }
    void setScanAttempts(uint8_t scanAttempts) { setUInt8(32, scanAttempts); }

    uint16_t getTimeBetweenScans() { return getUInt16(33); }
    void setTimeBetweenScans(uint16_t timeBetweenScans) { setUInt16(33, timeBetweenScans); }

    uint16_t getRejoinInterval() { return getUInt16(34); }
    void setRejoinInterval(uint16_t rejoinInterval) { setUInt16(34, rejoinInterval); }

    uint16_t getMaxRejoinInterval() { return getUInt16(35); }
    void setMaxRejoinInterval(uint16_t maxRejoinInterval) { setUInt16(35, maxRejoinInterval); }

    uint16_t getIndirectPollRate() { return getUInt16(48); }
    void setIndirectPollRate(uint16_t indirectPollRate) { setUInt16(48, indirectPollRate); }

    uint8_t getParentRetryThreshold() { return getUInt8(49); }
    void setParentRetryThreshold(uint8_t parentRetryThreshold) { setUInt8(49, parentRetryThreshold); }

    bool getConcentratorFlag() { return getBool(64); }
    void setConcentratorFlag(bool concentratorFlag) { setBool(64, concentratorFlag); }

    uint8_t getConcentratorRus() { return getUInt8(65); }
    void setConcentratorRus(uint8_t concentratorRus) { setUInt8(65, concentratorRus); }

    uint8_t getConcentratorDiscoveryTime() { return getUInt8(66); }
    void setConcentratorDiscoveryTime(uint8_t concentratorDiscoveryTime) { setUInt8(66, concentratorDiscoveryTime); }

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

    uint64_t getUpgradeServerId() { return getEUI64(0); }
    void setUpgradeServerId(uint64_t upgradeServerId) { setEUI64(0, upgradeServerId); }

    uint32_t getFileOffset() { return getUInt32(1); }
    void setFileOffset(uint32_t fileOffset) { setUInt32(1, fileOffset); }

    uint32_t getCurrentFileVersion() { return getUInt32(2); }
    void setCurrentFileVersion(uint32_t currentFileVersion) { setUInt32(2, currentFileVersion); }

    uint16_t getCurrentZigbeeStackVersion() { return getUInt16(3); }
    void setCurrentZigbeeStackVersion(uint16_t currentZigbeeStackVersion) { setUInt16(3, currentZigbeeStackVersion); }

    uint32_t getDownloadedFileVersion() { return getUInt32(4); }
    void setDownloadedFileVersion(uint32_t downloadedFileVersion) { setUInt32(4, downloadedFileVersion); }

    uint16_t getDownloadedZigbeeStackVersion() { return getUInt16(5); }
    void setDownloadedZigbeeStackVersion(uint16_t downloadedZigbeeStackVersion) { setUInt16(5, downloadedZigbeeStackVersion); }

    uint8_t getImageUpgradeStatus() { return getEnum8(6); }
    void setImageUpgradeStatus(uint8_t imageUpgradeStatus) { setEnum8(6, imageUpgradeStatus); }

    uint16_t getManufacturerId() { return getUInt16(7); }
    void setManufacturerId(uint16_t manufacturerId) { setUInt16(7, manufacturerId); }

    uint16_t getImageTypeId() { return getUInt16(8); }
    void setImageTypeId(uint16_t imageTypeId) { setUInt16(8, imageTypeId); }

    uint16_t getMinimumBlockReqDelay() { return getUInt16(9); }
    void setMinimumBlockReqDelay(uint16_t minimumBlockReqDelay) { setUInt16(9, minimumBlockReqDelay); }

    uint32_t getImageStamp() { return getUInt32(10); }
    void setImageStamp(uint32_t imageStamp) { setUInt32(10, imageStamp); }

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

    uint32_t getCheckinInterval() { return getUInt32(0); }
    void setCheckinInterval(uint32_t checkinInterval) { setUInt32(0, checkinInterval); }

    uint32_t getLongPollInterval() { return getUInt32(1); }
    void setLongPollInterval(uint32_t longPollInterval) { setUInt32(1, longPollInterval); }

    uint16_t getShortPollInterval() { return getUInt16(2); }
    void setShortPollInterval(uint16_t shortPollInterval) { setUInt16(2, shortPollInterval); }

    uint16_t getFastPollTimeout() { return getUInt16(3); }
    void setFastPollTimeout(uint16_t fastPollTimeout) { setUInt16(3, fastPollTimeout); }

    uint32_t getCheckinIntervalMin() { return getUInt32(4); }
    void setCheckinIntervalMin(uint32_t checkinIntervalMin) { setUInt32(4, checkinIntervalMin); }

    uint32_t getLongPollIntervalMin() { return getUInt32(5); }
    void setLongPollIntervalMin(uint32_t longPollIntervalMin) { setUInt32(5, longPollIntervalMin); }

    uint16_t getFastPollTimeoutMax() { return getUInt16(6); }
    void setFastPollTimeoutMax(uint16_t fastPollTimeoutMax) { setUInt16(6, fastPollTimeoutMax); }

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

    uint16_t getKeepAliveTime() { return getUInt16(0); }
    void setKeepAliveTime(uint16_t keepAliveTime) { setUInt16(0, keepAliveTime); }

    uint16_t getRejoinTimeout() { return getUInt16(1); }
    void setRejoinTimeout(uint16_t rejoinTimeout) { setUInt16(1, rejoinTimeout); }
};

class NeighborCleaningCluster: public Cluster {
public:
    NeighborCleaningCluster() : Cluster(35) {
    }

    uint16_t getNeighborCleaningTimeout() { return getUInt16(0); }
    void setNeighborCleaningTimeout(uint16_t neighborCleaningTimeout) { setUInt16(0, neighborCleaningTimeout); }
};

class NearestGatewayCluster: public Cluster {
public:
    NearestGatewayCluster() : Cluster(36) {
    }

    uint16_t getNearestGateway() { return getUInt16(0); }
    void setNearestGateway(uint16_t nearestGateway) { setUInt16(0, nearestGateway); }

    uint16_t getNewMobileNode() { return getUInt16(1); }
    void setNewMobileNode(uint16_t newMobileNode) { setUInt16(1, newMobileNode); }
};

class ClosuresShadeCfgCluster: public Cluster {
public:
    ClosuresShadeCfgCluster() : Cluster(256) {
    }

    uint16_t getPhysicalClosedLimit() { return getUInt16(0); }
    void setPhysicalClosedLimit(uint16_t physicalClosedLimit) { setUInt16(0, physicalClosedLimit); }

    uint8_t getMotorStepSize() { return getUInt8(1); }
    void setMotorStepSize(uint8_t motorStepSize) { setUInt8(1, motorStepSize); }

    uint8_t getStatus() { return getMap8(2); }
    void setStatus(uint8_t status) { setMap8(2, status); }

    uint16_t getLosedLimit() { return getUInt16(16); }
    void setLosedLimit(uint16_t losedLimit) { setUInt16(16, losedLimit); }

    uint8_t getMode() { return getEnum8(18); }
    void setMode(uint8_t mode) { setEnum8(18, mode); }
};

class ClosuresDoorLockCluster: public Cluster {
public:
    ClosuresDoorLockCluster() : Cluster(257) {
    }

    uint8_t getLockState() { return getEnum8(0); }
    void setLockState(uint8_t lockState) { setEnum8(0, lockState); }

    uint16_t getLockType() { return getMap16(38); }
    void setLockType(uint16_t lockType) { setMap16(38, lockType); }

    bool getActuatorEnabled() { return getBool(2); }
    void setActuatorEnabled(bool actuatorEnabled) { setBool(2, actuatorEnabled); }

    uint8_t getDoorState() { return getEnum8(3); }
    void setDoorState(uint8_t doorState) { setEnum8(3, doorState); }

    uint32_t getDoorOpenEvents() { return getUInt32(4); }
    void setDoorOpenEvents(uint32_t doorOpenEvents) { setUInt32(4, doorOpenEvents); }

    uint32_t getDoorClosedEvents() { return getUInt32(5); }
    void setDoorClosedEvents(uint32_t doorClosedEvents) { setUInt32(5, doorClosedEvents); }

    uint16_t getOpenPeriod() { return getUInt16(6); }
    void setOpenPeriod(uint16_t openPeriod) { setUInt16(6, openPeriod); }

    uint16_t getNumOfLockRecordsSupported() { return getUInt16(16); }
    void setNumOfLockRecordsSupported(uint16_t numOfLockRecordsSupported) { setUInt16(16, numOfLockRecordsSupported); }

    uint16_t getNumOfTotalUsersSupported() { return getUInt16(17); }
    void setNumOfTotalUsersSupported(uint16_t numOfTotalUsersSupported) { setUInt16(17, numOfTotalUsersSupported); }

    uint16_t getNumOfPinUsersSupported() { return getUInt16(18); }
    void setNumOfPinUsersSupported(uint16_t numOfPinUsersSupported) { setUInt16(18, numOfPinUsersSupported); }

    uint16_t getNumOfRfidUsersSupported() { return getUInt16(19); }
    void setNumOfRfidUsersSupported(uint16_t numOfRfidUsersSupported) { setUInt16(19, numOfRfidUsersSupported); }

    uint8_t getNumOfWeekDaySchedulesSupportedPerUser() { return getUInt8(20); }
    void setNumOfWeekDaySchedulesSupportedPerUser(uint8_t numOfWeekDaySchedulesSupportedPerUser) { setUInt8(20, numOfWeekDaySchedulesSupportedPerUser); }

    uint8_t getNumOfYearDaySchedulesSupportedPerUser() { return getUInt8(21); }
    void setNumOfYearDaySchedulesSupportedPerUser(uint8_t numOfYearDaySchedulesSupportedPerUser) { setUInt8(21, numOfYearDaySchedulesSupportedPerUser); }

    uint8_t getNumOfHolidayScheduledsSupported() { return getUInt8(22); }
    void setNumOfHolidayScheduledsSupported(uint8_t numOfHolidayScheduledsSupported) { setUInt8(22, numOfHolidayScheduledsSupported); }

    uint8_t getMaxPinLen() { return getUInt8(23); }
    void setMaxPinLen(uint8_t maxPinLen) { setUInt8(23, maxPinLen); }

    uint8_t getMinPinLen() { return getUInt8(24); }
    void setMinPinLen(uint8_t minPinLen) { setUInt8(24, minPinLen); }

    uint8_t getMaxRfidLen() { return getUInt8(25); }
    void setMaxRfidLen(uint8_t maxRfidLen) { setUInt8(25, maxRfidLen); }

    uint8_t getMinRfidLen() { return getUInt8(26); }
    void setMinRfidLen(uint8_t minRfidLen) { setUInt8(26, minRfidLen); }

    bool getEnableLogging() { return getBool(32); }
    void setEnableLogging(bool enableLogging) { setBool(32, enableLogging); }

    String getLanguage() { return getString(33); }
    void setLanguage(const String& language) { setString(33, language); }

    uint8_t getLedSettings() { return getUInt8(34); }
    void setLedSettings(uint8_t ledSettings) { setUInt8(34, ledSettings); }

    uint32_t getAutoRelockTime() { return getUInt32(35); }
    void setAutoRelockTime(uint32_t autoRelockTime) { setUInt32(35, autoRelockTime); }

    uint8_t getSoundVolume() { return getUInt8(36); }
    void setSoundVolume(uint8_t soundVolume) { setUInt8(36, soundVolume); }

    uint32_t getOperatingMode() { return getUInt32(37); }
    void setOperatingMode(uint32_t operatingMode) { setUInt32(37, operatingMode); }

    uint16_t getDefaultConfigurationRegister() { return getMap16(39); }
    void setDefaultConfigurationRegister(uint16_t defaultConfigurationRegister) { setMap16(39, defaultConfigurationRegister); }

    bool getEnableLocalProgramming() { return getBool(40); }
    void setEnableLocalProgramming(bool enableLocalProgramming) { setBool(40, enableLocalProgramming); }

    bool getEnableOneTouchLocking() { return getBool(41); }
    void setEnableOneTouchLocking(bool enableOneTouchLocking) { setBool(41, enableOneTouchLocking); }

    bool getEnableInsideStatusLed() { return getBool(42); }
    void setEnableInsideStatusLed(bool enableInsideStatusLed) { setBool(42, enableInsideStatusLed); }

    bool getEnablePrivacyModeButton() { return getBool(43); }
    void setEnablePrivacyModeButton(bool enablePrivacyModeButton) { setBool(43, enablePrivacyModeButton); }

    uint8_t getWrongCodeEntryLimit() { return getUInt8(48); }
    void setWrongCodeEntryLimit(uint8_t wrongCodeEntryLimit) { setUInt8(48, wrongCodeEntryLimit); }

    uint8_t getUserCodeTemporaryDisableTime() { return getUInt8(49); }
    void setUserCodeTemporaryDisableTime(uint8_t userCodeTemporaryDisableTime) { setUInt8(49, userCodeTemporaryDisableTime); }

    bool getSendPinOta() { return getBool(50); }
    void setSendPinOta(bool sendPinOta) { setBool(50, sendPinOta); }

    bool getRequirePinForRfOperation() { return getBool(51); }
    void setRequirePinForRfOperation(bool requirePinForRfOperation) { setBool(51, requirePinForRfOperation); }

    uint8_t getZigbeeSecurityLevel() { return getUInt8(52); }
    void setZigbeeSecurityLevel(uint8_t zigbeeSecurityLevel) { setUInt8(52, zigbeeSecurityLevel); }

    uint16_t getAlarmMask() { return getMap16(64); }
    void setAlarmMask(uint16_t alarmMask) { setMap16(64, alarmMask); }

    uint16_t getKeypadOperationEventMask() { return getMap16(65); }
    void setKeypadOperationEventMask(uint16_t keypadOperationEventMask) { setMap16(65, keypadOperationEventMask); }

    uint16_t getRfOperationEventMask() { return getMap16(66); }
    void setRfOperationEventMask(uint16_t rfOperationEventMask) { setMap16(66, rfOperationEventMask); }

    uint16_t getManualOperationEventMask() { return getMap16(67); }
    void setManualOperationEventMask(uint16_t manualOperationEventMask) { setMap16(67, manualOperationEventMask); }

    uint16_t getRfidOperationEventMask() { return getMap16(68); }
    void setRfidOperationEventMask(uint16_t rfidOperationEventMask) { setMap16(68, rfidOperationEventMask); }

    uint16_t getKeypadProgrammingEventMask() { return getMap16(69); }
    void setKeypadProgrammingEventMask(uint16_t keypadProgrammingEventMask) { setMap16(69, keypadProgrammingEventMask); }

    uint16_t getRfProgrammingEventMask() { return getMap16(70); }
    void setRfProgrammingEventMask(uint16_t rfProgrammingEventMask) { setMap16(70, rfProgrammingEventMask); }

    uint16_t getRfidProgrammingEventMask() { return getMap16(71); }
    void setRfidProgrammingEventMask(uint16_t rfidProgrammingEventMask) { setMap16(71, rfidProgrammingEventMask); }

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

    uint8_t getWindowCoveringType() { return getEnum8(0); }
    void setWindowCoveringType(uint8_t windowCoveringType) { setEnum8(0, windowCoveringType); }

    uint16_t getPhysicalClosedLimitLiftCm() { return getUInt16(1); }
    void setPhysicalClosedLimitLiftCm(uint16_t physicalClosedLimitLiftCm) { setUInt16(1, physicalClosedLimitLiftCm); }

    uint16_t getPhysicalClosedLimitTiltDdegree() { return getUInt16(2); }
    void setPhysicalClosedLimitTiltDdegree(uint16_t physicalClosedLimitTiltDdegree) { setUInt16(2, physicalClosedLimitTiltDdegree); }

    uint16_t getCurrentPositionLiftCm() { return getUInt16(3); }
    void setCurrentPositionLiftCm(uint16_t currentPositionLiftCm) { setUInt16(3, currentPositionLiftCm); }

    uint16_t getCurrentPositionTiltDdegree() { return getUInt16(4); }
    void setCurrentPositionTiltDdegree(uint16_t currentPositionTiltDdegree) { setUInt16(4, currentPositionTiltDdegree); }

    uint16_t getNumOfActuationsLift() { return getUInt16(5); }
    void setNumOfActuationsLift(uint16_t numOfActuationsLift) { setUInt16(5, numOfActuationsLift); }

    uint16_t getNumOfActuationsTilt() { return getUInt16(6); }
    void setNumOfActuationsTilt(uint16_t numOfActuationsTilt) { setUInt16(6, numOfActuationsTilt); }

    uint8_t getConfigStatus() { return getMap8(7); }
    void setConfigStatus(uint8_t configStatus) { setMap8(7, configStatus); }

    uint8_t getCurrentPositionLiftPercentage() { return getUInt8(8); }
    void setCurrentPositionLiftPercentage(uint8_t currentPositionLiftPercentage) { setUInt8(8, currentPositionLiftPercentage); }

    uint8_t getCurrentPositionTiltPercentage() { return getUInt8(9); }
    void setCurrentPositionTiltPercentage(uint8_t currentPositionTiltPercentage) { setUInt8(9, currentPositionTiltPercentage); }

    uint8_t getOperationalStatus() { return getMap8(10); }
    void setOperationalStatus(uint8_t operationalStatus) { setMap8(10, operationalStatus); }

    uint16_t getInstalledOpenLimitLiftCm() { return getUInt16(16); }
    void setInstalledOpenLimitLiftCm(uint16_t installedOpenLimitLiftCm) { setUInt16(16, installedOpenLimitLiftCm); }

    uint16_t getInstalledClosedLimitLiftCm() { return getUInt16(17); }
    void setInstalledClosedLimitLiftCm(uint16_t installedClosedLimitLiftCm) { setUInt16(17, installedClosedLimitLiftCm); }

    uint16_t getInstalledOpenLimitTiltDdegree() { return getUInt16(18); }
    void setInstalledOpenLimitTiltDdegree(uint16_t installedOpenLimitTiltDdegree) { setUInt16(18, installedOpenLimitTiltDdegree); }

    uint16_t getInstalledClosedLimitTiltDdegree() { return getUInt16(19); }
    void setInstalledClosedLimitTiltDdegree(uint16_t installedClosedLimitTiltDdegree) { setUInt16(19, installedClosedLimitTiltDdegree); }

    uint16_t getVelocityLift() { return getUInt16(20); }
    void setVelocityLift(uint16_t velocityLift) { setUInt16(20, velocityLift); }

    uint16_t getAccelerationTimeLift() { return getUInt16(21); }
    void setAccelerationTimeLift(uint16_t accelerationTimeLift) { setUInt16(21, accelerationTimeLift); }

    uint16_t getDecelerationTimeLift() { return getUInt16(22); }
    void setDecelerationTimeLift(uint16_t decelerationTimeLift) { setUInt16(22, decelerationTimeLift); }

    uint8_t getWindowCoveringMode() { return getMap8(23); }
    void setWindowCoveringMode(uint8_t windowCoveringMode) { setMap8(23, windowCoveringMode); }

    Buffer getIntermediateSetpointsLift() { return getOctstr(24); }
    void setIntermediateSetpointsLift(const Buffer& intermediateSetpointsLift) { setOctstr(24, intermediateSetpointsLift); }

    Buffer getIntermediateSetpointsTilt() { return getOctstr(25); }
    void setIntermediateSetpointsTilt(const Buffer& intermediateSetpointsTilt) { setOctstr(25, intermediateSetpointsTilt); }

    uint16_t getMoesCalibrationTime() { return getUInt16(61443); }
    void setMoesCalibrationTime(uint16_t moesCalibrationTime) { setUInt16(61443, moesCalibrationTime); }

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

    uint8_t getMovingState() { return getEnum8(1); }
    void setMovingState(uint8_t movingState) { setEnum8(1, movingState); }

    uint16_t getSafetyStatus() { return getMap16(2); }
    void setSafetyStatus(uint16_t safetyStatus) { setMap16(2, safetyStatus); }

    uint8_t getCapabilities() { return getMap8(3); }
    void setCapabilities(uint8_t capabilities) { setMap8(3, capabilities); }

    uint16_t getOpenEvents() { return getUInt16(4); }
    void setOpenEvents(uint16_t openEvents) { setUInt16(4, openEvents); }

    uint16_t getCloseEvents() { return getUInt16(5); }
    void setCloseEvents(uint16_t closeEvents) { setUInt16(5, closeEvents); }

    uint16_t getCommandOpenEvents() { return getUInt16(6); }
    void setCommandOpenEvents(uint16_t commandOpenEvents) { setUInt16(6, commandOpenEvents); }

    uint16_t getCommandCloseEvents() { return getUInt16(7); }
    void setCommandCloseEvents(uint16_t commandCloseEvents) { setUInt16(7, commandCloseEvents); }

    uint16_t getOpenPeriod() { return getUInt16(8); }
    void setOpenPeriod(uint16_t openPeriod) { setUInt16(8, openPeriod); }

    uint16_t getClosePeriod() { return getUInt16(9); }
    void setClosePeriod(uint16_t closePeriod) { setUInt16(9, closePeriod); }

    uint8_t getBarrierPosition() { return getUInt8(10); }
    void setBarrierPosition(uint8_t barrierPosition) { setUInt8(10, barrierPosition); }

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

    int16_t getMaxPressure() { return getInt16(0); }
    void setMaxPressure(int16_t maxPressure) { setInt16(0, maxPressure); }

    uint16_t getMaxSpeed() { return getUInt16(1); }
    void setMaxSpeed(uint16_t maxSpeed) { setUInt16(1, maxSpeed); }

    uint16_t getMaxFlow() { return getUInt16(2); }
    void setMaxFlow(uint16_t maxFlow) { setUInt16(2, maxFlow); }

    int16_t getMinConstPressure() { return getInt16(3); }
    void setMinConstPressure(int16_t minConstPressure) { setInt16(3, minConstPressure); }

    int16_t getMaxConstPressure() { return getInt16(4); }
    void setMaxConstPressure(int16_t maxConstPressure) { setInt16(4, maxConstPressure); }

    int16_t getMinCompPressure() { return getInt16(5); }
    void setMinCompPressure(int16_t minCompPressure) { setInt16(5, minCompPressure); }

    int16_t getMaxCompPressure() { return getInt16(6); }
    void setMaxCompPressure(int16_t maxCompPressure) { setInt16(6, maxCompPressure); }

    uint16_t getMinConstSpeed() { return getUInt16(7); }
    void setMinConstSpeed(uint16_t minConstSpeed) { setUInt16(7, minConstSpeed); }

    uint16_t getMaxConstSpeed() { return getUInt16(8); }
    void setMaxConstSpeed(uint16_t maxConstSpeed) { setUInt16(8, maxConstSpeed); }

    uint16_t getMinConstFlow() { return getUInt16(9); }
    void setMinConstFlow(uint16_t minConstFlow) { setUInt16(9, minConstFlow); }

    uint16_t getMaxConstFlow() { return getUInt16(10); }
    void setMaxConstFlow(uint16_t maxConstFlow) { setUInt16(10, maxConstFlow); }

    int16_t getMinConstTemp() { return getInt16(11); }
    void setMinConstTemp(int16_t minConstTemp) { setInt16(11, minConstTemp); }

    int16_t getMaxConstTemp() { return getInt16(12); }
    void setMaxConstTemp(int16_t maxConstTemp) { setInt16(12, maxConstTemp); }

    uint16_t getPumpStatus() { return getMap16(16); }
    void setPumpStatus(uint16_t pumpStatus) { setMap16(16, pumpStatus); }

    uint8_t getEffectiveOperationMode() { return getEnum8(17); }
    void setEffectiveOperationMode(uint8_t effectiveOperationMode) { setEnum8(17, effectiveOperationMode); }

    uint8_t getEffectiveControlMode() { return getEnum8(18); }
    void setEffectiveControlMode(uint8_t effectiveControlMode) { setEnum8(18, effectiveControlMode); }

    int16_t getCapacity() { return getInt16(19); }
    void setCapacity(int16_t capacity) { setInt16(19, capacity); }

    uint16_t getSpeed() { return getUInt16(20); }
    void setSpeed(uint16_t speed) { setUInt16(20, speed); }

    uint32_t getLifetimeRunningHours() { return getUInt24(21); }
    void setLifetimeRunningHours(uint32_t lifetimeRunningHours) { setUInt24(21, lifetimeRunningHours); }

    uint32_t getPower() { return getUInt24(22); }
    void setPower(uint32_t power) { setUInt24(22, power); }

    uint32_t getLifetimeEnergyConsumed() { return getUInt32(23); }
    void setLifetimeEnergyConsumed(uint32_t lifetimeEnergyConsumed) { setUInt32(23, lifetimeEnergyConsumed); }

    uint8_t getOperationMode() { return getEnum8(32); }
    void setOperationMode(uint8_t operationMode) { setEnum8(32, operationMode); }

    uint8_t getControlMode() { return getEnum8(33); }
    void setControlMode(uint8_t controlMode) { setEnum8(33, controlMode); }

    uint16_t getAlarmMask() { return getMap16(34); }
    void setAlarmMask(uint16_t alarmMask) { setMap16(34, alarmMask); }
};

class HvacThermostatCluster: public Cluster {
public:
    HvacThermostatCluster() : Cluster(513) {
    }

    int16_t getLocalTemp() { return getInt16(0); }
    void setLocalTemp(int16_t localTemp) { setInt16(0, localTemp); }

    int16_t getOutdoorTemp() { return getInt16(1); }
    void setOutdoorTemp(int16_t outdoorTemp) { setInt16(1, outdoorTemp); }

    uint8_t getOccupancy() { return getMap8(2); }
    void setOccupancy(uint8_t occupancy) { setMap8(2, occupancy); }

    int16_t getAbsMinHeatSetpointLimit() { return getInt16(3); }
    void setAbsMinHeatSetpointLimit(int16_t absMinHeatSetpointLimit) { setInt16(3, absMinHeatSetpointLimit); }

    int16_t getAbsMaxHeatSetpointLimit() { return getInt16(4); }
    void setAbsMaxHeatSetpointLimit(int16_t absMaxHeatSetpointLimit) { setInt16(4, absMaxHeatSetpointLimit); }

    int16_t getAbsMinCoolSetpointLimit() { return getInt16(5); }
    void setAbsMinCoolSetpointLimit(int16_t absMinCoolSetpointLimit) { setInt16(5, absMinCoolSetpointLimit); }

    int16_t getAbsMaxCoolSetpointLimit() { return getInt16(6); }
    void setAbsMaxCoolSetpointLimit(int16_t absMaxCoolSetpointLimit) { setInt16(6, absMaxCoolSetpointLimit); }

    uint8_t getPICoolingDemand() { return getUInt8(7); }
    void setPICoolingDemand(uint8_t pICoolingDemand) { setUInt8(7, pICoolingDemand); }

    uint8_t getPIHeatingDemand() { return getUInt8(8); }
    void setPIHeatingDemand(uint8_t pIHeatingDemand) { setUInt8(8, pIHeatingDemand); }

    uint8_t getSystemTypeConfig() { return getMap8(9); }
    void setSystemTypeConfig(uint8_t systemTypeConfig) { setMap8(9, systemTypeConfig); }

    int8_t getLocalTemperatureCalibration() { return getInt8(16); }
    void setLocalTemperatureCalibration(int8_t localTemperatureCalibration) { setInt8(16, localTemperatureCalibration); }

    int16_t getOccupiedCoolingSetpoint() { return getInt16(17); }
    void setOccupiedCoolingSetpoint(int16_t occupiedCoolingSetpoint) { setInt16(17, occupiedCoolingSetpoint); }

    int16_t getOccupiedHeatingSetpoint() { return getInt16(18); }
    void setOccupiedHeatingSetpoint(int16_t occupiedHeatingSetpoint) { setInt16(18, occupiedHeatingSetpoint); }

    int16_t getUnoccupiedCoolingSetpoint() { return getInt16(19); }
    void setUnoccupiedCoolingSetpoint(int16_t unoccupiedCoolingSetpoint) { setInt16(19, unoccupiedCoolingSetpoint); }

    int16_t getUnoccupiedHeatingSetpoint() { return getInt16(20); }
    void setUnoccupiedHeatingSetpoint(int16_t unoccupiedHeatingSetpoint) { setInt16(20, unoccupiedHeatingSetpoint); }

    int16_t getMinHeatSetpointLimit() { return getInt16(21); }
    void setMinHeatSetpointLimit(int16_t minHeatSetpointLimit) { setInt16(21, minHeatSetpointLimit); }

    int16_t getMaxHeatSetpointLimit() { return getInt16(22); }
    void setMaxHeatSetpointLimit(int16_t maxHeatSetpointLimit) { setInt16(22, maxHeatSetpointLimit); }

    int16_t getMinCoolSetpointLimit() { return getInt16(23); }
    void setMinCoolSetpointLimit(int16_t minCoolSetpointLimit) { setInt16(23, minCoolSetpointLimit); }

    int16_t getMaxCoolSetpointLimit() { return getInt16(24); }
    void setMaxCoolSetpointLimit(int16_t maxCoolSetpointLimit) { setInt16(24, maxCoolSetpointLimit); }

    int8_t getMinSetpointDeadBand() { return getInt8(25); }
    void setMinSetpointDeadBand(int8_t minSetpointDeadBand) { setInt8(25, minSetpointDeadBand); }

    uint8_t getRemoteSensing() { return getMap8(26); }
    void setRemoteSensing(uint8_t remoteSensing) { setMap8(26, remoteSensing); }

    uint8_t getCtrlSeqeOfOper() { return getEnum8(27); }
    void setCtrlSeqeOfOper(uint8_t ctrlSeqeOfOper) { setEnum8(27, ctrlSeqeOfOper); }

    uint8_t getSystemMode() { return getEnum8(28); }
    void setSystemMode(uint8_t systemMode) { setEnum8(28, systemMode); }

    uint8_t getAlarmMask() { return getMap8(29); }
    void setAlarmMask(uint8_t alarmMask) { setMap8(29, alarmMask); }

    uint8_t getRunningMode() { return getEnum8(30); }
    void setRunningMode(uint8_t runningMode) { setEnum8(30, runningMode); }

    uint8_t getStartOfWeek() { return getEnum8(32); }
    void setStartOfWeek(uint8_t startOfWeek) { setEnum8(32, startOfWeek); }

    uint8_t getNumberOfWeeklyTrans() { return getUInt8(33); }
    void setNumberOfWeeklyTrans(uint8_t numberOfWeeklyTrans) { setUInt8(33, numberOfWeeklyTrans); }

    uint8_t getNumberOfDailyTrans() { return getUInt8(34); }
    void setNumberOfDailyTrans(uint8_t numberOfDailyTrans) { setUInt8(34, numberOfDailyTrans); }

    uint8_t getTempSetpointHold() { return getEnum8(35); }
    void setTempSetpointHold(uint8_t tempSetpointHold) { setEnum8(35, tempSetpointHold); }

    uint16_t getTempSetpointHoldDuration() { return getUInt16(36); }
    void setTempSetpointHoldDuration(uint16_t tempSetpointHoldDuration) { setUInt16(36, tempSetpointHoldDuration); }

    uint8_t getProgramingOperMode() { return getMap8(37); }
    void setProgramingOperMode(uint8_t programingOperMode) { setMap8(37, programingOperMode); }

    uint16_t getRunningState() { return getMap16(41); }
    void setRunningState(uint16_t runningState) { setMap16(41, runningState); }

    uint8_t getSetpointChangeSource() { return getEnum8(48); }
    void setSetpointChangeSource(uint8_t setpointChangeSource) { setEnum8(48, setpointChangeSource); }

    int16_t getSetpointChangeAmount() { return getInt16(49); }
    void setSetpointChangeAmount(int16_t setpointChangeAmount) { setInt16(49, setpointChangeAmount); }

    uint32_t getSetpointChangeSourceTimeStamp() { return getUTC(50); }
    void setSetpointChangeSourceTimeStamp(uint32_t setpointChangeSourceTimeStamp) { setUTC(50, setpointChangeSourceTimeStamp); }

    uint8_t getAcType() { return getEnum8(64); }
    void setAcType(uint8_t acType) { setEnum8(64, acType); }

    uint16_t getAcCapacity() { return getUInt16(65); }
    void setAcCapacity(uint16_t acCapacity) { setUInt16(65, acCapacity); }

    uint8_t getAcRefrigerantType() { return getEnum8(66); }
    void setAcRefrigerantType(uint8_t acRefrigerantType) { setEnum8(66, acRefrigerantType); }

    uint8_t getAcConpressorType() { return getEnum8(67); }
    void setAcConpressorType(uint8_t acConpressorType) { setEnum8(67, acConpressorType); }

    uint32_t getAcErrorCode() { return getMap32(68); }
    void setAcErrorCode(uint32_t acErrorCode) { setMap32(68, acErrorCode); }

    uint8_t getAcLouverPosition() { return getEnum8(69); }
    void setAcLouverPosition(uint8_t acLouverPosition) { setEnum8(69, acLouverPosition); }

    int16_t getAcCollTemp() { return getInt16(70); }
    void setAcCollTemp(int16_t acCollTemp) { setInt16(70, acCollTemp); }

    uint8_t getAcCapacityFormat() { return getEnum8(71); }
    void setAcCapacityFormat(uint8_t acCapacityFormat) { setEnum8(71, acCapacityFormat); }

    uint8_t getStelproSystemMode() { return getEnum8(16412); }
    void setStelproSystemMode(uint8_t StelproSystemMode) { setEnum8(16412, StelproSystemMode); }

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

    uint8_t getFanMode() { return getEnum8(0); }
    void setFanMode(uint8_t fanMode) { setEnum8(0, fanMode); }

    uint8_t getFanModeSequence() { return getEnum8(1); }
    void setFanModeSequence(uint8_t fanModeSequence) { setEnum8(1, fanModeSequence); }
};

class HvacDehumidificationCtrlCluster: public Cluster {
public:
    HvacDehumidificationCtrlCluster() : Cluster(515) {
    }

    uint8_t getRelativeHumidity() { return getUInt8(0); }
    void setRelativeHumidity(uint8_t relativeHumidity) { setUInt8(0, relativeHumidity); }

    uint8_t getDehumidCooling() { return getUInt8(1); }
    void setDehumidCooling(uint8_t dehumidCooling) { setUInt8(1, dehumidCooling); }

    uint8_t getRhDehumidSetpoint() { return getUInt8(16); }
    void setRhDehumidSetpoint(uint8_t rhDehumidSetpoint) { setUInt8(16, rhDehumidSetpoint); }

    uint8_t getRelativeHumidityMode() { return getEnum8(17); }
    void setRelativeHumidityMode(uint8_t relativeHumidityMode) { setEnum8(17, relativeHumidityMode); }

    uint8_t getDehumidLockout() { return getEnum8(18); }
    void setDehumidLockout(uint8_t dehumidLockout) { setEnum8(18, dehumidLockout); }

    uint8_t getDehumidHysteresis() { return getUInt8(19); }
    void setDehumidHysteresis(uint8_t dehumidHysteresis) { setUInt8(19, dehumidHysteresis); }

    uint8_t getDehumidMaxCool() { return getUInt8(20); }
    void setDehumidMaxCool(uint8_t dehumidMaxCool) { setUInt8(20, dehumidMaxCool); }

    uint8_t getRelativeHumidDisplay() { return getEnum8(21); }
    void setRelativeHumidDisplay(uint8_t relativeHumidDisplay) { setEnum8(21, relativeHumidDisplay); }
};

class HvacUserInterfaceCfgCluster: public Cluster {
public:
    HvacUserInterfaceCfgCluster() : Cluster(516) {
    }

    uint8_t getTempDisplayMode() { return getEnum8(0); }
    void setTempDisplayMode(uint8_t tempDisplayMode) { setEnum8(0, tempDisplayMode); }

    uint8_t getKeypadLockout() { return getEnum8(1); }
    void setKeypadLockout(uint8_t keypadLockout) { setEnum8(1, keypadLockout); }

    uint8_t getProgrammingVisibility() { return getEnum8(2); }
    void setProgrammingVisibility(uint8_t programmingVisibility) { setEnum8(2, programmingVisibility); }
};

class LightingColorCtrlCluster: public Cluster {
public:
    LightingColorCtrlCluster() : Cluster(768) {
    }

    uint8_t getCurrentHue() { return getUInt8(0); }
    void setCurrentHue(uint8_t currentHue) { setUInt8(0, currentHue); }

    uint8_t getCurrentSaturation() { return getUInt8(1); }
    void setCurrentSaturation(uint8_t currentSaturation) { setUInt8(1, currentSaturation); }

    uint16_t getRemainingTime() { return getUInt16(2); }
    void setRemainingTime(uint16_t remainingTime) { setUInt16(2, remainingTime); }

    uint16_t getCurrentX() { return getUInt16(3); }
    void setCurrentX(uint16_t currentX) { setUInt16(3, currentX); }

    uint16_t getCurrentY() { return getUInt16(4); }
    void setCurrentY(uint16_t currentY) { setUInt16(4, currentY); }

    uint8_t getDriftCompensation() { return getEnum8(5); }
    void setDriftCompensation(uint8_t driftCompensation) { setEnum8(5, driftCompensation); }

    String getCompensationText() { return getString(6); }
    void setCompensationText(const String& compensationText) { setString(6, compensationText); }

    uint16_t getColorTemperature() { return getUInt16(7); }
    void setColorTemperature(uint16_t colorTemperature) { setUInt16(7, colorTemperature); }

    uint8_t getColorMode() { return getEnum8(8); }
    void setColorMode(uint8_t colorMode) { setEnum8(8, colorMode); }

    uint8_t getOptions() { return getMap8(15); }
    void setOptions(uint8_t options) { setMap8(15, options); }

    uint8_t getNumPrimaries() { return getUInt8(16); }
    void setNumPrimaries(uint8_t numPrimaries) { setUInt8(16, numPrimaries); }

    uint16_t getPrimary1X() { return getUInt16(17); }
    void setPrimary1X(uint16_t primary1X) { setUInt16(17, primary1X); }

    uint16_t getPrimary1Y() { return getUInt16(18); }
    void setPrimary1Y(uint16_t primary1Y) { setUInt16(18, primary1Y); }

    uint8_t getPrimary1Intensity() { return getUInt8(19); }
    void setPrimary1Intensity(uint8_t primary1Intensity) { setUInt8(19, primary1Intensity); }

    uint16_t getPrimary2X() { return getUInt16(21); }
    void setPrimary2X(uint16_t primary2X) { setUInt16(21, primary2X); }

    uint16_t getPrimary2Y() { return getUInt16(22); }
    void setPrimary2Y(uint16_t primary2Y) { setUInt16(22, primary2Y); }

    uint8_t getPrimary2Intensity() { return getUInt8(23); }
    void setPrimary2Intensity(uint8_t primary2Intensity) { setUInt8(23, primary2Intensity); }

    uint16_t getPrimary3X() { return getUInt16(25); }
    void setPrimary3X(uint16_t primary3X) { setUInt16(25, primary3X); }

    uint16_t getPrimary3Y() { return getUInt16(26); }
    void setPrimary3Y(uint16_t primary3Y) { setUInt16(26, primary3Y); }

    uint8_t getPrimary3Intensity() { return getUInt8(27); }
    void setPrimary3Intensity(uint8_t primary3Intensity) { setUInt8(27, primary3Intensity); }

    uint16_t getPrimary4X() { return getUInt16(32); }
    void setPrimary4X(uint16_t primary4X) { setUInt16(32, primary4X); }

    uint16_t getPrimary4Y() { return getUInt16(33); }
    void setPrimary4Y(uint16_t primary4Y) { setUInt16(33, primary4Y); }

    uint8_t getPrimary4Intensity() { return getUInt8(34); }
    void setPrimary4Intensity(uint8_t primary4Intensity) { setUInt8(34, primary4Intensity); }

    uint16_t getPrimary5X() { return getUInt16(36); }
    void setPrimary5X(uint16_t primary5X) { setUInt16(36, primary5X); }

    uint16_t getPrimary5Y() { return getUInt16(37); }
    void setPrimary5Y(uint16_t primary5Y) { setUInt16(37, primary5Y); }

    uint8_t getPrimary5Intensity() { return getUInt8(38); }
    void setPrimary5Intensity(uint8_t primary5Intensity) { setUInt8(38, primary5Intensity); }

    uint16_t getPrimary6X() { return getUInt16(40); }
    void setPrimary6X(uint16_t primary6X) { setUInt16(40, primary6X); }

    uint16_t getPrimary6Y() { return getUInt16(41); }
    void setPrimary6Y(uint16_t primary6Y) { setUInt16(41, primary6Y); }

    uint8_t getPrimary6Intensity() { return getUInt8(42); }
    void setPrimary6Intensity(uint8_t primary6Intensity) { setUInt8(42, primary6Intensity); }

    uint16_t getWhitePointX() { return getUInt16(48); }
    void setWhitePointX(uint16_t whitePointX) { setUInt16(48, whitePointX); }

    uint16_t getWhitePointY() { return getUInt16(49); }
    void setWhitePointY(uint16_t whitePointY) { setUInt16(49, whitePointY); }

    uint16_t getColorPointRX() { return getUInt16(50); }
    void setColorPointRX(uint16_t colorPointRX) { setUInt16(50, colorPointRX); }

    uint16_t getColorPointRY() { return getUInt16(51); }
    void setColorPointRY(uint16_t colorPointRY) { setUInt16(51, colorPointRY); }

    uint8_t getColorPointRIntensity() { return getUInt8(52); }
    void setColorPointRIntensity(uint8_t colorPointRIntensity) { setUInt8(52, colorPointRIntensity); }

    uint16_t getColorPointGX() { return getUInt16(54); }
    void setColorPointGX(uint16_t colorPointGX) { setUInt16(54, colorPointGX); }

    uint16_t getColorPointGY() { return getUInt16(55); }
    void setColorPointGY(uint16_t colorPointGY) { setUInt16(55, colorPointGY); }

    uint8_t getColorPointGIntensity() { return getUInt8(56); }
    void setColorPointGIntensity(uint8_t colorPointGIntensity) { setUInt8(56, colorPointGIntensity); }

    uint16_t getColorPointBX() { return getUInt16(58); }
    void setColorPointBX(uint16_t colorPointBX) { setUInt16(58, colorPointBX); }

    uint16_t getColorPointBY() { return getUInt16(59); }
    void setColorPointBY(uint16_t colorPointBY) { setUInt16(59, colorPointBY); }

    uint8_t getColorPointBIntensity() { return getUInt8(60); }
    void setColorPointBIntensity(uint8_t colorPointBIntensity) { setUInt8(60, colorPointBIntensity); }

    uint16_t getEnhancedCurrentHue() { return getUInt16(16384); }
    void setEnhancedCurrentHue(uint16_t enhancedCurrentHue) { setUInt16(16384, enhancedCurrentHue); }

    uint8_t getEnhancedColorMode() { return getEnum8(16385); }
    void setEnhancedColorMode(uint8_t enhancedColorMode) { setEnum8(16385, enhancedColorMode); }

    uint8_t getColorLoopActive() { return getUInt8(16386); }
    void setColorLoopActive(uint8_t colorLoopActive) { setUInt8(16386, colorLoopActive); }

    uint8_t getColorLoopDirection() { return getUInt8(16387); }
    void setColorLoopDirection(uint8_t colorLoopDirection) { setUInt8(16387, colorLoopDirection); }

    uint16_t getColorLoopTime() { return getUInt16(16388); }
    void setColorLoopTime(uint16_t colorLoopTime) { setUInt16(16388, colorLoopTime); }

    uint16_t getColorLoopStartEnhancedHue() { return getUInt16(16389); }
    void setColorLoopStartEnhancedHue(uint16_t colorLoopStartEnhancedHue) { setUInt16(16389, colorLoopStartEnhancedHue); }

    uint16_t getColorLoopStoredEnhancedHue() { return getUInt16(16390); }
    void setColorLoopStoredEnhancedHue(uint16_t colorLoopStoredEnhancedHue) { setUInt16(16390, colorLoopStoredEnhancedHue); }

    uint16_t getColorCapabilities() { return getUInt16(16394); }
    void setColorCapabilities(uint16_t colorCapabilities) { setUInt16(16394, colorCapabilities); }

    uint16_t getColorTempPhysicalMin() { return getUInt16(16395); }
    void setColorTempPhysicalMin(uint16_t colorTempPhysicalMin) { setUInt16(16395, colorTempPhysicalMin); }

    uint16_t getColorTempPhysicalMax() { return getUInt16(16396); }
    void setColorTempPhysicalMax(uint16_t colorTempPhysicalMax) { setUInt16(16396, colorTempPhysicalMax); }

    uint16_t getCoupleColorTempToLevelMin() { return getUInt16(16397); }
    void setCoupleColorTempToLevelMin(uint16_t coupleColorTempToLevelMin) { setUInt16(16397, coupleColorTempToLevelMin); }

    uint16_t getStartUpColorTemperature() { return getUInt16(16400); }
    void setStartUpColorTemperature(uint16_t startUpColorTemperature) { setUInt16(16400, startUpColorTemperature); }

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

    uint8_t getPhysicalMinLevel() { return getUInt8(0); }
    void setPhysicalMinLevel(uint8_t physicalMinLevel) { setUInt8(0, physicalMinLevel); }

    uint8_t getPhysicalMaxLevel() { return getUInt8(1); }
    void setPhysicalMaxLevel(uint8_t physicalMaxLevel) { setUInt8(1, physicalMaxLevel); }

    uint8_t getBallastStatus() { return getMap8(2); }
    void setBallastStatus(uint8_t ballastStatus) { setMap8(2, ballastStatus); }

    uint8_t getMinLevel() { return getUInt8(16); }
    void setMinLevel(uint8_t minLevel) { setUInt8(16, minLevel); }

    uint8_t getMaxLevel() { return getUInt8(17); }
    void setMaxLevel(uint8_t maxLevel) { setUInt8(17, maxLevel); }

    uint8_t getPowerOnLevel() { return getUInt8(18); }
    void setPowerOnLevel(uint8_t powerOnLevel) { setUInt8(18, powerOnLevel); }

    uint16_t getPowerOnFadeTime() { return getUInt16(19); }
    void setPowerOnFadeTime(uint16_t powerOnFadeTime) { setUInt16(19, powerOnFadeTime); }

    uint8_t getIntrinsicBallastFactor() { return getUInt8(20); }
    void setIntrinsicBallastFactor(uint8_t intrinsicBallastFactor) { setUInt8(20, intrinsicBallastFactor); }

    uint8_t getBallastFactorAdjustment() { return getUInt8(21); }
    void setBallastFactorAdjustment(uint8_t ballastFactorAdjustment) { setUInt8(21, ballastFactorAdjustment); }

    uint8_t getLampQuantity() { return getUInt8(32); }
    void setLampQuantity(uint8_t lampQuantity) { setUInt8(32, lampQuantity); }

    String getLampType() { return getString(48); }
    void setLampType(const String& lampType) { setString(48, lampType); }

    String getLampManufacturer() { return getString(49); }
    void setLampManufacturer(const String& lampManufacturer) { setString(49, lampManufacturer); }

    uint32_t getLampRatedHours() { return getUInt24(50); }
    void setLampRatedHours(uint32_t lampRatedHours) { setUInt24(50, lampRatedHours); }

    uint32_t getLampBurnHours() { return getUInt24(51); }
    void setLampBurnHours(uint32_t lampBurnHours) { setUInt24(51, lampBurnHours); }

    uint8_t getLampAlarmMode() { return getMap8(52); }
    void setLampAlarmMode(uint8_t lampAlarmMode) { setMap8(52, lampAlarmMode); }

    uint32_t getLampBurnHoursTripPoint() { return getUInt24(53); }
    void setLampBurnHoursTripPoint(uint32_t lampBurnHoursTripPoint) { setUInt24(53, lampBurnHoursTripPoint); }
};

class MsIlluminanceMeasurementCluster: public Cluster {
public:
    MsIlluminanceMeasurementCluster() : Cluster(1024) {
    }

    uint16_t getMeasuredValue() { return getUInt16(0); }
    void setMeasuredValue(uint16_t measuredValue) { setUInt16(0, measuredValue); }

    uint16_t getMinMeasuredValue() { return getUInt16(1); }
    void setMinMeasuredValue(uint16_t minMeasuredValue) { setUInt16(1, minMeasuredValue); }

    uint16_t getMaxMeasuredValue() { return getUInt16(2); }
    void setMaxMeasuredValue(uint16_t maxMeasuredValue) { setUInt16(2, maxMeasuredValue); }

    uint16_t getTolerance() { return getUInt16(3); }
    void setTolerance(uint16_t tolerance) { setUInt16(3, tolerance); }

    uint8_t getLightSensorType() { return getEnum8(4); }
    void setLightSensorType(uint8_t lightSensorType) { setEnum8(4, lightSensorType); }
};

class MsIlluminanceLevelSensingCluster: public Cluster {
public:
    MsIlluminanceLevelSensingCluster() : Cluster(1025) {
    }

    uint8_t getLevelStatus() { return getEnum8(0); }
    void setLevelStatus(uint8_t levelStatus) { setEnum8(0, levelStatus); }

    uint8_t getLightSensorType() { return getEnum8(1); }
    void setLightSensorType(uint8_t lightSensorType) { setEnum8(1, lightSensorType); }

    uint16_t getIlluminanceTargetLevel() { return getUInt16(16); }
    void setIlluminanceTargetLevel(uint16_t illuminanceTargetLevel) { setUInt16(16, illuminanceTargetLevel); }
};

class MsTemperatureMeasurementCluster: public Cluster {
public:
    MsTemperatureMeasurementCluster() : Cluster(1026) {
    }

    int16_t getMeasuredValue() { return getInt16(0); }
    void setMeasuredValue(int16_t measuredValue) { setInt16(0, measuredValue); }

    int16_t getMinMeasuredValue() { return getInt16(1); }
    void setMinMeasuredValue(int16_t minMeasuredValue) { setInt16(1, minMeasuredValue); }

    int16_t getMaxMeasuredValue() { return getInt16(2); }
    void setMaxMeasuredValue(int16_t maxMeasuredValue) { setInt16(2, maxMeasuredValue); }

    uint16_t getTolerance() { return getUInt16(3); }
    void setTolerance(uint16_t tolerance) { setUInt16(3, tolerance); }
};

class MsPressureMeasurementCluster: public Cluster {
public:
    MsPressureMeasurementCluster() : Cluster(1027) {
    }

    int16_t getMeasuredValue() { return getInt16(0); }
    void setMeasuredValue(int16_t measuredValue) { setInt16(0, measuredValue); }

    int16_t getMinMeasuredValue() { return getInt16(1); }
    void setMinMeasuredValue(int16_t minMeasuredValue) { setInt16(1, minMeasuredValue); }

    int16_t getMaxMeasuredValue() { return getInt16(2); }
    void setMaxMeasuredValue(int16_t maxMeasuredValue) { setInt16(2, maxMeasuredValue); }

    uint16_t getTolerance() { return getUInt16(3); }
    void setTolerance(uint16_t tolerance) { setUInt16(3, tolerance); }

    int16_t getScaledValue() { return getInt16(16); }
    void setScaledValue(int16_t scaledValue) { setInt16(16, scaledValue); }

    int16_t getMinScaledValue() { return getInt16(17); }
    void setMinScaledValue(int16_t minScaledValue) { setInt16(17, minScaledValue); }

    int16_t getMaxScaledValue() { return getInt16(18); }
    void setMaxScaledValue(int16_t maxScaledValue) { setInt16(18, maxScaledValue); }

    uint16_t getScaledTolerance() { return getUInt16(19); }
    void setScaledTolerance(uint16_t scaledTolerance) { setUInt16(19, scaledTolerance); }

    int8_t getScale() { return getInt8(20); }
    void setScale(int8_t scale) { setInt8(20, scale); }
};

class MsFlowMeasurementCluster: public Cluster {
public:
    MsFlowMeasurementCluster() : Cluster(1028) {
    }

    uint16_t getMeasuredValue() { return getUInt16(0); }
    void setMeasuredValue(uint16_t measuredValue) { setUInt16(0, measuredValue); }

    uint16_t getMinMeasuredValue() { return getUInt16(1); }
    void setMinMeasuredValue(uint16_t minMeasuredValue) { setUInt16(1, minMeasuredValue); }

    uint16_t getMaxMeasuredValue() { return getUInt16(2); }
    void setMaxMeasuredValue(uint16_t maxMeasuredValue) { setUInt16(2, maxMeasuredValue); }

    uint16_t getTolerance() { return getUInt16(3); }
    void setTolerance(uint16_t tolerance) { setUInt16(3, tolerance); }
};

class MsRelativeHumidityCluster: public Cluster {
public:
    MsRelativeHumidityCluster() : Cluster(1029) {
    }

    uint16_t getMeasuredValue() { return getUInt16(0); }
    void setMeasuredValue(uint16_t measuredValue) { setUInt16(0, measuredValue); }

    uint16_t getMinMeasuredValue() { return getUInt16(1); }
    void setMinMeasuredValue(uint16_t minMeasuredValue) { setUInt16(1, minMeasuredValue); }

    uint16_t getMaxMeasuredValue() { return getUInt16(2); }
    void setMaxMeasuredValue(uint16_t maxMeasuredValue) { setUInt16(2, maxMeasuredValue); }

    uint16_t getTolerance() { return getUInt16(3); }
    void setTolerance(uint16_t tolerance) { setUInt16(3, tolerance); }
};

class MsOccupancySensingCluster: public Cluster {
public:
    MsOccupancySensingCluster() : Cluster(1030) {
    }

    uint8_t getOccupancy() { return getMap8(0); }
    void setOccupancy(uint8_t occupancy) { setMap8(0, occupancy); }

    uint8_t getOccupancySensorType() { return getEnum8(1); }
    void setOccupancySensorType(uint8_t occupancySensorType) { setEnum8(1, occupancySensorType); }

    uint16_t getPirOToUDelay() { return getUInt16(16); }
    void setPirOToUDelay(uint16_t pirOToUDelay) { setUInt16(16, pirOToUDelay); }

    uint16_t getPirUToODelay() { return getUInt16(17); }
    void setPirUToODelay(uint16_t pirUToODelay) { setUInt16(17, pirUToODelay); }

    uint8_t getPirUToOThreshold() { return getUInt8(18); }
    void setPirUToOThreshold(uint8_t pirUToOThreshold) { setUInt8(18, pirUToOThreshold); }

    uint16_t getUltrasonicOToUDelay() { return getUInt16(32); }
    void setUltrasonicOToUDelay(uint16_t ultrasonicOToUDelay) { setUInt16(32, ultrasonicOToUDelay); }

    uint16_t getUltrasonicUToODelay() { return getUInt16(33); }
    void setUltrasonicUToODelay(uint16_t ultrasonicUToODelay) { setUInt16(33, ultrasonicUToODelay); }

    uint8_t getUltrasonicUToOThreshold() { return getUInt8(34); }
    void setUltrasonicUToOThreshold(uint8_t ultrasonicUToOThreshold) { setUInt8(34, ultrasonicUToOThreshold); }
};

class MsSoilMoistureCluster: public Cluster {
public:
    MsSoilMoistureCluster() : Cluster(1032) {
    }

    uint16_t getMeasuredValue() { return getUInt16(0); }
    void setMeasuredValue(uint16_t measuredValue) { setUInt16(0, measuredValue); }

    uint16_t getMinMeasuredValue() { return getUInt16(1); }
    void setMinMeasuredValue(uint16_t minMeasuredValue) { setUInt16(1, minMeasuredValue); }

    uint16_t getMaxMeasuredValue() { return getUInt16(2); }
    void setMaxMeasuredValue(uint16_t maxMeasuredValue) { setUInt16(2, maxMeasuredValue); }

    uint16_t getTolerance() { return getUInt16(3); }
    void setTolerance(uint16_t tolerance) { setUInt16(3, tolerance); }
};

class PHMeasurementCluster: public Cluster {
public:
    PHMeasurementCluster() : Cluster(1033) {
    }

    uint16_t getMeasuredValue() { return getUInt16(0); }
    void setMeasuredValue(uint16_t measuredValue) { setUInt16(0, measuredValue); }

    uint16_t getMinMeasuredValue() { return getUInt16(1); }
    void setMinMeasuredValue(uint16_t minMeasuredValue) { setUInt16(1, minMeasuredValue); }

    uint16_t getMaxMeasuredValue() { return getUInt16(2); }
    void setMaxMeasuredValue(uint16_t maxMeasuredValue) { setUInt16(2, maxMeasuredValue); }

    uint16_t getTolerance() { return getUInt16(3); }
    void setTolerance(uint16_t tolerance) { setUInt16(3, tolerance); }
};

class MsCO2Cluster: public Cluster {
public:
    MsCO2Cluster() : Cluster(1037) {
    }

    float getMeasuredValue() { return getSingle(0); }
    void setMeasuredValue(float measuredValue) { setSingle(0, measuredValue); }

    float getMinMeasuredValue() { return getSingle(1); }
    void setMinMeasuredValue(float minMeasuredValue) { setSingle(1, minMeasuredValue); }

    float getMaxMeasuredValue() { return getSingle(2); }
    void setMaxMeasuredValue(float maxMeasuredValue) { setSingle(2, maxMeasuredValue); }
};

class SsIasZoneCluster: public Cluster {
public:
    SsIasZoneCluster() : Cluster(1280) {
    }

    uint8_t getZoneState() { return getEnum8(0); }
    void setZoneState(uint8_t zoneState) { setEnum8(0, zoneState); }

    uint16_t getZoneType() { return getEnum16(1); }
    void setZoneType(uint16_t zoneType) { setEnum16(1, zoneType); }

    uint16_t getZoneStatus() { return getMap16(2); }
    void setZoneStatus(uint16_t zoneStatus) { setMap16(2, zoneStatus); }

    uint64_t getIasCieAddr() { return getEUI64(16); }
    void setIasCieAddr(uint64_t iasCieAddr) { setEUI64(16, iasCieAddr); }

    uint8_t getZoneId() { return getUInt8(17); }
    void setZoneId(uint8_t zoneId) { setUInt8(17, zoneId); }

    uint8_t getNumZoneSensitivityLevelsSupported() { return getUInt8(18); }
    void setNumZoneSensitivityLevelsSupported(uint8_t numZoneSensitivityLevelsSupported) { setUInt8(18, numZoneSensitivityLevelsSupported); }

    uint8_t getCurrentZoneSensitivityLevel() { return getUInt8(19); }
    void setCurrentZoneSensitivityLevel(uint8_t currentZoneSensitivityLevel) { setUInt8(19, currentZoneSensitivityLevel); }

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

    uint16_t getMaxDuration() { return getUInt16(0); }
    void setMaxDuration(uint16_t maxDuration) { setUInt16(0, maxDuration); }

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

    uint16_t getMaxIncomeTransSize() { return getUInt16(1); }
    void setMaxIncomeTransSize(uint16_t maxIncomeTransSize) { setUInt16(1, maxIncomeTransSize); }

    uint16_t getMaxOutgoTransSize() { return getUInt16(2); }
    void setMaxOutgoTransSize(uint16_t maxOutgoTransSize) { setUInt16(2, maxOutgoTransSize); }

    Buffer getProtocolAddr() { return getOctstr(3); }
    void setProtocolAddr(const Buffer& protocolAddr) { setOctstr(3, protocolAddr); }

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

    float getCovIncrement() { return getSingle(22); }
    void setCovIncrement(float covIncrement) { setSingle(22, covIncrement); }

    String getDeviceType() { return getString(31); }
    void setDeviceType(const String& deviceType) { setString(31, deviceType); }

    uint32_t getObjectId() { return getBacOID(75); }
    void setObjectId(uint32_t objectId) { setBacOID(75, objectId); }

    String getObjectName() { return getString(77); }
    void setObjectName(const String& objectName) { setString(77, objectName); }

    uint16_t getObjectType() { return getEnum16(79); }
    void setObjectType(uint16_t objectType) { setEnum16(79, objectType); }

    uint8_t getUpdateInterval() { return getUInt8(118); }
    void setUpdateInterval(uint8_t updateInterval) { setUInt8(118, updateInterval); }

    String getProfileName() { return getString(168); }
    void setProfileName(const String& profileName) { setString(168, profileName); }
};

class PiAnalogInputExtCluster: public Cluster {
public:
    PiAnalogInputExtCluster() : Cluster(1539) {
    }

    uint8_t getAckedTransitions() { return getMap8(0); }
    void setAckedTransitions(uint8_t ackedTransitions) { setMap8(0, ackedTransitions); }

    uint16_t getNotificationClass() { return getUInt16(17); }
    void setNotificationClass(uint16_t notificationClass) { setUInt16(17, notificationClass); }

    float getDeadband() { return getSingle(25); }
    void setDeadband(float deadband) { setSingle(25, deadband); }

    uint8_t getEventEnable() { return getMap8(35); }
    void setEventEnable(uint8_t eventEnable) { setMap8(35, eventEnable); }

    uint8_t getEventState() { return getEnum8(36); }
    void setEventState(uint8_t eventState) { setEnum8(36, eventState); }

    float getHighLimit() { return getSingle(45); }
    void setHighLimit(float highLimit) { setSingle(45, highLimit); }

    uint8_t getLimitEnable() { return getMap8(52); }
    void setLimitEnable(uint8_t limitEnable) { setMap8(52, limitEnable); }

    float getLowLimit() { return getSingle(59); }
    void setLowLimit(float lowLimit) { setSingle(59, lowLimit); }

    uint8_t getNotifyType() { return getEnum8(72); }
    void setNotifyType(uint8_t notifyType) { setEnum8(72, notifyType); }

    uint8_t getTimeDelay() { return getUInt8(113); }
    void setTimeDelay(uint8_t timeDelay) { setUInt8(113, timeDelay); }

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

    float getCovIncrement() { return getSingle(22); }
    void setCovIncrement(float covIncrement) { setSingle(22, covIncrement); }

    String getDeviceType() { return getString(31); }
    void setDeviceType(const String& deviceType) { setString(31, deviceType); }

    uint32_t getObjectId() { return getBacOID(75); }
    void setObjectId(uint32_t objectId) { setBacOID(75, objectId); }

    String getObjectName() { return getString(77); }
    void setObjectName(const String& objectName) { setString(77, objectName); }

    uint16_t getObjectType() { return getEnum16(79); }
    void setObjectType(uint16_t objectType) { setEnum16(79, objectType); }

    uint8_t getUpdateInterval() { return getUInt8(118); }
    void setUpdateInterval(uint8_t updateInterval) { setUInt8(118, updateInterval); }

    String getProfileName() { return getString(168); }
    void setProfileName(const String& profileName) { setString(168, profileName); }
};

class PiAnalogOutputExtCluster: public Cluster {
public:
    PiAnalogOutputExtCluster() : Cluster(1541) {
    }

    uint8_t getAckedTransitions() { return getMap8(0); }
    void setAckedTransitions(uint8_t ackedTransitions) { setMap8(0, ackedTransitions); }

    uint16_t getNotificationClass() { return getUInt16(17); }
    void setNotificationClass(uint16_t notificationClass) { setUInt16(17, notificationClass); }

    float getDeadband() { return getSingle(25); }
    void setDeadband(float deadband) { setSingle(25, deadband); }

    uint8_t getEventEnable() { return getMap8(35); }
    void setEventEnable(uint8_t eventEnable) { setMap8(35, eventEnable); }

    uint8_t getEventState() { return getEnum8(36); }
    void setEventState(uint8_t eventState) { setEnum8(36, eventState); }

    float getHighLimit() { return getSingle(45); }
    void setHighLimit(float highLimit) { setSingle(45, highLimit); }

    uint8_t getLimitEnable() { return getMap8(52); }
    void setLimitEnable(uint8_t limitEnable) { setMap8(52, limitEnable); }

    float getLowLimit() { return getSingle(59); }
    void setLowLimit(float lowLimit) { setSingle(59, lowLimit); }

    uint8_t getNotifyType() { return getEnum8(72); }
    void setNotifyType(uint8_t notifyType) { setEnum8(72, notifyType); }

    uint8_t getTimeDelay() { return getUInt8(113); }
    void setTimeDelay(uint8_t timeDelay) { setUInt8(113, timeDelay); }
};

class PiAnalogValueRegCluster: public Cluster {
public:
    PiAnalogValueRegCluster() : Cluster(1542) {
    }

    float getCovIncrement() { return getSingle(22); }
    void setCovIncrement(float covIncrement) { setSingle(22, covIncrement); }

    uint32_t getObjectId() { return getBacOID(75); }
    void setObjectId(uint32_t objectId) { setBacOID(75, objectId); }

    String getObjectName() { return getString(77); }
    void setObjectName(const String& objectName) { setString(77, objectName); }

    uint16_t getObjectType() { return getEnum16(79); }
    void setObjectType(uint16_t objectType) { setEnum16(79, objectType); }

    String getProfileName() { return getString(168); }
    void setProfileName(const String& profileName) { setString(168, profileName); }
};

class PiAnalogValueExtCluster: public Cluster {
public:
    PiAnalogValueExtCluster() : Cluster(1543) {
    }

    uint8_t getAckedTransitions() { return getMap8(0); }
    void setAckedTransitions(uint8_t ackedTransitions) { setMap8(0, ackedTransitions); }

    uint16_t getNotificationClass() { return getUInt16(17); }
    void setNotificationClass(uint16_t notificationClass) { setUInt16(17, notificationClass); }

    float getDeadband() { return getSingle(25); }
    void setDeadband(float deadband) { setSingle(25, deadband); }

    uint8_t getEventEnable() { return getMap8(35); }
    void setEventEnable(uint8_t eventEnable) { setMap8(35, eventEnable); }

    uint8_t getEventState() { return getEnum8(36); }
    void setEventState(uint8_t eventState) { setEnum8(36, eventState); }

    float getHighLimit() { return getSingle(45); }
    void setHighLimit(float highLimit) { setSingle(45, highLimit); }

    uint8_t getLimitEnable() { return getMap8(52); }
    void setLimitEnable(uint8_t limitEnable) { setMap8(52, limitEnable); }

    float getLowLimit() { return getSingle(59); }
    void setLowLimit(float lowLimit) { setSingle(59, lowLimit); }

    uint8_t getNotifyType() { return getEnum8(72); }
    void setNotifyType(uint8_t notifyType) { setEnum8(72, notifyType); }

    uint8_t getTimeDelay() { return getUInt8(113); }
    void setTimeDelay(uint8_t timeDelay) { setUInt8(113, timeDelay); }
};

class PiBinaryInputRegCluster: public Cluster {
public:
    PiBinaryInputRegCluster() : Cluster(1544) {
    }

    uint32_t getChangeOfStateCount() { return getUInt32(15); }
    void setChangeOfStateCount(uint32_t changeOfStateCount) { setUInt32(15, changeOfStateCount); }

    DateTime getChangeOfStateTime() { return getDateTime(16); }
    void setChangeOfStateTime(const DateTime& changeOfStateTime) { setDateTime(16, changeOfStateTime); }

    String getDeviceType() { return getString(31); }
    void setDeviceType(const String& deviceType) { setString(31, deviceType); }

    uint32_t getElapsedActiveTime() { return getUInt32(33); }
    void setElapsedActiveTime(uint32_t elapsedActiveTime) { setUInt32(33, elapsedActiveTime); }

    uint32_t getObjectIdentifier() { return getBacOID(75); }
    void setObjectIdentifier(uint32_t objectIdentifier) { setBacOID(75, objectIdentifier); }

    String getObjectName() { return getString(77); }
    void setObjectName(const String& objectName) { setString(77, objectName); }

    uint16_t getObjectType() { return getEnum16(79); }
    void setObjectType(uint16_t objectType) { setEnum16(79, objectType); }

    DateTime getTimeOfATReset() { return getDateTime(114); }
    void setTimeOfATReset(const DateTime& timeOfATReset) { setDateTime(114, timeOfATReset); }

    DateTime getTimeOfSCReset() { return getDateTime(115); }
    void setTimeOfSCReset(const DateTime& timeOfSCReset) { setDateTime(115, timeOfSCReset); }

    String getProfileName() { return getString(168); }
    void setProfileName(const String& profileName) { setString(168, profileName); }
};

class PiBinaryInputExtCluster: public Cluster {
public:
    PiBinaryInputExtCluster() : Cluster(1545) {
    }

    uint8_t getAckedTransitions() { return getMap8(0); }
    void setAckedTransitions(uint8_t ackedTransitions) { setMap8(0, ackedTransitions); }

    bool getAlarmValue() { return getBool(6); }
    void setAlarmValue(bool alarmValue) { setBool(6, alarmValue); }

    uint16_t getNotificationClass() { return getUInt16(17); }
    void setNotificationClass(uint16_t notificationClass) { setUInt16(17, notificationClass); }

    uint8_t getEventEnable() { return getMap8(35); }
    void setEventEnable(uint8_t eventEnable) { setMap8(35, eventEnable); }

    uint8_t getEventState() { return getEnum8(36); }
    void setEventState(uint8_t eventState) { setEnum8(36, eventState); }

    uint8_t getNotifyType() { return getEnum8(72); }
    void setNotifyType(uint8_t notifyType) { setEnum8(72, notifyType); }

    uint8_t getTimeDelay() { return getUInt8(113); }
    void setTimeDelay(uint8_t timeDelay) { setUInt8(113, timeDelay); }
};

class PiBinaryOutputRegCluster: public Cluster {
public:
    PiBinaryOutputRegCluster() : Cluster(1546) {
    }

    uint32_t getChangeOfStateCount() { return getUInt32(15); }
    void setChangeOfStateCount(uint32_t changeOfStateCount) { setUInt32(15, changeOfStateCount); }

    DateTime getChangeOfStateTime() { return getDateTime(16); }
    void setChangeOfStateTime(const DateTime& changeOfStateTime) { setDateTime(16, changeOfStateTime); }

    String getDeviceType() { return getString(31); }
    void setDeviceType(const String& deviceType) { setString(31, deviceType); }

    uint32_t getElapsedActiveTime() { return getUInt32(33); }
    void setElapsedActiveTime(uint32_t elapsedActiveTime) { setUInt32(33, elapsedActiveTime); }

    uint8_t getFeedBackValue() { return getEnum8(40); }
    void setFeedBackValue(uint8_t feedBackValue) { setEnum8(40, feedBackValue); }

    uint32_t getObjectIdentifier() { return getBacOID(75); }
    void setObjectIdentifier(uint32_t objectIdentifier) { setBacOID(75, objectIdentifier); }

    String getObjectName() { return getString(77); }
    void setObjectName(const String& objectName) { setString(77, objectName); }

    uint16_t getObjectType() { return getEnum16(79); }
    void setObjectType(uint16_t objectType) { setEnum16(79, objectType); }

    DateTime getTimeOfATReset() { return getDateTime(114); }
    void setTimeOfATReset(const DateTime& timeOfATReset) { setDateTime(114, timeOfATReset); }

    DateTime getTimeOfSCReset() { return getDateTime(115); }
    void setTimeOfSCReset(const DateTime& timeOfSCReset) { setDateTime(115, timeOfSCReset); }

    String getProfileName() { return getString(168); }
    void setProfileName(const String& profileName) { setString(168, profileName); }
};

class PiBinaryOutputExtCluster: public Cluster {
public:
    PiBinaryOutputExtCluster() : Cluster(1547) {
    }

    uint8_t getAckedTransitions() { return getMap8(0); }
    void setAckedTransitions(uint8_t ackedTransitions) { setMap8(0, ackedTransitions); }

    uint16_t getNotificationClass() { return getUInt16(17); }
    void setNotificationClass(uint16_t notificationClass) { setUInt16(17, notificationClass); }

    uint8_t getEventEnable() { return getMap8(35); }
    void setEventEnable(uint8_t eventEnable) { setMap8(35, eventEnable); }

    uint8_t getEventState() { return getEnum8(36); }
    void setEventState(uint8_t eventState) { setEnum8(36, eventState); }

    uint8_t getNotifyType() { return getEnum8(72); }
    void setNotifyType(uint8_t notifyType) { setEnum8(72, notifyType); }

    uint8_t getTimeDelay() { return getUInt8(113); }
    void setTimeDelay(uint8_t timeDelay) { setUInt8(113, timeDelay); }
};

class PiBinaryValueRegCluster: public Cluster {
public:
    PiBinaryValueRegCluster() : Cluster(1548) {
    }

    uint32_t getChangeOfStateCount() { return getUInt32(15); }
    void setChangeOfStateCount(uint32_t changeOfStateCount) { setUInt32(15, changeOfStateCount); }

    DateTime getChangeOfStateTime() { return getDateTime(16); }
    void setChangeOfStateTime(const DateTime& changeOfStateTime) { setDateTime(16, changeOfStateTime); }

    uint32_t getElapsedActiveTime() { return getUInt32(33); }
    void setElapsedActiveTime(uint32_t elapsedActiveTime) { setUInt32(33, elapsedActiveTime); }

    uint32_t getObjectIdentifier() { return getBacOID(75); }
    void setObjectIdentifier(uint32_t objectIdentifier) { setBacOID(75, objectIdentifier); }

    String getObjectName() { return getString(77); }
    void setObjectName(const String& objectName) { setString(77, objectName); }

    uint16_t getObjectType() { return getEnum16(79); }
    void setObjectType(uint16_t objectType) { setEnum16(79, objectType); }

    DateTime getTimeOfATReset() { return getDateTime(114); }
    void setTimeOfATReset(const DateTime& timeOfATReset) { setDateTime(114, timeOfATReset); }

    DateTime getTimeOfSCReset() { return getDateTime(115); }
    void setTimeOfSCReset(const DateTime& timeOfSCReset) { setDateTime(115, timeOfSCReset); }

    String getProfileName() { return getString(168); }
    void setProfileName(const String& profileName) { setString(168, profileName); }
};

class PiBinaryValueExtCluster: public Cluster {
public:
    PiBinaryValueExtCluster() : Cluster(1549) {
    }

    uint8_t getAckedTransitions() { return getMap8(0); }
    void setAckedTransitions(uint8_t ackedTransitions) { setMap8(0, ackedTransitions); }

    bool getAlarmValue() { return getBool(6); }
    void setAlarmValue(bool alarmValue) { setBool(6, alarmValue); }

    uint16_t getNotificationClass() { return getUInt16(17); }
    void setNotificationClass(uint16_t notificationClass) { setUInt16(17, notificationClass); }

    uint8_t getEventEnable() { return getMap8(35); }
    void setEventEnable(uint8_t eventEnable) { setMap8(35, eventEnable); }

    uint8_t getEventState() { return getEnum8(36); }
    void setEventState(uint8_t eventState) { setEnum8(36, eventState); }

    uint8_t getNotifyType() { return getEnum8(72); }
    void setNotifyType(uint8_t notifyType) { setEnum8(72, notifyType); }

    uint8_t getTimeDelay() { return getUInt8(113); }
    void setTimeDelay(uint8_t timeDelay) { setUInt8(113, timeDelay); }
};

class PiMultistateInputRegCluster: public Cluster {
public:
    PiMultistateInputRegCluster() : Cluster(1550) {
    }

    String getDeviceType() { return getString(31); }
    void setDeviceType(const String& deviceType) { setString(31, deviceType); }

    uint32_t getObjectId() { return getBacOID(75); }
    void setObjectId(uint32_t objectId) { setBacOID(75, objectId); }

    String getObjectName() { return getString(77); }
    void setObjectName(const String& objectName) { setString(77, objectName); }

    uint16_t getObjectType() { return getEnum16(79); }
    void setObjectType(uint16_t objectType) { setEnum16(79, objectType); }

    String getProfileName() { return getString(168); }
    void setProfileName(const String& profileName) { setString(168, profileName); }
};

class PiMultistateInputExtCluster: public Cluster {
public:
    PiMultistateInputExtCluster() : Cluster(1551) {
    }

    uint8_t getAckedTransitions() { return getMap8(0); }
    void setAckedTransitions(uint8_t ackedTransitions) { setMap8(0, ackedTransitions); }

    uint16_t getAlarmValue() { return getUInt16(6); }
    void setAlarmValue(uint16_t alarmValue) { setUInt16(6, alarmValue); }

    uint16_t getNotificationClass() { return getUInt16(17); }
    void setNotificationClass(uint16_t notificationClass) { setUInt16(17, notificationClass); }

    uint8_t getEventEnable() { return getMap8(35); }
    void setEventEnable(uint8_t eventEnable) { setMap8(35, eventEnable); }

    uint8_t getEventState() { return getEnum8(36); }
    void setEventState(uint8_t eventState) { setEnum8(36, eventState); }

    uint16_t getFaultValues() { return getUInt16(37); }
    void setFaultValues(uint16_t faultValues) { setUInt16(37, faultValues); }

    uint8_t getNotifyType() { return getEnum8(72); }
    void setNotifyType(uint8_t notifyType) { setEnum8(72, notifyType); }

    uint8_t getTimeDelay() { return getUInt8(113); }
    void setTimeDelay(uint8_t timeDelay) { setUInt8(113, timeDelay); }
};

class PiMultistateOutputRegCluster: public Cluster {
public:
    PiMultistateOutputRegCluster() : Cluster(1552) {
    }

    String getDeviceType() { return getString(31); }
    void setDeviceType(const String& deviceType) { setString(31, deviceType); }

    uint8_t getFeedBackValue() { return getEnum8(40); }
    void setFeedBackValue(uint8_t feedBackValue) { setEnum8(40, feedBackValue); }

    uint32_t getObjectId() { return getBacOID(75); }
    void setObjectId(uint32_t objectId) { setBacOID(75, objectId); }

    String getObjectName() { return getString(77); }
    void setObjectName(const String& objectName) { setString(77, objectName); }

    uint16_t getObjectType() { return getEnum16(79); }
    void setObjectType(uint16_t objectType) { setEnum16(79, objectType); }

    String getProfileName() { return getString(168); }
    void setProfileName(const String& profileName) { setString(168, profileName); }
};

class PiMultistateOutputExtCluster: public Cluster {
public:
    PiMultistateOutputExtCluster() : Cluster(1553) {
    }

    uint8_t getAckedTransitions() { return getMap8(0); }
    void setAckedTransitions(uint8_t ackedTransitions) { setMap8(0, ackedTransitions); }

    uint16_t getNotificationClass() { return getUInt16(17); }
    void setNotificationClass(uint16_t notificationClass) { setUInt16(17, notificationClass); }

    uint8_t getEventEnable() { return getMap8(35); }
    void setEventEnable(uint8_t eventEnable) { setMap8(35, eventEnable); }

    uint8_t getEventState() { return getEnum8(36); }
    void setEventState(uint8_t eventState) { setEnum8(36, eventState); }

    uint8_t getNotifyType() { return getEnum8(72); }
    void setNotifyType(uint8_t notifyType) { setEnum8(72, notifyType); }

    uint8_t getTimeDelay() { return getUInt8(113); }
    void setTimeDelay(uint8_t timeDelay) { setUInt8(113, timeDelay); }
};

class PiMultistateValueRegCluster: public Cluster {
public:
    PiMultistateValueRegCluster() : Cluster(1554) {
    }

    uint32_t getObjectId() { return getBacOID(75); }
    void setObjectId(uint32_t objectId) { setBacOID(75, objectId); }

    String getObjectName() { return getString(77); }
    void setObjectName(const String& objectName) { setString(77, objectName); }

    uint16_t getObjectType() { return getEnum16(79); }
    void setObjectType(uint16_t objectType) { setEnum16(79, objectType); }

    String getProfileName() { return getString(168); }
    void setProfileName(const String& profileName) { setString(168, profileName); }
};

class PiMultistateValueExtCluster: public Cluster {
public:
    PiMultistateValueExtCluster() : Cluster(1555) {
    }

    uint8_t getAckedTransitions() { return getMap8(0); }
    void setAckedTransitions(uint8_t ackedTransitions) { setMap8(0, ackedTransitions); }

    uint16_t getAlarmValue() { return getUInt16(6); }
    void setAlarmValue(uint16_t alarmValue) { setUInt16(6, alarmValue); }

    uint16_t getNotificationClass() { return getUInt16(17); }
    void setNotificationClass(uint16_t notificationClass) { setUInt16(17, notificationClass); }

    uint8_t getEventEnable() { return getMap8(35); }
    void setEventEnable(uint8_t eventEnable) { setMap8(35, eventEnable); }

    uint8_t getEventState() { return getEnum8(36); }
    void setEventState(uint8_t eventState) { setEnum8(36, eventState); }

    uint16_t getFaultValues() { return getUInt16(37); }
    void setFaultValues(uint16_t faultValues) { setUInt16(37, faultValues); }

    uint8_t getNotifyType() { return getEnum8(72); }
    void setNotifyType(uint8_t notifyType) { setEnum8(72, notifyType); }

    uint8_t getTimeDelay() { return getUInt8(113); }
    void setTimeDelay(uint8_t timeDelay) { setUInt8(113, timeDelay); }
};

class Pi11073ProtocolTunnelCluster: public Cluster {
public:
    Pi11073ProtocolTunnelCluster() : Cluster(1556) {
    }

    uint64_t getManagerTarget() { return getEUI64(1); }
    void setManagerTarget(uint64_t managerTarget) { setEUI64(1, managerTarget); }

    uint8_t getManagerEndpoint() { return getUInt8(2); }
    void setManagerEndpoint(uint8_t managerEndpoint) { setUInt8(2, managerEndpoint); }

    bool getConnected() { return getBool(3); }
    void setConnected(bool connected) { setBool(3, connected); }

    bool getPreemptible() { return getBool(4); }
    void setPreemptible(bool preemptible) { setBool(4, preemptible); }

    uint16_t getIdleTimeout() { return getUInt16(5); }
    void setIdleTimeout(uint16_t idleTimeout) { setUInt16(5, idleTimeout); }

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

    uint8_t getStatus() { return getUInt8(0); }
    void setStatus(uint8_t status) { setUInt8(0, status); }
};

class PiRetailTunnelCluster: public Cluster {
public:
    PiRetailTunnelCluster() : Cluster(1559) {
    }

    uint16_t getManufacturerCode() { return getUInt16(0); }
    void setManufacturerCode(uint16_t manufacturerCode) { setUInt16(0, manufacturerCode); }

    uint16_t getMsProfile() { return getUInt16(1); }
    void setMsProfile(uint16_t msProfile) { setUInt16(1, msProfile); }
};

class SeMeteringCluster: public Cluster {
public:
    SeMeteringCluster() : Cluster(1794) {
    }

    uint64_t getCurrentSummDelivered() { return getUInt48(0); }
    void setCurrentSummDelivered(uint64_t currentSummDelivered) { setUInt48(0, currentSummDelivered); }

    uint64_t getCurrentSummReceived() { return getUInt48(1); }
    void setCurrentSummReceived(uint64_t currentSummReceived) { setUInt48(1, currentSummReceived); }

    uint64_t getCurrentMaxDemandDelivered() { return getUInt48(2); }
    void setCurrentMaxDemandDelivered(uint64_t currentMaxDemandDelivered) { setUInt48(2, currentMaxDemandDelivered); }

    uint64_t getCurrentMaxDemandReceived() { return getUInt48(3); }
    void setCurrentMaxDemandReceived(uint64_t currentMaxDemandReceived) { setUInt48(3, currentMaxDemandReceived); }

    uint64_t getDftSumm() { return getUInt48(4); }
    void setDftSumm(uint64_t dftSumm) { setUInt48(4, dftSumm); }

    uint16_t getDailyFreezeTime() { return getUInt16(5); }
    void setDailyFreezeTime(uint16_t dailyFreezeTime) { setUInt16(5, dailyFreezeTime); }

    int8_t getPowerFactor() { return getInt8(6); }
    void setPowerFactor(int8_t powerFactor) { setInt8(6, powerFactor); }

    uint32_t getReadingSnapshotTime() { return getUTC(7); }
    void setReadingSnapshotTime(uint32_t readingSnapshotTime) { setUTC(7, readingSnapshotTime); }

    uint32_t getCurrentMaxDemandDeliverdTime() { return getUTC(8); }
    void setCurrentMaxDemandDeliverdTime(uint32_t currentMaxDemandDeliverdTime) { setUTC(8, currentMaxDemandDeliverdTime); }

    uint32_t getCurrentMaxDemandReceivedTime() { return getUTC(9); }
    void setCurrentMaxDemandReceivedTime(uint32_t currentMaxDemandReceivedTime) { setUTC(9, currentMaxDemandReceivedTime); }

    uint8_t getDefaultUpdatePeriod() { return getUInt8(10); }
    void setDefaultUpdatePeriod(uint8_t defaultUpdatePeriod) { setUInt8(10, defaultUpdatePeriod); }

    uint8_t getFastPollUpdatePeriod() { return getUInt8(11); }
    void setFastPollUpdatePeriod(uint8_t fastPollUpdatePeriod) { setUInt8(11, fastPollUpdatePeriod); }

    uint64_t getCurrentBlockPeriodConsumpDelivered() { return getUInt48(12); }
    void setCurrentBlockPeriodConsumpDelivered(uint64_t currentBlockPeriodConsumpDelivered) { setUInt48(12, currentBlockPeriodConsumpDelivered); }

    uint32_t getDailyConsumpTarget() { return getUInt24(13); }
    void setDailyConsumpTarget(uint32_t dailyConsumpTarget) { setUInt24(13, dailyConsumpTarget); }

    uint8_t getCurrentBlock() { return getEnum8(14); }
    void setCurrentBlock(uint8_t currentBlock) { setEnum8(14, currentBlock); }

    uint8_t getProfileIntervalPeriod() { return getEnum8(15); }
    void setProfileIntervalPeriod(uint8_t profileIntervalPeriod) { setEnum8(15, profileIntervalPeriod); }

    uint16_t getIntervalReadReportingPeriod() { return getUInt16(16); }
    void setIntervalReadReportingPeriod(uint16_t intervalReadReportingPeriod) { setUInt16(16, intervalReadReportingPeriod); }

    uint16_t getPresetReadingTime() { return getUInt16(17); }
    void setPresetReadingTime(uint16_t presetReadingTime) { setUInt16(17, presetReadingTime); }

    uint16_t getVolumePerReport() { return getUInt16(18); }
    void setVolumePerReport(uint16_t volumePerReport) { setUInt16(18, volumePerReport); }

    uint8_t getFlowRestriction() { return getUInt8(19); }
    void setFlowRestriction(uint8_t flowRestriction) { setUInt8(19, flowRestriction); }

    uint8_t getSupplyStatus() { return getEnum8(20); }
    void setSupplyStatus(uint8_t supplyStatus) { setEnum8(20, supplyStatus); }

    uint64_t getCurrentInEnergyCarrierSumm() { return getUInt48(21); }
    void setCurrentInEnergyCarrierSumm(uint64_t currentInEnergyCarrierSumm) { setUInt48(21, currentInEnergyCarrierSumm); }

    uint64_t getCurrentOutEnergyCarrierSumm() { return getUInt48(22); }
    void setCurrentOutEnergyCarrierSumm(uint64_t currentOutEnergyCarrierSumm) { setUInt48(22, currentOutEnergyCarrierSumm); }

    int32_t getInletTempreature() { return getInt24(23); }
    void setInletTempreature(int32_t inletTempreature) { setInt24(23, inletTempreature); }

    int32_t getOutletTempreature() { return getInt24(24); }
    void setOutletTempreature(int32_t outletTempreature) { setInt24(24, outletTempreature); }

    int32_t getControlTempreature() { return getInt24(25); }
    void setControlTempreature(int32_t controlTempreature) { setInt24(25, controlTempreature); }

    int32_t getCurrentInEnergyCarrierDemand() { return getInt24(26); }
    void setCurrentInEnergyCarrierDemand(int32_t currentInEnergyCarrierDemand) { setInt24(26, currentInEnergyCarrierDemand); }

    int32_t getCurrentOutEnergyCarrierDemand() { return getInt24(27); }
    void setCurrentOutEnergyCarrierDemand(int32_t currentOutEnergyCarrierDemand) { setInt24(27, currentOutEnergyCarrierDemand); }

    uint64_t getCurrentBlockPeriodConsumpReceived() { return getUInt48(29); }
    void setCurrentBlockPeriodConsumpReceived(uint64_t currentBlockPeriodConsumpReceived) { setUInt48(29, currentBlockPeriodConsumpReceived); }

    uint64_t getCurrentBlockReceived() { return getUInt48(30); }
    void setCurrentBlockReceived(uint64_t currentBlockReceived) { setUInt48(30, currentBlockReceived); }

    uint64_t getDFTSummationReceived() { return getUInt48(31); }
    void setDFTSummationReceived(uint64_t DFTSummationReceived) { setUInt48(31, DFTSummationReceived); }

    uint8_t getActiveRegisterTierDelivered() { return getEnum8(32); }
    void setActiveRegisterTierDelivered(uint8_t activeRegisterTierDelivered) { setEnum8(32, activeRegisterTierDelivered); }

    uint8_t getActiveRegisterTierReceived() { return getEnum8(33); }
    void setActiveRegisterTierReceived(uint8_t activeRegisterTierReceived) { setEnum8(33, activeRegisterTierReceived); }

    uint64_t getCurrentTier1SummDelivered() { return getUInt48(256); }
    void setCurrentTier1SummDelivered(uint64_t currentTier1SummDelivered) { setUInt48(256, currentTier1SummDelivered); }

    uint64_t getCurrentTier1SummReceived() { return getUInt48(257); }
    void setCurrentTier1SummReceived(uint64_t currentTier1SummReceived) { setUInt48(257, currentTier1SummReceived); }

    uint64_t getCurrentTier2SummDelivered() { return getUInt48(258); }
    void setCurrentTier2SummDelivered(uint64_t currentTier2SummDelivered) { setUInt48(258, currentTier2SummDelivered); }

    uint64_t getCurrentTier2SummReceived() { return getUInt48(259); }
    void setCurrentTier2SummReceived(uint64_t currentTier2SummReceived) { setUInt48(259, currentTier2SummReceived); }

    uint64_t getCurrentTier3SummDelivered() { return getUInt48(260); }
    void setCurrentTier3SummDelivered(uint64_t currentTier3SummDelivered) { setUInt48(260, currentTier3SummDelivered); }

    uint64_t getCurrentTier3SummReceived() { return getUInt48(261); }
    void setCurrentTier3SummReceived(uint64_t currentTier3SummReceived) { setUInt48(261, currentTier3SummReceived); }

    uint64_t getCurrentTier4SummDelivered() { return getUInt48(262); }
    void setCurrentTier4SummDelivered(uint64_t currentTier4SummDelivered) { setUInt48(262, currentTier4SummDelivered); }

    uint64_t getCurrentTier4SummReceived() { return getUInt48(263); }
    void setCurrentTier4SummReceived(uint64_t currentTier4SummReceived) { setUInt48(263, currentTier4SummReceived); }

    uint64_t getCurrentTier5SummDelivered() { return getUInt48(264); }
    void setCurrentTier5SummDelivered(uint64_t currentTier5SummDelivered) { setUInt48(264, currentTier5SummDelivered); }

    uint64_t getCurrentTier5SummReceived() { return getUInt48(265); }
    void setCurrentTier5SummReceived(uint64_t currentTier5SummReceived) { setUInt48(265, currentTier5SummReceived); }

    uint64_t getCurrentTier6SummDelivered() { return getUInt48(266); }
    void setCurrentTier6SummDelivered(uint64_t currentTier6SummDelivered) { setUInt48(266, currentTier6SummDelivered); }

    uint64_t getCurrentTier6SummReceived() { return getUInt48(267); }
    void setCurrentTier6SummReceived(uint64_t currentTier6SummReceived) { setUInt48(267, currentTier6SummReceived); }

    uint64_t getCurrentTier7SummDelivered() { return getUInt48(268); }
    void setCurrentTier7SummDelivered(uint64_t currentTier7SummDelivered) { setUInt48(268, currentTier7SummDelivered); }

    uint64_t getCurrentTier7SummReceived() { return getUInt48(269); }
    void setCurrentTier7SummReceived(uint64_t currentTier7SummReceived) { setUInt48(269, currentTier7SummReceived); }

    uint64_t getCurrentTier8SummDelivered() { return getUInt48(270); }
    void setCurrentTier8SummDelivered(uint64_t currentTier8SummDelivered) { setUInt48(270, currentTier8SummDelivered); }

    uint64_t getCurrentTier8SummReceived() { return getUInt48(271); }
    void setCurrentTier8SummReceived(uint64_t currentTier8SummReceived) { setUInt48(271, currentTier8SummReceived); }

    uint64_t getCurrentTier9SummDelivered() { return getUInt48(272); }
    void setCurrentTier9SummDelivered(uint64_t currentTier9SummDelivered) { setUInt48(272, currentTier9SummDelivered); }

    uint64_t getCurrentTier9SummReceived() { return getUInt48(273); }
    void setCurrentTier9SummReceived(uint64_t currentTier9SummReceived) { setUInt48(273, currentTier9SummReceived); }

    uint64_t getCurrentTier10SummDelivered() { return getUInt48(274); }
    void setCurrentTier10SummDelivered(uint64_t currentTier10SummDelivered) { setUInt48(274, currentTier10SummDelivered); }

    uint64_t getCurrentTier10SummReceived() { return getUInt48(275); }
    void setCurrentTier10SummReceived(uint64_t currentTier10SummReceived) { setUInt48(275, currentTier10SummReceived); }

    uint64_t getCurrentTier11SummDelivered() { return getUInt48(276); }
    void setCurrentTier11SummDelivered(uint64_t currentTier11SummDelivered) { setUInt48(276, currentTier11SummDelivered); }

    uint64_t getCurrentTier11SummReceived() { return getUInt48(277); }
    void setCurrentTier11SummReceived(uint64_t currentTier11SummReceived) { setUInt48(277, currentTier11SummReceived); }

    uint64_t getCurrentTier12SummDelivered() { return getUInt48(278); }
    void setCurrentTier12SummDelivered(uint64_t currentTier12SummDelivered) { setUInt48(278, currentTier12SummDelivered); }

    uint64_t getCurrentTier12SummReceived() { return getUInt48(279); }
    void setCurrentTier12SummReceived(uint64_t currentTier12SummReceived) { setUInt48(279, currentTier12SummReceived); }

    uint64_t getCurrentTier13SummDelivered() { return getUInt48(280); }
    void setCurrentTier13SummDelivered(uint64_t currentTier13SummDelivered) { setUInt48(280, currentTier13SummDelivered); }

    uint64_t getCurrentTier13SummReceived() { return getUInt48(281); }
    void setCurrentTier13SummReceived(uint64_t currentTier13SummReceived) { setUInt48(281, currentTier13SummReceived); }

    uint64_t getCurrentTier14SummDelivered() { return getUInt48(282); }
    void setCurrentTier14SummDelivered(uint64_t currentTier14SummDelivered) { setUInt48(282, currentTier14SummDelivered); }

    uint64_t getCurrentTier14SummReceived() { return getUInt48(283); }
    void setCurrentTier14SummReceived(uint64_t currentTier14SummReceived) { setUInt48(283, currentTier14SummReceived); }

    uint64_t getCurrentTier15SummDelivered() { return getUInt48(284); }
    void setCurrentTier15SummDelivered(uint64_t currentTier15SummDelivered) { setUInt48(284, currentTier15SummDelivered); }

    uint64_t getCurrentTier15SummReceived() { return getUInt48(285); }
    void setCurrentTier15SummReceived(uint64_t currentTier15SummReceived) { setUInt48(285, currentTier15SummReceived); }

    uint8_t getStatus() { return getMap8(512); }
    void setStatus(uint8_t status) { setMap8(512, status); }

    uint8_t getRemainingBattLife() { return getUInt8(513); }
    void setRemainingBattLife(uint8_t remainingBattLife) { setUInt8(513, remainingBattLife); }

    uint32_t getHoursInOperation() { return getUInt24(514); }
    void setHoursInOperation(uint32_t hoursInOperation) { setUInt24(514, hoursInOperation); }

    uint32_t getHoursInFault() { return getUInt24(515); }
    void setHoursInFault(uint32_t hoursInFault) { setUInt24(515, hoursInFault); }

    uint64_t getExtendedStatus() { return getMap64(516); }
    void setExtendedStatus(uint64_t extendedStatus) { setMap64(516, extendedStatus); }

    uint8_t getUnitOfMeasure() { return getEnum8(768); }
    void setUnitOfMeasure(uint8_t unitOfMeasure) { setEnum8(768, unitOfMeasure); }

    uint32_t getMultiplier() { return getUInt24(769); }
    void setMultiplier(uint32_t multiplier) { setUInt24(769, multiplier); }

    uint32_t getDivisor() { return getUInt24(770); }
    void setDivisor(uint32_t divisor) { setUInt24(770, divisor); }

    uint8_t getSummaFormatting() { return getMap8(771); }
    void setSummaFormatting(uint8_t summaFormatting) { setMap8(771, summaFormatting); }

    uint8_t getDemandFormatting() { return getMap8(772); }
    void setDemandFormatting(uint8_t demandFormatting) { setMap8(772, demandFormatting); }

    uint8_t getHistoricalConsumpFormatting() { return getMap8(773); }
    void setHistoricalConsumpFormatting(uint8_t historicalConsumpFormatting) { setMap8(773, historicalConsumpFormatting); }

    uint8_t getMeteringDeviceType() { return getMap8(774); }
    void setMeteringDeviceType(uint8_t meteringDeviceType) { setMap8(774, meteringDeviceType); }

    Buffer getSiteId() { return getOctstr(775); }
    void setSiteId(const Buffer& siteId) { setOctstr(775, siteId); }

    Buffer getMeterSerialNumber() { return getOctstr(776); }
    void setMeterSerialNumber(const Buffer& meterSerialNumber) { setOctstr(776, meterSerialNumber); }

    uint8_t getEnergyCarrierUnitOfMeas() { return getEnum8(777); }
    void setEnergyCarrierUnitOfMeas(uint8_t energyCarrierUnitOfMeas) { setEnum8(777, energyCarrierUnitOfMeas); }

    uint8_t getEnergyCarrierSummFormatting() { return getMap8(778); }
    void setEnergyCarrierSummFormatting(uint8_t energyCarrierSummFormatting) { setMap8(778, energyCarrierSummFormatting); }

    uint8_t getEnergyCarrierDemandFormatting() { return getMap8(779); }
    void setEnergyCarrierDemandFormatting(uint8_t energyCarrierDemandFormatting) { setMap8(779, energyCarrierDemandFormatting); }

    uint8_t getTemperatureUnitOfMeas() { return getEnum8(780); }
    void setTemperatureUnitOfMeas(uint8_t temperatureUnitOfMeas) { setEnum8(780, temperatureUnitOfMeas); }

    uint8_t getTemperatureFormatting() { return getMap8(781); }
    void setTemperatureFormatting(uint8_t temperatureFormatting) { setMap8(781, temperatureFormatting); }

    Buffer getModuleSerialNumber() { return getOctstr(782); }
    void setModuleSerialNumber(const Buffer& moduleSerialNumber) { setOctstr(782, moduleSerialNumber); }

    Buffer getOperatingTariffLevel() { return getOctstr(783); }
    void setOperatingTariffLevel(const Buffer& operatingTariffLevel) { setOctstr(783, operatingTariffLevel); }

    int32_t getInstantaneousDemand() { return getInt24(1024); }
    void setInstantaneousDemand(int32_t instantaneousDemand) { setInt24(1024, instantaneousDemand); }

    uint32_t getCurrentdayConsumpDelivered() { return getUInt24(1025); }
    void setCurrentdayConsumpDelivered(uint32_t currentdayConsumpDelivered) { setUInt24(1025, currentdayConsumpDelivered); }

    uint32_t getCurrentdayConsumpReceived() { return getUInt24(1026); }
    void setCurrentdayConsumpReceived(uint32_t currentdayConsumpReceived) { setUInt24(1026, currentdayConsumpReceived); }

    uint32_t getPreviousdayConsumpDelivered() { return getUInt24(1027); }
    void setPreviousdayConsumpDelivered(uint32_t previousdayConsumpDelivered) { setUInt24(1027, previousdayConsumpDelivered); }

    uint32_t getPreviousdayConsumpReceived() { return getUInt24(1028); }
    void setPreviousdayConsumpReceived(uint32_t previousdayConsumpReceived) { setUInt24(1028, previousdayConsumpReceived); }

    uint32_t getCurPartProfileIntStartTimeDelivered() { return getUTC(1029); }
    void setCurPartProfileIntStartTimeDelivered(uint32_t curPartProfileIntStartTimeDelivered) { setUTC(1029, curPartProfileIntStartTimeDelivered); }

    uint32_t getCurPartProfileIntStartTimeReceived() { return getUTC(1030); }
    void setCurPartProfileIntStartTimeReceived(uint32_t curPartProfileIntStartTimeReceived) { setUTC(1030, curPartProfileIntStartTimeReceived); }

    uint32_t getCurPartProfileIntValueDelivered() { return getUInt24(1031); }
    void setCurPartProfileIntValueDelivered(uint32_t curPartProfileIntValueDelivered) { setUInt24(1031, curPartProfileIntValueDelivered); }

    uint32_t getCurPartProfileIntValueReceived() { return getUInt24(1032); }
    void setCurPartProfileIntValueReceived(uint32_t curPartProfileIntValueReceived) { setUInt24(1032, curPartProfileIntValueReceived); }

    uint64_t getCurrentDayMaxPressure() { return getUInt48(1033); }
    void setCurrentDayMaxPressure(uint64_t currentDayMaxPressure) { setUInt48(1033, currentDayMaxPressure); }

    uint64_t getCurrentDayMinPressure() { return getUInt48(1034); }
    void setCurrentDayMinPressure(uint64_t currentDayMinPressure) { setUInt48(1034, currentDayMinPressure); }

    uint64_t getPreviousDayMaxPressure() { return getUInt48(1035); }
    void setPreviousDayMaxPressure(uint64_t previousDayMaxPressure) { setUInt48(1035, previousDayMaxPressure); }

    uint64_t getPreviousDayMinPressure() { return getUInt48(1036); }
    void setPreviousDayMinPressure(uint64_t previousDayMinPressure) { setUInt48(1036, previousDayMinPressure); }

    int32_t getCurrentDayMaxDemand() { return getInt24(1037); }
    void setCurrentDayMaxDemand(int32_t currentDayMaxDemand) { setInt24(1037, currentDayMaxDemand); }

    int32_t getPreviousDayMaxDemand() { return getInt24(1038); }
    void setPreviousDayMaxDemand(int32_t previousDayMaxDemand) { setInt24(1038, previousDayMaxDemand); }

    int32_t getCurrentMonthMaxDemand() { return getInt24(1039); }
    void setCurrentMonthMaxDemand(int32_t currentMonthMaxDemand) { setInt24(1039, currentMonthMaxDemand); }

    int32_t getCurrentYearMaxDemand() { return getInt24(1040); }
    void setCurrentYearMaxDemand(int32_t currentYearMaxDemand) { setInt24(1040, currentYearMaxDemand); }

    int32_t getCurrentdayMaxEnergyCarrDemand() { return getInt24(1041); }
    void setCurrentdayMaxEnergyCarrDemand(int32_t currentdayMaxEnergyCarrDemand) { setInt24(1041, currentdayMaxEnergyCarrDemand); }

    int32_t getPreviousdayMaxEnergyCarrDemand() { return getInt24(1042); }
    void setPreviousdayMaxEnergyCarrDemand(int32_t previousdayMaxEnergyCarrDemand) { setInt24(1042, previousdayMaxEnergyCarrDemand); }

    int32_t getCurMonthMaxEnergyCarrDemand() { return getInt24(1043); }
    void setCurMonthMaxEnergyCarrDemand(int32_t curMonthMaxEnergyCarrDemand) { setInt24(1043, curMonthMaxEnergyCarrDemand); }

    int32_t getCurMonthMinEnergyCarrDemand() { return getInt24(1044); }
    void setCurMonthMinEnergyCarrDemand(int32_t curMonthMinEnergyCarrDemand) { setInt24(1044, curMonthMinEnergyCarrDemand); }

    int32_t getCurYearMaxEnergyCarrDemand() { return getInt24(1045); }
    void setCurYearMaxEnergyCarrDemand(int32_t curYearMaxEnergyCarrDemand) { setInt24(1045, curYearMaxEnergyCarrDemand); }

    int32_t getCurYearMinEnergyCarrDemand() { return getInt24(1046); }
    void setCurYearMinEnergyCarrDemand(int32_t curYearMinEnergyCarrDemand) { setInt24(1046, curYearMinEnergyCarrDemand); }

    uint8_t getMaxNumberOfPeriodsDelivered() { return getUInt8(1280); }
    void setMaxNumberOfPeriodsDelivered(uint8_t maxNumberOfPeriodsDelivered) { setUInt8(1280, maxNumberOfPeriodsDelivered); }

    uint32_t getCurrentDemandDelivered() { return getUInt24(1536); }
    void setCurrentDemandDelivered(uint32_t currentDemandDelivered) { setUInt24(1536, currentDemandDelivered); }

    uint32_t getDemandLimit() { return getUInt24(1537); }
    void setDemandLimit(uint32_t demandLimit) { setUInt24(1537, demandLimit); }

    uint8_t getDemandIntegrationPeriod() { return getUInt8(1538); }
    void setDemandIntegrationPeriod(uint8_t demandIntegrationPeriod) { setUInt8(1538, demandIntegrationPeriod); }

    uint8_t getNumberOfDemandSubintervals() { return getUInt8(1539); }
    void setNumberOfDemandSubintervals(uint8_t numberOfDemandSubintervals) { setUInt8(1539, numberOfDemandSubintervals); }

    uint16_t getDemandLimitArmDuration() { return getUInt16(1540); }
    void setDemandLimitArmDuration(uint16_t demandLimitArmDuration) { setUInt16(1540, demandLimitArmDuration); }

    uint16_t getGenericAlarmMask() { return getMap16(2048); }
    void setGenericAlarmMask(uint16_t genericAlarmMask) { setMap16(2048, genericAlarmMask); }

    uint32_t getElectricityAlarmMask() { return getMap32(2049); }
    void setElectricityAlarmMask(uint32_t electricityAlarmMask) { setMap32(2049, electricityAlarmMask); }

    uint16_t getGenFlowPressureAlarmMask() { return getMap16(2050); }
    void setGenFlowPressureAlarmMask(uint16_t genFlowPressureAlarmMask) { setMap16(2050, genFlowPressureAlarmMask); }

    uint16_t getWaterSpecificAlarmMask() { return getMap16(2051); }
    void setWaterSpecificAlarmMask(uint16_t waterSpecificAlarmMask) { setMap16(2051, waterSpecificAlarmMask); }

    uint16_t getHeatCoolSpecificAlarmMASK() { return getMap16(2052); }
    void setHeatCoolSpecificAlarmMASK(uint16_t heatCoolSpecificAlarmMASK) { setMap16(2052, heatCoolSpecificAlarmMASK); }

    uint16_t getGasSpecificAlarmMask() { return getMap16(2053); }
    void setGasSpecificAlarmMask(uint16_t gasSpecificAlarmMask) { setMap16(2053, gasSpecificAlarmMask); }

    uint64_t getExtendedGenericAlarmMask() { return getMap48(2054); }
    void setExtendedGenericAlarmMask(uint64_t extendedGenericAlarmMask) { setMap48(2054, extendedGenericAlarmMask); }

    uint16_t getManufactureAlarmMask() { return getMap16(2055); }
    void setManufactureAlarmMask(uint16_t manufactureAlarmMask) { setMap16(2055, manufactureAlarmMask); }

    uint32_t getBillToDate() { return getUInt32(2560); }
    void setBillToDate(uint32_t billToDate) { setUInt32(2560, billToDate); }

    uint32_t getBillToDateTimeStamp() { return getUTC(2561); }
    void setBillToDateTimeStamp(uint32_t billToDateTimeStamp) { setUTC(2561, billToDateTimeStamp); }

    uint32_t getProjectedBill() { return getUInt32(2562); }
    void setProjectedBill(uint32_t projectedBill) { setUInt32(2562, projectedBill); }

    uint32_t getProjectedBillTimeStamp() { return getUTC(2563); }
    void setProjectedBillTimeStamp(uint32_t projectedBillTimeStamp) { setUTC(2563, projectedBillTimeStamp); }

    uint32_t getNotificationControlFlags() { return getMap32(0); }
    void setNotificationControlFlags(uint32_t notificationControlFlags) { setMap32(0, notificationControlFlags); }

    uint32_t getNotificationFlags() { return getMap32(1); }
    void setNotificationFlags(uint32_t notificationFlags) { setMap32(1, notificationFlags); }

    uint32_t getPriceNotificationFlags() { return getMap32(2); }
    void setPriceNotificationFlags(uint32_t priceNotificationFlags) { setMap32(2, priceNotificationFlags); }

    uint32_t getCalendarNotificationFlags() { return getMap32(3); }
    void setCalendarNotificationFlags(uint32_t calendarNotificationFlags) { setMap32(3, calendarNotificationFlags); }

    uint32_t getPrePayNotificationFlags() { return getMap32(4); }
    void setPrePayNotificationFlags(uint32_t prePayNotificationFlags) { setMap32(4, prePayNotificationFlags); }

    uint32_t getDeviceManagementFlags() { return getMap32(5); }
    void setDeviceManagementFlags(uint32_t deviceManagementFlags) { setMap32(5, deviceManagementFlags); }

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

    String getNodeDescription() { return getString(0); }
    void setNodeDescription(const String& nodeDescription) { setString(0, nodeDescription); }

    bool getDeliveryEnable() { return getBool(1); }
    void setDeliveryEnable(bool deliveryEnable) { setBool(1, deliveryEnable); }

    uint32_t getPushInformationTimer() { return getUInt32(2); }
    void setPushInformationTimer(uint32_t pushInformationTimer) { setUInt32(2, pushInformationTimer); }

    bool getEnableSecureConfiguration() { return getBool(3); }
    void setEnableSecureConfiguration(bool enableSecureConfiguration) { setBool(3, enableSecureConfiguration); }

    uint16_t getNumberOfContents() { return getUInt16(16); }
    void setNumberOfContents(uint16_t numberOfContents) { setUInt16(16, numberOfContents); }

    uint16_t getContentRootID() { return getUInt16(17); }
    void setContentRootID(uint16_t contentRootID) { setUInt16(17, contentRootID); }
};

class TelecommunicationsVoiceOverZigbeeCluster: public Cluster {
public:
    TelecommunicationsVoiceOverZigbeeCluster() : Cluster(2308) {
    }

    uint8_t getCodecType() { return getEnum8(0); }
    void setCodecType(uint8_t codecType) { setEnum8(0, codecType); }

    uint8_t getSamplingFrequency() { return getEnum8(1); }
    void setSamplingFrequency(uint8_t samplingFrequency) { setEnum8(1, samplingFrequency); }

    uint8_t getCodecrate() { return getEnum8(2); }
    void setCodecrate(uint8_t codecrate) { setEnum8(2, codecrate); }

    uint8_t getEstablishmentTimeout() { return getUInt8(3); }
    void setEstablishmentTimeout(uint8_t establishmentTimeout) { setUInt8(3, establishmentTimeout); }

    uint8_t getCodecTypeSub1() { return getEnum8(4); }
    void setCodecTypeSub1(uint8_t codecTypeSub1) { setEnum8(4, codecTypeSub1); }

    uint8_t getCodecTypeSub2() { return getEnum8(5); }
    void setCodecTypeSub2(uint8_t codecTypeSub2) { setEnum8(5, codecTypeSub2); }

    uint8_t getCodecTypeSub3() { return getEnum8(6); }
    void setCodecTypeSub3(uint8_t codecTypeSub3) { setEnum8(6, codecTypeSub3); }

    uint8_t getCompressionType() { return getEnum8(7); }
    void setCompressionType(uint8_t compressionType) { setEnum8(7, compressionType); }

    uint8_t getCompressionRate() { return getEnum8(8); }
    void setCompressionRate(uint8_t compressionRate) { setEnum8(8, compressionRate); }

    uint8_t getOptionFlags() { return getMap8(9); }
    void setOptionFlags(uint8_t optionFlags) { setMap8(9, optionFlags); }

    uint8_t getThreshold() { return getUInt8(10); }
    void setThreshold(uint8_t threshold) { setUInt8(10, threshold); }
};

class TelecommunicationsChattingCluster: public Cluster {
public:
    TelecommunicationsChattingCluster() : Cluster(2309) {
    }

    uint16_t getUID() { return getUInt16(0); }
    void setUID(uint16_t uID) { setUInt16(0, uID); }

    String getNickname() { return getString(1); }
    void setNickname(const String& nickname) { setString(1, nickname); }

    uint16_t getCID() { return getUInt16(16); }
    void setCID(uint16_t cID) { setUInt16(16, cID); }

    String getName() { return getString(17); }
    void setName(const String& name) { setString(17, name); }

    bool getEnableAddChat() { return getBool(18); }
    void setEnableAddChat(bool enableAddChat) { setBool(18, enableAddChat); }
};

class HaApplianceIdentificationCluster: public Cluster {
public:
    HaApplianceIdentificationCluster() : Cluster(2816) {
    }

    uint64_t getBasicIdentification() { return getUInt56(0); }
    void setBasicIdentification(uint64_t basicIdentification) { setUInt56(0, basicIdentification); }

    String getCompanyName() { return getString(16); }
    void setCompanyName(const String& companyName) { setString(16, companyName); }

    uint16_t getCompanyId() { return getUInt16(17); }
    void setCompanyId(uint16_t companyId) { setUInt16(17, companyId); }

    String getBrandName() { return getString(18); }
    void setBrandName(const String& brandName) { setString(18, brandName); }

    uint16_t getBrandId() { return getUInt16(19); }
    void setBrandId(uint16_t brandId) { setUInt16(19, brandId); }

    Buffer getModel() { return getOctstr(20); }
    void setModel(const Buffer& model) { setOctstr(20, model); }

    Buffer getPartNumber() { return getOctstr(21); }
    void setPartNumber(const Buffer& partNumber) { setOctstr(21, partNumber); }

    Buffer getProductRevision() { return getOctstr(22); }
    void setProductRevision(const Buffer& productRevision) { setOctstr(22, productRevision); }

    Buffer getSoftwareRevision() { return getOctstr(23); }
    void setSoftwareRevision(const Buffer& softwareRevision) { setOctstr(23, softwareRevision); }

    Buffer getProductTypeName() { return getOctstr(24); }
    void setProductTypeName(const Buffer& productTypeName) { setOctstr(24, productTypeName); }

    uint16_t getProductTypeId() { return getUInt16(25); }
    void setProductTypeId(uint16_t productTypeId) { setUInt16(25, productTypeId); }

    uint8_t getCecedSpecificationVersion() { return getUInt8(26); }
    void setCecedSpecificationVersion(uint8_t cecedSpecificationVersion) { setUInt8(26, cecedSpecificationVersion); }
};

class HaMeterIdentificationCluster: public Cluster {
public:
    HaMeterIdentificationCluster() : Cluster(2817) {
    }

    String getCompanyName() { return getString(0); }
    void setCompanyName(const String& companyName) { setString(0, companyName); }

    uint16_t getMeterTypeId() { return getUInt16(1); }
    void setMeterTypeId(uint16_t meterTypeId) { setUInt16(1, meterTypeId); }

    uint16_t getDataQualityId() { return getUInt16(4); }
    void setDataQualityId(uint16_t dataQualityId) { setUInt16(4, dataQualityId); }

    String getCustomerName() { return getString(5); }
    void setCustomerName(const String& customerName) { setString(5, customerName); }

    String getModel() { return getString(6); }
    void setModel(const String& model) { setString(6, model); }

    String getPartNumber() { return getString(7); }
    void setPartNumber(const String& partNumber) { setString(7, partNumber); }

    String getProductRevision() { return getString(8); }
    void setProductRevision(const String& productRevision) { setString(8, productRevision); }

    String getSoftwareRevision() { return getString(10); }
    void setSoftwareRevision(const String& softwareRevision) { setString(10, softwareRevision); }

    String getUtilityName() { return getString(11); }
    void setUtilityName(const String& utilityName) { setString(11, utilityName); }

    String getPod() { return getString(12); }
    void setPod(const String& pod) { setString(12, pod); }

    int32_t getAvailablePower() { return getInt24(13); }
    void setAvailablePower(int32_t availablePower) { setInt24(13, availablePower); }

    int32_t getPowerThreshold() { return getInt24(14); }
    void setPowerThreshold(int32_t powerThreshold) { setInt24(14, powerThreshold); }
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

    uint32_t getLogMaxSize() { return getUInt32(0); }
    void setLogMaxSize(uint32_t logMaxSize) { setUInt32(0, logMaxSize); }

    uint8_t getLogQueueMaxSize() { return getUInt8(1); }
    void setLogQueueMaxSize(uint8_t logQueueMaxSize) { setUInt8(1, logQueueMaxSize); }

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

    uint32_t getMeasurementType() { return getMap32(0); }
    void setMeasurementType(uint32_t measurementType) { setMap32(0, measurementType); }

    int16_t getDcVoltage() { return getInt16(256); }
    void setDcVoltage(int16_t dcVoltage) { setInt16(256, dcVoltage); }

    int16_t getDcVoltageMin() { return getInt16(257); }
    void setDcVoltageMin(int16_t dcVoltageMin) { setInt16(257, dcVoltageMin); }

    int16_t getDcvoltagemax() { return getInt16(258); }
    void setDcvoltagemax(int16_t dcvoltagemax) { setInt16(258, dcvoltagemax); }

    int16_t getDcCurrent() { return getInt16(259); }
    void setDcCurrent(int16_t dcCurrent) { setInt16(259, dcCurrent); }

    int16_t getDcCurrentMin() { return getInt16(260); }
    void setDcCurrentMin(int16_t dcCurrentMin) { setInt16(260, dcCurrentMin); }

    int16_t getDcCurrentMax() { return getInt16(261); }
    void setDcCurrentMax(int16_t dcCurrentMax) { setInt16(261, dcCurrentMax); }

    int16_t getDcPower() { return getInt16(262); }
    void setDcPower(int16_t dcPower) { setInt16(262, dcPower); }

    int16_t getDcPowerMin() { return getInt16(263); }
    void setDcPowerMin(int16_t dcPowerMin) { setInt16(263, dcPowerMin); }

    int16_t getDcPowerMax() { return getInt16(264); }
    void setDcPowerMax(int16_t dcPowerMax) { setInt16(264, dcPowerMax); }

    uint16_t getDcVoltageMultiplier() { return getUInt16(512); }
    void setDcVoltageMultiplier(uint16_t dcVoltageMultiplier) { setUInt16(512, dcVoltageMultiplier); }

    uint16_t getDcVoltageDivisor() { return getUInt16(513); }
    void setDcVoltageDivisor(uint16_t dcVoltageDivisor) { setUInt16(513, dcVoltageDivisor); }

    uint16_t getDcCurrentMultiplier() { return getUInt16(514); }
    void setDcCurrentMultiplier(uint16_t dcCurrentMultiplier) { setUInt16(514, dcCurrentMultiplier); }

    uint16_t getDcCurrentDivisor() { return getUInt16(515); }
    void setDcCurrentDivisor(uint16_t dcCurrentDivisor) { setUInt16(515, dcCurrentDivisor); }

    uint16_t getDcPowerMultiplier() { return getUInt16(516); }
    void setDcPowerMultiplier(uint16_t dcPowerMultiplier) { setUInt16(516, dcPowerMultiplier); }

    uint16_t getDcPowerDivisor() { return getUInt16(517); }
    void setDcPowerDivisor(uint16_t dcPowerDivisor) { setUInt16(517, dcPowerDivisor); }

    uint16_t getAcFrequency() { return getUInt16(768); }
    void setAcFrequency(uint16_t acFrequency) { setUInt16(768, acFrequency); }

    uint16_t getAcFrequencyMin() { return getUInt16(769); }
    void setAcFrequencyMin(uint16_t acFrequencyMin) { setUInt16(769, acFrequencyMin); }

    uint16_t getAcFrequencyMax() { return getUInt16(770); }
    void setAcFrequencyMax(uint16_t acFrequencyMax) { setUInt16(770, acFrequencyMax); }

    uint16_t getNeutralCurrent() { return getUInt16(771); }
    void setNeutralCurrent(uint16_t neutralCurrent) { setUInt16(771, neutralCurrent); }

    int32_t getTotalActivePower() { return getInt32(772); }
    void setTotalActivePower(int32_t totalActivePower) { setInt32(772, totalActivePower); }

    int32_t getTotalReactivePower() { return getInt32(773); }
    void setTotalReactivePower(int32_t totalReactivePower) { setInt32(773, totalReactivePower); }

    uint32_t getTotalApparentPower() { return getUInt32(774); }
    void setTotalApparentPower(uint32_t totalApparentPower) { setUInt32(774, totalApparentPower); }

    int16_t getMeas1stHarmonicCurrent() { return getInt16(775); }
    void setMeas1stHarmonicCurrent(int16_t meas1stHarmonicCurrent) { setInt16(775, meas1stHarmonicCurrent); }

    int16_t getMeas3rdHarmonicCurrent() { return getInt16(776); }
    void setMeas3rdHarmonicCurrent(int16_t meas3rdHarmonicCurrent) { setInt16(776, meas3rdHarmonicCurrent); }

    int16_t getMeas5thHarmonicCurrent() { return getInt16(777); }
    void setMeas5thHarmonicCurrent(int16_t meas5thHarmonicCurrent) { setInt16(777, meas5thHarmonicCurrent); }

    int16_t getMeas7thHarmonicCurrent() { return getInt16(778); }
    void setMeas7thHarmonicCurrent(int16_t meas7thHarmonicCurrent) { setInt16(778, meas7thHarmonicCurrent); }

    int16_t getMeas9thHarmonicCurrent() { return getInt16(779); }
    void setMeas9thHarmonicCurrent(int16_t meas9thHarmonicCurrent) { setInt16(779, meas9thHarmonicCurrent); }

    int16_t getMeas11thHarmonicCurrent() { return getInt16(780); }
    void setMeas11thHarmonicCurrent(int16_t meas11thHarmonicCurrent) { setInt16(780, meas11thHarmonicCurrent); }

    int16_t getMeasPhase1stHarmonicCurrent() { return getInt16(781); }
    void setMeasPhase1stHarmonicCurrent(int16_t measPhase1stHarmonicCurrent) { setInt16(781, measPhase1stHarmonicCurrent); }

    int16_t getMeasPhase3rdHarmonicCurrent() { return getInt16(782); }
    void setMeasPhase3rdHarmonicCurrent(int16_t measPhase3rdHarmonicCurrent) { setInt16(782, measPhase3rdHarmonicCurrent); }

    int16_t getMeasPhase5thHarmonicCurrent() { return getInt16(783); }
    void setMeasPhase5thHarmonicCurrent(int16_t measPhase5thHarmonicCurrent) { setInt16(783, measPhase5thHarmonicCurrent); }

    int16_t getMeasPhase7thHarmonicCurrent() { return getInt16(784); }
    void setMeasPhase7thHarmonicCurrent(int16_t measPhase7thHarmonicCurrent) { setInt16(784, measPhase7thHarmonicCurrent); }

    int16_t getMeasPhase9thHarmonicCurrent() { return getInt16(785); }
    void setMeasPhase9thHarmonicCurrent(int16_t measPhase9thHarmonicCurrent) { setInt16(785, measPhase9thHarmonicCurrent); }

    int16_t getMeasPhase11thHarmonicCurrent() { return getInt16(786); }
    void setMeasPhase11thHarmonicCurrent(int16_t measPhase11thHarmonicCurrent) { setInt16(786, measPhase11thHarmonicCurrent); }

    uint16_t getAcFrequencyMultiplier() { return getUInt16(1024); }
    void setAcFrequencyMultiplier(uint16_t acFrequencyMultiplier) { setUInt16(1024, acFrequencyMultiplier); }

    uint16_t getAcFrequencyDivisor() { return getUInt16(1025); }
    void setAcFrequencyDivisor(uint16_t acFrequencyDivisor) { setUInt16(1025, acFrequencyDivisor); }

    uint32_t getPowerMultiplier() { return getUInt32(1026); }
    void setPowerMultiplier(uint32_t powerMultiplier) { setUInt32(1026, powerMultiplier); }

    uint32_t getPowerDivisor() { return getUInt32(1027); }
    void setPowerDivisor(uint32_t powerDivisor) { setUInt32(1027, powerDivisor); }

    int8_t getHarmonicCurrentMultiplier() { return getInt8(1028); }
    void setHarmonicCurrentMultiplier(int8_t harmonicCurrentMultiplier) { setInt8(1028, harmonicCurrentMultiplier); }

    int8_t getPhaseHarmonicCurrentMultiplier() { return getInt8(1029); }
    void setPhaseHarmonicCurrentMultiplier(int8_t phaseHarmonicCurrentMultiplier) { setInt8(1029, phaseHarmonicCurrentMultiplier); }

    int16_t getInstantaneousVoltage() { return getInt16(1280); }
    void setInstantaneousVoltage(int16_t instantaneousVoltage) { setInt16(1280, instantaneousVoltage); }

    uint16_t getInstantaneousLineCurrent() { return getUInt16(1281); }
    void setInstantaneousLineCurrent(uint16_t instantaneousLineCurrent) { setUInt16(1281, instantaneousLineCurrent); }

    int16_t getInstantaneousActiveCurrent() { return getInt16(1282); }
    void setInstantaneousActiveCurrent(int16_t instantaneousActiveCurrent) { setInt16(1282, instantaneousActiveCurrent); }

    int16_t getInstantaneousReactiveCurrent() { return getInt16(1283); }
    void setInstantaneousReactiveCurrent(int16_t instantaneousReactiveCurrent) { setInt16(1283, instantaneousReactiveCurrent); }

    int16_t getInstantaneousPower() { return getInt16(1284); }
    void setInstantaneousPower(int16_t instantaneousPower) { setInt16(1284, instantaneousPower); }

    uint16_t getRmsVoltage() { return getUInt16(1285); }
    void setRmsVoltage(uint16_t rmsVoltage) { setUInt16(1285, rmsVoltage); }

    uint16_t getRmsVoltageMin() { return getUInt16(1286); }
    void setRmsVoltageMin(uint16_t rmsVoltageMin) { setUInt16(1286, rmsVoltageMin); }

    uint16_t getRmsVoltageMax() { return getUInt16(1287); }
    void setRmsVoltageMax(uint16_t rmsVoltageMax) { setUInt16(1287, rmsVoltageMax); }

    uint16_t getRmsCurrent() { return getUInt16(1288); }
    void setRmsCurrent(uint16_t rmsCurrent) { setUInt16(1288, rmsCurrent); }

    uint16_t getRmsCurrentMin() { return getUInt16(1289); }
    void setRmsCurrentMin(uint16_t rmsCurrentMin) { setUInt16(1289, rmsCurrentMin); }

    uint16_t getRmsCurrentMax() { return getUInt16(1290); }
    void setRmsCurrentMax(uint16_t rmsCurrentMax) { setUInt16(1290, rmsCurrentMax); }

    int16_t getActivePower() { return getInt16(1291); }
    void setActivePower(int16_t activePower) { setInt16(1291, activePower); }

    int16_t getActivePowerMin() { return getInt16(1292); }
    void setActivePowerMin(int16_t activePowerMin) { setInt16(1292, activePowerMin); }

    int16_t getActivePowerMax() { return getInt16(1293); }
    void setActivePowerMax(int16_t activePowerMax) { setInt16(1293, activePowerMax); }

    int16_t getReactivePower() { return getInt16(1294); }
    void setReactivePower(int16_t reactivePower) { setInt16(1294, reactivePower); }

    uint16_t getApparentPower() { return getUInt16(1295); }
    void setApparentPower(uint16_t apparentPower) { setUInt16(1295, apparentPower); }

    int8_t getPowerFactor() { return getInt8(1296); }
    void setPowerFactor(int8_t powerFactor) { setInt8(1296, powerFactor); }

    uint16_t getAverageRmsVoltageMeasPeriod() { return getUInt16(1297); }
    void setAverageRmsVoltageMeasPeriod(uint16_t averageRmsVoltageMeasPeriod) { setUInt16(1297, averageRmsVoltageMeasPeriod); }

    uint16_t getAverageRmsOverVoltageCounter() { return getUInt16(1298); }
    void setAverageRmsOverVoltageCounter(uint16_t averageRmsOverVoltageCounter) { setUInt16(1298, averageRmsOverVoltageCounter); }

    uint16_t getAverageRmsUnderVoltageCounter() { return getUInt16(1299); }
    void setAverageRmsUnderVoltageCounter(uint16_t averageRmsUnderVoltageCounter) { setUInt16(1299, averageRmsUnderVoltageCounter); }

    uint16_t getRmsExtremeOverVoltagePeriod() { return getUInt16(1300); }
    void setRmsExtremeOverVoltagePeriod(uint16_t rmsExtremeOverVoltagePeriod) { setUInt16(1300, rmsExtremeOverVoltagePeriod); }

    uint16_t getRmsExtremeUnderVoltagePeriod() { return getUInt16(1301); }
    void setRmsExtremeUnderVoltagePeriod(uint16_t rmsExtremeUnderVoltagePeriod) { setUInt16(1301, rmsExtremeUnderVoltagePeriod); }

    uint16_t getRmsVoltageSagPeriod() { return getUInt16(1302); }
    void setRmsVoltageSagPeriod(uint16_t rmsVoltageSagPeriod) { setUInt16(1302, rmsVoltageSagPeriod); }

    uint16_t getRmsVoltageSwellPeriod() { return getUInt16(1303); }
    void setRmsVoltageSwellPeriod(uint16_t rmsVoltageSwellPeriod) { setUInt16(1303, rmsVoltageSwellPeriod); }

    uint16_t getAcVoltageMultiplier() { return getUInt16(1536); }
    void setAcVoltageMultiplier(uint16_t acVoltageMultiplier) { setUInt16(1536, acVoltageMultiplier); }

    uint16_t getAcVoltageDivisor() { return getUInt16(1537); }
    void setAcVoltageDivisor(uint16_t acVoltageDivisor) { setUInt16(1537, acVoltageDivisor); }

    uint16_t getAcCurrentMultiplier() { return getUInt16(1538); }
    void setAcCurrentMultiplier(uint16_t acCurrentMultiplier) { setUInt16(1538, acCurrentMultiplier); }

    uint16_t getAcCurrentDivisor() { return getUInt16(1539); }
    void setAcCurrentDivisor(uint16_t acCurrentDivisor) { setUInt16(1539, acCurrentDivisor); }

    uint16_t getAcPowerMultiplier() { return getUInt16(1540); }
    void setAcPowerMultiplier(uint16_t acPowerMultiplier) { setUInt16(1540, acPowerMultiplier); }

    uint16_t getAcPowerDivisor() { return getUInt16(1541); }
    void setAcPowerDivisor(uint16_t acPowerDivisor) { setUInt16(1541, acPowerDivisor); }

    uint8_t getDcOverloadAlarmsMask() { return getMap8(1792); }
    void setDcOverloadAlarmsMask(uint8_t dcOverloadAlarmsMask) { setMap8(1792, dcOverloadAlarmsMask); }

    int16_t getDcVoltageOverload() { return getInt16(1793); }
    void setDcVoltageOverload(int16_t dcVoltageOverload) { setInt16(1793, dcVoltageOverload); }

    int16_t getDcCurrentOverload() { return getInt16(1794); }
    void setDcCurrentOverload(int16_t dcCurrentOverload) { setInt16(1794, dcCurrentOverload); }

    uint16_t getAcAlarmsMask() { return getMap16(2048); }
    void setAcAlarmsMask(uint16_t acAlarmsMask) { setMap16(2048, acAlarmsMask); }

    int16_t getAcVoltageOverload() { return getInt16(2049); }
    void setAcVoltageOverload(int16_t acVoltageOverload) { setInt16(2049, acVoltageOverload); }

    int16_t getAcCurrentOverload() { return getInt16(2050); }
    void setAcCurrentOverload(int16_t acCurrentOverload) { setInt16(2050, acCurrentOverload); }

    int16_t getAcActivePowerOverload() { return getInt16(2051); }
    void setAcActivePowerOverload(int16_t acActivePowerOverload) { setInt16(2051, acActivePowerOverload); }

    int16_t getAcReactivePowerOverload() { return getInt16(2052); }
    void setAcReactivePowerOverload(int16_t acReactivePowerOverload) { setInt16(2052, acReactivePowerOverload); }

    int16_t getAverageRmsOverVoltage() { return getInt16(2053); }
    void setAverageRmsOverVoltage(int16_t averageRmsOverVoltage) { setInt16(2053, averageRmsOverVoltage); }

    int16_t getAverageRmsUnderVoltage() { return getInt16(2054); }
    void setAverageRmsUnderVoltage(int16_t averageRmsUnderVoltage) { setInt16(2054, averageRmsUnderVoltage); }

    int16_t getRmsExtremeOverVoltage() { return getInt16(2055); }
    void setRmsExtremeOverVoltage(int16_t rmsExtremeOverVoltage) { setInt16(2055, rmsExtremeOverVoltage); }

    int16_t getRmsExtremeUnderVoltage() { return getInt16(2056); }
    void setRmsExtremeUnderVoltage(int16_t rmsExtremeUnderVoltage) { setInt16(2056, rmsExtremeUnderVoltage); }

    int16_t getRmsVoltageSag() { return getInt16(2057); }
    void setRmsVoltageSag(int16_t rmsVoltageSag) { setInt16(2057, rmsVoltageSag); }

    int16_t getRmsVoltageSwell() { return getInt16(2058); }
    void setRmsVoltageSwell(int16_t rmsVoltageSwell) { setInt16(2058, rmsVoltageSwell); }

    uint16_t getLineCurrentPhB() { return getUInt16(2305); }
    void setLineCurrentPhB(uint16_t lineCurrentPhB) { setUInt16(2305, lineCurrentPhB); }

    int16_t getActiveCurrentPhB() { return getInt16(2306); }
    void setActiveCurrentPhB(int16_t activeCurrentPhB) { setInt16(2306, activeCurrentPhB); }

    int16_t getReactiveCurrentPhB() { return getInt16(2307); }
    void setReactiveCurrentPhB(int16_t reactiveCurrentPhB) { setInt16(2307, reactiveCurrentPhB); }

    uint16_t getRmsVoltagePhB() { return getUInt16(2309); }
    void setRmsVoltagePhB(uint16_t rmsVoltagePhB) { setUInt16(2309, rmsVoltagePhB); }

    uint16_t getRmsVoltageMinPhB() { return getUInt16(2310); }
    void setRmsVoltageMinPhB(uint16_t rmsVoltageMinPhB) { setUInt16(2310, rmsVoltageMinPhB); }

    uint16_t getRmsVoltageMaxPhB() { return getUInt16(2311); }
    void setRmsVoltageMaxPhB(uint16_t rmsVoltageMaxPhB) { setUInt16(2311, rmsVoltageMaxPhB); }

    uint16_t getRmsCurrentPhB() { return getUInt16(2312); }
    void setRmsCurrentPhB(uint16_t rmsCurrentPhB) { setUInt16(2312, rmsCurrentPhB); }

    uint16_t getRmsCurrentMinPhB() { return getUInt16(2313); }
    void setRmsCurrentMinPhB(uint16_t rmsCurrentMinPhB) { setUInt16(2313, rmsCurrentMinPhB); }

    uint16_t getRmsCurrentMaxPhB() { return getUInt16(2314); }
    void setRmsCurrentMaxPhB(uint16_t rmsCurrentMaxPhB) { setUInt16(2314, rmsCurrentMaxPhB); }

    int16_t getActivePowerPhB() { return getInt16(2315); }
    void setActivePowerPhB(int16_t activePowerPhB) { setInt16(2315, activePowerPhB); }

    int16_t getActivePowerMinPhB() { return getInt16(2316); }
    void setActivePowerMinPhB(int16_t activePowerMinPhB) { setInt16(2316, activePowerMinPhB); }

    int16_t getActivePowerMaxPhB() { return getInt16(2317); }
    void setActivePowerMaxPhB(int16_t activePowerMaxPhB) { setInt16(2317, activePowerMaxPhB); }

    int16_t getReactivePowerPhB() { return getInt16(2318); }
    void setReactivePowerPhB(int16_t reactivePowerPhB) { setInt16(2318, reactivePowerPhB); }

    uint16_t getApparentPowerPhB() { return getUInt16(2319); }
    void setApparentPowerPhB(uint16_t apparentPowerPhB) { setUInt16(2319, apparentPowerPhB); }

    int8_t getPowerFactorPhB() { return getInt8(2320); }
    void setPowerFactorPhB(int8_t powerFactorPhB) { setInt8(2320, powerFactorPhB); }

    uint16_t getAverageRmsVoltageMeasurePeriodPhB() { return getUInt16(2321); }
    void setAverageRmsVoltageMeasurePeriodPhB(uint16_t averageRmsVoltageMeasurePeriodPhB) { setUInt16(2321, averageRmsVoltageMeasurePeriodPhB); }

    uint16_t getAverageRmsOverVoltageCounterPhB() { return getUInt16(2322); }
    void setAverageRmsOverVoltageCounterPhB(uint16_t averageRmsOverVoltageCounterPhB) { setUInt16(2322, averageRmsOverVoltageCounterPhB); }

    uint16_t getAverageUnderVoltageCounterPhB() { return getUInt16(2323); }
    void setAverageUnderVoltageCounterPhB(uint16_t averageUnderVoltageCounterPhB) { setUInt16(2323, averageUnderVoltageCounterPhB); }

    uint16_t getRmsExtremeOverVoltagePeriodPhB() { return getUInt16(2324); }
    void setRmsExtremeOverVoltagePeriodPhB(uint16_t rmsExtremeOverVoltagePeriodPhB) { setUInt16(2324, rmsExtremeOverVoltagePeriodPhB); }

    uint16_t getRmsExtremeUnderVoltagePeriodPhB() { return getUInt16(2325); }
    void setRmsExtremeUnderVoltagePeriodPhB(uint16_t rmsExtremeUnderVoltagePeriodPhB) { setUInt16(2325, rmsExtremeUnderVoltagePeriodPhB); }

    uint16_t getRmsVoltageSagPeriodPhB() { return getUInt16(2326); }
    void setRmsVoltageSagPeriodPhB(uint16_t rmsVoltageSagPeriodPhB) { setUInt16(2326, rmsVoltageSagPeriodPhB); }

    uint16_t getRmsVoltageSwellPeriodPhB() { return getUInt16(2327); }
    void setRmsVoltageSwellPeriodPhB(uint16_t rmsVoltageSwellPeriodPhB) { setUInt16(2327, rmsVoltageSwellPeriodPhB); }

    uint16_t getLineCurrentPhC() { return getUInt16(2561); }
    void setLineCurrentPhC(uint16_t lineCurrentPhC) { setUInt16(2561, lineCurrentPhC); }

    int16_t getActiveCurrentPhC() { return getInt16(2562); }
    void setActiveCurrentPhC(int16_t activeCurrentPhC) { setInt16(2562, activeCurrentPhC); }

    int16_t getReactiveCurrentPhC() { return getInt16(2563); }
    void setReactiveCurrentPhC(int16_t reactiveCurrentPhC) { setInt16(2563, reactiveCurrentPhC); }

    uint16_t getRmsVoltagePhC() { return getUInt16(2565); }
    void setRmsVoltagePhC(uint16_t rmsVoltagePhC) { setUInt16(2565, rmsVoltagePhC); }

    uint16_t getRmsVoltageMinPhC() { return getUInt16(2566); }
    void setRmsVoltageMinPhC(uint16_t rmsVoltageMinPhC) { setUInt16(2566, rmsVoltageMinPhC); }

    uint16_t getRmsVoltageMaxPhC() { return getUInt16(2567); }
    void setRmsVoltageMaxPhC(uint16_t rmsVoltageMaxPhC) { setUInt16(2567, rmsVoltageMaxPhC); }

    uint16_t getRmsCurrentPhC() { return getUInt16(2568); }
    void setRmsCurrentPhC(uint16_t rmsCurrentPhC) { setUInt16(2568, rmsCurrentPhC); }

    uint16_t getRmsCurrentMinPhC() { return getUInt16(2569); }
    void setRmsCurrentMinPhC(uint16_t rmsCurrentMinPhC) { setUInt16(2569, rmsCurrentMinPhC); }

    uint16_t getRmsCurrentMaxPhC() { return getUInt16(2570); }
    void setRmsCurrentMaxPhC(uint16_t rmsCurrentMaxPhC) { setUInt16(2570, rmsCurrentMaxPhC); }

    int16_t getActivePowerPhC() { return getInt16(2571); }
    void setActivePowerPhC(int16_t activePowerPhC) { setInt16(2571, activePowerPhC); }

    int16_t getActivePowerMinPhC() { return getInt16(2572); }
    void setActivePowerMinPhC(int16_t activePowerMinPhC) { setInt16(2572, activePowerMinPhC); }

    int16_t getActivePowerMaxPhC() { return getInt16(2573); }
    void setActivePowerMaxPhC(int16_t activePowerMaxPhC) { setInt16(2573, activePowerMaxPhC); }

    int16_t getReactivePowerPhC() { return getInt16(2574); }
    void setReactivePowerPhC(int16_t reactivePowerPhC) { setInt16(2574, reactivePowerPhC); }

    uint16_t getApparentPowerPhC() { return getUInt16(2575); }
    void setApparentPowerPhC(uint16_t apparentPowerPhC) { setUInt16(2575, apparentPowerPhC); }

    int8_t getPowerFactorPhC() { return getInt8(2576); }
    void setPowerFactorPhC(int8_t powerFactorPhC) { setInt8(2576, powerFactorPhC); }

    uint16_t getAverageRmsVoltageMeasPeriodPhC() { return getUInt16(2577); }
    void setAverageRmsVoltageMeasPeriodPhC(uint16_t averageRmsVoltageMeasPeriodPhC) { setUInt16(2577, averageRmsVoltageMeasPeriodPhC); }

    uint16_t getAverageRmsOverVoltageCounterPhC() { return getUInt16(2578); }
    void setAverageRmsOverVoltageCounterPhC(uint16_t averageRmsOverVoltageCounterPhC) { setUInt16(2578, averageRmsOverVoltageCounterPhC); }

    uint16_t getAverageUnderVoltageCounterPhC() { return getUInt16(2579); }
    void setAverageUnderVoltageCounterPhC(uint16_t averageUnderVoltageCounterPhC) { setUInt16(2579, averageUnderVoltageCounterPhC); }

    uint16_t getRmsExtremeOverVoltagePeriodPhC() { return getUInt16(2580); }
    void setRmsExtremeOverVoltagePeriodPhC(uint16_t rmsExtremeOverVoltagePeriodPhC) { setUInt16(2580, rmsExtremeOverVoltagePeriodPhC); }

    uint16_t getRmsExtremeUnderVoltagePeriodPhC() { return getUInt16(2581); }
    void setRmsExtremeUnderVoltagePeriodPhC(uint16_t rmsExtremeUnderVoltagePeriodPhC) { setUInt16(2581, rmsExtremeUnderVoltagePeriodPhC); }

    uint16_t getRmsVoltageSagPeriodPhC() { return getUInt16(2582); }
    void setRmsVoltageSagPeriodPhC(uint16_t rmsVoltageSagPeriodPhC) { setUInt16(2582, rmsVoltageSagPeriodPhC); }

    uint16_t getRmsVoltageSwellPeriodPhC() { return getUInt16(2583); }
    void setRmsVoltageSwellPeriodPhC(uint16_t rmsVoltageSwellPeriodPhC) { setUInt16(2583, rmsVoltageSwellPeriodPhC); }

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

    uint16_t getNumberOfResets() { return getUInt16(0); }
    void setNumberOfResets(uint16_t numberOfResets) { setUInt16(0, numberOfResets); }

    uint16_t getPersistentMemoryWrites() { return getUInt16(1); }
    void setPersistentMemoryWrites(uint16_t persistentMemoryWrites) { setUInt16(1, persistentMemoryWrites); }

    uint32_t getMacRxBcast() { return getUInt32(256); }
    void setMacRxBcast(uint32_t macRxBcast) { setUInt32(256, macRxBcast); }

    uint32_t getMacTxBcast() { return getUInt32(257); }
    void setMacTxBcast(uint32_t macTxBcast) { setUInt32(257, macTxBcast); }

    uint32_t getMacRxUcast() { return getUInt32(258); }
    void setMacRxUcast(uint32_t macRxUcast) { setUInt32(258, macRxUcast); }

    uint32_t getMacTxUcast() { return getUInt32(259); }
    void setMacTxUcast(uint32_t macTxUcast) { setUInt32(259, macTxUcast); }

    uint16_t getMacTxUcastRetry() { return getUInt16(260); }
    void setMacTxUcastRetry(uint16_t macTxUcastRetry) { setUInt16(260, macTxUcastRetry); }

    uint16_t getMacTxUcastFail() { return getUInt16(261); }
    void setMacTxUcastFail(uint16_t macTxUcastFail) { setUInt16(261, macTxUcastFail); }

    uint16_t getAPSRxBcast() { return getUInt16(262); }
    void setAPSRxBcast(uint16_t aPSRxBcast) { setUInt16(262, aPSRxBcast); }

    uint16_t getAPSTxBcast() { return getUInt16(263); }
    void setAPSTxBcast(uint16_t aPSTxBcast) { setUInt16(263, aPSTxBcast); }

    uint16_t getAPSRxUcast() { return getUInt16(264); }
    void setAPSRxUcast(uint16_t aPSRxUcast) { setUInt16(264, aPSRxUcast); }

    uint16_t getAPSTxUcastSuccess() { return getUInt16(265); }
    void setAPSTxUcastSuccess(uint16_t aPSTxUcastSuccess) { setUInt16(265, aPSTxUcastSuccess); }

    uint16_t getAPSTxUcastRetry() { return getUInt16(266); }
    void setAPSTxUcastRetry(uint16_t aPSTxUcastRetry) { setUInt16(266, aPSTxUcastRetry); }

    uint16_t getAPSTxUcastFail() { return getUInt16(267); }
    void setAPSTxUcastFail(uint16_t aPSTxUcastFail) { setUInt16(267, aPSTxUcastFail); }

    uint16_t getRouteDiscInitiated() { return getUInt16(268); }
    void setRouteDiscInitiated(uint16_t routeDiscInitiated) { setUInt16(268, routeDiscInitiated); }

    uint16_t getNeighborAdded() { return getUInt16(269); }
    void setNeighborAdded(uint16_t neighborAdded) { setUInt16(269, neighborAdded); }

    uint16_t getNeighborRemoved() { return getUInt16(270); }
    void setNeighborRemoved(uint16_t neighborRemoved) { setUInt16(270, neighborRemoved); }

    uint16_t getNeighborStale() { return getUInt16(271); }
    void setNeighborStale(uint16_t neighborStale) { setUInt16(271, neighborStale); }

    uint16_t getJoinIndication() { return getUInt16(272); }
    void setJoinIndication(uint16_t joinIndication) { setUInt16(272, joinIndication); }

    uint16_t getChildMoved() { return getUInt16(273); }
    void setChildMoved(uint16_t childMoved) { setUInt16(273, childMoved); }

    uint16_t getNwkFcFailure() { return getUInt16(274); }
    void setNwkFcFailure(uint16_t nwkFcFailure) { setUInt16(274, nwkFcFailure); }

    uint16_t getApsFcFailure() { return getUInt16(275); }
    void setApsFcFailure(uint16_t apsFcFailure) { setUInt16(275, apsFcFailure); }

    uint16_t getApsUnauthorizedKey() { return getUInt16(276); }
    void setApsUnauthorizedKey(uint16_t apsUnauthorizedKey) { setUInt16(276, apsUnauthorizedKey); }

    uint16_t getNwkDecryptFailures() { return getUInt16(277); }
    void setNwkDecryptFailures(uint16_t nwkDecryptFailures) { setUInt16(277, nwkDecryptFailures); }

    uint16_t getApsDecryptFailures() { return getUInt16(278); }
    void setApsDecryptFailures(uint16_t apsDecryptFailures) { setUInt16(278, apsDecryptFailures); }

    uint16_t getPacketBufferAllocateFailures() { return getUInt16(279); }
    void setPacketBufferAllocateFailures(uint16_t packetBufferAllocateFailures) { setUInt16(279, packetBufferAllocateFailures); }

    uint16_t getRelayedUcast() { return getUInt16(280); }
    void setRelayedUcast(uint16_t relayedUcast) { setUInt16(280, relayedUcast); }

    uint16_t getPhyToMacQueueLimitReached() { return getUInt16(281); }
    void setPhyToMacQueueLimitReached(uint16_t phyToMacQueueLimitReached) { setUInt16(281, phyToMacQueueLimitReached); }

    uint16_t getPacketValidateDropCount() { return getUInt16(282); }
    void setPacketValidateDropCount(uint16_t packetValidateDropCount) { setUInt16(282, packetValidateDropCount); }

    uint16_t getAverageMacRetryPerApsMessageSent() { return getUInt16(283); }
    void setAverageMacRetryPerApsMessageSent(uint16_t averageMacRetryPerApsMessageSent) { setUInt16(283, averageMacRetryPerApsMessageSent); }

    uint8_t getLastMessageLqi() { return getUInt8(284); }
    void setLastMessageLqi(uint8_t lastMessageLqi) { setUInt8(284, lastMessageLqi); }

    int8_t getLastMessageRssi() { return getInt8(285); }
    void setLastMessageRssi(int8_t lastMessageRssi) { setInt8(285, lastMessageRssi); }
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

    String getDeviceInfo() { return getString(32); }
    void setDeviceInfo(const String& deviceInfo) { setString(32, deviceInfo); }
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
