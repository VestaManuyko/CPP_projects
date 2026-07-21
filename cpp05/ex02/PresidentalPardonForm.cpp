#include "PresidentalPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentalPardonForm::PresidentalPardonForm() : AForm("PresidentalPardon", 25, 5)
{
	return ;
}

PresidentalPardonForm::PresidentalPardonForm(std::string target) : AForm("PresidentalForm", 25, 5)
{
	_target = target;
	return ;
}

PresidentalPardonForm::PresidentalPardonForm(const PresidentalPardonForm& other) : AForm(other)
{
	return ;
}

PresidentalPardonForm& PresidentalPardonForm::operator=(const PresidentalPardonForm& other)
{
	(void)other;
	return (*this);
}

PresidentalPardonForm::~PresidentalPardonForm()
{
	return ;
}

void	PresidentalPardonForm::executeForm() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}