#include "Form.hpp"

Form::Form() : _name("default"), _reqGradeToSign(1), _reqGradeToExecute(150)
{
	_signed = false;
	return ;
}

Form::Form(const Form& other) : _name(other._name), _reqGradeToSign(other._reqGradeToSign), _reqGradeToExecute(other._reqGradeToExecute)
{
	_signed = false;
	return ;
}

Form& Form::operator=(const Form& other)
{
	_signed = other._signed;
	return (*this);
}

Form::~Form()
{
	return ;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Exception: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Exception: Grade too low!";
}
