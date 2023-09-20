#include<iostream>

class Fixed
{
private:
	
	int					_fixedValue;
	static const int	_fractionalBits = 8;
	
public:

	Fixed();
	Fixed(const Fixed &src);
	Fixed(int int_number);
	Fixed(float float_number);
	~Fixed();

	Fixed	&operator=(Fixed const &rhs);
	int 	getRawBits( void ) const;
	int 	getFractinalBits( void ) const;
	float	toFloat( void ) const;
	int		toInt( void ) const;
	void 	setRawBits( int const raw );
	
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);
