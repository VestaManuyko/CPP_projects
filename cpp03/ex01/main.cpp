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
}
