#ifndef POINT_CPP
#define POINT_CPP

#include"Fixed.hpp"

class Point
{
	private:
		
		Fixed const x;
		Fixed const y;
		Point	&operator=(Point const &rhs);

	public:

		Point(float const floating_pointx, float const floating_pointy);
		Point(const Point &src);
		Point();
		~Point();


		int getx( void ) const;
		int gety( void ) const;

};

#endif