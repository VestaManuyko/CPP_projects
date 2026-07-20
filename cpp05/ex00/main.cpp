#include "Bureaucrat.hpp"

static void title(const std::string &s)
{
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	title("Highest grade decrement/increment");
	Bureaucrat slippy("Slippy", 1);
	try
	{
		slippy.decrementGrade();
		slippy.incrementGrade();
		slippy.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	Bureaucrat def;
	try
	{
		def.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	
	title("Too high grade parameter");
	try
	{
		Bureaucrat john("John", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	title("Too Low grade parameter");
	try
	{
		Bureaucrat john("John", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl << std::endl;
	}
	title("<< operator overload");
	std::cout << slippy;
}