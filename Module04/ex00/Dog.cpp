#include "Dog.hpp"

Dog::Dog( std::string input )
	: Animal(input), type("Dog")
{
	std::cout	<< "Dog constructor called\n";
}

Dog::Dog( const Dog &other )
	: Animal(other), type(other.type)
{
	std::cout	<< "Dog copy constructor called\n";
}

Dog&Dog::operator=( const Dog &other )
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout	<< "Dog operator overload called\n";
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout	<< "Dog destructor called\n";
}

void Dog::makeSound( void )
{
	std::cout << "Woof woof!\n";
}