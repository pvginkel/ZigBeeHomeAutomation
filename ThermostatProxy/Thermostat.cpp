#include "Thermostat.h"

void Thermostat::begin() {
	pinMode(_thermostatInPin, INPUT);
	digitalWrite(_thermostatInPin, HIGH); // pull up
	digitalWrite(_thermostatOutPin, HIGH);
	pinMode(_thermostatOutPin, OUTPUT); // low output = high current, high output = low current
	pinMode(_boilerInPin, INPUT);
	digitalWrite(_boilerInPin, HIGH); // pull up
	digitalWrite(_boilerOutPin, HIGH);
	pinMode(_boilerOutPin, OUTPUT); // low output = high voltage, high output = low voltage
}

void Thermostat::update() {
    // This is just a simple gateway for now.
    // https://github.com/jpraus/arduino-opentherm/blob/master/examples/gateway/gateway.ino

    if (_mode == Mode::ListenMaster) {
        if (OPENTHERM::isSent() || OPENTHERM::isIdle() || OPENTHERM::isError()) {
            OPENTHERM::listen(_thermostatInPin);
        }
        else if (OPENTHERM::getMessage(_message)) {
            _eventOccurred.call(printMessage(F("-> ")));

            OPENTHERM::send(_boilerOutPin, _message); // forward message to boiler

            _mode = Mode::ListenSlave;
        }
    }
    else if (_mode == Mode::ListenSlave) {
        if (OPENTHERM::isSent()) {
            OPENTHERM::listen(_boilerInPin, 800); // response need to be sent back by boiler within 800ms
        }
        else if (OPENTHERM::getMessage(_message)) {
            _eventOccurred.call(printMessage(F("<- ")));

            OPENTHERM::send(_thermostatOutPin, _message); // send message back to thermostat

            _mode = Mode::ListenMaster;
        }
        else if (OPENTHERM::isError()) {
            _mode = Mode::ListenMaster;

            _eventOccurred.call(F("<- Timeout"));
        }
    }
}

const String& Thermostat::printMessage(const __FlashStringHelper* prefix) {
    _printedMessage = prefix;

    if (_message.type == OT_MSGTYPE_READ_DATA) {
        _printedMessage += String(F("ReadData"));
    }
    else if (_message.type == OT_MSGTYPE_READ_ACK) {
        _printedMessage += String(F("ReadAck"));
    }
    else if (_message.type == OT_MSGTYPE_WRITE_DATA) {
        _printedMessage += String(F("WriteData"));
    }
    else if (_message.type == OT_MSGTYPE_WRITE_ACK) {
        _printedMessage += String(F("WriteAck"));
    }
    else if (_message.type == OT_MSGTYPE_INVALID_DATA) {
        _printedMessage += String(F("InvalidData"));
    }
    else if (_message.type == OT_MSGTYPE_DATA_INVALID) {
        _printedMessage += String(F("DataInvalid"));
    }
    else if (_message.type == OT_MSGTYPE_UNKNOWN_DATAID) {
        _printedMessage += String(F("UnknownId"));
    }
    else {
        _printedMessage += String(_message.type, BIN);
    }

    _printedMessage += F(" ");
    _printedMessage += _message.id;
    _printedMessage += F(" ");
    _printedMessage += String(_message.valueHB, HEX);
    _printedMessage += F(" ");
    _printedMessage += String(_message.valueLB, HEX);

    return _printedMessage;
}
