#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include"ClapTrap.hpp"
#include<iostream>


class FragTrap : virtual public ClapTrap
{
	
	private:

	public:
		
		FragTrap();
		FragTrap(FragTrap &src);
		FragTrap(std::string name);
		~FragTrap();
		FragTrap	&operator=(FragTrap &rhs);

		void		highFivesGuys(void);
};


#endif