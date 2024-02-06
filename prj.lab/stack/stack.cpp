#include "stack.hpp"

Stack::Stack(const Stack& s) {
	Complex* new_data = new Complex[s.capacity_];
	std::copy(s._data, s._data + s._size, new_data);
	delete[] _data;
	
	_size_ = s._size;
	_capacity = s._capacity;
	_data = new_data;
}

Stack::Stack(std::ptrdiff_t size) {
	Complex* new_data = new Complex[size + 10];
	std::copy(_data, _data + _size, new_data);
	delete[] _data;

	_size_ = size;
	_capacity = capacity + 10;
	_data = new_data;
}

Stack::Stack& operator=(const Stack& s) noexcept {
	Complex* new_data = new Complex[s.capacity_];
	std::copy(s._data, s._data + s._size, new_data);
	delete[] _data;

	_size_ = s._size;
	_capacity = s._capacity;
	_data = new_data;
}

Stack::void Push(const Complex& num) {
	if (_size < _capacity) {
		_data[_size] = num;
		_size++;
	}
	else {
		Complex* new_data = new Complex[_size + 10];
		std::copy(_data, _data + _size, new_data);
		delete[] _data;

		_size++;
		_capacity = _capacity + 10;
		_data = new_data;
	}
}

Stack::bool IsEmpty() {
	return static_cast<bool>(_size);
}

Stack::Complex& Top() {
	if (_size) {
		return _data[_size];
	}
	else {
		throw::std::invalid_argument("Stack of zero size");
	}
}