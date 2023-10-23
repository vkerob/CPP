#ifndef FIXED_HPP
#define FIXED_HPP

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

		
		int 	getRawBits( void ) const;
		int 	getFractinalBits( void ) const;
		void 	setRawBits( int const raw );
	
};

std::ostream &operator<<(std::ostream &o, Fixed const &rhs);

#endif