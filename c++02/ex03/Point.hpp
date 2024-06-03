#include <iostream>
#include "Fixed.hpp"

#pragma once

class	Point
{
	public:
	
	void	operator=(const Point& original) = delete;
	Fixed	get_x() const;
	Fixed	get_y() const;
	Point();
	Point(const float x, const float y);
	Point(const Fixed& x, const Fixed& y);
	Point(const Point& original);
	~Point();

	static Fixed&	length(Point& a, Point& b);

	private:
	
	const Fixed	x;
	const Fixed	y;
};

bool	inside_triangle(const Point a, const Point b, const Point c, const Point point);