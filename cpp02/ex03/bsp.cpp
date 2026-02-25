#include "Point.hpp"

Fixed triangleArea( Point const a, Point const b, Point const c)
{
	return a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY());
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed total = triangleArea(a,b,c);
	Fixed abpArea = triangleArea(a,b,point);
	Fixed apcArea = triangleArea(a,point,c);
	Fixed pbcArea = triangleArea(point,b,c);
	if (total > 0)
		return (abpArea > 0 && apcArea > 0 && pbcArea > 0);
	return (abpArea < 0 && apcArea < 0 && pbcArea < 0);
}
