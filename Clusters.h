#pragma once

class GenBasicCluster: public Cluster {
public:
    GenBasicCluster() : Cluster(0) {
    }

    uint8_t getZclVersion() {
        return getUInt8(0);
    }

    void setZclVersion(uint8_t value) {
        setUInt8(0, value);
    }

    uint8_t getAppVersion() {
        return getUInt8(1);
    }

    void setAppVersion(uint8_t value) {
        setUInt8(1, value);
    }

    uint8_t getStackVersion() {
        return getUInt8(2);
    }

    void setStackVersion(uint8_t value) {
        setUInt8(2, value);
    }

    uint8_t getHwVersion() {
        return getUInt8(3);
    }

    void setHwVersion(uint8_t value) {
        setUInt8(3, value);
    }

    String getManufacturerName() {
        return getString(4);
    }

    void setManufacturerName(const String& value) {
        setString(4, value);
    }

    String getModelId() {
        return getString(5);
    }

    void setModelId(const String& value) {
        setString(5, value);
    }

    String getDateCode() {
        return getString(6);
    }

    void setDateCode(const String& value) {
        setString(6, value);
    }

    uint8_t getPowerSource() {
        return getEnum8(7);
    }

    void setPowerSource(uint8_t value) {
        setEnum8(7, value);
    }

    uint8_t getAppProfileVersion() {
        return getEnum8(8);
    }

    void setAppProfileVersion(uint8_t value) {
        setEnum8(8, value);
    }

    String getSwBuildId() {
        return getString(16384);
    }

    void setSwBuildId(const String& value) {
        setString(16384, value);
    }

    String getLocationDesc() {
        return getString(16);
    }

    void setLocationDesc(const String& value) {
        setString(16, value);
    }

    uint8_t getPhysicalEnv() {
        return getEnum8(17);
    }

    void setPhysicalEnv(uint8_t value) {
        setEnum8(17, value);
    }

    bool getDeviceEnabled() {
        return getBool(18);
    }

    void setDeviceEnabled(bool value) {
        setBool(18, value);
    }

    uint8_t getAlarmMask() {
        return getMap8(19);
    }

    void setAlarmMask(uint8_t value) {
        setMap8(19, value);
    }

    uint8_t getDisableLocalConfig() {
        return getMap8(20);
    }

    void setDisableLocalConfig(uint8_t value) {
        setMap8(20, value);
    }

    virtual Status resetFactDefaultCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto status_ = resetFactDefaultCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class GenPowerCfgCluster: public Cluster {
public:
    GenPowerCfgCluster() : Cluster(1) {
    }

    uint16_t getMainsVoltage() {
        return getUInt16(0);
    }

    void setMainsVoltage(uint16_t value) {
        setUInt16(0, value);
    }

    uint8_t getMainsFrequency() {
        return getUInt8(1);
    }

    void setMainsFrequency(uint8_t value) {
        setUInt8(1, value);
    }

    uint8_t getMainsAlarmMask() {
        return getMap8(16);
    }

    void setMainsAlarmMask(uint8_t value) {
        setMap8(16, value);
    }

    uint16_t getMainsVoltMinThres() {
        return getUInt16(17);
    }

    void setMainsVoltMinThres(uint16_t value) {
        setUInt16(17, value);
    }

    uint16_t getMainsVoltMaxThres() {
        return getUInt16(18);
    }

    void setMainsVoltMaxThres(uint16_t value) {
        setUInt16(18, value);
    }

    uint16_t getMainsVoltageDwellTripPoint() {
        return getUInt16(19);
    }

    void setMainsVoltageDwellTripPoint(uint16_t value) {
        setUInt16(19, value);
    }

    uint8_t getBatteryVoltage() {
        return getUInt8(32);
    }

    void setBatteryVoltage(uint8_t value) {
        setUInt8(32, value);
    }

    uint8_t getBatteryPercentageRemaining() {
        return getUInt8(33);
    }

    void setBatteryPercentageRemaining(uint8_t value) {
        setUInt8(33, value);
    }

    String getBatteryManufacturer() {
        return getString(48);
    }

    void setBatteryManufacturer(const String& value) {
        setString(48, value);
    }

    uint8_t getBatterySize() {
        return getEnum8(49);
    }

    void setBatterySize(uint8_t value) {
        setEnum8(49, value);
    }

    uint16_t getBatteryAHrRating() {
        return getUInt16(50);
    }

    void setBatteryAHrRating(uint16_t value) {
        setUInt16(50, value);
    }

    uint8_t getBatteryQuantity() {
        return getUInt8(51);
    }

    void setBatteryQuantity(uint8_t value) {
        setUInt8(51, value);
    }

    uint8_t getBatteryRatedVoltage() {
        return getUInt8(52);
    }

    void setBatteryRatedVoltage(uint8_t value) {
        setUInt8(52, value);
    }

    uint8_t getBatteryAlarmMask() {
        return getMap8(53);
    }

    void setBatteryAlarmMask(uint8_t value) {
        setMap8(53, value);
    }

    uint8_t getBatteryVoltMinThres() {
        return getUInt8(54);
    }

    void setBatteryVoltMinThres(uint8_t value) {
        setUInt8(54, value);
    }

    uint8_t getBatteryVoltThres1() {
        return getUInt8(55);
    }

    void setBatteryVoltThres1(uint8_t value) {
        setUInt8(55, value);
    }

    uint8_t getBatteryVoltThres2() {
        return getUInt8(56);
    }

    void setBatteryVoltThres2(uint8_t value) {
        setUInt8(56, value);
    }

    uint8_t getBatteryVoltThres3() {
        return getUInt8(57);
    }

    void setBatteryVoltThres3(uint8_t value) {
        setUInt8(57, value);
    }

    uint8_t getBatteryPercentMinThres() {
        return getUInt8(58);
    }

    void setBatteryPercentMinThres(uint8_t value) {
        setUInt8(58, value);
    }

    uint8_t getBatteryPercentThres1() {
        return getUInt8(59);
    }

    void setBatteryPercentThres1(uint8_t value) {
        setUInt8(59, value);
    }

    uint8_t getBatteryPercentThres2() {
        return getUInt8(60);
    }

    void setBatteryPercentThres2(uint8_t value) {
        setUInt8(60, value);
    }

    uint8_t getBatteryPercentThres3() {
        return getUInt8(61);
    }

    void setBatteryPercentThres3(uint8_t value) {
        setUInt8(61, value);
    }

    uint32_t getBatteryAlarmState() {
        return getMap32(62);
    }

    void setBatteryAlarmState(uint32_t value) {
        setMap32(62, value);
    }
};

class GenDeviceTempCfgCluster: public Cluster {
public:
    GenDeviceTempCfgCluster() : Cluster(2) {
    }

    int16_t getCurrentTemperature() {
        return getInt16(0);
    }

    void setCurrentTemperature(int16_t value) {
        setInt16(0, value);
    }

    int16_t getMinTempExperienced() {
        return getInt16(1);
    }

    void setMinTempExperienced(int16_t value) {
        setInt16(1, value);
    }

    int16_t getMaxTempExperienced() {
        return getInt16(2);
    }

    void setMaxTempExperienced(int16_t value) {
        setInt16(2, value);
    }

    uint16_t getOverTempTotalDwell() {
        return getUInt16(3);
    }

    void setOverTempTotalDwell(uint16_t value) {
        setUInt16(3, value);
    }

    uint8_t getDevTempAlarmMask() {
        return getMap8(16);
    }

    void setDevTempAlarmMask(uint8_t value) {
        setMap8(16, value);
    }

    int16_t getLowTempThres() {
        return getInt16(17);
    }

    void setLowTempThres(int16_t value) {
        setInt16(17, value);
    }

    int16_t getHighTempThres() {
        return getInt16(18);
    }

    void setHighTempThres(int16_t value) {
        setInt16(18, value);
    }

    uint32_t getLowTempDwellTripPoint() {
        return getUInt24(19);
    }

    void setLowTempDwellTripPoint(uint32_t value) {
        setUInt24(19, value);
    }

    uint32_t getHighTempDwellTripPoint() {
        return getUInt24(20);
    }

    void setHighTempDwellTripPoint(uint32_t value) {
        setUInt24(20, value);
    }
};

class GenIdentifyCluster: public Cluster {
public:
    GenIdentifyCluster() : Cluster(3) {
    }

    uint16_t getIdentifyTime() {
        return getUInt16(0);
    }

    void setIdentifyTime(uint16_t value) {
        setUInt16(0, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto identifytime = request.readUInt16Le();
                auto status_ = identifyCommand(identifytime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto status_ = identifyQueryCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto action = request.readUInt8();
                auto status_ = ezmodeInvokeCommand(action);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto action = request.readUInt8();
                auto commstatemask = request.readUInt8();
                auto status_ = updateCommissionStateCommand(action, commstatemask);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 64: {
                auto effectid = request.readUInt8();
                auto effectvariant = request.readUInt8();
                auto status_ = triggerEffectCommand(effectid, effectvariant);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class GenGroupsCluster: public Cluster {
public:
    GenGroupsCluster() : Cluster(4) {
    }

    uint8_t getNameSupport() {
        return getMap8(0);
    }

    void setNameSupport(uint8_t value) {
        setMap8(0, value);
    }

    class AddCommandResponse {
        uint8_t _status{};
        uint16_t _groupid{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

        uint16_t getGroupid() { return _groupid; }
        void setGroupid(uint16_t value) { _groupid = value; }

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
        void setStatus(uint8_t value) { _status = value; }

        uint16_t getGroupid() { return _groupid; }
        void setGroupid(uint16_t value) { _groupid = value; }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto groupid = request.readUInt16Le();
                auto groupname = request.readString();
                AddCommandResponse response_;
                auto status_ = addCommand(groupid, groupname, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                    response.writeUInt16Le(response_.getGroupid());
                }
                return;
            }
            case 1: {
                auto groupid = request.readUInt16Le();
                auto status_ = viewCommand(groupid);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto groupid = request.readUInt16Le();
                RemoveCommandResponse response_;
                auto status_ = removeCommand(groupid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                    response.writeUInt16Le(response_.getGroupid());
                }
                return;
            }
            case 4: {
                auto status_ = removeAllCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 5: {
                auto groupid = request.readUInt16Le();
                auto groupname = request.readString();
                auto status_ = addIfIdentifyingCommand(groupid, groupname);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class GenScenesCluster: public Cluster {
public:
    GenScenesCluster() : Cluster(5) {
    }

    uint8_t getCount() {
        return getUInt8(0);
    }

    void setCount(uint8_t value) {
        setUInt8(0, value);
    }

    uint8_t getCurrentScene() {
        return getUInt8(1);
    }

    void setCurrentScene(uint8_t value) {
        setUInt8(1, value);
    }

    uint16_t getCurrentGroup() {
        return getUInt16(2);
    }

    void setCurrentGroup(uint16_t value) {
        setUInt16(2, value);
    }

    bool getSceneValid() {
        return getBool(3);
    }

    void setSceneValid(bool value) {
        setBool(3, value);
    }

    uint8_t getNameSupport() {
        return getMap8(4);
    }

    void setNameSupport(uint8_t value) {
        setMap8(4, value);
    }

    uint64_t getLastCfgBy() {
        return getEUI64(5);
    }

    void setLastCfgBy(uint64_t value) {
        setEUI64(5, value);
    }

    class RemoveCommandResponse {
        uint8_t _status{};
        uint16_t _groupid{};
        uint8_t _sceneid{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

        uint16_t getGroupid() { return _groupid; }
        void setGroupid(uint16_t value) { _groupid = value; }

        uint8_t getSceneid() { return _sceneid; }
        void setSceneid(uint8_t value) { _sceneid = value; }

    };

    virtual Status removeCommand(uint16_t groupid, uint8_t sceneid, RemoveCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class RemoveAllCommandResponse {
        uint8_t _status{};
        uint16_t _groupid{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

        uint16_t getGroupid() { return _groupid; }
        void setGroupid(uint16_t value) { _groupid = value; }

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
        void setStatus(uint8_t value) { _status = value; }

        uint16_t getGroupid() { return _groupid; }
        void setGroupid(uint16_t value) { _groupid = value; }

        uint8_t getSceneid() { return _sceneid; }
        void setSceneid(uint8_t value) { _sceneid = value; }

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
        void setStatus(uint8_t value) { _status = value; }

        uint16_t getGroupidfrom() { return _groupidfrom; }
        void setGroupidfrom(uint16_t value) { _groupidfrom = value; }

        uint8_t getSceneidfrom() { return _sceneidfrom; }
        void setSceneidfrom(uint8_t value) { _sceneidfrom = value; }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 2: {
                auto groupid = request.readUInt16Le();
                auto sceneid = request.readUInt8();
                RemoveCommandResponse response_;
                auto status_ = removeCommand(groupid, sceneid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                    response.writeUInt16Le(response_.getGroupid());
                    response.writeUInt8(response_.getSceneid());
                }
                return;
            }
            case 3: {
                auto groupid = request.readUInt16Le();
                RemoveAllCommandResponse response_;
                auto status_ = removeAllCommand(groupid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                    response.writeUInt16Le(response_.getGroupid());
                }
                return;
            }
            case 4: {
                auto groupid = request.readUInt16Le();
                auto sceneid = request.readUInt8();
                StoreCommandResponse response_;
                auto status_ = storeCommand(groupid, sceneid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                    response.writeUInt16Le(response_.getGroupid());
                    response.writeUInt8(response_.getSceneid());
                }
                return;
            }
            case 5: {
                auto groupid = request.readUInt16Le();
                auto sceneid = request.readUInt8();
                auto status_ = recallCommand(groupid, sceneid);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 66: {
                auto mode = request.readUInt8();
                auto groupidfrom = request.readUInt16Le();
                auto sceneidfrom = request.readUInt8();
                auto groupidto = request.readUInt16Le();
                auto sceneidto = request.readUInt8();
                CopyCommandResponse response_;
                auto status_ = copyCommand(mode, groupidfrom, sceneidfrom, groupidto, sceneidto, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                    response.writeUInt16Le(response_.getGroupidfrom());
                    response.writeUInt8(response_.getSceneidfrom());
                }
                return;
            }
            case 7: {
                auto value = request.readUInt16Le();
                auto value2 = request.readUInt16Le();
                auto status_ = tradfriArrowSingleCommand(value, value2);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 8: {
                auto value = request.readUInt16Le();
                auto status_ = tradfriArrowHoldCommand(value);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 9: {
                auto value = request.readUInt16Le();
                auto status_ = tradfriArrowReleaseCommand(value);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class GenOnOffCluster: public Cluster {
public:
    GenOnOffCluster() : Cluster(6) {
    }

    bool getOnOff() {
        return getBool(0);
    }

    void setOnOff(bool value) {
        setBool(0, value);
    }

    bool getGlobalSceneCtrl() {
        return getBool(16384);
    }

    void setGlobalSceneCtrl(bool value) {
        setBool(16384, value);
    }

    uint16_t getOnTime() {
        return getUInt16(16385);
    }

    void setOnTime(uint16_t value) {
        setUInt16(16385, value);
    }

    uint16_t getOffWaitTime() {
        return getUInt16(16386);
    }

    void setOffWaitTime(uint16_t value) {
        setUInt16(16386, value);
    }

    uint8_t getStartUpOnOff() {
        return getEnum8(16387);
    }

    void setStartUpOnOff(uint8_t value) {
        setEnum8(16387, value);
    }

    uint8_t getMoesStartUpOnOff() {
        return getEnum8(32770);
    }

    void setMoesStartUpOnOff(uint8_t value) {
        setEnum8(32770, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto status_ = offCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto status_ = onCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto status_ = toggleCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 64: {
                auto effectid = request.readUInt8();
                auto effectvariant = request.readUInt8();
                auto status_ = offWithEffectCommand(effectid, effectvariant);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 65: {
                auto status_ = onWithRecallGlobalSceneCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 66: {
                auto ctrlbits = request.readUInt8();
                auto ontime = request.readUInt16Le();
                auto offwaittime = request.readUInt16Le();
                auto status_ = onWithTimedOffCommand(ctrlbits, ontime, offwaittime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class GenOnOffSwitchCfgCluster: public Cluster {
public:
    GenOnOffSwitchCfgCluster() : Cluster(7) {
    }

    uint8_t getSwitchType() {
        return getEnum8(0);
    }

    void setSwitchType(uint8_t value) {
        setEnum8(0, value);
    }

    uint8_t getSwitchActions() {
        return getEnum8(16);
    }

    void setSwitchActions(uint8_t value) {
        setEnum8(16, value);
    }
};

class GenLevelCtrlCluster: public Cluster {
public:
    GenLevelCtrlCluster() : Cluster(8) {
    }

    uint8_t getCurrentLevel() {
        return getUInt8(0);
    }

    void setCurrentLevel(uint8_t value) {
        setUInt8(0, value);
    }

    uint16_t getRemainingTime() {
        return getUInt16(1);
    }

    void setRemainingTime(uint16_t value) {
        setUInt16(1, value);
    }

    uint8_t getMinLevel() {
        return getUInt8(2);
    }

    void setMinLevel(uint8_t value) {
        setUInt8(2, value);
    }

    uint8_t getMaxLevel() {
        return getUInt8(3);
    }

    void setMaxLevel(uint8_t value) {
        setUInt8(3, value);
    }

    uint8_t getOptions() {
        return getMap8(15);
    }

    void setOptions(uint8_t value) {
        setMap8(15, value);
    }

    uint16_t getOnOffTransitionTime() {
        return getUInt16(16);
    }

    void setOnOffTransitionTime(uint16_t value) {
        setUInt16(16, value);
    }

    uint8_t getOnLevel() {
        return getUInt8(17);
    }

    void setOnLevel(uint8_t value) {
        setUInt8(17, value);
    }

    uint16_t getOnTransitionTime() {
        return getUInt16(18);
    }

    void setOnTransitionTime(uint16_t value) {
        setUInt16(18, value);
    }

    uint16_t getOffTransitionTime() {
        return getUInt16(19);
    }

    void setOffTransitionTime(uint16_t value) {
        setUInt16(19, value);
    }

    uint16_t getDefaultMoveRate() {
        return getUInt16(20);
    }

    void setDefaultMoveRate(uint16_t value) {
        setUInt16(20, value);
    }

    uint8_t getStartUpCurrentLevel() {
        return getUInt8(16384);
    }

    void setStartUpCurrentLevel(uint8_t value) {
        setUInt8(16384, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto level = request.readUInt8();
                auto transtime = request.readUInt16Le();
                auto status_ = moveToLevelCommand(level, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto movemode = request.readUInt8();
                auto rate = request.readUInt8();
                auto status_ = moveCommand(movemode, rate);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto stepmode = request.readUInt8();
                auto stepsize = request.readUInt8();
                auto transtime = request.readUInt16Le();
                auto status_ = stepCommand(stepmode, stepsize, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto status_ = stopCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 4: {
                auto level = request.readUInt8();
                auto transtime = request.readUInt16Le();
                auto status_ = moveToLevelWithOnOffCommand(level, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 5: {
                auto movemode = request.readUInt8();
                auto rate = request.readUInt8();
                auto status_ = moveWithOnOffCommand(movemode, rate);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 6: {
                auto stepmode = request.readUInt8();
                auto stepsize = request.readUInt8();
                auto transtime = request.readUInt16Le();
                auto status_ = stepWithOnOffCommand(stepmode, stepsize, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 7: {
                auto status_ = stopWithOnOffCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 240: {
                auto level = request.readUInt16Le();
                auto transtime = request.readUInt16Le();
                auto status_ = moveToLevelTuyaCommand(level, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class GenAlarmsCluster: public Cluster {
public:
    GenAlarmsCluster() : Cluster(9) {
    }

    uint16_t getAlarmCount() {
        return getUInt16(0);
    }

    void setAlarmCount(uint16_t value) {
        setUInt16(0, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto alarmcode = request.readUInt8();
                auto clusterid = request.readUInt16Le();
                auto status_ = resetCommand(alarmcode, clusterid);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto status_ = resetAllCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto status_ = getAlarmCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto status_ = resetLogCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 4: {
                auto status_ = publishEventLogCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class GenTimeCluster: public Cluster {
public:
    GenTimeCluster() : Cluster(10) {
    }

    uint32_t getTime() {
        return getUTC(0);
    }

    void setTime(uint32_t value) {
        setUTC(0, value);
    }

    uint8_t getTimeStatus() {
        return getMap8(1);
    }

    void setTimeStatus(uint8_t value) {
        setMap8(1, value);
    }

    int32_t getTimeZone() {
        return getInt32(2);
    }

    void setTimeZone(int32_t value) {
        setInt32(2, value);
    }

    uint32_t getDstStart() {
        return getUInt32(3);
    }

    void setDstStart(uint32_t value) {
        setUInt32(3, value);
    }

    uint32_t getDstEnd() {
        return getUInt32(4);
    }

    void setDstEnd(uint32_t value) {
        setUInt32(4, value);
    }

    int32_t getDstShift() {
        return getInt32(5);
    }

    void setDstShift(int32_t value) {
        setInt32(5, value);
    }

    uint32_t getStandardTime() {
        return getUInt32(6);
    }

    void setStandardTime(uint32_t value) {
        setUInt32(6, value);
    }

    uint32_t getLocalTime() {
        return getUInt32(7);
    }

    void setLocalTime(uint32_t value) {
        setUInt32(7, value);
    }

    uint32_t getLastSetTime() {
        return getUTC(8);
    }

    void setLastSetTime(uint32_t value) {
        setUTC(8, value);
    }

    uint32_t getValidUntilTime() {
        return getUTC(9);
    }

    void setValidUntilTime(uint32_t value) {
        setUTC(9, value);
    }
};

class GenRssiLocationCluster: public Cluster {
public:
    GenRssiLocationCluster() : Cluster(11) {
    }

    uint8_t getType() {
        return getData8(0);
    }

    void setType(uint8_t value) {
        setData8(0, value);
    }

    uint8_t getMethod() {
        return getEnum8(1);
    }

    void setMethod(uint8_t value) {
        setEnum8(1, value);
    }

    uint16_t getAge() {
        return getUInt16(2);
    }

    void setAge(uint16_t value) {
        setUInt16(2, value);
    }

    uint8_t getQualityMeasure() {
        return getUInt8(3);
    }

    void setQualityMeasure(uint8_t value) {
        setUInt8(3, value);
    }

    uint8_t getNumOfDevices() {
        return getUInt8(4);
    }

    void setNumOfDevices(uint8_t value) {
        setUInt8(4, value);
    }

    int16_t getCoordinate1() {
        return getInt16(16);
    }

    void setCoordinate1(int16_t value) {
        setInt16(16, value);
    }

    int16_t getCoordinate2() {
        return getInt16(17);
    }

    void setCoordinate2(int16_t value) {
        setInt16(17, value);
    }

    int16_t getCoordinate3() {
        return getInt16(18);
    }

    void setCoordinate3(int16_t value) {
        setInt16(18, value);
    }

    int16_t getPower() {
        return getInt16(19);
    }

    void setPower(int16_t value) {
        setInt16(19, value);
    }

    uint16_t getPathLossExponent() {
        return getUInt16(20);
    }

    void setPathLossExponent(uint16_t value) {
        setUInt16(20, value);
    }

    uint16_t getReportingPeriod() {
        return getUInt16(21);
    }

    void setReportingPeriod(uint16_t value) {
        setUInt16(21, value);
    }

    uint16_t getCalcPeriod() {
        return getUInt16(22);
    }

    void setCalcPeriod(uint16_t value) {
        setUInt16(22, value);
    }

    uint16_t getNumRSSIMeasurements() {
        return getUInt16(23);
    }

    void setNumRSSIMeasurements(uint16_t value) {
        setUInt16(23, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto coord1 = request.readInt16Le();
                auto coord2 = request.readInt16Le();
                auto coord3 = request.readInt16Le();
                auto power = request.readInt16Le();
                auto pathlossexponent = request.readUInt16Le();
                auto status_ = setAbsoluteCommand(coord1, coord2, coord3, power, pathlossexponent);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto power = request.readInt16Le();
                auto pathlossexponent = request.readUInt16Le();
                auto calperiod = request.readUInt16Le();
                auto numrssimeasurements = request.readUInt8();
                auto reportingperiod = request.readUInt16Le();
                auto status_ = setDevCfgCommand(power, pathlossexponent, calperiod, numrssimeasurements, reportingperiod);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto targetaddr = request.readUInt64Le();
                auto status_ = getDevCfgCommand(targetaddr);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto getdatainfo = request.readUInt8();
                auto numrsp = request.readUInt8();
                auto targetaddr = request.readUInt64Le();
                auto status_ = getDataCommand(getdatainfo, numrsp, targetaddr);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class GenAnalogInputCluster: public Cluster {
public:
    GenAnalogInputCluster() : Cluster(12) {
    }

    String getDescription() {
        return getString(28);
    }

    void setDescription(const String& value) {
        setString(28, value);
    }

    float getMaxPresentValue() {
        return getSingle(65);
    }

    void setMaxPresentValue(float value) {
        setSingle(65, value);
    }

    float getMinPresentValue() {
        return getSingle(69);
    }

    void setMinPresentValue(float value) {
        setSingle(69, value);
    }

    bool getOutOfService() {
        return getBool(81);
    }

    void setOutOfService(bool value) {
        setBool(81, value);
    }

    float getPresentValue() {
        return getSingle(85);
    }

    void setPresentValue(float value) {
        setSingle(85, value);
    }

    uint8_t getReliability() {
        return getEnum8(103);
    }

    void setReliability(uint8_t value) {
        setEnum8(103, value);
    }

    float getResolution() {
        return getSingle(106);
    }

    void setResolution(float value) {
        setSingle(106, value);
    }

    uint8_t getStatusFlags() {
        return getMap8(111);
    }

    void setStatusFlags(uint8_t value) {
        setMap8(111, value);
    }

    uint16_t getEngineeringUnits() {
        return getEnum16(117);
    }

    void setEngineeringUnits(uint16_t value) {
        setEnum16(117, value);
    }

    uint32_t getApplicationType() {
        return getUInt32(256);
    }

    void setApplicationType(uint32_t value) {
        setUInt32(256, value);
    }
};

class GenAnalogOutputCluster: public Cluster {
public:
    GenAnalogOutputCluster() : Cluster(13) {
    }

    String getDescription() {
        return getString(28);
    }

    void setDescription(const String& value) {
        setString(28, value);
    }

    float getMaxPresentValue() {
        return getSingle(65);
    }

    void setMaxPresentValue(float value) {
        setSingle(65, value);
    }

    float getMinPresentValue() {
        return getSingle(69);
    }

    void setMinPresentValue(float value) {
        setSingle(69, value);
    }

    bool getOutOfService() {
        return getBool(81);
    }

    void setOutOfService(bool value) {
        setBool(81, value);
    }

    float getPresentValue() {
        return getSingle(85);
    }

    void setPresentValue(float value) {
        setSingle(85, value);
    }

    uint8_t getReliability() {
        return getEnum8(103);
    }

    void setReliability(uint8_t value) {
        setEnum8(103, value);
    }

    float getRelinquishDefault() {
        return getSingle(104);
    }

    void setRelinquishDefault(float value) {
        setSingle(104, value);
    }

    float getResolution() {
        return getSingle(106);
    }

    void setResolution(float value) {
        setSingle(106, value);
    }

    uint8_t getStatusFlags() {
        return getMap8(111);
    }

    void setStatusFlags(uint8_t value) {
        setMap8(111, value);
    }

    uint16_t getEngineeringUnits() {
        return getEnum16(117);
    }

    void setEngineeringUnits(uint16_t value) {
        setEnum16(117, value);
    }

    uint32_t getApplicationType() {
        return getUInt32(256);
    }

    void setApplicationType(uint32_t value) {
        setUInt32(256, value);
    }
};

class GenAnalogValueCluster: public Cluster {
public:
    GenAnalogValueCluster() : Cluster(14) {
    }

    String getDescription() {
        return getString(28);
    }

    void setDescription(const String& value) {
        setString(28, value);
    }

    bool getOutOfService() {
        return getBool(81);
    }

    void setOutOfService(bool value) {
        setBool(81, value);
    }

    float getPresentValue() {
        return getSingle(85);
    }

    void setPresentValue(float value) {
        setSingle(85, value);
    }

    uint8_t getReliability() {
        return getEnum8(103);
    }

    void setReliability(uint8_t value) {
        setEnum8(103, value);
    }

    float getRelinquishDefault() {
        return getSingle(104);
    }

    void setRelinquishDefault(float value) {
        setSingle(104, value);
    }

    uint8_t getStatusFlags() {
        return getMap8(111);
    }

    void setStatusFlags(uint8_t value) {
        setMap8(111, value);
    }

    uint16_t getEngineeringUnits() {
        return getEnum16(117);
    }

    void setEngineeringUnits(uint16_t value) {
        setEnum16(117, value);
    }

    uint32_t getApplicationType() {
        return getUInt32(256);
    }

    void setApplicationType(uint32_t value) {
        setUInt32(256, value);
    }
};

class GenBinaryInputCluster: public Cluster {
public:
    GenBinaryInputCluster() : Cluster(15) {
    }

    String getActiveText() {
        return getString(4);
    }

    void setActiveText(const String& value) {
        setString(4, value);
    }

    String getDescription() {
        return getString(28);
    }

    void setDescription(const String& value) {
        setString(28, value);
    }

    String getInactiveText() {
        return getString(46);
    }

    void setInactiveText(const String& value) {
        setString(46, value);
    }

    bool getOutOfService() {
        return getBool(81);
    }

    void setOutOfService(bool value) {
        setBool(81, value);
    }

    uint8_t getPolarity() {
        return getEnum8(84);
    }

    void setPolarity(uint8_t value) {
        setEnum8(84, value);
    }

    bool getPresentValue() {
        return getBool(85);
    }

    void setPresentValue(bool value) {
        setBool(85, value);
    }

    uint8_t getReliability() {
        return getEnum8(103);
    }

    void setReliability(uint8_t value) {
        setEnum8(103, value);
    }

    uint8_t getStatusFlags() {
        return getMap8(111);
    }

    void setStatusFlags(uint8_t value) {
        setMap8(111, value);
    }

    uint32_t getApplicationType() {
        return getUInt32(256);
    }

    void setApplicationType(uint32_t value) {
        setUInt32(256, value);
    }
};

class GenBinaryOutputCluster: public Cluster {
public:
    GenBinaryOutputCluster() : Cluster(16) {
    }

    String getActiveText() {
        return getString(4);
    }

    void setActiveText(const String& value) {
        setString(4, value);
    }

    String getDescription() {
        return getString(28);
    }

    void setDescription(const String& value) {
        setString(28, value);
    }

    String getInactiveText() {
        return getString(46);
    }

    void setInactiveText(const String& value) {
        setString(46, value);
    }

    uint32_t getMinimumOffTime() {
        return getUInt32(66);
    }

    void setMinimumOffTime(uint32_t value) {
        setUInt32(66, value);
    }

    uint32_t getMinimumOnTime() {
        return getUInt32(67);
    }

    void setMinimumOnTime(uint32_t value) {
        setUInt32(67, value);
    }

    bool getOutOfService() {
        return getBool(81);
    }

    void setOutOfService(bool value) {
        setBool(81, value);
    }

    uint8_t getPolarity() {
        return getEnum8(84);
    }

    void setPolarity(uint8_t value) {
        setEnum8(84, value);
    }

    bool getPresentValue() {
        return getBool(85);
    }

    void setPresentValue(bool value) {
        setBool(85, value);
    }

    uint8_t getReliability() {
        return getEnum8(103);
    }

    void setReliability(uint8_t value) {
        setEnum8(103, value);
    }

    bool getRelinquishDefault() {
        return getBool(104);
    }

    void setRelinquishDefault(bool value) {
        setBool(104, value);
    }

    uint8_t getStatusFlags() {
        return getMap8(111);
    }

    void setStatusFlags(uint8_t value) {
        setMap8(111, value);
    }

    uint32_t getApplicationType() {
        return getUInt32(256);
    }

    void setApplicationType(uint32_t value) {
        setUInt32(256, value);
    }
};

class GenBinaryValueCluster: public Cluster {
public:
    GenBinaryValueCluster() : Cluster(17) {
    }

    String getActiveText() {
        return getString(4);
    }

    void setActiveText(const String& value) {
        setString(4, value);
    }

    String getDescription() {
        return getString(28);
    }

    void setDescription(const String& value) {
        setString(28, value);
    }

    String getInactiveText() {
        return getString(46);
    }

    void setInactiveText(const String& value) {
        setString(46, value);
    }

    uint32_t getMinimumOffTime() {
        return getUInt32(66);
    }

    void setMinimumOffTime(uint32_t value) {
        setUInt32(66, value);
    }

    uint32_t getMinimumOnTime() {
        return getUInt32(67);
    }

    void setMinimumOnTime(uint32_t value) {
        setUInt32(67, value);
    }

    bool getOutOfService() {
        return getBool(81);
    }

    void setOutOfService(bool value) {
        setBool(81, value);
    }

    bool getPresentValue() {
        return getBool(85);
    }

    void setPresentValue(bool value) {
        setBool(85, value);
    }

    uint8_t getReliability() {
        return getEnum8(103);
    }

    void setReliability(uint8_t value) {
        setEnum8(103, value);
    }

    bool getRelinquishDefault() {
        return getBool(104);
    }

    void setRelinquishDefault(bool value) {
        setBool(104, value);
    }

    uint8_t getStatusFlags() {
        return getMap8(111);
    }

    void setStatusFlags(uint8_t value) {
        setMap8(111, value);
    }

    uint32_t getApplicationType() {
        return getUInt32(256);
    }

    void setApplicationType(uint32_t value) {
        setUInt32(256, value);
    }
};

class GenMultistateInputCluster: public Cluster {
public:
    GenMultistateInputCluster() : Cluster(18) {
    }

    String getDescription() {
        return getString(28);
    }

    void setDescription(const String& value) {
        setString(28, value);
    }

    uint16_t getNumberOfStates() {
        return getUInt16(74);
    }

    void setNumberOfStates(uint16_t value) {
        setUInt16(74, value);
    }

    bool getOutOfService() {
        return getBool(81);
    }

    void setOutOfService(bool value) {
        setBool(81, value);
    }

    uint16_t getPresentValue() {
        return getUInt16(85);
    }

    void setPresentValue(uint16_t value) {
        setUInt16(85, value);
    }

    uint8_t getReliability() {
        return getEnum8(103);
    }

    void setReliability(uint8_t value) {
        setEnum8(103, value);
    }

    uint8_t getStatusFlags() {
        return getMap8(111);
    }

    void setStatusFlags(uint8_t value) {
        setMap8(111, value);
    }

    uint32_t getApplicationType() {
        return getUInt32(256);
    }

    void setApplicationType(uint32_t value) {
        setUInt32(256, value);
    }
};

class GenMultistateOutputCluster: public Cluster {
public:
    GenMultistateOutputCluster() : Cluster(19) {
    }

    String getDescription() {
        return getString(28);
    }

    void setDescription(const String& value) {
        setString(28, value);
    }

    uint16_t getNumberOfStates() {
        return getUInt16(74);
    }

    void setNumberOfStates(uint16_t value) {
        setUInt16(74, value);
    }

    bool getOutOfService() {
        return getBool(81);
    }

    void setOutOfService(bool value) {
        setBool(81, value);
    }

    uint16_t getPresentValue() {
        return getUInt16(85);
    }

    void setPresentValue(uint16_t value) {
        setUInt16(85, value);
    }

    uint8_t getReliability() {
        return getEnum8(103);
    }

    void setReliability(uint8_t value) {
        setEnum8(103, value);
    }

    uint16_t getRelinquishDefault() {
        return getUInt16(104);
    }

    void setRelinquishDefault(uint16_t value) {
        setUInt16(104, value);
    }

    uint8_t getStatusFlags() {
        return getMap8(111);
    }

    void setStatusFlags(uint8_t value) {
        setMap8(111, value);
    }

    uint32_t getApplicationType() {
        return getUInt32(256);
    }

    void setApplicationType(uint32_t value) {
        setUInt32(256, value);
    }
};

class GenMultistateValueCluster: public Cluster {
public:
    GenMultistateValueCluster() : Cluster(20) {
    }

    String getDescription() {
        return getString(28);
    }

    void setDescription(const String& value) {
        setString(28, value);
    }

    uint16_t getNumberOfStates() {
        return getUInt16(74);
    }

    void setNumberOfStates(uint16_t value) {
        setUInt16(74, value);
    }

    bool getOutOfService() {
        return getBool(81);
    }

    void setOutOfService(bool value) {
        setBool(81, value);
    }

    uint16_t getPresentValue() {
        return getUInt16(85);
    }

    void setPresentValue(uint16_t value) {
        setUInt16(85, value);
    }

    uint8_t getReliability() {
        return getEnum8(103);
    }

    void setReliability(uint8_t value) {
        setEnum8(103, value);
    }

    uint16_t getRelinquishDefault() {
        return getUInt16(104);
    }

    void setRelinquishDefault(uint16_t value) {
        setUInt16(104, value);
    }

    uint8_t getStatusFlags() {
        return getMap8(111);
    }

    void setStatusFlags(uint8_t value) {
        setMap8(111, value);
    }

    uint32_t getApplicationType() {
        return getUInt32(256);
    }

    void setApplicationType(uint32_t value) {
        setUInt32(256, value);
    }
};

class GenCommissioningCluster: public Cluster {
public:
    GenCommissioningCluster() : Cluster(21) {
    }

    uint16_t getShortress() {
        return getUInt16(0);
    }

    void setShortress(uint16_t value) {
        setUInt16(0, value);
    }

    uint64_t getExtendedPANId() {
        return getEUI64(1);
    }

    void setExtendedPANId(uint64_t value) {
        setEUI64(1, value);
    }

    uint16_t getPanId() {
        return getUInt16(2);
    }

    void setPanId(uint16_t value) {
        setUInt16(2, value);
    }

    uint32_t getChannelmask() {
        return getMap32(3);
    }

    void setChannelmask(uint32_t value) {
        setMap32(3, value);
    }

    uint8_t getProtocolVersion() {
        return getUInt8(4);
    }

    void setProtocolVersion(uint8_t value) {
        setUInt8(4, value);
    }

    uint8_t getStackProfile() {
        return getUInt8(5);
    }

    void setStackProfile(uint8_t value) {
        setUInt8(5, value);
    }

    uint8_t getStartupControl() {
        return getEnum8(6);
    }

    void setStartupControl(uint8_t value) {
        setEnum8(6, value);
    }

    uint64_t getTrustCenterress() {
        return getEUI64(16);
    }

    void setTrustCenterress(uint64_t value) {
        setEUI64(16, value);
    }

    bool getUseInsecureJoin() {
        return getBool(19);
    }

    void setUseInsecureJoin(bool value) {
        setBool(19, value);
    }

    uint8_t getNetworkKeySeqNum() {
        return getUInt8(21);
    }

    void setNetworkKeySeqNum(uint8_t value) {
        setUInt8(21, value);
    }

    uint8_t getNetworkKeyType() {
        return getEnum8(22);
    }

    void setNetworkKeyType(uint8_t value) {
        setEnum8(22, value);
    }

    uint16_t getNetworkManagerress() {
        return getUInt16(23);
    }

    void setNetworkManagerress(uint16_t value) {
        setUInt16(23, value);
    }

    uint8_t getScanAttempts() {
        return getUInt8(32);
    }

    void setScanAttempts(uint8_t value) {
        setUInt8(32, value);
    }

    uint16_t getTimeBetweenScans() {
        return getUInt16(33);
    }

    void setTimeBetweenScans(uint16_t value) {
        setUInt16(33, value);
    }

    uint16_t getRejoinInterval() {
        return getUInt16(34);
    }

    void setRejoinInterval(uint16_t value) {
        setUInt16(34, value);
    }

    uint16_t getMaxRejoinInterval() {
        return getUInt16(35);
    }

    void setMaxRejoinInterval(uint16_t value) {
        setUInt16(35, value);
    }

    uint16_t getIndirectPollRate() {
        return getUInt16(48);
    }

    void setIndirectPollRate(uint16_t value) {
        setUInt16(48, value);
    }

    uint8_t getParentRetryThreshold() {
        return getUInt8(49);
    }

    void setParentRetryThreshold(uint8_t value) {
        setUInt8(49, value);
    }

    bool getConcentratorFlag() {
        return getBool(64);
    }

    void setConcentratorFlag(bool value) {
        setBool(64, value);
    }

    uint8_t getConcentratorRus() {
        return getUInt8(65);
    }

    void setConcentratorRus(uint8_t value) {
        setUInt8(65, value);
    }

    uint8_t getConcentratorDiscoveryTime() {
        return getUInt8(66);
    }

    void setConcentratorDiscoveryTime(uint8_t value) {
        setUInt8(66, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto options = request.readUInt8();
                auto delay = request.readUInt8();
                auto jitter = request.readUInt8();
                auto status_ = restartDeviceCommand(options, delay, jitter);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto options = request.readUInt8();
                auto index = request.readUInt8();
                auto status_ = saveStartupParamsCommand(options, index);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto options = request.readUInt8();
                auto index = request.readUInt8();
                auto status_ = restoreStartupParamsCommand(options, index);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto options = request.readUInt8();
                auto index = request.readUInt8();
                auto status_ = resetStartupParamsCommand(options, index);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class GenOtaCluster: public Cluster {
public:
    GenOtaCluster() : Cluster(25) {
    }

    uint64_t getUpgradeServerId() {
        return getEUI64(0);
    }

    void setUpgradeServerId(uint64_t value) {
        setEUI64(0, value);
    }

    uint32_t getFileOffset() {
        return getUInt32(1);
    }

    void setFileOffset(uint32_t value) {
        setUInt32(1, value);
    }

    uint32_t getCurrentFileVersion() {
        return getUInt32(2);
    }

    void setCurrentFileVersion(uint32_t value) {
        setUInt32(2, value);
    }

    uint16_t getCurrentZigbeeStackVersion() {
        return getUInt16(3);
    }

    void setCurrentZigbeeStackVersion(uint16_t value) {
        setUInt16(3, value);
    }

    uint32_t getDownloadedFileVersion() {
        return getUInt32(4);
    }

    void setDownloadedFileVersion(uint32_t value) {
        setUInt32(4, value);
    }

    uint16_t getDownloadedZigbeeStackVersion() {
        return getUInt16(5);
    }

    void setDownloadedZigbeeStackVersion(uint16_t value) {
        setUInt16(5, value);
    }

    uint8_t getImageUpgradeStatus() {
        return getEnum8(6);
    }

    void setImageUpgradeStatus(uint8_t value) {
        setEnum8(6, value);
    }

    uint16_t getManufacturerId() {
        return getUInt16(7);
    }

    void setManufacturerId(uint16_t value) {
        setUInt16(7, value);
    }

    uint16_t getImageTypeId() {
        return getUInt16(8);
    }

    void setImageTypeId(uint16_t value) {
        setUInt16(8, value);
    }

    uint16_t getMinimumBlockReqDelay() {
        return getUInt16(9);
    }

    void setMinimumBlockReqDelay(uint16_t value) {
        setUInt16(9, value);
    }

    uint32_t getImageStamp() {
        return getUInt32(10);
    }

    void setImageStamp(uint32_t value) {
        setUInt32(10, value);
    }

    class QueryNextImageRequestCommandResponse {
        uint8_t _status{};
        uint16_t _manufacturerCode{};
        uint16_t _imageType{};
        uint32_t _fileVersion{};
        uint32_t _imageSize{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

        uint16_t getManufacturerCode() { return _manufacturerCode; }
        void setManufacturerCode(uint16_t value) { _manufacturerCode = value; }

        uint16_t getImageType() { return _imageType; }
        void setImageType(uint16_t value) { _imageType = value; }

        uint32_t getFileVersion() { return _fileVersion; }
        void setFileVersion(uint32_t value) { _fileVersion = value; }

        uint32_t getImageSize() { return _imageSize; }
        void setImageSize(uint32_t value) { _imageSize = value; }

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
        void setManufacturerCode(uint16_t value) { _manufacturerCode = value; }

        uint16_t getImageType() { return _imageType; }
        void setImageType(uint16_t value) { _imageType = value; }

        uint32_t getFileVersion() { return _fileVersion; }
        void setFileVersion(uint32_t value) { _fileVersion = value; }

        uint32_t getCurrentTime() { return _currentTime; }
        void setCurrentTime(uint32_t value) { _currentTime = value; }

        uint32_t getUpgradeTime() { return _upgradeTime; }
        void setUpgradeTime(uint32_t value) { _upgradeTime = value; }

    };

    virtual Status upgradeEndRequestCommand(uint8_t status, uint16_t manufacturerCode, uint16_t imageType, uint32_t fileVersion, UpgradeEndRequestCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 1: {
                auto fieldControl = request.readUInt8();
                auto manufacturerCode = request.readUInt16Le();
                auto imageType = request.readUInt16Le();
                auto fileVersion = request.readUInt32Le();
                QueryNextImageRequestCommandResponse response_;
                auto status_ = queryNextImageRequestCommand(fieldControl, manufacturerCode, imageType, fileVersion, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                    response.writeUInt16Le(response_.getManufacturerCode());
                    response.writeUInt16Le(response_.getImageType());
                    response.writeUInt32Le(response_.getFileVersion());
                    response.writeUInt32Le(response_.getImageSize());
                }
                return;
            }
            case 6: {
                auto status = request.readUInt8();
                auto manufacturerCode = request.readUInt16Le();
                auto imageType = request.readUInt16Le();
                auto fileVersion = request.readUInt32Le();
                UpgradeEndRequestCommandResponse response_;
                auto status_ = upgradeEndRequestCommand(status, manufacturerCode, imageType, fileVersion, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt16Le(response_.getManufacturerCode());
                    response.writeUInt16Le(response_.getImageType());
                    response.writeUInt32Le(response_.getFileVersion());
                    response.writeUInt32Le(response_.getCurrentTime());
                    response.writeUInt32Le(response_.getUpgradeTime());
                }
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class GenPollCtrlCluster: public Cluster {
public:
    GenPollCtrlCluster() : Cluster(32) {
    }

    uint32_t getCheckinInterval() {
        return getUInt32(0);
    }

    void setCheckinInterval(uint32_t value) {
        setUInt32(0, value);
    }

    uint32_t getLongPollInterval() {
        return getUInt32(1);
    }

    void setLongPollInterval(uint32_t value) {
        setUInt32(1, value);
    }

    uint16_t getShortPollInterval() {
        return getUInt16(2);
    }

    void setShortPollInterval(uint16_t value) {
        setUInt16(2, value);
    }

    uint16_t getFastPollTimeout() {
        return getUInt16(3);
    }

    void setFastPollTimeout(uint16_t value) {
        setUInt16(3, value);
    }

    uint32_t getCheckinIntervalMin() {
        return getUInt32(4);
    }

    void setCheckinIntervalMin(uint32_t value) {
        setUInt32(4, value);
    }

    uint32_t getLongPollIntervalMin() {
        return getUInt32(5);
    }

    void setLongPollIntervalMin(uint32_t value) {
        setUInt32(5, value);
    }

    uint16_t getFastPollTimeoutMax() {
        return getUInt16(6);
    }

    void setFastPollTimeoutMax(uint16_t value) {
        setUInt16(6, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto startFastPolling = request.readUInt8();
                auto fastPollTimeout = request.readUInt16Le();
                auto status_ = checkinRspCommand(startFastPolling, fastPollTimeout);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto status_ = fastPollStopCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto newLongPollInterval = request.readUInt32Le();
                auto status_ = setLongPollIntervalCommand(newLongPollInterval);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto newShortPollInterval = request.readUInt16Le();
                auto status_ = setShortPollIntervalCommand(newShortPollInterval);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
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

    uint16_t getKeepAliveTime() {
        return getUInt16(0);
    }

    void setKeepAliveTime(uint16_t value) {
        setUInt16(0, value);
    }

    uint16_t getRejoinTimeout() {
        return getUInt16(1);
    }

    void setRejoinTimeout(uint16_t value) {
        setUInt16(1, value);
    }
};

class NeighborCleaningCluster: public Cluster {
public:
    NeighborCleaningCluster() : Cluster(35) {
    }

    uint16_t getNeighborCleaningTimeout() {
        return getUInt16(0);
    }

    void setNeighborCleaningTimeout(uint16_t value) {
        setUInt16(0, value);
    }
};

class NearestGatewayCluster: public Cluster {
public:
    NearestGatewayCluster() : Cluster(36) {
    }

    uint16_t getNearestGateway() {
        return getUInt16(0);
    }

    void setNearestGateway(uint16_t value) {
        setUInt16(0, value);
    }

    uint16_t getNewMobileNode() {
        return getUInt16(1);
    }

    void setNewMobileNode(uint16_t value) {
        setUInt16(1, value);
    }
};

class ClosuresShadeCfgCluster: public Cluster {
public:
    ClosuresShadeCfgCluster() : Cluster(256) {
    }

    uint16_t getPhysicalClosedLimit() {
        return getUInt16(0);
    }

    void setPhysicalClosedLimit(uint16_t value) {
        setUInt16(0, value);
    }

    uint8_t getMotorStepSize() {
        return getUInt8(1);
    }

    void setMotorStepSize(uint8_t value) {
        setUInt8(1, value);
    }

    uint8_t getStatus() {
        return getMap8(2);
    }

    void setStatus(uint8_t value) {
        setMap8(2, value);
    }

    uint16_t getLosedLimit() {
        return getUInt16(16);
    }

    void setLosedLimit(uint16_t value) {
        setUInt16(16, value);
    }

    uint8_t getMode() {
        return getEnum8(18);
    }

    void setMode(uint8_t value) {
        setEnum8(18, value);
    }
};

class ClosuresDoorLockCluster: public Cluster {
public:
    ClosuresDoorLockCluster() : Cluster(257) {
    }

    uint8_t getLockState() {
        return getEnum8(0);
    }

    void setLockState(uint8_t value) {
        setEnum8(0, value);
    }

    uint16_t getLockType() {
        return getMap16(38);
    }

    void setLockType(uint16_t value) {
        setMap16(38, value);
    }

    bool getActuatorEnabled() {
        return getBool(2);
    }

    void setActuatorEnabled(bool value) {
        setBool(2, value);
    }

    uint8_t getDoorState() {
        return getEnum8(3);
    }

    void setDoorState(uint8_t value) {
        setEnum8(3, value);
    }

    uint32_t getDoorOpenEvents() {
        return getUInt32(4);
    }

    void setDoorOpenEvents(uint32_t value) {
        setUInt32(4, value);
    }

    uint32_t getDoorClosedEvents() {
        return getUInt32(5);
    }

    void setDoorClosedEvents(uint32_t value) {
        setUInt32(5, value);
    }

    uint16_t getOpenPeriod() {
        return getUInt16(6);
    }

    void setOpenPeriod(uint16_t value) {
        setUInt16(6, value);
    }

    uint16_t getNumOfLockRecordsSupported() {
        return getUInt16(16);
    }

    void setNumOfLockRecordsSupported(uint16_t value) {
        setUInt16(16, value);
    }

    uint16_t getNumOfTotalUsersSupported() {
        return getUInt16(17);
    }

    void setNumOfTotalUsersSupported(uint16_t value) {
        setUInt16(17, value);
    }

    uint16_t getNumOfPinUsersSupported() {
        return getUInt16(18);
    }

    void setNumOfPinUsersSupported(uint16_t value) {
        setUInt16(18, value);
    }

    uint16_t getNumOfRfidUsersSupported() {
        return getUInt16(19);
    }

    void setNumOfRfidUsersSupported(uint16_t value) {
        setUInt16(19, value);
    }

    uint8_t getNumOfWeekDaySchedulesSupportedPerUser() {
        return getUInt8(20);
    }

    void setNumOfWeekDaySchedulesSupportedPerUser(uint8_t value) {
        setUInt8(20, value);
    }

    uint8_t getNumOfYearDaySchedulesSupportedPerUser() {
        return getUInt8(21);
    }

    void setNumOfYearDaySchedulesSupportedPerUser(uint8_t value) {
        setUInt8(21, value);
    }

    uint8_t getNumOfHolidayScheduledsSupported() {
        return getUInt8(22);
    }

    void setNumOfHolidayScheduledsSupported(uint8_t value) {
        setUInt8(22, value);
    }

    uint8_t getMaxPinLen() {
        return getUInt8(23);
    }

    void setMaxPinLen(uint8_t value) {
        setUInt8(23, value);
    }

    uint8_t getMinPinLen() {
        return getUInt8(24);
    }

    void setMinPinLen(uint8_t value) {
        setUInt8(24, value);
    }

    uint8_t getMaxRfidLen() {
        return getUInt8(25);
    }

    void setMaxRfidLen(uint8_t value) {
        setUInt8(25, value);
    }

    uint8_t getMinRfidLen() {
        return getUInt8(26);
    }

    void setMinRfidLen(uint8_t value) {
        setUInt8(26, value);
    }

    bool getEnableLogging() {
        return getBool(32);
    }

    void setEnableLogging(bool value) {
        setBool(32, value);
    }

    String getLanguage() {
        return getString(33);
    }

    void setLanguage(const String& value) {
        setString(33, value);
    }

    uint8_t getLedSettings() {
        return getUInt8(34);
    }

    void setLedSettings(uint8_t value) {
        setUInt8(34, value);
    }

    uint32_t getAutoRelockTime() {
        return getUInt32(35);
    }

    void setAutoRelockTime(uint32_t value) {
        setUInt32(35, value);
    }

    uint8_t getSoundVolume() {
        return getUInt8(36);
    }

    void setSoundVolume(uint8_t value) {
        setUInt8(36, value);
    }

    uint32_t getOperatingMode() {
        return getUInt32(37);
    }

    void setOperatingMode(uint32_t value) {
        setUInt32(37, value);
    }

    uint16_t getDefaultConfigurationRegister() {
        return getMap16(39);
    }

    void setDefaultConfigurationRegister(uint16_t value) {
        setMap16(39, value);
    }

    bool getEnableLocalProgramming() {
        return getBool(40);
    }

    void setEnableLocalProgramming(bool value) {
        setBool(40, value);
    }

    bool getEnableOneTouchLocking() {
        return getBool(41);
    }

    void setEnableOneTouchLocking(bool value) {
        setBool(41, value);
    }

    bool getEnableInsideStatusLed() {
        return getBool(42);
    }

    void setEnableInsideStatusLed(bool value) {
        setBool(42, value);
    }

    bool getEnablePrivacyModeButton() {
        return getBool(43);
    }

    void setEnablePrivacyModeButton(bool value) {
        setBool(43, value);
    }

    uint8_t getWrongCodeEntryLimit() {
        return getUInt8(48);
    }

    void setWrongCodeEntryLimit(uint8_t value) {
        setUInt8(48, value);
    }

    uint8_t getUserCodeTemporaryDisableTime() {
        return getUInt8(49);
    }

    void setUserCodeTemporaryDisableTime(uint8_t value) {
        setUInt8(49, value);
    }

    bool getSendPinOta() {
        return getBool(50);
    }

    void setSendPinOta(bool value) {
        setBool(50, value);
    }

    bool getRequirePinForRfOperation() {
        return getBool(51);
    }

    void setRequirePinForRfOperation(bool value) {
        setBool(51, value);
    }

    uint8_t getZigbeeSecurityLevel() {
        return getUInt8(52);
    }

    void setZigbeeSecurityLevel(uint8_t value) {
        setUInt8(52, value);
    }

    uint16_t getAlarmMask() {
        return getMap16(64);
    }

    void setAlarmMask(uint16_t value) {
        setMap16(64, value);
    }

    uint16_t getKeypadOperationEventMask() {
        return getMap16(65);
    }

    void setKeypadOperationEventMask(uint16_t value) {
        setMap16(65, value);
    }

    uint16_t getRfOperationEventMask() {
        return getMap16(66);
    }

    void setRfOperationEventMask(uint16_t value) {
        setMap16(66, value);
    }

    uint16_t getManualOperationEventMask() {
        return getMap16(67);
    }

    void setManualOperationEventMask(uint16_t value) {
        setMap16(67, value);
    }

    uint16_t getRfidOperationEventMask() {
        return getMap16(68);
    }

    void setRfidOperationEventMask(uint16_t value) {
        setMap16(68, value);
    }

    uint16_t getKeypadProgrammingEventMask() {
        return getMap16(69);
    }

    void setKeypadProgrammingEventMask(uint16_t value) {
        setMap16(69, value);
    }

    uint16_t getRfProgrammingEventMask() {
        return getMap16(70);
    }

    void setRfProgrammingEventMask(uint16_t value) {
        setMap16(70, value);
    }

    uint16_t getRfidProgrammingEventMask() {
        return getMap16(71);
    }

    void setRfidProgrammingEventMask(uint16_t value) {
        setMap16(71, value);
    }

    class LockDoorCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status lockDoorCommand(String pincodevalue, LockDoorCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class UnlockDoorCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status unlockDoorCommand(String pincodevalue, UnlockDoorCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ToggleDoorCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status toggleDoorCommand(String pincodevalue, ToggleDoorCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class UnlockWithTimeoutCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

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
        void setLogentryid(uint16_t value) { _logentryid = value; }

        uint32_t getTimestamp() { return _timestamp; }
        void setTimestamp(uint32_t value) { _timestamp = value; }

        uint8_t getEventtype() { return _eventtype; }
        void setEventtype(uint8_t value) { _eventtype = value; }

        uint8_t getSource() { return _source; }
        void setSource(uint8_t value) { _source = value; }

        uint8_t getEventidalarmcode() { return _eventidalarmcode; }
        void setEventidalarmcode(uint8_t value) { _eventidalarmcode = value; }

        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t value) { _userid = value; }

        String getPincodevalue() { return _pincodevalue; }
        void setPincodevalue(const String& value) { _pincodevalue = value; }

    };

    virtual Status getLogRecordCommand(uint16_t logindex, GetLogRecordCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetPinCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

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
        void setUserid(uint16_t value) { _userid = value; }

        uint8_t getUserstatus() { return _userstatus; }
        void setUserstatus(uint8_t value) { _userstatus = value; }

        uint8_t getUsertype() { return _usertype; }
        void setUsertype(uint8_t value) { _usertype = value; }

        String getPincodevalue() { return _pincodevalue; }
        void setPincodevalue(const String& value) { _pincodevalue = value; }

    };

    virtual Status getPinCodeCommand(uint16_t userid, GetPinCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearPinCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status clearPinCodeCommand(uint16_t userid, ClearPinCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearAllPinCodesCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status clearAllPinCodesCommand(ClearAllPinCodesCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetUserStatusCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status setUserStatusCommand(uint16_t userid, uint8_t userstatus, SetUserStatusCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetUserStatusCommandResponse {
        uint16_t _userid{};
        uint8_t _userstatus{};

    public:
        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t value) { _userid = value; }

        uint8_t getUserstatus() { return _userstatus; }
        void setUserstatus(uint8_t value) { _userstatus = value; }

    };

    virtual Status getUserStatusCommand(uint16_t userid, GetUserStatusCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetWeekDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

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
        void setScheduleid(uint8_t value) { _scheduleid = value; }

        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t value) { _userid = value; }

        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

        uint8_t getDaysmask() { return _daysmask; }
        void setDaysmask(uint8_t value) { _daysmask = value; }

        uint8_t getStarthour() { return _starthour; }
        void setStarthour(uint8_t value) { _starthour = value; }

        uint8_t getStartminute() { return _startminute; }
        void setStartminute(uint8_t value) { _startminute = value; }

        uint8_t getEndhour() { return _endhour; }
        void setEndhour(uint8_t value) { _endhour = value; }

        uint8_t getEndminute() { return _endminute; }
        void setEndminute(uint8_t value) { _endminute = value; }

    };

    virtual Status getWeekDayScheduleCommand(uint8_t scheduleid, uint16_t userid, GetWeekDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearWeekDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status clearWeekDayScheduleCommand(uint8_t scheduleid, uint16_t userid, ClearWeekDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetYearDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

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
        void setScheduleid(uint8_t value) { _scheduleid = value; }

        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t value) { _userid = value; }

        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

        uint32_t getZigbeelocalstarttime() { return _zigbeelocalstarttime; }
        void setZigbeelocalstarttime(uint32_t value) { _zigbeelocalstarttime = value; }

        uint32_t getZigbeelocalendtime() { return _zigbeelocalendtime; }
        void setZigbeelocalendtime(uint32_t value) { _zigbeelocalendtime = value; }

    };

    virtual Status getYearDayScheduleCommand(uint8_t scheduleid, uint16_t userid, GetYearDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearYearDayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status clearYearDayScheduleCommand(uint8_t scheduleid, uint16_t userid, ClearYearDayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetHolidayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

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
        void setHolidayscheduleid(uint8_t value) { _holidayscheduleid = value; }

        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

        uint32_t getZigbeelocalstarttime() { return _zigbeelocalstarttime; }
        void setZigbeelocalstarttime(uint32_t value) { _zigbeelocalstarttime = value; }

        uint32_t getZigbeelocalendtime() { return _zigbeelocalendtime; }
        void setZigbeelocalendtime(uint32_t value) { _zigbeelocalendtime = value; }

        uint8_t getOpermodelduringholiday() { return _opermodelduringholiday; }
        void setOpermodelduringholiday(uint8_t value) { _opermodelduringholiday = value; }

    };

    virtual Status getHolidayScheduleCommand(uint8_t holidayscheduleid, GetHolidayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearHolidayScheduleCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status clearHolidayScheduleCommand(uint8_t holidayscheduleid, ClearHolidayScheduleCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetUserTypeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status setUserTypeCommand(uint16_t userid, uint8_t usertype, SetUserTypeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class GetUserTypeCommandResponse {
        uint16_t _userid{};
        uint8_t _usertype{};

    public:
        uint16_t getUserid() { return _userid; }
        void setUserid(uint16_t value) { _userid = value; }

        uint8_t getUsertype() { return _usertype; }
        void setUsertype(uint8_t value) { _usertype = value; }

    };

    virtual Status getUserTypeCommand(uint16_t userid, GetUserTypeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class SetRfidCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

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
        void setUserid(uint16_t value) { _userid = value; }

        uint8_t getUserstatus() { return _userstatus; }
        void setUserstatus(uint8_t value) { _userstatus = value; }

        uint8_t getUsertype() { return _usertype; }
        void setUsertype(uint8_t value) { _usertype = value; }

        String getPincodevalue() { return _pincodevalue; }
        void setPincodevalue(const String& value) { _pincodevalue = value; }

    };

    virtual Status getRfidCodeCommand(uint16_t userid, GetRfidCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearRfidCodeCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status clearRfidCodeCommand(uint16_t userid, ClearRfidCodeCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    class ClearAllRfidCodesCommandResponse {
        uint8_t _status{};

    public:
        uint8_t getStatus() { return _status; }
        void setStatus(uint8_t value) { _status = value; }

    };

    virtual Status clearAllRfidCodesCommand(ClearAllRfidCodesCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto pincodevalue = request.readString();
                LockDoorCommandResponse response_;
                auto status_ = lockDoorCommand(pincodevalue, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 1: {
                auto pincodevalue = request.readString();
                UnlockDoorCommandResponse response_;
                auto status_ = unlockDoorCommand(pincodevalue, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 2: {
                auto pincodevalue = request.readString();
                ToggleDoorCommandResponse response_;
                auto status_ = toggleDoorCommand(pincodevalue, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 3: {
                auto timeout = request.readUInt16Le();
                auto pincodevalue = request.readString();
                UnlockWithTimeoutCommandResponse response_;
                auto status_ = unlockWithTimeoutCommand(timeout, pincodevalue, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 4: {
                auto logindex = request.readUInt16Le();
                GetLogRecordCommandResponse response_;
                auto status_ = getLogRecordCommand(logindex, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt16Le(response_.getLogentryid());
                    response.writeUInt32Le(response_.getTimestamp());
                    response.writeUInt8(response_.getEventtype());
                    response.writeUInt8(response_.getSource());
                    response.writeUInt8(response_.getEventidalarmcode());
                    response.writeUInt16Le(response_.getUserid());
                    response.writeString(response_.getPincodevalue());
                }
                return;
            }
            case 5: {
                auto userid = request.readUInt16Le();
                auto userstatus = request.readUInt8();
                auto usertype = request.readUInt8();
                auto pincodevalue = request.readString();
                SetPinCodeCommandResponse response_;
                auto status_ = setPinCodeCommand(userid, userstatus, usertype, pincodevalue, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 6: {
                auto userid = request.readUInt16Le();
                GetPinCodeCommandResponse response_;
                auto status_ = getPinCodeCommand(userid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt16Le(response_.getUserid());
                    response.writeUInt8(response_.getUserstatus());
                    response.writeUInt8(response_.getUsertype());
                    response.writeString(response_.getPincodevalue());
                }
                return;
            }
            case 7: {
                auto userid = request.readUInt16Le();
                ClearPinCodeCommandResponse response_;
                auto status_ = clearPinCodeCommand(userid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 8: {
                ClearAllPinCodesCommandResponse response_;
                auto status_ = clearAllPinCodesCommand(response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 9: {
                auto userid = request.readUInt16Le();
                auto userstatus = request.readUInt8();
                SetUserStatusCommandResponse response_;
                auto status_ = setUserStatusCommand(userid, userstatus, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 10: {
                auto userid = request.readUInt16Le();
                GetUserStatusCommandResponse response_;
                auto status_ = getUserStatusCommand(userid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt16Le(response_.getUserid());
                    response.writeUInt8(response_.getUserstatus());
                }
                return;
            }
            case 11: {
                auto scheduleid = request.readUInt8();
                auto userid = request.readUInt16Le();
                auto daysmask = request.readUInt8();
                auto starthour = request.readUInt8();
                auto startminute = request.readUInt8();
                auto endhour = request.readUInt8();
                auto endminute = request.readUInt8();
                SetWeekDayScheduleCommandResponse response_;
                auto status_ = setWeekDayScheduleCommand(scheduleid, userid, daysmask, starthour, startminute, endhour, endminute, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 12: {
                auto scheduleid = request.readUInt8();
                auto userid = request.readUInt16Le();
                GetWeekDayScheduleCommandResponse response_;
                auto status_ = getWeekDayScheduleCommand(scheduleid, userid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getScheduleid());
                    response.writeUInt16Le(response_.getUserid());
                    response.writeUInt8(response_.getStatus());
                    response.writeUInt8(response_.getDaysmask());
                    response.writeUInt8(response_.getStarthour());
                    response.writeUInt8(response_.getStartminute());
                    response.writeUInt8(response_.getEndhour());
                    response.writeUInt8(response_.getEndminute());
                }
                return;
            }
            case 13: {
                auto scheduleid = request.readUInt8();
                auto userid = request.readUInt16Le();
                ClearWeekDayScheduleCommandResponse response_;
                auto status_ = clearWeekDayScheduleCommand(scheduleid, userid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 14: {
                auto scheduleid = request.readUInt8();
                auto userid = request.readUInt16Le();
                auto zigbeelocalstarttime = request.readUInt32Le();
                auto zigbeelocalendtime = request.readUInt32Le();
                SetYearDayScheduleCommandResponse response_;
                auto status_ = setYearDayScheduleCommand(scheduleid, userid, zigbeelocalstarttime, zigbeelocalendtime, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 15: {
                auto scheduleid = request.readUInt8();
                auto userid = request.readUInt16Le();
                GetYearDayScheduleCommandResponse response_;
                auto status_ = getYearDayScheduleCommand(scheduleid, userid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getScheduleid());
                    response.writeUInt16Le(response_.getUserid());
                    response.writeUInt8(response_.getStatus());
                    response.writeUInt32Le(response_.getZigbeelocalstarttime());
                    response.writeUInt32Le(response_.getZigbeelocalendtime());
                }
                return;
            }
            case 16: {
                auto scheduleid = request.readUInt8();
                auto userid = request.readUInt16Le();
                ClearYearDayScheduleCommandResponse response_;
                auto status_ = clearYearDayScheduleCommand(scheduleid, userid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 17: {
                auto holidayscheduleid = request.readUInt8();
                auto zigbeelocalstarttime = request.readUInt32Le();
                auto zigbeelocalendtime = request.readUInt32Le();
                auto opermodelduringholiday = request.readUInt8();
                SetHolidayScheduleCommandResponse response_;
                auto status_ = setHolidayScheduleCommand(holidayscheduleid, zigbeelocalstarttime, zigbeelocalendtime, opermodelduringholiday, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 18: {
                auto holidayscheduleid = request.readUInt8();
                GetHolidayScheduleCommandResponse response_;
                auto status_ = getHolidayScheduleCommand(holidayscheduleid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getHolidayscheduleid());
                    response.writeUInt8(response_.getStatus());
                    response.writeUInt32Le(response_.getZigbeelocalstarttime());
                    response.writeUInt32Le(response_.getZigbeelocalendtime());
                    response.writeUInt8(response_.getOpermodelduringholiday());
                }
                return;
            }
            case 19: {
                auto holidayscheduleid = request.readUInt8();
                ClearHolidayScheduleCommandResponse response_;
                auto status_ = clearHolidayScheduleCommand(holidayscheduleid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 20: {
                auto userid = request.readUInt16Le();
                auto usertype = request.readUInt8();
                SetUserTypeCommandResponse response_;
                auto status_ = setUserTypeCommand(userid, usertype, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 21: {
                auto userid = request.readUInt16Le();
                GetUserTypeCommandResponse response_;
                auto status_ = getUserTypeCommand(userid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt16Le(response_.getUserid());
                    response.writeUInt8(response_.getUsertype());
                }
                return;
            }
            case 22: {
                auto userid = request.readUInt16Le();
                auto userstatus = request.readUInt8();
                auto usertype = request.readUInt8();
                auto pincodevalue = request.readString();
                SetRfidCodeCommandResponse response_;
                auto status_ = setRfidCodeCommand(userid, userstatus, usertype, pincodevalue, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 23: {
                auto userid = request.readUInt16Le();
                GetRfidCodeCommandResponse response_;
                auto status_ = getRfidCodeCommand(userid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt16Le(response_.getUserid());
                    response.writeUInt8(response_.getUserstatus());
                    response.writeUInt8(response_.getUsertype());
                    response.writeString(response_.getPincodevalue());
                }
                return;
            }
            case 24: {
                auto userid = request.readUInt16Le();
                ClearRfidCodeCommandResponse response_;
                auto status_ = clearRfidCodeCommand(userid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            case 25: {
                ClearAllRfidCodesCommandResponse response_;
                auto status_ = clearAllRfidCodesCommand(response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getStatus());
                }
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class ClosuresWindowCoveringCluster: public Cluster {
public:
    ClosuresWindowCoveringCluster() : Cluster(258) {
    }

    uint8_t getWindowCoveringType() {
        return getEnum8(0);
    }

    void setWindowCoveringType(uint8_t value) {
        setEnum8(0, value);
    }

    uint16_t getPhysicalClosedLimitLiftCm() {
        return getUInt16(1);
    }

    void setPhysicalClosedLimitLiftCm(uint16_t value) {
        setUInt16(1, value);
    }

    uint16_t getPhysicalClosedLimitTiltDdegree() {
        return getUInt16(2);
    }

    void setPhysicalClosedLimitTiltDdegree(uint16_t value) {
        setUInt16(2, value);
    }

    uint16_t getCurrentPositionLiftCm() {
        return getUInt16(3);
    }

    void setCurrentPositionLiftCm(uint16_t value) {
        setUInt16(3, value);
    }

    uint16_t getCurrentPositionTiltDdegree() {
        return getUInt16(4);
    }

    void setCurrentPositionTiltDdegree(uint16_t value) {
        setUInt16(4, value);
    }

    uint16_t getNumOfActuationsLift() {
        return getUInt16(5);
    }

    void setNumOfActuationsLift(uint16_t value) {
        setUInt16(5, value);
    }

    uint16_t getNumOfActuationsTilt() {
        return getUInt16(6);
    }

    void setNumOfActuationsTilt(uint16_t value) {
        setUInt16(6, value);
    }

    uint8_t getConfigStatus() {
        return getMap8(7);
    }

    void setConfigStatus(uint8_t value) {
        setMap8(7, value);
    }

    uint8_t getCurrentPositionLiftPercentage() {
        return getUInt8(8);
    }

    void setCurrentPositionLiftPercentage(uint8_t value) {
        setUInt8(8, value);
    }

    uint8_t getCurrentPositionTiltPercentage() {
        return getUInt8(9);
    }

    void setCurrentPositionTiltPercentage(uint8_t value) {
        setUInt8(9, value);
    }

    uint8_t getOperationalStatus() {
        return getMap8(10);
    }

    void setOperationalStatus(uint8_t value) {
        setMap8(10, value);
    }

    uint16_t getInstalledOpenLimitLiftCm() {
        return getUInt16(16);
    }

    void setInstalledOpenLimitLiftCm(uint16_t value) {
        setUInt16(16, value);
    }

    uint16_t getInstalledClosedLimitLiftCm() {
        return getUInt16(17);
    }

    void setInstalledClosedLimitLiftCm(uint16_t value) {
        setUInt16(17, value);
    }

    uint16_t getInstalledOpenLimitTiltDdegree() {
        return getUInt16(18);
    }

    void setInstalledOpenLimitTiltDdegree(uint16_t value) {
        setUInt16(18, value);
    }

    uint16_t getInstalledClosedLimitTiltDdegree() {
        return getUInt16(19);
    }

    void setInstalledClosedLimitTiltDdegree(uint16_t value) {
        setUInt16(19, value);
    }

    uint16_t getVelocityLift() {
        return getUInt16(20);
    }

    void setVelocityLift(uint16_t value) {
        setUInt16(20, value);
    }

    uint16_t getAccelerationTimeLift() {
        return getUInt16(21);
    }

    void setAccelerationTimeLift(uint16_t value) {
        setUInt16(21, value);
    }

    uint16_t getDecelerationTimeLift() {
        return getUInt16(22);
    }

    void setDecelerationTimeLift(uint16_t value) {
        setUInt16(22, value);
    }

    uint8_t getWindowCoveringMode() {
        return getMap8(23);
    }

    void setWindowCoveringMode(uint8_t value) {
        setMap8(23, value);
    }

    Buffer getIntermediateSetpointsLift() {
        return getOctstr(24);
    }

    void setIntermediateSetpointsLift(const Buffer& value) {
        setOctstr(24, value);
    }

    Buffer getIntermediateSetpointsTilt() {
        return getOctstr(25);
    }

    void setIntermediateSetpointsTilt(const Buffer& value) {
        setOctstr(25, value);
    }

    uint16_t getMoesCalibrationTime() {
        return getUInt16(61443);
    }

    void setMoesCalibrationTime(uint16_t value) {
        setUInt16(61443, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto status_ = upOpenCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto status_ = downCloseCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto status_ = stopCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 4: {
                auto liftvalue = request.readUInt16Le();
                auto status_ = goToLiftValueCommand(liftvalue);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 5: {
                auto percentageliftvalue = request.readUInt8();
                auto status_ = goToLiftPercentageCommand(percentageliftvalue);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 7: {
                auto tiltvalue = request.readUInt16Le();
                auto status_ = goToTiltValueCommand(tiltvalue);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 8: {
                auto percentagetiltvalue = request.readUInt8();
                auto status_ = goToTiltPercentageCommand(percentagetiltvalue);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 128: {
                auto direction = request.readUInt16Le();
                auto stepvalue = request.readUInt16Le();
                auto status_ = elkoStopOrStepLiftPercentageCommand(direction, stepvalue);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class BarrierControlCluster: public Cluster {
public:
    BarrierControlCluster() : Cluster(259) {
    }

    uint8_t getMovingState() {
        return getEnum8(1);
    }

    void setMovingState(uint8_t value) {
        setEnum8(1, value);
    }

    uint16_t getSafetyStatus() {
        return getMap16(2);
    }

    void setSafetyStatus(uint16_t value) {
        setMap16(2, value);
    }

    uint8_t getCapabilities() {
        return getMap8(3);
    }

    void setCapabilities(uint8_t value) {
        setMap8(3, value);
    }

    uint16_t getOpenEvents() {
        return getUInt16(4);
    }

    void setOpenEvents(uint16_t value) {
        setUInt16(4, value);
    }

    uint16_t getCloseEvents() {
        return getUInt16(5);
    }

    void setCloseEvents(uint16_t value) {
        setUInt16(5, value);
    }

    uint16_t getCommandOpenEvents() {
        return getUInt16(6);
    }

    void setCommandOpenEvents(uint16_t value) {
        setUInt16(6, value);
    }

    uint16_t getCommandCloseEvents() {
        return getUInt16(7);
    }

    void setCommandCloseEvents(uint16_t value) {
        setUInt16(7, value);
    }

    uint16_t getOpenPeriod() {
        return getUInt16(8);
    }

    void setOpenPeriod(uint16_t value) {
        setUInt16(8, value);
    }

    uint16_t getClosePeriod() {
        return getUInt16(9);
    }

    void setClosePeriod(uint16_t value) {
        setUInt16(9, value);
    }

    uint8_t getBarrierPosition() {
        return getUInt8(10);
    }

    void setBarrierPosition(uint8_t value) {
        setUInt8(10, value);
    }

    virtual Status goToPercentCommand(uint8_t percentOpen) {
        return Status::UnsupportedAttribute;
    }

    virtual Status stopCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto percentOpen = request.readUInt8();
                auto status_ = goToPercentCommand(percentOpen);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto status_ = stopCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class HvacPumpCfgCtrlCluster: public Cluster {
public:
    HvacPumpCfgCtrlCluster() : Cluster(512) {
    }

    int16_t getMaxPressure() {
        return getInt16(0);
    }

    void setMaxPressure(int16_t value) {
        setInt16(0, value);
    }

    uint16_t getMaxSpeed() {
        return getUInt16(1);
    }

    void setMaxSpeed(uint16_t value) {
        setUInt16(1, value);
    }

    uint16_t getMaxFlow() {
        return getUInt16(2);
    }

    void setMaxFlow(uint16_t value) {
        setUInt16(2, value);
    }

    int16_t getMinConstPressure() {
        return getInt16(3);
    }

    void setMinConstPressure(int16_t value) {
        setInt16(3, value);
    }

    int16_t getMaxConstPressure() {
        return getInt16(4);
    }

    void setMaxConstPressure(int16_t value) {
        setInt16(4, value);
    }

    int16_t getMinCompPressure() {
        return getInt16(5);
    }

    void setMinCompPressure(int16_t value) {
        setInt16(5, value);
    }

    int16_t getMaxCompPressure() {
        return getInt16(6);
    }

    void setMaxCompPressure(int16_t value) {
        setInt16(6, value);
    }

    uint16_t getMinConstSpeed() {
        return getUInt16(7);
    }

    void setMinConstSpeed(uint16_t value) {
        setUInt16(7, value);
    }

    uint16_t getMaxConstSpeed() {
        return getUInt16(8);
    }

    void setMaxConstSpeed(uint16_t value) {
        setUInt16(8, value);
    }

    uint16_t getMinConstFlow() {
        return getUInt16(9);
    }

    void setMinConstFlow(uint16_t value) {
        setUInt16(9, value);
    }

    uint16_t getMaxConstFlow() {
        return getUInt16(10);
    }

    void setMaxConstFlow(uint16_t value) {
        setUInt16(10, value);
    }

    int16_t getMinConstTemp() {
        return getInt16(11);
    }

    void setMinConstTemp(int16_t value) {
        setInt16(11, value);
    }

    int16_t getMaxConstTemp() {
        return getInt16(12);
    }

    void setMaxConstTemp(int16_t value) {
        setInt16(12, value);
    }

    uint16_t getPumpStatus() {
        return getMap16(16);
    }

    void setPumpStatus(uint16_t value) {
        setMap16(16, value);
    }

    uint8_t getEffectiveOperationMode() {
        return getEnum8(17);
    }

    void setEffectiveOperationMode(uint8_t value) {
        setEnum8(17, value);
    }

    uint8_t getEffectiveControlMode() {
        return getEnum8(18);
    }

    void setEffectiveControlMode(uint8_t value) {
        setEnum8(18, value);
    }

    int16_t getCapacity() {
        return getInt16(19);
    }

    void setCapacity(int16_t value) {
        setInt16(19, value);
    }

    uint16_t getSpeed() {
        return getUInt16(20);
    }

    void setSpeed(uint16_t value) {
        setUInt16(20, value);
    }

    uint32_t getLifetimeRunningHours() {
        return getUInt24(21);
    }

    void setLifetimeRunningHours(uint32_t value) {
        setUInt24(21, value);
    }

    uint32_t getPower() {
        return getUInt24(22);
    }

    void setPower(uint32_t value) {
        setUInt24(22, value);
    }

    uint32_t getLifetimeEnergyConsumed() {
        return getUInt32(23);
    }

    void setLifetimeEnergyConsumed(uint32_t value) {
        setUInt32(23, value);
    }

    uint8_t getOperationMode() {
        return getEnum8(32);
    }

    void setOperationMode(uint8_t value) {
        setEnum8(32, value);
    }

    uint8_t getControlMode() {
        return getEnum8(33);
    }

    void setControlMode(uint8_t value) {
        setEnum8(33, value);
    }

    uint16_t getAlarmMask() {
        return getMap16(34);
    }

    void setAlarmMask(uint16_t value) {
        setMap16(34, value);
    }
};

class HvacThermostatCluster: public Cluster {
public:
    HvacThermostatCluster() : Cluster(513) {
    }

    int16_t getLocalTemp() {
        return getInt16(0);
    }

    void setLocalTemp(int16_t value) {
        setInt16(0, value);
    }

    int16_t getOutdoorTemp() {
        return getInt16(1);
    }

    void setOutdoorTemp(int16_t value) {
        setInt16(1, value);
    }

    uint8_t getOccupancy() {
        return getMap8(2);
    }

    void setOccupancy(uint8_t value) {
        setMap8(2, value);
    }

    int16_t getAbsMinHeatSetpointLimit() {
        return getInt16(3);
    }

    void setAbsMinHeatSetpointLimit(int16_t value) {
        setInt16(3, value);
    }

    int16_t getAbsMaxHeatSetpointLimit() {
        return getInt16(4);
    }

    void setAbsMaxHeatSetpointLimit(int16_t value) {
        setInt16(4, value);
    }

    int16_t getAbsMinCoolSetpointLimit() {
        return getInt16(5);
    }

    void setAbsMinCoolSetpointLimit(int16_t value) {
        setInt16(5, value);
    }

    int16_t getAbsMaxCoolSetpointLimit() {
        return getInt16(6);
    }

    void setAbsMaxCoolSetpointLimit(int16_t value) {
        setInt16(6, value);
    }

    uint8_t getPICoolingDemand() {
        return getUInt8(7);
    }

    void setPICoolingDemand(uint8_t value) {
        setUInt8(7, value);
    }

    uint8_t getPIHeatingDemand() {
        return getUInt8(8);
    }

    void setPIHeatingDemand(uint8_t value) {
        setUInt8(8, value);
    }

    uint8_t getSystemTypeConfig() {
        return getMap8(9);
    }

    void setSystemTypeConfig(uint8_t value) {
        setMap8(9, value);
    }

    int8_t getLocalTemperatureCalibration() {
        return getInt8(16);
    }

    void setLocalTemperatureCalibration(int8_t value) {
        setInt8(16, value);
    }

    int16_t getOccupiedCoolingSetpoint() {
        return getInt16(17);
    }

    void setOccupiedCoolingSetpoint(int16_t value) {
        setInt16(17, value);
    }

    int16_t getOccupiedHeatingSetpoint() {
        return getInt16(18);
    }

    void setOccupiedHeatingSetpoint(int16_t value) {
        setInt16(18, value);
    }

    int16_t getUnoccupiedCoolingSetpoint() {
        return getInt16(19);
    }

    void setUnoccupiedCoolingSetpoint(int16_t value) {
        setInt16(19, value);
    }

    int16_t getUnoccupiedHeatingSetpoint() {
        return getInt16(20);
    }

    void setUnoccupiedHeatingSetpoint(int16_t value) {
        setInt16(20, value);
    }

    int16_t getMinHeatSetpointLimit() {
        return getInt16(21);
    }

    void setMinHeatSetpointLimit(int16_t value) {
        setInt16(21, value);
    }

    int16_t getMaxHeatSetpointLimit() {
        return getInt16(22);
    }

    void setMaxHeatSetpointLimit(int16_t value) {
        setInt16(22, value);
    }

    int16_t getMinCoolSetpointLimit() {
        return getInt16(23);
    }

    void setMinCoolSetpointLimit(int16_t value) {
        setInt16(23, value);
    }

    int16_t getMaxCoolSetpointLimit() {
        return getInt16(24);
    }

    void setMaxCoolSetpointLimit(int16_t value) {
        setInt16(24, value);
    }

    int8_t getMinSetpointDeadBand() {
        return getInt8(25);
    }

    void setMinSetpointDeadBand(int8_t value) {
        setInt8(25, value);
    }

    uint8_t getRemoteSensing() {
        return getMap8(26);
    }

    void setRemoteSensing(uint8_t value) {
        setMap8(26, value);
    }

    uint8_t getCtrlSeqeOfOper() {
        return getEnum8(27);
    }

    void setCtrlSeqeOfOper(uint8_t value) {
        setEnum8(27, value);
    }

    uint8_t getSystemMode() {
        return getEnum8(28);
    }

    void setSystemMode(uint8_t value) {
        setEnum8(28, value);
    }

    uint8_t getAlarmMask() {
        return getMap8(29);
    }

    void setAlarmMask(uint8_t value) {
        setMap8(29, value);
    }

    uint8_t getRunningMode() {
        return getEnum8(30);
    }

    void setRunningMode(uint8_t value) {
        setEnum8(30, value);
    }

    uint8_t getStartOfWeek() {
        return getEnum8(32);
    }

    void setStartOfWeek(uint8_t value) {
        setEnum8(32, value);
    }

    uint8_t getNumberOfWeeklyTrans() {
        return getUInt8(33);
    }

    void setNumberOfWeeklyTrans(uint8_t value) {
        setUInt8(33, value);
    }

    uint8_t getNumberOfDailyTrans() {
        return getUInt8(34);
    }

    void setNumberOfDailyTrans(uint8_t value) {
        setUInt8(34, value);
    }

    uint8_t getTempSetpointHold() {
        return getEnum8(35);
    }

    void setTempSetpointHold(uint8_t value) {
        setEnum8(35, value);
    }

    uint16_t getTempSetpointHoldDuration() {
        return getUInt16(36);
    }

    void setTempSetpointHoldDuration(uint16_t value) {
        setUInt16(36, value);
    }

    uint8_t getProgramingOperMode() {
        return getMap8(37);
    }

    void setProgramingOperMode(uint8_t value) {
        setMap8(37, value);
    }

    uint16_t getRunningState() {
        return getMap16(41);
    }

    void setRunningState(uint16_t value) {
        setMap16(41, value);
    }

    uint8_t getSetpointChangeSource() {
        return getEnum8(48);
    }

    void setSetpointChangeSource(uint8_t value) {
        setEnum8(48, value);
    }

    int16_t getSetpointChangeAmount() {
        return getInt16(49);
    }

    void setSetpointChangeAmount(int16_t value) {
        setInt16(49, value);
    }

    uint32_t getSetpointChangeSourceTimeStamp() {
        return getUTC(50);
    }

    void setSetpointChangeSourceTimeStamp(uint32_t value) {
        setUTC(50, value);
    }

    uint8_t getAcType() {
        return getEnum8(64);
    }

    void setAcType(uint8_t value) {
        setEnum8(64, value);
    }

    uint16_t getAcCapacity() {
        return getUInt16(65);
    }

    void setAcCapacity(uint16_t value) {
        setUInt16(65, value);
    }

    uint8_t getAcRefrigerantType() {
        return getEnum8(66);
    }

    void setAcRefrigerantType(uint8_t value) {
        setEnum8(66, value);
    }

    uint8_t getAcConpressorType() {
        return getEnum8(67);
    }

    void setAcConpressorType(uint8_t value) {
        setEnum8(67, value);
    }

    uint32_t getAcErrorCode() {
        return getMap32(68);
    }

    void setAcErrorCode(uint32_t value) {
        setMap32(68, value);
    }

    uint8_t getAcLouverPosition() {
        return getEnum8(69);
    }

    void setAcLouverPosition(uint8_t value) {
        setEnum8(69, value);
    }

    int16_t getAcCollTemp() {
        return getInt16(70);
    }

    void setAcCollTemp(int16_t value) {
        setInt16(70, value);
    }

    uint8_t getAcCapacityFormat() {
        return getEnum8(71);
    }

    void setAcCapacityFormat(uint8_t value) {
        setEnum8(71, value);
    }

    uint8_t getStelproSystemMode() {
        return getEnum8(16412);
    }

    void setStelproSystemMode(uint8_t value) {
        setEnum8(16412, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto mode = request.readUInt8();
                auto amount = request.readInt8();
                auto status_ = setpointRaiseLowerCommand(mode, amount);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto daystoreturn = request.readUInt8();
                auto modetoreturn = request.readUInt8();
                auto status_ = getWeeklyScheduleCommand(daystoreturn, modetoreturn);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto status_ = clearWeeklyScheduleCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 4: {
                auto status_ = getRelayStatusLogCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 64: {
                auto setpointType = request.readUInt8();
                auto setpoint = request.readInt16Le();
                auto status_ = danfossSetpointCommandCommand(setpointType, setpoint);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 128: {
                auto command = request.readUInt8();
                auto enable = request.readUInt8();
                auto temperature = request.readUInt16Le();
                auto duration = request.readUInt16Le();
                auto status_ = schneiderWiserThermostatBoostCommand(command, enable, temperature, duration);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 224: {
                auto operatingmode = request.readUInt8();
                auto zonemode = request.readUInt8();
                auto setpoint = request.readInt16Le();
                auto reserved = request.readUInt8();
                auto status_ = wiserSmartSetSetpointCommand(operatingmode, zonemode, setpoint, reserved);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 226: {
                auto status_ = wiserSmartCalibrateValveCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 160: {
                auto status_ = plugwiseCalibrateValveCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class HvacFanCtrlCluster: public Cluster {
public:
    HvacFanCtrlCluster() : Cluster(514) {
    }

    uint8_t getFanMode() {
        return getEnum8(0);
    }

    void setFanMode(uint8_t value) {
        setEnum8(0, value);
    }

    uint8_t getFanModeSequence() {
        return getEnum8(1);
    }

    void setFanModeSequence(uint8_t value) {
        setEnum8(1, value);
    }
};

class HvacDehumidificationCtrlCluster: public Cluster {
public:
    HvacDehumidificationCtrlCluster() : Cluster(515) {
    }

    uint8_t getRelativeHumidity() {
        return getUInt8(0);
    }

    void setRelativeHumidity(uint8_t value) {
        setUInt8(0, value);
    }

    uint8_t getDehumidCooling() {
        return getUInt8(1);
    }

    void setDehumidCooling(uint8_t value) {
        setUInt8(1, value);
    }

    uint8_t getRhDehumidSetpoint() {
        return getUInt8(16);
    }

    void setRhDehumidSetpoint(uint8_t value) {
        setUInt8(16, value);
    }

    uint8_t getRelativeHumidityMode() {
        return getEnum8(17);
    }

    void setRelativeHumidityMode(uint8_t value) {
        setEnum8(17, value);
    }

    uint8_t getDehumidLockout() {
        return getEnum8(18);
    }

    void setDehumidLockout(uint8_t value) {
        setEnum8(18, value);
    }

    uint8_t getDehumidHysteresis() {
        return getUInt8(19);
    }

    void setDehumidHysteresis(uint8_t value) {
        setUInt8(19, value);
    }

    uint8_t getDehumidMaxCool() {
        return getUInt8(20);
    }

    void setDehumidMaxCool(uint8_t value) {
        setUInt8(20, value);
    }

    uint8_t getRelativeHumidDisplay() {
        return getEnum8(21);
    }

    void setRelativeHumidDisplay(uint8_t value) {
        setEnum8(21, value);
    }
};

class HvacUserInterfaceCfgCluster: public Cluster {
public:
    HvacUserInterfaceCfgCluster() : Cluster(516) {
    }

    uint8_t getTempDisplayMode() {
        return getEnum8(0);
    }

    void setTempDisplayMode(uint8_t value) {
        setEnum8(0, value);
    }

    uint8_t getKeypadLockout() {
        return getEnum8(1);
    }

    void setKeypadLockout(uint8_t value) {
        setEnum8(1, value);
    }

    uint8_t getProgrammingVisibility() {
        return getEnum8(2);
    }

    void setProgrammingVisibility(uint8_t value) {
        setEnum8(2, value);
    }
};

class LightingColorCtrlCluster: public Cluster {
public:
    LightingColorCtrlCluster() : Cluster(768) {
    }

    uint8_t getCurrentHue() {
        return getUInt8(0);
    }

    void setCurrentHue(uint8_t value) {
        setUInt8(0, value);
    }

    uint8_t getCurrentSaturation() {
        return getUInt8(1);
    }

    void setCurrentSaturation(uint8_t value) {
        setUInt8(1, value);
    }

    uint16_t getRemainingTime() {
        return getUInt16(2);
    }

    void setRemainingTime(uint16_t value) {
        setUInt16(2, value);
    }

    uint16_t getCurrentX() {
        return getUInt16(3);
    }

    void setCurrentX(uint16_t value) {
        setUInt16(3, value);
    }

    uint16_t getCurrentY() {
        return getUInt16(4);
    }

    void setCurrentY(uint16_t value) {
        setUInt16(4, value);
    }

    uint8_t getDriftCompensation() {
        return getEnum8(5);
    }

    void setDriftCompensation(uint8_t value) {
        setEnum8(5, value);
    }

    String getCompensationText() {
        return getString(6);
    }

    void setCompensationText(const String& value) {
        setString(6, value);
    }

    uint16_t getColorTemperature() {
        return getUInt16(7);
    }

    void setColorTemperature(uint16_t value) {
        setUInt16(7, value);
    }

    uint8_t getColorMode() {
        return getEnum8(8);
    }

    void setColorMode(uint8_t value) {
        setEnum8(8, value);
    }

    uint8_t getOptions() {
        return getMap8(15);
    }

    void setOptions(uint8_t value) {
        setMap8(15, value);
    }

    uint8_t getNumPrimaries() {
        return getUInt8(16);
    }

    void setNumPrimaries(uint8_t value) {
        setUInt8(16, value);
    }

    uint16_t getPrimary1X() {
        return getUInt16(17);
    }

    void setPrimary1X(uint16_t value) {
        setUInt16(17, value);
    }

    uint16_t getPrimary1Y() {
        return getUInt16(18);
    }

    void setPrimary1Y(uint16_t value) {
        setUInt16(18, value);
    }

    uint8_t getPrimary1Intensity() {
        return getUInt8(19);
    }

    void setPrimary1Intensity(uint8_t value) {
        setUInt8(19, value);
    }

    uint16_t getPrimary2X() {
        return getUInt16(21);
    }

    void setPrimary2X(uint16_t value) {
        setUInt16(21, value);
    }

    uint16_t getPrimary2Y() {
        return getUInt16(22);
    }

    void setPrimary2Y(uint16_t value) {
        setUInt16(22, value);
    }

    uint8_t getPrimary2Intensity() {
        return getUInt8(23);
    }

    void setPrimary2Intensity(uint8_t value) {
        setUInt8(23, value);
    }

    uint16_t getPrimary3X() {
        return getUInt16(25);
    }

    void setPrimary3X(uint16_t value) {
        setUInt16(25, value);
    }

    uint16_t getPrimary3Y() {
        return getUInt16(26);
    }

    void setPrimary3Y(uint16_t value) {
        setUInt16(26, value);
    }

    uint8_t getPrimary3Intensity() {
        return getUInt8(27);
    }

    void setPrimary3Intensity(uint8_t value) {
        setUInt8(27, value);
    }

    uint16_t getPrimary4X() {
        return getUInt16(32);
    }

    void setPrimary4X(uint16_t value) {
        setUInt16(32, value);
    }

    uint16_t getPrimary4Y() {
        return getUInt16(33);
    }

    void setPrimary4Y(uint16_t value) {
        setUInt16(33, value);
    }

    uint8_t getPrimary4Intensity() {
        return getUInt8(34);
    }

    void setPrimary4Intensity(uint8_t value) {
        setUInt8(34, value);
    }

    uint16_t getPrimary5X() {
        return getUInt16(36);
    }

    void setPrimary5X(uint16_t value) {
        setUInt16(36, value);
    }

    uint16_t getPrimary5Y() {
        return getUInt16(37);
    }

    void setPrimary5Y(uint16_t value) {
        setUInt16(37, value);
    }

    uint8_t getPrimary5Intensity() {
        return getUInt8(38);
    }

    void setPrimary5Intensity(uint8_t value) {
        setUInt8(38, value);
    }

    uint16_t getPrimary6X() {
        return getUInt16(40);
    }

    void setPrimary6X(uint16_t value) {
        setUInt16(40, value);
    }

    uint16_t getPrimary6Y() {
        return getUInt16(41);
    }

    void setPrimary6Y(uint16_t value) {
        setUInt16(41, value);
    }

    uint8_t getPrimary6Intensity() {
        return getUInt8(42);
    }

    void setPrimary6Intensity(uint8_t value) {
        setUInt8(42, value);
    }

    uint16_t getWhitePointX() {
        return getUInt16(48);
    }

    void setWhitePointX(uint16_t value) {
        setUInt16(48, value);
    }

    uint16_t getWhitePointY() {
        return getUInt16(49);
    }

    void setWhitePointY(uint16_t value) {
        setUInt16(49, value);
    }

    uint16_t getColorPointRX() {
        return getUInt16(50);
    }

    void setColorPointRX(uint16_t value) {
        setUInt16(50, value);
    }

    uint16_t getColorPointRY() {
        return getUInt16(51);
    }

    void setColorPointRY(uint16_t value) {
        setUInt16(51, value);
    }

    uint8_t getColorPointRIntensity() {
        return getUInt8(52);
    }

    void setColorPointRIntensity(uint8_t value) {
        setUInt8(52, value);
    }

    uint16_t getColorPointGX() {
        return getUInt16(54);
    }

    void setColorPointGX(uint16_t value) {
        setUInt16(54, value);
    }

    uint16_t getColorPointGY() {
        return getUInt16(55);
    }

    void setColorPointGY(uint16_t value) {
        setUInt16(55, value);
    }

    uint8_t getColorPointGIntensity() {
        return getUInt8(56);
    }

    void setColorPointGIntensity(uint8_t value) {
        setUInt8(56, value);
    }

    uint16_t getColorPointBX() {
        return getUInt16(58);
    }

    void setColorPointBX(uint16_t value) {
        setUInt16(58, value);
    }

    uint16_t getColorPointBY() {
        return getUInt16(59);
    }

    void setColorPointBY(uint16_t value) {
        setUInt16(59, value);
    }

    uint8_t getColorPointBIntensity() {
        return getUInt8(60);
    }

    void setColorPointBIntensity(uint8_t value) {
        setUInt8(60, value);
    }

    uint16_t getEnhancedCurrentHue() {
        return getUInt16(16384);
    }

    void setEnhancedCurrentHue(uint16_t value) {
        setUInt16(16384, value);
    }

    uint8_t getEnhancedColorMode() {
        return getEnum8(16385);
    }

    void setEnhancedColorMode(uint8_t value) {
        setEnum8(16385, value);
    }

    uint8_t getColorLoopActive() {
        return getUInt8(16386);
    }

    void setColorLoopActive(uint8_t value) {
        setUInt8(16386, value);
    }

    uint8_t getColorLoopDirection() {
        return getUInt8(16387);
    }

    void setColorLoopDirection(uint8_t value) {
        setUInt8(16387, value);
    }

    uint16_t getColorLoopTime() {
        return getUInt16(16388);
    }

    void setColorLoopTime(uint16_t value) {
        setUInt16(16388, value);
    }

    uint16_t getColorLoopStartEnhancedHue() {
        return getUInt16(16389);
    }

    void setColorLoopStartEnhancedHue(uint16_t value) {
        setUInt16(16389, value);
    }

    uint16_t getColorLoopStoredEnhancedHue() {
        return getUInt16(16390);
    }

    void setColorLoopStoredEnhancedHue(uint16_t value) {
        setUInt16(16390, value);
    }

    uint16_t getColorCapabilities() {
        return getUInt16(16394);
    }

    void setColorCapabilities(uint16_t value) {
        setUInt16(16394, value);
    }

    uint16_t getColorTempPhysicalMin() {
        return getUInt16(16395);
    }

    void setColorTempPhysicalMin(uint16_t value) {
        setUInt16(16395, value);
    }

    uint16_t getColorTempPhysicalMax() {
        return getUInt16(16396);
    }

    void setColorTempPhysicalMax(uint16_t value) {
        setUInt16(16396, value);
    }

    uint16_t getCoupleColorTempToLevelMin() {
        return getUInt16(16397);
    }

    void setCoupleColorTempToLevelMin(uint16_t value) {
        setUInt16(16397, value);
    }

    uint16_t getStartUpColorTemperature() {
        return getUInt16(16400);
    }

    void setStartUpColorTemperature(uint16_t value) {
        setUInt16(16400, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto hue = request.readUInt8();
                auto direction = request.readUInt8();
                auto transtime = request.readUInt16Le();
                auto status_ = moveToHueCommand(hue, direction, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto movemode = request.readUInt8();
                auto rate = request.readUInt8();
                auto status_ = moveHueCommand(movemode, rate);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto stepmode = request.readUInt8();
                auto stepsize = request.readUInt8();
                auto transtime = request.readUInt8();
                auto status_ = stepHueCommand(stepmode, stepsize, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto saturation = request.readUInt8();
                auto transtime = request.readUInt16Le();
                auto status_ = moveToSaturationCommand(saturation, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 4: {
                auto movemode = request.readUInt8();
                auto rate = request.readUInt8();
                auto status_ = moveSaturationCommand(movemode, rate);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 5: {
                auto stepmode = request.readUInt8();
                auto stepsize = request.readUInt8();
                auto transtime = request.readUInt8();
                auto status_ = stepSaturationCommand(stepmode, stepsize, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 6: {
                auto hue = request.readUInt8();
                auto saturation = request.readUInt8();
                auto transtime = request.readUInt16Le();
                auto status_ = moveToHueAndSaturationCommand(hue, saturation, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 7: {
                auto colorx = request.readUInt16Le();
                auto colory = request.readUInt16Le();
                auto transtime = request.readUInt16Le();
                auto status_ = moveToColorCommand(colorx, colory, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 8: {
                auto ratex = request.readInt16Le();
                auto ratey = request.readInt16Le();
                auto status_ = moveColorCommand(ratex, ratey);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 9: {
                auto stepx = request.readInt16Le();
                auto stepy = request.readInt16Le();
                auto transtime = request.readUInt16Le();
                auto status_ = stepColorCommand(stepx, stepy, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 10: {
                auto colortemp = request.readUInt16Le();
                auto transtime = request.readUInt16Le();
                auto status_ = moveToColorTempCommand(colortemp, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 64: {
                auto enhancehue = request.readUInt16Le();
                auto direction = request.readUInt8();
                auto transtime = request.readUInt16Le();
                auto status_ = enhancedMoveToHueCommand(enhancehue, direction, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 65: {
                auto movemode = request.readUInt8();
                auto rate = request.readUInt16Le();
                auto status_ = enhancedMoveHueCommand(movemode, rate);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 66: {
                auto stepmode = request.readUInt8();
                auto stepsize = request.readUInt16Le();
                auto transtime = request.readUInt16Le();
                auto status_ = enhancedStepHueCommand(stepmode, stepsize, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 67: {
                auto enhancehue = request.readUInt16Le();
                auto saturation = request.readUInt8();
                auto transtime = request.readUInt16Le();
                auto status_ = enhancedMoveToHueAndSaturationCommand(enhancehue, saturation, transtime);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 68: {
                auto updateflags = request.readUInt8();
                auto action = request.readUInt8();
                auto direction = request.readUInt8();
                auto time = request.readUInt16Le();
                auto starthue = request.readUInt16Le();
                auto status_ = colorLoopSetCommand(updateflags, action, direction, time, starthue);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 71: {
                auto bits = request.readUInt8();
                auto bytee = request.readUInt8();
                auto action = request.readUInt8();
                auto direction = request.readUInt8();
                auto time = request.readUInt16Le();
                auto starthue = request.readUInt16Le();
                auto status_ = stopMoveStepCommand(bits, bytee, action, direction, time, starthue);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 75: {
                auto movemode = request.readUInt8();
                auto rate = request.readUInt16Le();
                auto minimum = request.readUInt16Le();
                auto maximum = request.readUInt16Le();
                auto status_ = moveColorTempCommand(movemode, rate, minimum, maximum);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 76: {
                auto stepmode = request.readUInt8();
                auto stepsize = request.readUInt16Le();
                auto transtime = request.readUInt16Le();
                auto minimum = request.readUInt16Le();
                auto maximum = request.readUInt16Le();
                auto status_ = stepColorTempCommand(stepmode, stepsize, transtime, minimum, maximum);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class LightingBallastCfgCluster: public Cluster {
public:
    LightingBallastCfgCluster() : Cluster(769) {
    }

    uint8_t getPhysicalMinLevel() {
        return getUInt8(0);
    }

    void setPhysicalMinLevel(uint8_t value) {
        setUInt8(0, value);
    }

    uint8_t getPhysicalMaxLevel() {
        return getUInt8(1);
    }

    void setPhysicalMaxLevel(uint8_t value) {
        setUInt8(1, value);
    }

    uint8_t getBallastStatus() {
        return getMap8(2);
    }

    void setBallastStatus(uint8_t value) {
        setMap8(2, value);
    }

    uint8_t getMinLevel() {
        return getUInt8(16);
    }

    void setMinLevel(uint8_t value) {
        setUInt8(16, value);
    }

    uint8_t getMaxLevel() {
        return getUInt8(17);
    }

    void setMaxLevel(uint8_t value) {
        setUInt8(17, value);
    }

    uint8_t getPowerOnLevel() {
        return getUInt8(18);
    }

    void setPowerOnLevel(uint8_t value) {
        setUInt8(18, value);
    }

    uint16_t getPowerOnFadeTime() {
        return getUInt16(19);
    }

    void setPowerOnFadeTime(uint16_t value) {
        setUInt16(19, value);
    }

    uint8_t getIntrinsicBallastFactor() {
        return getUInt8(20);
    }

    void setIntrinsicBallastFactor(uint8_t value) {
        setUInt8(20, value);
    }

    uint8_t getBallastFactorAdjustment() {
        return getUInt8(21);
    }

    void setBallastFactorAdjustment(uint8_t value) {
        setUInt8(21, value);
    }

    uint8_t getLampQuantity() {
        return getUInt8(32);
    }

    void setLampQuantity(uint8_t value) {
        setUInt8(32, value);
    }

    String getLampType() {
        return getString(48);
    }

    void setLampType(const String& value) {
        setString(48, value);
    }

    String getLampManufacturer() {
        return getString(49);
    }

    void setLampManufacturer(const String& value) {
        setString(49, value);
    }

    uint32_t getLampRatedHours() {
        return getUInt24(50);
    }

    void setLampRatedHours(uint32_t value) {
        setUInt24(50, value);
    }

    uint32_t getLampBurnHours() {
        return getUInt24(51);
    }

    void setLampBurnHours(uint32_t value) {
        setUInt24(51, value);
    }

    uint8_t getLampAlarmMode() {
        return getMap8(52);
    }

    void setLampAlarmMode(uint8_t value) {
        setMap8(52, value);
    }

    uint32_t getLampBurnHoursTripPoint() {
        return getUInt24(53);
    }

    void setLampBurnHoursTripPoint(uint32_t value) {
        setUInt24(53, value);
    }
};

class MsIlluminanceMeasurementCluster: public Cluster {
public:
    MsIlluminanceMeasurementCluster() : Cluster(1024) {
    }

    uint16_t getMeasuredValue() {
        return getUInt16(0);
    }

    void setMeasuredValue(uint16_t value) {
        setUInt16(0, value);
    }

    uint16_t getMinMeasuredValue() {
        return getUInt16(1);
    }

    void setMinMeasuredValue(uint16_t value) {
        setUInt16(1, value);
    }

    uint16_t getMaxMeasuredValue() {
        return getUInt16(2);
    }

    void setMaxMeasuredValue(uint16_t value) {
        setUInt16(2, value);
    }

    uint16_t getTolerance() {
        return getUInt16(3);
    }

    void setTolerance(uint16_t value) {
        setUInt16(3, value);
    }

    uint8_t getLightSensorType() {
        return getEnum8(4);
    }

    void setLightSensorType(uint8_t value) {
        setEnum8(4, value);
    }
};

class MsIlluminanceLevelSensingCluster: public Cluster {
public:
    MsIlluminanceLevelSensingCluster() : Cluster(1025) {
    }

    uint8_t getLevelStatus() {
        return getEnum8(0);
    }

    void setLevelStatus(uint8_t value) {
        setEnum8(0, value);
    }

    uint8_t getLightSensorType() {
        return getEnum8(1);
    }

    void setLightSensorType(uint8_t value) {
        setEnum8(1, value);
    }

    uint16_t getIlluminanceTargetLevel() {
        return getUInt16(16);
    }

    void setIlluminanceTargetLevel(uint16_t value) {
        setUInt16(16, value);
    }
};

class MsTemperatureMeasurementCluster: public Cluster {
public:
    MsTemperatureMeasurementCluster() : Cluster(1026) {
    }

    int16_t getMeasuredValue() {
        return getInt16(0);
    }

    void setMeasuredValue(int16_t value) {
        setInt16(0, value);
    }

    int16_t getMinMeasuredValue() {
        return getInt16(1);
    }

    void setMinMeasuredValue(int16_t value) {
        setInt16(1, value);
    }

    int16_t getMaxMeasuredValue() {
        return getInt16(2);
    }

    void setMaxMeasuredValue(int16_t value) {
        setInt16(2, value);
    }

    uint16_t getTolerance() {
        return getUInt16(3);
    }

    void setTolerance(uint16_t value) {
        setUInt16(3, value);
    }
};

class MsPressureMeasurementCluster: public Cluster {
public:
    MsPressureMeasurementCluster() : Cluster(1027) {
    }

    int16_t getMeasuredValue() {
        return getInt16(0);
    }

    void setMeasuredValue(int16_t value) {
        setInt16(0, value);
    }

    int16_t getMinMeasuredValue() {
        return getInt16(1);
    }

    void setMinMeasuredValue(int16_t value) {
        setInt16(1, value);
    }

    int16_t getMaxMeasuredValue() {
        return getInt16(2);
    }

    void setMaxMeasuredValue(int16_t value) {
        setInt16(2, value);
    }

    uint16_t getTolerance() {
        return getUInt16(3);
    }

    void setTolerance(uint16_t value) {
        setUInt16(3, value);
    }

    int16_t getScaledValue() {
        return getInt16(16);
    }

    void setScaledValue(int16_t value) {
        setInt16(16, value);
    }

    int16_t getMinScaledValue() {
        return getInt16(17);
    }

    void setMinScaledValue(int16_t value) {
        setInt16(17, value);
    }

    int16_t getMaxScaledValue() {
        return getInt16(18);
    }

    void setMaxScaledValue(int16_t value) {
        setInt16(18, value);
    }

    uint16_t getScaledTolerance() {
        return getUInt16(19);
    }

    void setScaledTolerance(uint16_t value) {
        setUInt16(19, value);
    }

    int8_t getScale() {
        return getInt8(20);
    }

    void setScale(int8_t value) {
        setInt8(20, value);
    }
};

class MsFlowMeasurementCluster: public Cluster {
public:
    MsFlowMeasurementCluster() : Cluster(1028) {
    }

    uint16_t getMeasuredValue() {
        return getUInt16(0);
    }

    void setMeasuredValue(uint16_t value) {
        setUInt16(0, value);
    }

    uint16_t getMinMeasuredValue() {
        return getUInt16(1);
    }

    void setMinMeasuredValue(uint16_t value) {
        setUInt16(1, value);
    }

    uint16_t getMaxMeasuredValue() {
        return getUInt16(2);
    }

    void setMaxMeasuredValue(uint16_t value) {
        setUInt16(2, value);
    }

    uint16_t getTolerance() {
        return getUInt16(3);
    }

    void setTolerance(uint16_t value) {
        setUInt16(3, value);
    }
};

class MsRelativeHumidityCluster: public Cluster {
public:
    MsRelativeHumidityCluster() : Cluster(1029) {
    }

    uint16_t getMeasuredValue() {
        return getUInt16(0);
    }

    void setMeasuredValue(uint16_t value) {
        setUInt16(0, value);
    }

    uint16_t getMinMeasuredValue() {
        return getUInt16(1);
    }

    void setMinMeasuredValue(uint16_t value) {
        setUInt16(1, value);
    }

    uint16_t getMaxMeasuredValue() {
        return getUInt16(2);
    }

    void setMaxMeasuredValue(uint16_t value) {
        setUInt16(2, value);
    }

    uint16_t getTolerance() {
        return getUInt16(3);
    }

    void setTolerance(uint16_t value) {
        setUInt16(3, value);
    }
};

class MsOccupancySensingCluster: public Cluster {
public:
    MsOccupancySensingCluster() : Cluster(1030) {
    }

    uint8_t getOccupancy() {
        return getMap8(0);
    }

    void setOccupancy(uint8_t value) {
        setMap8(0, value);
    }

    uint8_t getOccupancySensorType() {
        return getEnum8(1);
    }

    void setOccupancySensorType(uint8_t value) {
        setEnum8(1, value);
    }

    uint16_t getPirOToUDelay() {
        return getUInt16(16);
    }

    void setPirOToUDelay(uint16_t value) {
        setUInt16(16, value);
    }

    uint16_t getPirUToODelay() {
        return getUInt16(17);
    }

    void setPirUToODelay(uint16_t value) {
        setUInt16(17, value);
    }

    uint8_t getPirUToOThreshold() {
        return getUInt8(18);
    }

    void setPirUToOThreshold(uint8_t value) {
        setUInt8(18, value);
    }

    uint16_t getUltrasonicOToUDelay() {
        return getUInt16(32);
    }

    void setUltrasonicOToUDelay(uint16_t value) {
        setUInt16(32, value);
    }

    uint16_t getUltrasonicUToODelay() {
        return getUInt16(33);
    }

    void setUltrasonicUToODelay(uint16_t value) {
        setUInt16(33, value);
    }

    uint8_t getUltrasonicUToOThreshold() {
        return getUInt8(34);
    }

    void setUltrasonicUToOThreshold(uint8_t value) {
        setUInt8(34, value);
    }
};

class MsSoilMoistureCluster: public Cluster {
public:
    MsSoilMoistureCluster() : Cluster(1032) {
    }

    uint16_t getMeasuredValue() {
        return getUInt16(0);
    }

    void setMeasuredValue(uint16_t value) {
        setUInt16(0, value);
    }

    uint16_t getMinMeasuredValue() {
        return getUInt16(1);
    }

    void setMinMeasuredValue(uint16_t value) {
        setUInt16(1, value);
    }

    uint16_t getMaxMeasuredValue() {
        return getUInt16(2);
    }

    void setMaxMeasuredValue(uint16_t value) {
        setUInt16(2, value);
    }

    uint16_t getTolerance() {
        return getUInt16(3);
    }

    void setTolerance(uint16_t value) {
        setUInt16(3, value);
    }
};

class PHMeasurementCluster: public Cluster {
public:
    PHMeasurementCluster() : Cluster(1033) {
    }

    uint16_t getMeasuredValue() {
        return getUInt16(0);
    }

    void setMeasuredValue(uint16_t value) {
        setUInt16(0, value);
    }

    uint16_t getMinMeasuredValue() {
        return getUInt16(1);
    }

    void setMinMeasuredValue(uint16_t value) {
        setUInt16(1, value);
    }

    uint16_t getMaxMeasuredValue() {
        return getUInt16(2);
    }

    void setMaxMeasuredValue(uint16_t value) {
        setUInt16(2, value);
    }

    uint16_t getTolerance() {
        return getUInt16(3);
    }

    void setTolerance(uint16_t value) {
        setUInt16(3, value);
    }
};

class MsCO2Cluster: public Cluster {
public:
    MsCO2Cluster() : Cluster(1037) {
    }

    float getMeasuredValue() {
        return getSingle(0);
    }

    void setMeasuredValue(float value) {
        setSingle(0, value);
    }

    float getMinMeasuredValue() {
        return getSingle(1);
    }

    void setMinMeasuredValue(float value) {
        setSingle(1, value);
    }

    float getMaxMeasuredValue() {
        return getSingle(2);
    }

    void setMaxMeasuredValue(float value) {
        setSingle(2, value);
    }
};

class SsIasZoneCluster: public Cluster {
public:
    SsIasZoneCluster() : Cluster(1280) {
    }

    uint8_t getZoneState() {
        return getEnum8(0);
    }

    void setZoneState(uint8_t value) {
        setEnum8(0, value);
    }

    uint16_t getZoneType() {
        return getEnum16(1);
    }

    void setZoneType(uint16_t value) {
        setEnum16(1, value);
    }

    uint16_t getZoneStatus() {
        return getMap16(2);
    }

    void setZoneStatus(uint16_t value) {
        setMap16(2, value);
    }

    uint64_t getIasCieAddr() {
        return getEUI64(16);
    }

    void setIasCieAddr(uint64_t value) {
        setEUI64(16, value);
    }

    uint8_t getZoneId() {
        return getUInt8(17);
    }

    void setZoneId(uint8_t value) {
        setUInt8(17, value);
    }

    uint8_t getNumZoneSensitivityLevelsSupported() {
        return getUInt8(18);
    }

    void setNumZoneSensitivityLevelsSupported(uint8_t value) {
        setUInt8(18, value);
    }

    uint8_t getCurrentZoneSensitivityLevel() {
        return getUInt8(19);
    }

    void setCurrentZoneSensitivityLevel(uint8_t value) {
        setUInt8(19, value);
    }

    virtual Status enrollRspCommand(uint8_t enrollrspcode, uint8_t zoneid) {
        return Status::UnsupportedAttribute;
    }

    virtual Status initNormalOpModeCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status initTestModeCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto enrollrspcode = request.readUInt8();
                auto zoneid = request.readUInt8();
                auto status_ = enrollRspCommand(enrollrspcode, zoneid);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto status_ = initNormalOpModeCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto status_ = initTestModeCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class SsIasAceCluster: public Cluster {
public:
    SsIasAceCluster() : Cluster(1281) {
    }

    class ArmCommandResponse {
        uint8_t _armnotification{};

    public:
        uint8_t getArmnotification() { return _armnotification; }
        void setArmnotification(uint8_t value) { _armnotification = value; }

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
        void setZoneidmapsection0(uint16_t value) { _zoneidmapsection0 = value; }

        uint16_t getZoneidmapsection1() { return _zoneidmapsection1; }
        void setZoneidmapsection1(uint16_t value) { _zoneidmapsection1 = value; }

        uint16_t getZoneidmapsection2() { return _zoneidmapsection2; }
        void setZoneidmapsection2(uint16_t value) { _zoneidmapsection2 = value; }

        uint16_t getZoneidmapsection3() { return _zoneidmapsection3; }
        void setZoneidmapsection3(uint16_t value) { _zoneidmapsection3 = value; }

        uint16_t getZoneidmapsection4() { return _zoneidmapsection4; }
        void setZoneidmapsection4(uint16_t value) { _zoneidmapsection4 = value; }

        uint16_t getZoneidmapsection5() { return _zoneidmapsection5; }
        void setZoneidmapsection5(uint16_t value) { _zoneidmapsection5 = value; }

        uint16_t getZoneidmapsection6() { return _zoneidmapsection6; }
        void setZoneidmapsection6(uint16_t value) { _zoneidmapsection6 = value; }

        uint16_t getZoneidmapsection7() { return _zoneidmapsection7; }
        void setZoneidmapsection7(uint16_t value) { _zoneidmapsection7 = value; }

        uint16_t getZoneidmapsection8() { return _zoneidmapsection8; }
        void setZoneidmapsection8(uint16_t value) { _zoneidmapsection8 = value; }

        uint16_t getZoneidmapsection9() { return _zoneidmapsection9; }
        void setZoneidmapsection9(uint16_t value) { _zoneidmapsection9 = value; }

        uint16_t getZoneidmapsection10() { return _zoneidmapsection10; }
        void setZoneidmapsection10(uint16_t value) { _zoneidmapsection10 = value; }

        uint16_t getZoneidmapsection11() { return _zoneidmapsection11; }
        void setZoneidmapsection11(uint16_t value) { _zoneidmapsection11 = value; }

        uint16_t getZoneidmapsection12() { return _zoneidmapsection12; }
        void setZoneidmapsection12(uint16_t value) { _zoneidmapsection12 = value; }

        uint16_t getZoneidmapsection13() { return _zoneidmapsection13; }
        void setZoneidmapsection13(uint16_t value) { _zoneidmapsection13 = value; }

        uint16_t getZoneidmapsection14() { return _zoneidmapsection14; }
        void setZoneidmapsection14(uint16_t value) { _zoneidmapsection14 = value; }

        uint16_t getZoneidmapsection15() { return _zoneidmapsection15; }
        void setZoneidmapsection15(uint16_t value) { _zoneidmapsection15 = value; }

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
        void setZoneid(uint8_t value) { _zoneid = value; }

        uint16_t getZonetype() { return _zonetype; }
        void setZonetype(uint16_t value) { _zonetype = value; }

        uint64_t getIeeeaddr() { return _ieeeaddr; }
        void setIeeeaddr(uint64_t value) { _ieeeaddr = value; }

        String getZonelabel() { return _zonelabel; }
        void setZonelabel(const String& value) { _zonelabel = value; }

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
        void setPanelstatus(uint8_t value) { _panelstatus = value; }

        uint8_t getSecondsremain() { return _secondsremain; }
        void setSecondsremain(uint8_t value) { _secondsremain = value; }

        uint8_t getAudiblenotif() { return _audiblenotif; }
        void setAudiblenotif(uint8_t value) { _audiblenotif = value; }

        uint8_t getAlarmstatus() { return _alarmstatus; }
        void setAlarmstatus(uint8_t value) { _alarmstatus = value; }

    };

    virtual Status getPanelStatusCommand(GetPanelStatusCommandResponse& response) {
        return Status::UnsupportedAttribute;
    }

    virtual Status getBypassedZoneListCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto armmode = request.readUInt8();
                auto code = request.readString();
                auto zoneid = request.readUInt8();
                ArmCommandResponse response_;
                auto status_ = armCommand(armmode, code, zoneid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getArmnotification());
                }
                return;
            }
            case 2: {
                auto status_ = emergencyCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto status_ = fireCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 4: {
                auto status_ = panicCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 5: {
                GetZoneIDMapCommandResponse response_;
                auto status_ = getZoneIDMapCommand(response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt16Le(response_.getZoneidmapsection0());
                    response.writeUInt16Le(response_.getZoneidmapsection1());
                    response.writeUInt16Le(response_.getZoneidmapsection2());
                    response.writeUInt16Le(response_.getZoneidmapsection3());
                    response.writeUInt16Le(response_.getZoneidmapsection4());
                    response.writeUInt16Le(response_.getZoneidmapsection5());
                    response.writeUInt16Le(response_.getZoneidmapsection6());
                    response.writeUInt16Le(response_.getZoneidmapsection7());
                    response.writeUInt16Le(response_.getZoneidmapsection8());
                    response.writeUInt16Le(response_.getZoneidmapsection9());
                    response.writeUInt16Le(response_.getZoneidmapsection10());
                    response.writeUInt16Le(response_.getZoneidmapsection11());
                    response.writeUInt16Le(response_.getZoneidmapsection12());
                    response.writeUInt16Le(response_.getZoneidmapsection13());
                    response.writeUInt16Le(response_.getZoneidmapsection14());
                    response.writeUInt16Le(response_.getZoneidmapsection15());
                }
                return;
            }
            case 6: {
                auto zoneid = request.readUInt8();
                GetZoneInfoCommandResponse response_;
                auto status_ = getZoneInfoCommand(zoneid, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getZoneid());
                    response.writeUInt16Le(response_.getZonetype());
                    response.writeUInt64Le(response_.getIeeeaddr());
                    response.writeString(response_.getZonelabel());
                }
                return;
            }
            case 7: {
                GetPanelStatusCommandResponse response_;
                auto status_ = getPanelStatusCommand(response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt8(response_.getPanelstatus());
                    response.writeUInt8(response_.getSecondsremain());
                    response.writeUInt8(response_.getAudiblenotif());
                    response.writeUInt8(response_.getAlarmstatus());
                }
                return;
            }
            case 8: {
                auto status_ = getBypassedZoneListCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class SsIasWdCluster: public Cluster {
public:
    SsIasWdCluster() : Cluster(1282) {
    }

    uint16_t getMaxDuration() {
        return getUInt16(0);
    }

    void setMaxDuration(uint16_t value) {
        setUInt16(0, value);
    }

    virtual Status startWarningCommand(uint8_t startwarninginfo, uint16_t warningduration, uint8_t strobedutycycle, uint8_t strobelevel) {
        return Status::UnsupportedAttribute;
    }

    virtual Status squawkCommand(uint8_t squawkinfo) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto startwarninginfo = request.readUInt8();
                auto warningduration = request.readUInt16Le();
                auto strobedutycycle = request.readUInt8();
                auto strobelevel = request.readUInt8();
                auto status_ = startWarningCommand(startwarninginfo, warningduration, strobedutycycle, strobelevel);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto squawkinfo = request.readUInt8();
                auto status_ = squawkCommand(squawkinfo);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class PiGenericTunnelCluster: public Cluster {
public:
    PiGenericTunnelCluster() : Cluster(1536) {
    }

    uint16_t getMaxIncomeTransSize() {
        return getUInt16(1);
    }

    void setMaxIncomeTransSize(uint16_t value) {
        setUInt16(1, value);
    }

    uint16_t getMaxOutgoTransSize() {
        return getUInt16(2);
    }

    void setMaxOutgoTransSize(uint16_t value) {
        setUInt16(2, value);
    }

    Buffer getProtocolAddr() {
        return getOctstr(3);
    }

    void setProtocolAddr(const Buffer& value) {
        setOctstr(3, value);
    }

    virtual Status matchProtocolAddrCommand(String protocoladdr) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto protocoladdr = request.readString();
                auto status_ = matchProtocolAddrCommand(protocoladdr);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class PiBacnetProtocolTunnelCluster: public Cluster {
public:
    PiBacnetProtocolTunnelCluster() : Cluster(1537) {
    }

    virtual Status transferNpduCommand(uint8_t npdu) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto npdu = request.readUInt8();
                auto status_ = transferNpduCommand(npdu);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class PiAnalogInputRegCluster: public Cluster {
public:
    PiAnalogInputRegCluster() : Cluster(1538) {
    }

    float getCovIncrement() {
        return getSingle(22);
    }

    void setCovIncrement(float value) {
        setSingle(22, value);
    }

    String getDeviceType() {
        return getString(31);
    }

    void setDeviceType(const String& value) {
        setString(31, value);
    }

    uint32_t getObjectId() {
        return getBacOID(75);
    }

    void setObjectId(uint32_t value) {
        setBacOID(75, value);
    }

    String getObjectName() {
        return getString(77);
    }

    void setObjectName(const String& value) {
        setString(77, value);
    }

    uint16_t getObjectType() {
        return getEnum16(79);
    }

    void setObjectType(uint16_t value) {
        setEnum16(79, value);
    }

    uint8_t getUpdateInterval() {
        return getUInt8(118);
    }

    void setUpdateInterval(uint8_t value) {
        setUInt8(118, value);
    }

    String getProfileName() {
        return getString(168);
    }

    void setProfileName(const String& value) {
        setString(168, value);
    }
};

class PiAnalogInputExtCluster: public Cluster {
public:
    PiAnalogInputExtCluster() : Cluster(1539) {
    }

    uint8_t getAckedTransitions() {
        return getMap8(0);
    }

    void setAckedTransitions(uint8_t value) {
        setMap8(0, value);
    }

    uint16_t getNotificationClass() {
        return getUInt16(17);
    }

    void setNotificationClass(uint16_t value) {
        setUInt16(17, value);
    }

    float getDeadband() {
        return getSingle(25);
    }

    void setDeadband(float value) {
        setSingle(25, value);
    }

    uint8_t getEventEnable() {
        return getMap8(35);
    }

    void setEventEnable(uint8_t value) {
        setMap8(35, value);
    }

    uint8_t getEventState() {
        return getEnum8(36);
    }

    void setEventState(uint8_t value) {
        setEnum8(36, value);
    }

    float getHighLimit() {
        return getSingle(45);
    }

    void setHighLimit(float value) {
        setSingle(45, value);
    }

    uint8_t getLimitEnable() {
        return getMap8(52);
    }

    void setLimitEnable(uint8_t value) {
        setMap8(52, value);
    }

    float getLowLimit() {
        return getSingle(59);
    }

    void setLowLimit(float value) {
        setSingle(59, value);
    }

    uint8_t getNotifyType() {
        return getEnum8(72);
    }

    void setNotifyType(uint8_t value) {
        setEnum8(72, value);
    }

    uint8_t getTimeDelay() {
        return getUInt8(113);
    }

    void setTimeDelay(uint8_t value) {
        setUInt8(113, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto status_ = transferApduCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto status_ = connectReqCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto status_ = disconnectReqCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto status_ = connectStatusNotiCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class PiAnalogOutputRegCluster: public Cluster {
public:
    PiAnalogOutputRegCluster() : Cluster(1540) {
    }

    float getCovIncrement() {
        return getSingle(22);
    }

    void setCovIncrement(float value) {
        setSingle(22, value);
    }

    String getDeviceType() {
        return getString(31);
    }

    void setDeviceType(const String& value) {
        setString(31, value);
    }

    uint32_t getObjectId() {
        return getBacOID(75);
    }

    void setObjectId(uint32_t value) {
        setBacOID(75, value);
    }

    String getObjectName() {
        return getString(77);
    }

    void setObjectName(const String& value) {
        setString(77, value);
    }

    uint16_t getObjectType() {
        return getEnum16(79);
    }

    void setObjectType(uint16_t value) {
        setEnum16(79, value);
    }

    uint8_t getUpdateInterval() {
        return getUInt8(118);
    }

    void setUpdateInterval(uint8_t value) {
        setUInt8(118, value);
    }

    String getProfileName() {
        return getString(168);
    }

    void setProfileName(const String& value) {
        setString(168, value);
    }
};

class PiAnalogOutputExtCluster: public Cluster {
public:
    PiAnalogOutputExtCluster() : Cluster(1541) {
    }

    uint8_t getAckedTransitions() {
        return getMap8(0);
    }

    void setAckedTransitions(uint8_t value) {
        setMap8(0, value);
    }

    uint16_t getNotificationClass() {
        return getUInt16(17);
    }

    void setNotificationClass(uint16_t value) {
        setUInt16(17, value);
    }

    float getDeadband() {
        return getSingle(25);
    }

    void setDeadband(float value) {
        setSingle(25, value);
    }

    uint8_t getEventEnable() {
        return getMap8(35);
    }

    void setEventEnable(uint8_t value) {
        setMap8(35, value);
    }

    uint8_t getEventState() {
        return getEnum8(36);
    }

    void setEventState(uint8_t value) {
        setEnum8(36, value);
    }

    float getHighLimit() {
        return getSingle(45);
    }

    void setHighLimit(float value) {
        setSingle(45, value);
    }

    uint8_t getLimitEnable() {
        return getMap8(52);
    }

    void setLimitEnable(uint8_t value) {
        setMap8(52, value);
    }

    float getLowLimit() {
        return getSingle(59);
    }

    void setLowLimit(float value) {
        setSingle(59, value);
    }

    uint8_t getNotifyType() {
        return getEnum8(72);
    }

    void setNotifyType(uint8_t value) {
        setEnum8(72, value);
    }

    uint8_t getTimeDelay() {
        return getUInt8(113);
    }

    void setTimeDelay(uint8_t value) {
        setUInt8(113, value);
    }
};

class PiAnalogValueRegCluster: public Cluster {
public:
    PiAnalogValueRegCluster() : Cluster(1542) {
    }

    float getCovIncrement() {
        return getSingle(22);
    }

    void setCovIncrement(float value) {
        setSingle(22, value);
    }

    uint32_t getObjectId() {
        return getBacOID(75);
    }

    void setObjectId(uint32_t value) {
        setBacOID(75, value);
    }

    String getObjectName() {
        return getString(77);
    }

    void setObjectName(const String& value) {
        setString(77, value);
    }

    uint16_t getObjectType() {
        return getEnum16(79);
    }

    void setObjectType(uint16_t value) {
        setEnum16(79, value);
    }

    String getProfileName() {
        return getString(168);
    }

    void setProfileName(const String& value) {
        setString(168, value);
    }
};

class PiAnalogValueExtCluster: public Cluster {
public:
    PiAnalogValueExtCluster() : Cluster(1543) {
    }

    uint8_t getAckedTransitions() {
        return getMap8(0);
    }

    void setAckedTransitions(uint8_t value) {
        setMap8(0, value);
    }

    uint16_t getNotificationClass() {
        return getUInt16(17);
    }

    void setNotificationClass(uint16_t value) {
        setUInt16(17, value);
    }

    float getDeadband() {
        return getSingle(25);
    }

    void setDeadband(float value) {
        setSingle(25, value);
    }

    uint8_t getEventEnable() {
        return getMap8(35);
    }

    void setEventEnable(uint8_t value) {
        setMap8(35, value);
    }

    uint8_t getEventState() {
        return getEnum8(36);
    }

    void setEventState(uint8_t value) {
        setEnum8(36, value);
    }

    float getHighLimit() {
        return getSingle(45);
    }

    void setHighLimit(float value) {
        setSingle(45, value);
    }

    uint8_t getLimitEnable() {
        return getMap8(52);
    }

    void setLimitEnable(uint8_t value) {
        setMap8(52, value);
    }

    float getLowLimit() {
        return getSingle(59);
    }

    void setLowLimit(float value) {
        setSingle(59, value);
    }

    uint8_t getNotifyType() {
        return getEnum8(72);
    }

    void setNotifyType(uint8_t value) {
        setEnum8(72, value);
    }

    uint8_t getTimeDelay() {
        return getUInt8(113);
    }

    void setTimeDelay(uint8_t value) {
        setUInt8(113, value);
    }
};

class PiBinaryInputRegCluster: public Cluster {
public:
    PiBinaryInputRegCluster() : Cluster(1544) {
    }

    uint32_t getChangeOfStateCount() {
        return getUInt32(15);
    }

    void setChangeOfStateCount(uint32_t value) {
        setUInt32(15, value);
    }

    DateTime getChangeOfStateTime() {
        return getDateTime(16);
    }

    void setChangeOfStateTime(const DateTime& value) {
        setDateTime(16, value);
    }

    String getDeviceType() {
        return getString(31);
    }

    void setDeviceType(const String& value) {
        setString(31, value);
    }

    uint32_t getElapsedActiveTime() {
        return getUInt32(33);
    }

    void setElapsedActiveTime(uint32_t value) {
        setUInt32(33, value);
    }

    uint32_t getObjectIdentifier() {
        return getBacOID(75);
    }

    void setObjectIdentifier(uint32_t value) {
        setBacOID(75, value);
    }

    String getObjectName() {
        return getString(77);
    }

    void setObjectName(const String& value) {
        setString(77, value);
    }

    uint16_t getObjectType() {
        return getEnum16(79);
    }

    void setObjectType(uint16_t value) {
        setEnum16(79, value);
    }

    DateTime getTimeOfATReset() {
        return getDateTime(114);
    }

    void setTimeOfATReset(const DateTime& value) {
        setDateTime(114, value);
    }

    DateTime getTimeOfSCReset() {
        return getDateTime(115);
    }

    void setTimeOfSCReset(const DateTime& value) {
        setDateTime(115, value);
    }

    String getProfileName() {
        return getString(168);
    }

    void setProfileName(const String& value) {
        setString(168, value);
    }
};

class PiBinaryInputExtCluster: public Cluster {
public:
    PiBinaryInputExtCluster() : Cluster(1545) {
    }

    uint8_t getAckedTransitions() {
        return getMap8(0);
    }

    void setAckedTransitions(uint8_t value) {
        setMap8(0, value);
    }

    bool getAlarmValue() {
        return getBool(6);
    }

    void setAlarmValue(bool value) {
        setBool(6, value);
    }

    uint16_t getNotificationClass() {
        return getUInt16(17);
    }

    void setNotificationClass(uint16_t value) {
        setUInt16(17, value);
    }

    uint8_t getEventEnable() {
        return getMap8(35);
    }

    void setEventEnable(uint8_t value) {
        setMap8(35, value);
    }

    uint8_t getEventState() {
        return getEnum8(36);
    }

    void setEventState(uint8_t value) {
        setEnum8(36, value);
    }

    uint8_t getNotifyType() {
        return getEnum8(72);
    }

    void setNotifyType(uint8_t value) {
        setEnum8(72, value);
    }

    uint8_t getTimeDelay() {
        return getUInt8(113);
    }

    void setTimeDelay(uint8_t value) {
        setUInt8(113, value);
    }
};

class PiBinaryOutputRegCluster: public Cluster {
public:
    PiBinaryOutputRegCluster() : Cluster(1546) {
    }

    uint32_t getChangeOfStateCount() {
        return getUInt32(15);
    }

    void setChangeOfStateCount(uint32_t value) {
        setUInt32(15, value);
    }

    DateTime getChangeOfStateTime() {
        return getDateTime(16);
    }

    void setChangeOfStateTime(const DateTime& value) {
        setDateTime(16, value);
    }

    String getDeviceType() {
        return getString(31);
    }

    void setDeviceType(const String& value) {
        setString(31, value);
    }

    uint32_t getElapsedActiveTime() {
        return getUInt32(33);
    }

    void setElapsedActiveTime(uint32_t value) {
        setUInt32(33, value);
    }

    uint8_t getFeedBackValue() {
        return getEnum8(40);
    }

    void setFeedBackValue(uint8_t value) {
        setEnum8(40, value);
    }

    uint32_t getObjectIdentifier() {
        return getBacOID(75);
    }

    void setObjectIdentifier(uint32_t value) {
        setBacOID(75, value);
    }

    String getObjectName() {
        return getString(77);
    }

    void setObjectName(const String& value) {
        setString(77, value);
    }

    uint16_t getObjectType() {
        return getEnum16(79);
    }

    void setObjectType(uint16_t value) {
        setEnum16(79, value);
    }

    DateTime getTimeOfATReset() {
        return getDateTime(114);
    }

    void setTimeOfATReset(const DateTime& value) {
        setDateTime(114, value);
    }

    DateTime getTimeOfSCReset() {
        return getDateTime(115);
    }

    void setTimeOfSCReset(const DateTime& value) {
        setDateTime(115, value);
    }

    String getProfileName() {
        return getString(168);
    }

    void setProfileName(const String& value) {
        setString(168, value);
    }
};

class PiBinaryOutputExtCluster: public Cluster {
public:
    PiBinaryOutputExtCluster() : Cluster(1547) {
    }

    uint8_t getAckedTransitions() {
        return getMap8(0);
    }

    void setAckedTransitions(uint8_t value) {
        setMap8(0, value);
    }

    uint16_t getNotificationClass() {
        return getUInt16(17);
    }

    void setNotificationClass(uint16_t value) {
        setUInt16(17, value);
    }

    uint8_t getEventEnable() {
        return getMap8(35);
    }

    void setEventEnable(uint8_t value) {
        setMap8(35, value);
    }

    uint8_t getEventState() {
        return getEnum8(36);
    }

    void setEventState(uint8_t value) {
        setEnum8(36, value);
    }

    uint8_t getNotifyType() {
        return getEnum8(72);
    }

    void setNotifyType(uint8_t value) {
        setEnum8(72, value);
    }

    uint8_t getTimeDelay() {
        return getUInt8(113);
    }

    void setTimeDelay(uint8_t value) {
        setUInt8(113, value);
    }
};

class PiBinaryValueRegCluster: public Cluster {
public:
    PiBinaryValueRegCluster() : Cluster(1548) {
    }

    uint32_t getChangeOfStateCount() {
        return getUInt32(15);
    }

    void setChangeOfStateCount(uint32_t value) {
        setUInt32(15, value);
    }

    DateTime getChangeOfStateTime() {
        return getDateTime(16);
    }

    void setChangeOfStateTime(const DateTime& value) {
        setDateTime(16, value);
    }

    uint32_t getElapsedActiveTime() {
        return getUInt32(33);
    }

    void setElapsedActiveTime(uint32_t value) {
        setUInt32(33, value);
    }

    uint32_t getObjectIdentifier() {
        return getBacOID(75);
    }

    void setObjectIdentifier(uint32_t value) {
        setBacOID(75, value);
    }

    String getObjectName() {
        return getString(77);
    }

    void setObjectName(const String& value) {
        setString(77, value);
    }

    uint16_t getObjectType() {
        return getEnum16(79);
    }

    void setObjectType(uint16_t value) {
        setEnum16(79, value);
    }

    DateTime getTimeOfATReset() {
        return getDateTime(114);
    }

    void setTimeOfATReset(const DateTime& value) {
        setDateTime(114, value);
    }

    DateTime getTimeOfSCReset() {
        return getDateTime(115);
    }

    void setTimeOfSCReset(const DateTime& value) {
        setDateTime(115, value);
    }

    String getProfileName() {
        return getString(168);
    }

    void setProfileName(const String& value) {
        setString(168, value);
    }
};

class PiBinaryValueExtCluster: public Cluster {
public:
    PiBinaryValueExtCluster() : Cluster(1549) {
    }

    uint8_t getAckedTransitions() {
        return getMap8(0);
    }

    void setAckedTransitions(uint8_t value) {
        setMap8(0, value);
    }

    bool getAlarmValue() {
        return getBool(6);
    }

    void setAlarmValue(bool value) {
        setBool(6, value);
    }

    uint16_t getNotificationClass() {
        return getUInt16(17);
    }

    void setNotificationClass(uint16_t value) {
        setUInt16(17, value);
    }

    uint8_t getEventEnable() {
        return getMap8(35);
    }

    void setEventEnable(uint8_t value) {
        setMap8(35, value);
    }

    uint8_t getEventState() {
        return getEnum8(36);
    }

    void setEventState(uint8_t value) {
        setEnum8(36, value);
    }

    uint8_t getNotifyType() {
        return getEnum8(72);
    }

    void setNotifyType(uint8_t value) {
        setEnum8(72, value);
    }

    uint8_t getTimeDelay() {
        return getUInt8(113);
    }

    void setTimeDelay(uint8_t value) {
        setUInt8(113, value);
    }
};

class PiMultistateInputRegCluster: public Cluster {
public:
    PiMultistateInputRegCluster() : Cluster(1550) {
    }

    String getDeviceType() {
        return getString(31);
    }

    void setDeviceType(const String& value) {
        setString(31, value);
    }

    uint32_t getObjectId() {
        return getBacOID(75);
    }

    void setObjectId(uint32_t value) {
        setBacOID(75, value);
    }

    String getObjectName() {
        return getString(77);
    }

    void setObjectName(const String& value) {
        setString(77, value);
    }

    uint16_t getObjectType() {
        return getEnum16(79);
    }

    void setObjectType(uint16_t value) {
        setEnum16(79, value);
    }

    String getProfileName() {
        return getString(168);
    }

    void setProfileName(const String& value) {
        setString(168, value);
    }
};

class PiMultistateInputExtCluster: public Cluster {
public:
    PiMultistateInputExtCluster() : Cluster(1551) {
    }

    uint8_t getAckedTransitions() {
        return getMap8(0);
    }

    void setAckedTransitions(uint8_t value) {
        setMap8(0, value);
    }

    uint16_t getAlarmValue() {
        return getUInt16(6);
    }

    void setAlarmValue(uint16_t value) {
        setUInt16(6, value);
    }

    uint16_t getNotificationClass() {
        return getUInt16(17);
    }

    void setNotificationClass(uint16_t value) {
        setUInt16(17, value);
    }

    uint8_t getEventEnable() {
        return getMap8(35);
    }

    void setEventEnable(uint8_t value) {
        setMap8(35, value);
    }

    uint8_t getEventState() {
        return getEnum8(36);
    }

    void setEventState(uint8_t value) {
        setEnum8(36, value);
    }

    uint16_t getFaultValues() {
        return getUInt16(37);
    }

    void setFaultValues(uint16_t value) {
        setUInt16(37, value);
    }

    uint8_t getNotifyType() {
        return getEnum8(72);
    }

    void setNotifyType(uint8_t value) {
        setEnum8(72, value);
    }

    uint8_t getTimeDelay() {
        return getUInt8(113);
    }

    void setTimeDelay(uint8_t value) {
        setUInt8(113, value);
    }
};

class PiMultistateOutputRegCluster: public Cluster {
public:
    PiMultistateOutputRegCluster() : Cluster(1552) {
    }

    String getDeviceType() {
        return getString(31);
    }

    void setDeviceType(const String& value) {
        setString(31, value);
    }

    uint8_t getFeedBackValue() {
        return getEnum8(40);
    }

    void setFeedBackValue(uint8_t value) {
        setEnum8(40, value);
    }

    uint32_t getObjectId() {
        return getBacOID(75);
    }

    void setObjectId(uint32_t value) {
        setBacOID(75, value);
    }

    String getObjectName() {
        return getString(77);
    }

    void setObjectName(const String& value) {
        setString(77, value);
    }

    uint16_t getObjectType() {
        return getEnum16(79);
    }

    void setObjectType(uint16_t value) {
        setEnum16(79, value);
    }

    String getProfileName() {
        return getString(168);
    }

    void setProfileName(const String& value) {
        setString(168, value);
    }
};

class PiMultistateOutputExtCluster: public Cluster {
public:
    PiMultistateOutputExtCluster() : Cluster(1553) {
    }

    uint8_t getAckedTransitions() {
        return getMap8(0);
    }

    void setAckedTransitions(uint8_t value) {
        setMap8(0, value);
    }

    uint16_t getNotificationClass() {
        return getUInt16(17);
    }

    void setNotificationClass(uint16_t value) {
        setUInt16(17, value);
    }

    uint8_t getEventEnable() {
        return getMap8(35);
    }

    void setEventEnable(uint8_t value) {
        setMap8(35, value);
    }

    uint8_t getEventState() {
        return getEnum8(36);
    }

    void setEventState(uint8_t value) {
        setEnum8(36, value);
    }

    uint8_t getNotifyType() {
        return getEnum8(72);
    }

    void setNotifyType(uint8_t value) {
        setEnum8(72, value);
    }

    uint8_t getTimeDelay() {
        return getUInt8(113);
    }

    void setTimeDelay(uint8_t value) {
        setUInt8(113, value);
    }
};

class PiMultistateValueRegCluster: public Cluster {
public:
    PiMultistateValueRegCluster() : Cluster(1554) {
    }

    uint32_t getObjectId() {
        return getBacOID(75);
    }

    void setObjectId(uint32_t value) {
        setBacOID(75, value);
    }

    String getObjectName() {
        return getString(77);
    }

    void setObjectName(const String& value) {
        setString(77, value);
    }

    uint16_t getObjectType() {
        return getEnum16(79);
    }

    void setObjectType(uint16_t value) {
        setEnum16(79, value);
    }

    String getProfileName() {
        return getString(168);
    }

    void setProfileName(const String& value) {
        setString(168, value);
    }
};

class PiMultistateValueExtCluster: public Cluster {
public:
    PiMultistateValueExtCluster() : Cluster(1555) {
    }

    uint8_t getAckedTransitions() {
        return getMap8(0);
    }

    void setAckedTransitions(uint8_t value) {
        setMap8(0, value);
    }

    uint16_t getAlarmValue() {
        return getUInt16(6);
    }

    void setAlarmValue(uint16_t value) {
        setUInt16(6, value);
    }

    uint16_t getNotificationClass() {
        return getUInt16(17);
    }

    void setNotificationClass(uint16_t value) {
        setUInt16(17, value);
    }

    uint8_t getEventEnable() {
        return getMap8(35);
    }

    void setEventEnable(uint8_t value) {
        setMap8(35, value);
    }

    uint8_t getEventState() {
        return getEnum8(36);
    }

    void setEventState(uint8_t value) {
        setEnum8(36, value);
    }

    uint16_t getFaultValues() {
        return getUInt16(37);
    }

    void setFaultValues(uint16_t value) {
        setUInt16(37, value);
    }

    uint8_t getNotifyType() {
        return getEnum8(72);
    }

    void setNotifyType(uint8_t value) {
        setEnum8(72, value);
    }

    uint8_t getTimeDelay() {
        return getUInt8(113);
    }

    void setTimeDelay(uint8_t value) {
        setUInt8(113, value);
    }
};

class Pi11073ProtocolTunnelCluster: public Cluster {
public:
    Pi11073ProtocolTunnelCluster() : Cluster(1556) {
    }

    uint64_t getManagerTarget() {
        return getEUI64(1);
    }

    void setManagerTarget(uint64_t value) {
        setEUI64(1, value);
    }

    uint8_t getManagerEndpoint() {
        return getUInt8(2);
    }

    void setManagerEndpoint(uint8_t value) {
        setUInt8(2, value);
    }

    bool getConnected() {
        return getBool(3);
    }

    void setConnected(bool value) {
        setBool(3, value);
    }

    bool getPreemptible() {
        return getBool(4);
    }

    void setPreemptible(bool value) {
        setBool(4, value);
    }

    uint16_t getIdleTimeout() {
        return getUInt16(5);
    }

    void setIdleTimeout(uint16_t value) {
        setUInt16(5, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto status_ = transferApduCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto status_ = connectReqCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto status_ = disconnectReqCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto status_ = connectStatusNotiCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class PiIso7818ProtocolTunnelCluster: public Cluster {
public:
    PiIso7818ProtocolTunnelCluster() : Cluster(1557) {
    }

    uint8_t getStatus() {
        return getUInt8(0);
    }

    void setStatus(uint8_t value) {
        setUInt8(0, value);
    }
};

class PiRetailTunnelCluster: public Cluster {
public:
    PiRetailTunnelCluster() : Cluster(1559) {
    }

    uint16_t getManufacturerCode() {
        return getUInt16(0);
    }

    void setManufacturerCode(uint16_t value) {
        setUInt16(0, value);
    }

    uint16_t getMsProfile() {
        return getUInt16(1);
    }

    void setMsProfile(uint16_t value) {
        setUInt16(1, value);
    }
};

class SeMeteringCluster: public Cluster {
public:
    SeMeteringCluster() : Cluster(1794) {
    }

    uint64_t getCurrentSummDelivered() {
        return getUInt48(0);
    }

    void setCurrentSummDelivered(uint64_t value) {
        setUInt48(0, value);
    }

    uint64_t getCurrentSummReceived() {
        return getUInt48(1);
    }

    void setCurrentSummReceived(uint64_t value) {
        setUInt48(1, value);
    }

    uint64_t getCurrentMaxDemandDelivered() {
        return getUInt48(2);
    }

    void setCurrentMaxDemandDelivered(uint64_t value) {
        setUInt48(2, value);
    }

    uint64_t getCurrentMaxDemandReceived() {
        return getUInt48(3);
    }

    void setCurrentMaxDemandReceived(uint64_t value) {
        setUInt48(3, value);
    }

    uint64_t getDftSumm() {
        return getUInt48(4);
    }

    void setDftSumm(uint64_t value) {
        setUInt48(4, value);
    }

    uint16_t getDailyFreezeTime() {
        return getUInt16(5);
    }

    void setDailyFreezeTime(uint16_t value) {
        setUInt16(5, value);
    }

    int8_t getPowerFactor() {
        return getInt8(6);
    }

    void setPowerFactor(int8_t value) {
        setInt8(6, value);
    }

    uint32_t getReadingSnapshotTime() {
        return getUTC(7);
    }

    void setReadingSnapshotTime(uint32_t value) {
        setUTC(7, value);
    }

    uint32_t getCurrentMaxDemandDeliverdTime() {
        return getUTC(8);
    }

    void setCurrentMaxDemandDeliverdTime(uint32_t value) {
        setUTC(8, value);
    }

    uint32_t getCurrentMaxDemandReceivedTime() {
        return getUTC(9);
    }

    void setCurrentMaxDemandReceivedTime(uint32_t value) {
        setUTC(9, value);
    }

    uint8_t getDefaultUpdatePeriod() {
        return getUInt8(10);
    }

    void setDefaultUpdatePeriod(uint8_t value) {
        setUInt8(10, value);
    }

    uint8_t getFastPollUpdatePeriod() {
        return getUInt8(11);
    }

    void setFastPollUpdatePeriod(uint8_t value) {
        setUInt8(11, value);
    }

    uint64_t getCurrentBlockPeriodConsumpDelivered() {
        return getUInt48(12);
    }

    void setCurrentBlockPeriodConsumpDelivered(uint64_t value) {
        setUInt48(12, value);
    }

    uint32_t getDailyConsumpTarget() {
        return getUInt24(13);
    }

    void setDailyConsumpTarget(uint32_t value) {
        setUInt24(13, value);
    }

    uint8_t getCurrentBlock() {
        return getEnum8(14);
    }

    void setCurrentBlock(uint8_t value) {
        setEnum8(14, value);
    }

    uint8_t getProfileIntervalPeriod() {
        return getEnum8(15);
    }

    void setProfileIntervalPeriod(uint8_t value) {
        setEnum8(15, value);
    }

    uint16_t getIntervalReadReportingPeriod() {
        return getUInt16(16);
    }

    void setIntervalReadReportingPeriod(uint16_t value) {
        setUInt16(16, value);
    }

    uint16_t getPresetReadingTime() {
        return getUInt16(17);
    }

    void setPresetReadingTime(uint16_t value) {
        setUInt16(17, value);
    }

    uint16_t getVolumePerReport() {
        return getUInt16(18);
    }

    void setVolumePerReport(uint16_t value) {
        setUInt16(18, value);
    }

    uint8_t getFlowRestriction() {
        return getUInt8(19);
    }

    void setFlowRestriction(uint8_t value) {
        setUInt8(19, value);
    }

    uint8_t getSupplyStatus() {
        return getEnum8(20);
    }

    void setSupplyStatus(uint8_t value) {
        setEnum8(20, value);
    }

    uint64_t getCurrentInEnergyCarrierSumm() {
        return getUInt48(21);
    }

    void setCurrentInEnergyCarrierSumm(uint64_t value) {
        setUInt48(21, value);
    }

    uint64_t getCurrentOutEnergyCarrierSumm() {
        return getUInt48(22);
    }

    void setCurrentOutEnergyCarrierSumm(uint64_t value) {
        setUInt48(22, value);
    }

    int32_t getInletTempreature() {
        return getInt24(23);
    }

    void setInletTempreature(int32_t value) {
        setInt24(23, value);
    }

    int32_t getOutletTempreature() {
        return getInt24(24);
    }

    void setOutletTempreature(int32_t value) {
        setInt24(24, value);
    }

    int32_t getControlTempreature() {
        return getInt24(25);
    }

    void setControlTempreature(int32_t value) {
        setInt24(25, value);
    }

    int32_t getCurrentInEnergyCarrierDemand() {
        return getInt24(26);
    }

    void setCurrentInEnergyCarrierDemand(int32_t value) {
        setInt24(26, value);
    }

    int32_t getCurrentOutEnergyCarrierDemand() {
        return getInt24(27);
    }

    void setCurrentOutEnergyCarrierDemand(int32_t value) {
        setInt24(27, value);
    }

    uint64_t getCurrentBlockPeriodConsumpReceived() {
        return getUInt48(29);
    }

    void setCurrentBlockPeriodConsumpReceived(uint64_t value) {
        setUInt48(29, value);
    }

    uint64_t getCurrentBlockReceived() {
        return getUInt48(30);
    }

    void setCurrentBlockReceived(uint64_t value) {
        setUInt48(30, value);
    }

    uint64_t getDFTSummationReceived() {
        return getUInt48(31);
    }

    void setDFTSummationReceived(uint64_t value) {
        setUInt48(31, value);
    }

    uint8_t getActiveRegisterTierDelivered() {
        return getEnum8(32);
    }

    void setActiveRegisterTierDelivered(uint8_t value) {
        setEnum8(32, value);
    }

    uint8_t getActiveRegisterTierReceived() {
        return getEnum8(33);
    }

    void setActiveRegisterTierReceived(uint8_t value) {
        setEnum8(33, value);
    }

    uint64_t getCurrentTier1SummDelivered() {
        return getUInt48(256);
    }

    void setCurrentTier1SummDelivered(uint64_t value) {
        setUInt48(256, value);
    }

    uint64_t getCurrentTier1SummReceived() {
        return getUInt48(257);
    }

    void setCurrentTier1SummReceived(uint64_t value) {
        setUInt48(257, value);
    }

    uint64_t getCurrentTier2SummDelivered() {
        return getUInt48(258);
    }

    void setCurrentTier2SummDelivered(uint64_t value) {
        setUInt48(258, value);
    }

    uint64_t getCurrentTier2SummReceived() {
        return getUInt48(259);
    }

    void setCurrentTier2SummReceived(uint64_t value) {
        setUInt48(259, value);
    }

    uint64_t getCurrentTier3SummDelivered() {
        return getUInt48(260);
    }

    void setCurrentTier3SummDelivered(uint64_t value) {
        setUInt48(260, value);
    }

    uint64_t getCurrentTier3SummReceived() {
        return getUInt48(261);
    }

    void setCurrentTier3SummReceived(uint64_t value) {
        setUInt48(261, value);
    }

    uint64_t getCurrentTier4SummDelivered() {
        return getUInt48(262);
    }

    void setCurrentTier4SummDelivered(uint64_t value) {
        setUInt48(262, value);
    }

    uint64_t getCurrentTier4SummReceived() {
        return getUInt48(263);
    }

    void setCurrentTier4SummReceived(uint64_t value) {
        setUInt48(263, value);
    }

    uint64_t getCurrentTier5SummDelivered() {
        return getUInt48(264);
    }

    void setCurrentTier5SummDelivered(uint64_t value) {
        setUInt48(264, value);
    }

    uint64_t getCurrentTier5SummReceived() {
        return getUInt48(265);
    }

    void setCurrentTier5SummReceived(uint64_t value) {
        setUInt48(265, value);
    }

    uint64_t getCurrentTier6SummDelivered() {
        return getUInt48(266);
    }

    void setCurrentTier6SummDelivered(uint64_t value) {
        setUInt48(266, value);
    }

    uint64_t getCurrentTier6SummReceived() {
        return getUInt48(267);
    }

    void setCurrentTier6SummReceived(uint64_t value) {
        setUInt48(267, value);
    }

    uint64_t getCurrentTier7SummDelivered() {
        return getUInt48(268);
    }

    void setCurrentTier7SummDelivered(uint64_t value) {
        setUInt48(268, value);
    }

    uint64_t getCurrentTier7SummReceived() {
        return getUInt48(269);
    }

    void setCurrentTier7SummReceived(uint64_t value) {
        setUInt48(269, value);
    }

    uint64_t getCurrentTier8SummDelivered() {
        return getUInt48(270);
    }

    void setCurrentTier8SummDelivered(uint64_t value) {
        setUInt48(270, value);
    }

    uint64_t getCurrentTier8SummReceived() {
        return getUInt48(271);
    }

    void setCurrentTier8SummReceived(uint64_t value) {
        setUInt48(271, value);
    }

    uint64_t getCurrentTier9SummDelivered() {
        return getUInt48(272);
    }

    void setCurrentTier9SummDelivered(uint64_t value) {
        setUInt48(272, value);
    }

    uint64_t getCurrentTier9SummReceived() {
        return getUInt48(273);
    }

    void setCurrentTier9SummReceived(uint64_t value) {
        setUInt48(273, value);
    }

    uint64_t getCurrentTier10SummDelivered() {
        return getUInt48(274);
    }

    void setCurrentTier10SummDelivered(uint64_t value) {
        setUInt48(274, value);
    }

    uint64_t getCurrentTier10SummReceived() {
        return getUInt48(275);
    }

    void setCurrentTier10SummReceived(uint64_t value) {
        setUInt48(275, value);
    }

    uint64_t getCurrentTier11SummDelivered() {
        return getUInt48(276);
    }

    void setCurrentTier11SummDelivered(uint64_t value) {
        setUInt48(276, value);
    }

    uint64_t getCurrentTier11SummReceived() {
        return getUInt48(277);
    }

    void setCurrentTier11SummReceived(uint64_t value) {
        setUInt48(277, value);
    }

    uint64_t getCurrentTier12SummDelivered() {
        return getUInt48(278);
    }

    void setCurrentTier12SummDelivered(uint64_t value) {
        setUInt48(278, value);
    }

    uint64_t getCurrentTier12SummReceived() {
        return getUInt48(279);
    }

    void setCurrentTier12SummReceived(uint64_t value) {
        setUInt48(279, value);
    }

    uint64_t getCurrentTier13SummDelivered() {
        return getUInt48(280);
    }

    void setCurrentTier13SummDelivered(uint64_t value) {
        setUInt48(280, value);
    }

    uint64_t getCurrentTier13SummReceived() {
        return getUInt48(281);
    }

    void setCurrentTier13SummReceived(uint64_t value) {
        setUInt48(281, value);
    }

    uint64_t getCurrentTier14SummDelivered() {
        return getUInt48(282);
    }

    void setCurrentTier14SummDelivered(uint64_t value) {
        setUInt48(282, value);
    }

    uint64_t getCurrentTier14SummReceived() {
        return getUInt48(283);
    }

    void setCurrentTier14SummReceived(uint64_t value) {
        setUInt48(283, value);
    }

    uint64_t getCurrentTier15SummDelivered() {
        return getUInt48(284);
    }

    void setCurrentTier15SummDelivered(uint64_t value) {
        setUInt48(284, value);
    }

    uint64_t getCurrentTier15SummReceived() {
        return getUInt48(285);
    }

    void setCurrentTier15SummReceived(uint64_t value) {
        setUInt48(285, value);
    }

    uint8_t getStatus() {
        return getMap8(512);
    }

    void setStatus(uint8_t value) {
        setMap8(512, value);
    }

    uint8_t getRemainingBattLife() {
        return getUInt8(513);
    }

    void setRemainingBattLife(uint8_t value) {
        setUInt8(513, value);
    }

    uint32_t getHoursInOperation() {
        return getUInt24(514);
    }

    void setHoursInOperation(uint32_t value) {
        setUInt24(514, value);
    }

    uint32_t getHoursInFault() {
        return getUInt24(515);
    }

    void setHoursInFault(uint32_t value) {
        setUInt24(515, value);
    }

    uint64_t getExtendedStatus() {
        return getMap64(516);
    }

    void setExtendedStatus(uint64_t value) {
        setMap64(516, value);
    }

    uint8_t getUnitOfMeasure() {
        return getEnum8(768);
    }

    void setUnitOfMeasure(uint8_t value) {
        setEnum8(768, value);
    }

    uint32_t getMultiplier() {
        return getUInt24(769);
    }

    void setMultiplier(uint32_t value) {
        setUInt24(769, value);
    }

    uint32_t getDivisor() {
        return getUInt24(770);
    }

    void setDivisor(uint32_t value) {
        setUInt24(770, value);
    }

    uint8_t getSummaFormatting() {
        return getMap8(771);
    }

    void setSummaFormatting(uint8_t value) {
        setMap8(771, value);
    }

    uint8_t getDemandFormatting() {
        return getMap8(772);
    }

    void setDemandFormatting(uint8_t value) {
        setMap8(772, value);
    }

    uint8_t getHistoricalConsumpFormatting() {
        return getMap8(773);
    }

    void setHistoricalConsumpFormatting(uint8_t value) {
        setMap8(773, value);
    }

    uint8_t getMeteringDeviceType() {
        return getMap8(774);
    }

    void setMeteringDeviceType(uint8_t value) {
        setMap8(774, value);
    }

    Buffer getSiteId() {
        return getOctstr(775);
    }

    void setSiteId(const Buffer& value) {
        setOctstr(775, value);
    }

    Buffer getMeterSerialNumber() {
        return getOctstr(776);
    }

    void setMeterSerialNumber(const Buffer& value) {
        setOctstr(776, value);
    }

    uint8_t getEnergyCarrierUnitOfMeas() {
        return getEnum8(777);
    }

    void setEnergyCarrierUnitOfMeas(uint8_t value) {
        setEnum8(777, value);
    }

    uint8_t getEnergyCarrierSummFormatting() {
        return getMap8(778);
    }

    void setEnergyCarrierSummFormatting(uint8_t value) {
        setMap8(778, value);
    }

    uint8_t getEnergyCarrierDemandFormatting() {
        return getMap8(779);
    }

    void setEnergyCarrierDemandFormatting(uint8_t value) {
        setMap8(779, value);
    }

    uint8_t getTemperatureUnitOfMeas() {
        return getEnum8(780);
    }

    void setTemperatureUnitOfMeas(uint8_t value) {
        setEnum8(780, value);
    }

    uint8_t getTemperatureFormatting() {
        return getMap8(781);
    }

    void setTemperatureFormatting(uint8_t value) {
        setMap8(781, value);
    }

    Buffer getModuleSerialNumber() {
        return getOctstr(782);
    }

    void setModuleSerialNumber(const Buffer& value) {
        setOctstr(782, value);
    }

    Buffer getOperatingTariffLevel() {
        return getOctstr(783);
    }

    void setOperatingTariffLevel(const Buffer& value) {
        setOctstr(783, value);
    }

    int32_t getInstantaneousDemand() {
        return getInt24(1024);
    }

    void setInstantaneousDemand(int32_t value) {
        setInt24(1024, value);
    }

    uint32_t getCurrentdayConsumpDelivered() {
        return getUInt24(1025);
    }

    void setCurrentdayConsumpDelivered(uint32_t value) {
        setUInt24(1025, value);
    }

    uint32_t getCurrentdayConsumpReceived() {
        return getUInt24(1026);
    }

    void setCurrentdayConsumpReceived(uint32_t value) {
        setUInt24(1026, value);
    }

    uint32_t getPreviousdayConsumpDelivered() {
        return getUInt24(1027);
    }

    void setPreviousdayConsumpDelivered(uint32_t value) {
        setUInt24(1027, value);
    }

    uint32_t getPreviousdayConsumpReceived() {
        return getUInt24(1028);
    }

    void setPreviousdayConsumpReceived(uint32_t value) {
        setUInt24(1028, value);
    }

    uint32_t getCurPartProfileIntStartTimeDelivered() {
        return getUTC(1029);
    }

    void setCurPartProfileIntStartTimeDelivered(uint32_t value) {
        setUTC(1029, value);
    }

    uint32_t getCurPartProfileIntStartTimeReceived() {
        return getUTC(1030);
    }

    void setCurPartProfileIntStartTimeReceived(uint32_t value) {
        setUTC(1030, value);
    }

    uint32_t getCurPartProfileIntValueDelivered() {
        return getUInt24(1031);
    }

    void setCurPartProfileIntValueDelivered(uint32_t value) {
        setUInt24(1031, value);
    }

    uint32_t getCurPartProfileIntValueReceived() {
        return getUInt24(1032);
    }

    void setCurPartProfileIntValueReceived(uint32_t value) {
        setUInt24(1032, value);
    }

    uint64_t getCurrentDayMaxPressure() {
        return getUInt48(1033);
    }

    void setCurrentDayMaxPressure(uint64_t value) {
        setUInt48(1033, value);
    }

    uint64_t getCurrentDayMinPressure() {
        return getUInt48(1034);
    }

    void setCurrentDayMinPressure(uint64_t value) {
        setUInt48(1034, value);
    }

    uint64_t getPreviousDayMaxPressure() {
        return getUInt48(1035);
    }

    void setPreviousDayMaxPressure(uint64_t value) {
        setUInt48(1035, value);
    }

    uint64_t getPreviousDayMinPressure() {
        return getUInt48(1036);
    }

    void setPreviousDayMinPressure(uint64_t value) {
        setUInt48(1036, value);
    }

    int32_t getCurrentDayMaxDemand() {
        return getInt24(1037);
    }

    void setCurrentDayMaxDemand(int32_t value) {
        setInt24(1037, value);
    }

    int32_t getPreviousDayMaxDemand() {
        return getInt24(1038);
    }

    void setPreviousDayMaxDemand(int32_t value) {
        setInt24(1038, value);
    }

    int32_t getCurrentMonthMaxDemand() {
        return getInt24(1039);
    }

    void setCurrentMonthMaxDemand(int32_t value) {
        setInt24(1039, value);
    }

    int32_t getCurrentYearMaxDemand() {
        return getInt24(1040);
    }

    void setCurrentYearMaxDemand(int32_t value) {
        setInt24(1040, value);
    }

    int32_t getCurrentdayMaxEnergyCarrDemand() {
        return getInt24(1041);
    }

    void setCurrentdayMaxEnergyCarrDemand(int32_t value) {
        setInt24(1041, value);
    }

    int32_t getPreviousdayMaxEnergyCarrDemand() {
        return getInt24(1042);
    }

    void setPreviousdayMaxEnergyCarrDemand(int32_t value) {
        setInt24(1042, value);
    }

    int32_t getCurMonthMaxEnergyCarrDemand() {
        return getInt24(1043);
    }

    void setCurMonthMaxEnergyCarrDemand(int32_t value) {
        setInt24(1043, value);
    }

    int32_t getCurMonthMinEnergyCarrDemand() {
        return getInt24(1044);
    }

    void setCurMonthMinEnergyCarrDemand(int32_t value) {
        setInt24(1044, value);
    }

    int32_t getCurYearMaxEnergyCarrDemand() {
        return getInt24(1045);
    }

    void setCurYearMaxEnergyCarrDemand(int32_t value) {
        setInt24(1045, value);
    }

    int32_t getCurYearMinEnergyCarrDemand() {
        return getInt24(1046);
    }

    void setCurYearMinEnergyCarrDemand(int32_t value) {
        setInt24(1046, value);
    }

    uint8_t getMaxNumberOfPeriodsDelivered() {
        return getUInt8(1280);
    }

    void setMaxNumberOfPeriodsDelivered(uint8_t value) {
        setUInt8(1280, value);
    }

    uint32_t getCurrentDemandDelivered() {
        return getUInt24(1536);
    }

    void setCurrentDemandDelivered(uint32_t value) {
        setUInt24(1536, value);
    }

    uint32_t getDemandLimit() {
        return getUInt24(1537);
    }

    void setDemandLimit(uint32_t value) {
        setUInt24(1537, value);
    }

    uint8_t getDemandIntegrationPeriod() {
        return getUInt8(1538);
    }

    void setDemandIntegrationPeriod(uint8_t value) {
        setUInt8(1538, value);
    }

    uint8_t getNumberOfDemandSubintervals() {
        return getUInt8(1539);
    }

    void setNumberOfDemandSubintervals(uint8_t value) {
        setUInt8(1539, value);
    }

    uint16_t getDemandLimitArmDuration() {
        return getUInt16(1540);
    }

    void setDemandLimitArmDuration(uint16_t value) {
        setUInt16(1540, value);
    }

    uint16_t getGenericAlarmMask() {
        return getMap16(2048);
    }

    void setGenericAlarmMask(uint16_t value) {
        setMap16(2048, value);
    }

    uint32_t getElectricityAlarmMask() {
        return getMap32(2049);
    }

    void setElectricityAlarmMask(uint32_t value) {
        setMap32(2049, value);
    }

    uint16_t getGenFlowPressureAlarmMask() {
        return getMap16(2050);
    }

    void setGenFlowPressureAlarmMask(uint16_t value) {
        setMap16(2050, value);
    }

    uint16_t getWaterSpecificAlarmMask() {
        return getMap16(2051);
    }

    void setWaterSpecificAlarmMask(uint16_t value) {
        setMap16(2051, value);
    }

    uint16_t getHeatCoolSpecificAlarmMASK() {
        return getMap16(2052);
    }

    void setHeatCoolSpecificAlarmMASK(uint16_t value) {
        setMap16(2052, value);
    }

    uint16_t getGasSpecificAlarmMask() {
        return getMap16(2053);
    }

    void setGasSpecificAlarmMask(uint16_t value) {
        setMap16(2053, value);
    }

    uint64_t getExtendedGenericAlarmMask() {
        return getMap48(2054);
    }

    void setExtendedGenericAlarmMask(uint64_t value) {
        setMap48(2054, value);
    }

    uint16_t getManufactureAlarmMask() {
        return getMap16(2055);
    }

    void setManufactureAlarmMask(uint16_t value) {
        setMap16(2055, value);
    }

    uint32_t getBillToDate() {
        return getUInt32(2560);
    }

    void setBillToDate(uint32_t value) {
        setUInt32(2560, value);
    }

    uint32_t getBillToDateTimeStamp() {
        return getUTC(2561);
    }

    void setBillToDateTimeStamp(uint32_t value) {
        setUTC(2561, value);
    }

    uint32_t getProjectedBill() {
        return getUInt32(2562);
    }

    void setProjectedBill(uint32_t value) {
        setUInt32(2562, value);
    }

    uint32_t getProjectedBillTimeStamp() {
        return getUTC(2563);
    }

    void setProjectedBillTimeStamp(uint32_t value) {
        setUTC(2563, value);
    }

    uint32_t getNotificationControlFlags() {
        return getMap32(0);
    }

    void setNotificationControlFlags(uint32_t value) {
        setMap32(0, value);
    }

    uint32_t getNotificationFlags() {
        return getMap32(1);
    }

    void setNotificationFlags(uint32_t value) {
        setMap32(1, value);
    }

    uint32_t getPriceNotificationFlags() {
        return getMap32(2);
    }

    void setPriceNotificationFlags(uint32_t value) {
        setMap32(2, value);
    }

    uint32_t getCalendarNotificationFlags() {
        return getMap32(3);
    }

    void setCalendarNotificationFlags(uint32_t value) {
        setMap32(3, value);
    }

    uint32_t getPrePayNotificationFlags() {
        return getMap32(4);
    }

    void setPrePayNotificationFlags(uint32_t value) {
        setMap32(4, value);
    }

    uint32_t getDeviceManagementFlags() {
        return getMap32(5);
    }

    void setDeviceManagementFlags(uint32_t value) {
        setMap32(5, value);
    }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto status_ = getProfileCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto status_ = reqMirrorCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto status_ = mirrorRemCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto status_ = reqFastPollModeCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 4: {
                auto status_ = getSnapshotCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 5: {
                auto status_ = takeSnapshotCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 6: {
                auto status_ = mirrorReportAttrRspCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 32: {
                auto status_ = owonGetHistoryRecordCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 33: {
                auto status_ = owonStopSendingHistoricalRecordCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class TelecommunicationsInformationCluster: public Cluster {
public:
    TelecommunicationsInformationCluster() : Cluster(2304) {
    }

    String getNodeDescription() {
        return getString(0);
    }

    void setNodeDescription(const String& value) {
        setString(0, value);
    }

    bool getDeliveryEnable() {
        return getBool(1);
    }

    void setDeliveryEnable(bool value) {
        setBool(1, value);
    }

    uint32_t getPushInformationTimer() {
        return getUInt32(2);
    }

    void setPushInformationTimer(uint32_t value) {
        setUInt32(2, value);
    }

    bool getEnableSecureConfiguration() {
        return getBool(3);
    }

    void setEnableSecureConfiguration(bool value) {
        setBool(3, value);
    }

    uint16_t getNumberOfContents() {
        return getUInt16(16);
    }

    void setNumberOfContents(uint16_t value) {
        setUInt16(16, value);
    }

    uint16_t getContentRootID() {
        return getUInt16(17);
    }

    void setContentRootID(uint16_t value) {
        setUInt16(17, value);
    }
};

class TelecommunicationsVoiceOverZigbeeCluster: public Cluster {
public:
    TelecommunicationsVoiceOverZigbeeCluster() : Cluster(2308) {
    }

    uint8_t getCodecType() {
        return getEnum8(0);
    }

    void setCodecType(uint8_t value) {
        setEnum8(0, value);
    }

    uint8_t getSamplingFrequency() {
        return getEnum8(1);
    }

    void setSamplingFrequency(uint8_t value) {
        setEnum8(1, value);
    }

    uint8_t getCodecrate() {
        return getEnum8(2);
    }

    void setCodecrate(uint8_t value) {
        setEnum8(2, value);
    }

    uint8_t getEstablishmentTimeout() {
        return getUInt8(3);
    }

    void setEstablishmentTimeout(uint8_t value) {
        setUInt8(3, value);
    }

    uint8_t getCodecTypeSub1() {
        return getEnum8(4);
    }

    void setCodecTypeSub1(uint8_t value) {
        setEnum8(4, value);
    }

    uint8_t getCodecTypeSub2() {
        return getEnum8(5);
    }

    void setCodecTypeSub2(uint8_t value) {
        setEnum8(5, value);
    }

    uint8_t getCodecTypeSub3() {
        return getEnum8(6);
    }

    void setCodecTypeSub3(uint8_t value) {
        setEnum8(6, value);
    }

    uint8_t getCompressionType() {
        return getEnum8(7);
    }

    void setCompressionType(uint8_t value) {
        setEnum8(7, value);
    }

    uint8_t getCompressionRate() {
        return getEnum8(8);
    }

    void setCompressionRate(uint8_t value) {
        setEnum8(8, value);
    }

    uint8_t getOptionFlags() {
        return getMap8(9);
    }

    void setOptionFlags(uint8_t value) {
        setMap8(9, value);
    }

    uint8_t getThreshold() {
        return getUInt8(10);
    }

    void setThreshold(uint8_t value) {
        setUInt8(10, value);
    }
};

class TelecommunicationsChattingCluster: public Cluster {
public:
    TelecommunicationsChattingCluster() : Cluster(2309) {
    }

    uint16_t getUID() {
        return getUInt16(0);
    }

    void setUID(uint16_t value) {
        setUInt16(0, value);
    }

    String getNickname() {
        return getString(1);
    }

    void setNickname(const String& value) {
        setString(1, value);
    }

    uint16_t getCID() {
        return getUInt16(16);
    }

    void setCID(uint16_t value) {
        setUInt16(16, value);
    }

    String getName() {
        return getString(17);
    }

    void setName(const String& value) {
        setString(17, value);
    }

    bool getEnableAddChat() {
        return getBool(18);
    }

    void setEnableAddChat(bool value) {
        setBool(18, value);
    }
};

class HaApplianceIdentificationCluster: public Cluster {
public:
    HaApplianceIdentificationCluster() : Cluster(2816) {
    }

    uint64_t getBasicIdentification() {
        return getUInt56(0);
    }

    void setBasicIdentification(uint64_t value) {
        setUInt56(0, value);
    }

    String getCompanyName() {
        return getString(16);
    }

    void setCompanyName(const String& value) {
        setString(16, value);
    }

    uint16_t getCompanyId() {
        return getUInt16(17);
    }

    void setCompanyId(uint16_t value) {
        setUInt16(17, value);
    }

    String getBrandName() {
        return getString(18);
    }

    void setBrandName(const String& value) {
        setString(18, value);
    }

    uint16_t getBrandId() {
        return getUInt16(19);
    }

    void setBrandId(uint16_t value) {
        setUInt16(19, value);
    }

    Buffer getModel() {
        return getOctstr(20);
    }

    void setModel(const Buffer& value) {
        setOctstr(20, value);
    }

    Buffer getPartNumber() {
        return getOctstr(21);
    }

    void setPartNumber(const Buffer& value) {
        setOctstr(21, value);
    }

    Buffer getProductRevision() {
        return getOctstr(22);
    }

    void setProductRevision(const Buffer& value) {
        setOctstr(22, value);
    }

    Buffer getSoftwareRevision() {
        return getOctstr(23);
    }

    void setSoftwareRevision(const Buffer& value) {
        setOctstr(23, value);
    }

    Buffer getProductTypeName() {
        return getOctstr(24);
    }

    void setProductTypeName(const Buffer& value) {
        setOctstr(24, value);
    }

    uint16_t getProductTypeId() {
        return getUInt16(25);
    }

    void setProductTypeId(uint16_t value) {
        setUInt16(25, value);
    }

    uint8_t getCecedSpecificationVersion() {
        return getUInt8(26);
    }

    void setCecedSpecificationVersion(uint8_t value) {
        setUInt8(26, value);
    }
};

class HaMeterIdentificationCluster: public Cluster {
public:
    HaMeterIdentificationCluster() : Cluster(2817) {
    }

    String getCompanyName() {
        return getString(0);
    }

    void setCompanyName(const String& value) {
        setString(0, value);
    }

    uint16_t getMeterTypeId() {
        return getUInt16(1);
    }

    void setMeterTypeId(uint16_t value) {
        setUInt16(1, value);
    }

    uint16_t getDataQualityId() {
        return getUInt16(4);
    }

    void setDataQualityId(uint16_t value) {
        setUInt16(4, value);
    }

    String getCustomerName() {
        return getString(5);
    }

    void setCustomerName(const String& value) {
        setString(5, value);
    }

    String getModel() {
        return getString(6);
    }

    void setModel(const String& value) {
        setString(6, value);
    }

    String getPartNumber() {
        return getString(7);
    }

    void setPartNumber(const String& value) {
        setString(7, value);
    }

    String getProductRevision() {
        return getString(8);
    }

    void setProductRevision(const String& value) {
        setString(8, value);
    }

    String getSoftwareRevision() {
        return getString(10);
    }

    void setSoftwareRevision(const String& value) {
        setString(10, value);
    }

    String getUtilityName() {
        return getString(11);
    }

    void setUtilityName(const String& value) {
        setString(11, value);
    }

    String getPod() {
        return getString(12);
    }

    void setPod(const String& value) {
        setString(12, value);
    }

    int32_t getAvailablePower() {
        return getInt24(13);
    }

    void setAvailablePower(int32_t value) {
        setInt24(13, value);
    }

    int32_t getPowerThreshold() {
        return getInt24(14);
    }

    void setPowerThreshold(int32_t value) {
        setInt24(14, value);
    }
};

class HaApplianceEventsAlertsCluster: public Cluster {
public:
    HaApplianceEventsAlertsCluster() : Cluster(2818) {
    }

    virtual Status getAlertsCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto status_ = getAlertsCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class HaApplianceStatisticsCluster: public Cluster {
public:
    HaApplianceStatisticsCluster() : Cluster(2819) {
    }

    uint32_t getLogMaxSize() {
        return getUInt32(0);
    }

    void setLogMaxSize(uint32_t value) {
        setUInt32(0, value);
    }

    uint8_t getLogQueueMaxSize() {
        return getUInt8(1);
    }

    void setLogQueueMaxSize(uint8_t value) {
        setUInt8(1, value);
    }

    virtual Status logCommand(uint32_t logid) {
        return Status::UnsupportedAttribute;
    }

    virtual Status logQueueCommand() {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto logid = request.readUInt32Le();
                auto status_ = logCommand(logid);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto status_ = logQueueCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class HaElectricalMeasurementCluster: public Cluster {
public:
    HaElectricalMeasurementCluster() : Cluster(2820) {
    }

    uint32_t getMeasurementType() {
        return getMap32(0);
    }

    void setMeasurementType(uint32_t value) {
        setMap32(0, value);
    }

    int16_t getDcVoltage() {
        return getInt16(256);
    }

    void setDcVoltage(int16_t value) {
        setInt16(256, value);
    }

    int16_t getDcVoltageMin() {
        return getInt16(257);
    }

    void setDcVoltageMin(int16_t value) {
        setInt16(257, value);
    }

    int16_t getDcvoltagemax() {
        return getInt16(258);
    }

    void setDcvoltagemax(int16_t value) {
        setInt16(258, value);
    }

    int16_t getDcCurrent() {
        return getInt16(259);
    }

    void setDcCurrent(int16_t value) {
        setInt16(259, value);
    }

    int16_t getDcCurrentMin() {
        return getInt16(260);
    }

    void setDcCurrentMin(int16_t value) {
        setInt16(260, value);
    }

    int16_t getDcCurrentMax() {
        return getInt16(261);
    }

    void setDcCurrentMax(int16_t value) {
        setInt16(261, value);
    }

    int16_t getDcPower() {
        return getInt16(262);
    }

    void setDcPower(int16_t value) {
        setInt16(262, value);
    }

    int16_t getDcPowerMin() {
        return getInt16(263);
    }

    void setDcPowerMin(int16_t value) {
        setInt16(263, value);
    }

    int16_t getDcPowerMax() {
        return getInt16(264);
    }

    void setDcPowerMax(int16_t value) {
        setInt16(264, value);
    }

    uint16_t getDcVoltageMultiplier() {
        return getUInt16(512);
    }

    void setDcVoltageMultiplier(uint16_t value) {
        setUInt16(512, value);
    }

    uint16_t getDcVoltageDivisor() {
        return getUInt16(513);
    }

    void setDcVoltageDivisor(uint16_t value) {
        setUInt16(513, value);
    }

    uint16_t getDcCurrentMultiplier() {
        return getUInt16(514);
    }

    void setDcCurrentMultiplier(uint16_t value) {
        setUInt16(514, value);
    }

    uint16_t getDcCurrentDivisor() {
        return getUInt16(515);
    }

    void setDcCurrentDivisor(uint16_t value) {
        setUInt16(515, value);
    }

    uint16_t getDcPowerMultiplier() {
        return getUInt16(516);
    }

    void setDcPowerMultiplier(uint16_t value) {
        setUInt16(516, value);
    }

    uint16_t getDcPowerDivisor() {
        return getUInt16(517);
    }

    void setDcPowerDivisor(uint16_t value) {
        setUInt16(517, value);
    }

    uint16_t getAcFrequency() {
        return getUInt16(768);
    }

    void setAcFrequency(uint16_t value) {
        setUInt16(768, value);
    }

    uint16_t getAcFrequencyMin() {
        return getUInt16(769);
    }

    void setAcFrequencyMin(uint16_t value) {
        setUInt16(769, value);
    }

    uint16_t getAcFrequencyMax() {
        return getUInt16(770);
    }

    void setAcFrequencyMax(uint16_t value) {
        setUInt16(770, value);
    }

    uint16_t getNeutralCurrent() {
        return getUInt16(771);
    }

    void setNeutralCurrent(uint16_t value) {
        setUInt16(771, value);
    }

    int32_t getTotalActivePower() {
        return getInt32(772);
    }

    void setTotalActivePower(int32_t value) {
        setInt32(772, value);
    }

    int32_t getTotalReactivePower() {
        return getInt32(773);
    }

    void setTotalReactivePower(int32_t value) {
        setInt32(773, value);
    }

    uint32_t getTotalApparentPower() {
        return getUInt32(774);
    }

    void setTotalApparentPower(uint32_t value) {
        setUInt32(774, value);
    }

    int16_t getMeas1stHarmonicCurrent() {
        return getInt16(775);
    }

    void setMeas1stHarmonicCurrent(int16_t value) {
        setInt16(775, value);
    }

    int16_t getMeas3rdHarmonicCurrent() {
        return getInt16(776);
    }

    void setMeas3rdHarmonicCurrent(int16_t value) {
        setInt16(776, value);
    }

    int16_t getMeas5thHarmonicCurrent() {
        return getInt16(777);
    }

    void setMeas5thHarmonicCurrent(int16_t value) {
        setInt16(777, value);
    }

    int16_t getMeas7thHarmonicCurrent() {
        return getInt16(778);
    }

    void setMeas7thHarmonicCurrent(int16_t value) {
        setInt16(778, value);
    }

    int16_t getMeas9thHarmonicCurrent() {
        return getInt16(779);
    }

    void setMeas9thHarmonicCurrent(int16_t value) {
        setInt16(779, value);
    }

    int16_t getMeas11thHarmonicCurrent() {
        return getInt16(780);
    }

    void setMeas11thHarmonicCurrent(int16_t value) {
        setInt16(780, value);
    }

    int16_t getMeasPhase1stHarmonicCurrent() {
        return getInt16(781);
    }

    void setMeasPhase1stHarmonicCurrent(int16_t value) {
        setInt16(781, value);
    }

    int16_t getMeasPhase3rdHarmonicCurrent() {
        return getInt16(782);
    }

    void setMeasPhase3rdHarmonicCurrent(int16_t value) {
        setInt16(782, value);
    }

    int16_t getMeasPhase5thHarmonicCurrent() {
        return getInt16(783);
    }

    void setMeasPhase5thHarmonicCurrent(int16_t value) {
        setInt16(783, value);
    }

    int16_t getMeasPhase7thHarmonicCurrent() {
        return getInt16(784);
    }

    void setMeasPhase7thHarmonicCurrent(int16_t value) {
        setInt16(784, value);
    }

    int16_t getMeasPhase9thHarmonicCurrent() {
        return getInt16(785);
    }

    void setMeasPhase9thHarmonicCurrent(int16_t value) {
        setInt16(785, value);
    }

    int16_t getMeasPhase11thHarmonicCurrent() {
        return getInt16(786);
    }

    void setMeasPhase11thHarmonicCurrent(int16_t value) {
        setInt16(786, value);
    }

    uint16_t getAcFrequencyMultiplier() {
        return getUInt16(1024);
    }

    void setAcFrequencyMultiplier(uint16_t value) {
        setUInt16(1024, value);
    }

    uint16_t getAcFrequencyDivisor() {
        return getUInt16(1025);
    }

    void setAcFrequencyDivisor(uint16_t value) {
        setUInt16(1025, value);
    }

    uint32_t getPowerMultiplier() {
        return getUInt32(1026);
    }

    void setPowerMultiplier(uint32_t value) {
        setUInt32(1026, value);
    }

    uint32_t getPowerDivisor() {
        return getUInt32(1027);
    }

    void setPowerDivisor(uint32_t value) {
        setUInt32(1027, value);
    }

    int8_t getHarmonicCurrentMultiplier() {
        return getInt8(1028);
    }

    void setHarmonicCurrentMultiplier(int8_t value) {
        setInt8(1028, value);
    }

    int8_t getPhaseHarmonicCurrentMultiplier() {
        return getInt8(1029);
    }

    void setPhaseHarmonicCurrentMultiplier(int8_t value) {
        setInt8(1029, value);
    }

    int16_t getInstantaneousVoltage() {
        return getInt16(1280);
    }

    void setInstantaneousVoltage(int16_t value) {
        setInt16(1280, value);
    }

    uint16_t getInstantaneousLineCurrent() {
        return getUInt16(1281);
    }

    void setInstantaneousLineCurrent(uint16_t value) {
        setUInt16(1281, value);
    }

    int16_t getInstantaneousActiveCurrent() {
        return getInt16(1282);
    }

    void setInstantaneousActiveCurrent(int16_t value) {
        setInt16(1282, value);
    }

    int16_t getInstantaneousReactiveCurrent() {
        return getInt16(1283);
    }

    void setInstantaneousReactiveCurrent(int16_t value) {
        setInt16(1283, value);
    }

    int16_t getInstantaneousPower() {
        return getInt16(1284);
    }

    void setInstantaneousPower(int16_t value) {
        setInt16(1284, value);
    }

    uint16_t getRmsVoltage() {
        return getUInt16(1285);
    }

    void setRmsVoltage(uint16_t value) {
        setUInt16(1285, value);
    }

    uint16_t getRmsVoltageMin() {
        return getUInt16(1286);
    }

    void setRmsVoltageMin(uint16_t value) {
        setUInt16(1286, value);
    }

    uint16_t getRmsVoltageMax() {
        return getUInt16(1287);
    }

    void setRmsVoltageMax(uint16_t value) {
        setUInt16(1287, value);
    }

    uint16_t getRmsCurrent() {
        return getUInt16(1288);
    }

    void setRmsCurrent(uint16_t value) {
        setUInt16(1288, value);
    }

    uint16_t getRmsCurrentMin() {
        return getUInt16(1289);
    }

    void setRmsCurrentMin(uint16_t value) {
        setUInt16(1289, value);
    }

    uint16_t getRmsCurrentMax() {
        return getUInt16(1290);
    }

    void setRmsCurrentMax(uint16_t value) {
        setUInt16(1290, value);
    }

    int16_t getActivePower() {
        return getInt16(1291);
    }

    void setActivePower(int16_t value) {
        setInt16(1291, value);
    }

    int16_t getActivePowerMin() {
        return getInt16(1292);
    }

    void setActivePowerMin(int16_t value) {
        setInt16(1292, value);
    }

    int16_t getActivePowerMax() {
        return getInt16(1293);
    }

    void setActivePowerMax(int16_t value) {
        setInt16(1293, value);
    }

    int16_t getReactivePower() {
        return getInt16(1294);
    }

    void setReactivePower(int16_t value) {
        setInt16(1294, value);
    }

    uint16_t getApparentPower() {
        return getUInt16(1295);
    }

    void setApparentPower(uint16_t value) {
        setUInt16(1295, value);
    }

    int8_t getPowerFactor() {
        return getInt8(1296);
    }

    void setPowerFactor(int8_t value) {
        setInt8(1296, value);
    }

    uint16_t getAverageRmsVoltageMeasPeriod() {
        return getUInt16(1297);
    }

    void setAverageRmsVoltageMeasPeriod(uint16_t value) {
        setUInt16(1297, value);
    }

    uint16_t getAverageRmsOverVoltageCounter() {
        return getUInt16(1298);
    }

    void setAverageRmsOverVoltageCounter(uint16_t value) {
        setUInt16(1298, value);
    }

    uint16_t getAverageRmsUnderVoltageCounter() {
        return getUInt16(1299);
    }

    void setAverageRmsUnderVoltageCounter(uint16_t value) {
        setUInt16(1299, value);
    }

    uint16_t getRmsExtremeOverVoltagePeriod() {
        return getUInt16(1300);
    }

    void setRmsExtremeOverVoltagePeriod(uint16_t value) {
        setUInt16(1300, value);
    }

    uint16_t getRmsExtremeUnderVoltagePeriod() {
        return getUInt16(1301);
    }

    void setRmsExtremeUnderVoltagePeriod(uint16_t value) {
        setUInt16(1301, value);
    }

    uint16_t getRmsVoltageSagPeriod() {
        return getUInt16(1302);
    }

    void setRmsVoltageSagPeriod(uint16_t value) {
        setUInt16(1302, value);
    }

    uint16_t getRmsVoltageSwellPeriod() {
        return getUInt16(1303);
    }

    void setRmsVoltageSwellPeriod(uint16_t value) {
        setUInt16(1303, value);
    }

    uint16_t getAcVoltageMultiplier() {
        return getUInt16(1536);
    }

    void setAcVoltageMultiplier(uint16_t value) {
        setUInt16(1536, value);
    }

    uint16_t getAcVoltageDivisor() {
        return getUInt16(1537);
    }

    void setAcVoltageDivisor(uint16_t value) {
        setUInt16(1537, value);
    }

    uint16_t getAcCurrentMultiplier() {
        return getUInt16(1538);
    }

    void setAcCurrentMultiplier(uint16_t value) {
        setUInt16(1538, value);
    }

    uint16_t getAcCurrentDivisor() {
        return getUInt16(1539);
    }

    void setAcCurrentDivisor(uint16_t value) {
        setUInt16(1539, value);
    }

    uint16_t getAcPowerMultiplier() {
        return getUInt16(1540);
    }

    void setAcPowerMultiplier(uint16_t value) {
        setUInt16(1540, value);
    }

    uint16_t getAcPowerDivisor() {
        return getUInt16(1541);
    }

    void setAcPowerDivisor(uint16_t value) {
        setUInt16(1541, value);
    }

    uint8_t getDcOverloadAlarmsMask() {
        return getMap8(1792);
    }

    void setDcOverloadAlarmsMask(uint8_t value) {
        setMap8(1792, value);
    }

    int16_t getDcVoltageOverload() {
        return getInt16(1793);
    }

    void setDcVoltageOverload(int16_t value) {
        setInt16(1793, value);
    }

    int16_t getDcCurrentOverload() {
        return getInt16(1794);
    }

    void setDcCurrentOverload(int16_t value) {
        setInt16(1794, value);
    }

    uint16_t getAcAlarmsMask() {
        return getMap16(2048);
    }

    void setAcAlarmsMask(uint16_t value) {
        setMap16(2048, value);
    }

    int16_t getAcVoltageOverload() {
        return getInt16(2049);
    }

    void setAcVoltageOverload(int16_t value) {
        setInt16(2049, value);
    }

    int16_t getAcCurrentOverload() {
        return getInt16(2050);
    }

    void setAcCurrentOverload(int16_t value) {
        setInt16(2050, value);
    }

    int16_t getAcActivePowerOverload() {
        return getInt16(2051);
    }

    void setAcActivePowerOverload(int16_t value) {
        setInt16(2051, value);
    }

    int16_t getAcReactivePowerOverload() {
        return getInt16(2052);
    }

    void setAcReactivePowerOverload(int16_t value) {
        setInt16(2052, value);
    }

    int16_t getAverageRmsOverVoltage() {
        return getInt16(2053);
    }

    void setAverageRmsOverVoltage(int16_t value) {
        setInt16(2053, value);
    }

    int16_t getAverageRmsUnderVoltage() {
        return getInt16(2054);
    }

    void setAverageRmsUnderVoltage(int16_t value) {
        setInt16(2054, value);
    }

    int16_t getRmsExtremeOverVoltage() {
        return getInt16(2055);
    }

    void setRmsExtremeOverVoltage(int16_t value) {
        setInt16(2055, value);
    }

    int16_t getRmsExtremeUnderVoltage() {
        return getInt16(2056);
    }

    void setRmsExtremeUnderVoltage(int16_t value) {
        setInt16(2056, value);
    }

    int16_t getRmsVoltageSag() {
        return getInt16(2057);
    }

    void setRmsVoltageSag(int16_t value) {
        setInt16(2057, value);
    }

    int16_t getRmsVoltageSwell() {
        return getInt16(2058);
    }

    void setRmsVoltageSwell(int16_t value) {
        setInt16(2058, value);
    }

    uint16_t getLineCurrentPhB() {
        return getUInt16(2305);
    }

    void setLineCurrentPhB(uint16_t value) {
        setUInt16(2305, value);
    }

    int16_t getActiveCurrentPhB() {
        return getInt16(2306);
    }

    void setActiveCurrentPhB(int16_t value) {
        setInt16(2306, value);
    }

    int16_t getReactiveCurrentPhB() {
        return getInt16(2307);
    }

    void setReactiveCurrentPhB(int16_t value) {
        setInt16(2307, value);
    }

    uint16_t getRmsVoltagePhB() {
        return getUInt16(2309);
    }

    void setRmsVoltagePhB(uint16_t value) {
        setUInt16(2309, value);
    }

    uint16_t getRmsVoltageMinPhB() {
        return getUInt16(2310);
    }

    void setRmsVoltageMinPhB(uint16_t value) {
        setUInt16(2310, value);
    }

    uint16_t getRmsVoltageMaxPhB() {
        return getUInt16(2311);
    }

    void setRmsVoltageMaxPhB(uint16_t value) {
        setUInt16(2311, value);
    }

    uint16_t getRmsCurrentPhB() {
        return getUInt16(2312);
    }

    void setRmsCurrentPhB(uint16_t value) {
        setUInt16(2312, value);
    }

    uint16_t getRmsCurrentMinPhB() {
        return getUInt16(2313);
    }

    void setRmsCurrentMinPhB(uint16_t value) {
        setUInt16(2313, value);
    }

    uint16_t getRmsCurrentMaxPhB() {
        return getUInt16(2314);
    }

    void setRmsCurrentMaxPhB(uint16_t value) {
        setUInt16(2314, value);
    }

    int16_t getActivePowerPhB() {
        return getInt16(2315);
    }

    void setActivePowerPhB(int16_t value) {
        setInt16(2315, value);
    }

    int16_t getActivePowerMinPhB() {
        return getInt16(2316);
    }

    void setActivePowerMinPhB(int16_t value) {
        setInt16(2316, value);
    }

    int16_t getActivePowerMaxPhB() {
        return getInt16(2317);
    }

    void setActivePowerMaxPhB(int16_t value) {
        setInt16(2317, value);
    }

    int16_t getReactivePowerPhB() {
        return getInt16(2318);
    }

    void setReactivePowerPhB(int16_t value) {
        setInt16(2318, value);
    }

    uint16_t getApparentPowerPhB() {
        return getUInt16(2319);
    }

    void setApparentPowerPhB(uint16_t value) {
        setUInt16(2319, value);
    }

    int8_t getPowerFactorPhB() {
        return getInt8(2320);
    }

    void setPowerFactorPhB(int8_t value) {
        setInt8(2320, value);
    }

    uint16_t getAverageRmsVoltageMeasurePeriodPhB() {
        return getUInt16(2321);
    }

    void setAverageRmsVoltageMeasurePeriodPhB(uint16_t value) {
        setUInt16(2321, value);
    }

    uint16_t getAverageRmsOverVoltageCounterPhB() {
        return getUInt16(2322);
    }

    void setAverageRmsOverVoltageCounterPhB(uint16_t value) {
        setUInt16(2322, value);
    }

    uint16_t getAverageUnderVoltageCounterPhB() {
        return getUInt16(2323);
    }

    void setAverageUnderVoltageCounterPhB(uint16_t value) {
        setUInt16(2323, value);
    }

    uint16_t getRmsExtremeOverVoltagePeriodPhB() {
        return getUInt16(2324);
    }

    void setRmsExtremeOverVoltagePeriodPhB(uint16_t value) {
        setUInt16(2324, value);
    }

    uint16_t getRmsExtremeUnderVoltagePeriodPhB() {
        return getUInt16(2325);
    }

    void setRmsExtremeUnderVoltagePeriodPhB(uint16_t value) {
        setUInt16(2325, value);
    }

    uint16_t getRmsVoltageSagPeriodPhB() {
        return getUInt16(2326);
    }

    void setRmsVoltageSagPeriodPhB(uint16_t value) {
        setUInt16(2326, value);
    }

    uint16_t getRmsVoltageSwellPeriodPhB() {
        return getUInt16(2327);
    }

    void setRmsVoltageSwellPeriodPhB(uint16_t value) {
        setUInt16(2327, value);
    }

    uint16_t getLineCurrentPhC() {
        return getUInt16(2561);
    }

    void setLineCurrentPhC(uint16_t value) {
        setUInt16(2561, value);
    }

    int16_t getActiveCurrentPhC() {
        return getInt16(2562);
    }

    void setActiveCurrentPhC(int16_t value) {
        setInt16(2562, value);
    }

    int16_t getReactiveCurrentPhC() {
        return getInt16(2563);
    }

    void setReactiveCurrentPhC(int16_t value) {
        setInt16(2563, value);
    }

    uint16_t getRmsVoltagePhC() {
        return getUInt16(2565);
    }

    void setRmsVoltagePhC(uint16_t value) {
        setUInt16(2565, value);
    }

    uint16_t getRmsVoltageMinPhC() {
        return getUInt16(2566);
    }

    void setRmsVoltageMinPhC(uint16_t value) {
        setUInt16(2566, value);
    }

    uint16_t getRmsVoltageMaxPhC() {
        return getUInt16(2567);
    }

    void setRmsVoltageMaxPhC(uint16_t value) {
        setUInt16(2567, value);
    }

    uint16_t getRmsCurrentPhC() {
        return getUInt16(2568);
    }

    void setRmsCurrentPhC(uint16_t value) {
        setUInt16(2568, value);
    }

    uint16_t getRmsCurrentMinPhC() {
        return getUInt16(2569);
    }

    void setRmsCurrentMinPhC(uint16_t value) {
        setUInt16(2569, value);
    }

    uint16_t getRmsCurrentMaxPhC() {
        return getUInt16(2570);
    }

    void setRmsCurrentMaxPhC(uint16_t value) {
        setUInt16(2570, value);
    }

    int16_t getActivePowerPhC() {
        return getInt16(2571);
    }

    void setActivePowerPhC(int16_t value) {
        setInt16(2571, value);
    }

    int16_t getActivePowerMinPhC() {
        return getInt16(2572);
    }

    void setActivePowerMinPhC(int16_t value) {
        setInt16(2572, value);
    }

    int16_t getActivePowerMaxPhC() {
        return getInt16(2573);
    }

    void setActivePowerMaxPhC(int16_t value) {
        setInt16(2573, value);
    }

    int16_t getReactivePowerPhC() {
        return getInt16(2574);
    }

    void setReactivePowerPhC(int16_t value) {
        setInt16(2574, value);
    }

    uint16_t getApparentPowerPhC() {
        return getUInt16(2575);
    }

    void setApparentPowerPhC(uint16_t value) {
        setUInt16(2575, value);
    }

    int8_t getPowerFactorPhC() {
        return getInt8(2576);
    }

    void setPowerFactorPhC(int8_t value) {
        setInt8(2576, value);
    }

    uint16_t getAverageRmsVoltageMeasPeriodPhC() {
        return getUInt16(2577);
    }

    void setAverageRmsVoltageMeasPeriodPhC(uint16_t value) {
        setUInt16(2577, value);
    }

    uint16_t getAverageRmsOverVoltageCounterPhC() {
        return getUInt16(2578);
    }

    void setAverageRmsOverVoltageCounterPhC(uint16_t value) {
        setUInt16(2578, value);
    }

    uint16_t getAverageUnderVoltageCounterPhC() {
        return getUInt16(2579);
    }

    void setAverageUnderVoltageCounterPhC(uint16_t value) {
        setUInt16(2579, value);
    }

    uint16_t getRmsExtremeOverVoltagePeriodPhC() {
        return getUInt16(2580);
    }

    void setRmsExtremeOverVoltagePeriodPhC(uint16_t value) {
        setUInt16(2580, value);
    }

    uint16_t getRmsExtremeUnderVoltagePeriodPhC() {
        return getUInt16(2581);
    }

    void setRmsExtremeUnderVoltagePeriodPhC(uint16_t value) {
        setUInt16(2581, value);
    }

    uint16_t getRmsVoltageSagPeriodPhC() {
        return getUInt16(2582);
    }

    void setRmsVoltageSagPeriodPhC(uint16_t value) {
        setUInt16(2582, value);
    }

    uint16_t getRmsVoltageSwellPeriodPhC() {
        return getUInt16(2583);
    }

    void setRmsVoltageSwellPeriodPhC(uint16_t value) {
        setUInt16(2583, value);
    }

    virtual Status getProfileInfoCommand() {
        return Status::UnsupportedAttribute;
    }

    virtual Status getMeasurementProfileCommand(uint16_t attrId, uint32_t starttime, uint8_t numofuntervals) {
        return Status::UnsupportedAttribute;
    }

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto status_ = getProfileInfoCommand();
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto attrId = request.readUInt16Le();
                auto starttime = request.readUInt32Le();
                auto numofuntervals = request.readUInt8();
                auto status_ = getMeasurementProfileCommand(attrId, starttime, numofuntervals);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class HaDiagnosticCluster: public Cluster {
public:
    HaDiagnosticCluster() : Cluster(2821) {
    }

    uint16_t getNumberOfResets() {
        return getUInt16(0);
    }

    void setNumberOfResets(uint16_t value) {
        setUInt16(0, value);
    }

    uint16_t getPersistentMemoryWrites() {
        return getUInt16(1);
    }

    void setPersistentMemoryWrites(uint16_t value) {
        setUInt16(1, value);
    }

    uint32_t getMacRxBcast() {
        return getUInt32(256);
    }

    void setMacRxBcast(uint32_t value) {
        setUInt32(256, value);
    }

    uint32_t getMacTxBcast() {
        return getUInt32(257);
    }

    void setMacTxBcast(uint32_t value) {
        setUInt32(257, value);
    }

    uint32_t getMacRxUcast() {
        return getUInt32(258);
    }

    void setMacRxUcast(uint32_t value) {
        setUInt32(258, value);
    }

    uint32_t getMacTxUcast() {
        return getUInt32(259);
    }

    void setMacTxUcast(uint32_t value) {
        setUInt32(259, value);
    }

    uint16_t getMacTxUcastRetry() {
        return getUInt16(260);
    }

    void setMacTxUcastRetry(uint16_t value) {
        setUInt16(260, value);
    }

    uint16_t getMacTxUcastFail() {
        return getUInt16(261);
    }

    void setMacTxUcastFail(uint16_t value) {
        setUInt16(261, value);
    }

    uint16_t getAPSRxBcast() {
        return getUInt16(262);
    }

    void setAPSRxBcast(uint16_t value) {
        setUInt16(262, value);
    }

    uint16_t getAPSTxBcast() {
        return getUInt16(263);
    }

    void setAPSTxBcast(uint16_t value) {
        setUInt16(263, value);
    }

    uint16_t getAPSRxUcast() {
        return getUInt16(264);
    }

    void setAPSRxUcast(uint16_t value) {
        setUInt16(264, value);
    }

    uint16_t getAPSTxUcastSuccess() {
        return getUInt16(265);
    }

    void setAPSTxUcastSuccess(uint16_t value) {
        setUInt16(265, value);
    }

    uint16_t getAPSTxUcastRetry() {
        return getUInt16(266);
    }

    void setAPSTxUcastRetry(uint16_t value) {
        setUInt16(266, value);
    }

    uint16_t getAPSTxUcastFail() {
        return getUInt16(267);
    }

    void setAPSTxUcastFail(uint16_t value) {
        setUInt16(267, value);
    }

    uint16_t getRouteDiscInitiated() {
        return getUInt16(268);
    }

    void setRouteDiscInitiated(uint16_t value) {
        setUInt16(268, value);
    }

    uint16_t getNeighborAdded() {
        return getUInt16(269);
    }

    void setNeighborAdded(uint16_t value) {
        setUInt16(269, value);
    }

    uint16_t getNeighborRemoved() {
        return getUInt16(270);
    }

    void setNeighborRemoved(uint16_t value) {
        setUInt16(270, value);
    }

    uint16_t getNeighborStale() {
        return getUInt16(271);
    }

    void setNeighborStale(uint16_t value) {
        setUInt16(271, value);
    }

    uint16_t getJoinIndication() {
        return getUInt16(272);
    }

    void setJoinIndication(uint16_t value) {
        setUInt16(272, value);
    }

    uint16_t getChildMoved() {
        return getUInt16(273);
    }

    void setChildMoved(uint16_t value) {
        setUInt16(273, value);
    }

    uint16_t getNwkFcFailure() {
        return getUInt16(274);
    }

    void setNwkFcFailure(uint16_t value) {
        setUInt16(274, value);
    }

    uint16_t getApsFcFailure() {
        return getUInt16(275);
    }

    void setApsFcFailure(uint16_t value) {
        setUInt16(275, value);
    }

    uint16_t getApsUnauthorizedKey() {
        return getUInt16(276);
    }

    void setApsUnauthorizedKey(uint16_t value) {
        setUInt16(276, value);
    }

    uint16_t getNwkDecryptFailures() {
        return getUInt16(277);
    }

    void setNwkDecryptFailures(uint16_t value) {
        setUInt16(277, value);
    }

    uint16_t getApsDecryptFailures() {
        return getUInt16(278);
    }

    void setApsDecryptFailures(uint16_t value) {
        setUInt16(278, value);
    }

    uint16_t getPacketBufferAllocateFailures() {
        return getUInt16(279);
    }

    void setPacketBufferAllocateFailures(uint16_t value) {
        setUInt16(279, value);
    }

    uint16_t getRelayedUcast() {
        return getUInt16(280);
    }

    void setRelayedUcast(uint16_t value) {
        setUInt16(280, value);
    }

    uint16_t getPhyToMacQueueLimitReached() {
        return getUInt16(281);
    }

    void setPhyToMacQueueLimitReached(uint16_t value) {
        setUInt16(281, value);
    }

    uint16_t getPacketValidateDropCount() {
        return getUInt16(282);
    }

    void setPacketValidateDropCount(uint16_t value) {
        setUInt16(282, value);
    }

    uint16_t getAverageMacRetryPerApsMessageSent() {
        return getUInt16(283);
    }

    void setAverageMacRetryPerApsMessageSent(uint16_t value) {
        setUInt16(283, value);
    }

    uint8_t getLastMessageLqi() {
        return getUInt8(284);
    }

    void setLastMessageLqi(uint8_t value) {
        setUInt8(284, value);
    }

    int8_t getLastMessageRssi() {
        return getInt8(285);
    }

    void setLastMessageRssi(int8_t value) {
        setInt8(285, value);
    }
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
        void setTransactionID(uint32_t value) { _transactionID = value; }

        uint8_t getRssiCorrection() { return _rssiCorrection; }
        void setRssiCorrection(uint8_t value) { _rssiCorrection = value; }

        uint8_t getZigbeeInformation() { return _zigbeeInformation; }
        void setZigbeeInformation(uint8_t value) { _zigbeeInformation = value; }

        uint8_t getTouchlinkInformation() { return _touchlinkInformation; }
        void setTouchlinkInformation(uint8_t value) { _touchlinkInformation = value; }

        uint16_t getKeyBitmask() { return _keyBitmask; }
        void setKeyBitmask(uint16_t value) { _keyBitmask = value; }

        uint32_t getResponseID() { return _responseID; }
        void setResponseID(uint32_t value) { _responseID = value; }

        uint64_t getExtendedPanID() { return _extendedPanID; }
        void setExtendedPanID(uint64_t value) { _extendedPanID = value; }

        uint8_t getNetworkUpdateID() { return _networkUpdateID; }
        void setNetworkUpdateID(uint8_t value) { _networkUpdateID = value; }

        uint8_t getLogicalChannel() { return _logicalChannel; }
        void setLogicalChannel(uint8_t value) { _logicalChannel = value; }

        uint16_t getPanID() { return _panID; }
        void setPanID(uint16_t value) { _panID = value; }

        uint16_t getNetworkAddress() { return _networkAddress; }
        void setNetworkAddress(uint16_t value) { _networkAddress = value; }

        uint8_t getNumberOfSubDevices() { return _numberOfSubDevices; }
        void setNumberOfSubDevices(uint8_t value) { _numberOfSubDevices = value; }

        uint8_t getTotalGroupIdentifiers() { return _totalGroupIdentifiers; }
        void setTotalGroupIdentifiers(uint8_t value) { _totalGroupIdentifiers = value; }

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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto transactionID = request.readUInt32Le();
                auto zigbeeInformation = request.readUInt8();
                auto touchlinkInformation = request.readUInt8();
                ScanRequestCommandResponse response_;
                auto status_ = scanRequestCommand(transactionID, zigbeeInformation, touchlinkInformation, response_);
                response.writeUInt8((uint8_t)status_);
                if (status_ == Status::Success) {
                    response.writeUInt32Le(response_.getTransactionID());
                    response.writeUInt8(response_.getRssiCorrection());
                    response.writeUInt8(response_.getZigbeeInformation());
                    response.writeUInt8(response_.getTouchlinkInformation());
                    response.writeUInt16Le(response_.getKeyBitmask());
                    response.writeUInt32Le(response_.getResponseID());
                    response.writeUInt64Le(response_.getExtendedPanID());
                    response.writeUInt8(response_.getNetworkUpdateID());
                    response.writeUInt8(response_.getLogicalChannel());
                    response.writeUInt16Le(response_.getPanID());
                    response.writeUInt16Le(response_.getNetworkAddress());
                    response.writeUInt8(response_.getNumberOfSubDevices());
                    response.writeUInt8(response_.getTotalGroupIdentifiers());
                }
                return;
            }
            case 6: {
                auto transactionID = request.readUInt32Le();
                auto duration = request.readUInt16Le();
                auto status_ = identifyRequestCommand(transactionID, duration);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 7: {
                auto transactionID = request.readUInt32Le();
                auto status_ = resetToFactoryNewCommand(transactionID);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class WiserDeviceInfoCluster: public Cluster {
public:
    WiserDeviceInfoCluster() : Cluster(65027) {
    }

    String getDeviceInfo() {
        return getString(32);
    }

    void setDeviceInfo(const String& value) {
        setString(32, value);
    }
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

    void processCommand(uint8_t commandId, Memory& request, Memory& response) override {
        switch (commandId) {
            case 0: {
                auto seq = request.readUInt16Le();
                auto length = request.readUInt32Le();
                auto unk1 = request.readUInt32Le();
                auto unk2 = request.readUInt16Le();
                auto unk3 = request.readUInt8();
                auto cmd = request.readUInt8();
                auto unk4 = request.readUInt16Le();
                auto status_ = zosungSendIRCode00Command(seq, length, unk1, unk2, unk3, cmd, unk4);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 1: {
                auto zero = request.readUInt8();
                auto seq = request.readUInt16Le();
                auto length = request.readUInt32Le();
                auto unk1 = request.readUInt32Le();
                auto unk2 = request.readUInt16Le();
                auto unk3 = request.readUInt8();
                auto cmd = request.readUInt8();
                auto unk4 = request.readUInt16Le();
                auto status_ = zosungSendIRCode01Command(zero, seq, length, unk1, unk2, unk3, cmd, unk4);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 2: {
                auto seq = request.readUInt16Le();
                auto position = request.readUInt32Le();
                auto maxlen = request.readUInt8();
                auto status_ = zosungSendIRCode02Command(seq, position, maxlen);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 3: {
                auto zero = request.readUInt8();
                auto seq = request.readUInt16Le();
                auto position = request.readUInt32Le();
                auto msgpart = request.readOctstr();
                auto msgpartcrc = request.readUInt8();
                auto status_ = zosungSendIRCode03Command(zero, seq, position, msgpart, msgpartcrc);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 4: {
                auto zero0 = request.readUInt8();
                auto seq = request.readUInt16Le();
                auto zero1 = request.readUInt16Le();
                auto status_ = zosungSendIRCode04Command(zero0, seq, zero1);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            case 5: {
                auto seq = request.readUInt16Le();
                auto zero = request.readUInt16Le();
                auto status_ = zosungSendIRCode05Command(seq, zero);
                response.writeUInt8((uint8_t)status_);
                return;
            }
            default:
                Cluster::processCommand(commandId, request, response);
                return;
        }
    }
};

class ZosungIRControlCluster: public Cluster {
public:
    ZosungIRControlCluster() : Cluster(57348) {
    }
};
