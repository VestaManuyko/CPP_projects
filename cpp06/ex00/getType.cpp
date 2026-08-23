#include "ScalarConverter.hpp"

static bool	isSpecial(std::string literal)
{
	std::string	special[4] = {"nan", "nanf", "inf", "inff"};

	if (literal[0] == '+' || literal[0] == '-')
		literal.erase(0, 1);
	for (int i = 0; i < 4; i++)
	{
		if (literal == special[i])
			return 1;
	}
	return 0;
}

static type	whichSpecial(const std::string &literal)
{
	if (literal[literal.size() -1] == 'f' && literal[literal.size() -2] == 'f')
		return SPECIALF;
	if (literal == "nanf")
		return SPECIALF;
	return SPECIALD;
}

type	getType(const std::string &literal)
{
	unsigned long 	i = 0;

	if (literal.empty())
		return NONE;
	if (literal.size() == 1 && isprint(literal[0]) && !isdigit(literal[0]))
		return CHAR;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	while (literal[i])
	{
		if (!isdigit(literal[i]))
		{
			if (isSpecial(literal))
				return whichSpecial(literal);
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