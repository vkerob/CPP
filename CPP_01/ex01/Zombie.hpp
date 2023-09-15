#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include<iostream>

class  Zombie
{
private:

	std::string name;
	Zombie		*horde;
	
public:

	Zombie();
	~Zombie();
	void	announce( void );
	void	set_name(std::string name);

};

#endif

