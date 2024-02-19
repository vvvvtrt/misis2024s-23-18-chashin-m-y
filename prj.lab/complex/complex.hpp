#pragma once
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <sstream>
#include <iostream>
#include <iosfwd>
#include <limits>
#include <cmath>
#include <stdexcept>
#include <string>

struct Complex {
    [[nodiscard]] Complex() = default;
    [[nodiscard]] Complex(const Complex&) = default;
    [[nodiscard]] explicit Complex(const double real) : Complex(real, 0.0) {}
    [[nodiscard]] Complex(const double real, const double imaginary) : re(real), im(imaginary) {}

    ~Complex() = default;

    Complex& operator=(const Complex& rhs) = default;
    Complex& operator+=(const Complex& rhs) noexcept;
    Complex& operator-=(const Complex& rhs) noexcept;
    Complex& operator*=(const Complex& rhs) noexcept;
    Complex& operator/=(const Complex& rhs);
    Complex& operator=(const double rhs)  noexcept { return operator=(Complex(rhs)); }
    Complex& operator+=(const double rhs) noexcept { return operator+=(Complex(rhs)); }
    Complex& operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }
    Complex& operator*=(const double rhs) noexcept { return operator*=(Complex(rhs)); }
    Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }
    [[nodiscard]] Complex operator-() const noexcept;

    [[nodiscard]] std::ostream& writeTo(std::ostream& ostrm) const;
    [[nodiscard]] std::istream& readFrom(std::istream& isdtrm);

    double re{ 0.0 };
    double im{ 0.0 };

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

[[nodiscard]] Complex operator+(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator-(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator*(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator/(const Complex& lhs, const Complex& rhs);
[[nodiscard]] Complex operator!(const Complex& rhs) noexcept;
[[nodiscard]] Complex operator*(const double lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator*(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] Complex operator-(const double lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator-(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] Complex operator+(const double lhs, const Complex& rhs) noexcept;
[[nodiscard]] Complex operator+(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] Complex operator/(const double lhs, const Complex& rhs);
[[nodiscard]] Complex operator/(const Complex& lhs, const double rhs);
[[nodiscard]] Complex pow(const Complex& lhs, int n);

[[nodiscard]] bool operator==(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] bool operator!=(const Complex& lhs, const Complex& rhs) noexcept;
[[nodiscard]] bool operator==(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] bool operator==(const double lhs, const Complex& rhs) noexcept;
[[nodiscard]] bool operator!=(const Complex& lhs, const double rhs) noexcept;
[[nodiscard]] bool operator!=(const double lhs, const Complex& rhs) noexcept;
[[nodiscard]] double abs(const Complex& rhs) noexcept;

bool testParse(const std::string& str);
void test(const Complex& c1, const Complex& c2, const double c);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}

#endif