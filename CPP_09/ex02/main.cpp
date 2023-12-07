#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Error: enter at least one argument" << std::endl;
		return (1);
	}
	try 
	{
		PmergeMe algo;
		if (algo.pars_arg_and_push_in_pair_deque(argc, argv))
			return (1);
		algo.sort_each_pair();
		algo.sort_by_larger_value();
		algo.push_larger_value_in_result();
		algo.pre_sort_value_of_larger_value();
		algo.print();
	}
	catch (const std::out_of_range &e)
	{
		std::cout << "overflow error." << e.what() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "general error." << e.what() << std::endl;
	}
}
