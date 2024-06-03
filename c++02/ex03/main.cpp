#include <iostream>
#include <stdio.h>
#include "Fixed.hpp"
#include "Point.hpp"
#include "Triangle.hpp"

static void	test_triangle(Triangle& three_angles, Point& pt)
{
	if (inside_triangle(three_angles, pt) == true)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
}

int	main(void)
{
	Triangle	one(Point(2.1f, 2.1f), Point(-3.0f, 4.0f), Point(5.0f, 6.0f));
	Triangle	two(Point(-5.0f, -3.0f), Point(-2, -2), Point(-8, -10));
	Triangle	three(Point(3.0f, 8.6f), Point(-2, -2), Point(-8, -10));
	Triangle	four(Point(2.0f, 10.0f), Point(2, 2), Point(10, 2));
	Point		something(2.1f, 2.1f);

	test_triangle(one, something);
	test_triangle(two, something);
	test_triangle(three, something);
	test_triangle(four, something);
	return (0);
}
