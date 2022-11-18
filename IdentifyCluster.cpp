#include "IdentifyCluster.h"

IdentifyCluster::IdentifyCluster()
	: ZHA_Cluster(IDENTITY_CLUSTER_ID) {
	setAttribute(IDENTITY_CLUSTER_ATTRIBUTE_IDENTIFY_TIME, ZHA_TYPE_UINT16, 0x0000);
}
