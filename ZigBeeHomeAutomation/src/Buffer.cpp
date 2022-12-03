#include "ZigBeeHomeAutomation.h"

Buffer::Buffer(): _data(nullptr), _length(0) {
}

Buffer::Buffer(const uint8_t* data, int length) {
	_length = length;
	_data = new uint8_t[length];
	memcpy(_data, data, length);
}

Buffer::Buffer(const Buffer& other): Buffer(other._data, other._length) {
}

Buffer::Buffer(Buffer&& other) noexcept {
	_data = other._data;
	_length = other._length;

	other._data = nullptr;
	other._length = 0;
}

Buffer::~Buffer() {
	delete _data;
}

Buffer& Buffer::operator=(const Buffer& other) {
	if (this == &other) {
		return *this;
	}

	delete _data;

	_data = new uint8_t[other._length];
	_length = other._length;

	memcpy(_data, other._data, other._length);

	return *this;
}

Buffer& Buffer::operator=(Buffer&& other) noexcept {
	const auto data = _data;
	_data = other._data;
	other._data = data;

	auto length = _length;
	_length = other._length;
	other._length = length;

	return *this;
}

void Buffer::getBytes(uint8_t* data) const {
	if (_data) {
		memcpy(data, _data, _length);
	}
}
