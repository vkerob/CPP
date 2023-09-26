#include <iostream>

int main(int argc, char **argv)
{
	int i, j;

	char **tab;

	if (argc < 2)
	{
	   std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	   return (1);
	}
	tab = argv;
	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (islower(tab[i][j]))
				tab[i][j] -= 32;
			std::cout << tab[i][j];
		 j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}