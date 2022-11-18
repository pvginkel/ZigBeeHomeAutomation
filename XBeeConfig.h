#pragma once

#include "arduino.h"
#include <XBee.h>
#include <LinkedList.h>
#include "support.h"

typedef AtCommandRequest(*command_builder_t)(int);

#define AT_BUILDER(n, c, ...) \
	static AtCommandRequest n() { \
		static uint8_t value[] = { __VA_ARGS__ }; \
		return AtCommandRequest((uint8_t*)c, (uint8_t*)value, ARRAY_LENGTH(value)); \
	}

#define AT_BUILDER_STR(n, c, v) \
	static AtCommandRequest n() { \
		return AtCommandRequest((uint8_t*)c, (uint8_t*)v, strlen(v)); \
	}

AtCommandRequest buildResetCommand(int index);
AtCommandRequest buildRetrieveConfigurationCommand(int index);
AtCommandRequest buildReadDiagnosticsCommand(int index);
