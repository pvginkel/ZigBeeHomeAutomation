#pragma once

#include "Arduino.h"
#include "support.h"
#include "ZHA_Cluster.h"

#define LEVEL_CONTROL_CLUSTER_ID 0x0008
#define LEVEL_CONTROL_CLUSTER_ATTRIBUTE_CURRENT_LEVEL 0x0000
#define LEVEL_CONTROL_CLUSTER_ATTRIBUTE_REMAINING_TIME 0x0001
#define LEVEL_CONTROL_CLUSTER_ATTRIBUTE_ONOFF_TRANSITION_TIME 0x0010
#define LEVEL_CONTROL_CLUSTER_ATTRIBUTE_ON_LEVEL 0x0011
#define LEVEL_CONTROL_CLUSTER_COMMAND_MOVE_TO_LEVEL 0x00
#define LEVEL_CONTROL_CLUSTER_COMMAND_MOVE 0x01
#define LEVEL_CONTROL_CLUSTER_COMMAND_STEP 0x02
#define LEVEL_CONTROL_CLUSTER_COMMAND_STOP 0x03
#define LEVEL_CONTROL_CLUSTER_COMMAND_MOVE_TO_LEVEL_WITH_ON_OFF 0x04
#define LEVEL_CONTROL_CLUSTER_COMMAND_MOVE_WITH_ON_OFF 0x05
#define LEVEL_CONTROL_CLUSTER_COMMAND_STEP_WITH_ON_OFF 0x06
#define LEVEL_CONTROL_CLUSTER_COMMAND_STOP_WITH_ON_OFF 0x06

class LevelControlCluster : public ZHA_Cluster {
    CallbackArgs<uint8_t, uint16_t> _moveToLevelWithOnOffCallback;

public:
    LevelControlCluster();
    void moveToLevelWithOnOff(uint8_t level, uint16_t transition_time);

    void setMoveToLevelWithOnOffCallback(CallbackArgs<uint8_t, uint16_t>::Func func, uintptr_t data = 0) {
        _moveToLevelWithOnOffCallback.set(func, data);
    }

private:
    Zcl::Status processCommand(Buffer& frameData) override;
};
