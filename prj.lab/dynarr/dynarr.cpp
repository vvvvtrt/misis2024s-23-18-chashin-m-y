#include "dynarr.hpp"

DynArr::DynArr(const DynArr& d) {
    size_ = d.size_;
    capacity_ = d.capacity_;
    data_ = new float[size_];
    std::copy(d.data_, d.data_ + d.size_, data_);
}

DynArr::DynArr(const std::ptrdiff_t size) {
    if (size > 0) {
        size_ = size;
        capacity_ = size;
        data_ = new float[size];
        std::fill(data_, data_ + size, 0);
    }
    else if (size < 0) {
        throw std::invalid_argument("Negative array size\n");
    }
    else if (size == 0) {
        throw std::invalid_argument("Array of zero size\n");
    }
}

std::ptrdiff_t DynArr::Size() const noexcept {
    return size_;
}

DynArr& DynArr::operator=(const DynArr& d) noexcept {
    if (this != &d) {
        if (d.size_ > capacity_) {
            capacity_ = d.capacity_;
            delete[] data_;
            data_ = new float[d.size_];
        }
        std::copy(d.data_, d.data_ + d.size_, data_);
        size_ = d.size_;
        return *this;
    }
}

float& DynArr::operator[](const std::ptrdiff_t i) {
    if (i < 0) {
        throw std::invalid_argument("Negative index\n");
    }
    else if (i >= size_) {
        throw std::out_of_range("Index out of range\n");
    }
    else {
        return data_[i];
    }
}

const float& DynArr::operator[](const std::ptrdiff_t i) const {
    if (i < 0) {
        throw std::invalid_argument("Negative index\n");
    }
    else if (i >= size_) {
        throw std::out_of_range("Index out of range\n");
    }
    else {
        return data_[i];
    }
}

void DynArr::Resize(std::ptrdiff_t size) {
    if (size > 0) {
        if (size > size_ && size <= capacity_) {
            std::fill(data_ + size_, data_ + size, 0);
        }
        else if (size > capacity_) {
            float* new_data = new float[size];
            std::copy(data_, data_ + size_, new_data);
            std::fill(new_data + size_, new_data + size, 0);
            delete[] data_;
            data_ = new_data;
            capacity_ = size;
        }
        size_ = size;
    }
    else if (size < 0) {
        throw std::invalid_argument("Negative array size\n");
    }
    else {
        throw std::invalid_argument("Array of zero size\n");
    }
}