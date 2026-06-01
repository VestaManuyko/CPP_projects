#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *Horde = NULL;
	int i = 0;

	if (N < 1)
		return NULL;
	try
	{
		Horde = new Zombie[N];
		while (i < N)
		{
			Horde[i].setName(name);
			i++;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (Horde);
}
