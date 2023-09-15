#include"Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );


int	main(void)
{
	Zombie *horde;
	int 	i = 0;

	horde = zombieHorde(4, "foo");
	while (i < 4)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
}