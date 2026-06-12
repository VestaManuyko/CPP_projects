#include "DiamondTrap.hpp"

static void title(const std::string &s)
{
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	title("Constructors");
	DiamondTrap def;
	DiamondTrap rodger("Rodger");
	std::cout << "Default name: " << def.getName() << std::endl;
	std::cout << "Named: " << rodger.getName() << std::endl << std::endl;

	title("Copy constructor & assignment");
	DiamondTrap original("Original");
	DiamondTrap copy(original);
	DiamondTrap assigned;
	assigned = original;
	std::cout << "Original name: " << original.getName() << std::endl;
	std::cout << "Copy name: " << copy.getName() << std::endl;
	std::cout << "Assigned name: " << assigned.getName() << std::endl;
	std::cout << std::endl;

	title("Attack check");
	DiamondTrap attacker("Attacker");
	for (int i = 0; i < 2; ++i)
	{
		std::cout << "Attack #" << i + 1 << ":" << std::endl;
		attacker.attack("Target");
	}
	std::cout << std::endl;

	title("takeDamage to zero hitpoints");
	DiamondTrap victim("Victim");
	victim.takeDamage(100);
	victim.takeDamage(5);
	std::cout << std::endl;

	title("Cannot repair when HP is zero");
	DiamondTrap dead("Dead");
	dead.takeDamage(100);
	dead.beRepaired(5);
	std::cout << std::endl;


	title("beRepaired max amount");
	DiamondTrap big("Big");
	big.beRepaired(std::numeric_limits<unsigned int>::max());
	big.takeDamage(std::numeric_limits<unsigned int>::max());
	big.takeDamage(1);
	std::cout << std::endl;

	title("Inherited functions");
	big.guardGate();
	dead.highFiveGuys();
	std::cout << std::endl;

	title("whoAmI function");
	victim.whoAmI();
	big.whoAmI();
	std::cout << std::endl;
}
