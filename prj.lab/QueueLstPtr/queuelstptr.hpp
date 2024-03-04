#ifndef QUEUELSTPTR_HPP
#define QUEUELSTPTR_HPP

#include <iostream>

class QueueLstPtr {
public:
	[[nodiscard]] QueueLstPtr() = default;
	[[nodiscard]] QueueLstPtr(const QueueLstPtr& q);

	~QueueLstPtr();

	[[nodiscard]] QueueLstPtr& operator=(const QueueLstPtr& q) noexcept;

	void Push(const float val);
	void Pop() noexcept;
	void Clear() noexcept;
	[[nodiscard]] bool IsEmpty() noexcept;
	[[nodiscard]] float& Top();


private:
	struct Node {
		float val_;
		Node* next_;

		Node(float& val, Node* next) : val_(val), next_(next) {}
		~Node() = default;
	};

	Node* head_ = nullptr;

};

#endif // !QUEUELSTPTR_HPP
