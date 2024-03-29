#include "Display.h"

#define TEETH_ANIMATION 0

#define FONT_HEIGHT 10
#define FONT_WIDTH 6

// https://stackoverflow.com/questions/18216019
#define _FONT1(w, h) u8g2_font_##w##x##h##_mr
#define _FONT(w, h) _FONT1(w, h)

#define FONT _FONT(FONT_WIDTH, FONT_HEIGHT)

void Display::update() {

#if TEETH_ANIMATION

    auto currentMillis = millis();
    if (currentMillis - _lastUpdate > 300) {
        _dirty = true;
        _lastUpdate = currentMillis;
    }

#endif

	if (_screen && _dirty) {
        auto currentMillis = millis();
        if (currentMillis - _lastUpdate >= MAX_UPDATE_INTERVAL) {
            _lastUpdate = currentMillis;

            paint();

            _dirty = false;
        }
	}
}

void Display::paint() {
    _screen->clearBuffer();

#if !TEETH_ANIMATION

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

    _screen->setFont(FONT);
    _screen->setCursor(0, _height / 2);
    _screen->print(_mA, 3);
    _screen->print(F(" mA "));
    _screen->print(_wattage, 2);
    _screen->print(F(" W"));

#else

    constexpr int teeth = 8;
    int toothHeight = _height / 4;
    int toothHeightVariance = (int)(toothHeight * 0.6);
    int toothWidth = _width / teeth;

    for (int i = 0; i < teeth; i++) {
        int thisHeight = toothHeight - (rand() % toothHeightVariance);
        _screen->drawFrame(i * toothWidth, 0, toothWidth, thisHeight - 1);
    }

    for (int i = 0; i < teeth; i++) {
        int thisHeight = toothHeight - (rand() % toothHeightVariance);
        _screen->drawFrame(i * toothWidth, _height - thisHeight, toothWidth, thisHeight - 1);
    }

#endif

    _screen->sendBuffer();
}
