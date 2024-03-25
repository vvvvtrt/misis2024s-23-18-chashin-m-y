#include "stackarr.hpp"

StackArr::StackArr(const StackArr& rhs) {
    size_ = rhs.size_;
    i_top_ = rhs.i_top_;
    data_ = std::make_unique<Complex[]>(size_);
    std::copy(rhs.data_.get(), rhs.data_.get() + rhs.size_, data_.get());
}

StackArr::StackArr(StackArr&& rhs) noexcept {
    std::swap(data_, rhs.data_);
    std::swap(size_, rhs.size_);
    std::swap(i_top_, rhs.i_top_);
}

StackArr& StackArr::operator=(const StackArr& rhs) noexcept {
    if (this != &rhs) {
        if (rhs.size_ > size_) {
            data_ = std::make_unique<Complex[]>(rhs.size_);
        }
        std::copy(rhs.data_.get(), rhs.data_.get() + rhs.size_, data_.get());
        i_top_ = rhs.i_top_;
        size_ = rhs.size_;
        return *this;
    }
}

StackArr& StackArr::operator=(StackArr&& rhs) noexcept {
    if (this != &rhs) {
        std::swap(data_, rhs.data_);
        std::swap(size_, rhs.size_);
        std::swap(i_top_, rhs.i_top_);
    }
    return *this;
}

bool StackArr::IsEmpty() const noexcept {
    return (i_top_ == -1 ? 1 : 0);
}

void StackArr::Pop() noexcept {
    if (!IsEmpty()) {
        i_top_ -= 1;
    }
}

void StackArr::Push(const Complex& el) {
    if (i_top_ == -1) {
        size_ = 8;
        data_ = std::make_unique<Complex[]>(size_);
    }
    else if (size_ == i_top_ + 1) {
        std::unique_ptr<Complex[]> new_data = std::make_unique<Complex[]>(size_ * 2);
        std::copy(data_.get(), data_.get() + size_, new_data.get());
        std::swap(data_, new_data);
        size_ *= 2;
    }
    i_top_ += 1;
    data_[i_top_] = el;
}

Complex& StackArr::Top() {
    if (i_top_ >= 0) {
        return data_[i_top_];
    }
    else {
        throw std::logic_error("Stack is empty!\n");
    }
}

const Complex& StackArr::Top() const {
    if (i_top_ >= 0) {
        return data_[i_top_];
    }
    else {
        throw std::logic_error("Stack is empty!\n");
    }
}

void StackArr::Clear() noexcept {
    i_top_ = -1;
}