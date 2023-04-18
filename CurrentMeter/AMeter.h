#pragma once

#include "ZigBeeHomeAutomation.h"

class AMeter {
	const float VOLTS = 5.0;
	const uint16_t MAX_ADC = 1023;
	const bool SUPPRESS_NOISE = true;
	const uint32_t MICROS_PER_SECOND = 1000000ul;
	const uint32_t MINIMUM_SAMPLES = 40ul;

	uint8_t _analogPin;
	float _mAPerStep;
	uint8_t _frequency;
	time_t _interval;
	time_t _lastMeasurement{};
	time_t _lastStart{};
	uint32_t _samples{};
	double _sum{};
	int16_t _midPoint{};
	CallbackArgs<float> _sampleCollected;
	float _lastSample{};
	time_t _lastSampleCollected{};

public:
	AMeter(uint8_t analogPin, float mVperAmpere, uint8_t frequency, time_t intervalMs)
		: _analogPin(analogPin), _frequency(frequency), _interval(intervalMs * 1000ul) {

		const auto mVperStep = (1000.0f * VOLTS) / float(MAX_ADC);  //  1x 1000 for V -> mV
		_mAPerStep = 1000.0f * mVperStep / mVperAmpere;
	}

	void begin() {
		pinMode(_analogPin, INPUT);

		autoMidPoint();
	}

	void update();

	float getLastSample() {
		return _lastSample;
	}

	void onSampleCollected(CallbackArgs<float>::Func func, uintptr_t data = 0) {
		_sampleCollected.set(func, data);
	}

private:
	void autoMidPoint(uint16_t cycles = 1);
	void reset();
};
