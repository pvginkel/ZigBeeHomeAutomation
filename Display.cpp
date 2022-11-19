#include "Display.h"
#include "support.h"

#define FONT_HEIGHT 10
#define FONT_WIDTH 6

// https://stackoverflow.com/questions/18216019
#define _FONT1(w, h) u8g2_font_##w##x##h##_mr
#define _FONT(w, h) _FONT1(w, h)

#define FONT _FONT(FONT_WIDTH, FONT_HEIGHT)

void Display::loop() {
	if (_screen && _dirty) {
		paint();
		_dirty = false;
	}
}

void Display::paint() {
    _screen->clearBuffer();

    if (_connected) {
        // This font pulls in 10 Kb, but all we need is the "network bars" icon.
        //
        //_screen->setFont(u8g2_font_siji_t_6x10);
        //_screen->drawGlyph(_width - 12, 12, 57584);

        _screen->drawLine(_width - 1, 0, _width - 1, 8);
        _screen->drawLine(_width - 3, 2, _width - 3, 6);
        _screen->drawLine(_width - 5, 4, _width - 5, 4);
        _screen->drawLine(_width - 7, 2, _width - 7, 2);
    }

    int maxWidth = _width - 16;
    _screen->drawFrame(0, 0, maxWidth, 12);
    maxWidth -= 4;
    unsigned int width = _brightness * maxWidth / 255;
    if (width > 0) {
        _screen->drawBox(2, 2, width, 8);
    }

    if (_message.length() > 0) {
        _screen->setFont(FONT);
        _screen->setCursor(0, _height - 2);
        _screen->print(_message);
    }

    _screen->sendBuffer();
}
