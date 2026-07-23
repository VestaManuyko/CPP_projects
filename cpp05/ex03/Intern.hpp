#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		std::string	names[3];
		AForm *(Intern::*creator[3])(std::string);

	AForm *makePresident(std::string target);
	AForm *makeRobotomy(std::string target);
	AForm *makeShrubbery(std::string target);

	public:
    	Intern();
		Intern(const Intern& other); 
		Intern& operator=(const Intern& other);
		~Intern();

	AForm	*makeForm(std::string form, std::string target);
};

#endif
