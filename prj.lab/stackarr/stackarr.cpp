#include <stackarr/stackarr.hpp>

#include <stdexcept>

StackArr::StackArr(const StackArr& rhs)
    : size_(rhs.size_), i_top_(rhs.i_top_) {
    if (!rhs.IsEmpty()) {
        data_ = std::make_unique<Complex[]>(size_);
        std::copy(rhs.data_.get(), rhs.data_.get() + i_top_ + 1, data_.get());
    }
}

StackArr::StackArr(StackArr&& rhs) noexcept
    : size_(rhs.size_), i_top_(rhs.i_top_), data_(std::move(rhs.data_)) {
    rhs.size_ = 0;
    rhs.i_top_ = -1;
}

StackArr::~StackArr() = default;

StackArr& StackArr::operator=(const StackArr& rhs) {
    if (this != &rhs) {
        if (rhs.IsEmpty()) {
            Clear();
        }
        if (size_ <= rhs.i_top_) {
            size_ = (rhs.i_top_ + 4) / 4 * 4;
            data_ = std::make_unique<Complex[]>(size_);
        }
        i_top_ = rhs.i_top_;
        std::copy(rhs.data_.get(), rhs.data_.get() + i_top_ + 1, data_.get());
    }
    return *this;
}

StackArr& StackArr::operator=(StackArr&& rhs) noexcept {
    if (this != &rhs) {
        size_ = rhs.size_;
        i_top_ = rhs.i_top_;
        data_ = std::move(rhs.data_);

        rhs.size_ = 0;
        rhs.i_top_ = -1;
    }
    return *this;
}

bool StackArr::IsEmpty() const noexcept {
    return i_top_ < 0;
}

void StackArr::Pop() noexcept {
    if (!IsEmpty()) {
        i_top_ -= 1;
    }
}

void StackArr::Push(const Complex& val) {
    if (!data_) {
        size_ = 1;
        data_ = std::make_unique<Complex[]>(size_);
    }
    else if (size_ == i_top_ + 1) {
        auto new_data = std::make_unique<Complex[]>(size_ * 2);
        std::copy(data_.get(), data_.get() + size_, new_data.get());
        std::swap(data_, new_data);
        size_ *= 2;
    }
    data_[++i_top_] = val;
}

Complex& StackArr::Top()& {
    if (IsEmpty()) {
        throw std::logic_error("StackArr - try get top from empty stack.");
    }
    return data_[i_top_];
}

const Complex& StackArr::Top() const& {
    if (IsEmpty()) {
        throw std::logic_error("StackArr - try get top from empty stack.");
    }
    return data_[i_top_];
}

void StackArr::Clear() noexcept {
    i_top_ = -1;
}