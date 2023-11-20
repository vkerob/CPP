#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <iomanip>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define FLOAT_MAX 2147483647.0f
#define FLOAT_MIN -2147483648.0f
#define DOUBLE_MAX 2147483647.0
#define DOUBLE_MIN -2147483648.0

class ScalarConverter
{

	private:

		ScalarConverter();
		~ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		ScalarConverter &		operator=( ScalarConverter const & rhs );
		static int						checkPseudoLiteral(const std::string& str);
		static void					convertToChar(int nb_int, float nb_float, double nb_double, int type);
		static void					convertToInt(char c, float nb_float, double nb_double, int type);
		static void					convertToFloat(char c, int nb_int, double nb_double, int type);
		static void					convertToDouble(char c, int nb_int, float nb_float, int type);
		static void					CheckTypeAndError(const std::string& str);
		static void					ConvertAll(int type_nb, const std::string& str);
		static void					displayError( void );
		static int						checkChar(const std::string& str);

	public:

		static void	convert(const std::string& str);

};

//std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */