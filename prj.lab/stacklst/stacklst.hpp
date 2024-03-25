#pragma once
#ifndef STACKLST_HPP
#define STACKLST_HPP

#include<iostream>
#include<algorithm>
#include<complex/complex.hpp>

class StackLst {
public:
	[[nodiscard]] StackLst() = default;
	[[nodiscard]] StackLst(const StackLst& s);
	[[nodiscard]] StackLst(StackLst&& src) noexcept;


	~StackLst();

	[[nodiscard]] StackLst& operator=(const StackLst& s) noexcept;
	[[nodiscard]] StackLst& operator=(StackLst&& src) noexcept;

	void Push(const Complex& num);
	void Pop() noexcept;
	[[nodiscard]] bool IsEmpty() noexcept;
	[[nodiscard]] Complex& Top();
	[[nodiscard]] const Complex& Top() const;
	void Clear() noexcept;
	

private:
	struct Node
	{
		Complex val;
		Node* next;

		Node(const Complex& data) : val(data), next(nullptr) {}
		~Node() = default;
	};

	Node* head_ = nullptr;
};

#endif // !STACK_HPP
