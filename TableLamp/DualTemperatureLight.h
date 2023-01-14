#pragma once

#include "TemperatureLight.h"

template <class InterpolateAlgorithm>
class DualTemperatureLight {
	CallbackArgs<float> _levelChanged;
	CallbackArgs<uint16_t> _temperatureChanged;
	TemperatureLight<InterpolateAlgorithm> _low;
	TemperatureLight<InterpolateAlgorithm> _high;
	float _level;
	float _breakStart;
	float _breakEnd;

public:
	DualTemperatureLight(TemperatureLight<InterpolateAlgorithm> low, TemperatureLight<InterpolateAlgorithm> high, float breakStart, float breakEnd)
		: _low(low), _high(high), _level(0), _breakStart(breakStart), _breakEnd(breakEnd) {
	}

	void begin(uint8_t lowColdPin, uint8_t lowWarmPin, uint8_t highColdPin, uint8_t highWarmPin) {
		_low.begin(lowColdPin, lowWarmPin);
		_high.begin(highColdPin, highWarmPin);
	}

	bool isOn() const {
		return _level > 0;
	}
	float getLevel() const {
		return _level;
	}
	uint16_t getTemperature() const {
		return _low.getTemperature();
	}
	void onLevelChanged(CallbackArgs<float>::Func func, uintptr_t data = 0) {
		_levelChanged.set(func, data);
	}
	void onTemperatureChanged(CallbackArgs<uint16_t>::Func func, uintptr_t data = 0) {
		_temperatureChanged.set(func, data);
	}

	void update() {
		_low.update();
		_high.update();
	}

	void setLevel(float level, time_t time = 0) {
		_level = level;

		// Set the high lamp. The high lamp goes from breakStart till 255,
		// regardless of where the low lamp is at.

		if (level < _breakStart) {
			_high.setLevel(0, time);
		}
		else {
			const auto range = 1.0f - _breakStart;
			const auto offset = level - _breakStart / range;
			_high.setLevel(offset, time);
		}

		// Set the low lamp. Until breakStart, the low lamp increases relative
		// to the break start. Between breakStart and breakEnd, the low lamp
		// decreases as the offset between the two.

		if (level < _breakStart) {
			const auto offset = level / _breakStart;
			_low.setLevel(offset, time);
		}
		else if (level > _breakEnd) {
			_low.setLevel(0, time);
		}
		else {
			const auto range = _breakEnd - _breakStart;
			const auto offset = level - _breakStart / range;
			_low.setLevel(1.0f - offset, time);
		}

		_levelChanged.call(_level);
	}

	void setTemperature(uint16_t temperature, time_t time = 0) {
		_low.setTemperature(temperature, time);
		_high.setTemperature(temperature, time);

		_temperatureChanged.call(temperature);
	}

	void resetTransition() {
		_low.resetTransition();
		_high.resetTransition();
	}
};

typedef DualTemperatureLight<CIE1931InterpolateAlgorithm> NaturalDualTemperatureLight;
