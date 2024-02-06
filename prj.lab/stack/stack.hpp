#ifndef STACK_HPP
#define STACK_HPP

#include<iostream>
#include<algorithm>
#include<complex/complex.hpp>

class Stack {
public:
	Stack() = default;
	Stack(const Stack& s);
	Stack(std::ptrdiff_t size);

	~Stack() = default;

	[[nodiscard]] Stack& operator=(const Stack& s) noexcept;

	void Push(const Complex& num);
	void Pop() noexcept;
	bool IsEmpty() noexcept;
	Complex& Top();

private:
	std::ptrdiff_t _size = 0;
	std::ptrdiff_t _capacity = 0;

	Complex* _data = new Complex[size_ + 1];
};

#endif // !STACK_HPP
