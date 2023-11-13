#include"FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << name << " created" << std::endl;
}

FragTrap::FragTrap(FragTrap &src) : ClapTrap(src)
{
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << getName() << " destroyed" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap &rhs)
{
	if (this != &rhs)
	{
		this->setHitPoint(rhs.getHitPoint());
		this->setEnergyPoint(rhs.getEnergyPoint());
		this->setAttackDamage(rhs.getAttackDamage());
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (getHitPoint() == 0)
	{
		std::cout << "FragTrap " << getName() << " is dead, unfortunately he can't do anything..." << std::endl;
		return ;
	}
	std::cout << "(" << getName() << ") YEAHHH!!! HIGHFIVESGUYS!!!" << std::endl;
}
