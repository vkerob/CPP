#include"Fixed.hpp"


Fixed::Fixed() : _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const int_number)
{
	_fixedValue = int_number << this->getFractionalBits();
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float float_number)
{
	_fixedValue = static_cast<int>(roundf(float_number * (1 << this->getFractionalBits())));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixedValue = rhs.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << static_cast<float>(rhs.getRawBits()) / static_cast<float>((1 << rhs.getFractionalBits()));
	return (o);
}

int		Fixed::toInt( void ) const
{
	return (this->getRawBits() >> this->getFractionalBits());
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / static_cast<float>((1 << this->getFractionalBits())));
}

int Fixed::getRawBits( void ) const
{
	return (this->_fixedValue);
}

int Fixed::getFractionalBits( void ) const
{
	return (this->_fractionalBits);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedValue = raw;
}