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

//print.cpp
void	printNone(const std::string &literal);
void	printSpecialFloat(const std::string &literal);
void	printSpecialDouble(const std::string &literal);
//getType.cpp
type	getType(const std::string &literal);

#endif
