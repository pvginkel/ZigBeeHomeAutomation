#pragma once

class BasicDevice: public Device {
	GenBasicCluster _basicCluster;
	GenIdentifyCluster _identifyCluster;

public:
	BasicDevice(uint8_t endpointId, uint16_t deviceId, PowerSource powerSource) : Device(endpointId, deviceId) {
		addInCluster(_basicCluster);
		addInCluster(_identifyCluster);

		_basicCluster.setZclVersion(1);
		_basicCluster.setPowerSource((uint8_t)powerSource);
	}

	GenBasicCluster& getBasicCluster() {
		return _basicCluster;
	}

	GenIdentifyCluster& getIdentifyCluster() {
		return _identifyCluster;
	}
};
