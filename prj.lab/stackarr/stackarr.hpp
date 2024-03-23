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
		delete[] data_;
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
	std::ptrdiff_t i_top_ = -1;

	Complex* data_ = nullptr;
};

#endif // !STACK_HPP
