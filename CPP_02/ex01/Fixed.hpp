#ifndef FIXED_CPP
#define FIXED_CPP

#include<iostream>
#include<cmath>
class Fixed
{
private:
	
	int					_fixedValue;
	static const int	_fractionalBits = 8;
	
public:

	Fixed();
	Fixed(const Fixed &src);
	Fixed(int const int_number);
	Fixed(float float_number);
	~Fixed();


	Fixed	&operator=(Fixed const &rhs);


	int 	getRawBits( void ) const;
	int 	getFractionalBits( void ) const;
	float	toFloat( void ) const;
	int		toInt( void ) const;
	void 	setRawBits( int const raw );
	
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif