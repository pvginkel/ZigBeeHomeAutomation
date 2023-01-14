#pragma once

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
    int _irqState;
	Adafruit_MPR121 _cap;
    uint16_t _touched;
    CapBounce _buttons[4] = {
        CapBounce(_touched, 0),
        CapBounce(_touched, 1),
        CapBounce(_touched, 2),
        CapBounce(_touched, 3)
    };

public:
    ButtonArray() : _irqPin(0), _irqState(0), _touched(0) {
    }

    bool begin(uint8_t irqPin, uint8_t i2caddr) {
        _irqPin = irqPin;

        pinMode(irqPin, INPUT_PULLUP);
        // Enable pull-up resistor.
        //digitalWrite(irqPin, HIGH);

        return _cap.begin(i2caddr);
    }

    void update() {
        /*
        auto state = digitalRead(_irqPin);
        if (_irqState != state) {
            DEBUG(F("Button IRQ changed from "), _irqState, F(" to "), state);

            _irqState = state;

            if (!state) {
                _touched = _cap.touched();

                DEBUG(F("  Touched is now "), String(_touched, BIN));
            }
        }
        */

        auto touched = _touched;

        _touched = _cap.touched();

        if (touched != _touched) {
            DEBUG(F("  Touched is now "), String(_touched, BIN));
        }
    }

    bool rose(int button) {
        return _buttons[button].update() && _buttons[button].rose();
    }
    bool fell(int button) {
        return _buttons[button].update() && _buttons[button].fell();
    }
};
