#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_reqToSign;
		int const			_reqToExecute;

	protected:
		virtual void 		executeForm() const = 0;

	public:
    	AForm();
		AForm(std::string name, int reqToSign, int reqToExecute);
		AForm(const AForm& other); 
		AForm& operator=(const AForm& other);
		virtual ~AForm();

	const std::string 	&getName() const;
	const int 			&getReqToSign() const;
	const int 			&getReqToExecute() const;
	const bool 			&isSigned() const;
	void				beSigned(Bureaucrat const &skippy);
	void				execute(Bureaucrat const &executor) const;

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
	class FormNotSigned : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &stream, const AForm &Aform);

#endif
