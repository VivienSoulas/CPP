#include "Cat.hpp"

Cat::Cat()
{
	brain = new Brain;
	brain->ideas[0] = "I have no ideas";
	std::cout	<< "Cat constructor called\n";
}

Cat::Cat( std::string input )
	: Animal(input)
{
	brain = new Brain;
	brain->ideas[0] = "I have no ideas";
	std::cout	<< "Cat constructor called\n";
}

Cat::Cat( const Cat &other )
	: Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout	<< "Cat copy constructor called\n";
}

Cat&Cat::operator=( const Cat &other )
{
	if (this != &other)
	{
		delete(brain);
		brain = new Brain(*other.brain);
		Animal::operator=(other);
		std::cout	<< "Cat operator overload called\n";
	}
	return (*this);
}

Cat::~Cat()
{
	delete(brain);
	std::cout	<< "Cat destructor called\n";
}

void Cat::makeSound( void )
{
	std::cout << "Meowwww!\n";
}

std::string Cat::getIdea( void )
{
	return (brain->ideas[0]);
}

void Cat::setIdea( std::string input )
{
	brain->ideas[0] = input;
}

Animal* Cat::clone()
{
	return (new Cat(*this));
}

void Cat::whoAmI()
{
	std::cout	<< "I am a "
				<< this->getType()
				<< " who thinks: "
				<< 	this->getIdea()
				<< " and i make ";
	makeSound();
}