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

		static const float ERROR_CODE;

		std::stack<float> _stack;
		RPN &		operator=( RPN const & rhs );
		RPN( RPN const & src );

	public:

		RPN();
		~RPN();
		float	calculate(std::string &str);



};

#endif /* ************************************************************* RPN_H */