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


void	PmergeMe::printDeque(int &argc, char **&argv, clock_t start, clock_t end)
{
	std::deque<int>::iterator it1 = _result_deque.begin();
	int i = 1;
	std::cout << "before: ";
	while (i != argc)
	{
		std::cout << argv[i] << " ";
		i++;
	}
	i = 0;
	std::cout << std::endl << "after: ";
	for (; it1 != _result_deque.end(); it1++)
	{
		std::cout <<_result_deque[i] << " ";
		i++;
	}
	double time = static_cast<double>(end - start) * 1.0e6 / CLOCKS_PER_SEC;
	std::cout << std::endl << "Time to process a range of " 
	<<  _result_deque.size() << " elements with std::deque " << time << " us" << std::endl;
}

bool	PmergeMe::FordJohnsonAlgorithmDeque(int &argc, char **&argv)
{
	if (parseAndDispatchArgumentsInPairsDeque(argc, argv))
        return (true);
	clock_t start = clock();
	sortPairsItselfDeque();
    mergeSortDeque(0, _pair_deque.size() - 1);
	moveFirstElementToResultAndSecondToSecondElementDeque();
	reorganizeSecondElementWithJacobsthalDeque();
	performBinarySearchAndInsertForSecondElementDeque();
	clock_t end = clock();
	printDeque(argc, argv, start, end);
	return (false);
}

int	PmergeMe::checkOnlyDigit(char *&str)
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

int	PmergeMe::checkOverflowAndAssignNb(char *&str, int &nb)
{
	nb = atol(str);
	if (nb > 2147483647)
		return (ERROR_PARSING);
	return (0);
}

int	PmergeMe::parseAndDispatchArgumentsInPairsDeque(int &argc, char **&argv)
{
	int	i = 1;
	int	first, second;
	_unpaired_element_deque = -1;

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
			_unpaired_element_deque = first;
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
			_pair_deque.push_back(std::pair<int, int>(first, second));
		}
		i += 2;
	}
	return (0);
}

void PmergeMe::sortPairsItselfDeque()
{
	std::deque<std::pair<int, int> >::iterator it = _pair_deque.begin();
	for (; it != _pair_deque.end(); it++)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
}

void	PmergeMe::moveFirstElementToResultAndSecondToSecondElementDeque()
{
	std::deque<std::pair<int, int> >::iterator it = _pair_deque.begin();
	for (; it != _pair_deque.end(); it++)
	{
		if (it == _pair_deque.begin())
		{
			_result_deque.push_back(it->second);
			_result_deque.push_back(it->first);
			it->second = -2;
		}
		else
		{
			_result_deque.push_back(it->first);
			_b_element_deque.push_back(it->second);
		}
	}
}

size_t PmergeMe::jacobsthalDeque(int n)
{
	if (n == 0 || n == 1)
		return (2);
	return (jacobsthalDeque(n - 2) * 2 + jacobsthalDeque(n - 1));
}

void PmergeMe::mergeDeque(int left_idx, int mid, int right_idx)
{
    int i, j, k;
    int size_left_arr = mid - left_idx + 1;
    int size_right_arr = right_idx - mid;
    int left[size_left_arr], right[size_right_arr];

    for (i = 0; i < size_left_arr; i++)
        left[i] = _pair_deque[left_idx + i].first;
    for (j = 0; j < size_right_arr; j++)
        right[j] = _pair_deque[mid + 1 + j].first;

    i = 0;
    j = 0;
    k = left_idx;
    while (i < size_left_arr && j < size_right_arr) {
        if (left[i] <= right[j]) {
            _pair_deque[k].first = left[i];
            i++;
        }
        else {
            _pair_deque[k].first = right[j];
            j++;
        }
        k++;
    }

    while (i < size_left_arr) {
        _pair_deque[k].first = left[i];
        i++;
        k++;
    }
 
    while (j < size_right_arr) {
        _pair_deque[k].first = right[j];
        j++;
        k++;
    }
}
 
void PmergeMe::mergeSortDeque(int left_idx, int right_idx)
{

    if (left_idx < right_idx) {
        int mid = left_idx + (right_idx - left_idx) / 2;
 
        mergeSortDeque(left_idx, mid);
        mergeSortDeque(mid + 1, right_idx);
        mergeDeque(left_idx, mid, right_idx);
    }
}

void PmergeMe::reorganizeSecondElementWithJacobsthalDeque()
{
	std::deque<int>::iterator it = _b_element_deque.begin();
	std::deque<int>::iterator it2 = _b_element_deque.begin();

	size_t idx_start = 0, idx_end  = 0, start = 0, end = 0, n = 0;
	
	for (; it != _b_element_deque.end(); it++)
	{
		end += jacobsthalDeque(n) - 1;
		if (end >= _b_element_deque.size())
			end = _b_element_deque.size() - 1;
		idx_start = start;
		idx_end = end;
		while (idx_start < idx_end && it != _b_element_deque.end())
		{
			std::iter_swap(it2 + idx_start, it2 + idx_end);
			idx_start++;
			idx_end--;
			it++;
		}
		start = jacobsthalDeque(n);
		n++;
	}
	if (_unpaired_element_deque != -1)
	_b_element_deque.push_back(_unpaired_element_deque);
}

void	PmergeMe::BinarySearchInsertDeque(size_t high, int value)
{
	size_t low = 0;
	int mid = 0;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (_result_deque[mid] >= value)
		{
			if (mid == 0 || (_result_deque[mid - 1] <= value))
			{
				_result_deque.insert(_result_deque.begin() + mid, value);
				return ;
			}
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	_result_deque.insert(_result_deque.end(), value);
}

void	PmergeMe::performBinarySearchAndInsertForSecondElementDeque()
{
	std::deque<int>::iterator it = _b_element_deque.begin();
	//size_t high;

	for (int i = 0; it != _b_element_deque.end(); i++)
	{
		BinarySearchInsertDeque(_result_deque.size() - 1, *it);
		it++;
	}
}






























































void	PmergeMe::printVector(clock_t start, clock_t end)
{
	double time = static_cast<double>(end - start) * 1.0e6 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " 
	<<  _result_vector.size() << " elements with std::vector " << time << " us" << std::endl;
}

bool	PmergeMe::FordJohnsonAlgorithmVector(int &argc, char **&argv)
{
	if (parseAndDispatchArgumentsInPairsVector(argc, argv))
        return (true);
	clock_t start = clock();
	sortPairsItselfVector();
    mergeSortVector(0, _pair_vector.size() - 1);
	moveFirstElementToResultAndSecondToSecondElementVector();
	reorganizeSecondElementWithJacobsthalVector();
	performBinarySearchAndInsertForSecondElementVector();
	clock_t end = clock();
	printVector(start, end);
	return (false);
}

int	PmergeMe::parseAndDispatchArgumentsInPairsVector(int &argc, char **&argv)
{
	int	i = 1;
	int	first, second;
	_unpaired_element_vector = -1;

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
			_unpaired_element_vector = first;
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
			_pair_vector.push_back(std::pair<int, int>(first, second));
		}
		i += 2;
	}
	return (0);
}

void PmergeMe::sortPairsItselfVector()
{
	std::vector<std::pair<int, int> >::iterator it = _pair_vector.begin();
	for (; it != _pair_vector.end(); it++)
	{
		if (it->first < it->second)
			std::swap(it->first, it->second);
	}
}

void	PmergeMe::moveFirstElementToResultAndSecondToSecondElementVector()
{
	std::vector<std::pair<int, int> >::iterator it = _pair_vector.begin();
	for (; it != _pair_vector.end(); it++)
	{
		if (it == _pair_vector.begin())
		{
			_result_vector.push_back(it->second);
			_result_vector.push_back(it->first);
			it->second = -2;
		}
		else
		{
			_result_vector.push_back(it->first);
			_b_element_vector.push_back(it->second);
		}
	}
}

size_t PmergeMe::jacobsthalVector(int n)
{
	if (n == 0 || n == 1)
		return (2);
	return (jacobsthalVector(n - 2) * 2 + jacobsthalVector(n - 1));
}

void PmergeMe::mergeVector(int left_idx, int mid, int right_idx)
{
    int i, j, k;
    int size_left_arr = mid - left_idx + 1;
    int size_right_arr = right_idx - mid;
    int left[size_left_arr], right[size_right_arr];

    for (i = 0; i < size_left_arr; i++)
        left[i] = _pair_vector[left_idx + i].first;
    for (j = 0; j < size_right_arr; j++)
        right[j] = _pair_vector[mid + 1 + j].first;

    i = 0;
    j = 0;
    k = left_idx;
    while (i < size_left_arr && j < size_right_arr) {
        if (left[i] <= right[j]) {
            _pair_vector[k].first = left[i];
            i++;
        }
        else {
            _pair_vector[k].first = right[j];
            j++;
        }
        k++;
    }

    while (i < size_left_arr) {
        _pair_vector[k].first = left[i];
        i++;
        k++;
    }
 
    while (j < size_right_arr) {
        _pair_vector[k].first = right[j];
        j++;
        k++;
    }
}
 
void PmergeMe::mergeSortVector(int left_idx, int right_idx)
{

    if (left_idx < right_idx) {
        int mid = left_idx + (right_idx - left_idx) / 2;
 
        mergeSortVector(left_idx, mid);
        mergeSortVector(mid + 1, right_idx);
        mergeVector(left_idx, mid, right_idx);
    }
}

void PmergeMe::reorganizeSecondElementWithJacobsthalVector()
{
	std::vector<int>::iterator it = _b_element_vector.begin();
	std::vector<int>::iterator it2 = _b_element_vector.begin();

	size_t idx_start = 0, idx_end  = 0, start = 0, end = 0, n = 0;
	
	for (; it != _b_element_vector.end(); it++)
	{
		end += jacobsthalVector(n) - 1;
		if (end >= _b_element_vector.size())
			end = _b_element_vector.size() - 1;
		idx_start = start;
		idx_end = end;
		while (idx_start < idx_end && it != _b_element_vector.end())
		{
			std::iter_swap(it2 + idx_start, it2 + idx_end);
			idx_start++;
			idx_end--;
			it++;
		}
		start = jacobsthalDeque(n);
		n++;
	}
	if (_unpaired_element_vector != -1)
		_b_element_vector.push_back(_unpaired_element_vector);
}

void	PmergeMe::BinarySearchInsertVector(size_t high, int value)
{
	size_t low = 0;
	int mid = 0;

	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (_result_vector[mid] >= value)
		{
			if (mid == 0 || (_result_vector[mid - 1] <= value))
			{
				_result_vector.insert(_result_vector.begin() + mid, value);
				return ;
			}
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	_result_vector.insert(_result_vector.end(), value);
}

void	PmergeMe::performBinarySearchAndInsertForSecondElementVector()
{
	std::vector<int>::iterator it = _b_element_vector.begin();

	for (int i = 0; it != _b_element_vector.end(); i++)
	{
		BinarySearchInsertVector(_result_vector.size() - 1, *it);
		it++;
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */