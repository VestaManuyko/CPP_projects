#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << "\n----Array creation----\n";
	Animal *array[10];
	
	int	i = 0;
	while (i < 5)
		array[i++] = new Dog;
	while (i < 10)
		array[i++] = new Cat;
	i = 0;
	while (i < 10)
	{
		std::cout << "Element " << i << " is of type " << array[i]->getType() << std::endl;
		i++;
	}
	i = 0;
	while(i < 10)
		delete(array[i++]);

	std::cout << "\n----Deep copy test----\n";
	Dog basic;
	{
		Dog tmp;
		tmp = basic;
	}
	std::cout << std::endl;
	basic.setIdea(0, "llalala");
	std::cout << basic.getIdea(0);
	std::cout << std::endl;
	std::cout << "\n----Subject test(virtual destructor test)----\n";
	const Animal *j = new Dog();
	const Animal *k = new Cat();
	delete (j);
	delete (k);
	std::cout << std::endl;
}
