#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <iomanip>

bool	isSpecial(std::string literal)
{
	std::string	special[6] = {"nan", "nanf", "inf", "inff", "inf", "inff"};

	if (literal[0] == '+' || literal[0] == '-')
		literal.erase(0, 1);
	for (int i = 0; i < 6; i++)
	{
		if (literal == special[i])
			return 1;
	}
	return 0;
}

type	getType(std::string literal)
{
	unsigned long 	i = 0;

	if (literal.size() == 1 && isprint(literal[0]))
		return CHAR;
	while (literal[i])
	{
		if (!isdigit(literal[i]))
		{
			if (isSpecial(literal))
				return SPECIAL;
			if (literal[i] == '.')
			{
				i++;
				while (i < literal.size() - 1)
				{
					if (!isdigit(literal[i]))
						return NONE;
					i++;
				}
				if (!isdigit(literal[i]) && literal[i] != 'f')
					return NONE;
				else if (literal[i] == 'f')
					return FLOAT;
				else
					return DOUBLE;
			}
			return NONE;
		}
		i++;
	}
	return INT;
}

void	convertChar(std::string literal)
{
	std::cout << "char: '" << literal << "'" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	convertInt(std::string literal)
{
	(void)literal;
}

void	convertFloat(std::string literal)
{
	(void)literal;
}

void	convertDouble(std::string literal)
{
	(void)literal;
}

void	printSpecial(std::string literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << literal << 'f' << std::endl;
	std::cout << "double: " << literal << std::endl;
}

void	printNone(std::string literal)
{
	(void)literal;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void	ScalarConverter::convert(std::string literal)
{
	void (*methods[])(std::string literal) = {
		&convertChar,
		&convertInt,
		&convertFloat,
		&convertDouble,
		&printSpecial,
		&printNone
	};
	type inputType = getType(literal);
	methods[inputType](literal);

}
