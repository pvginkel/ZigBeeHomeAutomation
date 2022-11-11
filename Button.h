#pragma once

#include "arduino.h"
#include <SoftwareSerial.h>
#include "support.h"

class Button
{
private:
	static const int DEBOUNCE = 50;

	int _pin;
	int _state;
	bool _clickedRaised;
	time_t _lastStateChange;

public:
	Button(int pin) : _pin(pin) { }

	bool isState(int state) {
		int currentMillis = millis();
		int newState = digitalRead(_pin);
		if (newState != _state) {
			_lastStateChange = currentMillis;
			_state = newState;
		}

		if (currentMillis - _lastStateChange > DEBOUNCE) {
			return state == _state;
		}
		return false;
	}

	bool clicked() {
		if (isState(HIGH)) {
			if (!_clickedRaised) {
				_clickedRaised = true;
				return true;
			}
		}
		else {
			_clickedRaised = false;
		}
		return false;
	}
};
