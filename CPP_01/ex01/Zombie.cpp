#include"Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
};

Zombie::~Zombie(void)
{
	std::cout <<  this->name << " was destroyed" << std::endl;
	return ;
};

void	Zombie::set_name(std::string name)
{
	this->name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}