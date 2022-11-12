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
		LOG("ATID Extended PAN ID: ", send("ID"));
		LOG("ATSC Scan Channels: ", send("SC"));
		LOG("ATSD Scan Duration: ", send("SD"));
		LOG("ATZS Zigbee Stack Profile: ", send("ZS"));
		LOG("ATNJ Node Join Time: ", send("NJ"));
		LOG("ATNW Network Watchdog Timeout: ", send("NW"));
		LOG("ATJV Coordinator Join Verification: ", send("JV"));
		LOG("ATJN Join Notification: ", send("JN"));
		LOG("ATOP Operating Extended PAN ID: ", send("OP"));
		LOG("ATOI Operating 16-bit PAN ID: ", send("OI"));
		LOG("ATCH Operating Channel: ", send("CH"));
		LOG("ATNC Number of Remaining Children: ", send("NC"));
		LOG("ATCE Coordinator Enable: ", send("CE"));
		LOG("ATDO Miscellaneous Device Options: ", send("DO"));
		LOG("ATDC Joining Device Controls: ", send("DC"));
		LOG("ATII Initial 16-bit PAN ID: ", send("II"));
		LOG("ATED Energy Detect: ", send("ED"));
		LOG("ATSH Serial Number High: ", send("SH"));
		LOG("ATSL Serial Number Low: ", send("SL"));
		LOG("ATMY 16-bit Network Address: ", send("MY"));
		LOG("ATMP 16-bit Parent Network Address: ", send("MP"));
		LOG("ATDH Destination Address High: ", send("DH"));
		LOG("ATDL Destination Address Low: ", send("DL"));
		LOG("ATNI Node Identifier: ", send("NI"));
		LOG("ATNH Maximum Unicast Hops: ", send("NH"));
		LOG("ATBH Broadcast Hops: ", send("BH"));
		LOG("ATAR Aggregate Routing Notification: ", send("AR"));
		LOG("ATDD Device Type Identifier: ", send("DD"));
		LOG("ATNT Node Discover Timeout: ", send("NT"));
		LOG("ATNO Network Discovery Options: ", send("NO"));
		LOG("ATNP Maximum Packet Payload Bytes: ", send("NP"));
		LOG("ATCR Conflict Report: ", send("CR"));
		LOG("ATSE Source Endpoint: ", send("SE"));
		LOG("ATDE Destination Endpoint: ", send("DE"));
		LOG("ATCI Cluster ID: ", send("CI"));
		LOG("ATTO Transmit Options: ", send("TO"));
		LOG("ATPL TX Power Level: ", send("PL"));
		LOG("ATPP Power at PL4: ", send("PP"));
		LOG("ATPM Power Mode: ", send("PM"));
		LOG("ATEE Encryption Enable: ", send("EE"));
		LOG("ATEO Encryption Options: ", send("EO"));
		LOG("ATKY Link Key: ", send("KY"));
		LOG("ATNK Trust Center Network Key: ", send("NK"));
		LOG("ATBD Interface Data Rate: ", send("BD"));
		LOG("ATNB Parity: ", send("NB"));
		LOG("ATSB Stop Bits: ", send("SB"));
		LOG("ATRO Packetization Timeout: ", send("RO"));
		LOG("ATD6 DIO6/RTS: ", send("D6"));
		LOG("ATD7 DIO7/CTS: ", send("D7"));
		LOG("ATAP API Enable: ", send("AP"));
		LOG("ATAO API Options: ", send("AO"));
		LOG("ATCT Command Mode Timeout: ", send("CT"));
		LOG("ATGT Guard Times: ", send("GT"));
		LOG("ATCC Command Character: ", send("CC"));
		LOG("ATSP Sleep Period: ", send("SP"));
		LOG("ATSN Number of Cycles Between ON_SLEEP: ", send("SN"));
		LOG("ATSM Sleep Mode: ", send("SM"));
		LOG("ATST Time before Sleep: ", send("ST"));
		LOG("ATSO Sleep Options: ", send("SO"));
		LOG("ATWH Wake Host Delay: ", send("WH"));
		LOG("ATPO Polling Rate: ", send("PO"));
		LOG("ATD0 AD0/DIO0 Configuration: ", send("D0"));
		LOG("ATD1 AD1/DIO1/PTI_En Configuration: ", send("D1"));
		LOG("ATD2 AD2/DIO2 Configuration: ", send("D2"));
		LOG("ATD3 AD3/DIO3 Configuration: ", send("D3"));
		LOG("ATD4 DIO4 Configuration: ", send("D4"));
		LOG("ATD5 DIO5/Associate Configuration: ", send("D5"));
		LOG("ATD8 DIO8/DTR/SLP_RQ: ", send("D8"));
		LOG("ATD9 DIO9/ON_SLEEP: ", send("D9"));
		LOG("ATP0 RSSI/PWM0 Configuration: ", send("P0"));
		LOG("ATP1 DIO11/PWM1 Configuration: ", send("P1"));
		LOG("ATP2 DIO12 Configuration: ", send("P2"));
		LOG("ATP3 DIO13/DOUT Configuration: ", send("P3"));
		LOG("ATP4 DIO14/DIN: ", send("P4"));
		LOG("ATP5 DIO15/SPI_MISO: ", send("P5"));
		LOG("ATP6 SPI_MOSI Configuration: ", send("P6"));
		LOG("ATP7 DIO17/SPI_SSEL: ", send("P7"));
		LOG("ATP8 DIO18/SPI_SCLK: ", send("P8"));
		LOG("ATP9 DIO19/SPI_ATTN/PTI_DATA: ", send("P9"));
		LOG("ATPR Pull-up/Down Resistor Enable: ", send("PR"));
		LOG("ATPD Pull Up/Down Direction: ", send("PD"));
		LOG("ATLT Associate LED Blink Time: ", send("LT"));
		LOG("ATRP RSSI PWM Timer: ", send("RP"));
		LOG("ATIR I/O Sample Rate: ", send("IR"));
		LOG("ATIC Digital Change Detection: ", send("IC"));
		LOG("ATV+ Voltage Supply Monitoring: ", send("V+"));
		LOG("ATVR Firmware Version: ", send("VR"));
		LOG("ATHV Hardware Version: ", send("HV"));
		LOG("ATAI Association Indication: ", send("AI"));
		LOG("AT%V Voltage Supply Monitoring: ", send("%V"));
		LOG("ATDB Received Signal Strength: ", send("DB"));
		LOG("ATTP Temperature: ", send("TP"));
		LOG("ATVL Version Long: ", send("VL"));

		//LOG("ATAC Apply Changes: ", send("AC"));
		//LOG("ATAS Active Scan: ", send("AS"));
		//LOG("ATWR Write: ", send("WR"));
		//LOG("ATRE Restore Defaults: ", send("RE"));
		//LOG("ATFR Software Reset: ", send("FR"));
		//LOG("ATNR Network Reset: ", send("NR"));
		//LOG("ATSI Sleep Immediately: ", send("SI"));
		//LOG("ATCB Commissioning Pushbutton: ", send("CB"));
		//LOG("AT&X Clear Binding and Group Tables: ", send("&X"));
		//LOG("ATND Node Discovery: ", send("ND"));
		//LOG("ATDN Destination Node: ", send("DN"));
		//LOG("ATDJ Disable Joining: ", send("DJ"));
		//LOG("ATIS Force Sample: ", send("IS"));
	}

	void exitConfig() {
		LOG("ATCN Exit Command mode: ", send("CN"));

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

