#include "stacklst.hpp"


StackLst::StackLst(const StackLst& s) {
	Node* go_back_s = s.head;
	head = new Node(go_back_s->_data);
	Node* go_back = head;

	while (go_back_s->next != nullptr) {
		go_back_s = go_back_s->next;
		go_back->next = new Node(go_back_s->_data);
		go_back = go_back->next;
	}
}


void StackLst::Push(const Complex& num) {
	Node* copy = head;
	head = new Node(num);
	head->next = copy;
}

void StackLst::Pop() noexcept {
	if (head != nullptr) {
		Node copy = *head;
		delete head;
		head = copy.next;
	}
}

Complex& StackLst::Top() {
	if (head == nullptr) {
		throw::std::logic_error("Stack of zero size");
	}

	return head->_data;
}

bool StackLst::IsEmpty() noexcept {
	return head == nullptr;
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