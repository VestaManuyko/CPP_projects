#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	A objectA;
	B objectB;
	C objectC;

	std::cout << "A through pointer: ";
	identify(&objectA);
	std::cout << "A through reference: ";
	identify(objectA);
	std::cout << "B through pointer: ";
	identify(&objectB);
	std::cout << "B through reference: ";
	identify(objectB);
	std::cout << "C through pointer: ";
	identify(&objectC);
	std::cout << "C through reference: ";
	identify(objectC);

	Base *generated = generate();
	std::cout << "Generated through pointer: ";
	identify(generated);
	std::cout << "Generated through reference: ";
	identify(*generated);
	delete generated;
}
