#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
	return ;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;
	return ;
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Brain copy assignment called" << std::endl;
	for (int i = 0; i < 100; i++)
		_ideas[i] = other._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

void Brain::setIdea(int index, std::string idea)
{
	if (index > 100 || index < 0)
		return ;
	_ideas[index] = idea;
}

const std::string &Brain::getIdea(int index) const
{
	return _ideas[index];
}