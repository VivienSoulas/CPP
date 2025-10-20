#include "Cat.hpp"

Cat::Cat( std::string input )
	: Animal(input), type("Cat")
{
	std::cout	<< "Cat constructor called\n";
}

Cat::Cat( const Cat &other )
	: Animal(other), type(other.type)
{
	std::cout	<< "Cat copy constructor called\n";
}

Cat&Cat::operator=( const Cat &other )
{
	if (this != &other)
	{
		Animal::operator=(other);
		std::cout	<< "Cat operator overload called\n";
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout	<< "Cat destructor called\n";
}

void Cat::makeSound( void )
{
	std::cout << "Meowwww!\n";
}