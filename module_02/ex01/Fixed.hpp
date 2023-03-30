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
};

std::ostream& operator<<(std::ostream& os, Fixed const & fixed);
