#include "HumanB.hpp"

HumanB::HumanB()
{
	_name = "Default";
	hasWeapon = 0;
	return ;
}

HumanB::~HumanB()
{
	return ;
}

void HumanB::attack()
{
	if (!hasWeapon)
		return ;
	std::cout << _name << " attacks with their "
		<< _weapon.getType() << std::endl;
}
