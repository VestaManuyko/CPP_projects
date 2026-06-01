#include "Zombie.hpp"
#include <new>

Zombie* newZombie(std::string name)
{
	Zombie *newZombie = NULL;

	try
	{
		newZombie = new Zombie(name);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return newZombie;
}
