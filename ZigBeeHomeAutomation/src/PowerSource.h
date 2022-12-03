#pragma once

enum class PowerSource {
	Unknown = 0x00,
	MainsSinglePhase = 0x01,
	Mains3Phase = 0x02,
	Battery = 0x03,
	DCSource = 0x04,
	EmergencyMainsConstantlyPowered = 0x05,
	EmergencyMainsAndTransferSwitch = 0x06,
};
