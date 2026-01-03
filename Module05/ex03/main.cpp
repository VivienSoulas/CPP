#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	// Bureaucrat one("Vivien", 1);
	//Bureaucrat one("Vivien", 46);
	Bureaucrat one("Vivien", 45);
	// Bureaucrat one("Vivien", 150);
	Shrubbery formOne("Home");
	Robotomy formtwo("Form_two");
	Presidential formthree("Form_Three");

	Intern intern;
	// Form *created = intern.makeForm("Robotomy", "Home");
	// Form *created = intern.makeForm("", "Home");
	Form *created = intern.makeForm("Presidential", "Home");

	if (created)
	{
		one.signForm(*created);
		one.executeForm	(*created);
		delete(created);
	}
	std::cout	<< "\n\n";


	
	//no possible to create absract class
	//Form trial("Trial", 1, 150);

	one.signForm(formOne);
	formOne.execute(one);
std::cout << "\n";
	one.signForm(formtwo);
	formtwo.execute(one);
std::cout << "\n";
	one.signForm(formthree);
	formthree.execute(one);

std::cout << "\n" << "\n";
	one.executeForm(formOne);
std::cout << "\n";
	one.executeForm(formtwo);
std::cout << "\n";
	one.executeForm(formthree);
	return (0);
}