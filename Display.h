#pragma once

#include <U8g2lib.h>
#include "StatusCb.h"

class Display : public StatusCb
{
	U8G2* _screen{};
	bool _dirty{};
	ConnectionStatus _connected{};
	uint8_t _brightness{};
	String _status;
	int _width{};
	int _height{};

public:
	void begin(U8G2& screen, int width, int height) {
		_screen = &screen;
		_width = width;
		_height = height;
		_dirty = true;
	}

	void update();

	void setConnected(ConnectionStatus connected) override {
		_connected = connected;
		_dirty = true;
	}

	void setBrightness(uint8_t brightness) {
		_brightness = brightness;
		_dirty = true;
	}

	void setStatus(const String& status) override {
		_status = status;
		_dirty = true;
	}

private:
	void paint();
};
