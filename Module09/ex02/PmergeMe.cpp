#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::~PmergeMe()
{}

bool PmergeMe::run( const std::vector<std::string> &args )
{
	if (!checkInput(args))
		return (false);
	if (!checkDuplicate(input_vector))
		return (false);
	printBefore(input_vector);
	mergeInsertSort(input_vector);
	mergeInsertSort(input_deque);
	printAfter(input_vector);
	PrintResult(input_vector);
	PrintResult(input_deque);
	return (true);
}

bool PmergeMe::checkInput( const std::vector<std::string> &args )
{
	for (const auto &it : args)
	{
		std::stringstream ss(it);
		int num;
		char c;
		if (!(ss >> num) || (ss >> c))
		{
			std::cerr << "Error: Invalid argument: " << it << "\n";
			return (false);
		}
		if (num < 0)
		{
			std::cerr << "Error: Negative input: " << num << "\n";
			return (false);
		}
		input_vector.push_back(num);
		input_deque.push_back(num);
	}
	return (true);
}

template <typename T>
bool PmergeMe::checkDuplicate( const T &container)
{
	std::vector<int> temp = container;
	std::sort(temp.begin(), temp.end());
	if (std::adjacent_find(temp.begin(), temp.end()) != temp.end())
	{
		std::cerr << "Error: Duplicates found\n";
		return (false);
	}
	return (true);
}

template <typename T>
void PmergeMe::printBefore( const T &container )
{
	std::cout << "Before:\n";
	for (const auto &it : container)
		std::cout << it << " ";
	std::cout << "\n\n";
}

template <typename T>
void PmergeMe::printAfter( const T &container )
{
	std::cout << "After:\n";
	for (const auto &it : container)
		std::cout << it << " ";
	std::cout << "\n\n";
}

template <typename T>
void PmergeMe::PrintResult( const T &container )
{
	std::cout	<<	"Time to process a range of "
				<< container.size()
				<< " elements with std::";
	typeid(T) == typeid(std::vector<int>) ? std::cout << "vector: " << elapsed_vector.count() : std::cout << "deque: " << elapsed_deque.count();
	std::cout << " micro seconds\n";
}

template <typename T>
void PmergeMe::mergeInsertSort(T& container)
{
	auto start = std::chrono::high_resolution_clock::now();
	// merging logic here
	(void)container;
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	typeid(T) == typeid(std::vector<int>) ? elapsed_vector = elapsed : elapsed_deque = elapsed;
}