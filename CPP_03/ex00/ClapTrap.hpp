#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<iostream>

class ClapTrap
{
	private:

		std::string		_Name;
		unsigned int	_Hit_point;
		unsigned int	_Energy_point;
		unsigned int	_Attack_damage;
		
	public:

		ClapTrap();
		ClapTrap(const ClapTrap &src);
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &rhs);


		void		attack(const std::string& target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		bool		checkEnergyPoint( void ) const;


		std::string	getName(void) const;
		unsigned int			getHitPoint(void) const;
		unsigned int			getEnergyPoint(void) const;
		unsigned int			getAttackDamage(void) const;


		void	setName(std::string str);
		void	setHitPoint(unsigned int value);
		void	setEnergyPoint(unsigned int value);
		void	setAttackDamage(unsigned int value);

};




#endif