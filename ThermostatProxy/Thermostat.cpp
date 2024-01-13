#include "Thermostat.h"

Thermostat* Thermostat::_instance = nullptr;

void IRAM_ATTR Thermostat::handleBoilerInterrupt() {
    _instance->_boiler.handleInterrupt();
}

void IRAM_ATTR Thermostat::handleThermostatInterrupt() {
    _instance->_thermostat.handleInterrupt();
}

Thermostat::Thermostat(uint8_t boilerInPin, uint8_t boilerOutPin, uint8_t thermostatInPin, uint8_t thermostatOutPin) :
    _boiler(boilerInPin, boilerOutPin, false /* master */),
    _thermostat(thermostatInPin, thermostatOutPin, true /* slave */)
{
    _instance = this;

    _printedMessage.reserve(30);
}

void Thermostat::begin() {
    _boiler.begin(handleBoilerInterrupt);
    _thermostat.begin(handleThermostatInterrupt, [](unsigned long request, OpenThermResponseStatus status) {
        _instance->processThermostatRequest(request, status);
    });

    _eventOccurred.call(F("Proxying messages between the boiler and the thermostat"));
}

void Thermostat::processThermostatRequest(unsigned long request, OpenThermResponseStatus status) {
    auto response = _boiler.sendRequest(request);

    if (response) {
        _thermostat.sendResponse(response);
    }

    _printedMessage = F("T:");
    _printedMessage += String(request, HEX);
    _printedMessage += F(" B:");
    _printedMessage += String(response, HEX);

    _eventOccurred.call(_printedMessage);
}

void Thermostat::update() {
    // Only the thermostat has to be processed.
    _thermostat.process();
}
