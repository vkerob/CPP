#include"Fixed.hpp"

// constructeur et destructeur

Fixed::Fixed() : _fixedValue(0)
{
}

Fixed::Fixed(int int_number)
{
	_fixedValue = int_number << this->getFractinalBits();

}

Fixed::Fixed(float float_number)
{
	_fixedValue = static_cast<int>(float_number * (1 << this->getFractinalBits()));
	
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::~Fixed()
{
}


// fonctions

int Fixed::getRawBits( void ) const
{
	return (this->_fixedValue);
}

int Fixed::getFractinalBits( void ) const
{
	return (this->_fractionalBits);
}

void Fixed::setRawBits( int const raw )
{
	this->_fixedValue = raw;
}



// opereteur

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_fixedValue = rhs.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << static_cast<float>(rhs.getRawBits()) / (1 << rhs.getFractinalBits());
	return (o);
}
