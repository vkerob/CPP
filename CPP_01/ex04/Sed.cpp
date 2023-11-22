#include"Sed.hpp"

Sed::Sed()
{

}

Sed::~Sed()
{

}

std::string	Sed::find_and_replace(std::string &line, const std::string &s1, const std::string &s2)
{
	std::string new_str;
	size_t	start = 0;
	size_t	index_str_found = line.find(s1);


	while(index_str_found != std::string::npos)
	{
		new_str += line.substr(start, index_str_found - start);
		new_str += s2;
		start = index_str_found + s1.length();
		index_str_found = line.find(s1, start);
	}
	new_str += line.substr(start);
	return (new_str);
}