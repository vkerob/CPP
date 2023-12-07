#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <map>
# include <regex.h>
# include <sstream>
# include <limits.h>
# include <cstdlib>

# define INVALID_PARS_DATE 1
# define DATE_TO_LOW 2
# define DATE_TO_HIGH 3


class BitcoinExchange
{

	private:

		std::map<std::string, float>  _data;
		static const std::string	PATTERN_INPUT;
		static const std::string	PATTERN_DATA;
		BitcoinExchange( BitcoinExchange const & src );
		BitcoinExchange &		operator=( BitcoinExchange const & rhs );
		int			open_file(const char *file, std::ifstream *infile);
		int			patern_check(std::string line, std::string pattern);
		int			check_date(std::string date);

	public:

		BitcoinExchange();
		~BitcoinExchange();

		
		int			store_data(const char *file);
		int			pars_data();
		int			read_pars_and_print_input(const char *file);


};


#endif /* ************************************************* BITCOINEXCHANGE_H */