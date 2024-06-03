#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

#pragma once

class	Triangle
{
	public:
	
	const Point&	get_pt(int point) const;
	void			operator=(const Triangle& triangle) = delete;

	Triangle() = delete;
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle& og);
	~Triangle();

	private:
	
	const Point	vertices[3];
};

bool	inside_triangle(const Triangle& triangle, const Point& point);
void	Print(Triangle& that, Triangle& the_other_thing);