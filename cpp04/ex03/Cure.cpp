#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
	return ;
}

Cure::Cure(const Cure& other)
{
	_type = other._type;
	return ;
}

Cure& Cure::operator=(const Cure& other)
{
	_type = other._type;
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
