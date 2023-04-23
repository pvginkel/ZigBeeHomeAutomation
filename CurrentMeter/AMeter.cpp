#include "AMeter.h"

void AMeter::reset() {
    _lastStart = micros();
    _sum = 0;
    _samples = 0;
    _value = 0xffff;
}

//  configure by sampling for 2 cycles of AC
//  Also works for DC as long as no current flowing
//  note this is blocking!
void AMeter::autoMidPoint(uint8_t analogPin, uint16_t cycles) {
    pinMode(analogPin, INPUT);

    const auto twoPeriods = uint16_t(MICROS_PER_SECOND * 2ul / uint32_t(_frequency));

    if (cycles == 0) {
        cycles = 1;
    }

    uint32_t total = 0;

    for (uint16_t i = 0; i < cycles; i++) {
        uint32_t subTotal = 0;
        uint32_t samples = 0;

        uint32_t start = micros();

        while (micros() - start < twoPeriods) {
            const auto reading = analogRead(analogPin);
            subTotal += reading;
            samples++;
            //  Delaying prevents overflow
            //  since we'll perform a maximum of 40,000 reads @ 50 Hz.
            delayMicroseconds(1);
        }

        total += subTotal / samples;
    }

    _midPoint = total / cycles;
}

void AMeter::update() {
    // Is a value available?

    uint16_t value;
    if (!_analogTryRead(value)) {
        return;
    }

    if (SUPPRESS_NOISE) {
        if (_value == 0xffff) {
            _value = value;
            return;
        }

        value = (_value + value) / 2;
        _value = 0xffff;
    }

    // Add the sample.

    uint16_t current = int16_t(value) - _midPoint;

    _samples++;
    _sum += current * current;

    // Broadcast the sample once we have enough.

    const auto fullCycle = 1000000 / _frequency;
    const auto currentMicros = micros();

    if (currentMicros - _lastStart < fullCycle) {
        return;
    }

    if (_samples >= MINIMUM_SAMPLES) {
        const auto sum = sqrtf(float(_sum / _samples));

        _sampleList[_sampleListOffset++] = sum;
        if (_sampleListValid < _sampleListOffset) {
            _sampleListValid = _sampleListOffset;
        }
        if (_sampleListOffset >= _sampleListSize) {
            _sampleListOffset = 0;
        }

        auto total = 0.0f;
        for (int i = 0; i < _sampleListValid; i++) {
            total += _sampleList[i];
        }

        const auto average = total / float(_sampleListValid);

        _lastSample = average * _mAPerStep;

        _sampleCollected.call(_lastSample);
    }

    reset();
}
