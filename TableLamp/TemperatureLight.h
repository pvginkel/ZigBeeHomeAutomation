#pragma once

#include "Light.h"

template <class InterpolateAlgorithm>
class TemperatureLight {
	struct RGB {
		float r;
		float g;
		float b;

		RGB(float r, float g, float b) : r(r), g(g), b(b) { }
	};

	CallbackArgs<float> _levelChanged;
	CallbackArgs<uint16_t> _temperatureChanged;
	LinearLight _cold;
	LinearLight _warm;
	uint16_t _minimumTemperature;
	uint16_t _maximumTemperature;
	float _level;
	uint16_t _temperature;

public:
	TemperatureLight(uint16_t minimumTemperature, uint16_t maximumTemperature)
		: _minimumTemperature(minimumTemperature), _maximumTemperature(maximumTemperature),
		_level(0.0f), _temperature(minimumTemperature) {
	}

	void reconfigure(float minimumLevel, float maximumLevel, time_t time = 0) {
		_cold.reconfigure(minimumLevel, maximumLevel, time);
		_warm.reconfigure(minimumLevel, maximumLevel, time);
	}

	void begin(uint8_t coldPin, uint8_t warmPin) {
		_cold.begin(coldPin);
		_warm.begin(warmPin);
	}

	bool isOn() const {
		return _level > 0;
	}
	float getLevel() const {
		return _level;
	}
	uint16_t getTemperature() const {
		return _temperature;
	}
	void onLevelChanged(CallbackArgs<float>::Func func, uintptr_t data = 0) {
		_levelChanged.set(func, data);
	}
	void onTemperatureChanged(CallbackArgs<uint16_t>::Func func, uintptr_t data = 0) {
		_temperatureChanged.set(func, data);
	}

	void update() {
		_cold.update();
		_warm.update();
	}

	void setLevel(float level, time_t time = 0) {
		_level = level;

		updateLevelAndTemperature(time);

		_levelChanged.call(_level);
	}

	void setTemperature(uint16_t temperature, time_t time = 0) {
		if (temperature < _minimumTemperature) {
			temperature = _minimumTemperature;
		}
		if (temperature > _maximumTemperature) {
			temperature = _maximumTemperature;
		}

		_temperature = temperature;

		updateLevelAndTemperature(time);

		_temperatureChanged.call(temperature);
	}

	void resetTransition() {
		_cold.resetTransition();
		_warm.resetTransition();
	}

private:
	void updateLevelAndTemperature(time_t time = 0) {
		const auto range = float(_maximumTemperature - _minimumTemperature);
		const auto offset = float(_temperature - _minimumTemperature) / range;

		// We only use the first third of the HUE space. That's enough for
		// us to properly mix warm and cold white.

		auto mix = offset * 120.0f;

		auto color = hsi2rgb(mix, 100, InterpolateAlgorithm::interpolate(_level));

		auto warmLevel = color.g;
		auto coldLevel = color.r;

		_cold.setLevel(coldLevel, time);
		_warm.setLevel(warmLevel, time);
	}

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

	static RGB hsi2rgb(float H, float S, float I) {
		float r, g, b;
		H = fmodf(H, 360); // cycle H around to 0-360 degrees
		H = 3.14159f * H / 180.0f; // Convert to radians.
		S = S > 0 ? (S < 1 ? S : 1) : 0; // clamp S and I to interval [0,1]
		I = I > 0 ? (I < 1 ? I : 1) : 0;

		// Math! Thanks in part to Kyle Miller.
		if (H < 2.09439f) {
			r = I / 3 * (1 + S * cosf(H) / cosf(1.047196667f - H));
			g = I / 3 * (1 + S * (1 - cosf(H) / cosf(1.047196667f - H)));
			b = I / 3 * (1 - S);
		}
		else if (H < 4.188787f) {
			H = H - 2.09439f;
			g = I / 3 * (1 + S * cosf(H) / cos(1.047196667f - H));
			b = I / 3 * (1 + S * (1 - cosf(H) / cosf(1.047196667f - H)));
			r = I / 3 * (1 - S);
		}
		else {
			H = H - 4.188787f;
			b = I / 3 * (1 + S * cosf(H) / cosf(1.047196667f - H));
			r = I / 3 * (1 + S * (1 - cosf(H) / cosf(1.047196667f - H)));
			g = I / 3 * (1 - S);
		}

		return { r, g, b };
	}
};

typedef TemperatureLight<CIE1931InterpolateAlgorithm> NaturalTemperatureLight;
