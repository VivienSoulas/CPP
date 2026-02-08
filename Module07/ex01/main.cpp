#include "iter.hpp"

int main( void )
{
// c style array:
	int arr[] = {1, 2, 3, 4, 5};
	char arrChar[] = {'a', 'b', 'c', 'd', 'e'};

	iter(arr, 5, printConst<int>);
	iter(arr, 5, increment<int>);
	iter(arrChar, 5, printConst<char>);
	iter(arrChar, 5, increment<char>);

// c++ style array
	std::array<int, 10> arrCPP = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<char> arrCPPVevtor{'a', 'b', 'c', 'd', 'e', 'f'};
	std::vector<float> floatVector = {0.0f, 0.5f, 5.0f, 66.5f};

	iter(arrCPP.data(), arrCPP.size(), printConst<int>);
	iter(arrCPP.data(), arrCPP.size(), increment<int>);
	iter(arrCPPVevtor.data(), arrCPPVevtor.size(), printConst<char>);
	iter(arrCPPVevtor.data(), arrCPPVevtor.size(), increment<char>);
	iter(floatVector.data(), floatVector.size(), printConst<float>);
	iter(floatVector.data(), floatVector.size(), increment<float>);
	return 0;
}
