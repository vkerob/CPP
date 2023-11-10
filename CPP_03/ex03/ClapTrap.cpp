
#include"ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("default npc"), _Hit_point(10), _Energy_point(10), _Attack_damage(0)
{
	setHitPoint(100);
	std::cout << "ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Name(name), _Hit_point(10), _Energy_point(10), _Attack_damage(0)
{
	setHitPoint(100);
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

bool	ClapTrap::checkEnergyPoint( void ) const
{
	if (getEnergyPoint() == 0)
	{
		std::cout << "ClapTrap " << getName() << " doesn't have enough energy..." << std::endl;
		return (false);
	}
	return (true);
}

void ClapTrap::attack(const std::string& target)
{
	if (!checkEnergyPoint())
		return ;
	setEnergyPoint(getEnergyPoint() - 1);
	std::cout << "ClapTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!checkEnergyPoint())
		return ;
	if (getHitPoint() - amount < 0 && amount != 0)
		setHitPoint(0);
	else if (getHitPoint() == 0 && amount > 0)
	{
		std::cout << "ClapTrap " << getName() << " is dead, unfortunately he can't do anything..." << std::endl;
		return ;
	}
	else
	{
		setHitPoint(getHitPoint() - amount);
		std::cout << "ClapTrap " << getName() << " was attacked and took " << getAttackDamage() << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!checkEnergyPoint())
		return ;
	if (static_cast<long long int>(amount) + getHitPoint() <= 4294967295)
	{
		setEnergyPoint(getEnergyPoint() - 1);
		std::cout << "ClapTrap " << getName() << " repaired itself by " << amount << " hit points" << std::endl;
		setHitPoint(getHitPoint() + amount);
	}
	else
	{
		setEnergyPoint(getEnergyPoint() - 1);
		std::cout << "overflow" << std::endl;
	}
}

const std::string	&ClapTrap::getName(void) const
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
