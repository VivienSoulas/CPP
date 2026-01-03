#include "ShrubberyCreationForm.hpp"
#include <stdexcept>

Shrubbery::Shrubbery( std::string target )
	: Form(target, 145, 137)
{}

Shrubbery::Shrubbery( const Shrubbery &other )
	: Form(other)
{}

Shrubbery &Shrubbery::operator=( const Shrubbery &other )
{
	Form::operator=(other);
	return (*this);
}

Shrubbery::~Shrubbery()
{}

std::string Shrubbery::getName() const
{
	return (this->getFormName());
}


bool Shrubbery::execute(Bureaucrat const &executor) const
{
	try
	{
		if (!getSignedStatus())
			throw std::runtime_error("Form not signed\n");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
		return (false);
	}
	try
	{
	if (executor.getGrade() > getExecutionGrade())
		throw Form::GradeTooLowException();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what();
		return (false);
	}
	writeFile();
	return (true);
}

void Shrubbery::writeFile() const
{
	std::string file_name;

// open file in
	std::ifstream file_in("tree.txt");
	if (!file_in)
	{
		throw std::runtime_error("Failed to open file_in");
	}

// open file out
	file_name = this->getFormName() + "_shrubbery";
	std::ofstream file_out(file_name.c_str());

// copy file_in into file_out
	std::string read;
	while ( getline(file_in, read) )
	{
		file_out << read << "\n";
		if (!file_out)
			throw std::runtime_error("Failed to open output file: " + file_name);
	}
	file_in.close();
	file_out.close();
	std::cout 	<< "File "
				<< file_name
				<< " created and tree completed\n";
}