#pragma once

#include "arduino.h"
#include <XBee.h>
#include <LinkedList.h>
#include "support.h"

typedef AtCommandRequest(*command_builder_t)(int);

#define AT_BUILDER(n, c, ...) \
	AtCommandRequest n() { \
		static uint8_t value[] = { __VA_ARGS__ }; \
		return AtCommandRequest((uint8_t*)c, (uint8_t*)value, ARRAY_LENGTH(value)); \
	}

#define AT_BUILDER_STR(n, c, v) \
	AtCommandRequest n() { \
		return AtCommandRequest((uint8_t*)c, (uint8_t*)v, strlen(v)); \
	}

AtCommandRequest buildResetCommand(int index);
AtCommandRequest buildRetrieveConfigurationCommand(int index);
