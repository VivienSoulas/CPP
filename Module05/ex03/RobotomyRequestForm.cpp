#include "RobotomyRequestForm.hpp"
#include <random>
#include <stdexcept>

Robotomy::Robotomy( std::string target )
	: Form(target, 72, 45)
{}

Robotomy::Robotomy( const Robotomy &other )
	: Form(other)
{}

Robotomy &Robotomy::operator=( const Robotomy &other )
{
	Form::operator=(other);
	return (*this);
}

Robotomy::~Robotomy()
{}

std::string Robotomy::getName() const
{
	return (this->getFormName());
}



bool Robotomy::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!getSignedStatus())
			throw std::runtime_error("Form not signed\n");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
		return (false);
	}
	try
	{
	if (executor.getGrade() > getExecutionGrade())
		throw Form::GradeTooLowException();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
		return (false);
	}
	RobotomyExec();
	return (true);
}

void Robotomy::RobotomyExec() const
{
	std::cout	<<	"Bzzzzz Bzzzzz Drilling noises\n";
	std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist10(1,10);
	if (dist10(rng) > 5)
	{
		std::cout	<<	getName()
					<<	" has been robotomized\n";
	}
	else
		std::cout	<<	"Robotomy failed\n";
}