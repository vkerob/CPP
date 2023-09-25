
#include"ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("default npc"), _Hit_point(10), _Energy_point(10), _Attack_damage(0)
{
	std::cout << "ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Hit_point(10), _Energy_point(10), _Attack_damage(0)
{
	_Name = name;
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
		_Name = rhs.getName();
		_Attack_damage = rhs.getAttackDamage();
		_Energy_point = rhs.getEnergyPoint();
		_Hit_point = rhs.getHitPoint();
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
	_Energy_point--;
	std::cout << "ClapTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (checkPointValue())
		return ;
	_Hit_point -= amount;
	std::cout << "ClapTrap " << getName() << " was attacked and took " << getAttackDamage() << " points of damage!" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (checkPointValue())
		return ;
	_Energy_point--;
	std::cout << "ClapTrap " << getName() << " repaired itself by " << amount << " hit points" << std::endl;
	_Hit_point += amount;
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



void	ClapTrap::setHitPoint(int value)
{
	_Hit_point = value;
}

void	ClapTrap::setEnergyPoint(int value)
{
	_Energy_point = value;
}

void	ClapTrap::setAttackDamage(int value)
{
	_Attack_damage = value;
}
