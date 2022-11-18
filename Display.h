#pragma once

#include <U8g2lib.h>
#include "support.h"

class Display
{
	U8G2* _screen{};
	bool _dirty{};
	bool _connected{};
	uint8_t _brightness{};
	String _message;
	int _width{};
	int _height{};

public:
	void begin(U8G2& screen, int width, int height) {
		_screen = &screen;
		_width = width;
		_height = height;
		_dirty = true;
	}

	void loop();

	void setConnected(bool connected) {
		_connected = connected;
		_dirty = true;
	}

	void setBrightness(uint8_t brightness) {
		_brightness = brightness;
		_dirty = true;
	}

	void setMessage(const String& message) {
		_message = message;
		_dirty = true;
	}

private:
	void paint();
};
