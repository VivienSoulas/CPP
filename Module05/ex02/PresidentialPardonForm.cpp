#include "PresidentialPardonForm.hpp"


Presidential::Presidential( std::string target )
	: Form(target, 25, 5)
{}

Presidential::Presidential( const Presidential &other )
	: Form(other)
{}

Presidential &Presidential::operator=( const Presidential &other )
{
	Form::operator=(other);
	return (*this);
}

Presidential::~Presidential()
{}

std::string Presidential::getName() const
{
	return (this->getFormName());
}



bool Presidential::execute(Bureaucrat const &executor) const
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
	Pardon();
	return (true);
}

void Presidential::Pardon() const
{
	std::cout	<< getName()
				<< " has been pardoned by Zaphod Beeblebrox\n";
}