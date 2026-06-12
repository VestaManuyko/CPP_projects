#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : public ClapTrap
{
	public:
    	ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other); 
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();
	
	void 	attack(const std::string &target);
	void	guardGate();

	private:
		std::string 	_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif
