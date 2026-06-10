#include "Fixed.hpp"
#include <iostream>
#include <string>

void	comparisonTests()
{
	Fixed a(10);
	Fixed b(10.75f);

	std::cout << "Testing comparison operators with float and int" << std::endl;
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << std::boolalpha;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	Fixed i1(5);
	Fixed i2(5);
	Fixed i3(7);

	std::cout << "\nTesting comparison operators with int and int" << std::endl;
	std::cout << "i1: " << i1 << ", i2: " << i2 << ", i3: " << i3 << std::endl;
	std::cout << "i1 == i2: " << (i1 == i2) << std::endl;
	std::cout << "i1 != i3: " << (i1 != i3) << std::endl;
	std::cout << "i1 < i3: " << (i1 < i3) << std::endl;
	std::cout << "i3 > i2: " << (i3 > i2) << std::endl;

	Fixed f1(3.25f);
	Fixed f2(3.25f);
	Fixed f3(2.75f);

	std::cout << "\nTesting comparison operators with float and float" << std::endl;
	std::cout << "f1: " << f1 << ", f2: " << f2 << ", f3: " << f3 << std::endl;
	std::cout << "f1 == f2: " << (f1 == f2) << std::endl;
	std::cout << "f1 != f3: " << (f1 != f3) << std::endl;
	std::cout << "f3 <= f1: " << (f3 <= f1) << std::endl;
	std::cout << "f2 >= f3: " << (f2 >= f3) << std::endl;

	Fixed n1(-4);
	Fixed n2(-4.5f);
	Fixed n3(-3.75f);

	std::cout << "\nTesting comparison operators with negative values (mixing int and float)" << std::endl;
	std::cout << "n1: " << n1 << ", n2: " << n2 << ", n3: " << n3 << std::endl;
	std::cout << "n1 == n2: " << (n1 == n2) << std::endl;
	std::cout << "n2 < n3: " << (n2 < n3) << std::endl;
	std::cout << "n3 > n1: " << (n3 > n1) << std::endl;
	std::cout << "n1 != n3: " << (n1 != n3) << std::endl;

	Fixed z1(0);
	Fixed z2(0.0f);
	std::cout << "\nTesting zero equality and mixed comparisons" << std::endl;
	std::cout << "z1: " << z1 << ", z2: " << z2 << std::endl;
	std::cout << "z1 == z2: " << (z1 == z2) << std::endl;
	std::cout << std::noboolalpha;
}

void	arithmeticTests()
{
	std::cout << "Arithmetic tests: +, -, *, / with ints, floats, and mixed" << std::endl;

	Fixed a(10);
	Fixed b(-5);
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl << std::endl;

	Fixed f1(5.5f);
	Fixed f2(2.0f);
	std::cout << "f1: " << f1 << ", f2: " << f2 << std::endl;
	std::cout << "f1 + f2 = " << (f1 + f2) << std::endl;
	std::cout << "f1 - f2 = " << (f1 - f2) << std::endl;
	std::cout << "f1 * f2 = " << (f1 * f2) << std::endl;
	std::cout << "f1 / f2 = " << (f1 / f2) << std::endl << std::endl;

	Fixed mix1(7);
	Fixed mix2(2.5f);
	std::cout << "mix1: " << mix1 << ", mix2: " << mix2 << std::endl;
	std::cout << "mix1 + mix2 = " << (mix1 + mix2) << std::endl;
	std::cout << "mix1 - mix2 = " << (mix1 - mix2) << std::endl;
	std::cout << "mix1 * mix2 = " << (mix1 * mix2) << std::endl;
	std::cout << "mix1 / mix2 = " << (mix1 / mix2) << std::endl << std::endl;
}

void	incrementDecrementTests()
{
	std::cout << "Increment/Decrement tests (prefix and postfix)" << std::endl;

	Fixed a(1.1f);
	std::cout << "initial a: " << a << std::endl;
	std::cout << "prefix ++a: " << ++a << std::endl;
	std::cout << "after prefix a: " << a << std::endl;
	std::cout << "postfix a++: " << a++ << std::endl;
	std::cout << "after postfix a: " << a << std::endl;
	std::cout << "prefix --a: " << --a << std::endl;
	std::cout << "postfix a--: " << a-- << std::endl;
	std::cout << "after all ops a: " << a << std::endl << std::endl;

	Fixed b(5);
	std::cout << "initial b: " << b << std::endl;
	std::cout << "b++: " << b++ << ", now: " << b << std::endl;
	std::cout << "++b: " << ++b << ", now: " << b << std::endl;
	std::cout << "b--: " << b-- << ", now: " << b << std::endl;
	std::cout << "--b: " << --b << ", now: " << b << std::endl << std::endl;
}

void	minMaxTests()
{
	std::cout << "Min/Max tests (const and non-const)" << std::endl;

	Fixed a(2.5f);
	Fixed b(5);
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "min(a,b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a,b) = " << Fixed::max(a, b) << std::endl << std::endl;

	const Fixed ca(7.75f);
	const Fixed cb(3.125f);
	std::cout << "const ca: " << ca << ", const cb: " << cb << std::endl;
	std::cout << "min(ca,cb) = " << Fixed::min(ca, cb) << std::endl;
	std::cout << "max(ca,cb) = " << Fixed::max(ca, cb) << std::endl << std::endl;

	// ensure overloads work with equal values
	Fixed eq1(4);
	Fixed eq2(4.0f);
	std::cout << "eq1: " << eq1 << ", eq2: " << eq2 << std::endl;
	std::cout << "min(eq1,eq2) = " << Fixed::min(eq1, eq2) << std::endl;
	std::cout << "max(eq1,eq2) = " << Fixed::max(eq1, eq2) << std::endl << std::endl;
}

void	subjectTests()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "Subject test" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <test>\n";
		std::cerr << "Available tests: comparison, arithmetic, increment, minmax, subject\n";
		return 1;
	}
	std::string arg(argv[1]);
	if (arg == "comparison")
		comparisonTests();
	else if (arg == "arithmetic")
		arithmeticTests();
	else if (arg == "increment")
		incrementDecrementTests();
	else if (arg == "minmax")
		minMaxTests();
	else if (arg == "subject")
		subjectTests();
	else
	{
		std::cerr << "Unknown test: " << arg << "\n";
		std::cerr << "Available tests: comparison, arithmetic, increment, minmax, subject\n";
		return 1;
	}
	return 0;
}
