#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	void	gradeTooHigh()	const;
	void	gradeTooLow()	const;

	public:
    	Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other); 
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

	std::string const	&getName() const;
	int const 			&getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &Bureaucrat);

#endif
