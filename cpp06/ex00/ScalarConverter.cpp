#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <iomanip>

void	convertChar(const std::string &literal)
{
	std::cout << "char: '" << literal << "'" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	convertInt(const std::string &literal)
{
	long 	nbr = 0;
	int		n = 0;
	char 	c = 0;
	errno = 0;
	nbr = std::strtol(literal.c_str(), NULL, 10);
	if (errno == ERANGE || nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
	{
		printNone(literal);
		return ;
	}
	n = static_cast<int>(nbr);
	if (n >= std::numeric_limits<char>::min() && n <= std::numeric_limits<char>::max())
	{
    	c = static_cast<char>(n);
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: not displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << 'f' << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void	convertFloat(const std::string &literal)
{
	char c = 0;
	errno = 0;
	double nbr = std::strtof(literal.c_str(), NULL);
	if (errno == ERANGE)
	{
		printNone(literal);
		return ;
	}
	if (nbr >= std::numeric_limits<char>::min() && nbr <= std::numeric_limits<char>::max())
	{
    	c = static_cast<char>(nbr);
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: not displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << nbr << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(nbr) << std::endl;
}

void	convertDouble(const std::string &literal)
{
	char c = 0;
	errno = 0;
	double nbr = std::strtod(literal.c_str(), NULL);
	if (errno == ERANGE)
	{
		printNone(literal);
		return ;
	}
	if (nbr >= std::numeric_limits<char>::min() && nbr <= std::numeric_limits<char>::max())
	{
    	c = static_cast<char>(nbr);
		if (isprint(c))
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: not displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;
	if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	if (nbr < -std::numeric_limits<float>::max() || nbr > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(nbr) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << nbr << std::endl;
}

void	ScalarConverter::convert(std::string literal)
{
	void (*methods[])(const std::string &literal) = {
		&convertChar,
		&convertInt,
		&convertFloat,
		&convertDouble,
		&printSpecialFloat,
		&printSpecialDouble,
		&printNone
	};
	type inputType = getType(literal);
	methods[inputType](literal);
}
