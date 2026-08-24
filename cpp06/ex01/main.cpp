#include "Serializer.hpp"

#include <iostream>

int main()
{
	Data x;
	x.x = 5;
	Data *y = Serializer::deserialize(Serializer::serialize(&x));
	std::cout << "og pointer: " << &x << "\nafter serializer:  " << y << std::endl;
	std::cout << "the value og: " << x.x << "\nthe value after serializer: " << y->x << std::endl;
}
