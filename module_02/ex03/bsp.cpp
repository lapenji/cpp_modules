#include "Point.hpp"

static Fixed	abs(Fixed x) {
	if (x < 0)
		return x * -1;
	else
		return x;
}

Fixed	area(Point const a, Point const b, Point const c) {
	return ((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	abc;
	Fixed	pab;
	Fixed	pbc;
	Fixed	cpa;

	abc = abs(area(a, b, c));
	pab = abs(area(point, a, b));
	pbc = abs(area(point, b, c));
	cpa = abs(area(point, c, a));

	return ( abc == pab + pbc + cpa);
}



