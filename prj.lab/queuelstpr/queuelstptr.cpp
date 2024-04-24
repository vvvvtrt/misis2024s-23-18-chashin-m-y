#include <queuelstpr/queuelstpr.hpp>

#include <stdexcept>

QueueLstPr::QueueLstPr(const QueueLstPr& rhs) {
    Node* current = rhs.head.get();
    while (current != nullptr) {
        Push(current->data);
        current = current->next.get();
    }
}

QueueLstPr::QueueLstPr(QueueLstPr&& rhs) noexcept
    : head(std::move(rhs.head)), tail(std::move(rhs.tail)) {
    rhs.head = nullptr;
    rhs.tail = nullptr;
}

QueueLstPr::~QueueLstPr() {
    Clear();
}

QueueLstPr& QueueLstPr::operator=(const QueueLstPr& rhs) {
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

QueueLstPr& QueueLstPr::operator=(QueueLstPr&& rhs) noexcept {
    if (this != &rhs) {
        Clear();
        head = std::move(rhs.head);
        tail = std::move(rhs.tail);
        rhs.head = nullptr;
        rhs.tail = nullptr;
    }
    return *this;
}

bool QueueLstPr::IsEmpty() const noexcept {
    return head == nullptr;
}

void QueueLstPr::Pop() noexcept {
    if (head) {
        head = std::move(head->next);
        if (!head) {
            tail = nullptr;
        }
    }
}

void QueueLstPr::Push(const float& val) {
    auto newNode = std::make_unique<Node>(val);
    if (!head || val < head->data) {
        newNode->next = std::move(head);
        head = std::move(newNode);
        if (!tail) {
            tail = head.get();
        }
    }
    else {
        Node* current = head.get();
        while (current->next && val >= current->next->data) {
            current = current->next.get();
        }
        if (!current->next) {
            tail = newNode.get();
        }
        newNode->next = std::move(current->next);
        current->next = std::move(newNode);
    }
}

float& QueueLstPr::Top() {
    if (head) {
        return head->data;
    }
    throw std::out_of_range("empty queue.");
}

const float& QueueLstPr::Top() const {
    if (head) {
        return head->data;
    }
    throw std::out_of_range("empty queue.");
}

void QueueLstPr::Clear() noexcept {
    head = nullptr;
    tail = nullptr;
}