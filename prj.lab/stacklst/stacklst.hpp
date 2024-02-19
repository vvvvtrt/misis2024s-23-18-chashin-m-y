#pragma once
#ifndef STACKLST_HPP
#define STACKLST_HPP

#include<iostream>
#include<algorithm>
#include<complex/complex.hpp>

class StackLst {
public:
	StackLst() = default;
	StackLst(const StackLst& s);

	~StackLst();

	[[nodiscard]] StackLst& operator=(const StackLst& s) noexcept;

	void Push(const Complex& num);
	void Pop() noexcept;
	[[nodiscard]] bool IsEmpty() noexcept;
	[[nodiscard]] Complex& Top();
	void Clear() noexcept;
	

private:
	struct Node
	{
		Complex val;
		Node* next;

		Node(const Complex& data) : val(data), next(nullptr) {}
	};

	Node* head_ = nullptr;
};

#endif // !STACK_HPP
