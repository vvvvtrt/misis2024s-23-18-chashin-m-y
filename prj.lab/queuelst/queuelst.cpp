#include <queuelst/queuelst.hpp>

#include <algorithm>
#include <stdexcept>

QueueLst::QueueLst(const QueueLst& rhs) {
    Node* current = rhs.head.get();
    while (current != nullptr) {
        Push(current->data);
        current = current->next.get();
    }
}

QueueLst::QueueLst(QueueLst&& rhs) noexcept
    : head(std::move(rhs.head)), tail(std::move(rhs.tail)) {
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

QueueLst::~QueueLst() {
    Clear();
}

QueueLst& QueueLst::operator=(const QueueLst& rhs) {
    if (this != &rhs) {
        Clear();
        Node* current = rhs.head.get();
        while (current != nullptr) {
            Push(current->data);
            current = current->next.get();
        }
    }
    return *this;
}

QueueLst& QueueLst::operator=(QueueLst&& rhs) noexcept {
    if (this != &rhs) {
        Clear();
        head = std::move(rhs.head);
        tail = std::move(rhs.tail);
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }
    return *this;
}

bool QueueLst::IsEmpty() const noexcept {
    return head == nullptr;
}

void QueueLst::Pop() noexcept {
    if (!IsEmpty()) {
        head = std::move(head->next);
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

void QueueLst::Push(const Complex& val) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>(val);
    if (IsEmpty()) {
        head = std::move(newNode);
        tail = head.get();
    }
    else {
        tail->next = std::move(newNode);
        tail = tail->next.get();
    }
}

Complex& QueueLst::Top() {
    if (!IsEmpty()) {
        return head->data;
    }
    else {
        throw std::out_of_range("empty queue.");
    }
}

const Complex& QueueLst::Top() const {
    if (!IsEmpty()) {
        return head->data;
    }
    else {
        throw std::out_of_range("empty queue.");
    }
}

void QueueLst::Clear() noexcept {
    head = nullptr;
    tail = nullptr;
}