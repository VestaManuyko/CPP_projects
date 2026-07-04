#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
    	Ice();
		Ice(const Ice& other); 
		Ice& operator=(const Ice& other);
		~Ice() override;

		void use(ICharacter &target) override;
		AMateria *clone() const override;
};

#endif
