#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	_name = "no name";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energyPoints < 1)
	{
		std::cout << "No energy Points left, can't attack" << std::endl;
		return ;
	}
	if (_hitPoints < 1)
	{
		std::cout << "No hit Points left, can't attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target
			<< ", causing " << _attackDamage
			<< " points of damage!" << std::endl;
	_energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " receives "
			<< amount << " points of damage!" << std::endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints < 1)
	{
		std::cout << "No energy Points left, can't repair" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " receives "
			<< amount << " hit points!" << std::endl;
	_energyPoints -= 1;
	_hitPoints += amount;
}

const std::string &ClapTrap::getName() const
{
	return _name;
}
