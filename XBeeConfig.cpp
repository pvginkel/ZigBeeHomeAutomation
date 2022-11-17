#include "XBeeConfig.h"

AT_BUILDER(restoreDefaultsCommand, "RE");
AT_BUILDER(apiOptionsCommand, "AO", 3);
AT_BUILDER(networkResetCommand, "NR", 0);
AT_BUILDER_STR(nodeIdentifierCommand, "NI", "TEST LAMP");
AT_BUILDER(zigbeeStackProfileCommand, "ZS", 2);
AT_BUILDER(nodeJoinTimeCommand, "NJ", 0x5A);
AT_BUILDER(encryptionEnableCommand, "EE", 1);
AT_BUILDER(encryptionOptionsCommand, "EO", 1);
AT_BUILDER(linkKeyCommand, "KY", 0x5A, 0x69, 0x67, 0x42, 0x65, 0x65, 0x41, 0x6C, 0x6C, 0x69, 0x61, 0x6E, 0x63, 0x65, 0x30, 0x39);
AT_BUILDER(dio6RtsCommand, "D6", 0);
AT_BUILDER(scanChannelsCommand, "SC", 0xff, 0xff);
AT_BUILDER(writeCommand, "WR");
AT_BUILDER(softwareResetCommand, "FR");
AT_BUILDER(serialNumberHighCommand, "SH");
AT_BUILDER(serialNumberLowCommand, "SL");
AT_BUILDER(networkAddressCommand, "MY");

AtCommandRequest buildResetCommand(int index) {
	switch (index) {
	case 0: return restoreDefaultsCommand();
	case 1: return apiOptionsCommand();
	case 2: return networkResetCommand();
	case 3: return nodeIdentifierCommand();
	case 4: return zigbeeStackProfileCommand();
	case 5: return nodeJoinTimeCommand();
	case 6: return encryptionEnableCommand();
	case 7: return encryptionOptionsCommand();
	case 8: return linkKeyCommand();
	case 9: return dio6RtsCommand();
	case 10: return scanChannelsCommand();
	case 11: return writeCommand();
	case 12: return softwareResetCommand();
	default: return {};
	}
}

AtCommandRequest buildRetrieveConfigurationCommand(int index) {
	switch (index) {
	case 0: return serialNumberHighCommand();
	case 1: return serialNumberLowCommand();
	case 2: return networkAddressCommand();
	default: return {};
	}
}
