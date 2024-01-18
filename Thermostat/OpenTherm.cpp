/*
OpenTherm.cpp - OpenTherm Communication Library For Arduino, ESP8266
Copyright 2018, Ihor Melnyk
*/

#include "OpenTherm.h"

#ifndef ICACHE_RAM_ATTR
#define ICACHE_RAM_ATTR
#endif

#ifndef IRAM_ATTR
#define IRAM_ATTR ICACHE_RAM_ATTR
#endif

OpenTherm::OpenTherm(uint8_t inPin, uint8_t outPin, bool isSlave):
	_inPin(inPin),
	_outPin(outPin),
	_isSlave(isSlave),
	_status(OpenThermStatus::NotInitialized),
	_response(0),
	_responseStatus(OpenThermResponseStatus::None),
	_responseTimestamp(0),
	_responseBitIndex(0),
	_handleInterruptCallback(nullptr),
	_processResponseCallback(nullptr) { }

void OpenTherm::begin(void(*handleInterruptCallback)(), void(*processResponseCallback)(OpenThermFrame_t, OpenThermResponseStatus))
{
	pinMode(_inPin, INPUT);
	pinMode(_outPin, OUTPUT);

	if (handleInterruptCallback != nullptr) {
		_handleInterruptCallback = handleInterruptCallback;
		attachInterrupt(digitalPinToInterrupt(_inPin), handleInterruptCallback, CHANGE);
	}

	activateBoiler();

	_status = OpenThermStatus::Ready;
	_processResponseCallback = processResponseCallback;
}

void OpenTherm::activateBoiler() const
{
	setState(false);
	delay(1000);
}

bool IRAM_ATTR OpenTherm::isReady() const
{
	return _status == OpenThermStatus::Ready;
}

int IRAM_ATTR OpenTherm::readState() const
{
	return digitalRead(_inPin);
}

void OpenTherm::setState(bool active) const
{
	digitalWrite(_outPin, active ? LOW : HIGH);
}

void OpenTherm::sendBit(bool high) const {
	setState(high);
	delayMicroseconds(500);
	setState(!high);
	delayMicroseconds(500);
}

bool OpenTherm::trySendRequest(OpenThermMessage message)
{
	noInterrupts();
	const bool ready = isReady();
	interrupts();

	if (!ready) {
		return false;
	}

	sendFrame(serializeMessage(message));

	_status = OpenThermStatus::ResponseWaiting;
	_responseTimestamp = micros();

	return true;
}

void OpenTherm::sendResponse(OpenThermMessage message)
{
	sendFrame(serializeMessage(message));

	_status = OpenThermStatus::Ready;
}

void OpenTherm::sendFrame(OpenThermFrame_t frame)
{
	_status = OpenThermStatus::RequestSending;
	_response = 0;
	_responseStatus = OpenThermResponseStatus::None;

	sendBit(HIGH); //start bit
	for (auto i = 31; i >= 0; i--) {
		sendBit(bitRead(frame, i));
	}
	sendBit(HIGH); //stop bit
	setState(false);
}

OpenThermMessage OpenTherm::getLastResponse() const
{
	return deserializeMessage(_response);
}

OpenThermResponseStatus OpenTherm::getLastResponseStatus()
{
	return _responseStatus;
}

void IRAM_ATTR OpenTherm::handleInterrupt()
{
	if (isReady())
	{
		if (_isSlave && readState() == HIGH) {
		   _status = OpenThermStatus::ResponseWaiting;
		}
		else {
			return;
		}
	}

	const auto newTs = micros();
	if (_status == OpenThermStatus::ResponseWaiting) {
		if (readState() == HIGH) {
			_status = OpenThermStatus::ResponseStartBit;
		}
		else {
			_status = OpenThermStatus::ResponseInvalid;
		}
		_responseTimestamp = newTs;
	}
	else if (_status == OpenThermStatus::ResponseStartBit) {
		if ((newTs - _responseTimestamp < 750) && readState() == LOW) {
			_status = OpenThermStatus::ResponseReceiving;
			_responseBitIndex = 0;
			_response = 0;
		}
		else {
			_status = OpenThermStatus::ResponseInvalid;
		}
		_responseTimestamp = newTs;
	}
	else if (_status == OpenThermStatus::ResponseReceiving) {
		if ((newTs - _responseTimestamp) > 750) {
			if (_responseBitIndex < 32) {
				_response = (_response << 1) | !readState();
				_responseBitIndex++;
			}
			else { //stop bit
				_status = OpenThermStatus::ResponseReady;
			}
			_responseTimestamp = newTs;
		}
	}
}

void OpenTherm::process()
{
	noInterrupts();
	auto st = _status;
	auto ts = _responseTimestamp;
	interrupts();

	if (st == OpenThermStatus::Ready) {
		return;
	}

	auto newTs = micros();

	if (st != OpenThermStatus::NotInitialized && st != OpenThermStatus::Delay && (newTs - ts) > 1000000) {
		_status = OpenThermStatus::Ready;
		_responseStatus = OpenThermResponseStatus::Timeout;
		if (_processResponseCallback != nullptr) {
			_processResponseCallback(_response, _responseStatus);
		}
	}
	else if (st == OpenThermStatus::ResponseInvalid) {
		_status = OpenThermStatus::Delay;
		_responseStatus = OpenThermResponseStatus::Invalid;
		if (_processResponseCallback != nullptr) {
			_processResponseCallback(_response, _responseStatus);
		}
	}
	else if (st == OpenThermStatus::ResponseReady) {
		_status = OpenThermStatus::Delay;
		_responseStatus = !parity(_response) ? OpenThermResponseStatus::Success : OpenThermResponseStatus::Invalid;
		if (_processResponseCallback != nullptr) {
			_processResponseCallback(_response, _responseStatus);
		}
	}
	else if (st == OpenThermStatus::Delay) {
		if ((newTs - ts) > 100000) {
			_status = OpenThermStatus::Ready;
		}
	}
}

OpenThermFrame_t OpenTherm::parity(OpenThermFrame_t frame)
{
	byte p = 0;

	while (frame > 0)
	{
		if (frame & 1) {
			p++;
		}

		frame = frame >> 1;
	}

	return (p & 1) << 31;
}

void OpenTherm::end() const {
	if (_handleInterruptCallback != nullptr) {
		detachInterrupt(digitalPinToInterrupt(_inPin));
	}
}

OpenThermFrame_t OpenTherm::serializeMessage(OpenThermMessage& message) {
	const auto frame =
		(OpenThermFrame_t)message.payload |
		(OpenThermFrame_t)message.id << 16 |
		(OpenThermFrame_t)message.type << 28;

	return frame | parity(frame);
}

OpenThermMessage OpenTherm::deserializeMessage(OpenThermFrame_t frame) {
	const auto type = (OpenThermMessageType)((frame >> 28) & 0b111);
	const auto id = (OpenThermMessageID)((frame >> 16) & 0xff);
	const auto payload = uint16_t(frame);

	return { id, type, payload };
}
