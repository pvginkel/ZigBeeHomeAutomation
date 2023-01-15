#pragma once

#include <EEPROM.h>

class Configuration {
	static constexpr uint8_t CRC_MAGIC = 0x64;

	static constexpr int INITIALIZED_OFFSET = 0;
	static constexpr int TEMPERATURE_OFFSET = INITIALIZED_OFFSET + 1;
	static constexpr int CRC_OFFSET = TEMPERATURE_OFFSET + 2;

public:
	void begin() {
		EEPROM.begin();

		// Check the CRC.

		auto crc = calculateCrc();

		uint8_t actualCrc;
		EEPROM.get(CRC_OFFSET, actualCrc);

		if (crc != actualCrc) {
			DEBUG(F("EEPROM CRC does not match; clearing EEPROM"));

			for (int i = 0; i < CRC_OFFSET; i++) {
				EEPROM[i] = 0;
			}

			writeCrc();
		}
	}

	bool isInitialized() {
		uint8_t value;
		EEPROM.get(INITIALIZED_OFFSET, value);
		return value;
	}
	void setInitialized(bool initialized) {
		EEPROM.put(INITIALIZED_OFFSET, uint8_t(initialized));
		writeCrc();
	}

	uint16_t getTemperature() {
		uint16_t value;
		EEPROM.get(TEMPERATURE_OFFSET, value);
		return value;
	}
	void setTemperature(uint16_t value) {
		EEPROM.put(TEMPERATURE_OFFSET, value);
		writeCrc();
	}

private:
	void writeCrc() {
		EEPROM.put(CRC_OFFSET, calculateCrc());
	}

	uint8_t calculateCrc() {
		auto crc = CRC_MAGIC;

		for (int i = 0; i < CRC_OFFSET; i++) {
			crc ^= EEPROM[i];
		}

		return crc;
	}
};
