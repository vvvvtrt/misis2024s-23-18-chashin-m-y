#include <stacklst/stacklst.hpp>

StackLst::StackLst(const StackLst& rhs) {
    if (!rhs.head) {
        head = nullptr;
        return;
    }
    Node* rhsPtr = rhs.head.get();
    head = std::make_unique<Node>(rhsPtr->data);
    Node* current = head.get();
    rhsPtr = rhsPtr->next.get();
    while (rhsPtr) {
        current->next = std::make_unique<Node>(rhsPtr->data);
        current = current->next.get();
        rhsPtr = rhsPtr->next.get();
    }
}

StackLst::StackLst(StackLst&& rhs) noexcept : head(std::move(rhs.head)) {
    rhs.head = nullptr;
}

StackLst::~StackLst() noexcept {
    Clear();
}

StackLst& StackLst::operator=(const StackLst& rhs) {
    if (this == &rhs) {
        return *this;
    }
    head = nullptr;
    if (!rhs.head) {
        return *this;
    }
    Node* rhsPtr = rhs.head.get();
    head = std::make_unique<Node>(rhsPtr->data);
    Node* current = head.get();
    rhsPtr = rhsPtr->next.get();
    while (rhsPtr) {
        current->next = std::make_unique<Node>(rhsPtr->data);
        current = current->next.get();
        rhsPtr = rhsPtr->next.get();
    }
    return *this;
}

StackLst& StackLst::operator=(StackLst&& rhs) noexcept {
    if (this == &rhs) {
        return *this;
    }
    head = std::move(rhs.head);
    rhs.head = nullptr;
    return *this;
}

bool StackLst::IsEmpty() const noexcept {
    return !head;
}

void StackLst::Pop() noexcept {
    if (!head) {
        return;
    }
    head = std::move(head->next);
}

void StackLst::Push(const Complex& val) {
    auto newNode = std::make_unique<Node>(val);
    newNode->next = std::move(head);
    head = std::move(newNode);
}

Complex& StackLst::Top() {
    if (!head) {
        throw std::logic_error("StackLst - try get top from empty stack.");
    }
    return head->data;
}

const Complex& StackLst::Top() const {
    if (!head) {
        throw std::logic_error("StackLst - try get top from empty stack.");
    }
    return head->data;
}

void StackLst::Clear() noexcept {
    head = nullptr;
}