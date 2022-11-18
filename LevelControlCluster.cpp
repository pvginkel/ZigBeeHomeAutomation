#include "LevelControlCluster.h"

LevelControlCluster::LevelControlCluster()
	: ZHA_Cluster(LEVEL_CONTROL_CLUSTER_ID) {
    setAttribute(LEVEL_CONTROL_CLUSTER_ATTRIBUTE_CURRENT_LEVEL, ZHA_TYPE_UINT8, 0x0);
}

void LevelControlCluster::moveToLevelWithOnOff(uint8_t level, uint16_t transition_time) {
    getAttrById(LEVEL_CONTROL_CLUSTER_ATTRIBUTE_CURRENT_LEVEL)->set(level);
    _moveToLevelWithOnOffCallback.call(level, transition_time);
}

Zcl::Status LevelControlCluster::processCommand(Buffer& frameData) {
    switch (frameData.get(2)) {
	    case LEVEL_CONTROL_CLUSTER_COMMAND_MOVE_TO_LEVEL_WITH_ON_OFF:
	        uint8_t level = frameData.get(3);
	        moveToLevelWithOnOff(level, 0);
	        return Zcl::Status::Success;
    }
    return Zcl::Status::UnsupportedAttribute;
}
