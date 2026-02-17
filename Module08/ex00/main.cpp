#include "easyfind.hpp"

int main()
{
	//std::array<int, 8> contain = {666,-78, 5, 8, 56, 0, 95, -66};
	std::vector<int> contain = {1, 8, 2, 5, 9, 6, 0, 666};
	int found = 0;
	int notfound = 0;

	try
	{
		found = ::easyfind(contain, 5);
		std::cout << found << "\n";
		notfound = ::easyfind(contain, 10);
		std::cout << notfound << "\n";
	}
	catch (const NotFoundException& e)
	{
		std::cout << e.what();
	}

	std::cout << "found: " << found << "\nnotfound: " << notfound << "\n";
	return (0);
}