#include "stackarr.hpp"

StackArr::StackArr(const StackArr& s) {
	Complex* newdata_ = new Complex[s.i_top_];
	std::copy(s.data_, s.data_ + s.size_, newdata_);
	delete[] data_;
	
	size_ = s.size_;
	i_top_ = s.i_top_;
	data_ = newdata_;
}

StackArr& StackArr::operator=(const StackArr& s) noexcept {
	Complex* newdata_ = new Complex[s.i_top_];
	std::copy(s.data_, s.data_ + s.size_, newdata_);
	delete[] data_;

	size_ = s.size_;
	i_top_ = s.i_top_;
	data_ = newdata_;

	return *this;
}

void StackArr::Push(const Complex& num) {
	if (size_ >= i_top_) {
		Complex* newdata_ = new Complex[size_ * 2];
		std::copy(data_, data_ + size_, newdata_);
		delete[] data_;

		i_top_ = i_top_ * 2;
		data_ = newdata_;
	}

	data_[size_] = num;
	size_++;
}

void StackArr::Pop() noexcept {
	if (size_ > 0) {
		size_--;
	}
}

bool StackArr::IsEmpty() noexcept {
	return not(static_cast<bool>(size_));
}

Complex& StackArr::Top() {
	if (size_) {
		return data_[size_ - 1];
	}
	else {
		throw::std::invalid_argument("Stack of zero size");
	}
}

const Complex& StackArr::Top() const {
	if (size_) {
		return data_[size_ - 1];
	}
	else {
		throw::std::invalid_argument("Stack of zero size");
	}
}

void StackArr::Clear() noexcept {
	i_top_ = 0;
}