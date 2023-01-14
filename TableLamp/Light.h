#pragma once

template <class InterpolateAlgorithm>
class Light {
	CallbackArgs<float> _levelChanged;

	int _pin;
	float _level;
	float _actualLevel;
	float _startLevel;
	float _minimumLevel;
	float _maximumLevel;
	time_t _transitionStart;
	time_t _transitionTime;

public:
	Light(float minimumLevel, float maximumLevel)
		: _pin(-1), _level(0), _actualLevel(0), _startLevel(0), _minimumLevel(minimumLevel),
		_maximumLevel(maximumLevel), _transitionStart(0), _transitionTime(0) {
	}

	void begin(uint8_t pin) {
		_pin = pin;

		pinMode(pin, OUTPUT);

		resetTransition();
	}

	bool isOn() {
		return _level > 0;
	}
	float getLevel() {
		return _level;
	}
	void onLevelChanged(CallbackArgs<float>::Func func, uintptr_t data = 0) {
		_levelChanged.set(func, data);
	}

	void update() {
		if (_pin == -1 || !_transitionStart) {
			return;
		}

		auto diff = millis() - _transitionStart;

		if (diff >= _transitionTime) {
			resetTransition();
		}
		else {
			// Interpolate the level.

			float progress = float(diff) / float(_transitionTime);

			float level =
				_startLevel +
				(getScaledLevel() - _startLevel) * progress;

			_actualLevel = level;
			analogWrite(uint8_t(_pin), interpolate(_actualLevel));
		}
	}

	void setLevel(float level, time_t time = 0) {
		if (level < 0.0f) {
			level = 0.0f;
		}
		if (level > 1.0f) {
			level = 1.0f;
		}

		_level = level;

		if (time == 0) {
			resetTransition();
		}
		else {
			_startLevel = _actualLevel;
			_transitionStart = millis();
			_transitionTime = time;

			// Let update handle setting the value.
		}

		_levelChanged.call(_level);
	}

	void resetTransition() {
		auto scaledLevel = getScaledLevel();

		_startLevel = scaledLevel;
		_transitionStart = 0;
		_transitionTime = 0;

		_actualLevel = scaledLevel;
		analogWrite(_pin, interpolate(_actualLevel));
	}

private:
	float getScaledLevel() {
		if (_level > 0 && (_minimumLevel != 0.0f || _maximumLevel != 1.0f)) {
			return
				_minimumLevel +
				_level * (_maximumLevel - _minimumLevel);
		}

		return _level;
	}

	static uint8_t interpolate(float level) {
		const auto result = int(InterpolateAlgorithm::interpolate(level) * 256.0f);
			
		if (result < 0) {
			return 0;
		}
		if (result > 255) {
			return 255;
		}
		return uint8_t(result);
	}
};


class LinearInterpolateAlgorithm {
public:
	static float interpolate(float level) {
		return level;
	}
};

class CIE1931InterpolateAlgorithm {
public:
	static float interpolate(float level) {
		/*
		   For CIE, the following formulas have  Y as luminance, and
		   Yn is the luminance of a white reference (basically, max luminance).
		   This assumes a perceived lightness value L* between 0 and 100,
		   and  a luminance value Y of 0-1.0.
		   if L* > 8:  Y = ((L* + 16) / 116)^3 * Yn
		   if L* <= 8: Y = L* *903.3 * Yn
		 */

		float l = level * 100.0f;
		float Y;
		if (l <= 8.0f) {
			Y = (l / 903.3f);
		}
		else {
			float foo = (l + 16.0f) / 116.0f;
			Y = powf(foo, 3);
		}

		return Y;
	}
};

typedef Light<LinearInterpolateAlgorithm> LinearLight;
typedef Light<CIE1931InterpolateAlgorithm> NaturalLight;