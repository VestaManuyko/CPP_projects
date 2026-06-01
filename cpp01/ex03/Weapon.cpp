#include "Weapon.hpp"

Weapon::Weapon(void)
{
	_type = "Default";
	return ;
}

Weapon::Weapon(std::string type)
{
	_type = type;
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

const std::string &Weapon::getType(void)
{
	return _type;
}

void Weapon::setType(std::string type)
{
	_type = type;
}
