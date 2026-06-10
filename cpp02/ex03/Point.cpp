#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	return ;
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
	return ;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y)
{
	return ;
}

Point &Point::operator=(const Point& other)
{
	(void)other;
	return *this;
}

Point::~Point()
{
	return ;
}

Fixed	Point::getX() const
{
	return _x;
}

Fixed	Point::getY() const
{
	return _y;
}
