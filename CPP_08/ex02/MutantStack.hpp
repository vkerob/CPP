#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:

		typedef typename Container::iterator iterator;
		iterator begin()
		{
			return (*this).c.begin();
		}
		iterator end()
		{
			return (*this).c.end();
		}

		MutantStack &	operator=( MutantStack const & rhs )
		{
			if (&rhs != this)
			{
				this->~MutantStack();
				new (this) MutantStack();
			}
			return (*this);
		}
		MutantStack() {}
		MutantStack( MutantStack const & src ) 
		{
			*this = src;
		}
		~MutantStack() {}


		
};


#endif /* ***************************************************** MUTANTSTACK_H */