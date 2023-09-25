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
	Fixed(int int_number);
	Fixed(float float_number);
	~Fixed();

	Fixed&	operator=(Fixed const &rhs);
	bool	operator>(Fixed const &rhs) const;
	bool	operator<(Fixed const &rhs) const;
	bool	operator>=(Fixed const &rhs) const;
	bool	operator<=(Fixed const &rhs) const;
	bool	operator!=(Fixed const &rhs) const;
	Fixed&	operator+(Fixed const &rhs);
	Fixed&	operator-(Fixed const &rhs);
	Fixed	operator*(Fixed const &rhs) const;
	Fixed	operator/(Fixed const &rhs) const;
	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);
	static Fixed const&	max(Fixed const &a, Fixed const &b);
	static Fixed const&	min(Fixed const &a, Fixed const &b);
	static Fixed const&	max(Fixed &a, Fixed &b);
	static Fixed const&	min(Fixed &a, Fixed &b);
	int 	getRawBits( void ) const;
	int 	getFractionalBits( void ) const;
	float	toFloat( void ) const;
	int		toInt( void ) const;
	void 	setRawBits( int const raw );
	
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif