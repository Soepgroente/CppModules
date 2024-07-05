#include "Point.hpp"
#include "Fixed.hpp"
#include <cmath>

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x1, const float y1) : x(Fixed(x1)), y(Fixed(y1))
{
}

Point::Point(const Fixed& x1, const Fixed& y1) : x(x1), y(y1)
{
}

Point::Point(const Point& original) : x(original.x), y(original.y)
{
}

Point::~Point()
{
}

Fixed	Point::get_x() const
{
	return (Fixed(this->x));
}

Fixed	Point::get_y() const
{
	return (Fixed(this->y));
}

bool	Point::operator==(const Point& other)	const
{
	if (this->get_x() == other.get_x() && this->get_y() == other.get_y())
		return (true);
	return (false);
}

Fixed	Point::length(const Point& a, const Point& b)
{
	Fixed	res;
	Fixed	length_x(a.get_x() - b.get_x());
	Fixed	length_y(a.get_y() - b.get_y());

	length_x = length_x * length_x;
	length_y = length_y * length_y;
	res = (float)sqrt((length_x + length_y).toFloat());
	return (res);
}