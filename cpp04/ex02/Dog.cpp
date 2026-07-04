#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal()
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	Animal::operator=(other);
	delete(_brain);
	_brain = new Brain(*other._brain);
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete(_brain);
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Bark!" << std::endl;
}

void Dog::setIdea(int index, std::string idea)
{
	_brain->setIdea(index, idea);
}

const std::string &Dog::getIdea(int index) const
{
	return _brain->getIdea(index);
}