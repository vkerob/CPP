#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<iostream>

class ClapTrap
{
private:

	std::string	_Name;
	int			_Hit_point;
	int			_Energy_point;
	int			_Attack_damage;
	
public:

	ClapTrap();
	ClapTrap(const ClapTrap &src);
	ClapTrap(std::string name);
	~ClapTrap();
	ClapTrap	&operator=(const ClapTrap &rhs);


	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	bool		checkPointValue(void);


	std::string	getName(void) const;
	int			getHitPoint(void) const;
	int			getEnergyPoint(void) const;
	int			getAttackDamage(void) const;

};




#endif