#pragma once

#include "ZHA_Cluster.h"

#define SCENES_CLUSTER_ID                             0x0005
#define SCENES_CLUSTER_ATTRIBUTE_SCENE_COUNT          0x0000
#define SCENES_CLUSTER_ATTRIBUTE_CURRENT_SCENE        0x0001
#define SCENES_CLUSTER_ATTRIBUTE_CURRENT_GROUP        0x0002
#define SCENES_CLUSTER_ATTRIBUTE_SCENE_VALID          0x0003
#define SCENES_CLUSTER_ATTRIBUTE_NAME_SUPPORT         0x0004

class ScenesCluster : public ZHA_Cluster {
public:
    ScenesCluster();
};
