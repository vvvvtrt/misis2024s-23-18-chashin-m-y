#ifndef STACKARR_HPP
#define STACKARR_HPP

#include<iostream>
#include<algorithm>
#include<complex/complex.hpp>

class StackArr {
public:
	StackArr() = default;
	StackArr(const StackArr& s);

	~StackArr() {
		delete[] _data;
	}

	[[nodiscard]] StackArr& operator=(const StackArr& s) noexcept;

	void Push(const Complex& num);
	void Pop() noexcept;
	bool IsEmpty() noexcept;
	[[nodiscard]] Complex& Top();
	void Clear() noexcept;

private:
	std::ptrdiff_t _size = 0;
	std::ptrdiff_t i_top_ = 0;

	Complex* _data = new Complex[_size + 1];
};

#endif // !STACK_HPP
