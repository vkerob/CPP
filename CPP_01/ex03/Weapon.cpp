#include"Weapon.hpp"

Weapon::Weapon(std::string weapon_name)
{
	this->_type = weapon_name;
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType(void) const
{
	return(_type);
}

void	Weapon::setType(std::string str)
{
	this->_type = str;
}
