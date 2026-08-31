#include "iter.hpp"
#include <iostream>

template <typename T>
void	print(T &x)
{
	std::cout << x << std::endl;
}
template <typename T>
void	printconst(const T &x)
{
	std::cout << "const " << x << std::endl;
}

class Zombie
{
	public:
		Zombie() {};
		~Zombie() {};
};


std::ostream & operator<<(std::ostream &stream, const Zombie &zombie)
{
	(void)zombie;
	stream << "Zoombie";
	return stream; 
}

Zombie* zombieHorde(int N)
{
	Zombie *Horde = NULL;

	if (N < 1)
		return NULL;
	try
	{
		Horde = new Zombie[N];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (Horde);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 5, print<int>);
	iter(arr, 5, printconst<int>);
	Zombie *arr3 = zombieHorde(5);
	iter(arr3, 5, print<Zombie>);
	delete[] arr3;
}
