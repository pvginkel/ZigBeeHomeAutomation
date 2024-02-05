#include "Arduino.h"
#include "Support.h"
#include "Remote.h"

Remote::Remote(uint8_t button1Pin, uint8_t button2Pin, uint8_t button3Pin, uint8_t button4Pin, uint8_t button5Pin, uint8_t potPin)
	: _button1Pin(button1Pin), _button2Pin(button2Pin), _button3Pin(button3Pin), _button4Pin(button4Pin), _button5Pin(button5Pin), _potPin(potPin),
	_nextReleasePin(0), _nextRelease(0) {

}

void Remote::begin() const {
	setOff(_button1Pin);
	setOff(_button2Pin);
	setOff(_button3Pin);
	setOff(_button4Pin);
	setOff(_button5Pin);

	pinMode(_potPin, INPUT);
}

void Remote::update() {
	if (_nextRelease) {
		const auto currentMillis = millis();

		if (_nextRelease < currentMillis) {
			setOff(_nextReleasePin);

			_nextRelease = 0;
			_nextReleasePin = 0;
		}
	}
}

void Remote::pressBattery() { 
	INFO(F("Press battery button"));
	press(_button5Pin);
}

void Remote::pressOff() {
	INFO(F("Press off button"));
	press(_button4Pin);
}

void Remote::pressBrightness1() {
	INFO(F("Press brightness 1 button"));
	press(_button3Pin);
}

void Remote::pressBrightness2() {
	INFO(F("Press brightness 2 button"));
	press(_button2Pin);
}

void Remote::pressBrightness3() {
	INFO(F("Press brightness 3 button"));
	press(_button1Pin);
}

void Remote::press(uint8_t pin) {
	if (_nextRelease) {
		setOff(_nextReleasePin);
	}

	setOn(pin);

	_nextRelease = millis() + getPressDuration();
	_nextReleasePin = pin;
}

void Remote::setOn(uint8_t pin) {
	// From https://electronics.stackexchange.com/questions/36981.

	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
}

void Remote::setOff(uint8_t pin) {
	// From https://electronics.stackexchange.com/questions/36981.

	pinMode(pin, INPUT);
}

int Remote::getPressDuration() const {
	const int potValue = analogRead(_potPin);

	if (potValue <= POT_PIN_MIN) {
		return POT_MIN_MS;
	}
	if (potValue >= POT_PIN_MAX) {
		return POT_MAX_MS;
	}

	const auto offset = float(potValue - POT_PIN_MIN) / float(POT_PIN_MAX - POT_PIN_MIN);
	const auto ms = POT_MIN_MS + int(offset * (POT_MAX_MS - POT_MIN_MS));

	INFO(F("Button press duration "), ms, F(" ms"));

	return ms;
}
