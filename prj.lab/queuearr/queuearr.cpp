#include <queuearr/queuearr.hpp>

#include <algorithm>
#include <stdexcept>

std::ptrdiff_t QueueArr::Count() const {
    return IsEmpty() ? 0 : (tail_ + size_ - head_) % size_ + 1;
}

QueueArr::QueueArr(const QueueArr& rhs) {
    if (!rhs.IsEmpty()) {
        std::ptrdiff_t count = rhs.Count();
        head_ = 0;
        tail_ = count - 1;
        size_ = (count + 4) / 4 * 4;
        data_ = std::make_unique<Complex[]>(size_);
        if (rhs.head_ < rhs.tail_) {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.tail_ + 1, data_.get());
        }
        else {
            std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.size_, data_.get());
            std::copy(rhs.data_.get(), rhs.data_.get() + rhs.tail_ + 1, data_.get() + rhs.size_ - rhs.head_);
        }
    }
}

QueueArr::QueueArr(QueueArr&& rhs) noexcept
    : size_(rhs.size_), head_(rhs.head_), tail_(rhs.tail_), data_(std::move(rhs.data_)) {
    rhs.size_ = 0;
    rhs.head_ = -1;
    rhs.tail_ = -1;
}

QueueArr::~QueueArr() = default;

QueueArr& QueueArr::operator=(const QueueArr& rhs) {
    if (this != &rhs) {
        std::ptrdiff_t count = rhs.Count();
        if (!count) {
            head_ = -1;
        }
        else {
            if (size_ < count) {
                size_ = (count + 4) / 4 * 4;
                data_ = std::make_unique<Complex[]>(size_);
            }
            if (rhs.head_ < rhs.tail_) {
                std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.tail_ + 1, data_.get());
            }
            else {
                std::copy(rhs.data_.get() + rhs.head_, rhs.data_.get() + rhs.size_, data_.get());
                std::copy(rhs.data_.get(), rhs.data_.get() + rhs.tail_ + 1, data_.get() + rhs.size_ - rhs.head_);
            }
            head_ = 0;
            tail_ = count - 1;
        }
    }
    return *this;
}

QueueArr& QueueArr::operator=(QueueArr&& rhs) noexcept {
    if (this != &rhs) {
        size_ = rhs.size_;
        head_ = rhs.head_;
        tail_ = rhs.tail_;
        data_ = std::move(rhs.data_);

        rhs.size_ = 0;
        rhs.head_ = -1;
        rhs.tail_ = -1;
    }
    return *this;
}

bool QueueArr::IsEmpty() const noexcept {
    return head_ < 0;
}

void QueueArr::Pop() noexcept {
    if (!IsEmpty()) {
        if (head_ != tail_) {
            head_ = (head_ + 1) % size_;
        }
        else {
            head_ = -1;
        }
    }
}

void QueueArr::Push(const Complex& val) {
    if (!data_) {
        size_ = 2;
        data_ = std::make_unique<Complex[]>(size_);
    }
    if (IsEmpty()) {
        head_ = 0;
        tail_ = 0;
    }
    else {
        if (head_ == (tail_ + 1) % size_) {
            auto new_data = std::make_unique<Complex[]>(size_ * 2);
            if (head_ < tail_) {
                std::copy(data_.get() + head_, data_.get() + tail_ + 1, new_data.get());
            }
            else {
                std::copy(data_.get() + head_, data_.get() + size_, new_data.get());
                std::copy(data_.get(), data_.get() + tail_ + 1, new_data.get() + size_ - head_);
            }
            std::swap(data_, new_data);
            size_ *= 2;
            tail_ = Count();
        }
        else {
            tail_ = (tail_ + 1) % size_;
        }
    }
    data_[tail_] = val;
}

Complex& QueueArr::Top() {
    if (IsEmpty()) {
        throw std::logic_error("empty queue.");
    }
    return data_[head_];
}

const Complex& QueueArr::Top() const {
    if (IsEmpty()) {
        throw std::logic_error("empty queue.");
    }
    return data_[head_];
}

void QueueArr::Clear() noexcept {
    head_ = -1;
}