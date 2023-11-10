#include"ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(bool i)
{
	if (!i)
		return ;
	setEnergyPoint(50);
	std::cout << "ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setEnergyPoint(50);
	setAttackDamage(20);
	std::cout << "ScavTrap " << name << " created" << std::endl;
}

ScavTrap::ScavTrap(std::string name, bool i)
{
	if (!i)
		return ;
	setEnergyPoint(50);
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
	if (this != &rhs)
	{
		this->setHitPoint(rhs.getHitPoint());
		this->setEnergyPoint(rhs.getEnergyPoint());
		this->setAttackDamage(rhs.getAttackDamage());
		this->setKeerperMode(rhs.getKeeperMode());
	}
	return (*this);
}

bool	ScavTrap::getKeeperMode(void) const
{
	return (_keeper_mode);
}

void	ScavTrap::setKeerperMode(bool mode)
{
	_keeper_mode = mode;
}

void	ScavTrap::guardGate(void)
{
	if (getEnergyPoint() == 0 && !getKeeperMode())
	{
		std::cout << "ScavTrap " << getName() << " doesn't have enough energy..." << std::endl;
		return ;
	}
	else if (getHitPoint() == 0)
	{
		std::cout << "ScavTrap " << getName() << " is dead, unfortunately he can't do anything..." << std::endl;
		return ;
	}
	if (getKeeperMode() % 2 == 0)
	{
		setKeerperMode(true);
		std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
		setEnergyPoint(getEnergyPoint() - 10);
	}
	else
	{
		setKeerperMode(false);
		std::cout << "ScavTrap leave the Gatekeeper mode" << std::endl;
	}
}

void	ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoint() == 0)
		std::cout << "ScavTrap " << getName() << " doesn't have enough energy..." << std::endl;
	else if (getHitPoint() == 0)
		std::cout << "ScavTrap " << getName() << " is dead, unfortunately he can't do anything..." << std::endl;
	if (getEnergyPoint() == 0 || getHitPoint() == 0)
		return ;
	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << "ScavTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!" << std::endl;
}