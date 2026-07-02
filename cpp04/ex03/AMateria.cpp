#include "AMateria.hpp"

AMateria::AMateria()
{
	return ;
}

AMateria::AMateria(const AMateria& other)
{
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	return ;
}

AMateria& AMateria::operator=(const AMateria& other)
{
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
	return ;
}
