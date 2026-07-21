#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _reqToSign(1), _reqToExecute(150)
{
	std::cout << "Default Aform is creted with grades: 1, 150\n";
	_signed = false;
	return ;
}

AForm::AForm(const AForm& other) : _name(other._name), _reqToSign(other._reqToSign), _reqToExecute(other._reqToExecute)
{
	_signed = false;
	return ;
}

AForm::AForm(std::string name, int reqToSign, int reqToExecute) : _name(name), _reqToSign(reqToSign), _reqToExecute(reqToExecute)
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
	std::cout << "AForm with these parameters: name- " << name  << ", required grade to sign- " << reqToSign << ", to execute- " << reqToExecute << ", was created." << std::endl;
	return ;
}

AForm& AForm::operator=(const AForm& other)
{
	_signed = other._signed;
	return (*this);
}

AForm::~AForm()
{
	return ;
}

const std::string &AForm::getName() const
{
	return _name;
}
const int &AForm::getReqToSign() const
{
	return _reqToSign;
}
const int &AForm::getReqToExecute() const
{
	return _reqToExecute;
}
const bool &AForm::isSigned() const
{
	return _signed;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Exception: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Exception: Grade too low!";
}

const char* AForm::FormNotSigned::what() const throw()
{
	return "Exception: Form not signed!";
}

std::ostream &operator<<(std::ostream &stream, const AForm &Aform)
{
	stream << Aform.getName() << " is ";
	if (Aform.isSigned() == true)
		stream << "signed.";
	else
		stream << "unsigned.";
	stream << std::endl;
	stream << "The required grade to sign is " << Aform.getReqToSign() << " and to execute is " << Aform.getReqToExecute() << "." << std::endl;
	return stream;
}

void	AForm::beSigned(Bureaucrat const &skippy)
{
	if (skippy.getGrade() > _reqToSign)
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::execute(Bureaucrat const &executor)
{
	if (executor.getGrade() > _reqToExecute)
		throw GradeTooLowException();
	if (_signed == false)
		throw FormNotSigned();
	executeForm();
}