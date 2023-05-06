#pragma once

class Doorbell {
	Bounce _button;
	uint8_t _relayPin;
	bool _enabled;
	bool _ringing;
	Callback _ring;

public:
	Doorbell(Bounce button, uint8_t relayPin) : _button(button), _relayPin(relayPin), _enabled(false), _ringing(false) {
		pinMode(relayPin, OUTPUT);
		digitalWrite(relayPin, false);
	}

	void setEnabled(bool enabled) {
		_enabled = enabled;
	}

	void update() {
		_button.update();

		if (_button.read()) {
			if (!_ringing && _enabled) {
				_ringing = true;

				digitalWrite(_relayPin, 1);

				_ring.call();
			}
		}
		else {
			if (_ringing) {
				_ringing = false;

				digitalWrite(_relayPin, 0);
			}
		}
	}

	void onRing(Callback::Func func, uintptr_t data = 0) {
		_ring.set(func, data);
	}
};
