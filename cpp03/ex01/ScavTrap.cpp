#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default constructor ScavTrap called" << std::endl;
	_name = "no name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Constructor ScavTrap called" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "Copy constructor ScavTrap called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;

}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Copy assignment operator ScavTrap called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoints < 1)
	{
		std::cout << "No energy Points left, ScavTrap can't attack" << std::endl;
		return ;
	}
	if (_hitPoints < 1)
	{
		std::cout << "No hit Points left, ScavTrap can't attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage
			<< " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}