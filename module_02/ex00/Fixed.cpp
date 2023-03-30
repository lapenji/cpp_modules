#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called on Fixed" << std::endl;
	this->value = 0;
}

int		Fixed::getRawBits() const {
	return (this->value);
}

void	Fixed::setRawBits(int const value) {
	this->value = value;
}

Fixed::Fixed(const Fixed &toCopy) {
	std::cout << "Copy constructor called on Fixed" << std::endl;
	this->value = toCopy.value;
}

Fixed& Fixed::operator=( const Fixed &toCopy ) {
	std::cout << "= operator overload called on Fixed" << std::endl;
	if (this != &toCopy) {
		this->value = toCopy.value;
	}
	return (*this);
}
