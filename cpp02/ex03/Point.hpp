#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
    	Point();
		Point(Fixed const x, Fixed const y);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();
	
		Fixed	getX() const;
		Fixed	getY() const;

	private:
		const Fixed _x;
		const Fixed _y;
};

#endif
