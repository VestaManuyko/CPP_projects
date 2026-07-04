#include "AMateria.hpp"

AMateria::AMateria()
{
	return ;
}

AMateria::AMateria(const AMateria& other) : _type(other._type)
{
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	return ;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria()
{
	return ;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	return ;
}
