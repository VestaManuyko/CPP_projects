#include "Ice.hpp"

Ice::Ice()
{
	return ;
}

Ice::Ice(const Ice& other)
{
	return ;
}

Ice& Ice::operator=(const Ice& other)
{
	return (*this);
}

Ice::~Ice()
{
	return ;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* heals" << target.getName() << "'s wounds *\n";
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}
