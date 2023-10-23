#include"DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
	FragTrap::setAttackDamage(30);
	std::cout << "DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	_Name = name;
	FragTrap::setAttackDamage(30);
	std::cout << "DiamondTrap " << name << " created" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &src) : FragTrap(src), ScavTrap(src)
{
	*this = src;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << FragTrap::getName() << " destroyed" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap &rhs)
{
	if (this != &rhs)
	{
		this->ClapTrap::setName(rhs.getName() + "_clap_name");
		this->setHitPoint(rhs.getHitPoint());
		this->setEnergyPoint(rhs.getEnergyPoint());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return (*this);
}

void DiamondTrap::whoAmI( void )
{
	std::cout << std::endl
	<< "DiamondTrap name: " << getName() << std::endl
	<< "ClapTrap name: " << ClapTrap::getName() << std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return (_Name);
}