#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cstdlib>

class RPN
{

	private:

		static const long ERROR_CODE;

		std::stack<long> _stack;
		RPN &		operator=( RPN const & rhs );
		RPN( RPN const & src );

	public:

		RPN();
		~RPN();
		long	calculate(std::string &str);



};

#endif /* ************************************************************* RPN_H */