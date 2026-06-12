#include "FragTrap.hpp"

static void title(const std::string &s)
{
    std::cout << "=== " << s << " ===" << std::endl;
}

int main()
{
	title("Constructors");
	FragTrap def;
	FragTrap rodger("Rodger");
	std::cout << "Default name: " << def.getName() << std::endl;
	std::cout << "Named: " << rodger.getName() << std::endl << std::endl;
	
	title("Copy constructor & assignment");
	FragTrap original("Original");
	FragTrap copy(original);
	FragTrap assigned;
	assigned = original;
	std::cout << "Original name: " << original.getName() << std::endl;
	std::cout << "Copy name: " << copy.getName() << std::endl;
	std::cout << "Assigned name: " << assigned.getName() << std::endl;
	std::cout << std::endl;

	title("takeDamage to zero hitpoints");
	FragTrap victim("Victim");
	victim.takeDamage(100);
	victim.takeDamage(5);
	std::cout << std::endl;

	title("Cannot repair when HP is zero");
	FragTrap dead("Dead");
	dead.takeDamage(100);
	dead.beRepaired(5);
	std::cout << std::endl;

	title("beRepaired max amount");
	FragTrap big("Big");
	big.beRepaired(std::numeric_limits<unsigned int>::max());
	big.takeDamage(std::numeric_limits<unsigned int>::max());
	big.takeDamage(1);
	std::cout << std::endl;

	title("High-five request function");
	big.highFiveGuys();
	dead.highFiveGuys();
	std::cout << std::endl;
}
