#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
	: num_comp(0)
{}

PmergeMe::~PmergeMe()
{}

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
	// std::cout << "Numbers of Comparaison: " << num_comp / 2 << "\n";
}

template <typename T>
void PmergeMe::printDebug( const T &main, const T &pend )
{
	std::cout << "main: ";
	for (auto it : main)
	{
		std::cout << it << " ";
	}
	std::cout << "\nPend: ";
	for (auto it : pend)
	{
		std::cout << it << " ";
	}
	std::cout << "\n\n";
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

int PmergeMe::compare( int a, int b )
{
	num_comp++;
	return (a < b);
}

int PmergeMe::Jacobsthal( int i )
{
	if (i == 0)
		return (0);
	if (i == 1)
		return (1);
	return (round(pow(2, i + 1) - pow(-1, i + 1)) / 3);
}

bool PmergeMe::run( const std::vector<std::string> &args )
{
	auto start = std::chrono::high_resolution_clock::now();
	if (!checkInput(args))
		return (false);
	if (!checkDuplicate(input_vector))
		return (false);
	auto end = std::chrono::high_resolution_clock::now();
	elapsed_deque = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	elapsed_vector = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	printBefore(input_vector);
	mergeInsertSort(input_vector);
	mergeInsertSort(input_deque);
	printAfter(input_vector);
	PrintResult(input_vector);
	PrintResult(input_deque);
	return (true);
}

template <typename T>
void PmergeMe::mergeInsertSort(T& container)
{
	auto start = std::chrono::high_resolution_clock::now();
	sort(container);
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	typeid(T) == typeid(std::vector<int>) ? elapsed_vector += elapsed : elapsed_deque += elapsed;
}

template <typename T>
void PmergeMe::sort(T& container)
{
	T main, pend;

	for (auto it = container.begin() + 1; it < container.end(); it += 2)
	{
// putting bigger number of the pair in main and smaller in pend
		if (compare(*it, *(it - 1)))
		{
			main.push_back(*(it - 1));
			pend.push_back(*it);
		}
		else
		{
			main.push_back(*it);
			pend.push_back(*(it - 1));
		}
	}

// if odd, add the odd part in main
	if (container.size() % 2 != 0)
		main.push_back(container.back());

// recursion exit point
	if (main.size() <= 1)
	{
		insert(main, pend);
		container = main;
		return ;
	}

	if (DEBUG && (typeid(T) == typeid(std::vector<int>)))
		printDebug(main, pend);

// recursion
	sort(main);

	if (DEBUG && (typeid(T) == typeid(std::vector<int>)))
		printDebug(main, pend);

// pend insersion
	insert(main, pend);
	container = main;
}

template <typename T>
void PmergeMe::insert( T &main, T &pend )
{
// Generate Jacobsthal indexes
	std::vector<int> jacobsthal_indexes;
	int n =  pend.size();
	int i = 1;

	while (true)
	{
		int index = Jacobsthal(i);
		if (index >= n)
			break ;
		jacobsthal_indexes.push_back(index);
		i++;
	}

// Mark which indices have been used
	std::vector<bool> used(n, false);
	for (auto i : jacobsthal_indexes)
		used[i] = true;

// Insert pend elements at Jacobsthal indices
	for (int idx : jacobsthal_indexes)
	{
		int value = pend[idx];
		auto pos = std::lower_bound(main.begin(), main.end(), value,
			[this](int a, int b) { return compare(a, b); });
		main.insert(pos, value);
	}

// Insert remaining pend elements in order
	for (int idx = 0; idx < n; ++idx) {
		if (!used[idx]) {
			int value = pend[idx];
			auto pos = std::lower_bound(main.begin(), main.end(), value,
				[this](int a, int b) { return compare(a, b); });
			main.insert(pos, value);
		}
	}
}
