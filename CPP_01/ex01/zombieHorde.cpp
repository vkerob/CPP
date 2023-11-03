#include"Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *horde;
	int		i = 0;

	if (N < 0)
	{
		std::cout << "invalid number of zombie" <<std::endl;
		return (NULL);
	}
	try
	{
		horde = new Zombie[N];
	}
	catch(std::exception &bad_alloc)
	{
		std::cout << bad_alloc.what() << std::endl;
		return (NULL);
	}
	while (i < N)
	{
		horde[i].set_name(name);
		i++;
	}
	return(&horde[0]);
}