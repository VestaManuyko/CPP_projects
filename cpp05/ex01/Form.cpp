#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _reqToSign(1), _reqToExecute(150)
{
	std::cout << "Default form is creted with grades: 1, 150\n";
	_signed = false;
	return ;
}

Form::Form(const Form& other) : _name(other._name), _reqToSign(other._reqToSign), _reqToExecute(other._reqToExecute)
{
	_signed = false;
	return ;
}

Form::Form(std::string name, int reqToSign, int reqToExecute) : _name(name), _reqToSign(reqToSign), _reqToExecute(reqToExecute)
{
	_signed = false;
	if (reqToSign < 1)
		throw GradeTooHighException();
	if (reqToSign > 150)
		throw GradeTooLowException();
	if (reqToExecute < 1)
		throw GradeTooHighException();
	if (reqToExecute > 150)
		throw GradeTooLowException();
	std::cout << "Form with these parameters: name- " << name  << ", required grade to sign- " << reqToSign << ", to execute- " << reqToExecute << ", was created." << std::endl;
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

const std::string &Form::getName() const
{
	return _name;
}
const int &Form::getReqToSign() const
{
	return _reqToSign;
}
const int &Form::getReqToExecute() const
{
	return _reqToExecute;
}
const bool &Form::getSigned() const
{
	return _signed;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Exception: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Exception: Grade too low!";
}

std::ostream &operator<<(std::ostream &stream, const Form &form)
{
	stream << form.getName() << " is ";
	if (form.getSigned() == true)
		stream << "signed.";
	else
		stream << "unsigned.";
	stream << std::endl;
	stream << "The required grade to sign is " << form.getReqToSign() << " and to execute is " << form.getReqToExecute() << "." << std::endl;
	return stream;
}

void	Form::beSigned(Bureaucrat const &skippy)
{
	if (skippy.getGrade() > _reqToSign)
		throw GradeTooLowException();
	_signed = true;
}
