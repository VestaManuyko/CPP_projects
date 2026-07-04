#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	return ;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	return ;
}

Cure& Cure::operator=(const Cure& other)
{
	AMateria::operator=(other);
	return (*this);
}

Cure::~Cure()
{
	return ;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}
