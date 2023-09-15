#include"HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->weapon = NULL;
	this->name = name;
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	if (weapon->getType().empty())
		std::cout << name << " have no weapon" << std::endl;
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}