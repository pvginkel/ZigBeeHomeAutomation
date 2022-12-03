#include "ZigBee.h"

void StatusControl::setLed(int pin) {
	_led = pin;

	pinMode(pin, OUTPUT);
}

void StatusControl::setBounce(Bounce bounce) {
	_bounce = bounce;
}

void StatusControl::setConnected(ConnectionStatus connected) {
	if (_connected != connected) {
		_lastStatusChange = millis();
		_connected = connected;
	}
}

void StatusControl::reportRemaining(int remaining) {
	if (_remainingReported != remaining) {
		_remainingReported = remaining;
		_resetCountdown.call(remaining);

		if (remaining > 0) {
			INFO(F("Resetting in "), remaining);
		}
		else if (remaining == 0) {
			INFO(F("Resetting NOW"));
		}
	}
}

void StatusControl::update() {
	_bounce.update();

	auto currentMillis = millis();

	if (_bounce.read()) {
		if (!_isHigh) {
			_lastStatusChange = currentMillis;
			_isHigh = true;
			_click.call();
			digitalWrite(_led, HIGH);
		}
		if (_bounce.currentDuration() > _initialDelay) {
			auto duration = _bounce.currentDuration() - _initialDelay;
			auto steps = duration / _stepTime;
			int remaining = _steps - (int)steps;

			if (remaining <= 0) {
				if (!_resetRaised) {
					_resetRaised = true;

					if (_led >= 0) {
						digitalWrite(_led, LOW);
					}

					reportRemaining(remaining);

					_reset.call();
				}
			}
			else {
				reportRemaining(remaining);
			}
		}
	}
	else if (_isHigh) {
		_isHigh = false;
		_resetRaised = false;
		_lastStatusChange = currentMillis;
		reportRemaining(-1);
		if (_led >= 0) {
			digitalWrite(_led, LOW);
		}
	}

	if (_led >= 0) {
		// Blink progressively shorter while the button is down and the
		// reset hasn't been raised.

		if (_isHigh && !_resetRaised) {
			// The algorithm is to wait for 20% of the time until the
			// the reset will be raised to toggle the led.

			auto total = _initialDelay + _steps * _stepTime;
			auto target = currentMillis - _bounce.currentDuration() + total;
			auto remaining = target - _lastStatusChange;
			auto nextToggle = max((remaining * 10) / 100, 25);
			auto progress = currentMillis - _lastStatusChange;

			if (progress >= nextToggle) {
				_lastStatusChange = currentMillis;
				digitalWrite(_led, !digitalRead(_led));
			}
		}
		else if (_connected == ConnectionStatus::Connecting) {
			// Fade the led in and out while we're connecting.

			auto duration = currentMillis - _lastStatusChange;
			auto progress = duration % _fadePeriod;
			bool inverse = (duration / _fadePeriod) % 2 == 0;
			auto level = progress * 255 / _fadePeriod;

			if (inverse) {
				level = 255 - level;
			}
			analogWrite(_led, level);
		}
		else {
			digitalWrite(_led, LOW);
		}
	}
}
