#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequest", 72, 45)
{
	_target = target;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
	_target = other._target;
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	AForm::operator=(other);
	_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

void	RobotomyRequestForm::executeForm() const
{
	std::cout << "*drilling noises*" << std::endl;
	if (rand() % 2)
		std::cout << "Robotomy failed.\n";
	else
		std::cout << _target << " had been robotimized.\n";
}