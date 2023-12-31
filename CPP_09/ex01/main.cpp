#include "RPN.hpp"
#include <iomanip>

int main(int argc, char **argv)
{
	float nb;
	if (argc != 2)
	{
		std::cout << "Error: enter a string." << std::endl;
		return (1);
	}
	std::cout << std::fixed << std::setprecision(2);
	RPN rpn;
	std::string input(argv[1]);
	try 
	{
	nb = rpn.calculate(input);
	if (nb != 2147483648.0f)
		std ::cout << nb << std::endl;
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "overflow error." << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "general error." << e.what() << std::endl;
	}
}
