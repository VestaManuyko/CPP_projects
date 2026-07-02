#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

class ICharacter
{
	public:
    	ICharacter();
		ICharacter(const ICharacter& other); 
		ICharacter& operator=(const ICharacter& other);
		~ICharacter();
};

#endif
