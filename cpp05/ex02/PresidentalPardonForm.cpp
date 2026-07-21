#include "PresidentalPardonForm.hpp"

PresidentalPardonForm::PresidentalPardonForm() : AForm("PresidentalPardon", 25, 5)
{
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
