#include "WrongCat.hpp"

WrongCat::WrongCat( std::string input )
	: WrongAnimal(input), type("WrongCat")
{
	std::cout	<< "WrongCat constructor called\n";
}

WrongCat::WrongCat( const WrongCat &other )
	: WrongAnimal(other), type(other.type)
{
	std::cout	<< "WrongCat copy constructor called\n";
}

WrongCat&WrongCat::operator=( const WrongCat &other )
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
		std::cout	<< "WrongCat operator overload called\n";
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout	<< "WrongCat destructor called\n";
}

void WrongCat::makeSound( void )
{
	std::cout << "Wrong Meowwww!\n";
}