#include "Fixed.hpp"

Fixed::Fixed(void) : value(0){
	std::cout << "Default constructor called!" << std::endl;
}

Fixed::Fixed(int const value) : value(value << fractionalBits) {
	std::cout << "Int constructor called with value " << this->value << std::endl;
}

Fixed::Fixed(float const value) : value( roundf( value * (1 << this->fractionalBits))){
	std::cout << "Float constructor called with value " << this->value << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called!" << std::endl;
}

int		Fixed::getRawBits() const {
	return (this->value);
}

void	Fixed::setRawBits(int const value) {
	this->value = value;
}

Fixed::Fixed(const Fixed &toCopy) {
	std::cout << "Copy constructor called!" << std::endl;
	this->value = toCopy.value;
}

Fixed& Fixed::operator=( const Fixed &toCopy ) {
	std::cout << "= operator overload called!" << std::endl;
	if (this != &toCopy) {
		this->value = toCopy.value;
	}
	return (*this);
}

float	Fixed::toFloat(void) const{
	return ((float)this->value ) / ( 1 << this->fractionalBits );
}

int		Fixed::toInt(void) const{
	return this->value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, Fixed const & i) {
	os << i.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed &rhs) const {
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const {
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const {
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const {
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const {
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const {
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	&Fixed::operator++(void) {
	++this->value;
	return (*this);
}

Fixed	&Fixed::operator--(void) {
	--this->value;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp;
	tmp.value = this->value++;
	return (tmp);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp;
	tmp.value = this->value--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed & first, Fixed &second) {
	if (first > second)
		return second;
	else
		return first;
}

const Fixed	&Fixed::min(const Fixed & first, const Fixed & second) {
	if (first > second)
		return second;
	else
		return first;
}

Fixed	&Fixed::max(Fixed & first, Fixed &second) {
	if (first > second)
		return first;
	else
		return second;
}

const Fixed	&Fixed::max(const Fixed & first, const Fixed & second) {
	if (first > second)
		return first;
	else
		return second;
}
