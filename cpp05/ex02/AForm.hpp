#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_reqToSign;
		int const			_reqToExecute;
	public:
    	AForm();
		AForm(std::string name, int reqToSign, int reqToExecute);
		AForm(const AForm& other); 
		AForm& operator=(const AForm& other);
		~AForm();

	const std::string 	&getName() const;
	const int 			&getReqToSign() const;
	const int 			&getReqToExecute() const;
	const bool 			&getSigned() const;
	void				beSigned(Bureaucrat const &skippy);
	virtual void 		beExecuted() = 0;

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
