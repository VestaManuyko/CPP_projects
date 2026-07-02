#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
	return ;
}

Ice::Ice(const Ice& other)
{
	_type = other._type;
	return ;
}

Ice& Ice::operator=(const Ice& other)
{
	_type = other._type;
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