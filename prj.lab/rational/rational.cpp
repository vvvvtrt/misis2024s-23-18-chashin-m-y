#include "rational.hpp"


Rational::Rational(const int64_t numerator) : Rational(numerator, 1) {
	check();
	reducing_fractions();
}

Rational::Rational(int64_t numerator, int64_t denominator)
	: num_(numerator)
	, den_(denominator)
{
	check();
	reducing_fractions();
}


std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
	ostrm << num_ << separator << den_;
	return ostrm;
}


std::istream& Rational::readFrom(std::istream& istrm)
{
	int64_t numerator(0);
	char comma(0);
	int64_t denominator(0);

	istrm >> numerator >> comma >> denominator;

	if (istrm.good()) {
		if ((Rational::separator == comma)) {
			num_ = numerator;
			den_ = denominator;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}


Rational& Rational::operator+=(const Rational& rhs) {
	num_ = rhs.den_ * num_ + rhs.num_ * den_;
	den_ *= rhs.den_;
	return *this;
}

Rational operator+(Rational& lhs, Rational& rhs)
{
	return Rational(lhs.numerator() * rhs.denominator() + rhs.numerator() * lhs.denominator(), lhs.denominator() * rhs.denominator());
}

Rational& Rational::operator-=(const Rational& rhs) {
	num_ = rhs.den_ * num_ - rhs.num_ * den_;
	den_ *= rhs.den_;
	return *this;
}

Rational operator-(Rational& lhs, Rational& rhs)
{
	return Rational(lhs.numerator() * rhs.denominator() - rhs.numerator() * lhs.denominator(), lhs.denominator() * rhs.denominator());
}

Rational& Rational::operator*=(const Rational& rhs) {
	num_ *= rhs.num_;
	den_ *= rhs.den_;
	return *this;
}


Rational operator*(Rational& lhs, Rational& rhs)
{
	return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

Rational& Rational::operator/=(const Rational& rhs) {
	if (rhs.num_ == 0) {
		std::cerr << "Error";
		exit(8);
	}

	num_ *= rhs.den_;
	den_ *= rhs.num_;

	check();
	return *this;
}

Rational operator/(Rational& lhs, Rational& rhs)
{
	return Rational(lhs.numerator() * rhs.denominator(), lhs.denominator() * rhs.numerator());
}

void Rational::check() {
	if (den_ <= 0) {
		std::cerr << "Error";
		exit(8);
	}
}

void Rational::reducing_fractions() {
	int64_t a = num_;
	int64_t b = den_;

	while (b != 0) {
		int64_t temp = b;
		b = a % b;
		a = temp;
	}

	num_ /= a;
	den_ /= a;
}