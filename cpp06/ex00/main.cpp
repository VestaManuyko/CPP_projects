#include "ScalarConverter.hpp"

static void title(const std::string &s)
{
	std::cout << std::endl;
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	title("Tests");
	ScalarConverter::convert("n");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("5");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("287398214812482104712094");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("-1");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("126");
	std::cout << "_______________" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "_______________" << std::endl;
}
