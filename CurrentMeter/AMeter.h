#pragma once

#include "ZigBeeHomeAutomation.h"

class AMeter {
public:
	typedef bool(*analogTryRead_t)(uint16_t& result);

private:
	const float VOLTS = 5.0;
	const uint16_t MAX_ADC = 1023;
	const bool SUPPRESS_NOISE = true;
	const uint32_t MICROS_PER_SECOND = 1000000ul;
	const uint32_t MINIMUM_SAMPLES = 40ul;
	const int SECONDS_BACKLOG = 2;

	float _mAPerStep;
	uint8_t _frequency;
	uint16_t _value{};
	time_t _lastStart{};
	uint32_t _samples{};
	double _sum{};
	int16_t _midPoint{};
	CallbackArgs<float> _sampleCollected;
	float _lastSample{};
	analogTryRead_t _analogTryRead;
	float* _sampleList;
	int _sampleListSize;
	int _sampleListOffset{};
	int _sampleListValid{};

public:
	AMeter(float mVperAmpere, uint8_t frequency, analogTryRead_t analogTryRead)
		: _frequency(frequency), _analogTryRead(analogTryRead){
		const auto mVperStep = (1000.0f * VOLTS) / float(MAX_ADC);  //  1x 1000 for V -> mV
		_mAPerStep = 1000.0f * mVperStep / mVperAmpere;

		_sampleListSize = int(frequency) * SECONDS_BACKLOG;
		_sampleList = malloc(sizeof(float) * _sampleListSize);
	}

	void autoMidPoint(uint8_t analogPin, uint16_t cycles = 1);

	void begin() {
		reset();
	}

	void update();

	float getLastSample() {
		return _lastSample;
	}

	void onSampleCollected(CallbackArgs<float>::Func func, uintptr_t data = 0) {
		_sampleCollected.set(func, data);
	}

private:
	void reset();
};
