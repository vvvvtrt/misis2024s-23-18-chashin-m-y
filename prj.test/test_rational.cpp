#include <rational/rational.hpp>
//#include "doctest.h"

int main() {
	Rational a;
	Rational b;

	std::cin >> a;
	std::cin >> b;

	std::cout << (bool)(a == b) << '\n';
	std::cout << (bool)(a != b) << '\n';
	std::cout << (bool)(a > b) << '\n';
	std::cout << (bool)(a >= b) << '\n';
	std::cout << (bool)(a < b) << '\n';
	std::cout << (bool)(a <= b) << '\n';
}