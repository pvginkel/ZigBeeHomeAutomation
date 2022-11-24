#include "ZigBee.h"

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
