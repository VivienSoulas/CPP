#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat one("Vivien", 146);
	Shrubbery formOne("Home");
	Robotomy formtwo("Home");
	Presidential formthree("Home");
	
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

	return (0);
}