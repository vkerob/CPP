#include <iostream>
#include"Fixed.hpp"


int main( void ) 
{
	Fixed		a;
	Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;


	std::cout << std::endl << "MY TEST: " << std::endl;
	Fixed 		c( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed		d;

	std::cout << "MULTIPLICATION: " << std::endl;
	std::cout << "c = " << c << std::endl << std::endl;


	std::cout << "ADDITION AND SUBSTRACTION: " << std::endl;
	std::cout << "d = " << d-- << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "d = " << --d << std::endl;
	std::cout << "d = " << d << std::endl << std::endl;

	std::cout << "MIN, MAX: " << std::endl;
	std::cout << "a = " << a << " d = " << d << "   min: " << Fixed::min( a, d ) << std::endl;
	std::cout << "a = " << a << " d = " << d << "   max: " << Fixed::max( a, d ) << std::endl;
	std::cout << "b = " << a << " c = " << d << "   min: " << Fixed::min( b, c ) << std::endl;
	std::cout << "b = " << a << " c = " << d << "   max: " << Fixed::max( b, c ) << std::endl;


	std::cout << a + c << std::endl << std::endl;


	std::cout << "OPERATOR: (==, >, >=, <, <=)" << std::endl;
	if (a == c)
		std::cout << "a = c" << std::endl;
	if (a != c)
		std::cout << "a != c" << std::endl;
	if (a < c)
		std::cout << "a < c" << std::endl;
	if (a <= c)
		std::cout << "a <= c" << std::endl;
	if (a > c)
		std::cout << "a > c" << std::endl;
	if (a >= c)
		std::cout << "a >= c" << std::endl;

	return 0;
}