#include "Zombie.hpp"

int main()
{
	Zombie *Boo;

	randomChump("Foo");
	Boo = newZombie("Boo");
	if (!Boo)
		return (1);
	Boo->announce();
	delete(Boo);
}
