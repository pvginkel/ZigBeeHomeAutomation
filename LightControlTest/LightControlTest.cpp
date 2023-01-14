#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstdarg>

#include "CppUnitTest.h"

#include <inttypes.h>

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void pinMode(uint8_t pin, uint8_t mode) {
	// Ignore.
}

uint8_t pinValues[256] = {};

void analogWrite(uint8_t pin, uint8_t value) {
	pinValues[pin] = value;
}

time_t testMillis = 0;

time_t millis() {
	return testMillis;
}

#include "../ZigBeeHomeAutomation/src/Callback.h"
#include "../TableLamp/DualTemperatureLight.h"

void Log(char* msg, ...) {
	static char buffer[256];

	va_list argp;
	va_start(argp, msg);

	vsprintf(buffer, msg, argp);

	Logger::WriteMessage(buffer);

	va_end(argp);
}

TEST_CLASS(LightControlTest) {
public:
	TEST_METHOD_INITIALIZE(beforeTest) {
		// Set to a non zero value to make sure that the lights
		// think we're running.
		testMillis = 7;
	}

	TEST_METHOD(simpleLevel) {
		NaturalLight light(0, 1);
		light.begin(0);

		for (float i = 0.0f; i <= 1.0f; i += 0.01f) {
			if (i > 0.99f) {
				i = 1.0f;
			}

			light.setLevel(i);
			light.update();

			Log("%d\n", pinValues[0]);
		}
	}

	TEST_METHOD(fadeToLevel) {
		NaturalLight light(0, 1);
		light.begin(0);

		light.setLevel(1.0f, 1000);

		for (int i = 0; i < 100; i++) {
			testMillis += 10;
			light.update();

			Log("%d\n", pinValues[0]);
		}
	}

	TEST_METHOD(temperatureRange) {
		const int minTemp = 270;
		const int maxTemp = 650;

		NaturalTemperatureLight light(0, 1, minTemp, maxTemp);

		light.begin(0, 1);
		light.setLevel(1);

		for (int i = minTemp; i <= maxTemp; i += 10) {
			light.setTemperature(i);
			light.update();

			Log("%d\t%d\n", pinValues[0], pinValues[1]);
		}
	}

	TEST_METHOD(simpleLevelWithTemperature) {
		const int minTemp = 270;
		const int maxTemp = 650;

		NaturalTemperatureLight light(0, 1, minTemp, maxTemp);

		light.begin(0, 1);
		light.setTemperature((maxTemp + minTemp) / 2);

		for (float i = 0.0f; i <= 1.0f; i += 0.01f) {
			if (i > 0.99f) {
				i = 1.0f;
			}

			light.setLevel(i);
			light.update();

			Log("%d\t%d\n", pinValues[0], pinValues[1]);
		}
	}

	TEST_METHOD(simpleLevelWith25PercentTemperature) {
		const int minTemp = 270;
		const int maxTemp = 650;

		NaturalTemperatureLight light(0, 1, minTemp, maxTemp);

		light.begin(0, 1);
		light.setTemperature(minTemp + (maxTemp - minTemp) / 4);

		for (float i = 0.0f; i <= 1.0f; i += 0.01f) {
			if (i > 0.99f) {
				i = 1.0f;
			}

			light.setLevel(i);
			light.update();

			Log("%d\t%d\n", pinValues[0], pinValues[1]);
		}
	}
};
