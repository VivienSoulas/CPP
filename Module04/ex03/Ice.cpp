#include "Ice.hpp"

Ice::Ice()
{
	this->setLoggerType(IceType);
	this->setType();
}

Ice::Ice( std::string const & type )
	: AMateria(type)
{}

Ice::~Ice()
{}

Ice::Ice( const Ice &other )
	: AMateria(other)
{}

Ice &Ice::operator=( const Ice &other )
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout	<< "* shoots an ice bolt at "
				<< target
				<< " *\n";
}

void Ice::setType()
{
	type = "ice";
}