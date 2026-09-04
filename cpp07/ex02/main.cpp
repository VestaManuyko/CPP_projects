#include "Array.hpp"
#include <iostream>

int main()
{
	try
	{
		Array<int> a;
		Array<int> b(5);
	
		b[3] = 2;
		a = b;
		b[3] = 1;
		std::cout << b[3] << std::endl;
		std::cout << a[3] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
