#pragma once

class DateTime {
	uint32_t _date;
	uint32_t _time;

public:
	DateTime() : _date(0), _time(0) {
	}

	DateTime(uint32_t date, uint32_t time) : _date(date), _time(time) {
	}

	uint32_t getDate() const {
		return _date;
	}

	uint32_t getTime() const {
		return _time;
	}

	uint16_t getYear() const {
		return 1900 + (_date >> 24);
	}
	uint8_t getMonth() const {
		return (_date >> 16) & 0xff;
	}
	uint8_t getDay() const {
		return (_date >> 8) & 0xff;
	}
	uint8_t getDayOfWeek() const {
		return _date & 0xff;
	}
	uint8_t getHours() const {
		return _time >> 24;
	}
	uint8_t getMinutes() const {
		return (_time >> 16) & 0xff;
	}
	uint8_t getSeconds() const {
		return (_time >> 8) & 0xff;
	}
	uint8_t getMilliseconds() const {
		return (_time & 0xff) * 10;
	}

	bool operator ==(const DateTime& rhs) const {
		return _date == rhs._date && _time == rhs._time;
	}
	bool operator !=(const DateTime& rhs) const {
		return !operator ==(rhs);
	}
};
