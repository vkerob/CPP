#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T1, typename T2, typename Fonction> 
void	iter(T1 tab, T2 length, Fonction fonction)
{
	int i = 0;

	if (tab == NULL || length < 0)
		return ;
	while (i < length)
	{
		fonction(tab[i]);
		i++;
	}
}


#endif