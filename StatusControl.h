#pragma once

#include <Bounce2.h>
#include "Callback.h"
#include "StatusCb.h"
#include "support.h"

class StatusControl : public StatusCb
{
	int _led = -1;
	Bounce _bounce;
	bool _isHigh = false;
	Callback _click;
	Callback _reset;
	CallbackArgs<int> _resetCountdown;
	time_t _lastStatusChange = 0;
	ConnectionStatus _connected = ConnectionStatus::NotConnected;
	time_t _initialDelay;
	int _steps;
	time_t _stepTime;
	bool _resetRaised = false;
	time_t _fadePeriod;
	int _remainingReported = -1;

public:
	StatusControl(time_t initialDelay = 1000, int steps = 4, time_t stepTime = 1000, time_t fadePeriod = 1000)
		: _initialDelay(initialDelay), _steps(steps), _stepTime(stepTime), _fadePeriod(fadePeriod) {
	}

	void setLed(int pin);
	void setBounce(Bounce bounce);
	void setConnected(ConnectionStatus connected) override;
	void setStatus(const String& status) override;
	void reportRemaining(int remaining);
	void update();

	void onClick(Callback::Func func, uintptr_t data = 0) {
		_click.set(func, data);
	}

	void onReset(Callback::Func func, uintptr_t data = 0) {
		_reset.set(func, data);
	}

	void onResetCountdown(CallbackArgs<int>::Func func, uintptr_t data = 0) {
		_resetCountdown.set(func, data);
	}
};
