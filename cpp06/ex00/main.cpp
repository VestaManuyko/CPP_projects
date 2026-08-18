#include "ScalarConverter.hpp"

static void title(const std::string &s)
{
	std::cout << std::endl;
	std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	title("0");
	ScalarConverter::convert("0");

	title("42");
	ScalarConverter::convert("42");

	title("-1");
	ScalarConverter::convert("-1");

	title("5.0");
	ScalarConverter::convert("5.0");

	title("n");
	ScalarConverter::convert("n");

	title("inf");
	ScalarConverter::convert("inf");

	title("-inf");
	ScalarConverter::convert("-inf");

	title("nan");
	ScalarConverter::convert("nan");

	title("2147483647 (int max)");
	ScalarConverter::convert("2147483647");

	title("-2147483648 (int min)");
	ScalarConverter::convert("-2147483648");

	title("2147483648 (int max overflow)");
	ScalarConverter::convert("2147483648");

	title("-2147483649 (int min underflow)");
	ScalarConverter::convert("-2147483649");

	title("340282346638528859811704183484516925440.0 (float max)");
	ScalarConverter::convert("340282346638528859811704183484516925440.0");

	title("-340282346638528859811704183484516925440.0 (float min)");
	ScalarConverter::convert("-340282346638528859811704183484516925440.0");

	title("3.4028236e38 (float max overflow)");
	ScalarConverter::convert("3.4028236e38");

	title("hello");
	ScalarConverter::convert("hello");

	title("12.3.4");
	ScalarConverter::convert("12.3.4");

	title("++42");
	ScalarConverter::convert("++42");

	title("--42");
	ScalarConverter::convert("--42");

	title("1e309");
	ScalarConverter::convert("1e309");

	title("abc");
	ScalarConverter::convert("abc");

	title("nan123");
	ScalarConverter::convert("nan123");

	title("infx");
	ScalarConverter::convert("infx");

	title("*");
	ScalarConverter::convert("*");
}
