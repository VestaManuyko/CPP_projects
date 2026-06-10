#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

bool bsp(Point const a,Point const b,Point const c,Point const point);

static void printPoint(const Point &p)
{
	std::cout << "(" << p.getX() << ", " << p.getY() << ")";
}

static void run_test(const std::string &name, bool expected, Point a, Point b, Point c, Point p)
{
	std::cout << "Testing: " << name << std::endl;
	std::cout << " Triangle: A="; printPoint(a); std::cout << " B="; printPoint(b); std::cout << " C="; printPoint(c); std::cout << std::endl;
	std::cout << " Point: "; printPoint(p); std::cout << std::endl;
	bool result = bsp(a, b, c, p);
	std::cout << " Expected: " << std::boolalpha << expected << ", Got: " << result << std::endl;
}

int main()
{
	std::cout << std::boolalpha;

	// Integer coordinates: inside
	run_test("Inside integer",
			 true,
			 Point(Fixed(0), Fixed(0)),
			 Point(Fixed(5), Fixed(0)),
			 Point(Fixed(0), Fixed(5)),
			 Point(Fixed(1), Fixed(1)));

	// Integer coordinates: outside
	run_test("Outside integer",
			 false,
			 Point(Fixed(0), Fixed(0)),
			 Point(Fixed(2), Fixed(0)),
			 Point(Fixed(0), Fixed(2)),
			 Point(Fixed(3), Fixed(3)));

	// On vertex
	run_test("On vertex (A)",
			 false,
			 Point(Fixed(0), Fixed(0)),
			 Point(Fixed(2), Fixed(0)),
			 Point(Fixed(0), Fixed(2)),
			 Point(Fixed(0), Fixed(0)));

	// On edge (between A and B)
	run_test("On edge AB",
			 false,
			 Point(Fixed(0), Fixed(0)),
			 Point(Fixed(2), Fixed(0)),
			 Point(Fixed(0), Fixed(2)),
			 Point(Fixed(1), Fixed(0)));

	// Float coordinates: inside
	run_test("Inside float",
			 true,
			 Point(Fixed(0.5f), Fixed(0.5f)),
			 Point(Fixed(2.5f), Fixed(0.5f)),
			 Point(Fixed(0.5f), Fixed(2.5f)),
			 Point(Fixed(1.0f), Fixed(1.0f)));

	// Mixed int/float coordinates
	run_test("Mixed int/float",
			 true,
			 Point(Fixed(0), Fixed(0.0f)),
			 Point(Fixed(5.5f), Fixed(0)),
			 Point(Fixed(0), Fixed(5.5f)),
			 Point(Fixed(1.5f), Fixed(1)));

	return 0;
}
