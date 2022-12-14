#include "Display.h"

#define FONT_HEIGHT 10
#define FONT_WIDTH 6

// https://stackoverflow.com/questions/18216019
#define _FONT1(w, h) u8g2_font_##w##x##h##_mr
#define _FONT(w, h) _FONT1(w, h)

#define FONT _FONT(FONT_WIDTH, FONT_HEIGHT)

void Display::update() {
    // If the auto shutdown timer is configured, and we've been on
    // for too long, and the lamp isn't on, clear the screen.

    auto currentMillis = millis();

    if (
        _screen &&
        _lastUpdate &&
        _autoOffTime &&
        !_brightness &&
        (_lastUpdate + _autoOffTime) < currentMillis
    ) {
        _lastUpdate = 0;
        _screen->clearBuffer();
        _screen->sendBuffer();
        return;
    }

	if (_screen && _dirty) {
		paint();
        _lastUpdate = currentMillis;
		_dirty = false;
	}
}

void Display::paint() {
    _screen->clearBuffer();

    if (_connected == ConnectionStatus::Connected) {
        // This font pulls in 10 Kb, but all we need is the "network bars" icon.
        //
        //_screen->setFont(u8g2_font_siji_t_6x10);
        //_screen->drawGlyph(_width - 12, 12, 57584);

        _screen->drawLine(_width - 1, 2, _width - 1, 9);
        _screen->drawLine(_width - 3, 4, _width - 3, 9);
        _screen->drawLine(_width - 5, 6, _width - 5, 9);
        _screen->drawLine(_width - 7, 8, _width - 7, 9);
    }

    int maxWidth = _width - 13;
    _screen->drawFrame(0, 0, maxWidth, 12);
    maxWidth -= 4;
    unsigned int width = _brightness * maxWidth / 255;
    if (width > 0) {
        _screen->drawBox(2, 2, width, 8);
    }

    if (_status.length() > 0) {
        _screen->setFont(FONT);
        _screen->setCursor(0, _height - 2);
        _screen->print(_status);
    }

    _screen->sendBuffer();
}
