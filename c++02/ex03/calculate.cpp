#include "Fixed.hpp"
#include "Point.hpp"
#include "Triangle.hpp"

Fixed	length(const Fixed& x, const Fixed& y, const Fixed& z)
{
	Fixed	smallest;
	Fixed	largest;

	smallest = Fixed::min(x, y);
	smallest = Fixed::min(smallest, z);
	largest = Fixed::max(x, y);
	largest = Fixed::max(largest, z);
	smallest.abs();
	largest.abs();
	Fixed result(Fixed(largest) - Fixed(smallest));
	return (result);
}

Fixed tri_area(const Point& x, const Point& y, const Point& z)
{
	Fixed	width;
	Fixed	height;
	Fixed	area;

	width = length(x.get_x(), y.get_x(), z.get_x());
	height = length(x.get_y(), y.get_y(), z.get_y());

	area = Fixed(width) * Fixed(height);
	area = Fixed(area) / Fixed(2.0f);
	// area.abs();
	return (area);
}

bool	inside_triangle(const Triangle& triangle, const Point& point)
{
	Fixed	or_triangle;
	Fixed	pt_area[3];
	Fixed	total_area;

	or_triangle = tri_area(triangle.get_pt(0), triangle.get_pt(1), triangle.get_pt(2));
	pt_area[0] = tri_area(triangle.get_pt(0), triangle.get_pt(1), point);
	pt_area[1] = tri_area(triangle.get_pt(0), triangle.get_pt(2), point);
	pt_area[2] = tri_area(triangle.get_pt(1), triangle.get_pt(2), point);

	total_area = Fixed(pt_area[0]) + Fixed(pt_area[1]);
	total_area = Fixed(total_area) + Fixed(pt_area[2]);
	std::cout << "Area of triangle: " << or_triangle.toFloat() << std::endl;
	std::cout << "Area of three triangles with the point: " << total_area.toFloat() << std::endl;
	if (pt_area[0] + pt_area[1] + pt_area[2] == or_triangle)
		return (true);
	return (false);
}