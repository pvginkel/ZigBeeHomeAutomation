#include "BasicCluster.h"

BasicCluster::BasicCluster() : ZHA_Cluster(BASIC_CLUSTER_ID) {
    /* mandatory attributes, default values */
    setZCLVersion(0x01);
    setPowerSource(0x00);
}

void BasicCluster::setZCLVersion(uint8_t version) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_ZCL_VERSION, ZHA_TYPE_UINT8, version);
}

void BasicCluster::setApplicationVersion(uint8_t version) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_APPLICATION_VERSION, ZHA_TYPE_UINT8, version);
}

void BasicCluster::setStackVersion(uint8_t version) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_STACK_VERSION, ZHA_TYPE_UINT8, version);
}

void BasicCluster::setHWVersion(uint8_t version) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_HW_VERSION, ZHA_TYPE_UINT8, version);
}

void BasicCluster::setManufacturerName(String manufacturerName) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_MANUFACTURER_NAME, ZHA_TYPE_CHAR_STRING, manufacturerName);
}

void BasicCluster::setModelIdentifier(String modelId) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_MODEL_IDENTIFIER, ZHA_TYPE_CHAR_STRING, modelId);
}

void BasicCluster::setDateCode(String dateCode) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_DATE_CODE, ZHA_TYPE_CHAR_STRING, dateCode);
}

void BasicCluster::setPowerSource(uint8_t powerSource) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_POWER_SOURCE, ZHA_TYPE_ENUMERATION8, powerSource);
}

void BasicCluster::setLocationDescription(String locationDescription) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_LOCATION_DESCRIPTION, ZHA_TYPE_CHAR_STRING, locationDescription);
}

void BasicCluster::setPhysicalEnvironment(uint8_t physicalEnvironment) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_PHYSICAL_ENVIRONMENT, ZHA_TYPE_ENUMERATION8, physicalEnvironment);
}

void BasicCluster::setDeviceEnabled(bool deviceEnabled) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_DEVICE_ENABLED, ZHA_TYPE_BOOL, deviceEnabled);
}

void BasicCluster::setAlarmMask(uint8_t alarmMask) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_ALARM_MASK, ZHA_TYPE_BITMAP8, alarmMask);
}

void BasicCluster::setDisableLocalConfig(uint8_t disableLocalConfig) {
    setAttribute(BASIC_CLUSTER_ATTRIBUTE_DISABLE_LOCAL_CONFIG, ZHA_TYPE_BITMAP8, disableLocalConfig);
}
