#include "Bureaucrat.hpp"
#include "Form.hpp"

static void title(const std::string &s)
{
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	title("Form creation with wrong grades");
	try
	{
		Form john("John", -1, 41);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	try
	{
		Form john("John", 1, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	title("Form signage with wrong grade");
	Form john("John", 1, 1);
	std::cout << john;
	Bureaucrat johny("Johny", 1);
	johny.signForm(john);
	std::cout << john;
	Bureaucrat bip("Bip", 150);
	bip.signForm(john);
}