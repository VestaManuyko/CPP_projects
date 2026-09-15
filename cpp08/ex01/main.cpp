#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
		Span a(2);
		
		a.addNumber(57);
		a.addNumber(1);
		std::cout << a;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
