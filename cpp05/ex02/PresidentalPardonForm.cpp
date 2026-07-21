#include "PresidentalPardonForm.hpp"

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
	return (*this);
}

PresidentalPardonForm::~PresidentalPardonForm()
{
	return ;
}
