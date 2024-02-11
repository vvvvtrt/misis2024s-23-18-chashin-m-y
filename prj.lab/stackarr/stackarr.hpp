#ifndef STACK_HPP
#define STACK_HPP

#include<iostream>
#include<algorithm>
#include<complex/complex.hpp>

class StackArr {
public:
	StackArr() = default;
	StackArr(const StackArr& s);

	~StackArr() = default;

	[[nodiscard]] StackArr& operator=(const StackArr& s) noexcept;

	void Push(const Complex& num);
	void Pop() noexcept;
	bool IsEmpty() noexcept;
	Complex& Top();

private:
	std::ptrdiff_t _size = 0;
	std::ptrdiff_t _capacity = 0;

	Complex* _data = new Complex[_size + 1];
};

#endif // !STACK_HPP
