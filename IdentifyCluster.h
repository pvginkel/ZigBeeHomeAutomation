#pragma once

#include "ZHA_Cluster.h"

#define IDENTITY_CLUSTER_ID                           0x0003
#define IDENTITY_CLUSTER_ATTRIBUTE_IDENTIFY_TIME      0x0000

class IdentifyCluster : public ZHA_Cluster {
public:
    IdentifyCluster();
};
