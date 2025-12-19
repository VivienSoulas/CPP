#ifndef ROBOTOMY_HPP
#define ROBOTOMY_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Robotomy : public Form
{
	private:
	void RobotomyExec() const;

	public:
	Robotomy( std::string target );
	Robotomy( const Robotomy &other );
	Robotomy &operator=( const Robotomy &other );
	~Robotomy();

	std::string getName() const;
	bool execute(Bureaucrat const &executor) const;
};

#endif