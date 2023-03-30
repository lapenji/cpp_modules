#pragma once
#include "Fixed.hpp"
#include <iostream>


class Point {
	Fixed	x;
	Fixed	y;

	public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point &toCopy);
	~Point();
	Point& operator=( const Point &rhs );
	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
