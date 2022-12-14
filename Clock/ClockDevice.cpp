#include "ClockDevice.h"

ClockDevice::ClockDevice(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin, uint8_t outputEnablePin, ThreeWire& rtcWires)
	: _rtc(rtcWires), _dataPin(dataPin), _latchPin(latchPin), _clockPin(clockPin), _outputEnablePin(outputEnablePin),
	_level(0), _on(false), _nextUpdate(0), _nextRequestTimeUpdate(0) {
	pinMode(_dataPin, OUTPUT);
	pinMode(_latchPin, OUTPUT);
	pinMode(_clockPin, OUTPUT);
	pinMode(_outputEnablePin, OUTPUT);
}

void ClockDevice::begin() {
	_rtc.Begin();

	_rtc.SetIsRunning(true);
	_rtc.SetIsWriteProtected(false);
}

void ClockDevice::update() {
	auto currentMillis = millis();

	if (currentMillis >= _nextRequestTimeUpdate) {
		calculateNextRequestTimeUpdate();

		_requestTimeUpdate.call();
	}

	if (_nextUpdate != 0 && _nextUpdate <= currentMillis) {
		return;
	}

	// 10 means we don't print any digit.

	uint8_t hoursHigh = 10;
	uint8_t hoursLow = 10;
	uint8_t minutesHigh = 10;
	uint8_t minutesLow = 10;

	if (_on) {
		auto dateTime = _rtc.GetDateTime();

		hoursHigh = dateTime.Hour() / 10;
		hoursLow = dateTime.Hour() % 10;
		minutesHigh = dateTime.Minute() / 10;
		minutesLow = dateTime.Minute() % 10;

		int seconds = dateTime.Second();

		_nextUpdate = currentMillis + time_t(60 - seconds) * 1000ul;
	}
	else {
		// Disable updates.
		_nextUpdate = 0xffffffff;
	}

	digitalWrite(_clockPin, LOW);
	digitalWrite(_latchPin, LOW);

	shiftOut(_dataPin, _clockPin, MSBFIRST, minutesLow);
	shiftOut(_dataPin, _clockPin, MSBFIRST, minutesHigh);
	shiftOut(_dataPin, _clockPin, MSBFIRST, hoursLow);
	shiftOut(_dataPin, _clockPin, MSBFIRST, hoursHigh);

	digitalWrite(_latchPin, HIGH);
}

void ClockDevice::setDateTime(const DateTime& dateTime) {
	DEBUG(
		F("Setting date/time to "),
		dateTime.getYear(), F("-"), dateTime.getMonth(), F("-"), dateTime.getDay(),
		F(" "),
		dateTime.getHours(), F(":"), dateTime.getMinutes(), F(":"), dateTime.getSeconds(), F("."), dateTime.getMilliseconds()
	);

	RtcDateTime rtcDateTime(
		dateTime.getYear(),
		dateTime.getMonth(),
		dateTime.getDay(),
		dateTime.getHours(),
		dateTime.getMinutes(),
		dateTime.getSeconds()
	);

	_rtc.SetDateTime(rtcDateTime);

	calculateNextRequestTimeUpdate();

	_nextUpdate = 0;
}

void ClockDevice::setLevel(uint8_t level, time_t transitionTime) {
	if (level != _level) {
		_level = level;

		analogWrite(_outputEnablePin, 255 - level);

		_levelChanged.call(level);
	}
}

void ClockDevice::setOn(bool on) {
	if (on != _on) {
		_on = on;

		_nextUpdate = 0;

		_onOffChanged.call(on);
	}
}

void ClockDevice::calculateNextRequestTimeUpdate() {
	// Time updates are requested at 4 AM. The idea is that this is well after
	// DST changes, so we'll get the right time.

	auto dateTime = _rtc.GetDateTime();

	auto secondsAfterMidnight =
		uint32_t(dateTime.Hour()) * 3600ul +
		uint32_t(dateTime.Minute()) * 60ul +
		uint32_t(dateTime.Second());

	constexpr uint32_t secondsInDay = 24ul * 3600ul;

	auto diff = ((secondsInDay + 4ul * 3600ul) - secondsAfterMidnight) % secondsInDay;
	if (diff == 0) {
		diff = secondsInDay;
	}

	DEBUG(F("Requesting next time update in "), diff, F("s"));

	_nextRequestTimeUpdate = diff * 1000ul;
}

#define BUILD_DIGIT(_x1, _1, _x2, _6, _x3, _2, _x4, _7, _x5, _5, _x6, _3, _x7, _4, _x8) \
( \
	(!!(_1) << 0) | \
	(!!(_2) << 1) | \
	(!!(_3) << 2) | \
	(!!(_4) << 3) | \
	(!!(_5) << 4) | \
	(!!(_6) << 5) | \
	(!!(_7) << 6) \
)

uint8_t ClockDevice::getDigit(uint8_t digit) {
	switch (digit) {
	case 0:
		return BUILD_DIGIT(
			, 1, ,
			1, , 1,
			, 0, ,
			1, , 1,
			, 1,
			);
	case 1:
		return BUILD_DIGIT(
			, 0, ,
			0, , 1,
			, 0, ,
			0, , 1,
			, 0,
			);
	case 2:
		return BUILD_DIGIT(
			, 1, ,
			0, , 1,
			, 1, ,
			1, , 0,
			, 1,
			);
	case 3:
		return BUILD_DIGIT(
			, 1, ,
			0, , 1,
			, 1, ,
			0, , 1,
			, 1,
			);
	case 4:
		return BUILD_DIGIT(
			, 0, ,
			1, , 1,
			, 1, ,
			0, , 1,
			, 0,
			);
	case 5:
		return BUILD_DIGIT(
			, 1, ,
			1, , 0,
			, 1, ,
			0, , 1,
			, 1,
			);
	case 6:
		return BUILD_DIGIT(
			, 1, ,
			1, , 0,
			, 1, ,
			1, , 1,
			, 1,
			);
	case 7:
		return BUILD_DIGIT(
			, 1, ,
			0, , 1,
			, 0, ,
			0, , 1,
			, 0,
			);
	case 8:
		return BUILD_DIGIT(
			, 1, ,
			1, , 1,
			, 1, ,
			1, , 1,
			, 1,
			);
	case 9:
		return BUILD_DIGIT(
			, 1, ,
			1, , 1,
			, 1, ,
			0, , 1,
			, 1,
			);
	default:
		return 0;
	}
}
