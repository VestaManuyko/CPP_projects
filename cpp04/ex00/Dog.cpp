#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
{
	_type = other._type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	_type = other._type;
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound()
{
	std::cout << "Bark!" << std::endl;
}