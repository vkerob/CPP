#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <list>
# include <algorithm>
# include <time.h>

class Span
{

	private:

		unsigned int 		_max_number;
		std::list<int>		_list;

	public:

		Span();
		Span(unsigned int N);
		Span( Span const & src );
		~Span();

		Span &		operator=( Span const & rhs );


		void	addNumber(int nb);
		void	addManyNumber(std::list<int> &list2);
		int		shortestSpan();
		int		longestSpan();


		std::list<int> &getList();

};

#endif /* ************************************************************ SPAN_H */