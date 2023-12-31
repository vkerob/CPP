#include<iostream>
#include<fstream>
#include"Sed.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "this program takes three parameters, (filename, s1, s2)" <<std::endl;
		return (1);
	}
	std::string s1 = argv[2];
	if (s1.empty())
	{
		std::cout << "s1 can not be empty" << std::endl;
		return (1);
	}
	std::ifstream infile(argv[1], std::ifstream::in);
	if (!infile.is_open())
	{
		std::cerr << "error while opening file for reading" << std::endl;
		return (1);
	}
	
	std::ofstream outfile((std::string(argv[1]) + ".replace").c_str());

	if (!outfile.is_open())
	{
		std::cerr << "error while opening file for reading" << std::endl;
		return (1);
	}
	std::string	line;
	while(std::getline(infile, line))
	{
		line = Sed::find_and_replace(line, argv[2], argv[3]);
		outfile << line << std::endl;
	}
	outfile.close();
	infile.close();
	return (0);
}