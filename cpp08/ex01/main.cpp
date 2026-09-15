#include "Span.hpp"
#include <iostream>

int main()
{
	try
	{
		Span a(2);
		
		a.addNumber(57);
		a.addNumber(1);
		
		std::vector<int> b;
		b.push_back(4);
		b.push_back(3);
		Span c(4);
		c.addNumber(2);
		c.addNumber(3);
		c.addNumber(b.end(), b.begin());
		std::cout << c;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
