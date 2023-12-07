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



/*
** --------------------------------- METHODS ----------------------------------
*/

int	PmergeMe::check_only_numbers(char *str)
{
	for (unsigned long j = 0; j < strlen(str) -1; j++)
	{
		if (isdigit(str[j]) == 0)
		{
			std::cout << "Error: only numbers are allowed." << std::endl;
			return (ERROR_PARSING);
		}
	}
	return (0);
}

int	PmergeMe::check_overflow_assign_nb_and(char *str, long *nb)
{
	if (strlen(str) > 10)
	{
		std::cout << "Error: invalid argument." << std::endl;
		return (ERROR_PARSING);
	}
	*nb = atol(str);
	if (*nb >= 0 && *nb <= 2147483647)
		return (0);
	else
		return (ERROR_PARSING);
	return (0);
}



int	PmergeMe::pars_arg_and_push_in_pair_deque(int argc, char **argv)
{
	long a, b;
	int		i = 1;

	while (i < argc)
	{
		if (check_only_numbers(argv[i]) != 0)
			return (ERROR_PARSING);
		if (argv[i + 1] == NULL)
		{
			if (check_overflow_assign_nb_and(argv[i], &a) == 0)
				_unpaired_element_deque = a;
			else
				return (ERROR_PARSING);
		}
		else
		{
			if (check_only_numbers(argv[i]) || check_only_numbers(argv[i + 1]))
			return (ERROR_PARSING);
			if (check_overflow_assign_nb_and(argv[i], &a) == 0 && check_overflow_assign_nb_and(argv[i + 1], &b) == 0)
				_pair_deque.push_back(std::pair<int, int>(static_cast<int>(a), static_cast<int>(b)));
			else
				return (ERROR_PARSING);
		}
		i += 2;
	}
	return (0);
}

void	PmergeMe::push_larger_value_in_result()
{
	std::deque<std::pair<int, int> >::iterator it1 = _pair_deque.begin();

	for (; it1 != _pair_deque.end(); it1++)
	{
		if (it1 == _pair_deque.begin())
		{
			_result.push_back(it1->second);
			it1->second = -2;
		}
		if(it1->second != -2 && it1->second != -1)
			_b_element.push_back(std::pair<int, int>(it1->first, it1->second));
		if (it1->second != -1)
			_result.push_back(it1->first);
		else
			_b_element.push_back(std::pair<int, int>(it1->first, it1->first));
	}
	_pair_deque.erase(_pair_deque.begin());
}


void	PmergeMe::sort_each_pair()
{
	for (std::deque<std::pair<int, int> >::iterator it = _pair_deque.begin(); it != _pair_deque.end(); it++)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
}


int	PmergeMe::already_sort()
{
	std::deque<std::pair<int, int> >::iterator it1 = _pair_deque.begin();
	std::deque<std::pair<int, int> >::iterator it2 = _pair_deque.begin();
	it2++;
	for (; it2 != _pair_deque.end(); it2++)
	{
		if (it1->first > it2->first && it2->second != -1)
			return (0);
		it1++;
	}
	return (1);
}

int		PmergeMe::suite_de_lucas(int n)
{
	if (n == 0 || n == 1)
		return (2);
	else
		return (suite_de_lucas(n - 1) + suite_de_lucas(n - 2) * 2);
}

void	PmergeMe::pre_sort_value_of_larger_value()
{
	std::deque<std::pair<int, int> > tmp;
	std::deque<std::pair<int, int> >::iterator it = _b_element.begin();
	int start, target_position, n = 0;

	tmp.assign(_b_element.size(),std::pair<int, int>(-4, -4));
	start = 0;
	while(it != _b_element.end())
	{
		target_position = suite_de_lucas(n) + start;
		if (target_position > static_cast<int>(_b_element.size()))
			target_position = _b_element.size();
		while (target_position != start && it != _b_element.end())
		{
			tmp[target_position - 1] = *it;
			target_position--;
			it++;
		}
		start = suite_de_lucas(n);
		n++;
	}
	while(_b_element.empty() == 0)
		_b_element.pop_back();
	std::deque<std::pair<int, int> >::iterator it2 = tmp.begin();
	for(; it2 != tmp.end(); it2++)
		_b_element.push_back(*it2);
}

void	PmergeMe::sort_by_larger_value()
{

	std::deque<std::pair<int, int> >::iterator it1 = _pair_deque.begin();
	std::deque<std::pair<int, int> >::iterator it2 = _pair_deque.begin();
	it2++;
	for (; it2 != _pair_deque.end(); it2++)
	{
		if (it1->first > it2->first && it2->second != -1)
		{
			std::swap(it1->first, it2->first);
			std::swap(it1->second, it2->second);
		}
		it1++;
	}
	if (already_sort())
		return ;
	else
		sort_by_larger_value();
}

void	PmergeMe::binary_search(int end, int target)
{
	std::deque<int>::iterator it = _result.begin();
	
	int start = 0;

	while (start <= end)
	{
		int mid =  start + (end - start) / 2 -1;
		if (target == )
	}

}

void	PmergeMe::insert_b_element_in_result()
{
	std::deque<std::pair<int, int> >::iterator it = _b_element.begin();
	std::deque<std::pair<int, int> >::iterator it_end;

	for (; it != _b_element.end(); it++)
	{
		it_end = find_it__result();
		binary_search(it->first, it->second);
	}
}

void	PmergeMe::print()
{
	std::cout << "tmp" << std::endl;
	for (std::deque<std::pair<int, int> >::iterator it = _pair_deque.begin(); it != _pair_deque.end(); it++)
	{
		std::cout << "[" << it->first << ", " << it->second << "]" << std::endl;
	}
	std::cout << "_result" << std::endl;
	int i = 0;
	for (std::deque<int>::iterator it = _result.begin(); it != _result.end(); it++)
	{
		std::cout << i << " : " << *it << std::endl;
		i++;
	}
	std::cout << "_b_element" << std::endl;
	i = 0;
	for (std::deque<std::pair<int, int> >::iterator it = _b_element.begin(); it != _b_element.end(); it++)
	{
		std::cout << i << " : " << "[" << it->first << ", " << it->second << "]" << std::endl;
		i++;
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */