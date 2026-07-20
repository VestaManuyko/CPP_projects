#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_reqToSign;
		int const			_reqToExecute;
	public:
    	Form();
		Form(std::string name, int reqToSign, int reqToExecute);
		Form(const Form& other); 
		Form& operator=(const Form& other);
		~Form();

	const std::string &getName() const;
	const int &getReqToSign() const;
	const int &getReqToExecute() const;
	const bool &getSigned() const;

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

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif
