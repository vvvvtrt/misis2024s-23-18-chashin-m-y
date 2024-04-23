#pragma once

#ifndef QUEUELST_HPP
#define QUEUELST_HPP

#include <complex/complex.hpp>
#include <memory>
#include <cstddef>

class QueueLst {
public:
    QueueLst() = default;
    QueueLst(const QueueLst& other);
    QueueLst(QueueLst&& other) noexcept;

    ~QueueLst();

    QueueLst& operator=(const QueueLst& rhs);
    QueueLst& operator=(QueueLst&& rhs) noexcept;

    bool IsEmpty() const noexcept;

    void Pop() noexcept;

    void Push(const Complex& val);

    Complex& Top();
    const Complex& Top() const;

    void Clear() noexcept;

private:
    struct Node {
        Complex data;
        std::unique_ptr<Node> next;
        Node(Complex v) : data(v), next(nullptr) {}
    };
    std::unique_ptr<Node> head = nullptr;
    Node* tail = nullptr;
};

#endif