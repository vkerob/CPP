#include"Weapon.hpp"

Weapon::Weapon(std::string str)
{
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType(void)
{
	return(type);
}

void	Weapon::setType(Weapon weapon)
{
	type = weapon.getType();
}
