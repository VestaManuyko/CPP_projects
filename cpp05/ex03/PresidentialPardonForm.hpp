#ifndef PRESIDENTiALPARDONFORM_HPP
# define PRESIDENTiALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string		_target;
	public:
    	PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other); 
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void	executeForm() const;
};

#endif
