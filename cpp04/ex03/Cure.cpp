#include "Cure.hpp"

Cure::Cure()
{
	return ;
}

Cure::Cure(const Cure& other)
{
	return ;
}

Cure& Cure::operator=(const Cure& other)
{
	return (*this);
}

Cure::~Cure()
{
	return ;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at" << target.getName() << "*\n";
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}
