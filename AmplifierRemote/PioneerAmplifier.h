#pragma once

#include <IrSenderPwm.h>

class PioneerAmplifier
{
	IrSender* _irsend;

	void sendRaw(const microseconds_t intro_P[], size_t lengthIntro, const microseconds_t repeat_P[],
		size_t lengthRepeat, frequency_t frequency, unsigned times);

public:
	PioneerAmplifier(uint8_t pin) {
		_irsend = IrSenderPwm::getInstance(true);
	}

	void power(int times = 1);
	void volumeUp(int times = 1);
	void volumeDown(int times = 1);
};
