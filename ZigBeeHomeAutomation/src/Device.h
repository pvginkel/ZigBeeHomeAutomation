#pragma once

class DeviceManager;

class Device {
    uint8_t _endpointId;
    ArrayList<Cluster*> _clusters;
    uint16_t _deviceId;

public:
    Device(uint8_t endpointId, uint16_t deviceId);

    uint8_t getEndpointId() { return _endpointId; }
    uint16_t getDeviceId() { return _deviceId; }

	void addCluster(Cluster& cluster);
    Cluster *getClusterById(uint16_t clusterId);
    int getClusterCount();
    Cluster *getClusterByIndex(int index);

    Status processGeneralCommand(DeviceManager& deviceManager, Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response);

private:
    Status processGeneralReadAttributesCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response);
    Status processGeneralWriteAttributesCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response);
    Status processGeneralDiscoverAttributesCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response);
    Status processGeneralConfigureReportingCommand(DeviceManager& deviceManager, Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response);
};
