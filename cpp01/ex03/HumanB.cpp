#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB()
{
	return ;
}

void HumanB::attack()
{
	if (!_weapon)
		std::cout << _name << " doesnt have a weapon" << std::endl;
	else
		std::cout << _name << " attacks with their "
			<< (*_weapon).getType() << std::endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
	_weapon = &Weapon;
}