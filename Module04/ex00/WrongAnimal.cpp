#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( std::string input )
	: type(input)
{
	std::cout	<< "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal( const WrongAnimal &other )
	: type(other.type)
{
	std::cout	<< "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=( const WrongAnimal &other )
{
	if (this != &other)
	{
		type = other.type;
	}
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout	<< "WrongAnimal destructor called\n";
}

void WrongAnimal::makeSound( void )
{
	std::cout << "Some WrongAnimal sound\n";
}

std::string WrongAnimal::getType( void )
{
	return (type);
}