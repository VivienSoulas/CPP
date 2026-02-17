#include "Span.hpp"

int main()
{
	Span span = Span(15000);
	span.addNumber(15);
	span.addNumber(25);
	span.addNumber(35);
	span.addNumber(45);
	span.addNumber(55);
	std::cout << span.shortestSpan() << "\n";
	std::cout << span.longestSpan() << "\n";

	// random generation of numbers into numbers vector
	std::vector<int> numbers(14995);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(555555, 666666);
	std::generate(numbers.begin(), numbers.end(), [&]() { return dis(gen); });

	span.addMultiple(numbers.begin(), numbers.end());

	std::cout << "Shortest: " << span.shortestSpan() << "\n";
	std::cout << "Longest: " << span.longestSpan() << "\n";


	return 0;
}