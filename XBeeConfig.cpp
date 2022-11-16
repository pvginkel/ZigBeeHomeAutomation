#include "XBeeConfig.h"

#define VALUE(n, c1, c2, ...) \
	static constexpr uint8_t n[] = { c1, c2 }; \
	static constexpr uint8_t n##Value[] = { __VA_ARGS__ }

#define ADD(n) \
	commands.add(AtCommandRequest((uint8_t*)n, (uint8_t*)n##Value, ARRAY_LENGTH(n##Value)))

VALUE(restoreDefaults, 'R', 'E');
VALUE(apiOptions, 'A', 'O', 3);
VALUE(networkReset, 'N', 'R', 0);
VALUE(nodeIdentifier, 'N', 'I', 'T', 'E', 'S', 'T', ' ', 'L', 'A', 'M', 'P');
VALUE(zigbeeStackProfile, 'Z', 'S', 2);
VALUE(nodeJoinTime, 'N', 'J', 0x5A);
VALUE(encryptionEnable, 'E', 'E', 1);
VALUE(encryptionOptions, 'E', 'O', 1);
VALUE(linkKey, 'K', 'Y', 0x5A, 0x69, 0x67, 0x42, 0x65, 0x65, 0x41, 0x6C, 0x6C, 0x69, 0x61, 0x6E, 0x63, 0x65, 0x30, 0x39);
VALUE(dio6Rts, 'D', '6', 0);
VALUE(scanChannels, 'S', 'C', 0xff, 0xff);
VALUE(write, 'W', 'R');
VALUE(softwareReset, 'F', 'R');
VALUE(serialNumberHigh, 'S', 'H');
VALUE(serialNumberLow, 'S', 'L');
VALUE(networkAddress, 'M', 'Y');

void buildResetCommands(LinkedList<AtCommandRequest>& commands) {
	ADD(restoreDefaults);
	ADD(apiOptions);
	ADD(networkReset);
	ADD(nodeIdentifier);
	ADD(zigbeeStackProfile);
	ADD(nodeJoinTime);
	ADD(encryptionEnable);
	ADD(encryptionOptions);
	ADD(linkKey);
	ADD(dio6Rts);
	ADD(scanChannels);
	ADD(write);
	ADD(softwareReset);
}

void buildRetrieveConfigurationCommands(LinkedList<AtCommandRequest>& commands) {
	ADD(serialNumberHigh);
	ADD(serialNumberLow);
	ADD(networkAddress);
}
