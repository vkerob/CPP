#include"Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;
	int		i = 0;

	horde = new Zombie[N];
	while (i < N)
	{
		horde[i].set_name(name);
		i++;
	}
	return(&horde[0]);
}