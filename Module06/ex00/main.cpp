#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cout << "Not enought/too many arguments\n", 1);

	ScalarConverter::convert(av[1]);
	
	return (0);
}