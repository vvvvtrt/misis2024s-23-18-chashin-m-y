#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <string>
#include <cmath>

class Rational {
public:
	Rational() {};
	Rational(int64_t numerator, int64_t denominator);
	explicit Rational(const int64_t numerator);
	~Rational() = default;

	Rational& operator=(const Rational& rhs) = default;

	[[nodiscard]] bool operator==(const Rational& rhs) { return num_ * rhs.den_ == rhs.num_ * den_; }
	[[nodiscard]] bool operator!=(const Rational& rhs) { return !(operator==(rhs)); }

	[[nodiscard]] bool operator>(const Rational& rhs) { return num_ * rhs.den_ > rhs.num_ * den_; }
	[[nodiscard]] bool operator<(const Rational& rhs) { return num_ * rhs.den_ < rhs.num_ * den_; }
	[[nodiscard]] bool operator>=(const Rational& rhs) { return num_ * rhs.den_ >= rhs.num_ * den_; }
	[[nodiscard]] bool operator<=(const Rational& rhs) { return num_ * rhs.den_ <= rhs.num_ * den_; }

	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);

	int64_t numerator() { return num_; }
	int64_t denominator() { return den_; }

	std::ostream& writeTo(std::ostream& ostrm) const;
	std::istream& readFrom(std::istream& istrm);

	static const char separator{ '/' };

private:
	int64_t num_ = 0;
	int64_t den_ = 1;

	void check();
	void reducing_fractions();
};


Rational operator+(Rational& lhs, Rational& rhs);
Rational operator-(Rational& lhs, Rational& rhs);
Rational operator*(Rational& lhs, Rational& rhs);
Rational operator/(Rational& lhs, Rational& rhs);


inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
	return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
	return rhs.readFrom(istrm);
}

#endif