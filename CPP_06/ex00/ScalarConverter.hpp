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

		ScalarConverter &		operator=( ScalarConverter const & rhs );
		int						checkPseudoLiteral(const std::string& str);
		void					convertToChar(int nb_int, float nb_float, double nb_double, int type);
		void					convertToInt(char c, float nb_float, double nb_double, int type);
		void					convertToFloat(char c, int nb_int, double nb_double, int type);
		void					convertToDouble(char c, int nb_int, float nb_float, int type);
		void					CheckTypeAndError(const std::string& str);
		void					ConvertAll(int type_nb, const std::string& str);
		void					displayError( void );
		int						checkChar(const std::string& str);

	public:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();


		void	convert(const std::string& str);

};

//std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */