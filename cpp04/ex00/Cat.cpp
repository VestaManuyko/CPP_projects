#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
{
	_type = other._type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	_type = other._type;
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "Meow!" << std::endl;
}