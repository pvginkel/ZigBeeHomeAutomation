#pragma once

#include "Arduino.h"
#include "support.h"

class Buffer {
	uint8_t* _data;
	int _length;

public:
	explicit Buffer(uint8_t* data, int length = 0) : _data(data), _length(length) {
	}

	uint8_t* data() {
		return _data;
	}

	int length() {
		return _length;
	}

	void length(int value) {
		_length = value;
	}

	uint8_t get(int index) {
		return _data[index];
	}

	void set(int index, uint8_t value) {
		_data[index] = value;
	}

	template<typename T>
	T getLe(int index) {
		return packArrayLe<T>(&_data[index]);
	}

	template<typename T>
	T getBe(int index) {
		return packArray<T>(&_data[index]);
	}

	template<typename T>
	void setLe(int index, T value) {
		unpackArrayLe(&_data[index], value);
	}

	template<typename T>
	void setBe(int index, T value) {
		unpackArray(&_data[index], value);
	}
};
