#include "ScalarConverter.hpp"

void	printNone(const std::string &literal)
{
	(void)literal;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	printSpecialFloat(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << std::endl;
	std::cout << "double: " << literal.substr(0, literal.size() -1) << std::endl;
}

void	printSpecialDouble(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << 'f' << std::endl;
	std::cout << "double: " << literal << std::endl;
}
