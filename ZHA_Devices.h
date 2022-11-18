#pragma once

#include "XBee.h"
#include "ZHA_Cluster.h"
#include "Printers.h"
#include "ZHA_Utils.h"

#define ZHA_ON_OFF_OUTPUT_DEVICE_ID              0x0002
#define ZHA_LEVEL_CONTROLLABLE_OUTPUT_DEVICE_ID  0x0003

/* ZCL Status Fields */
#define STATUS_SUCCESS                            0x00
#define STATUS_FAILURE                            0x01
#define STATUS_UNSUPPORTED_ATTRIBUTE              0x86

/* General Command Frames */
#define ZCL_READ_ATTRIBUTES                       0x00
#define ZCL_READ_ATTRIBUTES_RESPONSE              0x01
#define ZCL_WRITE_ATTRIBUTES                      0x02
#define ZCL_WRITE_ATTRIBUTES_UNDIVIDED            0x03
#define ZCL_WRITE_ATTRIBUTES_RESPONSE             0x04
#define ZCL_WRITE_ATTRIBYTES_NO_RESPONSE          0x05
#define ZCL_CONFIGURE_REPORTING                   0x06
#define ZCL_CONFIGURE_REPORTING_RESPONSE          0x07
#define ZCL_READ_REPORTING_CONFIGURATION          0x08
#define ZCL_READ_REPORTING_CONFIGURATION_RESPONSE 0x09
#define ZCL_REPORT_ATTRIBUTES                     0x0A
#define ZCL_DEFAULT_RESPONSE                      0x0B
#define ZCL_DISCOVER_ATTRIBUTES                   0x0C
#define ZCL_DISCOVER_ATTRIBUTES_RESPONSE          0x0D
#define ZCL_READ_ATTRBIUTES_STRUCTURED            0x0E
#define ZCL_WRITE_ATTRIBUTES_STRUCTURED           0x0F
#define ZCL_WRITE_ATTRIBUTES_STRUCTURED_RESPONSE  0x10

class ZHA_Device {
    uint8_t _endpointId;
    LinkedList<ZHA_Cluster*> _inClusters;
    LinkedList<ZHA_Cluster*> _outClusters;
    uint16_t _deviceId;

public:
    ZHA_Device(uint8_t endpointId, uint16_t deviceId);
    void addInCluster(ZHA_Cluster *inCluster);
    void addOutCluster(ZHA_Cluster *outCluster);
    ZHA_Cluster *getInClusterById(uint16_t clusterId);
    ZHA_Cluster *getOutClusterById(uint16_t clusterId);

    uint16_t getDeviceId();
    uint8_t getEndpointId();
    int getNumInClusters();
    int getNumOutClusters();

    ZHA_Cluster *getInCluster(uint8_t num);
    ZHA_Cluster *getOutCluster(uint8_t num);

    bool processGeneralCommand(Buffer& frameData, ZBExplicitRxResponse& message, Buffer& buffer);

private:
    bool processGeneralReadAttributesCommand(Buffer& frameData, ZBExplicitRxResponse& message, Buffer& buffer);
    bool processGeneralDiscoverAttributesCommand(Buffer& frameData, ZBExplicitRxResponse& message, Buffer& buffer);
    bool processGeneralConfigureReportingCommand(Buffer& frameData, ZBExplicitRxResponse& message, Buffer& buffer);
};
