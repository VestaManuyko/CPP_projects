#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <string>

ScalarConverter::ScalarConverter() {} ;

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {} ;

void	ScalarConverter::convert(std::string literal)
{
	double nbr;
	int		int_nbr;
	size_t idx;
	try
	{
		nbr = std::stod(literal, &idx);
	}
	catch(const std::exception& e)
	{
		if (literal.size() == 1)
			std::cout << "char: " << literal << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	if (nbr > std::numeric_limits<int>::min() || nbr < std::numeric_limits<int>::max())
	{
		int_nbr = static_cast<int>(nbr);
		if (int_nbr >= 0 && int_nbr <= 255 && !std::isprint(static_cast<unsigned char>(int_nbr)))
				std::cout << "char: not displayable" << std::endl;
		else if (int_nbr < std::numeric_limits<char>::min() || int_nbr > std::numeric_limits<char>::max())
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: " << int_nbr << std::endl;
	}
	else
		std::cout << "int: impossible" << std::endl;
}
