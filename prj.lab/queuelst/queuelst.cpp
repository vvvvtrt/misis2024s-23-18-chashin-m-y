#include "QueueLst.hpp"


Complex& QueueLst::Top() {
	if (head_ == nullptr) {
		throw::std::logic_error("Stack of zero size");
	}

	return head_->val;
}

bool QueueLst::IsEmpty() noexcept {
	return head_ == nullptr;
}

void QueueLst::Clear() noexcept {
	while (!IsEmpty()) {
		Pop();
	}
}

QueueLst::~QueueLst() {
	while (!IsEmpty()) {
		Pop();
	}
}

void QueueLst::Push(const Complex& num) {
	if (IsEmpty()) {
		tail_ = new Node(num);
		head_ = tail_;
	}
	else
	{
		tail_->next = new Node(num);
		tail_ = tail_->next;
	}
}

void QueueLst::Pop() noexcept {
	if (head_ != nullptr) {
		Node copy = *head_;
		delete head_;
		head_ = copy.next;

		if (head_ == nullptr)
		{
			tail_ = nullptr;
		}
	}
}

QueueLst& QueueLst::operator=(const QueueLst& s) noexcept {
	Clear();

	Node* go_back_s = s.head_;

	while (go_back_s->next != nullptr) {
		Push(go_back_s->val);
		go_back_s = go_back_s->next;
	}

	tail_ = go_back_s;

	return *this;
}

QueueLst::QueueLst(const QueueLst& s) {
	Node* go_back_s = s.head_;

	while (go_back_s->next != nullptr) {
		Push(go_back_s->val);
		go_back_s = go_back_s->next;
	}

	tail_ = go_back_s;
}