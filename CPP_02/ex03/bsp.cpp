#include"Point.hpp"

int	CheckPointInside(Point const &v1, Point const &v2, Point const &point)
{
	return ((v2.getx() - point.getx()) * (v1.gety() - point.gety()) - 
	(v2.gety() - point.gety()) * (v1.getx() - point.getx()));
}


std::string bsp( Point const &a, Point const &b, Point const &c, Point const &point)
{
	int	result_ab = CheckPointInside(a, b, point);
	int	result_bc = CheckPointInside(b, c, point);
	int	result_ac = CheckPointInside(c, a, point);

	// std::cout << CheckPointInside(a, b, point) << std::endl;
	// std::cout << CheckPointInside(b, c, point) << std::endl;
	// std::cout << CheckPointInside(c, a, point) << std::endl;
	if ((result_ab > 0 && result_bc > 0 && result_ac > 0) ||
        (result_ab < 0 && result_bc < 0 && result_ac < 0))
		return("IN !");
	return ("OUT !");
	
}