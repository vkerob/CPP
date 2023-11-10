#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include<iostream>

class ClapTrap
{
	protected:

		std::string		_Name;
		unsigned int	_Hit_point;
		unsigned int	_Energy_point;
		unsigned int	_Attack_damage;
		
	public:

		ClapTrap();
		ClapTrap(const ClapTrap &src);
		ClapTrap(std::string name);
		virtual ~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &rhs);


		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		bool			checkEnergyPoint( void ) const;


		const std::string	&getName(void) const;
		int					getHitPoint(void) const;
		int					getEnergyPoint(void) const;
		int					getAttackDamage(void) const;


		virtual	void	setName(std::string str);
		void			setHitPoint(int value);
		void			setEnergyPoint(int value);
		void			setAttackDamage(int value);

};




#endif