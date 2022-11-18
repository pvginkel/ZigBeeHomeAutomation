#pragma once

#include "ZHA_Cluster.h"

#define GROUPS_CLUSTER_ID                             0x0004
#define GROUPS_CLUSTER_ATTRIBUTE_NAME_SUPPORT         0x0000

class GroupsCluster : public ZHA_Cluster {
public:
    GroupsCluster();
};
