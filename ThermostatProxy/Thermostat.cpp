#include "Thermostat.h"
#include "Support.h"

Thermostat* Thermostat::_instance = nullptr;

void IRAM_ATTR Thermostat::handleBoilerInterrupt() {
    _instance->_boiler.handleInterrupt();
}

void IRAM_ATTR Thermostat::handleThermostatInterrupt() {
    _instance->_thermostat.handleInterrupt();
}

Thermostat::Thermostat(uint8_t boilerInPin, uint8_t boilerOutPin, uint8_t thermostatInPin, uint8_t thermostatOutPin) :
    _boiler(boilerInPin, boilerOutPin, false /* master */),
    _thermostat(thermostatInPin, thermostatOutPin, true /* slave */),
    _pendingRequest(0)
{
    _instance = this;

    _printedMessage.reserve(30);
}

void Thermostat::begin() {
    _boiler.begin(handleBoilerInterrupt, [](unsigned long request, OpenThermResponseStatus status) {
        _instance->processBoilerResponse(request, status);
    });
    _thermostat.begin(handleThermostatInterrupt, [](unsigned long request, OpenThermResponseStatus status) {
        _instance->processThermostatRequest(request, status);
    });

    _eventOccurred.call(F("Proxying messages between the boiler and the thermostat"));
}

void Thermostat::processThermostatRequest(unsigned long request, OpenThermResponseStatus status) {
    _printedMessage = F("T:");
    _printedMessage += String(request, HEX);
    _printedMessage += F(":");
    _printedMessage += String((uint8_t)status);

    DEBUG(F("Process thermostat request "), _printedMessage);

    if (status == OpenThermResponseStatus::OTRS_SUCCESS) {
        auto sent = _boiler.sendRequestAync(request);
        if (!sent) {
            _pendingRequest = request;
            DEBUG(F("Pending"));
        }
        else {
            DEBUG(F("Sent"));
        }
    }
    else {
        _eventOccurred.call(_printedMessage);
    }
}

void Thermostat::processBoilerResponse(unsigned long response, OpenThermResponseStatus status) {
    if (response) {
        _thermostat.sendResponse(response);
    }

    _printedMessage += F(" B:");
    _printedMessage += String(response, HEX);
    _printedMessage += F(":");
    _printedMessage += String((uint8_t)status);

    DEBUG(F("Process boiler response "), _printedMessage);

    _eventOccurred.call(_printedMessage);
}

void Thermostat::update() {
    _thermostat.process();
    _boiler.process();

    if (_pendingRequest) {
        auto sent = _boiler.sendRequestAync(_pendingRequest);
        if (sent) {
            DEBUG(F("Sent pending request"));
            _pendingRequest = 0;
        }
    }
}
