#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
	std::string const name;
	bool isFormSigned;
	int	const signingGrade;
	int	const executionGrade;
	void checkGrade( int grade ) const;
	
	public:
	Form( std::string name, int sign, int exec );
	Form( const Form &other );
	Form &operator=( const Form &other );
	~Form();

	std::string getName() const;
	int getSigningGrade() const;
	int getExecutionGrade() const;
	bool getSignedStatus();

	class GradeTooHighException;
	class GradeTooLowException;

	void beSigned( Bureaucrat &bureaucrat );
	protected:
};

std::ostream &operator<<( std::ostream &os, Form &other );

#endif