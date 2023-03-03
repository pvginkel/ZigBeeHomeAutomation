#include <ZigBeeHomeAutomation.h>
#include "Light.h"

RGB hsi2rgb(float H, float S, float I) {
	float r, g, b;
	H = fmodf(H, 360); // cycle H around to 0-360 degrees
	H = 3.14159f * H / 180.0f; // Convert to radians.
	S = S > 0 ? (S < 1 ? S : 1) : 0; // clamp S and I to interval [0,1]
	I = I > 0 ? (I < 1 ? I : 1) : 0;

	// Math! Thanks in part to Kyle Miller.
	if (H < 2.09439f) {
		r = I / 3 * (1 + S * cosf(H) / cosf(1.047196667f - H));
		g = I / 3 * (1 + S * (1 - cosf(H) / cosf(1.047196667f - H)));
		b = I / 3 * (1 - S);
	}
	else if (H < 4.188787f) {
		H = H - 2.09439f;
		g = I / 3 * (1 + S * cosf(H) / cos(1.047196667f - H));
		b = I / 3 * (1 + S * (1 - cosf(H) / cosf(1.047196667f - H)));
		r = I / 3 * (1 - S);
	}
	else {
		H = H - 4.188787f;
		b = I / 3 * (1 + S * cosf(H) / cosf(1.047196667f - H));
		r = I / 3 * (1 + S * (1 - cosf(H) / cosf(1.047196667f - H)));
		g = I / 3 * (1 - S);
	}

	return { r, g, b };
}

uint16_t mired2kelvin(uint16_t mired) {
	return 1000000 / mired;
}

uint16_t kelvin2mired(uint16_t kelvin) {
	return 1000000 / kelvin;
}

float scaleLightLevel(float level, float minimumLevel, float maximumLevel) {
	if (level > 0 && (minimumLevel != 0.0f || maximumLevel != 1.0f)) {
		return
			minimumLevel +
			level * (maximumLevel - minimumLevel);
	}

	return level;
}
