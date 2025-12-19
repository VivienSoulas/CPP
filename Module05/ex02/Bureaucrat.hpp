#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
	private:
	std::string	const name;
	int			grade;
	void checkGrade( int grade ) const;

	
	public:
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat &other );
	~Bureaucrat();
	Bureaucrat &operator=( const Bureaucrat &other );

	std::string getName();
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	
	class GradeTooHighException;
	class GradeTooLowException;

	void signForm( Form &form );
};

std::ostream &operator<<( std::ostream &os, Bureaucrat &other );

#endif