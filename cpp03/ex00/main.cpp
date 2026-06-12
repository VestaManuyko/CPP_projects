#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("Rodger");

	b.attack(a.getName());
	b.takeDamage(0);
	b.attack(a.getName());
	b.beRepaired(2147483647);
	b.attack(a.getName());
}
