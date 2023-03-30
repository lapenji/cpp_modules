#pragma once
#include <iostream>
#include <cmath>

class Fixed {

	private:

	int					value;
	static const int	fractionalBits = 8;

	public:

	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(const Fixed &toCopy);
	~Fixed();
	Fixed& operator=( const Fixed &rhs );
	int		getRawBits(void) const;
	void	setRawBits(int const value);
	float	toFloat(void) const;
	int		toInt(void) const;
	bool	operator>(const Fixed &rhs) const ;
	bool	operator<(const Fixed &rhs) const ;
	bool	operator>=(const Fixed &rhs) const ;
	bool	operator<=(const Fixed &rhs) const ;
	bool	operator==(const Fixed &rhs) const ;
	bool	operator!=(const Fixed &rhs) const ;
	Fixed	operator+(const Fixed &rhs) const ;
	Fixed	operator-(const Fixed &rhs) const ;
	Fixed	operator*(const Fixed &rhs) const ;
	Fixed	operator/(const Fixed &rhs) const ;
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);
	static Fixed	&min(Fixed & first, Fixed &second);
	static const Fixed	&min(const Fixed & first, const Fixed & second);
	static Fixed	&max(Fixed & first, Fixed &second);
	static const Fixed	&max(const Fixed & first, const Fixed & second);
};

std::ostream& operator<<(std::ostream& os, Fixed const & fixed);
