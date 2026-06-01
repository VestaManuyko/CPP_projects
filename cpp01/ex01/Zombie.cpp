#include "Zombie.hpp"

Zombie::Zombie(void)
{
	_name = "Default";
	return ;
}

Zombie::Zombie(std::string myName)
{
	_name = myName;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called, " << _name << ": destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	_name = name;
}
