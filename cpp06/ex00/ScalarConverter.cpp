#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <iomanip>

bool	isSpecial(std::string literal)
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

type	whichSpecial(const std::string &literal)
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
