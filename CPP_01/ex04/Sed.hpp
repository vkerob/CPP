#ifndef SED_HPP
# define SED_HPP

#include<iostream>

class Sed
{
private:
	
public:
	std::string	find_and_replace(std::string &line, const std::string &s1, const std::string &s2);
	Sed();
	~Sed();
};




#endif