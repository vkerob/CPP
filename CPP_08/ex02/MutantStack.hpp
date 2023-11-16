#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>

template<typename T, typename Container = std::deque<T>>

class MutantStack : std::stack<T, Container>
{


	public:

		Container::iterator iterator begin()
		{
			return std::begin(this->c);
		}
		Container::iterator iterator end()
		{
			return std::end(this->c);
		}

	private:

};


#endif /* ***************************************************** MUTANTSTACK_H */