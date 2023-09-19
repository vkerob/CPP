#include"Fixed.hpp"


Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedValue = src.getFixedValue();
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixedValue = rhs.getFixedValue();

	return (*this);
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fractionalBits);
}

void Fixed::setRawBits( int const raw )
{
	this->fixedValue = raw;
}

int	Fixed::getFixedValue( void ) const
{
	return (this->fixedValue);
}