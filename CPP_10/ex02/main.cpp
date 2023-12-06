#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error: argument are needed." << std::endl;
        return (1);
    }
    PmergeMe algo;
    
    if (algo.FordJohnsonAlgorithm(argc, argv))
        return (1);
}