#include "BitcoinExchange.hpp"

int main(int ac, char**av)
{
	if (ac != 2)
	{
		std::cout << "Input file missing\n";
		return (1);
	}
	
	// creates bitcoin object with linked listfor each lines of data.txt
	Bitcoin bitcoin(av[1]);

	// parse and validate data.txt (data | value), (year-month-day), (0 to 1000 positive or float)
	bitcoin.parse();

	// result calculation: value * exchange rate (if date doenst exist, use lowest closest date)
}