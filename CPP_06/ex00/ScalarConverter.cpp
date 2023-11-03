#include "ScalarConverter.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScalarConverter::convertToChar(int nb_int, float nb_float, double nb_double, int type)
{
	char c;

	if (type == 1)
		c = static_cast<char>(nb_int);
	else if (type == 2)
		c = static_cast<char>(nb_float);
	else
		c = static_cast<char>(nb_double);
	if (type == 1)
	{
		if (nb_int > 20 && nb_int < 126)
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else if (type == 2)
	{
		if (nb_float > 20 && nb_float < 126)
			std::cout << "char: '" << c << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else if (type == 3)
	{
		if (nb_double > 20 && nb_double < 126)
			std::cout << "char: '" << c <<  "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	
}

void	ScalarConverter::convertToInt(char c, float nb_float, double nb_double, int type)
{
	int nb;

	if (type == 0)
		nb = static_cast<int>(c);
	else if (type == 2)
	{
		if (nb_float >= FLOAT_MAX || nb_float <= FLOAT_MIN)
		{
			std::cout << "int: overflow/underflow" << std::endl;
			return ;
		}
		nb = static_cast<int>(nb_float);
	}
	else
	{
		if (nb_double > DOUBLE_MAX || nb_double < DOUBLE_MIN)
		{
			std::cout << "int: overflow/underflow" << std::endl;
			return ;
		}
		nb = static_cast<int>(nb_double);
	}
	std::cout << "int: " << nb << std::endl;


}

void	ScalarConverter::convertToFloat(char c, int nb_int, double nb_double, int type)
{
	float nb;

	if (type == 0)
		nb = static_cast<float>(c);
	else if (type == 1)
		nb = static_cast<float>(nb_int);
	else 
		nb = static_cast<float>(nb_double);
	std::cout << "float: " << nb << "f" << std::endl;
}

void	ScalarConverter::convertToDouble(char c, int nb_int, float nb_float, int type)
{
	double nb;

	if (type == 0)
		nb = static_cast<double>(c);
	else if (type == 1)
		nb = static_cast<double>(nb_int);
	else
		nb = static_cast<double>(nb_float);
	std::cout << "double: " << nb << std::endl;
	
}

void	ScalarConverter::ConvertAll(int type_nb, const std::string& str)
{
	int		nb_int;
	float	nb_float;
	double	nb_double;
	if (type_nb == 0 && isdigit(str[0]))
	{
		nb_double = static_cast<double>(strtod(str.c_str(), 0));
		nb_int = atoi(str.c_str());
		if (nb_double > INT_MAX || nb_double < INT_MIN)
		{
			convertToChar(0, 0, 0, 1);
			std::cout << "int: overflow/underflow" << std::endl;
			std::cout << "float: overflow/underflow" << std::endl;
			std::cout << "double: overflow/underflow" << std::endl;
		}
		else
		{
			convertToChar(nb_int, 0, 0, 1);
			std::cout << "int: " << nb_int << std::endl;	
			convertToFloat(0, nb_int, 0, 1);
			convertToDouble(0, nb_int, 0, 1);
		}
	}
	else if (type_nb == 2)
	{
		nb_float = strtof(str.c_str(), 0);
		convertToChar(0, nb_float, 0, 2);
		convertToInt(0, nb_float, 0, 2);
		std::cout << "float: " << nb_float << "f" << std::endl;
		convertToDouble(0, 0, nb_float, 2);
	}
	else if (type_nb == 1)
	{
		nb_double = strtod(str.c_str(), 0);
		convertToChar(0, 0, nb_double, 3);
		convertToInt(0, 0, nb_double, 3);
		convertToFloat(0, 0, nb_double, 3);
		std::cout << "double: " << nb_double << std::endl;
	}
	else
		displayError();
}

void	ScalarConverter::displayError( void )
{
	std::cout << "char: impossible" << std::endl 
		<< "int: impossible" << std::endl
		<< "float: impossible"  << std::endl
		<< "double: impossible" << std::endl;
}

void	ScalarConverter::CheckTypeAndError(const std::string& str)
{
	int		nb_point = 0;
	int		type_nb = 0;
	int		error = 0;
	int		i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str.length() == 1)
			break;
		if (str[i] == '.' && ((i == 0 || i == static_cast<int>(str.length() - 1)) || ((str[0] == '-' || str[0] == '+') && i == 1)))
		{
			error = 1;
			break;
		}
		if (str[i] == '.')
			nb_point++;
		if (str[i] == 'f' && i == static_cast<int>(str.length() - 1) && nb_point == 1)
		{
			if (str[i - 1] != '.')
			{
				type_nb = 2;
				break;
			}
		}
		if (isdigit(str[i]) == 0 && str[i] != '.')
		{
			error = 1;
			break;
		}
		i++;
	}
	if (error == 1)
	{
		displayError();
		return ;
	}
	if (type_nb == 0 && nb_point == 1 && type_nb != 2)
		type_nb = 1;
	ConvertAll(type_nb, str);
}

int	ScalarConverter::checkPseudoLiteral(const std::string& str)
{
	double	int_double;
	float	int_float;

	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		int_double = strtod(str.c_str(), NULL);
		std::cout << "char: impossible" << std::endl 
		<< "int: impossible" << std::endl
		<< "float: " << static_cast<float>(int_double) << std::endl
		//strtod permet de passer d'une string a un float
		<< "double: " << strtod(str.c_str(), NULL) << "f" << std::endl;
		return (1);
	}
	if (str == "-inf" || str == "+inf" || str == "nan")
	{
		int_float = strtof(str.c_str(), NULL);
		std::cout << "char: impossible" << std::endl 
		<< "int: impossible" << std::endl
		//strtod permet de passer d'une string a un double
		<< "float: " << strtof(str.c_str(), NULL) << "f" << std::endl
		<< "double: " << static_cast<double>(int_float) << std::endl;
		return (1);
	}
	return (0);
}

int	ScalarConverter::checkChar(const std::string& str)
{
	char	c;

	if (str.length() == 3)
	{
		if (str[0] == '\'' && str[2] == '\'')
		{
			c = str[1];
			if (c > 20 && c < 126)
				std::cout << "char: '" << c << "'" << std::endl;
			else
				std::cout << "char: Non displayable" << std::endl;
			convertToInt(c, 0, 0, 0);
			convertToFloat(c, 0, 0, 0);
			convertToDouble(c, 0, 0, 0);
			return (1);
		}
	}
	return (0);
}

void	ScalarConverter::convert(const std::string& str)
{
	if (checkPseudoLiteral(str))
		return ;
	std::cout << std::fixed;
	if (checkChar(str))
		return ;
	CheckTypeAndError(str);


}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */