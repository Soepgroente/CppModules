#include <iostream>
#include <stdio.h>
#include "Fixed.hpp"
#include "Point.hpp"

static void	test_triangle(Point& a, Point& b, Point& c, Point& test)
{
	if (inside_triangle(a, b, c, test) == true)
		std::cout << "TRUE" << std::endl;
	else
		std::cout << "FALSE" << std::endl;
}

int	main(void)
{
	Point	a(-2.0f, 0);
	Point	b(2.0f, 0);
	Point	c(0, 6);
	Point	something(0.1f, 0.1f);

	test_triangle(a, b, c, something);
	return (0);
}
