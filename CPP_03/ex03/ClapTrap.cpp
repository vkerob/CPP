
#include"ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("default npc"), _Hit_point(10), _Energy_point(10), _Attack_damage(0)
{
	std::cout << "ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _Hit_point(10), _Energy_point(10), _Attack_damage(0)
{
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
}


ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << getName() << " destroyed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		setName(rhs.getName());
		setAttackDamage(rhs.getAttackDamage());
		setEnergyPoint(rhs.getEnergyPoint());
		setHitPoint(rhs.getHitPoint());
	}
	return (*this);
}

bool	ClapTrap::checkPointValue(void)
{
	if (getEnergyPoint() <= 0)
		std::cout << "ClapTrap " << getName() << " doesn't have enough energy..." << std::endl;
	else if (getHitPoint() <= 0)
		std::cout << "ClapTrap " << getName() << " is dead, unfortunately he can't do anything..." << std::endl;
	if (getEnergyPoint() <= 0 || getHitPoint() <= 0)
		return (true);
	return (false);
}

void ClapTrap::attack(const std::string& target)
{
	if (checkPointValue())
		return ;
	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << "ClapTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (checkPointValue())
		return ;
	setHitPoint(getHitPoint() - amount);
	std::cout << "ClapTrap " << getName() << " was attacked and took " << getAttackDamage() << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (checkPointValue())
		return ;
	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << "ClapTrap " << getName() << " repaired itself by " << amount << " hit points" << std::endl;
	setHitPoint(getHitPoint() + amount);
}

std::string	ClapTrap::getName(void) const
{
	return (_Name);
}

int	ClapTrap::getHitPoint(void) const
{
	return (_Hit_point);
}

int	ClapTrap::getEnergyPoint(void) const
{
	return (_Energy_point);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (_Attack_damage);
}



void	ClapTrap::setName(std::string str)
{
	_Name = str;
}

void	ClapTrap::setHitPoint(int value)
{
	if (value < 0)
		_Hit_point = 0;
	else
		_Hit_point = value;
}

void	ClapTrap::setEnergyPoint(int value)
{
	if (value < 0)
		_Energy_point = 0;
	else
		_Energy_point = value;
}

void	ClapTrap::setAttackDamage(int value)
{
	if (value < 0)
		_Attack_damage = 0;
	else
		_Attack_damage = value;
}
