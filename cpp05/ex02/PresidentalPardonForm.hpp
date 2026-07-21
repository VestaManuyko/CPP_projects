#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentalPardonForm : public AForm
{
	private:
		std::string		_target;
	public:
    	PresidentalPardonForm();
		PresidentalPardonForm(std::string target);
		PresidentalPardonForm(const PresidentalPardonForm& other); 
		PresidentalPardonForm& operator=(const PresidentalPardonForm& other);
		~PresidentalPardonForm();
};

#endif
