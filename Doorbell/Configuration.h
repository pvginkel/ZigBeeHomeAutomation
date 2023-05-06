#pragma once

#include <EEPROM.h>

class Configuration {
	static constexpr uint8_t CRC_MAGIC = 0x64;

	static constexpr int INITIALIZED_OFFSET = 0;
	static constexpr int DOORBELL_ENABLED = INITIALIZED_OFFSET + 1;
	static constexpr int CRC_OFFSET = DOORBELL_ENABLED + 2;

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

	bool getDoorbellEnabled() {
		uint8_t value;
		EEPROM.get(DOORBELL_ENABLED, value);
		return value;
	}
	void setDoorbellEnabled(bool value) {
		EEPROM.put(DOORBELL_ENABLED, uint8_t(value));
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
