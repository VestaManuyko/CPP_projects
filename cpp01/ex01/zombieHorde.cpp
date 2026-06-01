#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *Horde;

	try
	{
		Horde = new Zombie(name)[N];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}
