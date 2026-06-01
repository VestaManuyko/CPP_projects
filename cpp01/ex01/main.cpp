#include "Zombie.hpp"

int main(void)
{
	int i = 0;
	int N = 5;
	Zombie *Horde = zombieHorde(N, "joe");
	if (!Horde)
		return 1;
	while (i < N)
	{
		Horde[i].announce();
		i++;
	}
	delete[](Horde);
}
