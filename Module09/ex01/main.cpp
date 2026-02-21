#include "RPN.hpp"

// "8 9 * 9 - 9 - 9 - 4 - 1 +" = 42
int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: invalid amount of arguments\n";
		return (1);
	}
	RPN rpn(av[1]);
	if (rpn.parse())
		std::cout << rpn.getResult() << "\n";
	else
	{
		std::cerr << "Error: input error \n";
		return (1);
	}
	return (0);
}