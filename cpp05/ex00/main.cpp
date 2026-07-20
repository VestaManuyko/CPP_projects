#include "Bureaucrat.hpp"

static void title(const std::string &s)
{
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	title("Bureaucrat creation with negative grade");
	try
	{
		Bureaucrat("John", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}