#pragma once

#include <U8g2lib.h>
#include <ZigBeeHomeAutomation.h>

class Display {
	U8G2* _screen{};
	bool _dirty{};
	ConnectionStatus _connected{};
	uint8_t _brightness{};
	String _status;
	int _width{};
	int _height{};
	time_t _lastUpdate{};
	time_t _autoOffTime{};

public:
	void begin(U8G2& screen, int width, int height, time_t autoOffTime) {
		_screen = &screen;
		_width = width;
		_height = height;
		_autoOffTime = autoOffTime;
		_dirty = true;
	}

	void update();

	void setConnected(ConnectionStatus connected) {
		_connected = connected;
		_dirty = true;
	}

	void setBrightness(uint8_t brightness) {
		_brightness = brightness;
		_dirty = true;
	}

	void setStatus(const String& status) {
		_status = status;
		_dirty = true;
	}

private:
	void paint();
};
