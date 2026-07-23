#include "Intern.hpp"

Intern::Intern()
{
	names[0] = "presidential pardon";
	names[1] = "robotomy request";
	names[2] = "shrubbery creation";
	creator[0] = &makePresident;
	creator[1] = &makeRobotomy;
	creator[2] = &makeShrubbery;
	return ;
}

Intern::Intern(const Intern& other)
{
	(void)other;
	names[0] = "presidential pardon";
	names[1] = "robotomy request";
	names[2] = "shrubbery creation";
	creator[0] = &makePresident;
	creator[1] = &makeRobotomy;
	creator[2] = &makeShrubbery;
	return ;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	return ;
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	for (int i = 0; i < 3; i++)
	{
		if (names[i] == form)
		{
			std::cout << "Intern creates " << form << std::endl;
			return (creator[i])(target);
		}
	}
	std::cout << "The form with name '" << form << "' does not exist." << std::endl;
	return NULL;
}

AForm *makePresident(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}