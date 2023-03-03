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
		DEBUG("Setting temperature to ", temperature, " minimum ", _minimumTemperature, " maximum ", _maximumTemperature);

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

		auto scaledWarmLevel = scaleLevel(warmLevel, coldLevel + warmLevel);
		auto scaledColdLevel = scaleLevel(coldLevel, coldLevel + warmLevel);

		DEBUG("Warm level ", warmLevel * 100, " scaled ", scaledWarmLevel, " cold level ", coldLevel * 100, " scaled ", scaledColdLevel);

		_cold.setLevel(scaledColdLevel, time);
		_warm.setLevel(scaledWarmLevel, time);
	}

	float scaleLevel(float level, float totalLevel) {
		// Apply the minimum and maximum levels to the specific level. We do this
		// by scaling the specific level as a percentage of how much that level
		// influences the total light. So, if cold is 25% and warm 75%, 25% of
		// the minimum level goes to cold.

		auto fraction = level / totalLevel;

		float minimumLevel = fraction * _minimumLevel;

		return scaleLightLevel(level, minimumLevel, _maximumLevel);
	}
};

typedef TemperatureLight<CIE1931InterpolateAlgorithm> NaturalTemperatureLight;
