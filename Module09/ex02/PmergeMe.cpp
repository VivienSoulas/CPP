#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: num_comp(0), is_odd(false)
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
	//mergeInsertSort(input_deque);
	printAfter(input_vector);
	PrintResult(input_vector);
	//PrintResult(input_deque);
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

int PmergeMe::compare( int a, int b )
{
	num_comp++;
	return (a > b);
}

int PmergeMe::Jacobsthal( int i )
{
	if (i == 0)
		return (0);
	if (i == 1)
		return (1);
	return (round(pow(2, i + 1) - pow(-1, i + 1)) / 3);
}

template <typename T>
void PmergeMe::mergeInsertSort(T& container)
{
	auto start = std::chrono::high_resolution_clock::now();
	sort(container);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	typeid(T) == typeid(std::vector<int>) ? elapsed_vector = elapsed : elapsed_deque = elapsed;
}

template <typename T>
void PmergeMe::sort(T& container)
{
	static int order = 1;

	int pair_size = container.size() / order;
	if (pair_size < 2)
		return ;
	if ((pair_size % 2) == 1)
		is_odd = true;
	
std::cout << "pair_size = " << pair_size << "\n";
	for (auto it = container.begin(); it + 2 * pair_size <= container.end(); it += 2 * pair_size)
	{
		auto first_pair_end = it + pair_size - 1;
		auto second_pair_end = it + 2 * pair_size -1;
		std::cout << "pair compared are " << container[*first_pair_end] << " " << container[*second_pair_end] << "\n";
		if (compare(container[*first_pair_end], container[*second_pair_end]))
		{
			std::swap_ranges(it, it + pair_size, it + pair_size);
		}
	}

	std::cout << "NEW CONTAINER ORDER\n";
	for (auto &it : container)
		std::cout << it << " ";
	std::cout << "\n";

	order *= 2;
	sort(container);
}