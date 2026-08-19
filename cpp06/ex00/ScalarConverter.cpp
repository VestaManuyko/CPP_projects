#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <iomanip>

type	getType(std::string literal)
{
	return CHAR;
}

void	convertChar(std::string literal)
{

}

void	convertInt(std::string literal)
{

}

void	convertFloat(std::string literal)
{

}

void	convertDouble(std::string literal)
{

}

void	convertNone(std::string literal)
{

}

void	ScalarConverter::convert(std::string literal)
{
	void (*methods[])(std::string literal) = {
		&convertChar,
		&convertInt,
		&convertFloat,
		&convertDouble,
		&convertNone
	};
	type inputType = getType(literal);
	methods[inputType](literal);
}
