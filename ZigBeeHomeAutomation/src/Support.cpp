#include "ZigBeeHomeAutomation.h"

#ifdef __arm__
// should use uinstd.h to define sbrk but Due causes a conflict
extern "C" char* sbrk(int incr);
#else  // __ARM__
extern char* __brkval;
#endif  // __arm__

int freeMemory() {
	char top;
#ifdef __arm__
	return &top - reinterpret_cast<char*>(sbrk(0));
#elif defined(CORE_TEENSY) || (ARDUINO > 103 && ARDUINO != 151)
	return &top - __brkval;
#else  // __arm__
	return __brkval ? &top - __brkval : &top - __malloc_heap_start;
#endif  // __arm__
}

void fillMemory() {
	char top;
	char* p = &top - 2; // Make a little bit of space for the current function.
	while (p >= __brkval) {
		*p-- = 0x55;
	}
}

uint16_t checkMemory() {
	char top;
	char* p = __brkval;
	while (p < &top) {
		if (*p != 0x55) {
			return &top - p;
		}
		p++;
	}

	return 0;
}