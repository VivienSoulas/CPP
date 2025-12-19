#ifndef SHRUBBERY_HPP
#define SHRUBBERY_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Shrubbery : public Form
{
	private:
	void writeFile() const;

	public:
	Shrubbery( std::string target );
	Shrubbery( const Shrubbery &other );
	Shrubbery &operator=( const Shrubbery &other );
	~Shrubbery();

	std::string getName() const;
	bool execute(Bureaucrat const &executor) const;
};

#endif