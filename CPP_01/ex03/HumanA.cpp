#include"HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon), name(name)
{
	this->_name = name;
	this->weapon = weapon.getType();
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << weapon.getType() << std::endl;
}