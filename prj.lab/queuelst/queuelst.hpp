#pragma once
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

#include<iostream>
#include<algorithm>
#include<complex/complex.hpp>

class QueueLst {
public:
	[[nodiscard]] QueueLst() = default;
	[[nodiscard]] QueueLst(const QueueLst& s);
	[[nodiscard]] QueueLst(QueueLst&& rhs) noexcept;

	[[nodiscard]] ~QueueLst();

	[[nodiscard]] QueueLst& operator=(const QueueLst& s) noexcept;
	[[nodiscard]] QueueLst& operator=(QueueLst&& rhs) noexcept;

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
	Node* tail_ = nullptr;
};

#endif // !QUEUELST_HPP
