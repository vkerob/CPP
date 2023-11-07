#include "iter.hpp"

void	decrease(int &nb)
{
	if (nb != -2147483648)
		nb--;
}

void	toUpper(std::string &str)
{
	int i = 0;

	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
}

int	main()
{
	int tab1[5] = {0, 1, 2, 3, 4};
	iter(tab1, 5, decrease);
	std::cout << tab1[0] << std::endl;
	std::cout << tab1[1] << std::endl;
	std::cout << tab1[2] << std::endl;
	std::cout << tab1[3] << std::endl;
	std::cout << tab1[4] << std::endl;
	std::string tab2[5] = {"tt", "t", "88888t", "t", "t"};
	iter(tab2, 5, toUpper);
	std::cout << tab2[0] << std::endl;
	std::cout << tab2[1] << std::endl;
	std::cout << tab2[2] << std::endl;
	std::cout << tab2[3] << std::endl;
	std::cout << tab2[4] << std::endl;


	return 0;
}
