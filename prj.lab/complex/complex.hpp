#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <sstream>


double const pi = 4 * std::atan(1);

struct Complex {
	Complex() {}
	explicit Complex(const double real);
	Complex(const double real, const double imaginary);

	~Complex() = default;

	Complex& operator=(const Complex&) = default;

	[[nodiscard]] bool operator==(const Complex& rhs) const { const constexpr int eps = 2 * std::numeric_limits<double>::epsilon(); return (std::abs(rhs.re - re) <= eps && std::abs(rhs.im - im) <= eps);}

	[[nodiscard]] bool operator!=(const Complex& rhs) const { return (!(operator==(rhs))); }

	[[nodiscard]] bool operator>(const Complex& rhs) const { return (std::sqrt(re * re + im * im) > std::sqrt(rhs.re * rhs.re + rhs.im * rhs.im)); }
	[[nodiscard]] bool operator<(const Complex& rhs) const { return (std::sqrt(re * re + im * im) < std::sqrt(rhs.re * rhs.re + rhs.im * rhs.im)); }

	[[nodiscard]] bool operator>=(const Complex& rhs) const { return (operator==(rhs) || operator>(rhs)); }
	[[nodiscard]] bool operator<=(const Complex& rhs) const { return (operator==(rhs) || operator<(rhs)); }

	Complex& operator+=(const Complex& rhs);
	Complex& operator+=(const double rhs) { return (operator+=(Complex(rhs))); }

	Complex& operator-=(const Complex& rhs);
	Complex& operator-=(const double rhs) { return (operator-=(Complex(rhs))); }
	Complex operator-() const noexcept { return Complex(-re, -im);  }

	Complex& operator*=(const Complex& rhs);
	Complex& operator*=(const double rhs) { return (operator*=(Complex(rhs))); }

	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) { return (operator/=(Complex(rhs))); }

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	[[nodiscard]] double abs() { return std::sqrt(re * re + im * im); }
	void conjugate() { im = -im; }

	void pow(int base);
	[[nodiscard]] double argument();
	void sqrt(int base);



	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char separator{ ',' };
	static const char rightBrace{ '}' };
};



Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const double& lhs, const Complex& rhs); 
Complex operator+(const Complex& lhs, const double& rhs); 

Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const double& lhs, const Complex& rhs); 
Complex operator-(const Complex& lhs, const double& rhs); 

Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const double& lhs, const Complex& rhs); 
Complex operator*(const Complex& lhs, const double& rhs); 

Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const double& lhs, const Complex& rhs); 
Complex operator/(const Complex& lhs, const double& rhs); 

Complex operator!(const Complex& rhs);


[[nodiscard]] double abs(const Complex& num);
[[nodiscard]] double argument(const Complex& num);

[[nodiscard]] Complex pow(const Complex& lhs, int n);
[[nodiscard]] Complex conjugate(const Complex& num);
[[nodiscard]] Complex sqrt(Complex num, int base);

void errors(std::string message);


inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Complex& rhs)
{
	return rhs.readFrom(istrm);
}

#endif