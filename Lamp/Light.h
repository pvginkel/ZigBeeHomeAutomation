#pragma once

// Taken from https://blog.saikoled.com/post/43693602826/why-every-led-light-should-be-using-hsi.
//
// Function example takes H, S, I, and a pointer to the 
// returned RGB colorspace converted vector. It should
// be initialized with:
//
// int rgb[3];
//
// in the calling function. After calling hsi2rgb
// the vector rgb will contain red, green, and blue
// calculated values.

struct RGB {
	float r;
	float g;
	float b;
};

RGB hsi2rgb(float H, float S, float I);

uint16_t mired2kelvin(uint16_t mired);
uint16_t kelvin2mired(uint16_t kelvin);

float scaleLightLevel(float level, float minimumLevel, float maximumLevel);

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
	time_t _lastUpdate;
	time_t _transitionTime;

public:
	Light()
		: _pin(-1), _level(0), _actualLevel(0), _startLevel(0), _minimumLevel(0),
		_maximumLevel(1), _transitionStart(0), _lastUpdate(0), _transitionTime(0) {
	}

	void reconfigure(float minimumLevel, float maximumLevel, time_t time = 0) {
		auto level = getLevel();

		_minimumLevel = minimumLevel;
		_maximumLevel = maximumLevel;

		setLevel(level, time);
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

		auto currentMillis = millis();
		auto diff = currentMillis - _transitionStart;

		if (diff >= _transitionTime) {
			resetTransition();
		}
		else if (currentMillis > _lastUpdate) {
			// Interpolate the level.

			float progress = float(diff) / float(_transitionTime);

			float level =
				_startLevel +
				(getScaledLevel() - _startLevel) * progress;

			_actualLevel = level;
			_lastUpdate = currentMillis;

			updatePinValue();
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
		_lastUpdate = millis();

		updatePinValue();
	}

private:
	void updatePinValue() {
		auto realValue = interpolate(_actualLevel);

		DEBUG(F("Setting light pin to "), realValue, F(" scaled level "), _actualLevel);

		analogWrite(_pin, realValue);
	}

	float getScaledLevel() {
		return scaleLightLevel(_level, _minimumLevel, _maximumLevel);
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