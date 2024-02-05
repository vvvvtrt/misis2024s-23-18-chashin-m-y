#include "complex.hpp"


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

	if (istrm.good()) {
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
			&& (Complex::rightBrace == rightBrace)) {
			re = real;
			im = imaganary;
		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}

void Complex::pow(int base) {
	Complex term(re, im);

	Complex ans = Complex(1);

	if (base > 0) {
		for (int i = 0; i < std::abs(base); i++) {
			ans = ans * term;
		}
	}

	if (base < 0) {
		term = (1.0 / term);

		for (int i = 0; i < std::abs(base); i++) {
			ans = ans * term;
		}
	}

	re = ans.re;
	im = ans.im;

}

double Complex::argument() {
	if (re > 0) {
		return std::atan2(im, re);
	}
	else if (re < 0 && im >= 0) {
		return pi + std::atan2(im, re);
	}
	else if (re < 0 && im < 0) {
		return -pi + std::atan2(im, re);
	}
	else if (re == 0 && im > 0) {
		return pi / 2;
	}
	else {
		return -(pi / 2);
	}
}


void errors(std::string message) {
	std::cerr << message << "\n" << std::endl;
	std::exit(8);
}

double abs(const Complex& num) {
	return (std::sqrt(num.re * num.re + num.im * num.im));
}

Complex pow(const Complex& lhs, int n)
{
	Complex c0 = { 0,0 };
	if (lhs == c0 && n != 0) {
		return { 0,0 };
	}
	else if (lhs == c0 && n == 0) {
		errors("ERROR! Zero to the zero degree");
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



double argument(const Complex& num) {
	if (num.re > 0) {
		return std::atan(num.im / num.re);
	}
	else if (num.re < 0 && num.im >= 0) {
		return pi + std::atan(num.im / num.re);
	}
	else if (num.re < 0 && num.im < 0) {
		return -pi + std::atan(num.im / num.re);
	}
	else if (num.re == 0 && num.im > 0) {
		return pi / 2;
	}
	else {
		return -(pi / 2);
	}
}

Complex operator!(const Complex& rhs) {
	return Complex(rhs.re, -rhs.im);
}



Complex conjugate(const Complex& num) {
	return Complex(num.re, -num.im);
}


void Complex::sqrt(int base) {
	Complex a(re, im);

	double rootArgument = a.argument() / base;
	double a_abs = a.abs();
	double rootModulus = std::pow(a_abs, 1.0 / base);

	re = rootModulus * std::cos(rootArgument);
	im = rootModulus * std::sin(rootArgument);
}

Complex sqrt(Complex num, int base) {
	double rootArgument = num.argument() / base;
	double a_abs = num.abs();
	double rootModulus = std::pow(a_abs, 1.0 / base);

	return Complex(rootModulus * std::cos(rootArgument), rootModulus * std::sin(rootArgument));
}

Complex::Complex(const double real)
	: Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
	: re(real)
	, im(imaginary)
{
}

Complex& Complex::operator+=(const Complex& rhs)
{
	re += rhs.re;
	im += rhs.im;
	return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator+(const double& lhs, const Complex& rhs) { 
	return operator+(Complex(lhs), rhs); 
}

Complex operator+(const Complex& lhs, const double& rhs) { 
	return operator+(lhs, Complex(rhs)); 
}


Complex& Complex::operator-=(const Complex& rhs)
{
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator-(const double& lhs, const Complex& rhs) {
	return operator-(Complex(lhs), rhs);
}

Complex operator-(const Complex& lhs, const double& rhs) {
	return operator-(lhs, Complex(rhs));
}

//Complex Complex::operator-()



Complex& Complex::operator*=(const Complex& rhs)
{
	double re_new = re * rhs.re - im * rhs.im;

	im = re * rhs.im + im * rhs.re;
	re = re_new;

	return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
	return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.re * rhs.im + lhs.im * rhs.re);
}

Complex operator*(const double& lhs, const Complex& rhs) { 
	return operator*(Complex(lhs), rhs); 
}

Complex operator*(const Complex& lhs, const double& rhs) { 
	return operator*(lhs, Complex(rhs)); 
}


Complex& Complex::operator/=(const Complex& rhs)
{
	if (rhs.re == 0 && rhs.im == 0) {
		errors("Error! Division by zero!");
	}

	double temp_re = (re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	im = (im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
	re = temp_re;
	return *this;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
	if (rhs.re == 0 && rhs.im == 0) {
		errors("Error! Division by zero!");
	}

	return Complex(((lhs.re * rhs.re + lhs.im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im)), ((lhs.im * rhs.re - lhs.re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im)));
}

Complex operator/(const double& lhs, const Complex& rhs) {
	return operator/(Complex(lhs), rhs); 
}

Complex operator/(const Complex& lhs, const double& rhs) {
	return operator/(lhs, Complex(rhs)); 
}

