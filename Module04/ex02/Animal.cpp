#include "Animal.hpp"

Animal::Animal()
{
	TYPE = CatType;
	std::cout	<< "Animal constructor called\n";
}

Animal::Animal( std::string input )
	: type(input)
{
	std::cout	<< "Animal constructor called\n";
}

Animal::Animal( const Animal &other )
	: type(other.type)
{
	std::cout	<< "Animal copy constructor called\n";
}

Animal &Animal::operator=( const Animal &other )
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout	<< "Animal destructor called\n";
}

void Animal::makeSound( void )
{
	std::cout << "Some animal sound\n";
}

std::string Animal::getType( void )
{
	return (type);
}

void Animal::setLoggerType( LoggerType new_type )
{
	TYPE = new_type;
}

void Animal::setIdea( std::string input )
{
	(void)input;
}
std::string Animal::getIdea( void )
{
	return(NULL);
}

Animal* Animal::clone()
{
	return (NULL);
}

void Animal::whoAmI()
{}