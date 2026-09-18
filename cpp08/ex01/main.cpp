#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

static void title(const std::string &s)
{
	std::cout << std::endl;
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	try
	{
		title("Subject+/simple test");
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Expected output:\n2\n14\n";
		std::cout << "Current output:\n";
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "Trying to add a value over max capacity using simple addNumber:\n";
		sp.addNumber(6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		title("100000 ints");
		std::srand(std::time(NULL));
		std::vector<int> values;
		for (int i = 0; i < 100000; i++)
			values.push_back(std::rand());
		
		std::cout << "Creating Span using a range:\n";
		Span range(100000);

		range.addNumber(values.begin(), values.end());
		std::cout << "Created.\n";
		std::cout << "Shortest span: " << range.shortestSpan() << std::endl;
		std::cout << "Longest span: " << range.longestSpan() << std::endl;

		std::cout << "Trying to add a value over max allowed using range:\n";
		range.addNumber(values.begin(), values.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		title("Shortest span on an empty span:");
		Span empty;
		empty.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		title("Longest span on an empty span:");
		Span empty;
		empty.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		title("Shortest span on a span with 1 number:");
		Span lonely(1);
		lonely.addNumber(1);
		lonely.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		title("Longestest span on a span with 1 number:");
		Span lonely(1);
		lonely.addNumber(1);
		lonely.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		title("Span with negative numbers + max span");
		Span negative(4);
		negative.addNumber(-5);
		negative.addNumber(-4);
		negative.addNumber(2147483647);
		negative.addNumber(-2147483648);
		
		std::cout << "Shortest span: " << negative.shortestSpan() << std::endl;
		std::cout << "Longest span: " << negative.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
