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
	_fixedValue = static_cast<int>(roundf(float_number * (1 << this->getFractinalBits())));
	
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::~Fixed()
{
}








// fonctions


int		Fixed::toInt( void ) const
{
	return (this->getRawBits() >> this->getFractinalBits());
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits() * (1 << this->getFractinalBits())));
}

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

Fixed const&	Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a <= b)
		return (a);
	return (b);
}

Fixed const&	Fixed::max(Fixed const &a, Fixed const &b)
{
		if (b <= a)
		return (a);
	return (b);
}












// constructeur et destructeur opereteur

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

bool	Fixed::operator>(Fixed const &rhs) const
{
	if(this->_fixedValue > rhs.getRawBits())
		return (true);
	return(false);

}

bool	Fixed::operator<(Fixed const &rhs) const
{
	if(this->_fixedValue < rhs.getRawBits())
		return (true);
	return(false);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	if(this->_fixedValue >= rhs.getRawBits())
		return (true);
	return(false);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	if(this->_fixedValue <= rhs.getRawBits())
		return (true);
	return(false);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	if(this->_fixedValue != rhs.getRawBits())
		return (true);
	return(false);
}

Fixed&	Fixed::operator+(Fixed const &rhs)
{
	this->_fixedValue += rhs.getRawBits();
	return (*this);
}

Fixed&	Fixed::operator-(Fixed const &rhs)
{
	this->_fixedValue -= rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed tmp;
	tmp.setRawBits((this->getRawBits() * rhs.getRawBits()) >> this->getFractinalBits());
	return (tmp);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	Fixed tmp;
	tmp.setRawBits((this->getRawBits() << this->getFractinalBits()) / rhs.getRawBits());
	return (tmp);
}

Fixed&	Fixed::operator++()
{
	this->_fixedValue++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixedValue++;
	return (tmp);
}

Fixed&	Fixed::operator--()
{
	this->_fixedValue--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixedValue--;
	return (tmp);
}
