#include "Fixed.hpp"

Fixed::Fixed(void) : value(0){
	std::cout << "Default constructor called!" << std::endl;
}

Fixed::Fixed(int const value) : value(value << fractionalBits) {
	std::cout << "Int constructor called with value " << this->value << std::endl;
}

Fixed::Fixed(float const value) : value( roundf( value * (1 << fractionalBits))){
	std::cout << "Float constructor called with value " << this->value << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called!" << std::endl;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawbits called!" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const value) {
	std::cout << "setRawbits called!" << std::endl;
	this->value = value;
}

Fixed::Fixed(const Fixed &toCopy) {
	std::cout << "Copy constructor called!" << std::endl;
	this->value = toCopy.value;
}

Fixed& Fixed::operator=( const Fixed &toCopy ) {
	if (this != &toCopy) {
		this->value = toCopy.value;
	}
	return (*this);
}

float	Fixed::toFloat(void) const {
	return static_cast<float>( this->getRawBits() ) / ( 1 << fractionalBits );
}

int		Fixed::toInt(void) const{
	return this->value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, Fixed const & i) {
	os << i.toFloat();
	return os;
}
