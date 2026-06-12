#include "ScavTrap.hpp"

static void title(const std::string &s)
{
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	title("Constructors");
	ScavTrap def;
	ScavTrap rodger("Rodger");
	std::cout << "Default name: " << def.getName() << std::endl;
	std::cout << "Named: " << rodger.getName() << std::endl << std::endl;

	title("Copy constructor & assignment");
	ScavTrap original("Original");
	ScavTrap copy(original);
	ScavTrap assigned;
	assigned = original;
	std::cout << "Original name: " << original.getName() << std::endl;
	std::cout << "Copy name: " << copy.getName() << std::endl;
	std::cout << "Assigned name: " << assigned.getName() << std::endl;
	std::cout << std::endl;

	title("Attack & energy decrement");
	ScavTrap attacker("Attacker");
	ScavTrap target("Target");
	for (int i = 0; i < 51; ++i)
	{
		std::cout << "Attack #" << i + 1 << ":" << std::endl;
		attacker.attack(target.getName());
	}
	std::cout << std::endl;

	title("takeDamage to zero hitpoints");
	ScavTrap victim("Victim");
	victim.takeDamage(100);
	victim.takeDamage(5);
	std::cout << std::endl;

	title("beRepaired & energy decrement");
	ScavTrap repairer("Repairer");
	for (int i = 0; i < 51; ++i)
	{
		std::cout << "Repair #" << i + 1 << ":" << std::endl;
		repairer.beRepaired(1);
	}
	std::cout << std::endl;

	title("Cannot repair when HP is zero");
	ScavTrap dead("Dead");
	dead.takeDamage(100);
	dead.beRepaired(5);
	std::cout << std::endl;


	title("beRepaired max amount");
	ScavTrap big("Big");
	big.beRepaired(std::numeric_limits<unsigned int>::max());
	big.takeDamage(std::numeric_limits<unsigned int>::max());
	big.takeDamage(1);
	std::cout << std::endl;

	title("guardGate function");
	big.guardGate();
	dead.guardGate();
	std::cout << std::endl;
}
