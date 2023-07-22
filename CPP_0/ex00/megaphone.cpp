#include <iostream>

int main(int argc, char **argv)
{
	int i, j;

	char **tab;

	if (argc < 2)
	{
	   std::cout << "Wrong number of arguments" << std::endl;
	   return (1);
	}
	tab = argv;
	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			std::cout << (char)std::toupper(tab[i][j]);
			j++;
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}