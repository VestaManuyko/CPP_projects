#include "ClapTrap.hpp"

int main()
{
	ClapTrap a;
	ClapTrap b("Rodger");

	b.attack(a.getName());
	b.takeDamage(20);
	b.attack(a.getName());
	b.beRepaired(20);
	b.attack(a.getName());
}
