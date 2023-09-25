#include"DiamondTrap.hpp"


DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(), ClapTrap::name()
{
	std::cout << "DiamondTrap " << name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(), ScavTrap(), ClapTrap::_name(name + "_clap_name")
{
	setHitPoint(FragTrap::getHitPoint());
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << "DiamondTrap " << name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &src) : FragTrap(src), ScavTrap(src)
{
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << getName() << " destroyed" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap &rhs)
{
	/*if (this != &rhs)
	{

	}*/
	(void)rhs;
	return (*this);
}

