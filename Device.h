#pragma once

class Device {
    uint8_t _endpointId;
    LinkedList<Cluster*> _inClusters;
    LinkedList<Cluster*> _outClusters;
    uint16_t _deviceId;

public:
    Device(uint8_t endpointId, uint16_t deviceId);

    uint16_t getDeviceId();
    uint8_t getEndpointId();

	void addInCluster(Cluster& cluster);
    void addOutCluster(Cluster& cluster);
    Cluster *getInClusterById(uint16_t clusterId);
    Cluster *getOutClusterById(uint16_t clusterId);
    int getInClusterCount();
    int getOutClusterCount();
    Cluster *getInCluster(int index);
    Cluster *getOutCluster(int index);

    Status processGeneralCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response);

private:
    Status processGeneralReadAttributesCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response);
    Status processGeneralDiscoverAttributesCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response);
};
