#include"Weapon.hpp"

Weapon::Weapon(std::string weapon_name)
{
	this->type = weapon_name;
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType(void)
{
	return(type);
}

void	Weapon::setType(std::string str)
{
	this->type = str;
}
