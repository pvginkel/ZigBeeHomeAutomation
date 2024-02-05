#include "HumbleLight.h"

HumbleLight::HumbleLight(Remote remote): _remote(remote), _level(0) {
}

void HumbleLight::begin() const {
	_remote.begin();
}

void HumbleLight::update() {
	_remote.update();
}

bool HumbleLight::isOn() const {
	return _level > 0;
}

float HumbleLight::getLevel() const {
	return _level;
}

void HumbleLight::onLevelChanged(CallbackArgs<float>::Func func, uintptr_t data) {
	_levelChanged.set(func, data);
}

void HumbleLight::setLevel(float level) {
	if (level < 0.0f) {
		level = 0.0f;
	}
	if (level > 1.0f) {
		level = 1.0f;
	}

	_level = level;

	if (level <= 0.0f) {
		_remote.pressOff();
	}
	else if (level < BRIGHTNESS1_CUTOFF) {
		_remote.pressBrightness1();
	}
	else if (level < BRIGHTNESS2_CUTOFF) {
		_remote.pressBrightness2();
	}
	else {
		_remote.pressBrightness3();
	}

	_levelChanged.call(_level);
}
