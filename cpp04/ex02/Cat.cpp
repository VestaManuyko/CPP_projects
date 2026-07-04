#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	Animal::operator=(other);
	delete(_brain);
	_brain = new Brain(*other._brain);
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete(_brain);
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

void Cat::setIdea(int index, std::string idea)
{
	_brain->setIdea(index, idea);
}

const std::string &Cat::getIdea(int index) const
{
	return _brain->getIdea(index);
}
