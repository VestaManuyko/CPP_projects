#include "Span.hpp"
#include <iostream>

int main()
{
	{
	try
	{
		Span a(2);
		
		a.addNumber(57);
		a.addNumber(1);
		
		std::vector<int> b;
		b.push_back(14);
		b.push_back(33);
		Span c(4);
		c.addNumber(25);
		c.addNumber(3);
		c.addNumber(b.end(), b.begin());
		// std::cout << c;
		std::cout << c.shortestSpan() << std::endl;
		Span d;
		std::cout << d.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	}
	{
		try
		{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
}
