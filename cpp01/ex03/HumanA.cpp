#include "HumanA.hpp"

HumanA::HumanA(std::string name, std::string type)
{
	_name = name;
	_weapon.setType(type);
	return ;
}

HumanA::~HumanA()
{
	return ;
}

void HumanA::attack()
{
	std::cout << _name << " attacks with their "
		<< _weapon.getType() << std::endl;
}
