#include "rational.hpp"

[[nodiscard]] Rational operator+(const Rational& r1, const std::int64_t c) noexcept { return operator+(r1, Rational(c)); }
[[nodiscard]] Rational operator+(const std::int64_t c, const Rational& r2) noexcept { return operator+(Rational(c), r2); }
[[nodiscard]] Rational operator-(const Rational& r1, const std::int64_t c) noexcept { return operator-(r1, Rational(c)); }
[[nodiscard]] Rational operator-(const std::int64_t c, const Rational& r2) noexcept { return operator-(Rational(c), r2); }
[[nodiscard]] Rational operator*(const Rational& r1, const std::int64_t c) noexcept { return operator*(r1, Rational(c)); }
[[nodiscard]] Rational operator*(const std::int64_t c, const Rational& r2) noexcept { return operator*(Rational(c), r2); }
[[nodiscard]] Rational operator/(const Rational& r1, const std::int64_t c) { return operator/(r1, Rational(c)); }
[[nodiscard]] Rational operator/(const std::int64_t c, const Rational& r2) { return operator/(Rational(c), r2); }
[[nodiscard]] bool operator==(const std::int64_t c, const Rational& r2) noexcept { return operator==(Rational(c), r2); }
[[nodiscard]] bool operator==(const Rational& r1, const std::int64_t c) noexcept { return operator==(r1, Rational(c)); }
[[nodiscard]] bool operator!=(const Rational& r1, const Rational& r2) noexcept { return !operator==(r1, r2); }
[[nodiscard]] bool operator!=(const std::int64_t c, const Rational& r2) noexcept { return !operator==(Rational(c), r2); }
[[nodiscard]] bool operator!=(const Rational& r1, const std::int64_t c) noexcept { return !operator==(r1, Rational(c)); }
[[nodiscard]] bool operator>(const std::int64_t c, const Rational& r2) noexcept { return operator>(Rational(c), r2); }
[[nodiscard]] bool operator>(const Rational& r1, const std::int64_t c) noexcept { return operator>(r1, Rational(c)); }
[[nodiscard]] bool operator<(const Rational& r1, const Rational& r2) noexcept { return !operator>(r1, r2); }
[[nodiscard]] bool operator<(const std::int64_t c, const Rational& r2) noexcept { return !operator>(Rational(c), r2); }
[[nodiscard]] bool operator<(const Rational& r1, const std::int64_t c) noexcept { return !operator>(r1, Rational(c)); }
[[nodiscard]] bool operator>=(const std::int64_t c, const Rational& r2) noexcept { return operator>=(Rational(c), r2); }
[[nodiscard]] bool operator>=(const Rational& r1, const std::int64_t c) noexcept { return operator>=(r1, Rational(c)); }
[[nodiscard]] bool operator<=(const std::int64_t c, const Rational& r2) noexcept { return operator<=(Rational(c), r2); }
[[nodiscard]] bool operator<=(const Rational& r1, const std::int64_t c) noexcept { return operator<=(r1, Rational(c)); }

Rational& Rational::round() noexcept {
    if (den_ < 0) {
        num_ *= -1;
        den_ *= -1;
    }
    int nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    return *this;
}

Rational::Rational(const std::int64_t num, const std::int64_t den) {
    if (den == 0) {
        throw std::invalid_argument("Zero denominator in Rational ctor\n");
    }
    else {
        num_ = num;
        den_ = den;
        this->round();
    }
}

std::int64_t Rational::evkl(const std::int64_t c1, const std::int64_t c2) noexcept {
    std::int64_t mx, mn;
    std::int64_t v;
    mx = std::max(std::abs(c1), std::abs(c2));
    mn = std::min(std::abs(c1), std::abs(c2));
    if (mn == 0) {
        return mx;
    }
    while (mx != mn) {
        mx = mx - mn;
        v = mx;
        mx = std::max(mx, mn);
        mn = std::min(v, mn);
    }
    return mx;
}

Rational Rational::operator-() noexcept {
    return Rational(-num_, den_);
}

Rational Rational::pow(const std::int64_t n) {
    if (num_ == 0 && n == 0) {
        throw std::invalid_argument("Zero to the zero degree\n");
    }
    else {
        Rational r1(num_, den_);
        r1.num_ = std::pow(r1.num_, n);
        r1.den_ = std::pow(r1.den_, n);
        if (r1.den_ < 0) {
            r1.num_ *= -1;
            r1.den_ *= -1;
        }
        std::int64_t nod = evkl(r1);
        r1.num_ /= nod;
        r1.den_ /= nod;
        return r1;
    }
}

bool operator==(const Rational& r1, const Rational& r2) noexcept {
    std::int64_t ch1 = r1.num() * r2.den();
    std::int64_t ch2 = r2.num() * r1.den();
    if (ch1 == ch2) {
        return 1;
    }
    else {
        return 0;
    }
}

bool operator>(const Rational& r1, const Rational& r2) noexcept {
    std::int64_t ch1 = r1.num() * r2.den();
    std::int64_t ch2 = r2.num() * r1.den();
    if (ch1 > ch2) {
        return 1;
    }
    else {
        return 0;
    }
}

bool operator>=(const Rational& r1, const Rational& r2) noexcept {
    std::int64_t ch1 = r1.num() * r2.den();
    std::int64_t ch2 = r2.num() * r1.den();
    if (ch1 >= ch2) {
        return 1;
    }
    else {
        return 0;
    }
}


bool operator<=(const Rational& r1, const Rational& r2) noexcept {
    std::int64_t ch1 = r1.num() * r2.den();
    std::int64_t ch2 = r2.num() * r1.den();
    if (ch1 <= ch2) {
        return 1;
    }
    else {
        return 0;
    }
}

Rational& Rational::operator*=(const Rational& r) noexcept {
    num_ *= r.num_;
    den_ *= r.den_;
    this->round();
    return *this;
}

Rational& Rational::operator/=(const Rational& r) {
    if (r.num_ == 0) {
        throw std::invalid_argument("Division by zero\n");
    }
    num_ *= r.den_;
    den_ *= r.num_;
    this->round();
    return *this;
}

Rational Rational::abs() noexcept {
    Rational r12;
    r12.num_ = std::abs(num_);
    r12.den_ = std::abs(den_);
    return r12;
}

Rational operator+(const Rational& r1, const Rational& r2) noexcept {
    Rational r11(r1);
    r11 += r2;
    return r11;
}

Rational operator-(const Rational& r1, const Rational& r2) noexcept {
    Rational r11(r1);
    r11 -= r2;
    return r11;
}

Rational operator*(const Rational& r1, const Rational& r2) noexcept {
    Rational r11(r1);
    r11 *= r2;
    return r11;
}

Rational operator/(const Rational& r1, const Rational& r2) {
    Rational r11(r1);
    r11 /= r2;
    return r11;
}

Rational& Rational::operator-=(const Rational& r) noexcept {
    num_ = num_ * r.den_ - den_ * r.num_;
    den_ *= r.den_;
    this->round();
    return *this;
}

Rational& Rational::operator+=(const Rational& r) noexcept {
    num_ = num_ * r.den_ + den_ * r.num_;
    den_ *= r.den_;
    this->round();
    return *this;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << num_ << sl << den_;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
    int num(0);
    char sl(0);
    int den(1);
    istrm >> num;
    istrm.get(sl);
    int trash = istrm.peek();
    istrm >> den;
    if (!istrm || trash > '9' || trash < '0') {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    if (istrm.good() || istrm.eof()) {
        if (Rational::sl == sl && den > 0) {
            *this = Rational(num, den);
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}