#include "Zombie.hpp"

int main()
{
	Zombie *Boo;

	randomChump("Foo");
	Boo = newZombie("Boo");
	Boo->announce();
	delete(Boo);
}
