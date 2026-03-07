#include <iostream>
#include <vector>
#include "MutantStack.hpp"

// int main() {
//     MutantStack<int> mstack;
//     std::vector<int> vstack;

//     // Fill both containers
//     for (int i = 0; i < 10; ++i) {
//         mstack.push(i);
//         vstack.push_back(i);
//     }

//     // Iterate MutantStack
//     std::cout << "MutantStack iteration: ";
//     for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     // Iterate std::vector
//     std::cout << "Vector iteration: ";
//     for (std::vector<int>::iterator it = vstack.begin(); it != vstack.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << std::endl;

//     // Access last element
//     std::cout << "MutantStack top: " << mstack.top() << std::endl;
//     std::cout << "Vector back: " << vstack.back() << std::endl;

//     // Pop elements
//     mstack.pop();
//     vstack.pop_back();
//     std::cout << "MutantStack size after pop: " << mstack.size() << std::endl;
//     std::cout << "Vector size after pop: " << vstack.size() << std::endl;

//     return 0;
// }

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}
