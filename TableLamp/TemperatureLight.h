#pragma once

#include "Light.h"

template <class InterpolateAlgorithm>
class TemperatureLight {
	CallbackArgs<float> _levelChanged;
	CallbackArgs<uint16_t> _temperatureChanged;
	LinearLight _cold;
	LinearLight _warm;
	uint16_t _minimumTemperature;
	uint16_t _maximumTemperature;
	float _minimumLevel;
	float _maximumLevel;
	float _level;
	uint16_t _temperature;

public:
	TemperatureLight(uint16_t minimumTemperature, uint16_t maximumTemperature)
		: _minimumTemperature(minimumTemperature), _maximumTemperature(maximumTemperature),
		_minimumLevel(0.0f), _maximumLevel(1.0f), _level(0.0f), _temperature(minimumTemperature) {
	}

	void reconfigure(float minimumLevel, float maximumLevel, time_t time = 0) {
		_minimumLevel = minimumLevel;
		_maximumLevel = maximumLevel;

		updateLevelAndTemperature(time);
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
		DEBUG(F("Setting temperature to "), temperature, F(" minimum "), _minimumTemperature, F(" maximum "), _maximumTemperature);

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

		auto interpolatedLevel = InterpolateAlgorithm::interpolate(_level);
		auto scaledLevel = scaleLightLevel(interpolatedLevel, _minimumLevel, _maximumLevel);
		auto color = hsi2rgb(mix, 100, scaledLevel);

		auto warmLevel = color.g;
		auto coldLevel = color.r;

		DEBUG(F("Level "), _level, F(", interpolated "), interpolatedLevel, F(", scaled "), scaledLevel, F(", warm level "), warmLevel, F(" cold level "), coldLevel);

		_cold.setLevel(coldLevel, time);
		_warm.setLevel(warmLevel, time);
	}
};

typedef TemperatureLight<CIE1931InterpolateAlgorithm> NaturalTemperatureLight;
