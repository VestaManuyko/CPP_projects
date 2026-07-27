#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Default bureucrat was created with lowest grade 150.\n";
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat named " << _name << " with grade " << _grade << " was created.\n";
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

void Bureaucrat::incrementGrade()
{
	_grade--;
	if (_grade < 1)
	{
		_grade++;
		throw GradeTooHighException();
	}
	if (_grade > 150)
	{
		_grade++;
		throw GradeTooLowException();
	}
	std::cout << "Grade upgraded\n";
}

void Bureaucrat::decrementGrade()
{
	_grade++;
	if (_grade < 1)
	{
		_grade--;
		throw GradeTooHighException();
	}
	if (_grade > 150)
	{
		_grade--;
		throw GradeTooLowException();
	}
	std::cout << "Grade lowered\n";
}

std::string const &Bureaucrat::getName() const
{
	return _name;
}

int	Bureaucrat::getGrade() const
{
	return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Exception: Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Exception: Grade too low!";
}

void	Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}