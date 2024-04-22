#pragma once

#ifndef QUEUEARR_HPP
#define QUEUEARR_HPP

#include <complex/complex.hpp>

#include <cstddef>
#include <memory>

class QueueArr {
public:
	QueueArr() = default;
	QueueArr(const QueueArr& rhs);
	QueueArr(QueueArr&& rhs) noexcept;

	~QueueArr();

	QueueArr& operator=(const QueueArr& rhs);
	QueueArr& operator=(QueueArr&& rhs) noexcept;

	bool IsEmpty() const noexcept;

	void Pop() noexcept;

	void Push(const Complex& val);

	Complex& Top();
	const Complex& Top() const;

	void Clear() noexcept;

private:
	std::unique_ptr<Complex[]> data_ = nullptr;
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t head_ = -1;
	std::ptrdiff_t tail_ = -1;
	std::ptrdiff_t Count() const;
};

#endif