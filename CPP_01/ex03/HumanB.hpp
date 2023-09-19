#ifndef HUMANB_HPP
# define HUMANB_HPP

#include"Weapon.hpp"
#include<iostream>

class HumanB
{
private:

	Weapon		*weapon;
	std::string	_name;

public:

	HumanB(std::string name);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon &weapon);
	
};

#endif