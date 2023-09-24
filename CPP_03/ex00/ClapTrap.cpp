
#include"ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("")
{
	std::cout << "ClapTrap created" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_Name = name;
	std::cout << "ClapTrap" << name << "created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	*this = src;
}


ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap" << this->getName() << "destroyed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	return (*this);
}

bool	ClapTrap::checkPoint(void)
{
	if (this->getEnergyPoint() <= 0)
		std::cout << "ClapTrap" << this->getName() << " doesn't have enough energy..." << std::endl;
	else if (this->getHitPoint() <= 0)
		std::cout << "ClapTrap" << this->getName() << " is dead, unfortunately he can't do anything..." << std::endl;
	if (this->getEnergyPoint() <= 0 || this->getHitPoint() <= 0)
		return (true);
	return (false);
}

void ClapTrap::attack(const std::string& target)
{
	if (this->checkPoint())
		return ;
	std::cout << "ClapTrap" << this->getName() << "attacks" << target << "causing" << this->getAttackDamage() << "points of damage!" << std::endl;
	//comment faire prendre des degats a la target ?
	this->_Energy_point--;

}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_Hit_point -= amount;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->checkPoint())
		return ;
	this->_Energy_point--;
}

std::string	ClapTrap::getName(void)
{
	return (this->_Name);
}

int	ClapTrap::getHitPoint(void)
{
	return (this->_Hit_point);
}

int	ClapTrap::getEnergyPoint(void)
{
	return (this->_Energy_point);
}

int	ClapTrap::getAttackDamage(void)
{
	return (this->_Attack_damage);
}