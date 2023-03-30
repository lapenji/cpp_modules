#include <iostream>

class Fixed {

	private:

	int					value;
	static const int	lit = 8;

	public:

	Fixed();
	Fixed(const Fixed &toCopy);
	Fixed& operator=( const Fixed &rhs );
	int		getRawBits(void) const;
	void	setRawBits(int const value);
};
