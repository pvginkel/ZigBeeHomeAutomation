#include "GroupsCluster.h"

GroupsCluster::GroupsCluster()
    : ZHA_Cluster(GROUPS_CLUSTER_ID) {
    setAttribute(GROUPS_CLUSTER_ATTRIBUTE_NAME_SUPPORT, ZHA_TYPE_BITMAP8, 0x0000);
}
