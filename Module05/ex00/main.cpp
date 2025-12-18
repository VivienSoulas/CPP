#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat one("Vivien", 1);

// trying a grade to high in constructor
	try
	{
		Bureaucrat two("Two", 1);
		std::cout << "trial " << two;
		Bureaucrat three("Three", 0);
		// shouldn't print because earlier action failed
		std::cout << "trial " << three;
		Bureaucrat four("Four", 5);
		std::cout << "trial " << four;
		// this is bypassed by the failling of the second Bureaucrat
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}

// trying a grade too high post incrementation
	try
	{
		one.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}

// trying a grade to low in constructor
	try
	{
		Bureaucrat five("Five", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}

	Bureaucrat six("Six", 150);
// trying a grade too low post decfrementation
	try
	{
		six.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}

// trying writting with operator overload
	std::cout << six;

	// this would result in core dumped because of exception not caught
	// Bureaucrat seven("Seven", 152);

	return (0);
}