#pragma once

#include "Arduino.h"

enum class ConnectionStatus {
	NotConnected,
	Connecting,
	Connected
};

class StatusCb {
public:
	virtual ~StatusCb() = default;

	virtual void setConnected(ConnectionStatus connected) = 0;
	virtual void setStatus(const String& status) = 0;
};
