#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
    	DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other); 
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap();

	void				attack(const std::string &target);
	void 				whoAmI();
	const std::string 	&getName(void) const;

	private:
		std::string _name;
};

#endif
