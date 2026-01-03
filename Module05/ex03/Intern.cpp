#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern( const Intern &other )
{
	(void)other;
}

Intern &Intern::operator=( const Intern &other )
{
	(void)other;
	return (*this);
}

Intern::~Intern()
{}

static void printFormCreation(const std::string &formType)
{
	std::cout << "Intern creates " << formType << std::endl;
}

Form *Intern::makeForm( std::string form_name, std::string form_target )
{
	std::string formTypes[] = {"Shrubbery", "Robotomy", "Presidential"};
	int index = -1;
	
	for (int i = 0; i < 3; i++)
	{
		if (form_name == formTypes[i])
		{
			index = i;
			break;
		}
	}
	
	switch (index)
	{
		case 0:
		{
			printFormCreation("Shrubbery");
			return (new Shrubbery(form_target));
		}
		case 1:
		{
			printFormCreation("Robotomy");
			return (new Robotomy(form_target));
		}
		case 2:
		{
			printFormCreation("PresidentialPardon");
			return (new Presidential(form_target));
		}
		default:
		{
			std::cout << "Wrong form name" << std::endl;
			return (nullptr);
		}
	}
}