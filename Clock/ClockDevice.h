#pragma once

#include "ZigBeeHomeAutomation.h"
#include <ThreeWire.h>
#include <RtcDS1302.h>

class ClockDevice {
	RtcDS1302<ThreeWire> _rtc;
	uint8_t _dataPin;
	uint8_t _latchPin;
	uint8_t _clockPin;
	uint8_t _outputEnablePin;
	uint8_t _level;
	bool _on;
	time_t _nextUpdate;
	time_t _nextRequestTimeUpdate;
	CallbackArgs<bool> _onOffChanged;
	CallbackArgs<uint8_t> _levelChanged;
	Callback _requestTimeUpdate;

public:
	ClockDevice(uint8_t dataPin, uint8_t latchPin, uint8_t clockPin, uint8_t outputEnablePin, ThreeWire& rtcWires);

	void begin();

	void update();

	void setDateTime(const DateTime& dateTime);

	uint8_t getLevel() { return _level; }
	void setLevel(uint8_t level, time_t transitionTime);

	bool isOn() { return _on; }
	void setOn(bool on);

	void onOnOffChanged(CallbackArgs<bool>::Func func, uintptr_t data = 0) {
		_onOffChanged.set(func, data);
	}
	void onLevelChanged(CallbackArgs<uint8_t>::Func func, uintptr_t data = 0) {
		_levelChanged.set(func, data);
	}
	void onRequestTimeUpdate(Callback::Func func, uintptr_t data = 0) {
		_requestTimeUpdate.set(func, data);
	}

private:
	void calculateNextRequestTimeUpdate();
	static uint8_t getDigit(uint8_t digit);
};
