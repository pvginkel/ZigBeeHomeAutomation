#pragma once

#include "arduino.h"
#include <SoftwareSerial.h>
#include "support.h"

class XBeeConfig
{
private:
	static const int BUFFER_LENGTH = 100;

public:
	bool setup(Stream& stream) {
		auto timeout = stream.getTimeout();
		stream.setTimeout(2000);

		char* buffer = new char[BUFFER_LENGTH];
		int read;

		while (true) {
			LOG("Connecting...");
			stream.write("+++");
			if (readCommand(stream, buffer)) {
				break;
			}
		}

		send(stream, "RE", "Restore Defaults", buffer);
		send(stream, "NI TEST LAMP 1", "Node Identifier", buffer);

		send(stream, "ID", "Extended PAN ID", buffer);
		send(stream, "SC", "Scan Channels", buffer);
		send(stream, "SD", "Scan Duration", buffer);
		send(stream, "ZS", "Zigbee Stack Profile", buffer);
		send(stream, "NJ", "Node Join Time", buffer);
		send(stream, "NW", "Network Watchdog Timeout", buffer);
		send(stream, "JV", "Coordinator Join Verification", buffer);
		send(stream, "JN", "Join Notification", buffer);
		send(stream, "OP", "Operating Extended PAN ID", buffer);
		send(stream, "OI", "Operating 16-bit PAN ID", buffer);
		send(stream, "CH", "Operating Channel", buffer);
		send(stream, "NC", "Number of Remaining Children", buffer);
		send(stream, "CE", "Coordinator Enable", buffer);
		send(stream, "DO", "Miscellaneous Device Options", buffer);
		send(stream, "DC", "Joining Device Controls", buffer);
		send(stream, "II", "Initial 16-bit PAN ID", buffer);
		send(stream, "ED", "Energy Detect", buffer);
		send(stream, "SH", "Serial Number High", buffer);
		send(stream, "SL", "Serial Number Low", buffer);
		send(stream, "MY", "16-bit Network Address", buffer);
		send(stream, "MP", "16-bit Parent Network Address", buffer);
		send(stream, "DH", "Destination Address High", buffer);
		send(stream, "DL", "Destination Address Low", buffer);
		send(stream, "NI", "Node Identifier", buffer);
		send(stream, "NH", "Maximum Unicast Hops", buffer);
		send(stream, "BH", "Broadcast Hops", buffer);
		send(stream, "AR", "Aggregate Routing Notification", buffer);
		send(stream, "DD", "Device Type Identifier", buffer);
		send(stream, "NT", "Node Discover Timeout", buffer);
		send(stream, "NO", "Network Discovery Options", buffer);
		send(stream, "NP", "Maximum Packet Payload Bytes", buffer);
		send(stream, "CR", "Conflict Report", buffer);
		send(stream, "SE", "Source Endpoint", buffer);
		send(stream, "DE", "Destination Endpoint", buffer);
		send(stream, "CI", "Cluster ID", buffer);
		send(stream, "TO", "Transmit Options", buffer);
		send(stream, "PL", "TX Power Level", buffer);
		send(stream, "PP", "Power at PL4", buffer);
		send(stream, "PM", "Power Mode", buffer);
		send(stream, "EE", "Encryption Enable", buffer);
		send(stream, "EO", "Encryption Options", buffer);
		send(stream, "KY", "Link Key", buffer);
		send(stream, "NK", "Trust Center Network Key", buffer);
		send(stream, "BD", "Interface Data Rate", buffer);
		send(stream, "NB", "Parity", buffer);
		send(stream, "SB", "Stop Bits", buffer);
		send(stream, "RO", "Packetization Timeout", buffer);
		send(stream, "D6", "DIO6/RTS", buffer);
		send(stream, "D7", "DIO7/CTS", buffer);
		send(stream, "AP", "API Enable", buffer);
		send(stream, "AO", "API Options", buffer);
		send(stream, "CT", "Command Mode Timeout", buffer);
		send(stream, "GT", "Guard Times", buffer);
		send(stream, "CC", "Command Character", buffer);
		send(stream, "SP", "Sleep Period", buffer);
		send(stream, "SN", "Number of Cycles Between ON_SLEEP", buffer);
		send(stream, "SM", "Sleep Mode", buffer);
		send(stream, "ST", "Time before Sleep", buffer);
		send(stream, "SO", "Sleep Options", buffer);
		send(stream, "WH", "Wake Host Delay", buffer);
		send(stream, "PO", "Polling Rate", buffer);
		send(stream, "D0", "AD0/DIO0 Configuration", buffer);
		send(stream, "D1", "AD1/DIO1/PTI_En Configuration", buffer);
		send(stream, "D2", "AD2/DIO2 Configuration", buffer);
		send(stream, "D3", "AD3/DIO3 Configuration", buffer);
		send(stream, "D4", "DIO4 Configuration", buffer);
		send(stream, "D5", "DIO5/Associate Configuration", buffer);
		send(stream, "D8", "DIO8/DTR/SLP_RQ", buffer);
		send(stream, "D9", "DIO9/ON_SLEEP", buffer);
		send(stream, "P0", "RSSI/PWM0 Configuration", buffer);
		send(stream, "P1", "DIO11/PWM1 Configuration", buffer);
		send(stream, "P2", "DIO12 Configuration", buffer);
		send(stream, "P3", "DIO13/DOUT Configuration", buffer);
		send(stream, "P4", "DIO14/DIN", buffer);
		send(stream, "P5", "DIO15/SPI_MISO", buffer);
		send(stream, "P6", "SPI_MOSI Configuration", buffer);
		send(stream, "P7", "DIO17/SPI_SSEL", buffer);
		send(stream, "P8", "DIO18/SPI_SCLK", buffer);
		send(stream, "P9", "DIO19/SPI_ATTN/PTI_DATA", buffer);
		send(stream, "PR", "Pull-up/Down Resistor Enable", buffer);
		send(stream, "PD", "Pull Up/Down Direction", buffer);
		send(stream, "LT", "Associate LED Blink Time", buffer);
		send(stream, "RP", "RSSI PWM Timer", buffer);
		send(stream, "IR", "I/O Sample Rate", buffer);
		send(stream, "IC", "Digital Change Detection", buffer);
		send(stream, "V+", "Voltage Supply Monitoring", buffer);
		send(stream, "VR", "Firmware Version", buffer);
		send(stream, "HV", "Hardware Version", buffer);
		send(stream, "AI", "Association Indication", buffer);
		send(stream, "%V", "Voltage Supply Monitoring", buffer);
		send(stream, "DB", "Received Signal Strength", buffer);
		send(stream, "TP", "Temperature", buffer);
		send(stream, "VL", "Version Long", buffer);

		//send(stream, "AC", "Apply Changes", buffer);
		//send(stream, "AS", "Active Scan", buffer);
		//send(stream, "WR", "Write", buffer);
		//send(stream, "RE", "Restore Defaults", buffer);
		//send(stream, "FR", "Software Reset", buffer);
		//send(stream, "NR", "Network Reset", buffer);
		//send(stream, "SI", "Sleep Immediately", buffer);
		//send(stream, "CB", "Commissioning Pushbutton", buffer);
		//send(stream, "&X", "Clear Binding and Group Tables", buffer);
		//send(stream, "ND", "Node Discovery", buffer);
		//send(stream, "DN", "Destination Node", buffer);
		//send(stream, "DJ", "Disable Joining", buffer);
		//send(stream, "IS", "Force Sample", buffer);

		send(stream, "CN", "Exit Command mode", buffer);

		delete buffer;
		stream.setTimeout(timeout);
	}

private:
	char* send(Stream& stream, char* command, char* message, char* buffer) {
		stream.write("AT");
		stream.write(command);
		stream.write('\r');
		readCommand(stream, buffer);
		LOG(message, ": ", buffer);
		return buffer;
	}

	bool readCommand(Stream& stream, char * buffer) {
		int read = stream.readBytesUntil('\r', buffer, BUFFER_LENGTH - 1);
		buffer[read] = 0;
		return read > 0;
	}
};

