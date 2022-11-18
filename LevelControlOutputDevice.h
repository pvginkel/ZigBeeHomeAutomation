#pragma once

#include "Arduino.h"
#include "BasicCluster.h"
#include "GroupsCluster.h"
#include "IdentifyCluster.h"
#include "LevelControlCluster.h"
#include "OnOffCluster.h"
#include "ScenesCluster.h"
#include "ZHA_Devices.h"

class LevelControlOutputDevice: public ZHA_Device {
    BasicCluster basic_cluster;
    IdentifyCluster identify_cluster;
    OnOffCluster onoff_cluster;
    GroupsCluster groups_cluster;
    ScenesCluster scenes_cluster;
    LevelControlCluster level_cluster;

public:
    LevelControlOutputDevice(uint8_t endpointId);

    BasicCluster* getBasicCluster() { return &basic_cluster; }
    OnOffCluster* getOnOffCluster() { return &onoff_cluster; }
    LevelControlCluster* getLevelControlCluster() { return &level_cluster; }
};
