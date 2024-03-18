#pragma once
#ifndef STACKARR_HPP
#define STACKARR_HPP

#include<iostream>
#include<algorithm>
#include<complex/complex.hpp>

class StackArr {
public:
	[[nodiscard]] StackArr() = default;
	[[nodiscard]] StackArr(const StackArr& s);

	[[nodiscard]] ~StackArr() {
		delete[] _data;
	}

	[[nodiscard]] StackArr& operator=(const StackArr& s) noexcept;

	void Push(const Complex& num);
	void Pop() noexcept;
	[[nodiscard]] bool IsEmpty() noexcept;
	[[nodiscard]] Complex& Top();
	[[nodiscard]] const Complex& Top() const;
	void Clear() noexcept;

private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t i_top_ = 0;

	Complex* data_ = new Complex[size_ + 1];
};

#endif // !STACK_HPP
