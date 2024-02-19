#pragma once
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

#include<iostream>
#include<algorithm>
#include<complex/complex.hpp>

class QueueLst {
public:
	QueueLst() = default;
	QueueLst(const QueueLst& s);

	~QueueLst();

	[[nodiscard]] QueueLst& operator=(const QueueLst& s) noexcept;

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

		Node(const Complex& data) : val(val), next(nullptr) {}
	};

	Node* head_ = nullptr;
	Node* tail_ = nullptr;
};

#endif // !QUEUELST_HPP
