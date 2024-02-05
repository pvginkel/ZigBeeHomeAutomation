#pragma once

#include "Support.h"

class Remote
{
	static constexpr int POT_PIN_MIN = 0;
	static constexpr int POT_PIN_MAX = 1023;
	static constexpr int POT_MIN_MS = 0;
	static constexpr int POT_MAX_MS = 1000;

	uint8_t _button1Pin;
	uint8_t _button2Pin;
	uint8_t _button3Pin;
	uint8_t _button4Pin;
	uint8_t _button5Pin;
	uint8_t _potPin;
	uint8_t _nextReleasePin;
	time_t _nextRelease;

public:
	Remote(uint8_t button1Pin, uint8_t button2Pin, uint8_t button3Pin, uint8_t button4Pin, uint8_t button5Pin, uint8_t potPin);

	void begin() const;
	void update();
	void pressBattery();
	void pressOff();
	void pressBrightness1();
	void pressBrightness2();
	void pressBrightness3();

private:
	void press(uint8_t pin);
	static void setOn(uint8_t pin);
	static void setOff(uint8_t pin);
	int getPressDuration() const;
};
