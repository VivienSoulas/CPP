#include "AMateria.hpp"

AMateria::AMateria()
{}

AMateria::AMateria( std::string const & type )
	: type(type)
{}

AMateria::~AMateria()
{}

AMateria::AMateria( const AMateria &other )
	: type(other.type)
{}

AMateria &AMateria::operator=( const AMateria &other )
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

std::string const &AMateria::getType() const
{
	return (type);
}

void AMateria::setType()
{}

LoggerType AMateria::getLoggerType()
{
	return (logType);
}

void AMateria::setLoggerType( LoggerType new_type )
{
	logType = new_type;
}

AMateria *AMateria::clone() const
{
	return (NULL);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}