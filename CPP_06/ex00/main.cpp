#include "ScalarConverter.hpp"


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Enter one information only" << std::endl;
		return (1);
	}
	ScalarConverter converter;

	converter.convert(argv[1]);
}