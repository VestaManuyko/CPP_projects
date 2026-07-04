#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	return ;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	return ;
}

Ice& Ice::operator=(const Ice& other)
{
	AMateria::operator=(other);
	return (*this);
}

Ice::~Ice()
{
	return ;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}
