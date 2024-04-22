#pragma once

#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <complex/complex.hpp>

#include <cstddef>
#include <memory>

class StackArr {
public:
	StackArr() = default;
	StackArr(const StackArr& rhs);
	StackArr(StackArr&& rhs) noexcept;

	~StackArr();

	StackArr& operator=(const StackArr& rhs);
	StackArr& operator=(StackArr&& rhs) noexcept;

	bool IsEmpty() const noexcept;

	void Pop() noexcept;

	void Push(const Complex& val);

	Complex& Top()&;
	const Complex& Top() const&;

	void Clear() noexcept;

private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t i_top_ = -1;
	std::unique_ptr<Complex[]> data_ = nullptr;
};

#endif