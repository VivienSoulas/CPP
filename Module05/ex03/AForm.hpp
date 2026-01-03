#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

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
	virtual ~Form();

	int getSigningGrade() const;
	int getExecutionGrade() const;
	bool getSignedStatus() const;
	void beSigned( Bureaucrat &bureaucrat );
	virtual std::string getName() const = 0;
	virtual bool execute(Bureaucrat const &executor) const = 0;
	
	protected:
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char* what() const noexcept override;
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char* what() const noexcept override;
	};
	std::string getFormName() const;
};

std::ostream &operator<<( std::ostream &os, const Form &other );

#endif