#pragma once
#ifndef STACKLST_HPP
#define STACKLST_HPP

#include<iostream>
#include<algorithm>
#include<complex/complex.hpp>

template<class T>
class StackLstT {
public:
	[[nodiscard]] StackLstT() = default;
	[[nodiscard]] StackLstT(const StackLstT& s);
	[[nodiscard]] StackLstT(StackLstT&& src) noexcept;


	~StackLstT();

	[[nodiscard]] StackLstT& operator=(const StackLstT& s) noexcept;
	[[nodiscard]] StackLstT& operator=(StackLstT&& src) noexcept;

	void Push(const T& num);
	void Pop() noexcept;
	[[nodiscard]] bool IsEmpty() noexcept;
	[[nodiscard]] T& Top();
	[[nodiscard]] const T& Top() const;
	void Clear() noexcept;


private:
	struct Node
	{
		T val;
		Node* next;

		Node(const T& data) : val(data), next(nullptr) {}
		~Node() = default;
	};

	Node* head_ = nullptr;
};


template<class T>
StackLstT<T>::StackLstT(const StackLstT<T>& s) {
	Node* go_back_s = s.head_;
	head_ = new Node(go_back_s->val);
	Node* go_back = head_;

	while (go_back_s->next != nullptr) {
		go_back_s = go_back_s->next;
		go_back->next = new Node(go_back_s->val);
		go_back = go_back->next;
	}
}

template<class T>
void StackLstT<T>::Push(const T<T>& num) {
	Node* copy = head_;
	head_ = new Node(num);
	head_->next = copy;
}

template<class T>
void StackLstT<T>::Pop() noexcept {
	if (head_ != nullptr) {
		Node copy = *head_;
		delete head_;
		head_ = copy.next;
	}
}

template<class T>
T& StackLstT<T>::Top() {
	if (head_ == nullptr) {
		throw::std::logic_error("Stack of zero size");
	}

	return head_->val;
}

template<class T>
const T& StackLstT<T>::Top() const {
	if (head_ == nullptr) {
		throw::std::logic_error("Stack of zero size");
	}

	return head_->val;
}

template<class T>
bool StackLstT<T>::IsEmpty() noexcept {
	return head_ == nullptr;
}

template<class T>
void StackLstT<T>::Clear() noexcept {
	while (!IsEmpty()) {
		Pop();
	}
}

template<class T>
StackLstT<T>::~StackLstT() {
	while (!IsEmpty()) {
		Pop();
	}
}

template<class T>
StackLstT<T>& StackLstT<T>::operator=(const StackLstT<T>& s) noexcept {
	Clear();

	Node* go_back_s = s.head_;
	head_ = new Node(go_back_s->val);
	Node* go_back = head_;

	while (go_back_s->next != nullptr) {
		go_back_s = go_back_s->next;
		go_back->next = new Node(go_back_s->val);
		go_back = go_back->next;
	}

	return *this;
}

template<class T>
StackLstT<T>& StackLstT<T>::operator=(StackLstT<T>&& src) noexcept {
	if (this != &src) {
		std::swap(head_, src.head_);
	}
	return *this;
}

template<class T>
StackLstT<T>::StackLstT(StackLstT<T>&& src) noexcept {
	std::swap(head_, src.head_);
}


#endif // !STACK_HPP
