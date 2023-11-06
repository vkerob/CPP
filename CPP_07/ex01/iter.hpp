#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T1, typename T2, typename Fonction> 
void	iter(T1 x, T2 y, Fonction fonction)
{
	if (x == NULL)
		return ;
	for(int i = 0; i < y; i++)
	{
		if (x != NULL)
			fonction(x[i]);
	}
}


#endif