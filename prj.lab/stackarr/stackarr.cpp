#include "stackarr.hpp"

StackArr::StackArr(const StackArr& s) {
	Complex* new_data = new Complex[s.i_top_];
	std::copy(s._data, s._data + s._size, new_data);
	delete[] _data;
	
	_size = s._size;
	i_top_ = s.i_top_;
	_data = new_data;
}

StackArr& StackArr::operator=(const StackArr& s) noexcept {
	Complex* new_data = new Complex[s.i_top_];
	std::copy(s._data, s._data + s._size, new_data);
	delete[] _data;

	_size = s._size;
	i_top_ = s.i_top_;
	_data = new_data;

	return *this;
}

void StackArr::Push(const Complex& num) {
	if (_size >= i_top_) {
		Complex* new_data = new Complex[_size + 10];
		std::copy(_data, _data + _size, new_data);
		delete[] _data;

		i_top_ = i_top_ + 10;
		_data = new_data;
	}

	_data[_size] = num;
	_size++;
}

void StackArr::Pop() noexcept {
	if (_size > 0) {
		_size--;
	}
}

bool StackArr::IsEmpty() noexcept {
	return not(static_cast<bool>(_size));
}

Complex& StackArr::Top() {
	if (_size) {
		return _data[_size - 1];
	}
	else {
		throw::std::invalid_argument("Stack of zero size");
	}
}

const Complex& StackArr::Top() const {
	if (_size) {
		return _data[_size - 1];
	}
	else {
		throw::std::invalid_argument("Stack of zero size");
	}
}

void StackArr::Clear() noexcept {
	i_top_ = 0;
}