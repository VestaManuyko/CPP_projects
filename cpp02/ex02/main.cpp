#include "Fixed.hpp"

int main()
{
	Fixed a(10);
	Fixed b(10.75f);

	if (a < b)
		std::cout << "a is smaller\n";
}
