#pragma once

#if defined(ARDUINO)
// Placement new is not defined by standard for Arduino. See
// https://forum.arduino.cc/t/reason-for-missing-new-delete/73429/7 for more info.
inline void* operator new(size_t, void* ptr) {
	return ptr;
}
#endif

template <typename T>
class ArrayList {
#if defined(__AVR__)
	typedef uint16_t size_type;
#else
	typedef size_t size_type;
#endif

	static constexpr size_type DEFAULT_CAPACITY = 2;

	T* _data;
	size_type _size;
	size_type _capacity;

public:
	typedef T* iterator;
	typedef const T* const_iterator;

	ArrayList() : _data(nullptr), _size(0), _capacity(0) {
		reserve(DEFAULT_CAPACITY);
	}

	ArrayList(size_type capacity) : _data(nullptr), _size(0), _capacity(0) {
		reserve(capacity);
	}

	ArrayList(const ArrayList&) = delete;
	ArrayList(ArrayList&&) = delete;

	~ArrayList() {
		for (auto i = 0; i < _size; i++) {
			_data[i].~T();
		}

		if (_data) {
			free(_data);
			_data = nullptr;
		}
	}

	ArrayList& operator=(const ArrayList&) = delete;
	ArrayList& operator=(ArrayList&&) = delete;

	void add(const T& item) {
		reserve(_size + 1);
		new (&_data[_size++]) T(item);
	}

	bool insert(size_type index, const T& item) {
		if (index > _size) {
			return false;
		}

		if (index == _size) {
			add(item);
		}
		else {
			reserve(_size + 1);
			memmove(_data + index + 1, _data + index, (_size - index) * sizeof(T));

			new (&_data[index]) T(item);
			_size++;
		}

		return true;
	}

	bool remove(const T& value) {
		auto index = indexOf(value);
		if (index == -1) {
			return false;
		}

		removeAt(index);
		return true;
	}

	bool removeAt(size_type index) {
		if (index >= _size) {
			return false;
		}

		_data[index].~T();

		if (index < _size - 1) {
			memmove(_data + index, _data + index + 1, (_size - index - 1) * sizeof(T));
		}

		_size--;

		return true;
	}

	void clear() {
		_size = 0;
	}

	int indexOf(const T& value) const {
		for (int i = 0; i < _size; i++) {
			if (_data[i] == value) {
				return i;
			}
		}
		return -1;
	}

	int lastIndexOf(const T& value) const {
		for (int i = int(_size); i >= 0; i--) {
			if (_data[i] == value) {
				return i;
			}
		}
		return -1;
	}

	bool contains(const T& value) const {
		return indexOf(value) != -1;
	}

	const T& operator[](size_type index) const { return _data[index]; }
	T& operator[](size_type index) { return _data[index]; }

	size_type size() const { return _size; }
	size_type capacity() const { return _capacity; }

	iterator begin() { return &_data[0]; }
	const_iterator begin() const { return &_data[0]; }
	iterator end() { return &_data[_size]; }
	const_iterator end() const { return &_data[_size]; }

private:
	void reserve(size_type capacity) {
		if (capacity <= _capacity) {
			return;
		}
		if (capacity < _capacity * 2) {
			capacity = _capacity * 2;
		}

		auto data = (T*)malloc(capacity * sizeof(T));

		if (_data) {
			// Only copy the memory that's in use.
			memcpy(data, _data, _size * sizeof(T));
			free(_data);
		}

		_data = data;
		_capacity = capacity;
	}
};
