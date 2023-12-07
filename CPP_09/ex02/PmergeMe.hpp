#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstring>
# include <cstdlib>
# include <string>
# include <vector>
# include <deque>

# define ERROR_PARSING 1
# define LAST_PAIR -1
# define EMPTY_VALUE -2

class PmergeMe
{

	private:

		std::deque<std::pair<int, int> > _pair_deque;
		std::deque<int> _result;
		std::deque<std::pair<int, int> > _b_element;

		PmergeMe( PmergeMe const & src );
		PmergeMe &		operator=( PmergeMe const & rhs );

	public:

		PmergeMe();
		~PmergeMe();
		int		pars_arg_and_push_in_pair_deque(int argc, char **argv);
		void	sort_each_pair();
		int		check_only_numbers(char *str);
		int		check_overflow_assign_nb_and(char *str, long *nb);
		void	sort_by_larger_value();
		int		already_sort();
		void	print();
		void	push_larger_value_in_result();
		void	binary_search_and_insert_in_result();
		int		suite_de_lucas(int n);
		void	pre_sort_value_of_larger_value();
		void	binary_search(int end, int target);
		void	insert_b_element_in_result();

};

#endif /* ******************************************************** PMERGEME_H */