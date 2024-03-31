#pragma once
#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include<iostream>
#include<algorithm>
#include<complex/complex.hpp>

class QueueArr {
public:
	[[nodiscard]] QueueArr() = default;
	[[nodiscard]] QueueArr(const QueueArr& rhs);
	[[nodiscard]] QueueArr(QueueArr&& d) noexcept;

	[[nodiscard]] ~QueueArr() = default;

	[[nodiscard]] QueueArr& operator=(const QueueArr& rhs) noexcept;
	[[nodiscard]] QueueArr& operator=(QueueArr&& d) noexcept;

	void Push(const Complex& c);
	void Pop() noexcept;

	[[nodiscard]] bool IsEmpty() noexcept;
	[[nodiscard]] Complex& Top();
	[[nodiscard]] const Complex& Top() const;

	void Clear() noexcept;
	std::ptrdiff_t Count() const;
private:
	std::ptrdiff_t head_ = -1;
	std::ptrdiff_t tail_ = -1;

	std::ptrdiff_t capacity_ = 0;

	std::unique_ptr<Complex[]> data_ = std::make_unique<Complex[]>(capacity_);
};

#endif // !QUEUEARR_HPP