#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cout << "Error: argument are needed, or only one." << std::endl;
        return (1);
    }
    PmergeMe algo;
    
    if (algo.FordJohnsonAlgorithmDeque(argc, argv))
        return (1);
    if (algo.FordJohnsonAlgorithmVector(argc, argv))
        return (1);
}