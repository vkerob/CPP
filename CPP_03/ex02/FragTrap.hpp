#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include"ClapTrap.hpp"
#include<iostream>


class FragTrap : public ClapTrap
{
	protected:

	private:
		
	bool	_keeper_mode;

	public:
		
		FragTrap();
		FragTrap(FragTrap &src);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap	&operator=(FragTrap &rhs);

		void		highFivesGuys(void);
};


#endif