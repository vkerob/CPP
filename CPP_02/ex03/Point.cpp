#include"Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::Point(float const floating_pointx, float const floating_pointy) : x(Fixed(floating_pointx)), y(Fixed(floating_pointy))
{
	
}

Point	&Point::operator=(Point const &rhs)
{
	(void)rhs;
	return (*this);
}


int Point::getx( void ) const
{
	return(this->x.getRawBits());
}

int Point::gety( void ) const
{
	return(this->y.getRawBits());
}

Point::Point(const Point &src)
{
	*this = src;
}

Point::~Point()
{
}
