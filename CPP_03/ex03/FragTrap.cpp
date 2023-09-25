#include"FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	setHitPoint(100);
	setEnergyPoint(50);
	setHAttackDamage(20);
	std::cout << "FragTrap " << name << " created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setHitPoint(100);
	setEnergyPoint(50);
	setHAttackDamage(20);
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
	/*if (this != &rhs)
	{

	}*/
	(void)rhs;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "(" << getName() << ") YEAHHH!!! HIGHFIVESGUYS!!!" << std::endl;
}
