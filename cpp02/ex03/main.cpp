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
	run_test("Inside triangle",
			 true,
		 Point(0.0f, 0.0f),
		 Point(5.0f, 0.0f),
		 Point(0.0f, 5.0f),
		 Point(1.0f, 1.0f));

	// Integer coordinates: outside
	run_test("Outside triangle",
			 false,
			 Point(0.0f, 0.0f),
			 Point(2.0f, 0.0f),
			 Point(0.0f, 2.0f),
			 Point(3.0f, 3.0f));

	// On vertex
	run_test("On vertex (A)",
			 false,
			 Point(0.0f, 0.0f),
			 Point(2.0f, 0.0f),
			 Point(0.0f, 2.0f),
			 Point(0.0f, 0.0f));

	// On edge (between A and B)
	run_test("On edge AB",
			 false,
			 Point(0.0f, 0.0f),
			 Point(2.0f, 0.0f),
			 Point(0.0f, 2.0f),
			 Point(1.0f, 0.0f));

	// Float coordinates: inside
	run_test("Inside triangle",
			 true,
			 Point(0.5f, 0.5f),
			 Point(2.5f, 0.5f),
			 Point(0.5f, 2.5f),
			 Point(1.0f, 1.0f));

	// Mixed int/float coordinates
	run_test("Iside triangle",
			 true,
			 Point(0.0f, 0.0f),
			 Point(5.5f, 0.0f),
			 Point(0.0f, 5.5f),
			 Point(1.5f, 1.0f));

	return 0;
}
