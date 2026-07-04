#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	Animal	copy(*meta);
	copy = *meta;
	std::cout << std::endl;

	std::cout << meta->getType() << " is the type of meta" << std::endl;
	meta->makeSound();
	std::cout << j->getType() << " is the type of j" << std::endl;
	j->makeSound();
	std::cout << i->getType() << " is the type of i" << std::endl;
	i->makeSound();
	std::cout << copy.getType() << " is the type of copy" << std::endl;
	copy.makeSound();


	std::cout << std::endl << "----Wrong animal and cat tests----" << std::endl;
	WrongAnimal	*wrongmeta = new WrongAnimal();
	WrongAnimal *wrongi = new WrongCat();
	std::cout << wrongmeta->getType() << " is the type of wrongmeta" << std::endl;
	wrongmeta->makeSound();
	std::cout << wrongi->getType() << " is the type of wrongi" << std::endl;
	wrongi->makeSound();

	std::cout << std::endl;
	delete(meta);
	delete(i);
	delete(j);
	delete(wrongmeta);
	delete(wrongi);
}
