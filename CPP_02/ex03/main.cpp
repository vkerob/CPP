#include <iostream>
#include"Fixed.hpp"
#include"Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) 
{
	std::cout << bsp(Point(0, 0), Point(4, 0), Point(0, 4), Point(1, 1)) << std::endl;

	return 0;
}