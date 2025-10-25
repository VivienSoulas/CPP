#include "Cure.hpp"

Cure::Cure()
{
	this->setLoggerType(CureType);
	this->setType();
}

Cure::Cure( std::string const & type )
	: AMateria(type)
{}

Cure::~Cure()
{}

Cure::Cure( const Cure &other )
	: AMateria(other)
{}

Cure &Cure::operator=( const Cure &other )
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout	<< "* heals "
				<< target
				<< "’s wounds *\n";
}

void Cure::setType()
{
	type = "cure";
}