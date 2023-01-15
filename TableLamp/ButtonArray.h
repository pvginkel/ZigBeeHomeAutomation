#pragma once

#include <Adafruit_MPR121.h>

class ButtonArray {
    class CapBounce : public Debouncer {
        uint16_t* _touched;
        uint8_t _pin;

    public:
        CapBounce(uint16_t& touched, uint8_t pin, uint16_t interval = 50) : _touched(&touched), _pin(pin) {
            this->interval(interval);
        }
        virtual ~CapBounce() = default;

    protected:
        bool readCurrentState() override {
            return *_touched & (1 << _pin);
        }
    };

    uint8_t _irqPin;
	Adafruit_MPR121 _cap;
    uint16_t _touched;
    CapBounce _buttons[4] = {
        CapBounce(_touched, 0),
        CapBounce(_touched, 1),
        CapBounce(_touched, 2),
        CapBounce(_touched, 3)
    };

public:
    ButtonArray() : _irqPin(0), _touched(0) {
    }

    void interval(uint16_t interval_millis) {
        for (auto& button : _buttons) {
            button.interval(interval_millis);
        }
    }

    bool begin(uint8_t irqPin, uint8_t i2caddr) {
        _irqPin = irqPin;

        pinMode(irqPin, INPUT);

        return _cap.begin(i2caddr);
    }

    void update() {
        for (auto& button : _buttons) {
	        button.update();
        }

        // IRQ pin goes low if there's information available.

        auto state = digitalRead(_irqPin);
        if (state != LOW) {
            return;
        }

        _touched = _cap.touched();
    }

    bool rose(int button) {
        return _buttons[button].rose();
    }
    bool fell(int button) {
        return _buttons[button].fell();
    }
    bool read(int button) {
        return _buttons[button].read();
    }
    bool changed(int button) {
        return _buttons[button].changed();
    }
    unsigned long currentDuration(int button) {
        return _buttons[button].currentDuration();
    }
    unsigned long previousDuration(int button) {
        return _buttons[button].previousDuration();
    }
};
