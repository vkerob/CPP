#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<iostream>

class ClapTrap
{
private:

	std::string	_Name;
	int			_Hit_point = 10;
	int			_Energy_point = 10;
	int			_Attack_damage = 0;
	
public:

	ClapTrap();
	ClapTrap(const ClapTrap &src);
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap	&operator=(const ClapTrap &rhs);
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	bool		checkPoint(void);
	std::string	getName(void);
	int			getHitPoint(void);
	int			getEnergyPoint(void);
	int			getAttackDamage(void);

};




#endif