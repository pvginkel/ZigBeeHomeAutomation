#pragma once
#include "BasicCluster.h"
#include "IdentifyCluster.h"
#include "OnOffCluster.h"
#include "ZHA_Devices.h"

class OnOffDevice : public ZHA_Device {
    BasicCluster _basicCluster;
    IdentifyCluster _identityCluster;
    OnOffCluster _onOffCluster;

public:
    OnOffDevice(uint8_t endpointId) : ZHA_Device(endpointId, ZHA_ON_OFF_OUTPUT_DEVICE_ID) {
        addInCluster(&_basicCluster);
        addInCluster(&_identityCluster);
        addInCluster(&_onOffCluster);
    }

    BasicCluster& basicCluster() { return _basicCluster; }
    IdentifyCluster& identityCluster() { return _identityCluster; }
    OnOffCluster& onOffCluster() { return _onOffCluster; }
};
