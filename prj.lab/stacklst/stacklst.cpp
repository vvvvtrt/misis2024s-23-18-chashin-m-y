#include "stacklst.hpp"


StackLst::StackLst(const StackLst& s) {
	Node* go_back_s = s.head_;
	head_ = new Node(go_back_s->val);
	Node* go_back = head_;

	while (go_back_s->next != nullptr) {
		go_back_s = go_back_s->next;
		go_back->next = new Node(go_back_s->val);
		go_back = go_back->next;
	}
}


void StackLst::Push(const Complex& num) {
	Node* copy = head_;
	head_ = new Node(num);
	head_->next = copy;
}

void StackLst::Pop() noexcept {
	if (head_ != nullptr) {
		Node copy = *head_;
		delete head_;
		head_ = copy.next;
	}
}

Complex& StackLst::Top() {
	if (head_ == nullptr) {
		throw::std::logic_error("Stack of zero size");
	}

	return head_->val;
}

bool StackLst::IsEmpty() noexcept {
	return head_ == nullptr;
}

void StackLst::Clear() noexcept {
	while (! IsEmpty()) {
		Pop();
	}
}

StackLst::~StackLst() {
	while (! IsEmpty()) {
		Pop();
	}
}

StackLst& StackLst::operator=(const StackLst& s) noexcept {
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