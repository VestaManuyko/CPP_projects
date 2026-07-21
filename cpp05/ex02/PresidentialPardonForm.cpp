#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentalForm", 25, 5)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentalForm", 25, 5)
{
	_target = target;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
	return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

void	PresidentialPardonForm::executeForm() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}