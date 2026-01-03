#include "AForm.hpp"
#include "Bureaucrat.hpp"

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



int Form::getSigningGrade() const
{
	return (signingGrade);
}

int Form::getExecutionGrade() const
{
	return (executionGrade);
}

bool Form::getSignedStatus() const
{
	return (isFormSigned);
}

std::string Form::getFormName() const
{
	return (name);
}



const char* Form::GradeTooHighException::what() const noexcept
{
	return ("(form) Grade too High\n");
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return ("(form) Grade too low\n");
}



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



std::ostream &operator<<( std::ostream &os, const Form &other )
{
	os	<<	"Name: " << other.getName()
		<<	"\nSigned status: " << (other.getSignedStatus() ? "Signed" : "Not signed")
		<<	"\nSigning grade: " << other.getSigningGrade()
		<<	"\nExecution grade: " << other.getExecutionGrade()
		<< "\n";
	return (os);
}