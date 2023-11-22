#ifndef SED_HPP
# define SED_HPP

#include<iostream>
#include<string>

class Sed
{
	private:

		Sed();
		~Sed();

	public:

		static std::string	find_and_replace(std::string &line, const std::string &s1, const std::string &s2);
};




#endif