#include "easyfind.hpp"


int main()
{
	try
	{
		std::vector<int> tab(10, 10);
		tab[0] = 10;      
		std::vector<int>::iterator it = easyfind(tab, 1);
		std::cout << *it << std::endl ;
		std::cout << std::distance(tab.begin(), it) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}