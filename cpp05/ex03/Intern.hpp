#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

class Intern
{
	public:
    	Intern();
		Intern(const Intern& other); 
		Intern& operator=(const Intern& other);
		~Intern();

	void	makeForm(std::string form, std::string target);
};

#endif
