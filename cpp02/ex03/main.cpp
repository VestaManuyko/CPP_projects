#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

bool bsp(Point const a,Point const b,Point const c,Point const point);

int main()
{
	Point const a(5, 0);
	Point const b(0, 0);
	Point const c(0, 5);
	Point const point(3, 1);
	std::cout << std::boolalpha;
	std::cout << bsp(a, b ,c ,point) << std::endl;
	return 0;
}
