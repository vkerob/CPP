#include"Zombie.hpp"
#include<new>

Zombie*	newZombie( std::string name )
{
	Zombie *new_zombie;
	try
	{
		new_zombie = new Zombie();
	}
	catch(std::exception &bad_alloc)
	{
		std::cout << bad_alloc.what() << std::endl;
		return (NULL);
	}
	new_zombie->set_name(name);

	return (new_zombie);
}