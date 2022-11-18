#pragma once

#include "Arduino.h"
#include "support.h"
#include "ZHA_Cluster.h"

#define ON_OFF_CLUSTER_ID                       0x0006
#define ON_OFF_CLUSTER_ATTRIBUTE_ON_OFF         0x0000
#define ON_OFF_CLUSTER_OFF_COMMAND              0x00
#define ON_OFF_CLUSTER_ON_COMMAND               0x01
#define ON_OFF_CLUSTER_TOGGLE_COMMAND           0x02

class OnOffCluster : public ZHA_Cluster {
    Callback _onCallback;
    Callback _offCallback;
    Callback _toggleCallback;

public:
    OnOffCluster();

    Zcl::Status processCommand(Buffer& frameData) override;
    void on();
    void off();
    void toggle();

    // Attribute set functions
    void setOnOffAttribute(bool onoff);

    // Attribute get functions
    bool getOnOffAttribute();

    // Callback set functions
    void setOnCallback(Callback::Func func, uintptr_t data = 0) { _onCallback.set(func, data); }
    void setOffCallback(Callback::Func func, uintptr_t data = 0) { _offCallback.set(func, data); }
    void setToggleCallback(Callback::Func func, uintptr_t data = 0) { _toggleCallback.set(func, data); }
};
