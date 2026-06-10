#include "Fixed.hpp"

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
	Fixed a(10);
	Fixed b(5);
	Fixed res;

	res = a * b;
	std::cout << res << std::endl;
	res = a / b;
	std::cout << res << std::endl;
}

int main()
{
	comparisonTests();
	arithmeticTests();

	return 0;
}
