#pragma once
#pragma once
#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <iostream>
#include <sstream>
#include <algorithm>


class DynArr {
public:
    DynArr() = default;
    DynArr(const DynArr& d);
    DynArr(std::ptrdiff_t size);
    ~DynArr() { delete[] data_; }

    [[nodiscard]] DynArr& operator=(const DynArr& d) noexcept;

    [[nodiscard]] std::ptrdiff_t size() const noexcept;
    void resize(std::ptrdiff_t size);

    [[nodiscard]] float& operator[](const std::ptrdiff_t i);
    [[nodiscard]] const float& operator[](const std::ptrdiff_t i) const;

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;

    float* data_ = nullptr;
};

#endif