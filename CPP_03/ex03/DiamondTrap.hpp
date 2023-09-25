#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include"FragTrap.hpp"
#include"ScavTrap.hpp"
#include<iostream>


class DiamondTrap : public FragTrap, public ScavTrap
{

	private:

		std::string	_Name;

	public:
		
		DiamondTrap();
		DiamondTrap(DiamondTrap &src);
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap	&operator=(DiamondTrap &rhs);
		void whoAmI( void );

		std::string	getName(void) const;

};

#endif