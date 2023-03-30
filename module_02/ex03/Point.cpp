#include "Point.hpp"

Point::Point(void) : x(0), y(0) {
	std::cout << "Constructor called on a Point" << std::endl;
}

Point::Point(const float x, const float y) : x(x), y(y) {
	std::cout << "Constructor called on a Point, x = " << this->x << " y = " << this->y.toFloat() << std::endl;
}

Point::~Point() {
	std::cout << "Destructor called on Point" << std::endl;
}

Point::Point(const Point &toCopy) : x(toCopy.x), y(toCopy.y) {
	std::cout << "Copy constructor called on a Point" << std::endl;
}

Point	&Point::operator=( const Point &rhs ) {
	if (this != &rhs) {
		this->x = rhs.x;
		this->y = rhs.y;
	}
	return (*this);
}

Fixed	Point::getX(void) const{
	return ( this->x );
}

Fixed	Point::getY(void) const{
	return ( this->y );
}
