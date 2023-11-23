#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template <typename T> 
void	swap(T &x, T &y)
{
	T tmp;

	tmp = x;
	x = y;
	y = tmp;

}

template <typename T> 
T	min(T x, T y)
{
	if (x == y)
		return (y);
	if (x < y)
		return (x);
	else
		return (y);
}

template <typename T> 
T	max(T x, T y)
{
	if (x == y)
		return (y);
	if (x > y)
		return (x);
	else
		return (y);
}

#endif /* ******************************************************** WHATEVER_H */