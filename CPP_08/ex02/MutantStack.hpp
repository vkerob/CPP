#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	using std::stack<T, Container>::c;

	public:

		typedef typename Container::iterator iterator;
		iterator begin()
		{
			return c.begin();
		}
		iterator end()
		{
			return c.end();
		}
		MutantStack();
		~MutantStack();
		
};


#endif /* ***************************************************** MUTANTSTACK_H */