
#include"ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("default npc"), _Hit_point(10), _Energy_point(10), _Attack_damage(0)
{
	std::cout << "ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _Hit_point(10), _Energy_point(10), _Attack_damage(0)
{
	this->_Name = name;
	std::cout << "ClapTrap " << name << " created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
}


ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->getName() << " destroyed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this != &rhs)
	{
		this->_Name = rhs.getName();
		this->_Attack_damage = rhs.getAttackDamage();
		this->_Energy_point = rhs.getEnergyPoint();
		this->_Hit_point = rhs.getHitPoint();
	}
	return (*this);
}

bool	ClapTrap::checkPointValue(void)
{
	if (this->getEnergyPoint() <= 0)
		std::cout << "ClapTrap " << this->getName() << " doesn't have enough energy..." << std::endl;
	else if (this->getHitPoint() <= 0)
		std::cout << "ClapTrap " << this->getName() << " is dead, unfortunately he can't do anything..." << std::endl;
	if (this->getEnergyPoint() <= 0 || this->getHitPoint() <= 0)
		return (true);
	return (false);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->checkPointValue())
		return ;
	this->_Energy_point--;
	std::cout << "ClapTrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->checkPointValue())
		return ;
	this->_Hit_point -= amount;
	std::cout << "ClapTrap " << this->getName() << " was attacked and took " << this->getAttackDamage() << " points of damage!" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->checkPointValue())
		return ;
	this->_Energy_point--;
	std::cout << "ClapTrap " << this->getName() << " repaired itself by " << amount << " hit points" << std::endl;
	this->_Hit_point += amount;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_Name);
}

int	ClapTrap::getHitPoint(void) const
{
	return (this->_Hit_point);
}

int	ClapTrap::getEnergyPoint(void) const
{
	return (this->_Energy_point);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (this->_Attack_damage);
}