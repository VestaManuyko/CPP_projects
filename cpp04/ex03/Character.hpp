#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>

class Character
{
	public:
    	Character();
		Character(const Character& other); 
		Character& operator=(const Character& other);
		~Character();
};

#endif
