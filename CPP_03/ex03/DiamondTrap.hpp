#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include"FragTrap.hpp"
#include"ScavTrap.hpp"
#include<iostream>


class DiamondTrap : public FragTrap, public ScavTrap
{
	protected:

	private:

		std::string	_name;

	public:
		
		DiamondTrap();
		DiamondTrap(DiamondTrap &src);
		DiamondTrap(std::string name);
		~DiamondTrap();
		DiamondTrap	&operator=(DiamondTrap &rhs);

};

#endif