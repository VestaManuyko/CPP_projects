#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

enum type{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIALF,
	SPECIALD,
	NONE
};

class ScalarConverter
{
	private:
    	ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		static void	convert(std::string literal);
};

#endif
