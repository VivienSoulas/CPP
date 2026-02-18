#include "BitcoinExchange.hpp"

int main(int ac, char**av)
{
	if (ac != 2)
	{
		std::cout << "Input file missing\n";
		return (1);
	}
	Bitcoin bitcoin(av[1]);
	bitcoin.parse();
	return (0);
}