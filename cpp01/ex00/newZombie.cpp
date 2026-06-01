#include "Zombie.hpp"
#include <new>

Zombie* newZombie(std::string name)
{
	Zombie *newZombie = new Zombie(name);
	return newZombie;
}
