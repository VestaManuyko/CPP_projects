#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
    	Cure();
		Cure(const Cure& other); 
		Cure& operator=(const Cure& other);
		~Cure() override;

		void use(ICharacter &target) override;
		AMateria *clone() const override;
};

#endif
