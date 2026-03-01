#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: Not enough arguments\n";
		return (1);
	}

	std::vector<std::string> args(av + 1, av + ac);
	PmergeMe Merge;

	if (!Merge.run(args))
		return (1);

	return (0);
}