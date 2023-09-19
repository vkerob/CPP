#include"HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->weapon = NULL;
	this->_name = name;
}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	if (weapon->getType().empty())
		std::cout << _name << " have no weapon" << std::endl;
	std::cout << _name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}