#include "Form.hpp"

Form::Form( std::string name, int sign, int exec )
	: name(name), isFormSigned(false), signingGrade(sign), executionGrade(exec)
{
	checkGrade(sign);
	checkGrade(exec);
}

Form::Form( const Form &other )
	: name(other.name), isFormSigned(other.isFormSigned), signingGrade(other.signingGrade), executionGrade(other.executionGrade)
{}

Form &Form::operator=( const Form &other )
{
	if (this != &other)
		isFormSigned = other.isFormSigned;
	return (*this);
}

Form::~Form()
{}



std::string Form::getName() const
{
	return (name);
}

int Form::getSigningGrade() const
{
	return (signingGrade);
}

int Form::getExecutionGrade() const
{
	return (executionGrade);
}

bool Form::getSignedStatus()
{
	return (isFormSigned);
}



class Form::GradeTooHighException : public std::exception
{
	public:
	const char* what() const noexcept override
	{
		return ("(form) Grade too High\n");
	}
};

class Form::GradeTooLowException : public std::exception
{
	public:
	const char* what() const noexcept override
	{
		return ("Grade too low\n");
	}
};



void Form::checkGrade( int grade ) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}



void Form::beSigned( Bureaucrat &bureaucrat )
{
	if (bureaucrat.getGrade() <= signingGrade)
		isFormSigned = true;
	else
		throw GradeTooLowException();
}



std::ostream &operator<<( std::ostream &os, Form &other )
{
	os	<<	"Name: " << other.getName()
		<<	"\nSigned status: " << (other.getSignedStatus() ? "Signed" : "Not signed")
		<<	"\nSigning grade: " << other.getSigningGrade()
		<<	"\nExecution grade: " << other.getExecutionGrade()
		<< "\n";
	return (os);
}