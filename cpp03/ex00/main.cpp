#include "ClapTrap.hpp"

static void title(const std::string &s)
{
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	title("Constructors");
	ClapTrap def;
	ClapTrap rodger("Rodger");
	std::cout << "Default name: " << def.getName() << std::endl;
	std::cout << "Named: " << rodger.getName() << std::endl << std::endl;
	
	title("Copy constructor & assignment");
	ClapTrap original("Original");
	ClapTrap copy(original);
	ClapTrap assigned;
	assigned = original;
	std::cout << "Original name: " << original.getName() << std::endl;
	std::cout << "Copy name: " << copy.getName() << std::endl;
	std::cout << "Assigned name: " << assigned.getName() << std::endl;
	std::cout << std::endl;

	title("Attack & energy decrement");
	ClapTrap attacker("Attacker");
	ClapTrap target("Target");
	for (int i = 0; i < 11; ++i)
	{
		std::cout << "Attack #" << i + 1 << ":" << std::endl;
		attacker.attack(target.getName());
	}
	std::cout << std::endl;

	title("takeDamage to zero hitpoints");
	ClapTrap victim("Victim");
	victim.takeDamage(10);
	victim.takeDamage(5);
	std::cout << std::endl;

	title("beRepaired & energy decrement");
	ClapTrap repairer("Repairer");
	for (int i = 0; i < 11; ++i)
	{
		std::cout << "Repair #" << i + 1 << ":" << std::endl;
		repairer.beRepaired(1);
	}
	std::cout << std::endl;

	title("Cannot repair when HP is zero");
	ClapTrap dead("Dead");
	dead.takeDamage(10);
	dead.beRepaired(5);
	std::cout << std::endl;


	title("beRepaired max amount");
	ClapTrap big("Big");
	big.beRepaired(std::numeric_limits<unsigned int>::max());
	big.takeDamage(std::numeric_limits<unsigned int>::max());
	big.takeDamage(1);
	std::cout << std::endl;
}
