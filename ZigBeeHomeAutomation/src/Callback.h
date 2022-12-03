#pragma once

class Callback {
public:
	using Func = void (*)(uintptr_t);

private:
	Func _func;
	uintptr_t _data;

public:
	Callback() : _func(nullptr), _data((uintptr_t)nullptr) {
	}

	void set(Func func, uintptr_t data) {
		_func = func;
		_data = data;
	}

	bool call() {
		if (_func) {
			_func(_data);
			return true;
		}
		return false;
	}
};

template <typename... Args>
class CallbackArgs {
public:
	using Func = void (*)(Args..., uintptr_t);

private:
	Func _func;
	uintptr_t _data;

public:
	CallbackArgs() : _func(nullptr), _data((uintptr_t)nullptr) {
	}

	void set(Func func, uintptr_t data) {
		_func = func;
		_data = data;
	}

	bool call(Args... args) {
		if (_func) {
			_func(args..., _data);
			return true;
		}
		return false;
	}
};
