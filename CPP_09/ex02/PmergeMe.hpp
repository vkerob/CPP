#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <deque>
# include <vector>
# include <cstdlib>
# include <algorithm>
# include <ctime>

# define ERROR_PARSING true

class PmergeMe
{

	private:

		//deque
		std::deque<std::pair<int, int> >_pair_deque;
		std::deque<int> _result_deque;
		std::deque<int> _b_element_deque;
		int 			_unpaired_element_deque;

		int		parseAndDispatchArgumentsInPairsDeque(int &argc, char **&argv);
		void	moveFirstElementToResultAndSecondToSecondElementDeque();
		void 	reorganizeSecondElementWithJacobsthalDeque();
		size_t	jacobsthalDeque(int n);
		void	performBinarySearchAndInsertForSecondElementDeque();
		void	BinarySearchInsertDeque(size_t high, int value);
		void 	sortPairsItselfDeque();
		void 	mergeSortDeque(int left_idx, int right_idx);
		void 	mergeDeque(int left_idx, int mid, int right_idx);
		void	printDeque(int &argc, char **&argv, clock_t start, clock_t end);



		//vector
		std::vector<std::pair<int, int> >_pair_vector;
		std::vector<int> _result_vector;
		std::vector<int> _b_element_vector;
		int 			_unpaired_element_vector;

		int		parseAndDispatchArgumentsInPairsVector(int &argc, char **&argv);
		void	moveFirstElementToResultAndSecondToSecondElementVector();
		void 	reorganizeSecondElementWithJacobsthalVector();
		size_t	jacobsthalVector(int n);
		void	performBinarySearchAndInsertForSecondElementVector();
		void	BinarySearchInsertVector(size_t high, int value);
		void 	sortPairsItselfVector();
		void 	mergeSortVector(int left_idx, int right_idx);
		void 	mergeVector(int left_idx, int mid, int right_idx);
		void	printVector(clock_t start, clock_t end);




		PmergeMe &		operator=( PmergeMe const & rhs );
		PmergeMe( PmergeMe const & src );

	public:

		PmergeMe();
		~PmergeMe();


		bool	FordJohnsonAlgorithmDeque(int &argc, char **&argv);
		bool	FordJohnsonAlgorithmVector(int &argc, char **&argv);

		int		checkOnlyDigit(char *&str);
		int		checkOverflowAndAssignNb(char *&str, int &nb);


};

// std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */