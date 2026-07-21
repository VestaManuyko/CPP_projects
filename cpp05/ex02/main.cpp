#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentalPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

static void title(const std::string &s)
{
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	title("Shrubbery form");
	ShrubberyCreationForm shrub("home");
	Bureaucrat john("John", 137);
	try {
		john.executeForm(shrub);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		john.signForm(shrub);
		john.executeForm(shrub);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	title("Robotomy form");
	RobotomyRequestForm robot("robot");
	Bureaucrat bob("Bob", 45);
	try {
		bob.executeForm(robot);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		bob.signForm(robot);
		bob.executeForm(robot);
		john.executeForm(robot);
		bob.executeForm(robot);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	title("President form");
	PresidentalPardonForm pardon("the world");
	Bureaucrat bip("Bip", 5);
	try {
		bip.executeForm(pardon);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	try
	{
		bip.signForm(pardon);
		bip.executeForm(pardon);
		john.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}