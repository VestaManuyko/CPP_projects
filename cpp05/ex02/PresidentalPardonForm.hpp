#ifndef PRESIDENTALPARDONFORM_HPP
# define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentalPardonForm : public AForm
{
	public:
    	PresidentalPardonForm();
		PresidentalPardonForm(const PresidentalPardonForm& other); 
		PresidentalPardonForm& operator=(const PresidentalPardonForm& other);
		~PresidentalPardonForm();
};

#endif
