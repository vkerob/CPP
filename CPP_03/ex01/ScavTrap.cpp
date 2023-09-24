#include"ScavTrap.hpp"


ScavTrap::ScavTrap()
{

}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
}

ScavTrap::ScavTrap(ScavTrap &src)
{
	*this = src;
}

ScavTrap::~ScavTrap()
{

}

ScavTrap	&operator=(ScavTrap &rhs)
{
	if (this != &rhs)
	{

	}
	return (*this);
}
