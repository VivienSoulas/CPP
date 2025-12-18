#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
	std::string	name;
	int			grade;
	void checkGrade( int grade ) const;


	public:
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat &other );
	~Bureaucrat();
	Bureaucrat &operator=( const Bureaucrat &other );

	std::string getName();
	int getGrade();
	void incrementGrade();
	void decrementGrade();
	
	class GradeTooHighException;
	class GradeTooLowException;
};

std::ostream &operator<<( std::ostream& os, Bureaucrat &other );

#endif