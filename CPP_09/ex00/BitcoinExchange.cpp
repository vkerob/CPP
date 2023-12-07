#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::PATTERN_INPUT = "^[0-9]{4}-[0-9]{2}-[0-9]{2} \\| -?[0-9]+(\\.[0-9]+)?$";
const std::string BitcoinExchange::PATTERN_DATA = "^[0-9]{4}-[0-9]{2}-[0-9]{2},-?[0-9]+(\\.[0-9]+)?$";
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BitcoinExchange::~BitcoinExchange()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BitcoinExchange &				BitcoinExchange::operator=( BitcoinExchange const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

int	BitcoinExchange::patern_check(std::string line, std::string pattern)
{
	regex_t regex;
	int 	reti;

	reti = regcomp(&regex, pattern.c_str(), REG_EXTENDED);
	if (reti != 0)
	{
		std::cout << "regex compilation error." << std::endl;
		regfree(&regex);
		return (2);
	}
	reti = regexec(&regex, line.c_str(), 0, NULL, 0);
	if (reti == 0)
	{
		regfree(&regex);
		return(1);
	}
	else if (reti != REG_NOMATCH)
	{
		std::cerr << "regex execution error." << std::endl;
		regfree(&regex);
		return (2);
	}
	regfree(&regex);
	return (0);
}

int	BitcoinExchange::open_file(const char *file, std::ifstream *infile)
{
	infile->open(file, std::ifstream::in);
	if (!infile->is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	return (0);
}

int	BitcoinExchange::store_data(const char *file)
{
	std::ifstream infile;
	std::string line;
	int 		check = -1;
	float		value_btc;

	if (open_file(file, &infile))
		return (1);
	std::map<std::string, float>::iterator it = _data.begin();
	getline(infile, line);
	if (line != "date,exchange_rate")
	{
		std::cerr << "Error: bad header or missing(date,exchange_rate)" << std::endl;
		return (1);
	}
	while (getline(infile, line))
	{
		check = patern_check(line, PATTERN_DATA);
		std::istringstream iss (line.substr(11, line.size() - 11));
		iss >> value_btc;
		if (check == 1)
			_data[line.substr(0, 10)] = value_btc;
		else if(check == 0)
		{
			std::cerr << "Error: bad format(date,exchange_rate)" << std::endl;
			return (1);
		}
		else
			return (1);
		it++;
	}
	infile.close();
	return (0);
}

int	BitcoinExchange::read_pars_and_print_input(const char *file)
{
	std::ifstream infile;
	std::string line;
	int 		check = -1;
	float		nb_btc, value;


	std::map<std::string, float>::iterator itup;

	if (open_file(file, &infile))
		return (1);
	getline(infile, line);
	if (line != "date | value")
		std::cerr << "Error: bad header or missing(<date | value>)" << std::endl;
	while (getline(infile, line))
	{
		check = patern_check(line, PATTERN_INPUT);
		if (check == 0)
			std::cerr << "Error: bad format(<date | value>)" << std::endl;
		else if (check == 1)
		{
			std::istringstream iss (line.substr(13, line.size() - 13));
			iss >> nb_btc;
			check = check_date(line.substr(0, 10));
			if (check == INVALID_PARS_DATE)
				std::cerr << "Error: bad input => " + line.substr(0, 10) << std::endl;
			else if (check == DATE_TO_LOW)
				std::cerr << "Error: bitcoin does not exist at this date." << std::endl;
			else if (check == DATE_TO_HIGH)
				std::cerr << "Error: the date indicated is not yet visible." << std::endl;
			else if (nb_btc < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else if (nb_btc > 1000)
				std::cerr << "Error: too large a number." << std::endl;
			else
			{
				itup = _data.upper_bound(line.substr(0, 10));
				if (itup != _data.begin())
					itup--;
				if (itup == _data.end() && itup == _data.begin())
					std::cerr << "Error: no input in data." << std::endl;
				else
				{
					value = nb_btc * itup->second;
					std::cout << line.substr(0, 10) << " => " << nb_btc 
					<< " = " << value << std::endl;
				}
			}
		}
		else
			return (1);
	}
	infile.close();
	return (0);
}

int	BitcoinExchange::check_date(std::string date)
{
	int  year, mounth, day;
	
	year = atoi(date.substr(0, 4).c_str());
	mounth = atoi(date.substr(5, 7).c_str());
	day = atoi(date.substr(8, 10).c_str());
	
	if (mounth < 1 || mounth > 12 || day < 1)
		return (INVALID_PARS_DATE);
	if ((year == 2009 && mounth < 1 && day < 2) || year < 2009)
		return (DATE_TO_LOW);
	if (year > 2024)
		return (DATE_TO_HIGH);
	if (mounth == 2)
	{
		if ((year % 4 == 0 && day > 29) || (year % 4 != 0 && day > 28))
			return (INVALID_PARS_DATE);
		return (0);
	}
	if (mounth > 0 && mounth < 8
		&& ((mounth % 2 != 0 && day > 31) || (mounth % 2 == 0 && day > 30)))
		return (INVALID_PARS_DATE);
	else if (mounth > 7 && mounth < 13 
		&& ((mounth % 2 == 0 && day > 31) || (mounth % 2 != 0 && day > 30)))
		return (INVALID_PARS_DATE);
	return (0);
}

int	BitcoinExchange::pars_data()
{
	int check = 0;

	std::map<std::string, float>::iterator it = _data.begin();
	while (it != _data.end())
	{
		check = check_date(it->first);
		if (check == INVALID_PARS_DATE)
		{
			std::cerr << "Error: bad input => " << it->first << std::endl;
			return (1);
		}
		else if (check == DATE_TO_LOW)
		{
			std::cerr << "Error: bitcoin does not exist at this date." << std::endl;
			return (1);
		}
		else if (check == DATE_TO_HIGH)
		{
			std::cerr << "Error: the date indicated is not yet visible." << std::endl;
			return (1);
		}
		else if (it->second < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return (1);
		}
		it++;
	}
	return (0);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */