#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include"ClapTrap.hpp"
#include<iostream>


class ScavTrap : virtual public ClapTrap
{

	private:

		bool	_keeper_mode;

	public:
		
		ScavTrap();
		ScavTrap(bool i);
		ScavTrap(ScavTrap &src);
		ScavTrap(std::string name);
		ScavTrap(std::string name, bool i);
		virtual ~ScavTrap();
		ScavTrap	&operator=(ScavTrap &rhs);

		bool	getKeeperMode(void) const;

		void	setKeeperMode(bool mode);
		void	attack(const std::string& target);
		void	guardGate(void);

};


#endif
