#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		gradeTooHigh();
	if (grade > 150)
		gradeTooLow();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &Bureaucrat)
{
	stream << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << "." << std::endl;
	return stream;
}

void	Bureaucrat::gradeTooHigh() const
{
	throw(std::out_of_range("Bureaucrat::GradeTooHighException"));
}

void	Bureaucrat::gradeTooLow() const
{
	throw(std::out_of_range("Bureaucrat::GradeTooLowException"));
}

void Bureaucrat::incrementGrade()
{
	_grade--;
	if (_grade < 1)
		gradeTooHigh();
	if (_grade > 150)
		gradeTooLow();
}

void Bureaucrat::decrementGrade()
{
	_grade++;
	if (_grade < 1)
		gradeTooHigh();
	if (_grade > 150)
		gradeTooLow();
}

std::string const &Bureaucrat::getName() const
{
	return _name;
}

int const &Bureaucrat::getGrade() const
{
	return _grade;
}