#include "ZigBeeHomeAutomation.h"
#include "ACS712.h"
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

#if 0

void ADC0_init(void)
{
	///* Disable digital input buffer */
	//PORTD_PIN5CTRL &= ~PORT_ISC_gm;
	//PORTD_PIN5CTRL |= PORT_ISC_INPUT_DISABLE_gc;

	///* Disable pull-up resistor */
	//PORTD_PIN5CTRL &= ~PORT_PULLUPEN_bm;


	PORTD_PIN5CTRL = PORT_ISC_INPUT_DISABLE_gc;              // disable digital input buffer on A7 (AIN5)

	//ADC0.CTRLC = ADC_PRESC_DIV4_gc /* CLK_PER divided by 4 */
	//	| ADC_REFSEL_INTREF_gc; /* Internal reference */

	ADC0_CTRLC = ADC_PRESC_DIV32_gc | ADC_REFSEL_VDDREF_gc | ADC_SAMPCAP_bm; // reduced capacitance, Vdd ref, prescaler of 32

	ADC0.CTRLA = ADC_ENABLE_bm /* ADC Enable: enabled */
		| ADC_RESSEL_10BIT_gc; /* 10-bit mode */

	/* Select ADC channel */
	ADC0.MUXPOS = ADC_MUXPOS_AIN5_gc;

	/* Enable FreeRun mode */
	ADC0.CTRLA |= ADC_FREERUN_bm;
}
uint16_t ADC0_read(void)
{
	/* Clear the interrupt flag by writing 1: */
	ADC0.INTFLAGS = ADC_RESRDY_bm;

	return ADC0.RES;
}
void ADC0_start(void)
{
	/* Start conversion */
	ADC0.COMMAND = ADC_STCONV_bm;
}
bool ADC0_conersionDone(void)
{
	return (ADC0.INTFLAGS & ADC_RESRDY_bm);
}
void setup() {
	pinMode(IO_RELAY, OUTPUT);
	digitalWrite(IO_RELAY, 1);

	ADC0_init();
	ADC0_start();
}

time_t lastMillis = 0;

void loop() {
	if (ADC0_conersionDone())
	{
		uint16_t adcVal = ADC0_read();
		Serial.println(adcVal);

		auto currentMillis = millis();
		if (currentMillis - lastMillis > (1000 / 50)) {
			Serial.println("CYCLE");
			lastMillis = currentMillis;
		}
		/* In FreeRun mode, the next conversion starts automatically */
	}
}

#elif 0

void setup() {
	Serial.begin(115200);
	//Init
	//PORTD_PIN4CTRL = 0x04;              // disable digital input buffer on A6 (AIN4)
	PORTD_PIN5CTRL = 0x04;              // disable digital input buffer on A7 (AIN5)
	ADC0_CTRLA = ADC_RESSEL_10BIT_gc;   // 10-bit resolution
	ADC0_CTRLC = 0x54;                  // reduced capacitance, Vdd ref, prescaler of 32
	// ADC0_MUXPOS = 0x04;                 // select A6 (AIN4)
	ADC0_MUXPOS = ADC_MUXPOS_AIN5_gc;                 // select A7 (AIN5)
	ADC0_CTRLA |= ADC_ENABLE_bm | ADC_FREERUN_bm;        // turn ADC on, in free running mode
	// This is here already because we enable free running mode.
	ADC0_COMMAND |= ADC_STCONV_bm;         // start a conversion

	pinMode(IO_RELAY, OUTPUT);
	digitalWrite(IO_RELAY, 1);
}

time_t lastMillis = 0;
volatile uint16_t adcVal = 0;
volatile bool dirty = false;

void loop() {
	//Read
	//ADC0_COMMAND |= ADC_STCONV_bm;         // start a conversion
	while (ADC0.INTFLAGS & ADC_RESRDY_bm);  // wait while busy
	uint16_t adcVal = ADC0_RES;           // get ADC value
	Serial.println(adcVal);

	auto currentMillis = millis();
	if (currentMillis - lastMillis > (1000 / 50)) {
		Serial.println("CYCLE");
		lastMillis = currentMillis;
	}
}

#elif 1

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

AMeter aMeter(MV_PER_AMPERE, FREQUENCY, analogTryRead);

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

#elif 0

constexpr int valueRange = 64;
uint16_t values[valueRange * 2 + 1];

void printValues(int samples) {
	for (int i = 0; i < ARRAY_LENGTH(values); i++) {
		if (i > 0) {
			Serial.print(' ');
		}
		auto value = (int)(((float)values[i] / (float)samples) * 100);
		if (value < 10) {
			Serial.print(' ');
		}
		Serial.print(value);
		values[i] = 0;
	}

	Serial.println();
}

void printGraph(int samples) {
	auto max = values[0];
	for (int i = 1; i < ARRAY_LENGTH(values); i++) {
		if (values[i] > max) {
			max = values[i];
		}
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < ARRAY_LENGTH(values); j++) {
			auto value = (int)(((float)values[j] / (float)max) * 100) - 1;
			if (value < i * 10 || value >= (i + 1) * 10) {
				Serial.print(' ');
			}
			else if (value < i * 10 + 5) {
				Serial.print('.');
			}
			else {
				Serial.print('*');
			}
		}
		Serial.println();
	}
}

void loop() {
	auto midPoint = ACS.getMidPoint();

	auto start = millis();
	//constexpr auto sampleInterval = 1000 / 50;
	constexpr auto sampleInterval = 500;
	auto samples = 0;

	while (millis() - start < sampleInterval) {
		samples++;

		auto sample = analogRead(0);

		auto index = sample - (int)midPoint + valueRange;
		if (index >= 0 && index < ARRAY_LENGTH(values)) {
			values[index]++;
		}
	}

	printGraph(samples);
	printValues(samples);
}

#elif 1

void setup() {
	LOG_BEGIN();

	ACS.autoMidPoint();
}

void loop() {
	auto m1 = ACS.mA_AC(50, 5);
	auto m2 = ACS.mA_AC_sampling(50, 5);
	Serial.print("mA:\t");
	Serial.print(m1, 2);
	Serial.print("\t\t");
	Serial.println(m2, 2);
	delay(1000);
}

#elif 0

float getAverage(float* values, int count) {
	float result = 0;
	for (int i = 0; i < count; i++) {
		result += values[i];
	}
	return result / (float)count;
}

// perform bubble sort
void bubbleSort(float* array, int size) {

	// loop to access each array element
	for (int step = 0; step < size; ++step) {

		// loop to compare array elements
		for (int i = 0; i < size - step; ++i) {

			// compare two adjacent elements
			// change > to < to sort in descending order
			if (array[i] > array[i + 1]) {

				// swapping elements if elements
				// are not in the intended order
				auto temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}

float calculateSD(float* data, int count) {
	float mean = getAverage(data, count);
	float standardDeviation = 0.0;

	for (int i = 0; i < count; ++i) {
		standardDeviation += pow(data[i] - mean, 2);
	}

	return sqrt(standardDeviation / 10);
}

volatile uint16_t samples = 0;
volatile float sumSquared = 0;

void getSample() {
	samples++;
	int value = analogRead(A0);
	if (/* _suppresNoise */ false)  //  average 2 samples.
	{
		value = (value + analogRead(A0)) / 2;
	}
	float current = value - ACS.getMidPoint();
	sumSquared += (current * current);
}

float mA_AC_sampling()
{
	auto sum = sqrt(sumSquared / samples);

	float mA = sum * ACS.getmAPerStep();

	DEBUG(sum, ", ", sumSquared, ", ", samples, ", ", ACS.getmAPerStep());

	sumSquared = 0;
	samples = 0;

	return mA;
}

int index = 0;
constexpr int count = 50;
float values[count];

uint32_t start = 0;

void loop() {
	auto frequency = 50.0f;
	uint32_t period = round(1000000UL / frequency);
	auto currentMicros = micros();

	if (currentMicros - start >= period) {
		start = currentMicros;

		auto sample = mA_AC_sampling();
		DEBUG(sample);
		values[index++] = sample;

		if (index >= count) {
			index = 0;

			float average = getAverage(values, count);
			//DEBUG("x1");
			float standardDeviation = calculateSD(values, count);
			//DEBUG("x2");
			bubbleSort(values, count);
			//DEBUG("x3");
			float percentile50 = values[count / 2];
			//DEBUG("x4");
			float percentile95 = values[(int)((float)count * .95)];
			//DEBUG("x5");

			Serial.print(average, 2);
			Serial.print("\t");
			Serial.print(standardDeviation, 2);
			Serial.print("\t");
			Serial.print(percentile50, 2);
			Serial.print("\t");
			Serial.print(percentile95, 2);
			Serial.print("\n");
		}
}
}

#endif

// -- END OF FILE --