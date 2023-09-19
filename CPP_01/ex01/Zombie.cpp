#include"Zombie.hpp"

Zombie::Zombie(void)
{
	return ;
};

Zombie::~Zombie(void)
{
	std::cout <<  this->_name << " was destroyed" << std::endl;
	return ;
};

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." <<std::endl;
}