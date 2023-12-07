#include "RPN.hpp"
const long RPN::ERROR_CODE = 2147483648;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN()
{
}

RPN::RPN( const RPN & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

long	RPN::calculate(std::string &str)
{
	long				value, nb1, nb2;
	std::istringstream iss(str);
	std::string 		input;

	while (iss >> input)
	{
		// it's a digit
		if (isdigit(input[0]) && input.size() == 1)
		{
			value = atol(input.c_str());
			_stack.push(value);
		}
		// it's two characters
		else if (input.size() != 1)
		{
			std::cout << "Error: only single-digit numbers are allowed[0-9] or operator." << std::endl;
			return ERROR_CODE;
		}
		// it's an operator or error like 's' for example
		else
		{
			// there are not enough elements in stack
			if (_stack.size() < 2)
			{
				std::cout << "Error: not enough elements in stack for operation." << std::endl;
				return ERROR_CODE;
			}
			// there are at least two elements in the stack
			else
			{
				nb2 = _stack.top();
				_stack.pop();
				nb1 = _stack.top();
				_stack.pop();
			}
			if (input[0] == '+')
				value = nb1 + nb2;
			else if (input[0] == '-')
				value = nb1 - nb2;
			else if (input[0] == '*')
				value = nb1 * nb2;
			else if (input[0] == '/')
			{
				if (nb2 == 0)
				{
					std::cout << "Error: division by zero is impossible." << std::endl;
					return ERROR_CODE;
				}
				value = nb1 / nb2;
			}
			else
			{
				std::cout << "Error: unknown operator." << std::endl;
				return ERROR_CODE;
			}
			if (value > 2147483647 || value < -2147483648)
			{
				std::cout << "Error: overflow/underflow." << std::endl;
				return ERROR_CODE;
			}
			_stack.push(value);
		}
	}
	if (input.empty())
	{
		std::cout << "Error: empty string." << std::endl;
		return ERROR_CODE;
	}
	// in the end there is only the result
	else if (_stack.size() == 1)
		return (_stack.top());
	else
	{
		std::cout << "Error: operator missing, two numbers or more in stack at the end." << std::endl;
		return ERROR_CODE;
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */