#pragma once

#include <EEPROM.h>

class Configuration {
	static constexpr uint8_t CRC_MAGIC = 0x64;

	static constexpr int INITIALIZED_OFFSET = 0;
	static constexpr int TEMPERATURE_OFFSET = INITIALIZED_OFFSET + 1;
	static constexpr int LIGHT_MINIMUM_LEVEL = TEMPERATURE_OFFSET + 2;
	static constexpr int LIGHT_MAXIMUM_LEVEL = LIGHT_MINIMUM_LEVEL + 1;
	static constexpr int CRC_OFFSET = LIGHT_MAXIMUM_LEVEL + 2;

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

	uint8_t getLightMinimumLevel() {
		uint8_t value;
		EEPROM.get(LIGHT_MINIMUM_LEVEL, value);
		return value;
	}
	void setLightMinimumLevel(uint8_t value) {
		EEPROM.put(LIGHT_MINIMUM_LEVEL, value);
		writeCrc();
	}

	uint8_t getLightMaximumLevel() {
		uint8_t value;
		EEPROM.get(LIGHT_MAXIMUM_LEVEL, value);
		return value;
	}
	void setLightMaximumLevel(uint8_t value) {
		EEPROM.put(LIGHT_MAXIMUM_LEVEL, value);
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
