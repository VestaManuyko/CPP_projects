#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <iomanip>

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
	double	nbr;
	int		int_nbr;
	char	*endptr;
	errno = 0;

	nbr = std::strtod(literal.c_str(), &endptr);
	if (errno == ERANGE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (endptr[0] != '\0')
	{
		if (literal.size() == 1 && isalpha(literal[0]))
			std::cout << "char: '" << literal << "'" << std::endl;
		else
			std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	else if (nbr >= std::numeric_limits<int>::min() && nbr <= std::numeric_limits<int>::max())
	{
		int_nbr = static_cast<int>(nbr);
		if ((int_nbr >= std::numeric_limits<char>::min() && int_nbr <= std::numeric_limits<char>::max()) && !std::isprint(static_cast<unsigned char>(int_nbr)))
				std::cout << "char: not displayable" << std::endl;
		else if (int_nbr < std::numeric_limits<char>::min() || int_nbr > std::numeric_limits<char>::max())
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(int_nbr) << "'" << std::endl;
		std::cout << "int: " << int_nbr << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	if (nbr == std::numeric_limits<double>::infinity() ||
        nbr == -std::numeric_limits<double>::infinity())
	{
		std::cout << "float: " << (nbr > 0 ? "inff" : "-inff") << std::endl;
	}
	else if (nbr < -std::numeric_limits<float>::max() || nbr > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << nbr << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << nbr << std::endl;
}
