#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45)
{
	_success = false;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45)
{
	_success = false;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	_success = false;
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

void	RobotomyRequestForm::executeForm(Bureaucrat const &executor)
{
	std::cout << "*drilling noises*" << std::endl;
	if (_success == false)
	{
		std::cout << "Robotomy failed.\n";
		_success = true;
	}
	else
	{
		std::cout << _target << " had been robotimized.\n";
		_success = false;
	}
}