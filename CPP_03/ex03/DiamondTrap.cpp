#include"DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(true)
{
	std::cout << "DiamondTrap created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name, true)
{
	_Name = name;
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
		this->setName(rhs.getName());
	}
	return (*this);
}

void DiamondTrap::whoAmI( void ) const
{
	std::cout << std::endl
	<< "DiamondTrap name: " << getName() << std::endl
	<< "ClapTrap name: " << ClapTrap::getName() << std::endl;
}

std::string	DiamondTrap::getName(void) const
{
	return (_Name);
}

void	DiamondTrap::setName(std::string name)
{
	_Name = name;
}