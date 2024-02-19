#include "complex.hpp"

Complex operator*(const double lhs, const Complex& rhs) noexcept { return operator*(Complex(lhs), rhs); }
Complex operator*(const Complex& lhs, const double rhs) noexcept { return operator*(lhs, Complex(rhs)); }
Complex operator-(const double lhs, const Complex& rhs) noexcept { return operator-(Complex(lhs), rhs); }
Complex operator-(const Complex& lhs, const double rhs) noexcept { return operator-(lhs, Complex(rhs)); }
Complex operator+(const double lhs, const Complex& rhs) noexcept { return operator+(Complex(lhs), rhs); }
Complex operator+(const Complex& lhs, const double rhs) noexcept { return operator+(lhs, Complex(rhs)); }
Complex operator/(const double lhs, const Complex& rhs) { return operator/(Complex(lhs), rhs); }
Complex operator/(const Complex& lhs, const double rhs) { return operator/(lhs, Complex(rhs)); }
bool operator==(const Complex& lhs, const double rhs) noexcept { return operator==(lhs, Complex(rhs)); }
bool operator==(const double lhs, const Complex& rhs) noexcept { return operator==(Complex(lhs), rhs); }
bool operator!=(const Complex& lhs, const Complex& rhs) noexcept { return !operator==(lhs, rhs); }
bool operator!=(const Complex& lhs, const double rhs) noexcept { return !operator==(lhs, Complex(rhs)); }
bool operator!=(const double lhs, const Complex& rhs) noexcept { return !operator==(Complex(lhs), rhs); }

bool operator==(const Complex& lhs, const Complex& rhs) noexcept {
    double constexpr eps = 2 * std::numeric_limits<double>::epsilon();
    if (std::abs(lhs.im - rhs.im) <= eps && std::abs(lhs.re - rhs.re) <= eps) {
        return 1;
    }
    else {
        return 0;
    }
}

Complex Complex::operator-() const noexcept {
    return Complex(-re, -im);
}

Complex& Complex::operator+=(const Complex& rhs) noexcept
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept
{
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex& Complex::operator-=(const Complex& rhs) noexcept
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept
{
    Complex razn(lhs);
    razn -= rhs;
    return razn;
}

Complex& Complex::operator*=(const Complex& rhs) noexcept
{
    auto re1 = re, im1 = im;
    re = re * rhs.re - im * rhs.im;
    im = re1 * rhs.im + im1 * rhs.re;
    return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept
{
    Complex proizv(lhs);
    proizv *= rhs;
    return proizv;
}


Complex& Complex::operator/=(const Complex& rhs)
{
    const Complex c0 = { 0,0 };
    try {
        if (rhs == c0) {
            throw std::invalid_argument("Division by zero\n");
        }
        else {
            auto re1 = re, im1 = im;
            re = (re * rhs.re + im * rhs.im) / (std::pow(rhs.re, 2) + std::pow(rhs.im, 2));
            im = (im1 * rhs.re - re1 * rhs.im) / (std::pow(rhs.re, 2) + std::pow(rhs.im, 2));
            return *this;
        }
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
        exit(1);
    }
}


Complex operator/(const Complex& lhs, const Complex& rhs)
{
    const Complex c0 = { 0,0 };
    try {
        if (rhs == c0) {
            throw std::invalid_argument("Division by zero\n");
        }
        else {
            Complex chast(lhs);
            chast /= rhs;
            return chast;
        }
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
        exit(1);
    }
}

Complex operator!(const Complex& rhs) noexcept {
    Complex c;
    c.re = rhs.re;
    c.im = -rhs.im;
    return c;
}

double abs(const Complex& rhs) noexcept
{
    double ans = std::pow((std::pow(rhs.re, 2) + std::pow(rhs.im, 2)), 0.5);
    return ans;
}

Complex pow(const Complex& lhs, int n)
{
    const Complex c0 = { 0,0 };
    try {
        if (lhs == c0 && n != 0) {
            return { 0,0 };
        }
        else if (lhs == c0 && n == 0) {
            throw std::invalid_argument("Zero to the zero degree!\n");
        }
        else if (n == 0) {
            return Complex(1);
        }
        else if (n > 0) {
            return lhs * pow(lhs, --n);
        }
        else if (n < 0) {
            Complex olhs = (1.0 / lhs);
            return olhs * pow(lhs, ++n);
        }
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
        exit(1);
    }
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good())
    {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace))
        {
            re = real;
            im = imaganary;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}
