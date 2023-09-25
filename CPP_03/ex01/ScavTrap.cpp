#include"ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &src) : ClapTrap(src)
{
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << getName() << " destroyed" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap &rhs)
{
	/*if (this != &rhs)
	{

	}*/
	(void)rhs;
	return (*this);
}

int	ScavTrap::getKeeperMode(void) const
{
	return (_keeper_mode);
}

void	ScavTrap::setKeerperMode(int mode)
{
	_keeper_mode = mode;
}

void	ScavTrap::guardGate(void)
{
	if (getEnergyPoint() <= 0)
		std::cout << "ScavTrap " << getName() << " doesn't have enough energy..." << std::endl;
	else if (getHitPoint() <= 0)
		std::cout << "ScavTrap " << getName() << " is dead, unfortunately he can't do anything..." << std::endl;
	if (getEnergyPoint() <= 0 || getHitPoint() <= 0)
		return ;
	if (getKeeperMode() % 2 == 0)
	{
		setKeerperMode(1);
		setEnergyPoint(getEnergyPoint() - 10);
		std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
	}
	else
	{
		setKeerperMode(0);
		std::cout << "ScavTrap leave the Gatekeeper mode" << std::endl;
	}
}

void	ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoint() <= 0)
		std::cout << "ScavTrap " << getName() << " doesn't have enough energy..." << std::endl;
	else if (getHitPoint() <= 0)
		std::cout << "ScavTrap " << getName() << " is dead, unfortunately he can't do anything..." << std::endl;
	if (getEnergyPoint() <= 0 || getHitPoint() <= 0)
		return ;
	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!" << std::endl;
}