#include<iostream>

class Fixed
{
private:
	
	int	fixedValue;
	static const int fractionalBits = 0;
	
public:

	Fixed();
	Fixed(const Fixed &src);
	~Fixed();

	Fixed	&operator=(Fixed const &rhs);
	int	getFixedValue( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	
};

