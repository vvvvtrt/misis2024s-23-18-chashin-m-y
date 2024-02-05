#include <complex/complex.hpp>

void test() {

	Complex a(2, 3);
	std::cout << "Given complex num A: " << a << '\n';

	Complex b(4, 5);
	std::cout << "Given complex num B: " << b << '\n';;

	double c = 6;
	std::cout << "Given double num C: " << c << '\n';

	Complex a_save = a;
	Complex b_save = b;
	double c_save = c;

	std::cout << '\n';

	std::cout << "sum operator+ in complex: " << a + b << '\n';
	a += b;
	std::cout << "sum operator+= in complex: " << a << '\n';
	a = a_save;

	std::cout << "sum operator+ in double: " << a + c << '\n';
	a += c;
	std::cout << "sum operator+= in double: " << a << '\n';

	std::cout << '\n';

	a = a_save;
	std::cout << "dif operator- in complex: " << a - b << '\n';
	a -= b;
	std::cout << "dif operator-= in complex: " << a << '\n';

	a = a_save;
	std::cout << "dif operator- in double: " << a - c << '\n';
	a -= c;
	std::cout << "dif operator-= in double: " << a << '\n';

	std::cout << '\n';

	a = a_save;
	std::cout << "mul operator* in complex: " << a * b << '\n';
	a *= b;
	std::cout << "mul operator*= in complex: " << a << '\n';

	a = a_save;
	std::cout << "mul operator* in double: " << a * c << '\n';
	a *= c;
	std::cout << "mul operator*= in double: " << a << '\n';

	std::cout << '\n';

	a = a_save;
	std::cout << "div operator/ in complex: " << a / b << '\n';
	a /= b;
	std::cout << "div operator/= in complex: " << a << '\n';

	a = a_save;
	std::cout << "div operator/ in double: " << a / c << '\n';
	a /= c;
	std::cout << "div operator/= in double: " << a << '\n';

	std::cout << '\n';

	a = a_save;
	std::cout << "abs with abs(a): " << abs(a) << '\n';
	std::cout << "abs with a.abs(): " << a.abs() << '\n';

	std::cout << "arg with argument(): " << argument(a) << '\n';
	std::cout << "arg with a.argument(): " << a.argument() << '\n';

	std::cout << "con with conjugate(a): " << conjugate(a) << '\n';
	a.conjugate();
	std::cout << "con with a.conjugate();: " << a << '\n';

	a = a_save;
	std::cout << "!Complex(): " << !a << '\n';

	a = a_save;
	std::cout << "pow with pow(a, 2): " << pow(a, 2) << '\n';
	a.pow(2);
	std::cout << "pow with a.pow(2): " << a << '\n';

	a = a_save;
	std::cout << "sqrt with sqrt(): " << sqrt(a, 2) << '\n';
	a.sqrt(2);
	std::cout << "sqrt with a.sqrt(): " << a << '\n';

	a = -a_save;
	std::cout << "-Complex(): " << a << '\n';
	
	

	a = a_save;
	std::cout << "a == b: " << static_cast<bool>(a == b) << '\n';
	std::cout << "a != b: " << static_cast<bool>(a != b) << '\n';
	std::cout << "a > b: " << static_cast<bool>(a > b) << '\n';
	std::cout << "a < b: " << static_cast<bool>(a < b) << '\n';
	std::cout << "a >= b: " << static_cast<bool>(a >= b) << '\n';
	std::cout << "a <= b: " << static_cast<bool>(a <= b) << '\n';

	std::cout << "div by zero: " << a / 0.0 << '\n';
}


int main() {
	test();
	return 0;
}