#pragma once

class BasicDevice: public Device {
	GenBasicCluster _basicCluster;
	GenIdentifyCluster _identifyCluster;

public:
	BasicDevice(uint8_t endpointId, uint16_t deviceId, PowerSource powerSource) : Device(endpointId, deviceId) {
		addInCluster(_basicCluster);
		addInCluster(_identifyCluster);

		_basicCluster.getZclVersion()->setValue(1);
		_basicCluster.getPowerSource()->setValue((uint8_t)powerSource);
	}

	GenBasicCluster& getBasicCluster() {
		return _basicCluster;
	}

	GenIdentifyCluster& getIdentifyCluster() {
		return _identifyCluster;
	}
};
