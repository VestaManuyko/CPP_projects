#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cerrno>

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
	char 	*endptr = NULL;
	errno = 0;
	long	nbr = strtol(literal.c_str(), &endptr, 10);

	if (errno != ERANGE)
	{
		if (endptr != NULL)
		{
			if (endptr[1] == '\0')
				std::cout << "char: " << endptr[0] << std::endl;
			else
			{
				if (endptr[0] == '\0' && nbr >= 0 && nbr <= 255 && !std::isprint(static_cast<unsigned char>(nbr)))
					std::cout << "char: not displayable" << std::endl;
				else
					std::cout << "char: impossible1" << std::endl;
			}
			if (endptr[0] != '\0')
				std::cout << "int: impossible1" << std::endl;
			else
			{
				if (nbr < std::numeric_limits<int>::min() || nbr > std::numeric_limits<int>::max())
					std::cout << "int: impossible2" << std::endl;
				std::cout << "int: " << nbr << std::endl;
			}
		}
	}
	else
	{
		std::cout << "char: impossible3" << std::endl;
		std::cout << "int: impossible3" << std::endl;
	}
}
