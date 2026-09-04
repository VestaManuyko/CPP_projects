#include "Array.hpp"
#include <iostream>

int main()
{
	try
	{
		Array<int> a;
		Array<int> b(5);
	
		std::cout << "Size of a: " << a.size() << std::endl;
		std::cout << "Size of b: " << b.size() << std::endl;
		b[3] = 2;
		a = b;
		b[3] = 1;
		std::cout << b[3] << std::endl;
		std::cout << a[3] << std::endl;
		std::cout << "Size of a: " << a.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<int> c(55);
		c[55];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<std::string> you(1);
		std::cout << "Size of string you: " << you.size() << std::endl;
		you[0] = "lallala";
		std::cout << "string holded in you[0] is " << you[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// try
	// {
	// 	const Array<int> d(2);
	// 	d[1] = 1;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}
