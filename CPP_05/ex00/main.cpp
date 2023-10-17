#include "Bureaucrat.hpp"

int	main ()
{
	Bureaucrat lol1("lol1", 0);
	Bureaucrat lol2("lol2", 1);
	Bureaucrat lol3("lol3", 150);
	Bureaucrat lol4("lol4", 151);
	Bureaucrat lol5;

	std::cout << std::endl;
	lol2.decreaseGrade();
	std::cout << lol2 << std::endl;
	lol2.increaseGrade();
	lol2.increaseGrade();
	std::cout << lol2 << std::endl;
	std::cout << lol5 << std::endl;
	lol5.decreaseGrade();
	std::cout << lol5 << std::endl;
}