#include "Fixed.hpp"
#include "Point.hpp"

Fixed	getOrient(Point vector1, Point vector2)
{
	Fixed	orientationValue((vector1.getX() * vector2.getY()) - (vector2.getX() * vector1.getY()));
	return orientationValue;
}

bool bsp(Point const a,Point const b,Point const c,Point const point)
{
	Point	vectorAB((b.getX() - a.getX()), (b.getY() - a.getY()));
	Point	vectorAP((point.getX() - a.getX()), (point.getY() - a.getY()));
	Point	vectorBC((c.getX() - b.getX()), (c.getY() - b.getY()));
	Point	vectorBP((point.getX() - b.getX()), (point.getY() - b.getY()));
	Point 	vectorCA((a.getX() - c.getX()), (a.getY() - c.getY()));
	Point	vectorCP((point.getX() - c.getX()), (point.getY() - c.getY()));
	
	Fixed o1 = getOrient(vectorAB, vectorAP);
	Fixed o2 = getOrient(vectorBC, vectorBP);
	Fixed o3 = getOrient(vectorCA, vectorCP);
	if (o1 > 0 && o2 > 0 && o3 > 0)
		return true;
	else if (o1 < 0 && o2 < 0 && o3 < 0)
		return true;
	return false;
}
