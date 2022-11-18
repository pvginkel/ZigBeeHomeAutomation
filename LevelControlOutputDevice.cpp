#include "LevelControlOutputDevice.h"

LevelControlOutputDevice::LevelControlOutputDevice(uint8_t endpointId)
    : ZHA_Device(endpointId, ZHA_LEVEL_CONTROLLABLE_OUTPUT_DEVICE_ID) {
    addInCluster(&basic_cluster);
    addInCluster(&identify_cluster);
    addInCluster(&onoff_cluster);
    addInCluster(&groups_cluster);
    addInCluster(&scenes_cluster);
    addInCluster(&level_cluster);
}
