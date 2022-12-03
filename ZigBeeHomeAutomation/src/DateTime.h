#pragma once

class DateTime {
	uint32_t _date;
	uint32_t _time;

public:
	DateTime() : _date(0), _time(0) {
	}

	DateTime(uint32_t date, uint32_t time) : _date(date), _time(time) {
	}

	uint32_t getDate() {
		return _date;
	}

	uint32_t getTime() {
		return _time;
	}
};
