#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe()
{

}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	(void)rhs;
	return *this;
}

// std::ostream &			operator<<( std::ostream & o, PmergeMe const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/

bool	PmergeMe::FordJohnsonAlgorithm(int &argc, char **&argv)
{
	if (parseAndDispatchArgumentsInPairs(argc, argv))
        return (true);
	sortPairsItself();
   	sortPairsByFirstElement();
	moveFirstElementToResultAndSecondToSecondElement();
	reorganizeSecondElementWithJacobsthal();

	//std::deque<std::pair<int, int> >::iterator it = _pair.begin();
	std::deque<int>::iterator it1 = _result.begin();
	int i = 0;
	for (; it1 != _result.end(); it1++)
	{
		std::cout << "result : " <<_result[i] << std::endl;
		i++;
	}
	//performBinarySearchAndInsertForSecondElement();

	return (true);
}

int	checkOnlyDigit(char *&str)
{
	int i = 0;
	// stop at 10 because if arguments have more than 11 characters is overflow
	for (int i = 0; i != 10 && str[i]; i++)
	{
		if (isdigit(str[i]) == 0)
			return (ERROR_PARSING);
	}
	if (i == 10)
		return (ERROR_PARSING);
	return (0);
}

int	checkOverflowAndAssignNb(char *&str, int &nb)
{
	nb = atol(str);
	if (nb > 2147483647)
		return (ERROR_PARSING);
	return (0);
}


int	PmergeMe::parseAndDispatchArgumentsInPairs(int &argc, char **&argv)
{
	int	i = 1;
	int	first, second;

	while (i < argc)
	{
		if (argv[i + 1] == NULL)
		{
			if (checkOnlyDigit(argv[i])
				|| checkOverflowAndAssignNb(argv[i], first))
			{
				std::cout << "only positive integers are allowed." << std::endl;
				return (ERROR_PARSING);
			}
			_pair.push_back(std::pair<int, int>(first, -1));
		}
		else
		{
			if (checkOnlyDigit(argv[i]) || checkOnlyDigit(argv[i + 1])
				|| checkOverflowAndAssignNb(argv[i], first)
				|| checkOverflowAndAssignNb(argv[i + 1], second))
			{
				std::cout << "only positive integers are allowed." << std::endl;
				return (ERROR_PARSING);
			}
			_pair.push_back(std::pair<int, int>(first, second));
		}
		i += 2;
	}
	return (0);
}

int PmergeMe::alredySort()
{
	std::deque<std::pair<int, int> >::iterator it = _pair.begin();
	for (; it != _pair.end() - 1; it++)
	{
		if (it->first > (it + 1)->first)
			return (1);
	}
	return (0);
}

void	PmergeMe::sortPairsByFirstElement()
{
	std::deque<std::pair<int, int> >::iterator it = _pair.begin();
	for (; it != _pair.end() - 1; it++)
	{
		if (it->first > (it + 1)->first)
		{
			std::swap(it->first, (it + 1)->first);
			std::swap(it->second, (it + 1)->second);
		}
	}
	if (alredySort())
		sortPairsByFirstElement();

}

void PmergeMe::sortPairsItself()
{
	std::deque<std::pair<int, int> >::iterator it = _pair.begin();
	for (; it != _pair.end(); it++)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
}

void	PmergeMe::moveFirstElementToResultAndSecondToSecondElement()
{
	std::deque<std::pair<int, int> >::iterator it = _pair.begin();
	for (; it != _pair.end(); it++)
	{
		if (it == _pair.begin())
		{
			_result.push_back(it->second);
			_result.push_back(it->first);
		}
		else if (it->second != -1)
		{
			_result.push_back(it->first);
			_b_element.push_back(std::pair<int, int>(it->second, 0));
		}
		else
		{
			_b_element.push_back(std::pair<int, int>(it->first, 0));
			_b_element.push_back(std::pair<int, int>(it->first, 0));
		}
	}
}

size_t PmergeMe::jacobsthal(int n)
{
	if (n == 0 || n == 1)
		return (2);
	return (jacobsthal(n - 2) * 2 + jacobsthal(n - 1));
}

void PmergeMe::reorganizeSecondElementWithJacobsthal()
{
	std::deque<std::pair<int, int> >::iterator it = _b_element.begin();
	std::deque<std::pair<int, int> >::iterator it2 = _b_element.begin();

	int start = 0, end = 0, n = 0;
	
	for (; it != _b_element.end(); it++)
	{
		start += end;
		end = jacobsthal(n);
		if (end > _b_element.size())
			end = _b_element.size();
		while (start < end && it != _b_element.end())
		{
			std::swap(it2 + start, it2 + end);
			start--;
			end++;
			it++;
		}
		n++;
	}

	

}

void	PmergeMe::BinarySearch(size_t high, int value)
{
	size_t low = 0;
	int mid = 0;

	mid = low + (high - low) / 2;
	while (low <= high)
	{
		if (_result[mid] >= value)
		{
			if (mid == 0 || (_result[mid - 1] <= value))
			{
				_result.insert(_result.end() + mid, value);
				return ;
			}
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	_result.insert(_result.end(), value);

}

void	PmergeMe::performBinarySearchAndInsertForSecondElement()
{
	std::deque<std::pair<int, int> >::iterator it = _b_element.begin();
	size_t high;
	size_t j;

	for (int i = 0; it != _b_element.end(); i++)
	{
		high = jacobsthal(i);
		j = 0;
		while (j != high && it != _b_element.end())
		{
			BinarySearch(high, _b_element[i].first);
			j++;
		}
	}
}




/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */