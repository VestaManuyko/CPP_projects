#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : WrongAnimal
{
	public:
    	WrongCat();
		WrongCat(const WrongCat& other); 
		WrongCat& operator=(const WrongCat& other);
		~WrongCat();
};

#endif
