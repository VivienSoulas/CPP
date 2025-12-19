#ifndef PERSIDENTIAL_HPP
#define PERSIDENTIAL_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Presidential : public Form
{
	private:
	void Pardon() const;

	public:
	Presidential( std::string target );
	Presidential( const Presidential &other );
	Presidential &operator=( const Presidential &other );
	~Presidential();

	std::string getName() const;
	void execute(Bureaucrat const &executor) const;
};

#endif