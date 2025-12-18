#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string name, int grade )
	: name(name)
{
	checkGrade(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &other )
	: name(other.name), grade(other.grade)
{}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other )
{
	if (this != &other)
		grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{}



std::string Bureaucrat::getName()
{
	return (name);
}

int Bureaucrat::getGrade()
{
	return (grade);
}

void Bureaucrat::incrementGrade()
{
	checkGrade(grade - 1);
	grade--;
}

void Bureaucrat::decrementGrade()
{
	checkGrade(grade + 1);
	grade++;
}



class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
	const char* what() const noexcept override
	{
		return ("Grade too high\n");
	}
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
	const char* what() const noexcept override
	{
		return ("Grade too low\n");
	}
};



void Bureaucrat::checkGrade( int grade ) const
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}


void Bureaucrat::signForm( Form &form )
{
	try
	{
		form.beSigned(*this);
	}
	catch ( std::exception &e)
	{
		std::cerr << e.what();
	}
	if (form.getSignedStatus() == true)
	{
		std::cout	<< "Bureaucrat "
					<< name
					<< " signed "
					<< form.getName()
					<< "\n";
	}
	else
	{
		std::cout	<< "Bureaucrat "
		<< name
		<< " could not sign "
		<< form.getName()
		<< " because his grade was too low\n";
	}
}



std::ostream &operator<<( std::ostream &os, Bureaucrat &other )
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << "\n";
	return (os);
}