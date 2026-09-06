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

int main()
{
	try
	{
		int arr[] = {1, 2, 3, 4, 5};
		iter(arr, 5, print<int>);
		iter(arr, 5, printconst<int>);
		Zombie *arr3 = new Zombie[3];
		iter(arr3, 3, print<Zombie>);
		delete[] arr3;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
