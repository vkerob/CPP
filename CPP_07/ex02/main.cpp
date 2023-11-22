#include"Array.hpp"

int	main()
{
	std::string str = "test";
	Array<int> tab1(0);
	Array<std::string> tab2(2);

	tab1.setArray(1, 0);
	tab2.setArray(str, 0);
	tab2.setArray(str, 1);

	std::cout << tab1[0] << std::endl;
	std::cout << tab2[0] << std::endl;
	std::cout << tab2[1] << std::endl;


}