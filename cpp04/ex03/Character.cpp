#include "Character.hpp"

Character::Character()
{
	_name = "no name";
	_slot = 0;
	for (int i = 0; i < 4; i++)
		_equipment[i] = NULL;
	return ;
}

Character::Character(std::string name) : _name(name), _slot(0)
{
	for (int i = 0; i < 4; i++)
		_equipment[i] = NULL;
	return ;
}

Character::Character(const Character& other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (other._equipment[i] != NULL)
		{
			if (_equipment[i] != NULL)
				delete _equipment[i];
			_equipment[i] = other._equipment[i]->clone();
			_slot++;
		}
	}
	return ;
}

Character& Character::operator=(const Character& other)
{
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (other._equipment[i] != NULL)
		{
			if (_equipment[i] != NULL)
				delete _equipment[i];
			_equipment[i] = other._equipment[i]->clone();
			_slot++;
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_equipment[i] != NULL)
			delete _equipment[i];
	}
	return ;
}

std::string const &Character::getName() const
{
	return _name;
}

void	Character::equip(AMateria *m)
{
	std::cout << _slot << std::endl;
	if (_slot > 3 || m == NULL)
		return ;
	_equipment[_slot] = m->clone();
	_slot++;
}
//Before calling uneqip, make sure to save the address of the materia,
//that you are about to unequip and later delete it to avoid memory leaks.
void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || _equipment[idx] == NULL)
		return ;
	_equipment[idx] = NULL;
	_slot--;
	if (_slot < 0)
		_slot = 0;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || _equipment[idx] == NULL)
		return ;
	_equipment[idx]->use(target);
}

AMateria *Character::getMateria(int idx) const
{
	if (idx < 0 || idx > 3)
		return NULL;
	return (_equipment[idx]);
}