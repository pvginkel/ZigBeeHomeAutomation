#pragma once

#define BASIC_CLUSTER_ID                              0x0000
#define BASIC_CLUSTER_ATTRIBUTE_ZCL_VERSION           0x0000
#define BASIC_CLUSTER_ATTRIBUTE_APPLICATION_VERSION   0x0001
#define BASIC_CLUSTER_ATTRIBUTE_STACK_VERSION         0x0002
#define BASIC_CLUSTER_ATTRIBUTE_HW_VERSION            0x0003
#define BASIC_CLUSTER_ATTRIBUTE_MANUFACTURER_NAME     0x0004
#define BASIC_CLUSTER_ATTRIBUTE_MODEL_IDENTIFIER      0x0005
#define BASIC_CLUSTER_ATTRIBUTE_DATE_CODE             0x0006
#define BASIC_CLUSTER_ATTRIBUTE_POWER_SOURCE          0x0007
#define BASIC_CLUSTER_ATTRIBUTE_LOCATION_DESCRIPTION  0x0010
#define BASIC_CLUSTER_ATTRIBUTE_PHYSICAL_ENVIRONMENT  0x0011
#define BASIC_CLUSTER_ATTRIBUTE_DEVICE_ENABLED        0x0012
#define BASIC_CLUSTER_ATTRIBUTE_ALARM_MASK            0x0013
#define BASIC_CLUSTER_ATTRIBUTE_DISABLE_LOCAL_CONFIG  0x0014
#include "ZHA_Cluster.h"

class BasicCluster : public ZHA_Cluster {
public:
    BasicCluster();

    void setZCLVersion(uint8_t version);
    void setApplicationVersion(uint8_t version);
    void setStackVersion(uint8_t version);
    void setHWVersion(uint8_t version);
    void setManufacturerName(String manufacturerName);
    void setModelIdentifier(String modelId);
    void setDateCode(String dateCode);
    void setPowerSource(uint8_t powerSource);
    void setLocationDescription(String locationDescription);
    void setPhysicalEnvironment(uint8_t physicalEnvironment);
    void setDeviceEnabled(bool deviceEnabled);
    void setAlarmMask(uint8_t alarmMask);
    void setDisableLocalConfig(uint8_t disableLocalConfig);
};
