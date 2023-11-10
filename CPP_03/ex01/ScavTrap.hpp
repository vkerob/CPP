#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include"ClapTrap.hpp"
#include<iostream>


class ScavTrap : public ClapTrap
{
	protected:

	private:
		
	bool	_keeper_mode;

	public:
		
		ScavTrap();
		ScavTrap(ScavTrap &src);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap	&operator=(ScavTrap &rhs);

		bool	getKeeperMode(void) const;

		void	setKeerperMode(bool mode);
		void	attack(const std::string& target);
		void	guardGate(void);


};


#endif
