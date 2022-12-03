#include "ZigBeeHomeAutomation.h"

AttributeUInt8* GenBasicCluster::getZclVersion() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBasicCluster::getAppVersion() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBasicCluster::getStackVersion() {
    auto result = (AttributeUInt8*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt8(2, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBasicCluster::getHwVersion() {
    auto result = (AttributeUInt8*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt8(3, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBasicCluster::getManufacturerName() {
    auto result = (AttributeString*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeString(4, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBasicCluster::getModelId() {
    auto result = (AttributeString*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeString(5, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBasicCluster::getDateCode() {
    auto result = (AttributeString*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeString(6, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBasicCluster::getPowerSource() {
    auto result = (AttributeUInt8*)getAttributeById(7);
    if (result == nullptr) {
        result = new AttributeUInt8(7, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBasicCluster::getAppProfileVersion() {
    auto result = (AttributeUInt8*)getAttributeById(8);
    if (result == nullptr) {
        result = new AttributeUInt8(8, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBasicCluster::getSwBuildId() {
    auto result = (AttributeString*)getAttributeById(16384);
    if (result == nullptr) {
        result = new AttributeString(16384, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBasicCluster::getLocationDesc() {
    auto result = (AttributeString*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeString(16, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBasicCluster::getPhysicalEnv() {
    auto result = (AttributeUInt8*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt8(17, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBasicCluster::getDeviceEnabled() {
    auto result = (AttributeUInt8*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt8(18, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBasicCluster::getAlarmMask() {
    auto result = (AttributeUInt8*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt8(19, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBasicCluster::getDisableLocalConfig() {
    auto result = (AttributeUInt8*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeUInt8(20, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

void GenBasicCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt16* GenPowerCfgCluster::getMainsVoltage() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getMainsFrequency() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getMainsAlarmMask() {
    auto result = (AttributeUInt8*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt8(16, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenPowerCfgCluster::getMainsVoltMinThres() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenPowerCfgCluster::getMainsVoltMaxThres() {
    auto result = (AttributeUInt16*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt16(18, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenPowerCfgCluster::getMainsVoltageDwellTripPoint() {
    auto result = (AttributeUInt16*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt16(19, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryVoltage() {
    auto result = (AttributeUInt8*)getAttributeById(32);
    if (result == nullptr) {
        result = new AttributeUInt8(32, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryPercentageRemaining() {
    auto result = (AttributeUInt8*)getAttributeById(33);
    if (result == nullptr) {
        result = new AttributeUInt8(33, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenPowerCfgCluster::getBatteryManufacturer() {
    auto result = (AttributeString*)getAttributeById(48);
    if (result == nullptr) {
        result = new AttributeString(48, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatterySize() {
    auto result = (AttributeUInt8*)getAttributeById(49);
    if (result == nullptr) {
        result = new AttributeUInt8(49, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenPowerCfgCluster::getBatteryAHrRating() {
    auto result = (AttributeUInt16*)getAttributeById(50);
    if (result == nullptr) {
        result = new AttributeUInt16(50, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryQuantity() {
    auto result = (AttributeUInt8*)getAttributeById(51);
    if (result == nullptr) {
        result = new AttributeUInt8(51, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryRatedVoltage() {
    auto result = (AttributeUInt8*)getAttributeById(52);
    if (result == nullptr) {
        result = new AttributeUInt8(52, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryAlarmMask() {
    auto result = (AttributeUInt8*)getAttributeById(53);
    if (result == nullptr) {
        result = new AttributeUInt8(53, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryVoltMinThres() {
    auto result = (AttributeUInt8*)getAttributeById(54);
    if (result == nullptr) {
        result = new AttributeUInt8(54, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryVoltThres1() {
    auto result = (AttributeUInt8*)getAttributeById(55);
    if (result == nullptr) {
        result = new AttributeUInt8(55, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryVoltThres2() {
    auto result = (AttributeUInt8*)getAttributeById(56);
    if (result == nullptr) {
        result = new AttributeUInt8(56, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryVoltThres3() {
    auto result = (AttributeUInt8*)getAttributeById(57);
    if (result == nullptr) {
        result = new AttributeUInt8(57, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryPercentMinThres() {
    auto result = (AttributeUInt8*)getAttributeById(58);
    if (result == nullptr) {
        result = new AttributeUInt8(58, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryPercentThres1() {
    auto result = (AttributeUInt8*)getAttributeById(59);
    if (result == nullptr) {
        result = new AttributeUInt8(59, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryPercentThres2() {
    auto result = (AttributeUInt8*)getAttributeById(60);
    if (result == nullptr) {
        result = new AttributeUInt8(60, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenPowerCfgCluster::getBatteryPercentThres3() {
    auto result = (AttributeUInt8*)getAttributeById(61);
    if (result == nullptr) {
        result = new AttributeUInt8(61, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenPowerCfgCluster::getBatteryAlarmState() {
    auto result = (AttributeUInt32*)getAttributeById(62);
    if (result == nullptr) {
        result = new AttributeUInt32(62, DataType::Map32);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* GenDeviceTempCfgCluster::getCurrentTemperature() {
    auto result = (AttributeInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeInt16(0, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* GenDeviceTempCfgCluster::getMinTempExperienced() {
    auto result = (AttributeInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeInt16(1, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* GenDeviceTempCfgCluster::getMaxTempExperienced() {
    auto result = (AttributeInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeInt16(2, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenDeviceTempCfgCluster::getOverTempTotalDwell() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenDeviceTempCfgCluster::getDevTempAlarmMask() {
    auto result = (AttributeUInt8*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt8(16, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* GenDeviceTempCfgCluster::getLowTempThres() {
    auto result = (AttributeInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeInt16(17, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* GenDeviceTempCfgCluster::getHighTempThres() {
    auto result = (AttributeInt16*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeInt16(18, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* GenDeviceTempCfgCluster::getLowTempDwellTripPoint() {
    auto result = (AttributeUInt24*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt24(19, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* GenDeviceTempCfgCluster::getHighTempDwellTripPoint() {
    auto result = (AttributeUInt24*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeUInt24(20, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenIdentifyCluster::getIdentifyTime() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

void GenIdentifyCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt8* GenGroupsCluster::getNameSupport() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

void GenGroupsCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt8* GenScenesCluster::getCount() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenScenesCluster::getCurrentScene() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenScenesCluster::getCurrentGroup() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenScenesCluster::getSceneValid() {
    auto result = (AttributeUInt8*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt8(3, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenScenesCluster::getNameSupport() {
    auto result = (AttributeUInt8*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt8(4, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt64* GenScenesCluster::getLastCfgBy() {
    auto result = (AttributeUInt64*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt64(5, DataType::EUI64);
        addAttribute(result);
    }
    return result;
}

void GenScenesCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt8* GenOnOffCluster::getOnOff() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenOnOffCluster::getGlobalSceneCtrl() {
    auto result = (AttributeUInt8*)getAttributeById(16384);
    if (result == nullptr) {
        result = new AttributeUInt8(16384, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenOnOffCluster::getOnTime() {
    auto result = (AttributeUInt16*)getAttributeById(16385);
    if (result == nullptr) {
        result = new AttributeUInt16(16385, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenOnOffCluster::getOffWaitTime() {
    auto result = (AttributeUInt16*)getAttributeById(16386);
    if (result == nullptr) {
        result = new AttributeUInt16(16386, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenOnOffCluster::getStartUpOnOff() {
    auto result = (AttributeUInt8*)getAttributeById(16387);
    if (result == nullptr) {
        result = new AttributeUInt8(16387, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenOnOffCluster::getMoesStartUpOnOff() {
    auto result = (AttributeUInt8*)getAttributeById(32770);
    if (result == nullptr) {
        result = new AttributeUInt8(32770, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

void GenOnOffCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt8* GenOnOffSwitchCfgCluster::getSwitchType() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenOnOffSwitchCfgCluster::getSwitchActions() {
    auto result = (AttributeUInt8*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt8(16, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenLevelCtrlCluster::getCurrentLevel() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenLevelCtrlCluster::getRemainingTime() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenLevelCtrlCluster::getMinLevel() {
    auto result = (AttributeUInt8*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt8(2, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenLevelCtrlCluster::getMaxLevel() {
    auto result = (AttributeUInt8*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt8(3, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenLevelCtrlCluster::getOptions() {
    auto result = (AttributeUInt8*)getAttributeById(15);
    if (result == nullptr) {
        result = new AttributeUInt8(15, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenLevelCtrlCluster::getOnOffTransitionTime() {
    auto result = (AttributeUInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt16(16, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenLevelCtrlCluster::getOnLevel() {
    auto result = (AttributeUInt8*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt8(17, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenLevelCtrlCluster::getOnTransitionTime() {
    auto result = (AttributeUInt16*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt16(18, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenLevelCtrlCluster::getOffTransitionTime() {
    auto result = (AttributeUInt16*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt16(19, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenLevelCtrlCluster::getDefaultMoveRate() {
    auto result = (AttributeUInt16*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeUInt16(20, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenLevelCtrlCluster::getStartUpCurrentLevel() {
    auto result = (AttributeUInt8*)getAttributeById(16384);
    if (result == nullptr) {
        result = new AttributeUInt8(16384, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

void GenLevelCtrlCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt16* GenAlarmsCluster::getAlarmCount() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

void GenAlarmsCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt32* GenTimeCluster::getTime() {
    auto result = (AttributeUInt32*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt32(0, DataType::UTC);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenTimeCluster::getTimeStatus() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeInt32* GenTimeCluster::getTimeZone() {
    auto result = (AttributeInt32*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeInt32(2, DataType::Int32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenTimeCluster::getDstStart() {
    auto result = (AttributeUInt32*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt32(3, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenTimeCluster::getDstEnd() {
    auto result = (AttributeUInt32*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt32(4, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeInt32* GenTimeCluster::getDstShift() {
    auto result = (AttributeInt32*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeInt32(5, DataType::Int32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenTimeCluster::getStandardTime() {
    auto result = (AttributeUInt32*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt32(6, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenTimeCluster::getLocalTime() {
    auto result = (AttributeUInt32*)getAttributeById(7);
    if (result == nullptr) {
        result = new AttributeUInt32(7, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenTimeCluster::getLastSetTime() {
    auto result = (AttributeUInt32*)getAttributeById(8);
    if (result == nullptr) {
        result = new AttributeUInt32(8, DataType::UTC);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenTimeCluster::getValidUntilTime() {
    auto result = (AttributeUInt32*)getAttributeById(9);
    if (result == nullptr) {
        result = new AttributeUInt32(9, DataType::UTC);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenRssiLocationCluster::getType() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Data8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenRssiLocationCluster::getMethod() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenRssiLocationCluster::getAge() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenRssiLocationCluster::getQualityMeasure() {
    auto result = (AttributeUInt8*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt8(3, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenRssiLocationCluster::getNumOfDevices() {
    auto result = (AttributeUInt8*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt8(4, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* GenRssiLocationCluster::getCoordinate1() {
    auto result = (AttributeInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeInt16(16, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* GenRssiLocationCluster::getCoordinate2() {
    auto result = (AttributeInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeInt16(17, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* GenRssiLocationCluster::getCoordinate3() {
    auto result = (AttributeInt16*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeInt16(18, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* GenRssiLocationCluster::getPower() {
    auto result = (AttributeInt16*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeInt16(19, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenRssiLocationCluster::getPathLossExponent() {
    auto result = (AttributeUInt16*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeUInt16(20, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenRssiLocationCluster::getReportingPeriod() {
    auto result = (AttributeUInt16*)getAttributeById(21);
    if (result == nullptr) {
        result = new AttributeUInt16(21, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenRssiLocationCluster::getCalcPeriod() {
    auto result = (AttributeUInt16*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeUInt16(22, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenRssiLocationCluster::getNumRSSIMeasurements() {
    auto result = (AttributeUInt16*)getAttributeById(23);
    if (result == nullptr) {
        result = new AttributeUInt16(23, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

void GenRssiLocationCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeString* GenAnalogInputCluster::getDescription() {
    auto result = (AttributeString*)getAttributeById(28);
    if (result == nullptr) {
        result = new AttributeString(28, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* GenAnalogInputCluster::getMaxPresentValue() {
    auto result = (AttributeSingle*)getAttributeById(65);
    if (result == nullptr) {
        result = new AttributeSingle(65, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* GenAnalogInputCluster::getMinPresentValue() {
    auto result = (AttributeSingle*)getAttributeById(69);
    if (result == nullptr) {
        result = new AttributeSingle(69, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenAnalogInputCluster::getOutOfService() {
    auto result = (AttributeUInt8*)getAttributeById(81);
    if (result == nullptr) {
        result = new AttributeUInt8(81, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* GenAnalogInputCluster::getPresentValue() {
    auto result = (AttributeSingle*)getAttributeById(85);
    if (result == nullptr) {
        result = new AttributeSingle(85, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenAnalogInputCluster::getReliability() {
    auto result = (AttributeUInt8*)getAttributeById(103);
    if (result == nullptr) {
        result = new AttributeUInt8(103, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* GenAnalogInputCluster::getResolution() {
    auto result = (AttributeSingle*)getAttributeById(106);
    if (result == nullptr) {
        result = new AttributeSingle(106, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenAnalogInputCluster::getStatusFlags() {
    auto result = (AttributeUInt8*)getAttributeById(111);
    if (result == nullptr) {
        result = new AttributeUInt8(111, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenAnalogInputCluster::getEngineeringUnits() {
    auto result = (AttributeUInt16*)getAttributeById(117);
    if (result == nullptr) {
        result = new AttributeUInt16(117, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenAnalogInputCluster::getApplicationType() {
    auto result = (AttributeUInt32*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeUInt32(256, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenAnalogOutputCluster::getDescription() {
    auto result = (AttributeString*)getAttributeById(28);
    if (result == nullptr) {
        result = new AttributeString(28, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* GenAnalogOutputCluster::getMaxPresentValue() {
    auto result = (AttributeSingle*)getAttributeById(65);
    if (result == nullptr) {
        result = new AttributeSingle(65, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* GenAnalogOutputCluster::getMinPresentValue() {
    auto result = (AttributeSingle*)getAttributeById(69);
    if (result == nullptr) {
        result = new AttributeSingle(69, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenAnalogOutputCluster::getOutOfService() {
    auto result = (AttributeUInt8*)getAttributeById(81);
    if (result == nullptr) {
        result = new AttributeUInt8(81, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* GenAnalogOutputCluster::getPresentValue() {
    auto result = (AttributeSingle*)getAttributeById(85);
    if (result == nullptr) {
        result = new AttributeSingle(85, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenAnalogOutputCluster::getReliability() {
    auto result = (AttributeUInt8*)getAttributeById(103);
    if (result == nullptr) {
        result = new AttributeUInt8(103, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* GenAnalogOutputCluster::getRelinquishDefault() {
    auto result = (AttributeSingle*)getAttributeById(104);
    if (result == nullptr) {
        result = new AttributeSingle(104, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* GenAnalogOutputCluster::getResolution() {
    auto result = (AttributeSingle*)getAttributeById(106);
    if (result == nullptr) {
        result = new AttributeSingle(106, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenAnalogOutputCluster::getStatusFlags() {
    auto result = (AttributeUInt8*)getAttributeById(111);
    if (result == nullptr) {
        result = new AttributeUInt8(111, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenAnalogOutputCluster::getEngineeringUnits() {
    auto result = (AttributeUInt16*)getAttributeById(117);
    if (result == nullptr) {
        result = new AttributeUInt16(117, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenAnalogOutputCluster::getApplicationType() {
    auto result = (AttributeUInt32*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeUInt32(256, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenAnalogValueCluster::getDescription() {
    auto result = (AttributeString*)getAttributeById(28);
    if (result == nullptr) {
        result = new AttributeString(28, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenAnalogValueCluster::getOutOfService() {
    auto result = (AttributeUInt8*)getAttributeById(81);
    if (result == nullptr) {
        result = new AttributeUInt8(81, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* GenAnalogValueCluster::getPresentValue() {
    auto result = (AttributeSingle*)getAttributeById(85);
    if (result == nullptr) {
        result = new AttributeSingle(85, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenAnalogValueCluster::getReliability() {
    auto result = (AttributeUInt8*)getAttributeById(103);
    if (result == nullptr) {
        result = new AttributeUInt8(103, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* GenAnalogValueCluster::getRelinquishDefault() {
    auto result = (AttributeSingle*)getAttributeById(104);
    if (result == nullptr) {
        result = new AttributeSingle(104, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenAnalogValueCluster::getStatusFlags() {
    auto result = (AttributeUInt8*)getAttributeById(111);
    if (result == nullptr) {
        result = new AttributeUInt8(111, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenAnalogValueCluster::getEngineeringUnits() {
    auto result = (AttributeUInt16*)getAttributeById(117);
    if (result == nullptr) {
        result = new AttributeUInt16(117, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenAnalogValueCluster::getApplicationType() {
    auto result = (AttributeUInt32*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeUInt32(256, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBinaryInputCluster::getActiveText() {
    auto result = (AttributeString*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeString(4, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBinaryInputCluster::getDescription() {
    auto result = (AttributeString*)getAttributeById(28);
    if (result == nullptr) {
        result = new AttributeString(28, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBinaryInputCluster::getInactiveText() {
    auto result = (AttributeString*)getAttributeById(46);
    if (result == nullptr) {
        result = new AttributeString(46, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryInputCluster::getOutOfService() {
    auto result = (AttributeUInt8*)getAttributeById(81);
    if (result == nullptr) {
        result = new AttributeUInt8(81, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryInputCluster::getPolarity() {
    auto result = (AttributeUInt8*)getAttributeById(84);
    if (result == nullptr) {
        result = new AttributeUInt8(84, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryInputCluster::getPresentValue() {
    auto result = (AttributeUInt8*)getAttributeById(85);
    if (result == nullptr) {
        result = new AttributeUInt8(85, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryInputCluster::getReliability() {
    auto result = (AttributeUInt8*)getAttributeById(103);
    if (result == nullptr) {
        result = new AttributeUInt8(103, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryInputCluster::getStatusFlags() {
    auto result = (AttributeUInt8*)getAttributeById(111);
    if (result == nullptr) {
        result = new AttributeUInt8(111, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenBinaryInputCluster::getApplicationType() {
    auto result = (AttributeUInt32*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeUInt32(256, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBinaryOutputCluster::getActiveText() {
    auto result = (AttributeString*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeString(4, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBinaryOutputCluster::getDescription() {
    auto result = (AttributeString*)getAttributeById(28);
    if (result == nullptr) {
        result = new AttributeString(28, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBinaryOutputCluster::getInactiveText() {
    auto result = (AttributeString*)getAttributeById(46);
    if (result == nullptr) {
        result = new AttributeString(46, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenBinaryOutputCluster::getMinimumOffTime() {
    auto result = (AttributeUInt32*)getAttributeById(66);
    if (result == nullptr) {
        result = new AttributeUInt32(66, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenBinaryOutputCluster::getMinimumOnTime() {
    auto result = (AttributeUInt32*)getAttributeById(67);
    if (result == nullptr) {
        result = new AttributeUInt32(67, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryOutputCluster::getOutOfService() {
    auto result = (AttributeUInt8*)getAttributeById(81);
    if (result == nullptr) {
        result = new AttributeUInt8(81, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryOutputCluster::getPolarity() {
    auto result = (AttributeUInt8*)getAttributeById(84);
    if (result == nullptr) {
        result = new AttributeUInt8(84, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryOutputCluster::getPresentValue() {
    auto result = (AttributeUInt8*)getAttributeById(85);
    if (result == nullptr) {
        result = new AttributeUInt8(85, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryOutputCluster::getReliability() {
    auto result = (AttributeUInt8*)getAttributeById(103);
    if (result == nullptr) {
        result = new AttributeUInt8(103, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryOutputCluster::getRelinquishDefault() {
    auto result = (AttributeUInt8*)getAttributeById(104);
    if (result == nullptr) {
        result = new AttributeUInt8(104, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryOutputCluster::getStatusFlags() {
    auto result = (AttributeUInt8*)getAttributeById(111);
    if (result == nullptr) {
        result = new AttributeUInt8(111, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenBinaryOutputCluster::getApplicationType() {
    auto result = (AttributeUInt32*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeUInt32(256, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBinaryValueCluster::getActiveText() {
    auto result = (AttributeString*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeString(4, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBinaryValueCluster::getDescription() {
    auto result = (AttributeString*)getAttributeById(28);
    if (result == nullptr) {
        result = new AttributeString(28, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenBinaryValueCluster::getInactiveText() {
    auto result = (AttributeString*)getAttributeById(46);
    if (result == nullptr) {
        result = new AttributeString(46, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenBinaryValueCluster::getMinimumOffTime() {
    auto result = (AttributeUInt32*)getAttributeById(66);
    if (result == nullptr) {
        result = new AttributeUInt32(66, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenBinaryValueCluster::getMinimumOnTime() {
    auto result = (AttributeUInt32*)getAttributeById(67);
    if (result == nullptr) {
        result = new AttributeUInt32(67, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryValueCluster::getOutOfService() {
    auto result = (AttributeUInt8*)getAttributeById(81);
    if (result == nullptr) {
        result = new AttributeUInt8(81, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryValueCluster::getPresentValue() {
    auto result = (AttributeUInt8*)getAttributeById(85);
    if (result == nullptr) {
        result = new AttributeUInt8(85, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryValueCluster::getReliability() {
    auto result = (AttributeUInt8*)getAttributeById(103);
    if (result == nullptr) {
        result = new AttributeUInt8(103, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryValueCluster::getRelinquishDefault() {
    auto result = (AttributeUInt8*)getAttributeById(104);
    if (result == nullptr) {
        result = new AttributeUInt8(104, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenBinaryValueCluster::getStatusFlags() {
    auto result = (AttributeUInt8*)getAttributeById(111);
    if (result == nullptr) {
        result = new AttributeUInt8(111, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenBinaryValueCluster::getApplicationType() {
    auto result = (AttributeUInt32*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeUInt32(256, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenMultistateInputCluster::getDescription() {
    auto result = (AttributeString*)getAttributeById(28);
    if (result == nullptr) {
        result = new AttributeString(28, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenMultistateInputCluster::getNumberOfStates() {
    auto result = (AttributeUInt16*)getAttributeById(74);
    if (result == nullptr) {
        result = new AttributeUInt16(74, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenMultistateInputCluster::getOutOfService() {
    auto result = (AttributeUInt8*)getAttributeById(81);
    if (result == nullptr) {
        result = new AttributeUInt8(81, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenMultistateInputCluster::getPresentValue() {
    auto result = (AttributeUInt16*)getAttributeById(85);
    if (result == nullptr) {
        result = new AttributeUInt16(85, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenMultistateInputCluster::getReliability() {
    auto result = (AttributeUInt8*)getAttributeById(103);
    if (result == nullptr) {
        result = new AttributeUInt8(103, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenMultistateInputCluster::getStatusFlags() {
    auto result = (AttributeUInt8*)getAttributeById(111);
    if (result == nullptr) {
        result = new AttributeUInt8(111, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenMultistateInputCluster::getApplicationType() {
    auto result = (AttributeUInt32*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeUInt32(256, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenMultistateOutputCluster::getDescription() {
    auto result = (AttributeString*)getAttributeById(28);
    if (result == nullptr) {
        result = new AttributeString(28, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenMultistateOutputCluster::getNumberOfStates() {
    auto result = (AttributeUInt16*)getAttributeById(74);
    if (result == nullptr) {
        result = new AttributeUInt16(74, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenMultistateOutputCluster::getOutOfService() {
    auto result = (AttributeUInt8*)getAttributeById(81);
    if (result == nullptr) {
        result = new AttributeUInt8(81, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenMultistateOutputCluster::getPresentValue() {
    auto result = (AttributeUInt16*)getAttributeById(85);
    if (result == nullptr) {
        result = new AttributeUInt16(85, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenMultistateOutputCluster::getReliability() {
    auto result = (AttributeUInt8*)getAttributeById(103);
    if (result == nullptr) {
        result = new AttributeUInt8(103, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenMultistateOutputCluster::getRelinquishDefault() {
    auto result = (AttributeUInt16*)getAttributeById(104);
    if (result == nullptr) {
        result = new AttributeUInt16(104, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenMultistateOutputCluster::getStatusFlags() {
    auto result = (AttributeUInt8*)getAttributeById(111);
    if (result == nullptr) {
        result = new AttributeUInt8(111, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenMultistateOutputCluster::getApplicationType() {
    auto result = (AttributeUInt32*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeUInt32(256, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeString* GenMultistateValueCluster::getDescription() {
    auto result = (AttributeString*)getAttributeById(28);
    if (result == nullptr) {
        result = new AttributeString(28, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenMultistateValueCluster::getNumberOfStates() {
    auto result = (AttributeUInt16*)getAttributeById(74);
    if (result == nullptr) {
        result = new AttributeUInt16(74, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenMultistateValueCluster::getOutOfService() {
    auto result = (AttributeUInt8*)getAttributeById(81);
    if (result == nullptr) {
        result = new AttributeUInt8(81, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenMultistateValueCluster::getPresentValue() {
    auto result = (AttributeUInt16*)getAttributeById(85);
    if (result == nullptr) {
        result = new AttributeUInt16(85, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenMultistateValueCluster::getReliability() {
    auto result = (AttributeUInt8*)getAttributeById(103);
    if (result == nullptr) {
        result = new AttributeUInt8(103, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenMultistateValueCluster::getRelinquishDefault() {
    auto result = (AttributeUInt16*)getAttributeById(104);
    if (result == nullptr) {
        result = new AttributeUInt16(104, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenMultistateValueCluster::getStatusFlags() {
    auto result = (AttributeUInt8*)getAttributeById(111);
    if (result == nullptr) {
        result = new AttributeUInt8(111, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenMultistateValueCluster::getApplicationType() {
    auto result = (AttributeUInt32*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeUInt32(256, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenCommissioningCluster::getShortress() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt64* GenCommissioningCluster::getExtendedPANId() {
    auto result = (AttributeUInt64*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt64(1, DataType::EUI64);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenCommissioningCluster::getPanId() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenCommissioningCluster::getChannelmask() {
    auto result = (AttributeUInt32*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt32(3, DataType::Map32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenCommissioningCluster::getProtocolVersion() {
    auto result = (AttributeUInt8*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt8(4, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenCommissioningCluster::getStackProfile() {
    auto result = (AttributeUInt8*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt8(5, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenCommissioningCluster::getStartupControl() {
    auto result = (AttributeUInt8*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt8(6, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt64* GenCommissioningCluster::getTrustCenterress() {
    auto result = (AttributeUInt64*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt64(16, DataType::EUI64);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenCommissioningCluster::getUseInsecureJoin() {
    auto result = (AttributeUInt8*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt8(19, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenCommissioningCluster::getNetworkKeySeqNum() {
    auto result = (AttributeUInt8*)getAttributeById(21);
    if (result == nullptr) {
        result = new AttributeUInt8(21, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenCommissioningCluster::getNetworkKeyType() {
    auto result = (AttributeUInt8*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeUInt8(22, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenCommissioningCluster::getNetworkManagerress() {
    auto result = (AttributeUInt16*)getAttributeById(23);
    if (result == nullptr) {
        result = new AttributeUInt16(23, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenCommissioningCluster::getScanAttempts() {
    auto result = (AttributeUInt8*)getAttributeById(32);
    if (result == nullptr) {
        result = new AttributeUInt8(32, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenCommissioningCluster::getTimeBetweenScans() {
    auto result = (AttributeUInt16*)getAttributeById(33);
    if (result == nullptr) {
        result = new AttributeUInt16(33, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenCommissioningCluster::getRejoinInterval() {
    auto result = (AttributeUInt16*)getAttributeById(34);
    if (result == nullptr) {
        result = new AttributeUInt16(34, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenCommissioningCluster::getMaxRejoinInterval() {
    auto result = (AttributeUInt16*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt16(35, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenCommissioningCluster::getIndirectPollRate() {
    auto result = (AttributeUInt16*)getAttributeById(48);
    if (result == nullptr) {
        result = new AttributeUInt16(48, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenCommissioningCluster::getParentRetryThreshold() {
    auto result = (AttributeUInt8*)getAttributeById(49);
    if (result == nullptr) {
        result = new AttributeUInt8(49, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenCommissioningCluster::getConcentratorFlag() {
    auto result = (AttributeUInt8*)getAttributeById(64);
    if (result == nullptr) {
        result = new AttributeUInt8(64, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenCommissioningCluster::getConcentratorRus() {
    auto result = (AttributeUInt8*)getAttributeById(65);
    if (result == nullptr) {
        result = new AttributeUInt8(65, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenCommissioningCluster::getConcentratorDiscoveryTime() {
    auto result = (AttributeUInt8*)getAttributeById(66);
    if (result == nullptr) {
        result = new AttributeUInt8(66, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

void GenCommissioningCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt64* GenOtaCluster::getUpgradeServerId() {
    auto result = (AttributeUInt64*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt64(0, DataType::EUI64);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenOtaCluster::getFileOffset() {
    auto result = (AttributeUInt32*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt32(1, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenOtaCluster::getCurrentFileVersion() {
    auto result = (AttributeUInt32*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt32(2, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenOtaCluster::getCurrentZigbeeStackVersion() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenOtaCluster::getDownloadedFileVersion() {
    auto result = (AttributeUInt32*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt32(4, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenOtaCluster::getDownloadedZigbeeStackVersion() {
    auto result = (AttributeUInt16*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt16(5, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* GenOtaCluster::getImageUpgradeStatus() {
    auto result = (AttributeUInt8*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt8(6, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenOtaCluster::getManufacturerId() {
    auto result = (AttributeUInt16*)getAttributeById(7);
    if (result == nullptr) {
        result = new AttributeUInt16(7, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenOtaCluster::getImageTypeId() {
    auto result = (AttributeUInt16*)getAttributeById(8);
    if (result == nullptr) {
        result = new AttributeUInt16(8, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenOtaCluster::getMinimumBlockReqDelay() {
    auto result = (AttributeUInt16*)getAttributeById(9);
    if (result == nullptr) {
        result = new AttributeUInt16(9, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenOtaCluster::getImageStamp() {
    auto result = (AttributeUInt32*)getAttributeById(10);
    if (result == nullptr) {
        result = new AttributeUInt32(10, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

void GenOtaCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt32* GenPollCtrlCluster::getCheckinInterval() {
    auto result = (AttributeUInt32*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt32(0, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenPollCtrlCluster::getLongPollInterval() {
    auto result = (AttributeUInt32*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt32(1, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenPollCtrlCluster::getShortPollInterval() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenPollCtrlCluster::getFastPollTimeout() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenPollCtrlCluster::getCheckinIntervalMin() {
    auto result = (AttributeUInt32*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt32(4, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* GenPollCtrlCluster::getLongPollIntervalMin() {
    auto result = (AttributeUInt32*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt32(5, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* GenPollCtrlCluster::getFastPollTimeoutMax() {
    auto result = (AttributeUInt16*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt16(6, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

void GenPollCtrlCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt16* MobileDeviceCfgCluster::getKeepAliveTime() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MobileDeviceCfgCluster::getRejoinTimeout() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* NeighborCleaningCluster::getNeighborCleaningTimeout() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* NearestGatewayCluster::getNearestGateway() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* NearestGatewayCluster::getNewMobileNode() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresShadeCfgCluster::getPhysicalClosedLimit() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresShadeCfgCluster::getMotorStepSize() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresShadeCfgCluster::getStatus() {
    auto result = (AttributeUInt8*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt8(2, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresShadeCfgCluster::getLosedLimit() {
    auto result = (AttributeUInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt16(16, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresShadeCfgCluster::getMode() {
    auto result = (AttributeUInt8*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt8(18, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getLockState() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getLockType() {
    auto result = (AttributeUInt16*)getAttributeById(38);
    if (result == nullptr) {
        result = new AttributeUInt16(38, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getActuatorEnabled() {
    auto result = (AttributeUInt8*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt8(2, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getDoorState() {
    auto result = (AttributeUInt8*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt8(3, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* ClosuresDoorLockCluster::getDoorOpenEvents() {
    auto result = (AttributeUInt32*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt32(4, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* ClosuresDoorLockCluster::getDoorClosedEvents() {
    auto result = (AttributeUInt32*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt32(5, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getOpenPeriod() {
    auto result = (AttributeUInt16*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt16(6, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getNumOfLockRecordsSupported() {
    auto result = (AttributeUInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt16(16, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getNumOfTotalUsersSupported() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getNumOfPinUsersSupported() {
    auto result = (AttributeUInt16*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt16(18, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getNumOfRfidUsersSupported() {
    auto result = (AttributeUInt16*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt16(19, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getNumOfWeekDaySchedulesSupportedPerUser() {
    auto result = (AttributeUInt8*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeUInt8(20, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getNumOfYearDaySchedulesSupportedPerUser() {
    auto result = (AttributeUInt8*)getAttributeById(21);
    if (result == nullptr) {
        result = new AttributeUInt8(21, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getNumOfHolidayScheduledsSupported() {
    auto result = (AttributeUInt8*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeUInt8(22, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getMaxPinLen() {
    auto result = (AttributeUInt8*)getAttributeById(23);
    if (result == nullptr) {
        result = new AttributeUInt8(23, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getMinPinLen() {
    auto result = (AttributeUInt8*)getAttributeById(24);
    if (result == nullptr) {
        result = new AttributeUInt8(24, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getMaxRfidLen() {
    auto result = (AttributeUInt8*)getAttributeById(25);
    if (result == nullptr) {
        result = new AttributeUInt8(25, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getMinRfidLen() {
    auto result = (AttributeUInt8*)getAttributeById(26);
    if (result == nullptr) {
        result = new AttributeUInt8(26, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getEnableLogging() {
    auto result = (AttributeUInt8*)getAttributeById(32);
    if (result == nullptr) {
        result = new AttributeUInt8(32, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeString* ClosuresDoorLockCluster::getLanguage() {
    auto result = (AttributeString*)getAttributeById(33);
    if (result == nullptr) {
        result = new AttributeString(33, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getLedSettings() {
    auto result = (AttributeUInt8*)getAttributeById(34);
    if (result == nullptr) {
        result = new AttributeUInt8(34, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* ClosuresDoorLockCluster::getAutoRelockTime() {
    auto result = (AttributeUInt32*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt32(35, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getSoundVolume() {
    auto result = (AttributeUInt8*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt8(36, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* ClosuresDoorLockCluster::getOperatingMode() {
    auto result = (AttributeUInt32*)getAttributeById(37);
    if (result == nullptr) {
        result = new AttributeUInt32(37, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getDefaultConfigurationRegister() {
    auto result = (AttributeUInt16*)getAttributeById(39);
    if (result == nullptr) {
        result = new AttributeUInt16(39, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getEnableLocalProgramming() {
    auto result = (AttributeUInt8*)getAttributeById(40);
    if (result == nullptr) {
        result = new AttributeUInt8(40, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getEnableOneTouchLocking() {
    auto result = (AttributeUInt8*)getAttributeById(41);
    if (result == nullptr) {
        result = new AttributeUInt8(41, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getEnableInsideStatusLed() {
    auto result = (AttributeUInt8*)getAttributeById(42);
    if (result == nullptr) {
        result = new AttributeUInt8(42, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getEnablePrivacyModeButton() {
    auto result = (AttributeUInt8*)getAttributeById(43);
    if (result == nullptr) {
        result = new AttributeUInt8(43, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getWrongCodeEntryLimit() {
    auto result = (AttributeUInt8*)getAttributeById(48);
    if (result == nullptr) {
        result = new AttributeUInt8(48, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getUserCodeTemporaryDisableTime() {
    auto result = (AttributeUInt8*)getAttributeById(49);
    if (result == nullptr) {
        result = new AttributeUInt8(49, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getSendPinOta() {
    auto result = (AttributeUInt8*)getAttributeById(50);
    if (result == nullptr) {
        result = new AttributeUInt8(50, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getRequirePinForRfOperation() {
    auto result = (AttributeUInt8*)getAttributeById(51);
    if (result == nullptr) {
        result = new AttributeUInt8(51, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresDoorLockCluster::getZigbeeSecurityLevel() {
    auto result = (AttributeUInt8*)getAttributeById(52);
    if (result == nullptr) {
        result = new AttributeUInt8(52, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getAlarmMask() {
    auto result = (AttributeUInt16*)getAttributeById(64);
    if (result == nullptr) {
        result = new AttributeUInt16(64, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getKeypadOperationEventMask() {
    auto result = (AttributeUInt16*)getAttributeById(65);
    if (result == nullptr) {
        result = new AttributeUInt16(65, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getRfOperationEventMask() {
    auto result = (AttributeUInt16*)getAttributeById(66);
    if (result == nullptr) {
        result = new AttributeUInt16(66, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getManualOperationEventMask() {
    auto result = (AttributeUInt16*)getAttributeById(67);
    if (result == nullptr) {
        result = new AttributeUInt16(67, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getRfidOperationEventMask() {
    auto result = (AttributeUInt16*)getAttributeById(68);
    if (result == nullptr) {
        result = new AttributeUInt16(68, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getKeypadProgrammingEventMask() {
    auto result = (AttributeUInt16*)getAttributeById(69);
    if (result == nullptr) {
        result = new AttributeUInt16(69, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getRfProgrammingEventMask() {
    auto result = (AttributeUInt16*)getAttributeById(70);
    if (result == nullptr) {
        result = new AttributeUInt16(70, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresDoorLockCluster::getRfidProgrammingEventMask() {
    auto result = (AttributeUInt16*)getAttributeById(71);
    if (result == nullptr) {
        result = new AttributeUInt16(71, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

void ClosuresDoorLockCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt8* ClosuresWindowCoveringCluster::getWindowCoveringType() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getPhysicalClosedLimitLiftCm() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getPhysicalClosedLimitTiltDdegree() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getCurrentPositionLiftCm() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getCurrentPositionTiltDdegree() {
    auto result = (AttributeUInt16*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt16(4, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getNumOfActuationsLift() {
    auto result = (AttributeUInt16*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt16(5, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getNumOfActuationsTilt() {
    auto result = (AttributeUInt16*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt16(6, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresWindowCoveringCluster::getConfigStatus() {
    auto result = (AttributeUInt8*)getAttributeById(7);
    if (result == nullptr) {
        result = new AttributeUInt8(7, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresWindowCoveringCluster::getCurrentPositionLiftPercentage() {
    auto result = (AttributeUInt8*)getAttributeById(8);
    if (result == nullptr) {
        result = new AttributeUInt8(8, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresWindowCoveringCluster::getCurrentPositionTiltPercentage() {
    auto result = (AttributeUInt8*)getAttributeById(9);
    if (result == nullptr) {
        result = new AttributeUInt8(9, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresWindowCoveringCluster::getOperationalStatus() {
    auto result = (AttributeUInt8*)getAttributeById(10);
    if (result == nullptr) {
        result = new AttributeUInt8(10, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getInstalledOpenLimitLiftCm() {
    auto result = (AttributeUInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt16(16, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getInstalledClosedLimitLiftCm() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getInstalledOpenLimitTiltDdegree() {
    auto result = (AttributeUInt16*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt16(18, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getInstalledClosedLimitTiltDdegree() {
    auto result = (AttributeUInt16*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt16(19, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getVelocityLift() {
    auto result = (AttributeUInt16*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeUInt16(20, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getAccelerationTimeLift() {
    auto result = (AttributeUInt16*)getAttributeById(21);
    if (result == nullptr) {
        result = new AttributeUInt16(21, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getDecelerationTimeLift() {
    auto result = (AttributeUInt16*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeUInt16(22, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* ClosuresWindowCoveringCluster::getWindowCoveringMode() {
    auto result = (AttributeUInt8*)getAttributeById(23);
    if (result == nullptr) {
        result = new AttributeUInt8(23, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* ClosuresWindowCoveringCluster::getIntermediateSetpointsLift() {
    auto result = (AttributeOctstr*)getAttributeById(24);
    if (result == nullptr) {
        result = new AttributeOctstr(24, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* ClosuresWindowCoveringCluster::getIntermediateSetpointsTilt() {
    auto result = (AttributeOctstr*)getAttributeById(25);
    if (result == nullptr) {
        result = new AttributeOctstr(25, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* ClosuresWindowCoveringCluster::getMoesCalibrationTime() {
    auto result = (AttributeUInt16*)getAttributeById(61443);
    if (result == nullptr) {
        result = new AttributeUInt16(61443, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

void ClosuresWindowCoveringCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt8* BarrierControlCluster::getMovingState() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* BarrierControlCluster::getSafetyStatus() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* BarrierControlCluster::getCapabilities() {
    auto result = (AttributeUInt8*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt8(3, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* BarrierControlCluster::getOpenEvents() {
    auto result = (AttributeUInt16*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt16(4, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* BarrierControlCluster::getCloseEvents() {
    auto result = (AttributeUInt16*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt16(5, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* BarrierControlCluster::getCommandOpenEvents() {
    auto result = (AttributeUInt16*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt16(6, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* BarrierControlCluster::getCommandCloseEvents() {
    auto result = (AttributeUInt16*)getAttributeById(7);
    if (result == nullptr) {
        result = new AttributeUInt16(7, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* BarrierControlCluster::getOpenPeriod() {
    auto result = (AttributeUInt16*)getAttributeById(8);
    if (result == nullptr) {
        result = new AttributeUInt16(8, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* BarrierControlCluster::getClosePeriod() {
    auto result = (AttributeUInt16*)getAttributeById(9);
    if (result == nullptr) {
        result = new AttributeUInt16(9, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* BarrierControlCluster::getBarrierPosition() {
    auto result = (AttributeUInt8*)getAttributeById(10);
    if (result == nullptr) {
        result = new AttributeUInt8(10, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

void BarrierControlCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeInt16* HvacPumpCfgCtrlCluster::getMaxPressure() {
    auto result = (AttributeInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeInt16(0, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacPumpCfgCtrlCluster::getMaxSpeed() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacPumpCfgCtrlCluster::getMaxFlow() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacPumpCfgCtrlCluster::getMinConstPressure() {
    auto result = (AttributeInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeInt16(3, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacPumpCfgCtrlCluster::getMaxConstPressure() {
    auto result = (AttributeInt16*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeInt16(4, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacPumpCfgCtrlCluster::getMinCompPressure() {
    auto result = (AttributeInt16*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeInt16(5, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacPumpCfgCtrlCluster::getMaxCompPressure() {
    auto result = (AttributeInt16*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeInt16(6, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacPumpCfgCtrlCluster::getMinConstSpeed() {
    auto result = (AttributeUInt16*)getAttributeById(7);
    if (result == nullptr) {
        result = new AttributeUInt16(7, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacPumpCfgCtrlCluster::getMaxConstSpeed() {
    auto result = (AttributeUInt16*)getAttributeById(8);
    if (result == nullptr) {
        result = new AttributeUInt16(8, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacPumpCfgCtrlCluster::getMinConstFlow() {
    auto result = (AttributeUInt16*)getAttributeById(9);
    if (result == nullptr) {
        result = new AttributeUInt16(9, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacPumpCfgCtrlCluster::getMaxConstFlow() {
    auto result = (AttributeUInt16*)getAttributeById(10);
    if (result == nullptr) {
        result = new AttributeUInt16(10, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacPumpCfgCtrlCluster::getMinConstTemp() {
    auto result = (AttributeInt16*)getAttributeById(11);
    if (result == nullptr) {
        result = new AttributeInt16(11, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacPumpCfgCtrlCluster::getMaxConstTemp() {
    auto result = (AttributeInt16*)getAttributeById(12);
    if (result == nullptr) {
        result = new AttributeInt16(12, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacPumpCfgCtrlCluster::getPumpStatus() {
    auto result = (AttributeUInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt16(16, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacPumpCfgCtrlCluster::getEffectiveOperationMode() {
    auto result = (AttributeUInt8*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt8(17, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacPumpCfgCtrlCluster::getEffectiveControlMode() {
    auto result = (AttributeUInt8*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt8(18, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacPumpCfgCtrlCluster::getCapacity() {
    auto result = (AttributeInt16*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeInt16(19, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacPumpCfgCtrlCluster::getSpeed() {
    auto result = (AttributeUInt16*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeUInt16(20, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* HvacPumpCfgCtrlCluster::getLifetimeRunningHours() {
    auto result = (AttributeUInt24*)getAttributeById(21);
    if (result == nullptr) {
        result = new AttributeUInt24(21, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* HvacPumpCfgCtrlCluster::getPower() {
    auto result = (AttributeUInt24*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeUInt24(22, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* HvacPumpCfgCtrlCluster::getLifetimeEnergyConsumed() {
    auto result = (AttributeUInt32*)getAttributeById(23);
    if (result == nullptr) {
        result = new AttributeUInt32(23, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacPumpCfgCtrlCluster::getOperationMode() {
    auto result = (AttributeUInt8*)getAttributeById(32);
    if (result == nullptr) {
        result = new AttributeUInt8(32, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacPumpCfgCtrlCluster::getControlMode() {
    auto result = (AttributeUInt8*)getAttributeById(33);
    if (result == nullptr) {
        result = new AttributeUInt8(33, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacPumpCfgCtrlCluster::getAlarmMask() {
    auto result = (AttributeUInt16*)getAttributeById(34);
    if (result == nullptr) {
        result = new AttributeUInt16(34, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getLocalTemp() {
    auto result = (AttributeInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeInt16(0, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getOutdoorTemp() {
    auto result = (AttributeInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeInt16(1, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getOccupancy() {
    auto result = (AttributeUInt8*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt8(2, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getAbsMinHeatSetpointLimit() {
    auto result = (AttributeInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeInt16(3, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getAbsMaxHeatSetpointLimit() {
    auto result = (AttributeInt16*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeInt16(4, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getAbsMinCoolSetpointLimit() {
    auto result = (AttributeInt16*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeInt16(5, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getAbsMaxCoolSetpointLimit() {
    auto result = (AttributeInt16*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeInt16(6, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getPICoolingDemand() {
    auto result = (AttributeUInt8*)getAttributeById(7);
    if (result == nullptr) {
        result = new AttributeUInt8(7, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getPIHeatingDemand() {
    auto result = (AttributeUInt8*)getAttributeById(8);
    if (result == nullptr) {
        result = new AttributeUInt8(8, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getSystemTypeConfig() {
    auto result = (AttributeUInt8*)getAttributeById(9);
    if (result == nullptr) {
        result = new AttributeUInt8(9, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeInt8* HvacThermostatCluster::getLocalTemperatureCalibration() {
    auto result = (AttributeInt8*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeInt8(16, DataType::Int8);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getOccupiedCoolingSetpoint() {
    auto result = (AttributeInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeInt16(17, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getOccupiedHeatingSetpoint() {
    auto result = (AttributeInt16*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeInt16(18, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getUnoccupiedCoolingSetpoint() {
    auto result = (AttributeInt16*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeInt16(19, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getUnoccupiedHeatingSetpoint() {
    auto result = (AttributeInt16*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeInt16(20, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getMinHeatSetpointLimit() {
    auto result = (AttributeInt16*)getAttributeById(21);
    if (result == nullptr) {
        result = new AttributeInt16(21, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getMaxHeatSetpointLimit() {
    auto result = (AttributeInt16*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeInt16(22, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getMinCoolSetpointLimit() {
    auto result = (AttributeInt16*)getAttributeById(23);
    if (result == nullptr) {
        result = new AttributeInt16(23, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getMaxCoolSetpointLimit() {
    auto result = (AttributeInt16*)getAttributeById(24);
    if (result == nullptr) {
        result = new AttributeInt16(24, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt8* HvacThermostatCluster::getMinSetpointDeadBand() {
    auto result = (AttributeInt8*)getAttributeById(25);
    if (result == nullptr) {
        result = new AttributeInt8(25, DataType::Int8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getRemoteSensing() {
    auto result = (AttributeUInt8*)getAttributeById(26);
    if (result == nullptr) {
        result = new AttributeUInt8(26, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getCtrlSeqeOfOper() {
    auto result = (AttributeUInt8*)getAttributeById(27);
    if (result == nullptr) {
        result = new AttributeUInt8(27, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getSystemMode() {
    auto result = (AttributeUInt8*)getAttributeById(28);
    if (result == nullptr) {
        result = new AttributeUInt8(28, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getAlarmMask() {
    auto result = (AttributeUInt8*)getAttributeById(29);
    if (result == nullptr) {
        result = new AttributeUInt8(29, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getRunningMode() {
    auto result = (AttributeUInt8*)getAttributeById(30);
    if (result == nullptr) {
        result = new AttributeUInt8(30, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getStartOfWeek() {
    auto result = (AttributeUInt8*)getAttributeById(32);
    if (result == nullptr) {
        result = new AttributeUInt8(32, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getNumberOfWeeklyTrans() {
    auto result = (AttributeUInt8*)getAttributeById(33);
    if (result == nullptr) {
        result = new AttributeUInt8(33, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getNumberOfDailyTrans() {
    auto result = (AttributeUInt8*)getAttributeById(34);
    if (result == nullptr) {
        result = new AttributeUInt8(34, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getTempSetpointHold() {
    auto result = (AttributeUInt8*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt8(35, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacThermostatCluster::getTempSetpointHoldDuration() {
    auto result = (AttributeUInt16*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt16(36, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getProgramingOperMode() {
    auto result = (AttributeUInt8*)getAttributeById(37);
    if (result == nullptr) {
        result = new AttributeUInt8(37, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacThermostatCluster::getRunningState() {
    auto result = (AttributeUInt16*)getAttributeById(41);
    if (result == nullptr) {
        result = new AttributeUInt16(41, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getSetpointChangeSource() {
    auto result = (AttributeUInt8*)getAttributeById(48);
    if (result == nullptr) {
        result = new AttributeUInt8(48, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getSetpointChangeAmount() {
    auto result = (AttributeInt16*)getAttributeById(49);
    if (result == nullptr) {
        result = new AttributeInt16(49, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* HvacThermostatCluster::getSetpointChangeSourceTimeStamp() {
    auto result = (AttributeUInt32*)getAttributeById(50);
    if (result == nullptr) {
        result = new AttributeUInt32(50, DataType::UTC);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getAcType() {
    auto result = (AttributeUInt8*)getAttributeById(64);
    if (result == nullptr) {
        result = new AttributeUInt8(64, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HvacThermostatCluster::getAcCapacity() {
    auto result = (AttributeUInt16*)getAttributeById(65);
    if (result == nullptr) {
        result = new AttributeUInt16(65, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getAcRefrigerantType() {
    auto result = (AttributeUInt8*)getAttributeById(66);
    if (result == nullptr) {
        result = new AttributeUInt8(66, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getAcConpressorType() {
    auto result = (AttributeUInt8*)getAttributeById(67);
    if (result == nullptr) {
        result = new AttributeUInt8(67, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* HvacThermostatCluster::getAcErrorCode() {
    auto result = (AttributeUInt32*)getAttributeById(68);
    if (result == nullptr) {
        result = new AttributeUInt32(68, DataType::Map32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getAcLouverPosition() {
    auto result = (AttributeUInt8*)getAttributeById(69);
    if (result == nullptr) {
        result = new AttributeUInt8(69, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HvacThermostatCluster::getAcCollTemp() {
    auto result = (AttributeInt16*)getAttributeById(70);
    if (result == nullptr) {
        result = new AttributeInt16(70, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getAcCapacityFormat() {
    auto result = (AttributeUInt8*)getAttributeById(71);
    if (result == nullptr) {
        result = new AttributeUInt8(71, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacThermostatCluster::getStelproSystemMode() {
    auto result = (AttributeUInt8*)getAttributeById(16412);
    if (result == nullptr) {
        result = new AttributeUInt8(16412, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

void HvacThermostatCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt8* HvacFanCtrlCluster::getFanMode() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacFanCtrlCluster::getFanModeSequence() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacDehumidificationCtrlCluster::getRelativeHumidity() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacDehumidificationCtrlCluster::getDehumidCooling() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacDehumidificationCtrlCluster::getRhDehumidSetpoint() {
    auto result = (AttributeUInt8*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt8(16, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacDehumidificationCtrlCluster::getRelativeHumidityMode() {
    auto result = (AttributeUInt8*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt8(17, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacDehumidificationCtrlCluster::getDehumidLockout() {
    auto result = (AttributeUInt8*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt8(18, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacDehumidificationCtrlCluster::getDehumidHysteresis() {
    auto result = (AttributeUInt8*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt8(19, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacDehumidificationCtrlCluster::getDehumidMaxCool() {
    auto result = (AttributeUInt8*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeUInt8(20, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacDehumidificationCtrlCluster::getRelativeHumidDisplay() {
    auto result = (AttributeUInt8*)getAttributeById(21);
    if (result == nullptr) {
        result = new AttributeUInt8(21, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacUserInterfaceCfgCluster::getTempDisplayMode() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacUserInterfaceCfgCluster::getKeypadLockout() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HvacUserInterfaceCfgCluster::getProgrammingVisibility() {
    auto result = (AttributeUInt8*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt8(2, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getCurrentHue() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getCurrentSaturation() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getRemainingTime() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getCurrentX() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getCurrentY() {
    auto result = (AttributeUInt16*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt16(4, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getDriftCompensation() {
    auto result = (AttributeUInt8*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt8(5, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeString* LightingColorCtrlCluster::getCompensationText() {
    auto result = (AttributeString*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeString(6, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorTemperature() {
    auto result = (AttributeUInt16*)getAttributeById(7);
    if (result == nullptr) {
        result = new AttributeUInt16(7, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getColorMode() {
    auto result = (AttributeUInt8*)getAttributeById(8);
    if (result == nullptr) {
        result = new AttributeUInt8(8, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getOptions() {
    auto result = (AttributeUInt8*)getAttributeById(15);
    if (result == nullptr) {
        result = new AttributeUInt8(15, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getNumPrimaries() {
    auto result = (AttributeUInt8*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt8(16, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary1X() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary1Y() {
    auto result = (AttributeUInt16*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt16(18, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getPrimary1Intensity() {
    auto result = (AttributeUInt8*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt8(19, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary2X() {
    auto result = (AttributeUInt16*)getAttributeById(21);
    if (result == nullptr) {
        result = new AttributeUInt16(21, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary2Y() {
    auto result = (AttributeUInt16*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeUInt16(22, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getPrimary2Intensity() {
    auto result = (AttributeUInt8*)getAttributeById(23);
    if (result == nullptr) {
        result = new AttributeUInt8(23, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary3X() {
    auto result = (AttributeUInt16*)getAttributeById(25);
    if (result == nullptr) {
        result = new AttributeUInt16(25, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary3Y() {
    auto result = (AttributeUInt16*)getAttributeById(26);
    if (result == nullptr) {
        result = new AttributeUInt16(26, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getPrimary3Intensity() {
    auto result = (AttributeUInt8*)getAttributeById(27);
    if (result == nullptr) {
        result = new AttributeUInt8(27, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary4X() {
    auto result = (AttributeUInt16*)getAttributeById(32);
    if (result == nullptr) {
        result = new AttributeUInt16(32, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary4Y() {
    auto result = (AttributeUInt16*)getAttributeById(33);
    if (result == nullptr) {
        result = new AttributeUInt16(33, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getPrimary4Intensity() {
    auto result = (AttributeUInt8*)getAttributeById(34);
    if (result == nullptr) {
        result = new AttributeUInt8(34, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary5X() {
    auto result = (AttributeUInt16*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt16(36, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary5Y() {
    auto result = (AttributeUInt16*)getAttributeById(37);
    if (result == nullptr) {
        result = new AttributeUInt16(37, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getPrimary5Intensity() {
    auto result = (AttributeUInt8*)getAttributeById(38);
    if (result == nullptr) {
        result = new AttributeUInt8(38, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary6X() {
    auto result = (AttributeUInt16*)getAttributeById(40);
    if (result == nullptr) {
        result = new AttributeUInt16(40, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getPrimary6Y() {
    auto result = (AttributeUInt16*)getAttributeById(41);
    if (result == nullptr) {
        result = new AttributeUInt16(41, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getPrimary6Intensity() {
    auto result = (AttributeUInt8*)getAttributeById(42);
    if (result == nullptr) {
        result = new AttributeUInt8(42, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getWhitePointX() {
    auto result = (AttributeUInt16*)getAttributeById(48);
    if (result == nullptr) {
        result = new AttributeUInt16(48, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getWhitePointY() {
    auto result = (AttributeUInt16*)getAttributeById(49);
    if (result == nullptr) {
        result = new AttributeUInt16(49, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorPointRX() {
    auto result = (AttributeUInt16*)getAttributeById(50);
    if (result == nullptr) {
        result = new AttributeUInt16(50, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorPointRY() {
    auto result = (AttributeUInt16*)getAttributeById(51);
    if (result == nullptr) {
        result = new AttributeUInt16(51, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getColorPointRIntensity() {
    auto result = (AttributeUInt8*)getAttributeById(52);
    if (result == nullptr) {
        result = new AttributeUInt8(52, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorPointGX() {
    auto result = (AttributeUInt16*)getAttributeById(54);
    if (result == nullptr) {
        result = new AttributeUInt16(54, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorPointGY() {
    auto result = (AttributeUInt16*)getAttributeById(55);
    if (result == nullptr) {
        result = new AttributeUInt16(55, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getColorPointGIntensity() {
    auto result = (AttributeUInt8*)getAttributeById(56);
    if (result == nullptr) {
        result = new AttributeUInt8(56, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorPointBX() {
    auto result = (AttributeUInt16*)getAttributeById(58);
    if (result == nullptr) {
        result = new AttributeUInt16(58, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorPointBY() {
    auto result = (AttributeUInt16*)getAttributeById(59);
    if (result == nullptr) {
        result = new AttributeUInt16(59, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getColorPointBIntensity() {
    auto result = (AttributeUInt8*)getAttributeById(60);
    if (result == nullptr) {
        result = new AttributeUInt8(60, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getEnhancedCurrentHue() {
    auto result = (AttributeUInt16*)getAttributeById(16384);
    if (result == nullptr) {
        result = new AttributeUInt16(16384, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getEnhancedColorMode() {
    auto result = (AttributeUInt8*)getAttributeById(16385);
    if (result == nullptr) {
        result = new AttributeUInt8(16385, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getColorLoopActive() {
    auto result = (AttributeUInt8*)getAttributeById(16386);
    if (result == nullptr) {
        result = new AttributeUInt8(16386, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingColorCtrlCluster::getColorLoopDirection() {
    auto result = (AttributeUInt8*)getAttributeById(16387);
    if (result == nullptr) {
        result = new AttributeUInt8(16387, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorLoopTime() {
    auto result = (AttributeUInt16*)getAttributeById(16388);
    if (result == nullptr) {
        result = new AttributeUInt16(16388, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorLoopStartEnhancedHue() {
    auto result = (AttributeUInt16*)getAttributeById(16389);
    if (result == nullptr) {
        result = new AttributeUInt16(16389, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorLoopStoredEnhancedHue() {
    auto result = (AttributeUInt16*)getAttributeById(16390);
    if (result == nullptr) {
        result = new AttributeUInt16(16390, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorCapabilities() {
    auto result = (AttributeUInt16*)getAttributeById(16394);
    if (result == nullptr) {
        result = new AttributeUInt16(16394, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorTempPhysicalMin() {
    auto result = (AttributeUInt16*)getAttributeById(16395);
    if (result == nullptr) {
        result = new AttributeUInt16(16395, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getColorTempPhysicalMax() {
    auto result = (AttributeUInt16*)getAttributeById(16396);
    if (result == nullptr) {
        result = new AttributeUInt16(16396, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getCoupleColorTempToLevelMin() {
    auto result = (AttributeUInt16*)getAttributeById(16397);
    if (result == nullptr) {
        result = new AttributeUInt16(16397, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingColorCtrlCluster::getStartUpColorTemperature() {
    auto result = (AttributeUInt16*)getAttributeById(16400);
    if (result == nullptr) {
        result = new AttributeUInt16(16400, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

void LightingColorCtrlCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt8* LightingBallastCfgCluster::getPhysicalMinLevel() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingBallastCfgCluster::getPhysicalMaxLevel() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingBallastCfgCluster::getBallastStatus() {
    auto result = (AttributeUInt8*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt8(2, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingBallastCfgCluster::getMinLevel() {
    auto result = (AttributeUInt8*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt8(16, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingBallastCfgCluster::getMaxLevel() {
    auto result = (AttributeUInt8*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt8(17, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingBallastCfgCluster::getPowerOnLevel() {
    auto result = (AttributeUInt8*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt8(18, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* LightingBallastCfgCluster::getPowerOnFadeTime() {
    auto result = (AttributeUInt16*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt16(19, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingBallastCfgCluster::getIntrinsicBallastFactor() {
    auto result = (AttributeUInt8*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeUInt8(20, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingBallastCfgCluster::getBallastFactorAdjustment() {
    auto result = (AttributeUInt8*)getAttributeById(21);
    if (result == nullptr) {
        result = new AttributeUInt8(21, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingBallastCfgCluster::getLampQuantity() {
    auto result = (AttributeUInt8*)getAttributeById(32);
    if (result == nullptr) {
        result = new AttributeUInt8(32, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeString* LightingBallastCfgCluster::getLampType() {
    auto result = (AttributeString*)getAttributeById(48);
    if (result == nullptr) {
        result = new AttributeString(48, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* LightingBallastCfgCluster::getLampManufacturer() {
    auto result = (AttributeString*)getAttributeById(49);
    if (result == nullptr) {
        result = new AttributeString(49, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* LightingBallastCfgCluster::getLampRatedHours() {
    auto result = (AttributeUInt24*)getAttributeById(50);
    if (result == nullptr) {
        result = new AttributeUInt24(50, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* LightingBallastCfgCluster::getLampBurnHours() {
    auto result = (AttributeUInt24*)getAttributeById(51);
    if (result == nullptr) {
        result = new AttributeUInt24(51, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* LightingBallastCfgCluster::getLampAlarmMode() {
    auto result = (AttributeUInt8*)getAttributeById(52);
    if (result == nullptr) {
        result = new AttributeUInt8(52, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* LightingBallastCfgCluster::getLampBurnHoursTripPoint() {
    auto result = (AttributeUInt24*)getAttributeById(53);
    if (result == nullptr) {
        result = new AttributeUInt24(53, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsIlluminanceMeasurementCluster::getMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsIlluminanceMeasurementCluster::getMinMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsIlluminanceMeasurementCluster::getMaxMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsIlluminanceMeasurementCluster::getTolerance() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* MsIlluminanceMeasurementCluster::getLightSensorType() {
    auto result = (AttributeUInt8*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt8(4, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* MsIlluminanceLevelSensingCluster::getLevelStatus() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* MsIlluminanceLevelSensingCluster::getLightSensorType() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsIlluminanceLevelSensingCluster::getIlluminanceTargetLevel() {
    auto result = (AttributeUInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt16(16, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* MsTemperatureMeasurementCluster::getMeasuredValue() {
    auto result = (AttributeInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeInt16(0, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* MsTemperatureMeasurementCluster::getMinMeasuredValue() {
    auto result = (AttributeInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeInt16(1, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* MsTemperatureMeasurementCluster::getMaxMeasuredValue() {
    auto result = (AttributeInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeInt16(2, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsTemperatureMeasurementCluster::getTolerance() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* MsPressureMeasurementCluster::getMeasuredValue() {
    auto result = (AttributeInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeInt16(0, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* MsPressureMeasurementCluster::getMinMeasuredValue() {
    auto result = (AttributeInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeInt16(1, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* MsPressureMeasurementCluster::getMaxMeasuredValue() {
    auto result = (AttributeInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeInt16(2, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsPressureMeasurementCluster::getTolerance() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* MsPressureMeasurementCluster::getScaledValue() {
    auto result = (AttributeInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeInt16(16, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* MsPressureMeasurementCluster::getMinScaledValue() {
    auto result = (AttributeInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeInt16(17, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* MsPressureMeasurementCluster::getMaxScaledValue() {
    auto result = (AttributeInt16*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeInt16(18, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsPressureMeasurementCluster::getScaledTolerance() {
    auto result = (AttributeUInt16*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt16(19, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt8* MsPressureMeasurementCluster::getScale() {
    auto result = (AttributeInt8*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeInt8(20, DataType::Int8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsFlowMeasurementCluster::getMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsFlowMeasurementCluster::getMinMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsFlowMeasurementCluster::getMaxMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsFlowMeasurementCluster::getTolerance() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsRelativeHumidityCluster::getMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsRelativeHumidityCluster::getMinMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsRelativeHumidityCluster::getMaxMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsRelativeHumidityCluster::getTolerance() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* MsOccupancySensingCluster::getOccupancy() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* MsOccupancySensingCluster::getOccupancySensorType() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsOccupancySensingCluster::getPirOToUDelay() {
    auto result = (AttributeUInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt16(16, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsOccupancySensingCluster::getPirUToODelay() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* MsOccupancySensingCluster::getPirUToOThreshold() {
    auto result = (AttributeUInt8*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt8(18, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsOccupancySensingCluster::getUltrasonicOToUDelay() {
    auto result = (AttributeUInt16*)getAttributeById(32);
    if (result == nullptr) {
        result = new AttributeUInt16(32, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsOccupancySensingCluster::getUltrasonicUToODelay() {
    auto result = (AttributeUInt16*)getAttributeById(33);
    if (result == nullptr) {
        result = new AttributeUInt16(33, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* MsOccupancySensingCluster::getUltrasonicUToOThreshold() {
    auto result = (AttributeUInt8*)getAttributeById(34);
    if (result == nullptr) {
        result = new AttributeUInt8(34, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsSoilMoistureCluster::getMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsSoilMoistureCluster::getMinMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsSoilMoistureCluster::getMaxMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* MsSoilMoistureCluster::getTolerance() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PHMeasurementCluster::getMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PHMeasurementCluster::getMinMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PHMeasurementCluster::getMaxMeasuredValue() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PHMeasurementCluster::getTolerance() {
    auto result = (AttributeUInt16*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt16(3, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* MsCO2Cluster::getMeasuredValue() {
    auto result = (AttributeSingle*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeSingle(0, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* MsCO2Cluster::getMinMeasuredValue() {
    auto result = (AttributeSingle*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeSingle(1, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* MsCO2Cluster::getMaxMeasuredValue() {
    auto result = (AttributeSingle*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeSingle(2, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SsIasZoneCluster::getZoneState() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SsIasZoneCluster::getZoneType() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SsIasZoneCluster::getZoneStatus() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt64* SsIasZoneCluster::getIasCieAddr() {
    auto result = (AttributeUInt64*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt64(16, DataType::EUI64);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SsIasZoneCluster::getZoneId() {
    auto result = (AttributeUInt8*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt8(17, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SsIasZoneCluster::getNumZoneSensitivityLevelsSupported() {
    auto result = (AttributeUInt8*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt8(18, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SsIasZoneCluster::getCurrentZoneSensitivityLevel() {
    auto result = (AttributeUInt8*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt8(19, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

void SsIasZoneCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

void SsIasAceCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt16* SsIasWdCluster::getMaxDuration() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

void SsIasWdCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt16* PiGenericTunnelCluster::getMaxIncomeTransSize() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiGenericTunnelCluster::getMaxOutgoTransSize() {
    auto result = (AttributeUInt16*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt16(2, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* PiGenericTunnelCluster::getProtocolAddr() {
    auto result = (AttributeOctstr*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeOctstr(3, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

void PiGenericTunnelCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

void PiBacnetProtocolTunnelCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeSingle* PiAnalogInputRegCluster::getCovIncrement() {
    auto result = (AttributeSingle*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeSingle(22, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiAnalogInputRegCluster::getDeviceType() {
    auto result = (AttributeString*)getAttributeById(31);
    if (result == nullptr) {
        result = new AttributeString(31, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiAnalogInputRegCluster::getObjectId() {
    auto result = (AttributeUInt32*)getAttributeById(75);
    if (result == nullptr) {
        result = new AttributeUInt32(75, DataType::BacOID);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiAnalogInputRegCluster::getObjectName() {
    auto result = (AttributeString*)getAttributeById(77);
    if (result == nullptr) {
        result = new AttributeString(77, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiAnalogInputRegCluster::getObjectType() {
    auto result = (AttributeUInt16*)getAttributeById(79);
    if (result == nullptr) {
        result = new AttributeUInt16(79, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogInputRegCluster::getUpdateInterval() {
    auto result = (AttributeUInt8*)getAttributeById(118);
    if (result == nullptr) {
        result = new AttributeUInt8(118, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiAnalogInputRegCluster::getProfileName() {
    auto result = (AttributeString*)getAttributeById(168);
    if (result == nullptr) {
        result = new AttributeString(168, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogInputExtCluster::getAckedTransitions() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiAnalogInputExtCluster::getNotificationClass() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* PiAnalogInputExtCluster::getDeadband() {
    auto result = (AttributeSingle*)getAttributeById(25);
    if (result == nullptr) {
        result = new AttributeSingle(25, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogInputExtCluster::getEventEnable() {
    auto result = (AttributeUInt8*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt8(35, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogInputExtCluster::getEventState() {
    auto result = (AttributeUInt8*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt8(36, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* PiAnalogInputExtCluster::getHighLimit() {
    auto result = (AttributeSingle*)getAttributeById(45);
    if (result == nullptr) {
        result = new AttributeSingle(45, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogInputExtCluster::getLimitEnable() {
    auto result = (AttributeUInt8*)getAttributeById(52);
    if (result == nullptr) {
        result = new AttributeUInt8(52, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* PiAnalogInputExtCluster::getLowLimit() {
    auto result = (AttributeSingle*)getAttributeById(59);
    if (result == nullptr) {
        result = new AttributeSingle(59, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogInputExtCluster::getNotifyType() {
    auto result = (AttributeUInt8*)getAttributeById(72);
    if (result == nullptr) {
        result = new AttributeUInt8(72, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogInputExtCluster::getTimeDelay() {
    auto result = (AttributeUInt8*)getAttributeById(113);
    if (result == nullptr) {
        result = new AttributeUInt8(113, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

void PiAnalogInputExtCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeSingle* PiAnalogOutputRegCluster::getCovIncrement() {
    auto result = (AttributeSingle*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeSingle(22, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiAnalogOutputRegCluster::getDeviceType() {
    auto result = (AttributeString*)getAttributeById(31);
    if (result == nullptr) {
        result = new AttributeString(31, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiAnalogOutputRegCluster::getObjectId() {
    auto result = (AttributeUInt32*)getAttributeById(75);
    if (result == nullptr) {
        result = new AttributeUInt32(75, DataType::BacOID);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiAnalogOutputRegCluster::getObjectName() {
    auto result = (AttributeString*)getAttributeById(77);
    if (result == nullptr) {
        result = new AttributeString(77, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiAnalogOutputRegCluster::getObjectType() {
    auto result = (AttributeUInt16*)getAttributeById(79);
    if (result == nullptr) {
        result = new AttributeUInt16(79, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogOutputRegCluster::getUpdateInterval() {
    auto result = (AttributeUInt8*)getAttributeById(118);
    if (result == nullptr) {
        result = new AttributeUInt8(118, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiAnalogOutputRegCluster::getProfileName() {
    auto result = (AttributeString*)getAttributeById(168);
    if (result == nullptr) {
        result = new AttributeString(168, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogOutputExtCluster::getAckedTransitions() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiAnalogOutputExtCluster::getNotificationClass() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* PiAnalogOutputExtCluster::getDeadband() {
    auto result = (AttributeSingle*)getAttributeById(25);
    if (result == nullptr) {
        result = new AttributeSingle(25, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogOutputExtCluster::getEventEnable() {
    auto result = (AttributeUInt8*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt8(35, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogOutputExtCluster::getEventState() {
    auto result = (AttributeUInt8*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt8(36, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* PiAnalogOutputExtCluster::getHighLimit() {
    auto result = (AttributeSingle*)getAttributeById(45);
    if (result == nullptr) {
        result = new AttributeSingle(45, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogOutputExtCluster::getLimitEnable() {
    auto result = (AttributeUInt8*)getAttributeById(52);
    if (result == nullptr) {
        result = new AttributeUInt8(52, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* PiAnalogOutputExtCluster::getLowLimit() {
    auto result = (AttributeSingle*)getAttributeById(59);
    if (result == nullptr) {
        result = new AttributeSingle(59, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogOutputExtCluster::getNotifyType() {
    auto result = (AttributeUInt8*)getAttributeById(72);
    if (result == nullptr) {
        result = new AttributeUInt8(72, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogOutputExtCluster::getTimeDelay() {
    auto result = (AttributeUInt8*)getAttributeById(113);
    if (result == nullptr) {
        result = new AttributeUInt8(113, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* PiAnalogValueRegCluster::getCovIncrement() {
    auto result = (AttributeSingle*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeSingle(22, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiAnalogValueRegCluster::getObjectId() {
    auto result = (AttributeUInt32*)getAttributeById(75);
    if (result == nullptr) {
        result = new AttributeUInt32(75, DataType::BacOID);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiAnalogValueRegCluster::getObjectName() {
    auto result = (AttributeString*)getAttributeById(77);
    if (result == nullptr) {
        result = new AttributeString(77, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiAnalogValueRegCluster::getObjectType() {
    auto result = (AttributeUInt16*)getAttributeById(79);
    if (result == nullptr) {
        result = new AttributeUInt16(79, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiAnalogValueRegCluster::getProfileName() {
    auto result = (AttributeString*)getAttributeById(168);
    if (result == nullptr) {
        result = new AttributeString(168, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogValueExtCluster::getAckedTransitions() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiAnalogValueExtCluster::getNotificationClass() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* PiAnalogValueExtCluster::getDeadband() {
    auto result = (AttributeSingle*)getAttributeById(25);
    if (result == nullptr) {
        result = new AttributeSingle(25, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogValueExtCluster::getEventEnable() {
    auto result = (AttributeUInt8*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt8(35, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogValueExtCluster::getEventState() {
    auto result = (AttributeUInt8*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt8(36, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* PiAnalogValueExtCluster::getHighLimit() {
    auto result = (AttributeSingle*)getAttributeById(45);
    if (result == nullptr) {
        result = new AttributeSingle(45, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogValueExtCluster::getLimitEnable() {
    auto result = (AttributeUInt8*)getAttributeById(52);
    if (result == nullptr) {
        result = new AttributeUInt8(52, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeSingle* PiAnalogValueExtCluster::getLowLimit() {
    auto result = (AttributeSingle*)getAttributeById(59);
    if (result == nullptr) {
        result = new AttributeSingle(59, DataType::Single);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogValueExtCluster::getNotifyType() {
    auto result = (AttributeUInt8*)getAttributeById(72);
    if (result == nullptr) {
        result = new AttributeUInt8(72, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiAnalogValueExtCluster::getTimeDelay() {
    auto result = (AttributeUInt8*)getAttributeById(113);
    if (result == nullptr) {
        result = new AttributeUInt8(113, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiBinaryInputRegCluster::getChangeOfStateCount() {
    auto result = (AttributeUInt32*)getAttributeById(15);
    if (result == nullptr) {
        result = new AttributeUInt32(15, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeDateTime* PiBinaryInputRegCluster::getChangeOfStateTime() {
    auto result = (AttributeDateTime*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeDateTime(16, DataType::DateTime);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiBinaryInputRegCluster::getDeviceType() {
    auto result = (AttributeString*)getAttributeById(31);
    if (result == nullptr) {
        result = new AttributeString(31, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiBinaryInputRegCluster::getElapsedActiveTime() {
    auto result = (AttributeUInt32*)getAttributeById(33);
    if (result == nullptr) {
        result = new AttributeUInt32(33, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiBinaryInputRegCluster::getObjectIdentifier() {
    auto result = (AttributeUInt32*)getAttributeById(75);
    if (result == nullptr) {
        result = new AttributeUInt32(75, DataType::BacOID);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiBinaryInputRegCluster::getObjectName() {
    auto result = (AttributeString*)getAttributeById(77);
    if (result == nullptr) {
        result = new AttributeString(77, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiBinaryInputRegCluster::getObjectType() {
    auto result = (AttributeUInt16*)getAttributeById(79);
    if (result == nullptr) {
        result = new AttributeUInt16(79, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeDateTime* PiBinaryInputRegCluster::getTimeOfATReset() {
    auto result = (AttributeDateTime*)getAttributeById(114);
    if (result == nullptr) {
        result = new AttributeDateTime(114, DataType::DateTime);
        addAttribute(result);
    }
    return result;
}

AttributeDateTime* PiBinaryInputRegCluster::getTimeOfSCReset() {
    auto result = (AttributeDateTime*)getAttributeById(115);
    if (result == nullptr) {
        result = new AttributeDateTime(115, DataType::DateTime);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiBinaryInputRegCluster::getProfileName() {
    auto result = (AttributeString*)getAttributeById(168);
    if (result == nullptr) {
        result = new AttributeString(168, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryInputExtCluster::getAckedTransitions() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryInputExtCluster::getAlarmValue() {
    auto result = (AttributeUInt8*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt8(6, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiBinaryInputExtCluster::getNotificationClass() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryInputExtCluster::getEventEnable() {
    auto result = (AttributeUInt8*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt8(35, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryInputExtCluster::getEventState() {
    auto result = (AttributeUInt8*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt8(36, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryInputExtCluster::getNotifyType() {
    auto result = (AttributeUInt8*)getAttributeById(72);
    if (result == nullptr) {
        result = new AttributeUInt8(72, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryInputExtCluster::getTimeDelay() {
    auto result = (AttributeUInt8*)getAttributeById(113);
    if (result == nullptr) {
        result = new AttributeUInt8(113, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiBinaryOutputRegCluster::getChangeOfStateCount() {
    auto result = (AttributeUInt32*)getAttributeById(15);
    if (result == nullptr) {
        result = new AttributeUInt32(15, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeDateTime* PiBinaryOutputRegCluster::getChangeOfStateTime() {
    auto result = (AttributeDateTime*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeDateTime(16, DataType::DateTime);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiBinaryOutputRegCluster::getDeviceType() {
    auto result = (AttributeString*)getAttributeById(31);
    if (result == nullptr) {
        result = new AttributeString(31, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiBinaryOutputRegCluster::getElapsedActiveTime() {
    auto result = (AttributeUInt32*)getAttributeById(33);
    if (result == nullptr) {
        result = new AttributeUInt32(33, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryOutputRegCluster::getFeedBackValue() {
    auto result = (AttributeUInt8*)getAttributeById(40);
    if (result == nullptr) {
        result = new AttributeUInt8(40, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiBinaryOutputRegCluster::getObjectIdentifier() {
    auto result = (AttributeUInt32*)getAttributeById(75);
    if (result == nullptr) {
        result = new AttributeUInt32(75, DataType::BacOID);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiBinaryOutputRegCluster::getObjectName() {
    auto result = (AttributeString*)getAttributeById(77);
    if (result == nullptr) {
        result = new AttributeString(77, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiBinaryOutputRegCluster::getObjectType() {
    auto result = (AttributeUInt16*)getAttributeById(79);
    if (result == nullptr) {
        result = new AttributeUInt16(79, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeDateTime* PiBinaryOutputRegCluster::getTimeOfATReset() {
    auto result = (AttributeDateTime*)getAttributeById(114);
    if (result == nullptr) {
        result = new AttributeDateTime(114, DataType::DateTime);
        addAttribute(result);
    }
    return result;
}

AttributeDateTime* PiBinaryOutputRegCluster::getTimeOfSCReset() {
    auto result = (AttributeDateTime*)getAttributeById(115);
    if (result == nullptr) {
        result = new AttributeDateTime(115, DataType::DateTime);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiBinaryOutputRegCluster::getProfileName() {
    auto result = (AttributeString*)getAttributeById(168);
    if (result == nullptr) {
        result = new AttributeString(168, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryOutputExtCluster::getAckedTransitions() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiBinaryOutputExtCluster::getNotificationClass() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryOutputExtCluster::getEventEnable() {
    auto result = (AttributeUInt8*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt8(35, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryOutputExtCluster::getEventState() {
    auto result = (AttributeUInt8*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt8(36, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryOutputExtCluster::getNotifyType() {
    auto result = (AttributeUInt8*)getAttributeById(72);
    if (result == nullptr) {
        result = new AttributeUInt8(72, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryOutputExtCluster::getTimeDelay() {
    auto result = (AttributeUInt8*)getAttributeById(113);
    if (result == nullptr) {
        result = new AttributeUInt8(113, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiBinaryValueRegCluster::getChangeOfStateCount() {
    auto result = (AttributeUInt32*)getAttributeById(15);
    if (result == nullptr) {
        result = new AttributeUInt32(15, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeDateTime* PiBinaryValueRegCluster::getChangeOfStateTime() {
    auto result = (AttributeDateTime*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeDateTime(16, DataType::DateTime);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiBinaryValueRegCluster::getElapsedActiveTime() {
    auto result = (AttributeUInt32*)getAttributeById(33);
    if (result == nullptr) {
        result = new AttributeUInt32(33, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiBinaryValueRegCluster::getObjectIdentifier() {
    auto result = (AttributeUInt32*)getAttributeById(75);
    if (result == nullptr) {
        result = new AttributeUInt32(75, DataType::BacOID);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiBinaryValueRegCluster::getObjectName() {
    auto result = (AttributeString*)getAttributeById(77);
    if (result == nullptr) {
        result = new AttributeString(77, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiBinaryValueRegCluster::getObjectType() {
    auto result = (AttributeUInt16*)getAttributeById(79);
    if (result == nullptr) {
        result = new AttributeUInt16(79, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeDateTime* PiBinaryValueRegCluster::getTimeOfATReset() {
    auto result = (AttributeDateTime*)getAttributeById(114);
    if (result == nullptr) {
        result = new AttributeDateTime(114, DataType::DateTime);
        addAttribute(result);
    }
    return result;
}

AttributeDateTime* PiBinaryValueRegCluster::getTimeOfSCReset() {
    auto result = (AttributeDateTime*)getAttributeById(115);
    if (result == nullptr) {
        result = new AttributeDateTime(115, DataType::DateTime);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiBinaryValueRegCluster::getProfileName() {
    auto result = (AttributeString*)getAttributeById(168);
    if (result == nullptr) {
        result = new AttributeString(168, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryValueExtCluster::getAckedTransitions() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryValueExtCluster::getAlarmValue() {
    auto result = (AttributeUInt8*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt8(6, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiBinaryValueExtCluster::getNotificationClass() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryValueExtCluster::getEventEnable() {
    auto result = (AttributeUInt8*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt8(35, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryValueExtCluster::getEventState() {
    auto result = (AttributeUInt8*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt8(36, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryValueExtCluster::getNotifyType() {
    auto result = (AttributeUInt8*)getAttributeById(72);
    if (result == nullptr) {
        result = new AttributeUInt8(72, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiBinaryValueExtCluster::getTimeDelay() {
    auto result = (AttributeUInt8*)getAttributeById(113);
    if (result == nullptr) {
        result = new AttributeUInt8(113, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiMultistateInputRegCluster::getDeviceType() {
    auto result = (AttributeString*)getAttributeById(31);
    if (result == nullptr) {
        result = new AttributeString(31, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiMultistateInputRegCluster::getObjectId() {
    auto result = (AttributeUInt32*)getAttributeById(75);
    if (result == nullptr) {
        result = new AttributeUInt32(75, DataType::BacOID);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiMultistateInputRegCluster::getObjectName() {
    auto result = (AttributeString*)getAttributeById(77);
    if (result == nullptr) {
        result = new AttributeString(77, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiMultistateInputRegCluster::getObjectType() {
    auto result = (AttributeUInt16*)getAttributeById(79);
    if (result == nullptr) {
        result = new AttributeUInt16(79, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiMultistateInputRegCluster::getProfileName() {
    auto result = (AttributeString*)getAttributeById(168);
    if (result == nullptr) {
        result = new AttributeString(168, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateInputExtCluster::getAckedTransitions() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiMultistateInputExtCluster::getAlarmValue() {
    auto result = (AttributeUInt16*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt16(6, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiMultistateInputExtCluster::getNotificationClass() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateInputExtCluster::getEventEnable() {
    auto result = (AttributeUInt8*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt8(35, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateInputExtCluster::getEventState() {
    auto result = (AttributeUInt8*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt8(36, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiMultistateInputExtCluster::getFaultValues() {
    auto result = (AttributeUInt16*)getAttributeById(37);
    if (result == nullptr) {
        result = new AttributeUInt16(37, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateInputExtCluster::getNotifyType() {
    auto result = (AttributeUInt8*)getAttributeById(72);
    if (result == nullptr) {
        result = new AttributeUInt8(72, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateInputExtCluster::getTimeDelay() {
    auto result = (AttributeUInt8*)getAttributeById(113);
    if (result == nullptr) {
        result = new AttributeUInt8(113, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiMultistateOutputRegCluster::getDeviceType() {
    auto result = (AttributeString*)getAttributeById(31);
    if (result == nullptr) {
        result = new AttributeString(31, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateOutputRegCluster::getFeedBackValue() {
    auto result = (AttributeUInt8*)getAttributeById(40);
    if (result == nullptr) {
        result = new AttributeUInt8(40, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiMultistateOutputRegCluster::getObjectId() {
    auto result = (AttributeUInt32*)getAttributeById(75);
    if (result == nullptr) {
        result = new AttributeUInt32(75, DataType::BacOID);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiMultistateOutputRegCluster::getObjectName() {
    auto result = (AttributeString*)getAttributeById(77);
    if (result == nullptr) {
        result = new AttributeString(77, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiMultistateOutputRegCluster::getObjectType() {
    auto result = (AttributeUInt16*)getAttributeById(79);
    if (result == nullptr) {
        result = new AttributeUInt16(79, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiMultistateOutputRegCluster::getProfileName() {
    auto result = (AttributeString*)getAttributeById(168);
    if (result == nullptr) {
        result = new AttributeString(168, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateOutputExtCluster::getAckedTransitions() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiMultistateOutputExtCluster::getNotificationClass() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateOutputExtCluster::getEventEnable() {
    auto result = (AttributeUInt8*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt8(35, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateOutputExtCluster::getEventState() {
    auto result = (AttributeUInt8*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt8(36, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateOutputExtCluster::getNotifyType() {
    auto result = (AttributeUInt8*)getAttributeById(72);
    if (result == nullptr) {
        result = new AttributeUInt8(72, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateOutputExtCluster::getTimeDelay() {
    auto result = (AttributeUInt8*)getAttributeById(113);
    if (result == nullptr) {
        result = new AttributeUInt8(113, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* PiMultistateValueRegCluster::getObjectId() {
    auto result = (AttributeUInt32*)getAttributeById(75);
    if (result == nullptr) {
        result = new AttributeUInt32(75, DataType::BacOID);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiMultistateValueRegCluster::getObjectName() {
    auto result = (AttributeString*)getAttributeById(77);
    if (result == nullptr) {
        result = new AttributeString(77, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiMultistateValueRegCluster::getObjectType() {
    auto result = (AttributeUInt16*)getAttributeById(79);
    if (result == nullptr) {
        result = new AttributeUInt16(79, DataType::Enum16);
        addAttribute(result);
    }
    return result;
}

AttributeString* PiMultistateValueRegCluster::getProfileName() {
    auto result = (AttributeString*)getAttributeById(168);
    if (result == nullptr) {
        result = new AttributeString(168, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateValueExtCluster::getAckedTransitions() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiMultistateValueExtCluster::getAlarmValue() {
    auto result = (AttributeUInt16*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt16(6, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiMultistateValueExtCluster::getNotificationClass() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateValueExtCluster::getEventEnable() {
    auto result = (AttributeUInt8*)getAttributeById(35);
    if (result == nullptr) {
        result = new AttributeUInt8(35, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateValueExtCluster::getEventState() {
    auto result = (AttributeUInt8*)getAttributeById(36);
    if (result == nullptr) {
        result = new AttributeUInt8(36, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiMultistateValueExtCluster::getFaultValues() {
    auto result = (AttributeUInt16*)getAttributeById(37);
    if (result == nullptr) {
        result = new AttributeUInt16(37, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateValueExtCluster::getNotifyType() {
    auto result = (AttributeUInt8*)getAttributeById(72);
    if (result == nullptr) {
        result = new AttributeUInt8(72, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* PiMultistateValueExtCluster::getTimeDelay() {
    auto result = (AttributeUInt8*)getAttributeById(113);
    if (result == nullptr) {
        result = new AttributeUInt8(113, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt64* Pi11073ProtocolTunnelCluster::getManagerTarget() {
    auto result = (AttributeUInt64*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt64(1, DataType::EUI64);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* Pi11073ProtocolTunnelCluster::getManagerEndpoint() {
    auto result = (AttributeUInt8*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt8(2, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* Pi11073ProtocolTunnelCluster::getConnected() {
    auto result = (AttributeUInt8*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt8(3, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* Pi11073ProtocolTunnelCluster::getPreemptible() {
    auto result = (AttributeUInt8*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt8(4, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* Pi11073ProtocolTunnelCluster::getIdleTimeout() {
    auto result = (AttributeUInt16*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt16(5, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

void Pi11073ProtocolTunnelCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt8* PiIso7818ProtocolTunnelCluster::getStatus() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiRetailTunnelCluster::getManufacturerCode() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* PiRetailTunnelCluster::getMsProfile() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentSummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt48(0, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentSummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt48(1, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentMaxDemandDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt48(2, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentMaxDemandReceived() {
    auto result = (AttributeUInt48*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt48(3, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getDftSumm() {
    auto result = (AttributeUInt48*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt48(4, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SeMeteringCluster::getDailyFreezeTime() {
    auto result = (AttributeUInt16*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt16(5, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt8* SeMeteringCluster::getPowerFactor() {
    auto result = (AttributeInt8*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeInt8(6, DataType::Int8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getReadingSnapshotTime() {
    auto result = (AttributeUInt32*)getAttributeById(7);
    if (result == nullptr) {
        result = new AttributeUInt32(7, DataType::UTC);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getCurrentMaxDemandDeliverdTime() {
    auto result = (AttributeUInt32*)getAttributeById(8);
    if (result == nullptr) {
        result = new AttributeUInt32(8, DataType::UTC);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getCurrentMaxDemandReceivedTime() {
    auto result = (AttributeUInt32*)getAttributeById(9);
    if (result == nullptr) {
        result = new AttributeUInt32(9, DataType::UTC);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getDefaultUpdatePeriod() {
    auto result = (AttributeUInt8*)getAttributeById(10);
    if (result == nullptr) {
        result = new AttributeUInt8(10, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getFastPollUpdatePeriod() {
    auto result = (AttributeUInt8*)getAttributeById(11);
    if (result == nullptr) {
        result = new AttributeUInt8(11, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentBlockPeriodConsumpDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(12);
    if (result == nullptr) {
        result = new AttributeUInt48(12, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getDailyConsumpTarget() {
    auto result = (AttributeUInt24*)getAttributeById(13);
    if (result == nullptr) {
        result = new AttributeUInt24(13, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getCurrentBlock() {
    auto result = (AttributeUInt8*)getAttributeById(14);
    if (result == nullptr) {
        result = new AttributeUInt8(14, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getProfileIntervalPeriod() {
    auto result = (AttributeUInt8*)getAttributeById(15);
    if (result == nullptr) {
        result = new AttributeUInt8(15, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SeMeteringCluster::getIntervalReadReportingPeriod() {
    auto result = (AttributeUInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt16(16, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SeMeteringCluster::getPresetReadingTime() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SeMeteringCluster::getVolumePerReport() {
    auto result = (AttributeUInt16*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt16(18, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getFlowRestriction() {
    auto result = (AttributeUInt8*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt8(19, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getSupplyStatus() {
    auto result = (AttributeUInt8*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeUInt8(20, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentInEnergyCarrierSumm() {
    auto result = (AttributeUInt48*)getAttributeById(21);
    if (result == nullptr) {
        result = new AttributeUInt48(21, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentOutEnergyCarrierSumm() {
    auto result = (AttributeUInt48*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeUInt48(22, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getInletTempreature() {
    auto result = (AttributeInt24*)getAttributeById(23);
    if (result == nullptr) {
        result = new AttributeInt24(23, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getOutletTempreature() {
    auto result = (AttributeInt24*)getAttributeById(24);
    if (result == nullptr) {
        result = new AttributeInt24(24, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getControlTempreature() {
    auto result = (AttributeInt24*)getAttributeById(25);
    if (result == nullptr) {
        result = new AttributeInt24(25, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getCurrentInEnergyCarrierDemand() {
    auto result = (AttributeInt24*)getAttributeById(26);
    if (result == nullptr) {
        result = new AttributeInt24(26, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getCurrentOutEnergyCarrierDemand() {
    auto result = (AttributeInt24*)getAttributeById(27);
    if (result == nullptr) {
        result = new AttributeInt24(27, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentBlockPeriodConsumpReceived() {
    auto result = (AttributeUInt48*)getAttributeById(29);
    if (result == nullptr) {
        result = new AttributeUInt48(29, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentBlockReceived() {
    auto result = (AttributeUInt48*)getAttributeById(30);
    if (result == nullptr) {
        result = new AttributeUInt48(30, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getDFTSummationReceived() {
    auto result = (AttributeUInt48*)getAttributeById(31);
    if (result == nullptr) {
        result = new AttributeUInt48(31, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getActiveRegisterTierDelivered() {
    auto result = (AttributeUInt8*)getAttributeById(32);
    if (result == nullptr) {
        result = new AttributeUInt8(32, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getActiveRegisterTierReceived() {
    auto result = (AttributeUInt8*)getAttributeById(33);
    if (result == nullptr) {
        result = new AttributeUInt8(33, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier1SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeUInt48(256, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier1SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(257);
    if (result == nullptr) {
        result = new AttributeUInt48(257, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier2SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(258);
    if (result == nullptr) {
        result = new AttributeUInt48(258, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier2SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(259);
    if (result == nullptr) {
        result = new AttributeUInt48(259, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier3SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(260);
    if (result == nullptr) {
        result = new AttributeUInt48(260, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier3SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(261);
    if (result == nullptr) {
        result = new AttributeUInt48(261, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier4SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(262);
    if (result == nullptr) {
        result = new AttributeUInt48(262, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier4SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(263);
    if (result == nullptr) {
        result = new AttributeUInt48(263, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier5SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(264);
    if (result == nullptr) {
        result = new AttributeUInt48(264, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier5SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(265);
    if (result == nullptr) {
        result = new AttributeUInt48(265, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier6SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(266);
    if (result == nullptr) {
        result = new AttributeUInt48(266, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier6SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(267);
    if (result == nullptr) {
        result = new AttributeUInt48(267, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier7SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(268);
    if (result == nullptr) {
        result = new AttributeUInt48(268, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier7SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(269);
    if (result == nullptr) {
        result = new AttributeUInt48(269, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier8SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(270);
    if (result == nullptr) {
        result = new AttributeUInt48(270, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier8SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(271);
    if (result == nullptr) {
        result = new AttributeUInt48(271, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier9SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(272);
    if (result == nullptr) {
        result = new AttributeUInt48(272, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier9SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(273);
    if (result == nullptr) {
        result = new AttributeUInt48(273, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier10SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(274);
    if (result == nullptr) {
        result = new AttributeUInt48(274, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier10SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(275);
    if (result == nullptr) {
        result = new AttributeUInt48(275, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier11SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(276);
    if (result == nullptr) {
        result = new AttributeUInt48(276, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier11SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(277);
    if (result == nullptr) {
        result = new AttributeUInt48(277, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier12SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(278);
    if (result == nullptr) {
        result = new AttributeUInt48(278, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier12SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(279);
    if (result == nullptr) {
        result = new AttributeUInt48(279, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier13SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(280);
    if (result == nullptr) {
        result = new AttributeUInt48(280, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier13SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(281);
    if (result == nullptr) {
        result = new AttributeUInt48(281, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier14SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(282);
    if (result == nullptr) {
        result = new AttributeUInt48(282, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier14SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(283);
    if (result == nullptr) {
        result = new AttributeUInt48(283, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier15SummDelivered() {
    auto result = (AttributeUInt48*)getAttributeById(284);
    if (result == nullptr) {
        result = new AttributeUInt48(284, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentTier15SummReceived() {
    auto result = (AttributeUInt48*)getAttributeById(285);
    if (result == nullptr) {
        result = new AttributeUInt48(285, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getStatus() {
    auto result = (AttributeUInt8*)getAttributeById(512);
    if (result == nullptr) {
        result = new AttributeUInt8(512, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getRemainingBattLife() {
    auto result = (AttributeUInt8*)getAttributeById(513);
    if (result == nullptr) {
        result = new AttributeUInt8(513, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getHoursInOperation() {
    auto result = (AttributeUInt24*)getAttributeById(514);
    if (result == nullptr) {
        result = new AttributeUInt24(514, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getHoursInFault() {
    auto result = (AttributeUInt24*)getAttributeById(515);
    if (result == nullptr) {
        result = new AttributeUInt24(515, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt64* SeMeteringCluster::getExtendedStatus() {
    auto result = (AttributeUInt64*)getAttributeById(516);
    if (result == nullptr) {
        result = new AttributeUInt64(516, DataType::Map64);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getUnitOfMeasure() {
    auto result = (AttributeUInt8*)getAttributeById(768);
    if (result == nullptr) {
        result = new AttributeUInt8(768, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getMultiplier() {
    auto result = (AttributeUInt24*)getAttributeById(769);
    if (result == nullptr) {
        result = new AttributeUInt24(769, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getDivisor() {
    auto result = (AttributeUInt24*)getAttributeById(770);
    if (result == nullptr) {
        result = new AttributeUInt24(770, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getSummaFormatting() {
    auto result = (AttributeUInt8*)getAttributeById(771);
    if (result == nullptr) {
        result = new AttributeUInt8(771, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getDemandFormatting() {
    auto result = (AttributeUInt8*)getAttributeById(772);
    if (result == nullptr) {
        result = new AttributeUInt8(772, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getHistoricalConsumpFormatting() {
    auto result = (AttributeUInt8*)getAttributeById(773);
    if (result == nullptr) {
        result = new AttributeUInt8(773, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getMeteringDeviceType() {
    auto result = (AttributeUInt8*)getAttributeById(774);
    if (result == nullptr) {
        result = new AttributeUInt8(774, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* SeMeteringCluster::getSiteId() {
    auto result = (AttributeOctstr*)getAttributeById(775);
    if (result == nullptr) {
        result = new AttributeOctstr(775, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* SeMeteringCluster::getMeterSerialNumber() {
    auto result = (AttributeOctstr*)getAttributeById(776);
    if (result == nullptr) {
        result = new AttributeOctstr(776, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getEnergyCarrierUnitOfMeas() {
    auto result = (AttributeUInt8*)getAttributeById(777);
    if (result == nullptr) {
        result = new AttributeUInt8(777, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getEnergyCarrierSummFormatting() {
    auto result = (AttributeUInt8*)getAttributeById(778);
    if (result == nullptr) {
        result = new AttributeUInt8(778, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getEnergyCarrierDemandFormatting() {
    auto result = (AttributeUInt8*)getAttributeById(779);
    if (result == nullptr) {
        result = new AttributeUInt8(779, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getTemperatureUnitOfMeas() {
    auto result = (AttributeUInt8*)getAttributeById(780);
    if (result == nullptr) {
        result = new AttributeUInt8(780, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getTemperatureFormatting() {
    auto result = (AttributeUInt8*)getAttributeById(781);
    if (result == nullptr) {
        result = new AttributeUInt8(781, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* SeMeteringCluster::getModuleSerialNumber() {
    auto result = (AttributeOctstr*)getAttributeById(782);
    if (result == nullptr) {
        result = new AttributeOctstr(782, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* SeMeteringCluster::getOperatingTariffLevel() {
    auto result = (AttributeOctstr*)getAttributeById(783);
    if (result == nullptr) {
        result = new AttributeOctstr(783, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getInstantaneousDemand() {
    auto result = (AttributeInt24*)getAttributeById(1024);
    if (result == nullptr) {
        result = new AttributeInt24(1024, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getCurrentdayConsumpDelivered() {
    auto result = (AttributeUInt24*)getAttributeById(1025);
    if (result == nullptr) {
        result = new AttributeUInt24(1025, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getCurrentdayConsumpReceived() {
    auto result = (AttributeUInt24*)getAttributeById(1026);
    if (result == nullptr) {
        result = new AttributeUInt24(1026, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getPreviousdayConsumpDelivered() {
    auto result = (AttributeUInt24*)getAttributeById(1027);
    if (result == nullptr) {
        result = new AttributeUInt24(1027, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getPreviousdayConsumpReceived() {
    auto result = (AttributeUInt24*)getAttributeById(1028);
    if (result == nullptr) {
        result = new AttributeUInt24(1028, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getCurPartProfileIntStartTimeDelivered() {
    auto result = (AttributeUInt32*)getAttributeById(1029);
    if (result == nullptr) {
        result = new AttributeUInt32(1029, DataType::UTC);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getCurPartProfileIntStartTimeReceived() {
    auto result = (AttributeUInt32*)getAttributeById(1030);
    if (result == nullptr) {
        result = new AttributeUInt32(1030, DataType::UTC);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getCurPartProfileIntValueDelivered() {
    auto result = (AttributeUInt24*)getAttributeById(1031);
    if (result == nullptr) {
        result = new AttributeUInt24(1031, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getCurPartProfileIntValueReceived() {
    auto result = (AttributeUInt24*)getAttributeById(1032);
    if (result == nullptr) {
        result = new AttributeUInt24(1032, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentDayMaxPressure() {
    auto result = (AttributeUInt48*)getAttributeById(1033);
    if (result == nullptr) {
        result = new AttributeUInt48(1033, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getCurrentDayMinPressure() {
    auto result = (AttributeUInt48*)getAttributeById(1034);
    if (result == nullptr) {
        result = new AttributeUInt48(1034, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getPreviousDayMaxPressure() {
    auto result = (AttributeUInt48*)getAttributeById(1035);
    if (result == nullptr) {
        result = new AttributeUInt48(1035, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getPreviousDayMinPressure() {
    auto result = (AttributeUInt48*)getAttributeById(1036);
    if (result == nullptr) {
        result = new AttributeUInt48(1036, DataType::UInt48);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getCurrentDayMaxDemand() {
    auto result = (AttributeInt24*)getAttributeById(1037);
    if (result == nullptr) {
        result = new AttributeInt24(1037, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getPreviousDayMaxDemand() {
    auto result = (AttributeInt24*)getAttributeById(1038);
    if (result == nullptr) {
        result = new AttributeInt24(1038, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getCurrentMonthMaxDemand() {
    auto result = (AttributeInt24*)getAttributeById(1039);
    if (result == nullptr) {
        result = new AttributeInt24(1039, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getCurrentYearMaxDemand() {
    auto result = (AttributeInt24*)getAttributeById(1040);
    if (result == nullptr) {
        result = new AttributeInt24(1040, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getCurrentdayMaxEnergyCarrDemand() {
    auto result = (AttributeInt24*)getAttributeById(1041);
    if (result == nullptr) {
        result = new AttributeInt24(1041, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getPreviousdayMaxEnergyCarrDemand() {
    auto result = (AttributeInt24*)getAttributeById(1042);
    if (result == nullptr) {
        result = new AttributeInt24(1042, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getCurMonthMaxEnergyCarrDemand() {
    auto result = (AttributeInt24*)getAttributeById(1043);
    if (result == nullptr) {
        result = new AttributeInt24(1043, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getCurMonthMinEnergyCarrDemand() {
    auto result = (AttributeInt24*)getAttributeById(1044);
    if (result == nullptr) {
        result = new AttributeInt24(1044, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getCurYearMaxEnergyCarrDemand() {
    auto result = (AttributeInt24*)getAttributeById(1045);
    if (result == nullptr) {
        result = new AttributeInt24(1045, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* SeMeteringCluster::getCurYearMinEnergyCarrDemand() {
    auto result = (AttributeInt24*)getAttributeById(1046);
    if (result == nullptr) {
        result = new AttributeInt24(1046, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getMaxNumberOfPeriodsDelivered() {
    auto result = (AttributeUInt8*)getAttributeById(1280);
    if (result == nullptr) {
        result = new AttributeUInt8(1280, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getCurrentDemandDelivered() {
    auto result = (AttributeUInt24*)getAttributeById(1536);
    if (result == nullptr) {
        result = new AttributeUInt24(1536, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt24* SeMeteringCluster::getDemandLimit() {
    auto result = (AttributeUInt24*)getAttributeById(1537);
    if (result == nullptr) {
        result = new AttributeUInt24(1537, DataType::UInt24);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getDemandIntegrationPeriod() {
    auto result = (AttributeUInt8*)getAttributeById(1538);
    if (result == nullptr) {
        result = new AttributeUInt8(1538, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* SeMeteringCluster::getNumberOfDemandSubintervals() {
    auto result = (AttributeUInt8*)getAttributeById(1539);
    if (result == nullptr) {
        result = new AttributeUInt8(1539, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SeMeteringCluster::getDemandLimitArmDuration() {
    auto result = (AttributeUInt16*)getAttributeById(1540);
    if (result == nullptr) {
        result = new AttributeUInt16(1540, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SeMeteringCluster::getGenericAlarmMask() {
    auto result = (AttributeUInt16*)getAttributeById(2048);
    if (result == nullptr) {
        result = new AttributeUInt16(2048, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getElectricityAlarmMask() {
    auto result = (AttributeUInt32*)getAttributeById(2049);
    if (result == nullptr) {
        result = new AttributeUInt32(2049, DataType::Map32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SeMeteringCluster::getGenFlowPressureAlarmMask() {
    auto result = (AttributeUInt16*)getAttributeById(2050);
    if (result == nullptr) {
        result = new AttributeUInt16(2050, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SeMeteringCluster::getWaterSpecificAlarmMask() {
    auto result = (AttributeUInt16*)getAttributeById(2051);
    if (result == nullptr) {
        result = new AttributeUInt16(2051, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SeMeteringCluster::getHeatCoolSpecificAlarmMASK() {
    auto result = (AttributeUInt16*)getAttributeById(2052);
    if (result == nullptr) {
        result = new AttributeUInt16(2052, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SeMeteringCluster::getGasSpecificAlarmMask() {
    auto result = (AttributeUInt16*)getAttributeById(2053);
    if (result == nullptr) {
        result = new AttributeUInt16(2053, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt48* SeMeteringCluster::getExtendedGenericAlarmMask() {
    auto result = (AttributeUInt48*)getAttributeById(2054);
    if (result == nullptr) {
        result = new AttributeUInt48(2054, DataType::Map48);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* SeMeteringCluster::getManufactureAlarmMask() {
    auto result = (AttributeUInt16*)getAttributeById(2055);
    if (result == nullptr) {
        result = new AttributeUInt16(2055, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getBillToDate() {
    auto result = (AttributeUInt32*)getAttributeById(2560);
    if (result == nullptr) {
        result = new AttributeUInt32(2560, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getBillToDateTimeStamp() {
    auto result = (AttributeUInt32*)getAttributeById(2561);
    if (result == nullptr) {
        result = new AttributeUInt32(2561, DataType::UTC);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getProjectedBill() {
    auto result = (AttributeUInt32*)getAttributeById(2562);
    if (result == nullptr) {
        result = new AttributeUInt32(2562, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getProjectedBillTimeStamp() {
    auto result = (AttributeUInt32*)getAttributeById(2563);
    if (result == nullptr) {
        result = new AttributeUInt32(2563, DataType::UTC);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getNotificationControlFlags() {
    auto result = (AttributeUInt32*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt32(0, DataType::Map32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getNotificationFlags() {
    auto result = (AttributeUInt32*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt32(1, DataType::Map32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getPriceNotificationFlags() {
    auto result = (AttributeUInt32*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt32(2, DataType::Map32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getCalendarNotificationFlags() {
    auto result = (AttributeUInt32*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt32(3, DataType::Map32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getPrePayNotificationFlags() {
    auto result = (AttributeUInt32*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt32(4, DataType::Map32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* SeMeteringCluster::getDeviceManagementFlags() {
    auto result = (AttributeUInt32*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt32(5, DataType::Map32);
        addAttribute(result);
    }
    return result;
}

void SeMeteringCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeString* TelecommunicationsInformationCluster::getNodeDescription() {
    auto result = (AttributeString*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeString(0, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsInformationCluster::getDeliveryEnable() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* TelecommunicationsInformationCluster::getPushInformationTimer() {
    auto result = (AttributeUInt32*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt32(2, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsInformationCluster::getEnableSecureConfiguration() {
    auto result = (AttributeUInt8*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt8(3, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* TelecommunicationsInformationCluster::getNumberOfContents() {
    auto result = (AttributeUInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt16(16, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* TelecommunicationsInformationCluster::getContentRootID() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsVoiceOverZigbeeCluster::getCodecType() {
    auto result = (AttributeUInt8*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt8(0, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsVoiceOverZigbeeCluster::getSamplingFrequency() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsVoiceOverZigbeeCluster::getCodecrate() {
    auto result = (AttributeUInt8*)getAttributeById(2);
    if (result == nullptr) {
        result = new AttributeUInt8(2, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsVoiceOverZigbeeCluster::getEstablishmentTimeout() {
    auto result = (AttributeUInt8*)getAttributeById(3);
    if (result == nullptr) {
        result = new AttributeUInt8(3, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsVoiceOverZigbeeCluster::getCodecTypeSub1() {
    auto result = (AttributeUInt8*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt8(4, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsVoiceOverZigbeeCluster::getCodecTypeSub2() {
    auto result = (AttributeUInt8*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeUInt8(5, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsVoiceOverZigbeeCluster::getCodecTypeSub3() {
    auto result = (AttributeUInt8*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeUInt8(6, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsVoiceOverZigbeeCluster::getCompressionType() {
    auto result = (AttributeUInt8*)getAttributeById(7);
    if (result == nullptr) {
        result = new AttributeUInt8(7, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsVoiceOverZigbeeCluster::getCompressionRate() {
    auto result = (AttributeUInt8*)getAttributeById(8);
    if (result == nullptr) {
        result = new AttributeUInt8(8, DataType::Enum8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsVoiceOverZigbeeCluster::getOptionFlags() {
    auto result = (AttributeUInt8*)getAttributeById(9);
    if (result == nullptr) {
        result = new AttributeUInt8(9, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsVoiceOverZigbeeCluster::getThreshold() {
    auto result = (AttributeUInt8*)getAttributeById(10);
    if (result == nullptr) {
        result = new AttributeUInt8(10, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* TelecommunicationsChattingCluster::getUID() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeString* TelecommunicationsChattingCluster::getNickname() {
    auto result = (AttributeString*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeString(1, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* TelecommunicationsChattingCluster::getCID() {
    auto result = (AttributeUInt16*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeUInt16(16, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeString* TelecommunicationsChattingCluster::getName() {
    auto result = (AttributeString*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeString(17, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* TelecommunicationsChattingCluster::getEnableAddChat() {
    auto result = (AttributeUInt8*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeUInt8(18, DataType::Bool);
        addAttribute(result);
    }
    return result;
}

AttributeUInt56* HaApplianceIdentificationCluster::getBasicIdentification() {
    auto result = (AttributeUInt56*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt56(0, DataType::UInt56);
        addAttribute(result);
    }
    return result;
}

AttributeString* HaApplianceIdentificationCluster::getCompanyName() {
    auto result = (AttributeString*)getAttributeById(16);
    if (result == nullptr) {
        result = new AttributeString(16, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaApplianceIdentificationCluster::getCompanyId() {
    auto result = (AttributeUInt16*)getAttributeById(17);
    if (result == nullptr) {
        result = new AttributeUInt16(17, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeString* HaApplianceIdentificationCluster::getBrandName() {
    auto result = (AttributeString*)getAttributeById(18);
    if (result == nullptr) {
        result = new AttributeString(18, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaApplianceIdentificationCluster::getBrandId() {
    auto result = (AttributeUInt16*)getAttributeById(19);
    if (result == nullptr) {
        result = new AttributeUInt16(19, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* HaApplianceIdentificationCluster::getModel() {
    auto result = (AttributeOctstr*)getAttributeById(20);
    if (result == nullptr) {
        result = new AttributeOctstr(20, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* HaApplianceIdentificationCluster::getPartNumber() {
    auto result = (AttributeOctstr*)getAttributeById(21);
    if (result == nullptr) {
        result = new AttributeOctstr(21, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* HaApplianceIdentificationCluster::getProductRevision() {
    auto result = (AttributeOctstr*)getAttributeById(22);
    if (result == nullptr) {
        result = new AttributeOctstr(22, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* HaApplianceIdentificationCluster::getSoftwareRevision() {
    auto result = (AttributeOctstr*)getAttributeById(23);
    if (result == nullptr) {
        result = new AttributeOctstr(23, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

AttributeOctstr* HaApplianceIdentificationCluster::getProductTypeName() {
    auto result = (AttributeOctstr*)getAttributeById(24);
    if (result == nullptr) {
        result = new AttributeOctstr(24, DataType::Octstr);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaApplianceIdentificationCluster::getProductTypeId() {
    auto result = (AttributeUInt16*)getAttributeById(25);
    if (result == nullptr) {
        result = new AttributeUInt16(25, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HaApplianceIdentificationCluster::getCecedSpecificationVersion() {
    auto result = (AttributeUInt8*)getAttributeById(26);
    if (result == nullptr) {
        result = new AttributeUInt8(26, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeString* HaMeterIdentificationCluster::getCompanyName() {
    auto result = (AttributeString*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeString(0, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaMeterIdentificationCluster::getMeterTypeId() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaMeterIdentificationCluster::getDataQualityId() {
    auto result = (AttributeUInt16*)getAttributeById(4);
    if (result == nullptr) {
        result = new AttributeUInt16(4, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeString* HaMeterIdentificationCluster::getCustomerName() {
    auto result = (AttributeString*)getAttributeById(5);
    if (result == nullptr) {
        result = new AttributeString(5, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* HaMeterIdentificationCluster::getModel() {
    auto result = (AttributeString*)getAttributeById(6);
    if (result == nullptr) {
        result = new AttributeString(6, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* HaMeterIdentificationCluster::getPartNumber() {
    auto result = (AttributeString*)getAttributeById(7);
    if (result == nullptr) {
        result = new AttributeString(7, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* HaMeterIdentificationCluster::getProductRevision() {
    auto result = (AttributeString*)getAttributeById(8);
    if (result == nullptr) {
        result = new AttributeString(8, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* HaMeterIdentificationCluster::getSoftwareRevision() {
    auto result = (AttributeString*)getAttributeById(10);
    if (result == nullptr) {
        result = new AttributeString(10, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* HaMeterIdentificationCluster::getUtilityName() {
    auto result = (AttributeString*)getAttributeById(11);
    if (result == nullptr) {
        result = new AttributeString(11, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeString* HaMeterIdentificationCluster::getPod() {
    auto result = (AttributeString*)getAttributeById(12);
    if (result == nullptr) {
        result = new AttributeString(12, DataType::String);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* HaMeterIdentificationCluster::getAvailablePower() {
    auto result = (AttributeInt24*)getAttributeById(13);
    if (result == nullptr) {
        result = new AttributeInt24(13, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

AttributeInt24* HaMeterIdentificationCluster::getPowerThreshold() {
    auto result = (AttributeInt24*)getAttributeById(14);
    if (result == nullptr) {
        result = new AttributeInt24(14, DataType::Int24);
        addAttribute(result);
    }
    return result;
}

void HaApplianceEventsAlertsCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt32* HaApplianceStatisticsCluster::getLogMaxSize() {
    auto result = (AttributeUInt32*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt32(0, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HaApplianceStatisticsCluster::getLogQueueMaxSize() {
    auto result = (AttributeUInt8*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt8(1, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

void HaApplianceStatisticsCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt32* HaElectricalMeasurementCluster::getMeasurementType() {
    auto result = (AttributeUInt32*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt32(0, DataType::Map32);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getDcVoltage() {
    auto result = (AttributeInt16*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeInt16(256, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getDcVoltageMin() {
    auto result = (AttributeInt16*)getAttributeById(257);
    if (result == nullptr) {
        result = new AttributeInt16(257, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getDcvoltagemax() {
    auto result = (AttributeInt16*)getAttributeById(258);
    if (result == nullptr) {
        result = new AttributeInt16(258, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getDcCurrent() {
    auto result = (AttributeInt16*)getAttributeById(259);
    if (result == nullptr) {
        result = new AttributeInt16(259, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getDcCurrentMin() {
    auto result = (AttributeInt16*)getAttributeById(260);
    if (result == nullptr) {
        result = new AttributeInt16(260, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getDcCurrentMax() {
    auto result = (AttributeInt16*)getAttributeById(261);
    if (result == nullptr) {
        result = new AttributeInt16(261, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getDcPower() {
    auto result = (AttributeInt16*)getAttributeById(262);
    if (result == nullptr) {
        result = new AttributeInt16(262, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getDcPowerMin() {
    auto result = (AttributeInt16*)getAttributeById(263);
    if (result == nullptr) {
        result = new AttributeInt16(263, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getDcPowerMax() {
    auto result = (AttributeInt16*)getAttributeById(264);
    if (result == nullptr) {
        result = new AttributeInt16(264, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getDcVoltageMultiplier() {
    auto result = (AttributeUInt16*)getAttributeById(512);
    if (result == nullptr) {
        result = new AttributeUInt16(512, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getDcVoltageDivisor() {
    auto result = (AttributeUInt16*)getAttributeById(513);
    if (result == nullptr) {
        result = new AttributeUInt16(513, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getDcCurrentMultiplier() {
    auto result = (AttributeUInt16*)getAttributeById(514);
    if (result == nullptr) {
        result = new AttributeUInt16(514, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getDcCurrentDivisor() {
    auto result = (AttributeUInt16*)getAttributeById(515);
    if (result == nullptr) {
        result = new AttributeUInt16(515, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getDcPowerMultiplier() {
    auto result = (AttributeUInt16*)getAttributeById(516);
    if (result == nullptr) {
        result = new AttributeUInt16(516, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getDcPowerDivisor() {
    auto result = (AttributeUInt16*)getAttributeById(517);
    if (result == nullptr) {
        result = new AttributeUInt16(517, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcFrequency() {
    auto result = (AttributeUInt16*)getAttributeById(768);
    if (result == nullptr) {
        result = new AttributeUInt16(768, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcFrequencyMin() {
    auto result = (AttributeUInt16*)getAttributeById(769);
    if (result == nullptr) {
        result = new AttributeUInt16(769, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcFrequencyMax() {
    auto result = (AttributeUInt16*)getAttributeById(770);
    if (result == nullptr) {
        result = new AttributeUInt16(770, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getNeutralCurrent() {
    auto result = (AttributeUInt16*)getAttributeById(771);
    if (result == nullptr) {
        result = new AttributeUInt16(771, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt32* HaElectricalMeasurementCluster::getTotalActivePower() {
    auto result = (AttributeInt32*)getAttributeById(772);
    if (result == nullptr) {
        result = new AttributeInt32(772, DataType::Int32);
        addAttribute(result);
    }
    return result;
}

AttributeInt32* HaElectricalMeasurementCluster::getTotalReactivePower() {
    auto result = (AttributeInt32*)getAttributeById(773);
    if (result == nullptr) {
        result = new AttributeInt32(773, DataType::Int32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* HaElectricalMeasurementCluster::getTotalApparentPower() {
    auto result = (AttributeUInt32*)getAttributeById(774);
    if (result == nullptr) {
        result = new AttributeUInt32(774, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeas1stHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(775);
    if (result == nullptr) {
        result = new AttributeInt16(775, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeas3rdHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(776);
    if (result == nullptr) {
        result = new AttributeInt16(776, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeas5thHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(777);
    if (result == nullptr) {
        result = new AttributeInt16(777, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeas7thHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(778);
    if (result == nullptr) {
        result = new AttributeInt16(778, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeas9thHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(779);
    if (result == nullptr) {
        result = new AttributeInt16(779, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeas11thHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(780);
    if (result == nullptr) {
        result = new AttributeInt16(780, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeasPhase1stHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(781);
    if (result == nullptr) {
        result = new AttributeInt16(781, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeasPhase3rdHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(782);
    if (result == nullptr) {
        result = new AttributeInt16(782, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeasPhase5thHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(783);
    if (result == nullptr) {
        result = new AttributeInt16(783, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeasPhase7thHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(784);
    if (result == nullptr) {
        result = new AttributeInt16(784, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeasPhase9thHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(785);
    if (result == nullptr) {
        result = new AttributeInt16(785, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getMeasPhase11thHarmonicCurrent() {
    auto result = (AttributeInt16*)getAttributeById(786);
    if (result == nullptr) {
        result = new AttributeInt16(786, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcFrequencyMultiplier() {
    auto result = (AttributeUInt16*)getAttributeById(1024);
    if (result == nullptr) {
        result = new AttributeUInt16(1024, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcFrequencyDivisor() {
    auto result = (AttributeUInt16*)getAttributeById(1025);
    if (result == nullptr) {
        result = new AttributeUInt16(1025, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* HaElectricalMeasurementCluster::getPowerMultiplier() {
    auto result = (AttributeUInt32*)getAttributeById(1026);
    if (result == nullptr) {
        result = new AttributeUInt32(1026, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* HaElectricalMeasurementCluster::getPowerDivisor() {
    auto result = (AttributeUInt32*)getAttributeById(1027);
    if (result == nullptr) {
        result = new AttributeUInt32(1027, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeInt8* HaElectricalMeasurementCluster::getHarmonicCurrentMultiplier() {
    auto result = (AttributeInt8*)getAttributeById(1028);
    if (result == nullptr) {
        result = new AttributeInt8(1028, DataType::Int8);
        addAttribute(result);
    }
    return result;
}

AttributeInt8* HaElectricalMeasurementCluster::getPhaseHarmonicCurrentMultiplier() {
    auto result = (AttributeInt8*)getAttributeById(1029);
    if (result == nullptr) {
        result = new AttributeInt8(1029, DataType::Int8);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getInstantaneousVoltage() {
    auto result = (AttributeInt16*)getAttributeById(1280);
    if (result == nullptr) {
        result = new AttributeInt16(1280, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getInstantaneousLineCurrent() {
    auto result = (AttributeUInt16*)getAttributeById(1281);
    if (result == nullptr) {
        result = new AttributeUInt16(1281, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getInstantaneousActiveCurrent() {
    auto result = (AttributeInt16*)getAttributeById(1282);
    if (result == nullptr) {
        result = new AttributeInt16(1282, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getInstantaneousReactiveCurrent() {
    auto result = (AttributeInt16*)getAttributeById(1283);
    if (result == nullptr) {
        result = new AttributeInt16(1283, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getInstantaneousPower() {
    auto result = (AttributeInt16*)getAttributeById(1284);
    if (result == nullptr) {
        result = new AttributeInt16(1284, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltage() {
    auto result = (AttributeUInt16*)getAttributeById(1285);
    if (result == nullptr) {
        result = new AttributeUInt16(1285, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageMin() {
    auto result = (AttributeUInt16*)getAttributeById(1286);
    if (result == nullptr) {
        result = new AttributeUInt16(1286, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageMax() {
    auto result = (AttributeUInt16*)getAttributeById(1287);
    if (result == nullptr) {
        result = new AttributeUInt16(1287, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsCurrent() {
    auto result = (AttributeUInt16*)getAttributeById(1288);
    if (result == nullptr) {
        result = new AttributeUInt16(1288, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsCurrentMin() {
    auto result = (AttributeUInt16*)getAttributeById(1289);
    if (result == nullptr) {
        result = new AttributeUInt16(1289, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsCurrentMax() {
    auto result = (AttributeUInt16*)getAttributeById(1290);
    if (result == nullptr) {
        result = new AttributeUInt16(1290, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getActivePower() {
    auto result = (AttributeInt16*)getAttributeById(1291);
    if (result == nullptr) {
        result = new AttributeInt16(1291, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getActivePowerMin() {
    auto result = (AttributeInt16*)getAttributeById(1292);
    if (result == nullptr) {
        result = new AttributeInt16(1292, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getActivePowerMax() {
    auto result = (AttributeInt16*)getAttributeById(1293);
    if (result == nullptr) {
        result = new AttributeInt16(1293, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getReactivePower() {
    auto result = (AttributeInt16*)getAttributeById(1294);
    if (result == nullptr) {
        result = new AttributeInt16(1294, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getApparentPower() {
    auto result = (AttributeUInt16*)getAttributeById(1295);
    if (result == nullptr) {
        result = new AttributeUInt16(1295, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt8* HaElectricalMeasurementCluster::getPowerFactor() {
    auto result = (AttributeInt8*)getAttributeById(1296);
    if (result == nullptr) {
        result = new AttributeInt8(1296, DataType::Int8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAverageRmsVoltageMeasPeriod() {
    auto result = (AttributeUInt16*)getAttributeById(1297);
    if (result == nullptr) {
        result = new AttributeUInt16(1297, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAverageRmsOverVoltageCounter() {
    auto result = (AttributeUInt16*)getAttributeById(1298);
    if (result == nullptr) {
        result = new AttributeUInt16(1298, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAverageRmsUnderVoltageCounter() {
    auto result = (AttributeUInt16*)getAttributeById(1299);
    if (result == nullptr) {
        result = new AttributeUInt16(1299, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsExtremeOverVoltagePeriod() {
    auto result = (AttributeUInt16*)getAttributeById(1300);
    if (result == nullptr) {
        result = new AttributeUInt16(1300, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsExtremeUnderVoltagePeriod() {
    auto result = (AttributeUInt16*)getAttributeById(1301);
    if (result == nullptr) {
        result = new AttributeUInt16(1301, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageSagPeriod() {
    auto result = (AttributeUInt16*)getAttributeById(1302);
    if (result == nullptr) {
        result = new AttributeUInt16(1302, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageSwellPeriod() {
    auto result = (AttributeUInt16*)getAttributeById(1303);
    if (result == nullptr) {
        result = new AttributeUInt16(1303, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcVoltageMultiplier() {
    auto result = (AttributeUInt16*)getAttributeById(1536);
    if (result == nullptr) {
        result = new AttributeUInt16(1536, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcVoltageDivisor() {
    auto result = (AttributeUInt16*)getAttributeById(1537);
    if (result == nullptr) {
        result = new AttributeUInt16(1537, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcCurrentMultiplier() {
    auto result = (AttributeUInt16*)getAttributeById(1538);
    if (result == nullptr) {
        result = new AttributeUInt16(1538, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcCurrentDivisor() {
    auto result = (AttributeUInt16*)getAttributeById(1539);
    if (result == nullptr) {
        result = new AttributeUInt16(1539, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcPowerMultiplier() {
    auto result = (AttributeUInt16*)getAttributeById(1540);
    if (result == nullptr) {
        result = new AttributeUInt16(1540, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcPowerDivisor() {
    auto result = (AttributeUInt16*)getAttributeById(1541);
    if (result == nullptr) {
        result = new AttributeUInt16(1541, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HaElectricalMeasurementCluster::getDcOverloadAlarmsMask() {
    auto result = (AttributeUInt8*)getAttributeById(1792);
    if (result == nullptr) {
        result = new AttributeUInt8(1792, DataType::Map8);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getDcVoltageOverload() {
    auto result = (AttributeInt16*)getAttributeById(1793);
    if (result == nullptr) {
        result = new AttributeInt16(1793, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getDcCurrentOverload() {
    auto result = (AttributeInt16*)getAttributeById(1794);
    if (result == nullptr) {
        result = new AttributeInt16(1794, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAcAlarmsMask() {
    auto result = (AttributeUInt16*)getAttributeById(2048);
    if (result == nullptr) {
        result = new AttributeUInt16(2048, DataType::Map16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getAcVoltageOverload() {
    auto result = (AttributeInt16*)getAttributeById(2049);
    if (result == nullptr) {
        result = new AttributeInt16(2049, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getAcCurrentOverload() {
    auto result = (AttributeInt16*)getAttributeById(2050);
    if (result == nullptr) {
        result = new AttributeInt16(2050, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getAcActivePowerOverload() {
    auto result = (AttributeInt16*)getAttributeById(2051);
    if (result == nullptr) {
        result = new AttributeInt16(2051, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getAcReactivePowerOverload() {
    auto result = (AttributeInt16*)getAttributeById(2052);
    if (result == nullptr) {
        result = new AttributeInt16(2052, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getAverageRmsOverVoltage() {
    auto result = (AttributeInt16*)getAttributeById(2053);
    if (result == nullptr) {
        result = new AttributeInt16(2053, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getAverageRmsUnderVoltage() {
    auto result = (AttributeInt16*)getAttributeById(2054);
    if (result == nullptr) {
        result = new AttributeInt16(2054, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getRmsExtremeOverVoltage() {
    auto result = (AttributeInt16*)getAttributeById(2055);
    if (result == nullptr) {
        result = new AttributeInt16(2055, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getRmsExtremeUnderVoltage() {
    auto result = (AttributeInt16*)getAttributeById(2056);
    if (result == nullptr) {
        result = new AttributeInt16(2056, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getRmsVoltageSag() {
    auto result = (AttributeInt16*)getAttributeById(2057);
    if (result == nullptr) {
        result = new AttributeInt16(2057, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getRmsVoltageSwell() {
    auto result = (AttributeInt16*)getAttributeById(2058);
    if (result == nullptr) {
        result = new AttributeInt16(2058, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getLineCurrentPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2305);
    if (result == nullptr) {
        result = new AttributeUInt16(2305, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getActiveCurrentPhB() {
    auto result = (AttributeInt16*)getAttributeById(2306);
    if (result == nullptr) {
        result = new AttributeInt16(2306, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getReactiveCurrentPhB() {
    auto result = (AttributeInt16*)getAttributeById(2307);
    if (result == nullptr) {
        result = new AttributeInt16(2307, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltagePhB() {
    auto result = (AttributeUInt16*)getAttributeById(2309);
    if (result == nullptr) {
        result = new AttributeUInt16(2309, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageMinPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2310);
    if (result == nullptr) {
        result = new AttributeUInt16(2310, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageMaxPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2311);
    if (result == nullptr) {
        result = new AttributeUInt16(2311, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsCurrentPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2312);
    if (result == nullptr) {
        result = new AttributeUInt16(2312, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsCurrentMinPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2313);
    if (result == nullptr) {
        result = new AttributeUInt16(2313, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsCurrentMaxPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2314);
    if (result == nullptr) {
        result = new AttributeUInt16(2314, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getActivePowerPhB() {
    auto result = (AttributeInt16*)getAttributeById(2315);
    if (result == nullptr) {
        result = new AttributeInt16(2315, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getActivePowerMinPhB() {
    auto result = (AttributeInt16*)getAttributeById(2316);
    if (result == nullptr) {
        result = new AttributeInt16(2316, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getActivePowerMaxPhB() {
    auto result = (AttributeInt16*)getAttributeById(2317);
    if (result == nullptr) {
        result = new AttributeInt16(2317, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getReactivePowerPhB() {
    auto result = (AttributeInt16*)getAttributeById(2318);
    if (result == nullptr) {
        result = new AttributeInt16(2318, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getApparentPowerPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2319);
    if (result == nullptr) {
        result = new AttributeUInt16(2319, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt8* HaElectricalMeasurementCluster::getPowerFactorPhB() {
    auto result = (AttributeInt8*)getAttributeById(2320);
    if (result == nullptr) {
        result = new AttributeInt8(2320, DataType::Int8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAverageRmsVoltageMeasurePeriodPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2321);
    if (result == nullptr) {
        result = new AttributeUInt16(2321, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAverageRmsOverVoltageCounterPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2322);
    if (result == nullptr) {
        result = new AttributeUInt16(2322, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAverageUnderVoltageCounterPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2323);
    if (result == nullptr) {
        result = new AttributeUInt16(2323, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsExtremeOverVoltagePeriodPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2324);
    if (result == nullptr) {
        result = new AttributeUInt16(2324, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsExtremeUnderVoltagePeriodPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2325);
    if (result == nullptr) {
        result = new AttributeUInt16(2325, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageSagPeriodPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2326);
    if (result == nullptr) {
        result = new AttributeUInt16(2326, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageSwellPeriodPhB() {
    auto result = (AttributeUInt16*)getAttributeById(2327);
    if (result == nullptr) {
        result = new AttributeUInt16(2327, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getLineCurrentPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2561);
    if (result == nullptr) {
        result = new AttributeUInt16(2561, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getActiveCurrentPhC() {
    auto result = (AttributeInt16*)getAttributeById(2562);
    if (result == nullptr) {
        result = new AttributeInt16(2562, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getReactiveCurrentPhC() {
    auto result = (AttributeInt16*)getAttributeById(2563);
    if (result == nullptr) {
        result = new AttributeInt16(2563, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltagePhC() {
    auto result = (AttributeUInt16*)getAttributeById(2565);
    if (result == nullptr) {
        result = new AttributeUInt16(2565, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageMinPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2566);
    if (result == nullptr) {
        result = new AttributeUInt16(2566, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageMaxPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2567);
    if (result == nullptr) {
        result = new AttributeUInt16(2567, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsCurrentPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2568);
    if (result == nullptr) {
        result = new AttributeUInt16(2568, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsCurrentMinPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2569);
    if (result == nullptr) {
        result = new AttributeUInt16(2569, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsCurrentMaxPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2570);
    if (result == nullptr) {
        result = new AttributeUInt16(2570, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getActivePowerPhC() {
    auto result = (AttributeInt16*)getAttributeById(2571);
    if (result == nullptr) {
        result = new AttributeInt16(2571, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getActivePowerMinPhC() {
    auto result = (AttributeInt16*)getAttributeById(2572);
    if (result == nullptr) {
        result = new AttributeInt16(2572, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getActivePowerMaxPhC() {
    auto result = (AttributeInt16*)getAttributeById(2573);
    if (result == nullptr) {
        result = new AttributeInt16(2573, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeInt16* HaElectricalMeasurementCluster::getReactivePowerPhC() {
    auto result = (AttributeInt16*)getAttributeById(2574);
    if (result == nullptr) {
        result = new AttributeInt16(2574, DataType::Int16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getApparentPowerPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2575);
    if (result == nullptr) {
        result = new AttributeUInt16(2575, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeInt8* HaElectricalMeasurementCluster::getPowerFactorPhC() {
    auto result = (AttributeInt8*)getAttributeById(2576);
    if (result == nullptr) {
        result = new AttributeInt8(2576, DataType::Int8);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAverageRmsVoltageMeasPeriodPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2577);
    if (result == nullptr) {
        result = new AttributeUInt16(2577, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAverageRmsOverVoltageCounterPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2578);
    if (result == nullptr) {
        result = new AttributeUInt16(2578, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getAverageUnderVoltageCounterPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2579);
    if (result == nullptr) {
        result = new AttributeUInt16(2579, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsExtremeOverVoltagePeriodPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2580);
    if (result == nullptr) {
        result = new AttributeUInt16(2580, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsExtremeUnderVoltagePeriodPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2581);
    if (result == nullptr) {
        result = new AttributeUInt16(2581, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageSagPeriodPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2582);
    if (result == nullptr) {
        result = new AttributeUInt16(2582, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaElectricalMeasurementCluster::getRmsVoltageSwellPeriodPhC() {
    auto result = (AttributeUInt16*)getAttributeById(2583);
    if (result == nullptr) {
        result = new AttributeUInt16(2583, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

void HaElectricalMeasurementCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeUInt16* HaDiagnosticCluster::getNumberOfResets() {
    auto result = (AttributeUInt16*)getAttributeById(0);
    if (result == nullptr) {
        result = new AttributeUInt16(0, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getPersistentMemoryWrites() {
    auto result = (AttributeUInt16*)getAttributeById(1);
    if (result == nullptr) {
        result = new AttributeUInt16(1, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* HaDiagnosticCluster::getMacRxBcast() {
    auto result = (AttributeUInt32*)getAttributeById(256);
    if (result == nullptr) {
        result = new AttributeUInt32(256, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* HaDiagnosticCluster::getMacTxBcast() {
    auto result = (AttributeUInt32*)getAttributeById(257);
    if (result == nullptr) {
        result = new AttributeUInt32(257, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* HaDiagnosticCluster::getMacRxUcast() {
    auto result = (AttributeUInt32*)getAttributeById(258);
    if (result == nullptr) {
        result = new AttributeUInt32(258, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt32* HaDiagnosticCluster::getMacTxUcast() {
    auto result = (AttributeUInt32*)getAttributeById(259);
    if (result == nullptr) {
        result = new AttributeUInt32(259, DataType::UInt32);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getMacTxUcastRetry() {
    auto result = (AttributeUInt16*)getAttributeById(260);
    if (result == nullptr) {
        result = new AttributeUInt16(260, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getMacTxUcastFail() {
    auto result = (AttributeUInt16*)getAttributeById(261);
    if (result == nullptr) {
        result = new AttributeUInt16(261, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getAPSRxBcast() {
    auto result = (AttributeUInt16*)getAttributeById(262);
    if (result == nullptr) {
        result = new AttributeUInt16(262, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getAPSTxBcast() {
    auto result = (AttributeUInt16*)getAttributeById(263);
    if (result == nullptr) {
        result = new AttributeUInt16(263, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getAPSRxUcast() {
    auto result = (AttributeUInt16*)getAttributeById(264);
    if (result == nullptr) {
        result = new AttributeUInt16(264, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getAPSTxUcastSuccess() {
    auto result = (AttributeUInt16*)getAttributeById(265);
    if (result == nullptr) {
        result = new AttributeUInt16(265, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getAPSTxUcastRetry() {
    auto result = (AttributeUInt16*)getAttributeById(266);
    if (result == nullptr) {
        result = new AttributeUInt16(266, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getAPSTxUcastFail() {
    auto result = (AttributeUInt16*)getAttributeById(267);
    if (result == nullptr) {
        result = new AttributeUInt16(267, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getRouteDiscInitiated() {
    auto result = (AttributeUInt16*)getAttributeById(268);
    if (result == nullptr) {
        result = new AttributeUInt16(268, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getNeighborAdded() {
    auto result = (AttributeUInt16*)getAttributeById(269);
    if (result == nullptr) {
        result = new AttributeUInt16(269, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getNeighborRemoved() {
    auto result = (AttributeUInt16*)getAttributeById(270);
    if (result == nullptr) {
        result = new AttributeUInt16(270, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getNeighborStale() {
    auto result = (AttributeUInt16*)getAttributeById(271);
    if (result == nullptr) {
        result = new AttributeUInt16(271, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getJoinIndication() {
    auto result = (AttributeUInt16*)getAttributeById(272);
    if (result == nullptr) {
        result = new AttributeUInt16(272, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getChildMoved() {
    auto result = (AttributeUInt16*)getAttributeById(273);
    if (result == nullptr) {
        result = new AttributeUInt16(273, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getNwkFcFailure() {
    auto result = (AttributeUInt16*)getAttributeById(274);
    if (result == nullptr) {
        result = new AttributeUInt16(274, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getApsFcFailure() {
    auto result = (AttributeUInt16*)getAttributeById(275);
    if (result == nullptr) {
        result = new AttributeUInt16(275, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getApsUnauthorizedKey() {
    auto result = (AttributeUInt16*)getAttributeById(276);
    if (result == nullptr) {
        result = new AttributeUInt16(276, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getNwkDecryptFailures() {
    auto result = (AttributeUInt16*)getAttributeById(277);
    if (result == nullptr) {
        result = new AttributeUInt16(277, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getApsDecryptFailures() {
    auto result = (AttributeUInt16*)getAttributeById(278);
    if (result == nullptr) {
        result = new AttributeUInt16(278, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getPacketBufferAllocateFailures() {
    auto result = (AttributeUInt16*)getAttributeById(279);
    if (result == nullptr) {
        result = new AttributeUInt16(279, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getRelayedUcast() {
    auto result = (AttributeUInt16*)getAttributeById(280);
    if (result == nullptr) {
        result = new AttributeUInt16(280, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getPhyToMacQueueLimitReached() {
    auto result = (AttributeUInt16*)getAttributeById(281);
    if (result == nullptr) {
        result = new AttributeUInt16(281, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getPacketValidateDropCount() {
    auto result = (AttributeUInt16*)getAttributeById(282);
    if (result == nullptr) {
        result = new AttributeUInt16(282, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt16* HaDiagnosticCluster::getAverageMacRetryPerApsMessageSent() {
    auto result = (AttributeUInt16*)getAttributeById(283);
    if (result == nullptr) {
        result = new AttributeUInt16(283, DataType::UInt16);
        addAttribute(result);
    }
    return result;
}

AttributeUInt8* HaDiagnosticCluster::getLastMessageLqi() {
    auto result = (AttributeUInt8*)getAttributeById(284);
    if (result == nullptr) {
        result = new AttributeUInt8(284, DataType::UInt8);
        addAttribute(result);
    }
    return result;
}

AttributeInt8* HaDiagnosticCluster::getLastMessageRssi() {
    auto result = (AttributeInt8*)getAttributeById(285);
    if (result == nullptr) {
        result = new AttributeInt8(285, DataType::Int8);
        addAttribute(result);
    }
    return result;
}

void TouchlinkCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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

AttributeString* WiserDeviceInfoCluster::getDeviceInfo() {
    auto result = (AttributeString*)getAttributeById(32);
    if (result == nullptr) {
        result = new AttributeString(32, DataType::String);
        addAttribute(result);
    }
    return result;
}

void ZosungIRTransmitCluster::processCommand(uint8_t commandId, Memory& request, Memory& response) {
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
