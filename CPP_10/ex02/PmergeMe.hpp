#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <deque>
# include <cstdlib>

# define ERROR_PARSING true

class PmergeMe
{

	private:

		std::deque<std::pair<int, int> >_pair;
		std::deque<int> _result;
		std::deque<std::pair<int, int> > _b_element;


		PmergeMe &		operator=( PmergeMe const & rhs );
		PmergeMe( PmergeMe const & src );

		
		int		parseAndDispatchArgumentsInPairs(int &argc, char **&argv);
		void	sortPairsByFirstElement();
		int		alredySort();
		void	moveFirstElementToResultAndSecondToSecondElement();
		void 	reorganizeSecondElementWithJacobsthal();
		size_t	jacobsthal(int n);
		void	performBinarySearchAndInsertForSecondElement();
		void	BinarySearch(size_t high, int value);
		void 	sortPairsItself();

	public:

		PmergeMe();
		~PmergeMe();


		bool	FordJohnsonAlgorithm(int &argc, char **&argv);


};

// std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */