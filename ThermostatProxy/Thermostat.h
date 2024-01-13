#pragma once

#include "OpenTherm.h"
#include "Arduino.h"
#include "Callback.h"

class Thermostat
{
	static Thermostat* _instance;
	static void IRAM_ATTR handleBoilerInterrupt();
	static void IRAM_ATTR handleThermostatInterrupt();

	CallbackArgs<const String&> _eventOccurred;
	OpenTherm _boiler;
	OpenTherm _thermostat;
	String _printedMessage;

	void processThermostatRequest(unsigned long request, OpenThermResponseStatus status);

public:
	Thermostat(uint8_t boilerInPin, uint8_t boilerOutPin, uint8_t thermostatInPin, uint8_t thermostatOutPin);

	void begin();
	void update();

	void eventOccurredCallback(CallbackArgs<const String&>::Func func, uintptr_t data = 0) {
		_eventOccurred.set(func, data);
	}
};
