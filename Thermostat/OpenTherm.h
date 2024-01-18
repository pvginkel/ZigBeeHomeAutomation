/*
OpenTherm.h - OpenTherm Library for the ESP8266/Arduino platform
https://github.com/ihormelnyk/OpenTherm
http://ihormelnyk.com/pages/OpenTherm
Licensed under MIT license
Copyright 2018, Ihor Melnyk

Frame Structure:
P MGS-TYPE SPARE DATA-ID  DATA-VALUE
0 000      0000  00000000 00000000 00000000
*/

#pragma once

#include <stdint.h>
#include <Arduino.h>

enum class OpenThermResponseStatus {
	None,
	Success,
	Invalid,
	Timeout
};

enum class OpenThermMessageType: byte {
	/*  Master to Slave */
	ReadData        = 0b000,
	WriteData       = 0b001,
	InvalidData     = 0b010,
	Reserved        = 0b011,
	/* Slave to Master */
	ReadAck         = 0b100,
	WriteAck        = 0b101,
	DataInvalid     = 0b110,
	UnknownDataId   = 0b111
};

enum class OpenThermMessageID: byte {
	Status, // flag8 / flag8  Master and Slave Status flags.
	TSet, // f8.8  Control setpoint  ie CH  water temperature setpoint (°C)
	MConfigMMemberIDcode, // flag8 / u8  Master Configuration Flags /  Master MemberID Code
	SConfigSMemberIDcode, // flag8 / u8  Slave Configuration Flags /  Slave MemberID Code
	Command, // u8 / u8  Remote Command
	ASFflags, // / OEM-fault-code  flag8 / u8  Application-specific fault flags and OEM fault code
	RBPflags, // flag8 / flag8  Remote boiler parameter transfer-enable & read/write flags
	CoolingControl, // f8.8  Cooling control signal (%)
	TsetCH2, // f8.8  Control setpoint for 2e CH circuit (°C)
	TrOverride, // f8.8  Remote override room setpoint
	TSP, // u8 / u8  Number of Transparent-Slave-Parameters supported by slave
	TSPindexTSPvalue, // u8 / u8  Index number / Value of referred-to transparent slave parameter.
	FHBsize, // u8 / u8  Size of Fault-History-Buffer supported by slave
	FHBindexFHBvalue, // u8 / u8  Index number / Value of referred-to fault-history buffer entry.
	MaxRelModLevelSetting, // f8.8  Maximum relative modulation level setting (%)
	MaxCapacityMinModLevel, // u8 / u8  Maximum boiler capacity (kW) / Minimum boiler modulation level(%)
	TrSet, // f8.8  Room Setpoint (°C)
	RelModLevel, // f8.8  Relative Modulation Level (%)
	CHPressure, // f8.8  Water pressure in CH circuit  (bar)
	DHWFlowRate, // f8.8  Water flow rate in DHW circuit. (litres/minute)
	DayTime, // special / u8  Day of Week and Time of Day
	Date, // u8 / u8  Calendar date
	Year, // u16  Calendar year
	TrSetCH2, // f8.8  Room Setpoint for 2nd CH circuit (°C)
	Tr, // f8.8  Room temperature (°C)
	Tboiler, // f8.8  Boiler flow water temperature (°C)
	Tdhw, // f8.8  DHW temperature (°C)
	Toutside, // f8.8  Outside temperature (°C)
	Tret, // f8.8  Return water temperature (°C)
	Tstorage, // f8.8  Solar storage temperature (°C)
	Tcollector, // f8.8  Solar collector temperature (°C)
	TflowCH2, // f8.8  Flow water temperature CH2 circuit (°C)
	Tdhw2, // f8.8  Domestic hot water temperature 2 (°C)
	Texhaust, // s16  Boiler exhaust temperature (°C)
	TdhwSetUBTdhwSetLB = 48, // s8 / s8  DHW setpoint upper & lower bounds for adjustment  (°C)
	MaxTSetUBMaxTSetLB, // s8 / s8  Max CH water setpoint upper & lower bounds for adjustment  (°C)
	HcratioUBHcratioLB, // s8 / s8  OTC heat curve ratio upper & lower bounds for adjustment
	TdhwSet = 56, // f8.8  DHW setpoint (°C)    (Remote parameter 1)
	MaxTSet, // f8.8  Max CH water setpoint (°C)  (Remote parameters 2)
	Hcratio, // f8.8  OTC heat curve ratio (°C)  (Remote parameter 3)
	RemoteOverrideFunction = 100, // flag8 / -  Function of manual and program changes in master and remote room setpoint.
	OEMDiagnosticCode = 115, // u16  OEM-specific diagnostic/service code
	BurnerStarts, // u16  Number of starts burner
	CHPumpStarts, // u16  Number of starts CH pump
	DHWPumpValveStarts, // u16  Number of starts DHW pump/valve
	DHWBurnerStarts, // u16  Number of starts burner during DHW mode
	BurnerOperationHours, // u16  Number of hours that burner is in operation (i.e. flame on)
	CHPumpOperationHours, // u16  Number of hours that CH pump has been running
	DHWPumpValveOperationHours, // u16  Number of hours that DHW pump has been running or DHW valve has been opened
	DHWBurnerOperationHours, // u16  Number of hours that burner is in operation during DHW mode
	OpenThermVersionMaster, // f8.8  The implemented version of the OpenTherm Protocol Specification in the master.
	OpenThermVersionSlave, // f8.8  The implemented version of the OpenTherm Protocol Specification in the slave.
	MasterVersion, // u8 / u8  Master product version number and type
	SlaveVersion, // u8 / u8  Slave product version number and type
};

enum class OpenThermStatus {
	NotInitialized,
	Ready,
	Delay,
	RequestSending,
	ResponseWaiting,
	ResponseStartBit,
	ResponseReceiving,
	ResponseReady,
	ResponseInvalid
};

struct OpenThermMessage
{
	OpenThermMessage(OpenThermMessageID id, OpenThermMessageType type, uint16_t payload);
	OpenThermMessage(OpenThermMessageID id, OpenThermMessageType type, uint8_t lb, uint8_t hb);
	OpenThermMessage(OpenThermMessageID id, OpenThermMessageType type, float payload);

	OpenThermMessageID id;
	OpenThermMessageType type;
	uint16_t payload;

	uint8_t getHB() const;
	uint8_t getLB() const;
	float getFloat() const;

private:
	static uint16_t serializeFloat(float value);
};

typedef unsigned long OpenThermFrame_t;

class OpenTherm
{
public:
	OpenTherm(uint8_t inPin, uint8_t outPin, bool isSlave);
	void begin(void(*handleInterruptCallback)(), void(*processResponseCallback)(OpenThermFrame_t, OpenThermResponseStatus) = nullptr);
	bool isReady() const;
	void sendResponse(OpenThermMessage message);
	bool trySendRequest(OpenThermMessage message);
	OpenThermMessage getLastResponse() const;
	OpenThermResponseStatus getLastResponseStatus();
	void handleInterrupt();
	void process();
	void end() const;

private:
	uint8_t _inPin;
	uint8_t _outPin;
	bool _isSlave;

	volatile OpenThermStatus _status;
	volatile OpenThermFrame_t _response;
	volatile OpenThermResponseStatus _responseStatus;
	volatile unsigned long _responseTimestamp;
	volatile byte _responseBitIndex;

	void(*_handleInterruptCallback)();
	void(*_processResponseCallback)(OpenThermFrame_t, OpenThermResponseStatus);

	void sendFrame(OpenThermFrame_t frame);
	void sendBit(bool high) const;
	int readState() const;
	void setState(bool active) const;
	void activateBoiler() const;

	static OpenThermFrame_t parity(OpenThermFrame_t frame);
	static OpenThermFrame_t serializeMessage(OpenThermMessage& message);
	static OpenThermMessage deserializeMessage(OpenThermFrame_t frame);
};
