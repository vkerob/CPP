#include"Zombie.hpp"
Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main(void)
{
	Zombie *zombie_1;

	zombie_1 = newZombie("Foo");
	if (zombie_1 != NULL)
	{
		zombie_1->announce();
		delete zombie_1;
	}
	randomChump("Foo2");
}