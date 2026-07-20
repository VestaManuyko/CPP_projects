#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_reqGradeToSign;
		int const			_reqGradeToExecute;
	public:
    	Form();
		Form(const Form& other); 
		Form& operator=(const Form& other);
		~Form();

	class GradeTooHighException : public std::exception
	{
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

};

#endif
