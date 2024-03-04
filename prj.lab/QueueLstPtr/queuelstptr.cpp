#include "queuelstptr.hpp"

bool QueueLstPtr::IsEmpty() noexcept {
	return head_ == nullptr;
}

void QueueLstPtr::Push(const float val) {
	if (IsEmpty()) {
		head_ = new Node(val, nullptr);
		return;
	}

	Node* go_back = head_;
	Node* one_step_to_go_back_save = nullptr;
	while (go_back->next_ != nullptr) {
		if (go_back->val_ <= val) {
			if (one_step_to_go_back_save != nullptr) {
				one_step_to_go_back_save->next_ = new Node(val, one_step_to_go_back_save);
			}
			else {
				head_ = new Node(val, head_);
			}

			return;
		}

		one_step_to_go_back_save = go_back;
		go_back = go_back->next_;
	}
	
	if (go_back->next_ == nullptr) {
		go_back->next_ = new Node(val, nullptr);
	}

}

void QueueLst::Pop() noexcept {
	if (head_ != nullptr) {
		Node copy = *head_;
		delete head_;
		head_ = copy.next;
	}
}

Complex& QueueLst::Top() {
	if (head_ == nullptr) {
		throw::std::logic_error("Stack of zero size");
	}

	return head_->val;
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

QueueLstPtr::QueueLstPtr(const QueueLstPtr& q) {
	Node* go_back_s = q.head_;

	while (go_back_s->next != nullptr) {
		Push(go_back_s->val);
		go_back_s = go_back_s->next;
	}
}

QueueLstPtr& QueueLstPtr::operator=(const QueueLstPtr& q) noexcept {
	if (this * != q) {
		Clear();
		Node* go_back_s = q.head_;

		while (go_back_s->next != nullptr) {
			Push(go_back_s->val);
			go_back_s = go_back_s->next;
		}
	}
}