#include "ScalarConverter.hpp"

int main(int ac, char **argv)
{
	if (ac != 2)
	{
		std::cout << "Invalid number of arguments.\n";
		return 1;
	}
	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
