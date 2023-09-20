#include<iostream>

class Fixed
{
private:
	
	int					_fixedValue;
	static const int	_fractionalBits = 8;
	
public:

	Fixed();
	Fixed(const Fixed &src);
	~Fixed();

	Fixed	&operator=(Fixed const &rhs);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
};

