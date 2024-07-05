#include "Fixed.hpp"
#include "Point.hpp"

Fixed	triangleArea(Point a, Point b, Point c)
{
	Fixed	area;
	
	area =	a.get_x() * (b.get_y() - c.get_y()) + \
			b.get_x() * (c.get_y() - a.get_y()) + \
			c.get_x() * (a.get_y() - b.get_y()) / Fixed(2);
	area.abs();
	return (area);
}

bool	inside_triangle( const Point& a, const Point& b, const Point& c, const Point& point)
{
	Fixed	ab_point = triangleArea(a, b, point);
	Fixed	bc_point = triangleArea(b, c, point);
	Fixed	ac_point = triangleArea(a, c, point);
	Fixed	original = triangleArea(a, b, c);

	if (ab_point + bc_point + ac_point != original)
		return (false);
	return (true);
}