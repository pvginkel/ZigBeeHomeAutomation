#pragma once

#include <inttypes.h>

#define LOG_LEVEL_DEBUG 4
#define LOG_LEVEL_INFO 3
#define LOG_LEVEL_WARN 2
#define LOG_LEVEL_ERROR 1
#define LOG_LEVEL_NONE 0

#define LOG_LEVEL LOG_LEVEL_DEBUG

#define _LOG1(a1) Serial.println(a1); Serial.flush()
#define _LOG2(a1, a2) Serial.print(a1); Serial.println(a2); Serial.flush()
#define _LOG3(a1, a2, a3) Serial.print(a1); Serial.print(a2); Serial.println(a3); Serial.flush()
#define _LOG4(a1, a2, a3, a4) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.println(a4); Serial.flush()
#define _LOG5(a1, a2, a3, a4, a5) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.println(a5); Serial.flush()
#define _LOG6(a1, a2, a3, a4, a5, a6) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.println(a6); Serial.flush()
#define _LOG7(a1, a2, a3, a4, a5, a6, a7) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.println(a7); Serial.flush()
#define _LOG8(a1, a2, a3, a4, a5, a6, a7, a8) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.println(a8); Serial.flush()
#define _LOG9(a1, a2, a3, a4, a5, a6, a7, a8, a9) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.println(a9); Serial.flush()
#define _LOG10(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.println(a10); Serial.flush()
#define _LOG11(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.println(a11); Serial.flush()
#define _LOG12(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.println(a12); Serial.flush()
#define _LOG13(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.println(a13); Serial.flush()
#define _LOG14(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.println(a14); Serial.flush()
#define _LOG15(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.println(a15); Serial.flush()
#define _LOG16(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.println(a16); Serial.flush()
#define _LOG17(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.println(a17); Serial.flush()
#define _LOG18(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.println(a18); Serial.flush()
#define _LOG19(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.println(a19); Serial.flush()
#define _LOG20(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.println(a20); Serial.flush()
#define _LOG21(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.println(a21); Serial.flush()
#define _LOG22(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.print(a21); Serial.println(a22); Serial.flush()
#define _LOG23(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.print(a21); Serial.print(a22); Serial.println(a23); Serial.flush()
#define _LOG24(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.print(a21); Serial.print(a22); Serial.print(a23); Serial.println(a24); Serial.flush()
#define _LOG25(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.print(a21); Serial.print(a22); Serial.print(a23); Serial.print(a24); Serial.println(a25); Serial.flush()
#define _LOG26(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.print(a21); Serial.print(a22); Serial.print(a23); Serial.print(a24); Serial.print(a25); Serial.println(a26); Serial.flush()
#define _LOG27(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.print(a21); Serial.print(a22); Serial.print(a23); Serial.print(a24); Serial.print(a25); Serial.print(a26); Serial.println(a27); Serial.flush()
#define _LOG28(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.print(a21); Serial.print(a22); Serial.print(a23); Serial.print(a24); Serial.print(a25); Serial.print(a26); Serial.print(a27); Serial.println(a28); Serial.flush()
#define _LOG29(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.print(a21); Serial.print(a22); Serial.print(a23); Serial.print(a24); Serial.print(a25); Serial.print(a26); Serial.print(a27); Serial.print(a28); Serial.println(a29); Serial.flush()
#define _LOG30(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.print(a21); Serial.print(a22); Serial.print(a23); Serial.print(a24); Serial.print(a25); Serial.print(a26); Serial.print(a27); Serial.print(a28); Serial.print(a29); Serial.println(a30); Serial.flush()
#define _LOG31(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.print(a21); Serial.print(a22); Serial.print(a23); Serial.print(a24); Serial.print(a25); Serial.print(a26); Serial.print(a27); Serial.print(a28); Serial.print(a29); Serial.print(a30); Serial.println(a31); Serial.flush()
#define _LOG32(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20, a21, a22, a23, a24, a25, a26, a27, a28, a29, a30, a31, a32) Serial.print(a1); Serial.print(a2); Serial.print(a3); Serial.print(a4); Serial.print(a5); Serial.print(a6); Serial.print(a7); Serial.print(a8); Serial.print(a9); Serial.print(a10); Serial.print(a11); Serial.print(a12); Serial.print(a13); Serial.print(a14); Serial.print(a15); Serial.print(a16); Serial.print(a17); Serial.print(a18); Serial.print(a19); Serial.print(a20); Serial.print(a21); Serial.print(a22); Serial.print(a23); Serial.print(a24); Serial.print(a25); Serial.print(a26); Serial.print(a27); Serial.print(a28); Serial.print(a29); Serial.print(a30); Serial.print(a31); Serial.println(a32); Serial.flush()

#define _NUM_ARGS2(X, X64, X63, X62, X61, X60, X59, X58, X57, X56, X55, X54, X53, X52, X51, X50, X49, X48, X47, X46, X45, X44, X43, X42, X41, X40, X39, X38, X37, X36, X35, X34, X33, X32, X31, X30, X29, X28, X27, X26, X25, X24, X23, X22, X21, X20, X19, X18, X17, X16, X15, X14, X13, X12, X11, X10, X9, X8, X7, X6, X5, X4, X3, X2, X1, N, ...) N
#define _NUM_ARGS(...) _NUM_ARGS2(0, __VA_ARGS__ , 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define _LOG_N3(N, ...) _LOG ## N(__VA_ARGS__)
#define _LOG_N2(N, ...) _LOG_N3(N, __VA_ARGS__)

#if LOG_LEVEL >= LOG_LEVEL_ERROR
#define LOG_ERROR 1
#define ERROR(...) _LOG_N2(_NUM_ARGS(__VA_ARGS__), __VA_ARGS__)
#else
#define LOG_ERROR 0
#define ERROR(...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARN
#define LOG_WARN 1
#define WARN(...) _LOG_N2(_NUM_ARGS(__VA_ARGS__), __VA_ARGS__)
#else
#define LOG_WARN 0
#define WARN(...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
#define LOG_INFO 1
#define INFO(...) _LOG_N2(_NUM_ARGS(__VA_ARGS__), __VA_ARGS__)
#else
#define LOG_INFO 0
#define INFO(...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_DEBUG
#define LOG_DEBUG 1
#define DEBUG(...) _LOG_N2(_NUM_ARGS(__VA_ARGS__), __VA_ARGS__)
#else
#define LOG_DEBUG 0
#define DEBUG(...)
#endif

// Only enable serial if we're logging anything. For the Arduino Pro Micro,
// logging and serial needs to be disabled completely if running without
// a computer connected because the outgoing buffers will never empty.

#if LOG_LEVEL > LOG_LEVEL_NONE
#define LOG_BEGIN()					\
	do {							\
		Serial.begin(115200);		\
		while (!Serial);			\
		DEBUG(F("Serial ready"));	\
	} while (0)
#else
#define LOG_BEGIN()
#endif

#define ARRAY_LENGTH(array) (sizeof(array)/sizeof((array)[0]))

typedef uint32_t time_t;

int freeMemory();

//
// These two methods can be used to guess how much stack the code in
// loop() needs.
//
// fillMemory() and checkMemory() work in tandem. Call fillMemory() at the top
// of loop(), and checkMemory() at the bottom, e.g. like this:
//
//   uint16_t lastReported = 0;
//   
//   void loop() {
//       fillMemory();
//       
//       // Normal code
//   
//       auto result = checkMemory();
//       if (result != lastReported) {
//           lastReported = result;
//           Serial.print("Stack usage: ");
//           Serial.println(result);
//       }
//   }
//
// Fill memory fills all available memory with a specific pattern and
// checkMemory checks whether it's still there.
//
// This only works if nothing in loop() allocated. If something does
// allocate, it'll change the pattern near the end of the available
// memory and checkMemory will think everything is in use.
//

void fillMemory();
uint16_t checkMemory();
