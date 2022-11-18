#include "OnOffCluster.h"

void OnOffCluster::on() {
    getAttrById(ON_OFF_CLUSTER_ATTRIBUTE_ON_OFF)->set((uint64_t)true);
    _onCallback.call();
}

void OnOffCluster::off() {
    getAttrById(ON_OFF_CLUSTER_ATTRIBUTE_ON_OFF)->set((uint64_t)false);
    _offCallback.call();
}

void OnOffCluster::toggle() {
    setOnOffAttribute(!getOnOffAttribute());
    _toggleCallback.call();
}

void OnOffCluster::setOnOffAttribute(bool onoff) {
    setAttribute(ON_OFF_CLUSTER_ATTRIBUTE_ON_OFF, ZHA_TYPE_BOOL, onoff);
}

bool OnOffCluster::getOnOffAttribute() {
    ZHA_Attribute* attr = getAttrById(ON_OFF_CLUSTER_ATTRIBUTE_ON_OFF);
    if (attr) {
        return attr->getValueBool();
    }
    return false;
}

OnOffCluster::OnOffCluster()
    : ZHA_Cluster(ON_OFF_CLUSTER_ID) {
    /* mandatory attributes, default values */
    setOnOffAttribute(false);
}

Zcl::Status OnOffCluster::processCommand(Buffer& frameData) {
    switch (frameData.get(2)) {
	    case ON_OFF_CLUSTER_ON_COMMAND:
	        on();
	        return Zcl::Status::Success;
	    case ON_OFF_CLUSTER_OFF_COMMAND:
	        off();
	        return Zcl::Status::Success;
	    case ON_OFF_CLUSTER_TOGGLE_COMMAND:
	        toggle();
	        return Zcl::Status::Success;
        default:
            return Zcl::Status::UnsupportedAttribute;
    }
}
