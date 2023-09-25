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
		ScavTrap(ScavTrap &src);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap	&operator=(ScavTrap &rhs);

		int		getKeeperMode(void) const;

		void	setKeerperMode(int mode);
		void	attack(const std::string& target);
		void	guardGate(void);

};


#endif
