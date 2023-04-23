#include "ZigBeeHomeAutomation.h"
#include "AMeter.h"
#include "Bounce2.h"
#include "U8g2lib.h"
#include "Display.h"

constexpr int SCREEN_HEIGHT = 64;
constexpr int SCREEN_WIDTH = 128;

constexpr uint8_t IO_XBEE_IN = 2;
constexpr uint8_t IO_XBEE_OUT = 3;
constexpr uint8_t IO_STATUS_LED = 10;
constexpr uint8_t IO_PB = 9;
constexpr uint8_t IO_RELAY = 5;
constexpr uint8_t IO_AMETER = A7;

constexpr uint8_t FREQUENCY = 50;
constexpr uint16_t VOLTAGE = 225;
constexpr float MV_PER_AMPERE = 185;

StatusControl status;
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);
Display display;
AMeter aMeter(MV_PER_AMPERE, FREQUENCY, analogTryRead);

void analogSetup() {
	// Disable digital input buffer on A7 (AIN5).
	PORTD_PIN5CTRL = PORT_ISC_INPUT_DISABLE_gc;

	// Reduced capacitance, Vdd ref, prescaler of 32.
	ADC0.CTRLC = uint8_t(ADC_PRESC_DIV32_gc) | uint8_t(ADC_REFSEL_VDDREF_gc) | ADC_SAMPCAP_bm;

	// ADC enable in 10 bit mode.
	ADC0.CTRLA = ADC_ENABLE_bm | ADC_RESSEL_10BIT_gc;

	// Select ADC channel.
	ADC0.MUXPOS = ADC_MUXPOS_AIN5_gc;

	// Enable FreeRun mode.
	ADC0.CTRLA |= ADC_FREERUN_bm;

	// Start conversion. Only set once because in FreeRun mode
	// the conversion keeps going.
	ADC0.COMMAND = ADC_STCONV_bm;
}

bool analogTryRead(uint16_t& result) {
	if (ADC0.INTFLAGS & ADC_RESRDY_bm) {
		// Clear the interrupt flag by writing 1
		ADC0.INTFLAGS = ADC_RESRDY_bm;

		result = ADC0.RES;
		return true;
	}

	return false;
}

void setup() {
	LOG_BEGIN();

	aMeter.onSampleCollected([](float sample, uintptr_t) {
		display.setAMeterValue(sample);
		display.setWattage((sample / 1000.0f) * VOLTAGE);
		});

	aMeter.autoMidPoint(IO_AMETER);

	pinMode(IO_RELAY, OUTPUT);

	status.onClick([](uintptr_t) {
		digitalWrite(IO_RELAY, !digitalRead(IO_RELAY));
	});

	status.onReset([](uintptr_t) {
	});

	status.setBounce(Bounce(IO_PB, 50));
	status.setLed(IO_STATUS_LED);

	status.onResetCountdown([](int remaining, uintptr_t) {
		if (remaining > 0) {
			display.setStatus(String(F("Resetting in ")) + remaining);
		}
		else if (remaining == 0) {
			display.setStatus(F("Resetting NOW"));
		}
		else {
			display.setStatus(String());
		}
	});

	u8g2.begin();
	display.begin(u8g2, SCREEN_WIDTH, SCREEN_HEIGHT);

	analogSetup();

	aMeter.begin();
}

void loop() {
	status.update();
	aMeter.update();

	// Update display last to make sure we don't have a dirty
	// screen in the next cycle.
	display.update();
}
