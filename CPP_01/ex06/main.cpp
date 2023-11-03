#include"Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cout << "this program take only one argument" <<std::endl;
		return (1);
	}
	if (argv[1] != NULL)
		harl.complain(argv[1]);
	return (0);
}