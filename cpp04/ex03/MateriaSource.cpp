#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	_slot = 0;
	for (int i = 0; i < 4; i++)
		_known[i] = NULL;
	return ;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._known[i] != NULL)
		{
			if (_known[i] != NULL)
				delete _known[i];
			_known[i] = other._known[i]->clone();
			_slot++;
		}
	}
	return ;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._known[i] != NULL)
		{
			if (_known[i] != NULL)
				delete _known[i];
			_known[i] = other._known[i]->clone();
			_slot++;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (_known[i] != NULL)
			delete _known[i];
	}
	return ;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (_slot > 3 || m == NULL)
		return ;
	_known[_slot] = m->clone();
	_slot++;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 3; i++)
	{
		if (_known[i] != NULL)
		{
			if (_known[i]->getType() == type)
				return _known[i]->clone();
		}
	}
	return NULL;
}
