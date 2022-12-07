#pragma once

template <typename T>
class ArrayList {
	static constexpr size_t DEFAULT_CAPACITY = 2;

	T* _data;
	size_t _size;
	size_t _capacity;

public:
	typedef T* iterator;
	typedef const T* const_iterator;

	ArrayList() : _data(nullptr), _size(0), _capacity(0) {
		reserve(DEFAULT_CAPACITY);
	}

	ArrayList(size_t capacity) : _data(nullptr), _size(0), _capacity(0) {
		reserve(capacity);
	}

	ArrayList(const ArrayList&) = delete;
	ArrayList(ArrayList&&) = delete;

	~ArrayList() {
		delete _data;
	}

	ArrayList& operator=(const ArrayList&) = delete;
	ArrayList& operator=(ArrayList&&) = delete;

	void add(const T& item) {
		reserve(_size + 1);
		_data[_size++] = item;
	}

	bool insert(size_t index, const T& item) {
		if (index > _size) {
			return false;
		}

		if (index == _size) {
			add(item);
		}
		else {
			reserve(_size + 1);
			memmove(_data + index + 1, _data + index, (_size - index) * sizeof(T));

			_data[index] = item;
			_size++;
		}

		return true;
	}

	T remove(size_t index) {
		auto result = _data[index];

		removeAt(index);

		return result;
	}

	bool removeAt(size_t index) {
		if (index >= _size) {
			return false;
		}

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
		for (int i = _size; i >= 0; i--) {
			if (_data[i] == value) {
				return i;
			}
		}
		return -1;
	}

	bool contains(const T& value) const {
		return indexOf(value) != -1;
	}

	const T& operator[](size_t index) const { return _data[index]; }
	T& operator[](size_t index) { return _data[index]; }

	size_t size() const { return _size; }
	size_t capacity() const { return _capacity; }

	iterator begin() { return &_data[0]; }
	const_iterator begin() const { return &_data[0]; }
	iterator end() { return &_data[_size]; }
	const_iterator end() const { return &_data[_size]; }

private:
	void reserve(size_t capacity) {
		if (capacity <= _capacity) {
			return;
		}
		if (capacity < _capacity * 2) {
			capacity = _capacity * 2;
		}

		auto data = new T[capacity];
		// Only copy the memory that's in use.
		memcpy(data, _data, _size * sizeof(T));
		delete _data;

		_data = data;
		_capacity = capacity;
	}
};
