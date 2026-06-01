#include "Zombie.hpp"

Zombie::Zombie(std::string myName)
{
	name = myName;
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "Destructor called, " << name << ": destroyed." << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
