#pragma once

class Buffer
{
	uint8_t* _data;
	int _length;

public:
	Buffer();
	Buffer(const uint8_t* data, int length);
	Buffer(const Buffer& other);
	Buffer(Buffer&& other) noexcept;
	~Buffer();
	Buffer& operator=(const Buffer& other);
	Buffer& operator=(Buffer&& other) noexcept;

	int length() const {
		return _length;
	}

	void getBytes(uint8_t* data) const;
};
