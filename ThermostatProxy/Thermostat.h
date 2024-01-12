#pragma once

#include "opentherm.h"
#include "Arduino.h"
#include "Callback.h"

class Thermostat
{
	enum class Mode: uint8_t {
		ListenMaster,
		ListenSlave
	};

	CallbackArgs<const String&> _eventOccurred;
	uint8_t _boilerInPin;
	uint8_t _boilerOutPin;
	uint8_t _thermostatInPin;
	uint8_t _thermostatOutPin;
	Mode _mode = Mode::ListenMaster;
	OpenthermData _message;
	String _printedMessage;

	const String& printMessage(const __FlashStringHelper* prefix);

public:
	Thermostat(uint8_t boilerInPin, uint8_t boilerOutPin, uint8_t thermostatInPin, uint8_t thermostatOutPin) :
		_boilerInPin(boilerInPin), _boilerOutPin(boilerOutPin), _thermostatInPin(thermostatInPin), _thermostatOutPin(thermostatOutPin),
		_message()
	{
		_printedMessage.reserve(30);
	}

	void begin();
	void update();

	void eventOccurredCallback(CallbackArgs<const String&>::Func func, uintptr_t data = 0) {
		_eventOccurred.set(func, data);
	}
};
