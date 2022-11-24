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

    bool processGeneralCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response);

private:
    bool processGeneralReadAttributesCommand(Frame& frame, Memory& request, ZBExplicitRxResponse& message, Memory& response);
    bool processGeneralDiscoverAttributesCommand(Frame& frame, Memory& frameData, ZBExplicitRxResponse& message, Memory& buffer);
    bool processGeneralConfigureReportingCommand(Frame& frame, Memory& frameData, ZBExplicitRxResponse& message, Memory& buffer);
};
