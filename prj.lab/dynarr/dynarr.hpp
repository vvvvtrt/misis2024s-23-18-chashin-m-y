#pragma once
#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstddef>
#include <iosfwd>
#include <stdexcept>

class DynArr {
public:
    [[nodiscard]] DynArr() = default;
    [[nodiscard]] DynArr(const DynArr& d);
    [[nodiscard]] explicit DynArr(std::ptrdiff_t size);
    [[nodiscard]] DynArr(DynArr&& src) noexcept;
    ~DynArr() {
        delete[] data_;
        data_ = nullptr;
    }

    DynArr& operator=(const DynArr& d) noexcept;
    DynArr& operator=(DynArr&& src) noexcept;

    [[nodiscard]] std::ptrdiff_t Size() const noexcept;
    void Resize(std::ptrdiff_t size);

    [[nodiscard]] float& operator[](const std::ptrdiff_t i);
    [[nodiscard]] const float& operator[](const std::ptrdiff_t i) const;

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;

    float* data_ = nullptr;
};

#endif