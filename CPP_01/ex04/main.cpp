#include<iostream>
#include<fstream>

int	main(int argc, std::string *argv)
{
	if (argc != 3)
	{
		std::cout << "this program takes three parameters, (filename, s1, s2)" <<std::endl;
		return (1);
	}
	std::ifstream inputFile(argv[0]);

	if (!inputFile.is_open())
	{
		std::cerr << "error while opening file for reading" << std::endl;
		return (1);
	}
	
}