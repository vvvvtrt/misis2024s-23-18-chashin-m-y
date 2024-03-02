#pragma once
#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include<iostream>
#include<algorithm>
#include<complex/complex.hpp>

class QueueArr {
public:
	[[nodiscard]] QueueArr() = default;
	[[nodiscard]] QueueArr(const QueueArr& s);

	[[nodiscard]] ~QueueArr() = default;

	[[nodiscard]] QueueArr& operator=(const QueueArr& s) noexcept;

	void Push(const Complex& num);
	void Pop() noexcept;
	[[nodiscard]] bool IsEmpty() noexcept;
	[[nodiscard]] Complex& Top();
	void Clear() noexcept;
private:
	Complex* head_ = nullptr;
	Complex* tail_ = nullptr;

	std::ptrdiff_t capacity_ = 0;

	std::unique_ptr<Complex[]> data_(new Complex[capacity_]);
};

#endif // !QUEUEARR_HPP