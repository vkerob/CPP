#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
#include <cstdlib>
#include <cctype>

class ScalarConverter
{

	private:

		ScalarConverter &		operator=( ScalarConverter const & rhs );

	public:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		~ScalarConverter();


		void	convert(const std::string& str);
		int		checkPseudoLiteral(const std::string& str);
		void	convertToChar(int nb_int, float nb_float, double nb_double, int type);
		void	convertToInt(char c, float nb_float, double nb_double, int type);
		void	convertToFloat(char c, int nb_int, double nb_double, int type);
		void	convertToDouble(char c, int nb_int, float nb_float, int type);
		void	CheckTypeAndError(const std::string& str);
		void	ConvertAll(int type_nb, const std::string& str);
		void	displayError( void );

};

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i );

#endif /* ************************************************* SCALARCONVERTER_H */