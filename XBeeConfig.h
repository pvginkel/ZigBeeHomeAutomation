#pragma once

#include "arduino.h"
#include <SoftwareSerial.h>
#include "support.h"

class XBeeConfig
{
private:
	static const int BUFFER_LENGTH = 100;

	Stream* _stream;
	time_t _timeout;
	char* _buffer;

public:
	XBeeConfig(Stream& stream) : _stream(&stream), _buffer(new char[BUFFER_LENGTH]) { }

	~XBeeConfig() {
		delete _buffer;
	}

	void enterConfig() {
		_timeout = _stream->getTimeout();
		_stream->setTimeout(2000);

		char* buffer = new char[BUFFER_LENGTH];
		int read;

		while (true) {
			LOG("Connecting...");
			_stream->write("+++");
			if (readCommand()) {
				break;
			}
		}
	}

	void printConfig() {
		LOG("Extended PAN ID: ", send("ID"));
		LOG("Scan Channels: ", send("SC"));
		LOG("Scan Duration: ", send("SD"));
		LOG("Zigbee Stack Profile: ", send("ZS"));
		LOG("Node Join Time: ", send("NJ"));
		LOG("Network Watchdog Timeout: ", send("NW"));
		LOG("Coordinator Join Verification: ", send("JV"));
		LOG("Join Notification: ", send("JN"));
		LOG("Operating Extended PAN ID: ", send("OP"));
		LOG("Operating 16-bit PAN ID: ", send("OI"));
		LOG("Operating Channel: ", send("CH"));
		LOG("Number of Remaining Children: ", send("NC"));
		LOG("Coordinator Enable: ", send("CE"));
		LOG("Miscellaneous Device Options: ", send("DO"));
		LOG("Joining Device Controls: ", send("DC"));
		LOG("Initial 16-bit PAN ID: ", send("II"));
		LOG("Energy Detect: ", send("ED"));
		LOG("Serial Number High: ", send("SH"));
		LOG("Serial Number Low: ", send("SL"));
		LOG("16-bit Network Address: ", send("MY"));
		LOG("16-bit Parent Network Address: ", send("MP"));
		LOG("Destination Address High: ", send("DH"));
		LOG("Destination Address Low: ", send("DL"));
		LOG("Node Identifier: ", send("NI"));
		LOG("Maximum Unicast Hops: ", send("NH"));
		LOG("Broadcast Hops: ", send("BH"));
		LOG("Aggregate Routing Notification: ", send("AR"));
		LOG("Device Type Identifier: ", send("DD"));
		LOG("Node Discover Timeout: ", send("NT"));
		LOG("Network Discovery Options: ", send("NO"));
		LOG("Maximum Packet Payload Bytes: ", send("NP"));
		LOG("Conflict Report: ", send("CR"));
		LOG("Source Endpoint: ", send("SE"));
		LOG("Destination Endpoint: ", send("DE"));
		LOG("Cluster ID: ", send("CI"));
		LOG("Transmit Options: ", send("TO"));
		LOG("TX Power Level: ", send("PL"));
		LOG("Power at PL4: ", send("PP"));
		LOG("Power Mode: ", send("PM"));
		LOG("Encryption Enable: ", send("EE"));
		LOG("Encryption Options: ", send("EO"));
		LOG("Link Key: ", send("KY"));
		LOG("Trust Center Network Key: ", send("NK"));
		LOG("Interface Data Rate: ", send("BD"));
		LOG("Parity: ", send("NB"));
		LOG("Stop Bits: ", send("SB"));
		LOG("Packetization Timeout: ", send("RO"));
		LOG("DIO6/RTS: ", send("D6"));
		LOG("DIO7/CTS: ", send("D7"));
		LOG("API Enable: ", send("AP"));
		LOG("API Options: ", send("AO"));
		LOG("Command Mode Timeout: ", send("CT"));
		LOG("Guard Times: ", send("GT"));
		LOG("Command Character: ", send("CC"));
		LOG("Sleep Period: ", send("SP"));
		LOG("Number of Cycles Between ON_SLEEP: ", send("SN"));
		LOG("Sleep Mode: ", send("SM"));
		LOG("Time before Sleep: ", send("ST"));
		LOG("Sleep Options: ", send("SO"));
		LOG("Wake Host Delay: ", send("WH"));
		LOG("Polling Rate: ", send("PO"));
		LOG("AD0/DIO0 Configuration: ", send("D0"));
		LOG("AD1/DIO1/PTI_En Configuration: ", send("D1"));
		LOG("AD2/DIO2 Configuration: ", send("D2"));
		LOG("AD3/DIO3 Configuration: ", send("D3"));
		LOG("DIO4 Configuration: ", send("D4"));
		LOG("DIO5/Associate Configuration: ", send("D5"));
		LOG("DIO8/DTR/SLP_RQ: ", send("D8"));
		LOG("DIO9/ON_SLEEP: ", send("D9"));
		LOG("RSSI/PWM0 Configuration: ", send("P0"));
		LOG("DIO11/PWM1 Configuration: ", send("P1"));
		LOG("DIO12 Configuration: ", send("P2"));
		LOG("DIO13/DOUT Configuration: ", send("P3"));
		LOG("DIO14/DIN: ", send("P4"));
		LOG("DIO15/SPI_MISO: ", send("P5"));
		LOG("SPI_MOSI Configuration: ", send("P6"));
		LOG("DIO17/SPI_SSEL: ", send("P7"));
		LOG("DIO18/SPI_SCLK: ", send("P8"));
		LOG("DIO19/SPI_ATTN/PTI_DATA: ", send("P9"));
		LOG("Pull-up/Down Resistor Enable: ", send("PR"));
		LOG("Pull Up/Down Direction: ", send("PD"));
		LOG("Associate LED Blink Time: ", send("LT"));
		LOG("RSSI PWM Timer: ", send("RP"));
		LOG("I/O Sample Rate: ", send("IR"));
		LOG("Digital Change Detection: ", send("IC"));
		LOG("Voltage Supply Monitoring: ", send("V+"));
		LOG("Firmware Version: ", send("VR"));
		LOG("Hardware Version: ", send("HV"));
		LOG("Association Indication: ", send("AI"));
		LOG("Voltage Supply Monitoring: ", send("%V"));
		LOG("Received Signal Strength: ", send("DB"));
		LOG("Temperature: ", send("TP"));
		LOG("Version Long: ", send("VL"));

		//LOG("Apply Changes: ", send("AC"));
		//LOG("Active Scan: ", send("AS"));
		//LOG("Write: ", send("WR"));
		//LOG("Restore Defaults: ", send("RE"));
		//LOG("Software Reset: ", send("FR"));
		//LOG("Network Reset: ", send("NR"));
		//LOG("Sleep Immediately: ", send("SI"));
		//LOG("Commissioning Pushbutton: ", send("CB"));
		//LOG("Clear Binding and Group Tables: ", send("&X"));
		//LOG("Node Discovery: ", send("ND"));
		//LOG("Destination Node: ", send("DN"));
		//LOG("Disable Joining: ", send("DJ"));
		//LOG("Force Sample: ", send("IS"));
	}

	void exitConfig() {
		LOG("Exit Command mode: ", send("CN"));

		_stream->setTimeout(_timeout);
	}

	char* send(char* command) {
		_stream->write("AT");
		_stream->write(command);
		_stream->write('\r');
		readCommand();
		return _buffer;
	}

private:
	bool readCommand() {
		int read = _stream->readBytesUntil('\r', _buffer, BUFFER_LENGTH - 1);
		_buffer[read] = 0;
		return read > 0;
	}
};

