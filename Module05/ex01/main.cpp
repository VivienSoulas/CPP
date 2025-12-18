#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat one("Vivien", 150);
	Form formOne("Maths", 5, 50);

std::cout << "... Creating invalid Bureaucrat and Form to see the difference in error messages:\n";
	try
	{
		Bureaucrat two("Two", -1);
	}
	catch ( std::exception &e)
	{
		std::cerr << e.what();
	}
	try
	{
		Form one("Vivien", 3567, 9);
	}
	catch ( std::exception &e)
	{
		std::cerr << e.what();
	}

std::cout	<< "\n... Printing the FormOne informations:\n"
			<< formOne
			<< "\n... Trying to create invalid forms:\n";

// trying out of bound signing and execution values
	try
	{
		Form formTwo("Science", -5, 50);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}

	try
	{
		Form formThree("English", 5, 250);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
	}

std::cout << "\n... Trying to sign form Bureaucrat too low in grade:\n";
// trying to sign form with too low grade of bureaucrat
	try
	{
		one.signForm(formOne);
	}
	catch ( std::exception &e)
	{
		std::cerr << e.what();
	}

std::cout << "\n... Trying to sign form Bureaucrat with enough grade:\n";
//trying to sign with bureaucrat with enough grade
	Bureaucrat two("Tom", 1);
	try
	{
		two.signForm(formOne);
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what();
	}

std::cout << "\n... Printing new FormOne status to see change in signedForm";
	std::cout << "\n" << formOne;
	return (0);
}