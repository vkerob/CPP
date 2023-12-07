#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	BitcoinExchange btc;
	if (btc.store_data("data.csv"))
		return (1);
	if (btc.pars_data())
		return (1);
	if (btc.read_pars_and_print_input(argv[1]))
		return (1);
}
