#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
#include <algorithm>
#include <vector>

template <typename T>
typename T::iterator	easyfind(T &type, int i)
{
	typename T::iterator it;
	it = std::find(type.begin(), type.end(), i);
	if (it == type.end())
		throw std::logic_error("occurence not found");
	return (it);	
}

#endif