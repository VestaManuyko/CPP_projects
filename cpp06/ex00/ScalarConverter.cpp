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
	int 	i = 0;

	if (literal.size() == 1 && isalpha(literal[0]))
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

// void	convertChar(std::string literal)
// {
	
// }

// void	convertInt(std::string literal)
// {

// }

// void	convertFloat(std::string literal)
// {

// }

// void	convertDouble(std::string literal)
// {

// }

// void	printSpecial(std::string literal)
// {

// }

// void	printNone(std::string literal)
// {

// }

// void	ScalarConverter::convert(std::string literal)
// {
// 	// void (*methods[])(std::string literal) = {
// 	// 	&convertChar,
// 	// 	&convertInt,
// 	// 	&convertFloat,
// 	// 	&convertDouble,
// 	// 	&printSpecial,
// 	// 	&printNone
// 	// };
// 	// type inputType = getType(literal);
// 	// methods[inputType](literal);

// }

int main(int ac, char **argv)
{
	if (ac != 2)
		return 1;
	switch (getType(argv[1]))
	{
		case 0:
		{
			std::cout << "CHAR";
			break ;
		}
		case 1:
		{
			std::cout << "INT";
			break ;
		}
		case 2:
		{
			std::cout << "FLOAT";
			break ;
		}
		case 3:
		{
			std::cout << "DOUBLE";
			break ;
		}
		case 4:
		{
			std::cout << "SPECIAL";
			break ;
		}
		case 5:
		{
			std::cout << "NONE";
			break ;
		}
	}
	std::cout << std::endl;
}