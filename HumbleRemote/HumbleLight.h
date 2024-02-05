#pragma once

#include "Remote.h"
#include "Callback.h"

class HumbleLight
{
	static constexpr float BRIGHTNESS1_CUTOFF = 1.0f / 3.0f;
	static constexpr float BRIGHTNESS2_CUTOFF = 2.0f / 3.0f;

	Remote _remote;
	float _level;
	CallbackArgs<float> _levelChanged;

public:
	HumbleLight(Remote remote);

	void begin() const;
	void update();
	bool isOn() const;
	float getLevel() const;
	void onLevelChanged(CallbackArgs<float>::Func func, uintptr_t data = 0);
	void setLevel(float level);
};
