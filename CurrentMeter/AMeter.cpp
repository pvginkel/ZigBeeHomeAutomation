#include "AMeter.h"

void AMeter::reset() {
    _lastStart = _lastMeasurement = micros();
    _sum = 0;
    _samples = 0;
}

//  configure by sampling for 2 cycles of AC
//  Also works for DC as long as no current flowing
//  note this is blocking!
void AMeter::autoMidPoint(uint16_t cycles) {
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
            const auto reading = analogRead(_analogPin);
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
    if (!_lastStart) {
        reset();
    }

    auto currentMicros = micros();

    if (currentMicros - _lastSampleCollected < _interval) {
        return;
    }

    const auto fullCycle = MICROS_PER_SECOND / uint32_t(_frequency);
    // We allow for a maximum gap between two measurements of 1/20th of a full cycle.
    const auto maximumGap = fullCycle / 20ul;

    if (currentMicros - _lastMeasurement > maximumGap) {
        reset();
        currentMicros = _lastStart;
    }

    // Take a measurement and update the sum.

    auto value = analogRead(_analogPin);
    if (SUPPRESS_NOISE) {
        value = (analogRead(_analogPin) + value) / 2;
    }
    _lastMeasurement = currentMicros;

    const uint16_t current = int16_t(value) - _midPoint;

    _samples++;
    _sum += current * current;

    // Broadcast the sample once we have enough.

    if (currentMicros - _lastStart >= fullCycle) {
    	if (_samples < MINIMUM_SAMPLES) {
            DEBUG(F("Dropping sample because we got too few samples: "), _samples);
            DEBUG(F("Last start "), _lastStart, F(" current "), currentMicros);
            reset();
            return;
        }

        const auto sum = sqrtf(float(_sum / _samples));

        _lastSample = sum * _mAPerStep;
        _lastSampleCollected = currentMicros;

        _sampleCollected.call(_lastSample);

        reset();
    }
}
