#include "Dog.hpp"

Dog::Dog()
{
	brain = new Brain;
	brain->ideas[0] = "I have no ideas";
	std::cout	<< "Dog constructor called\n";
}

Dog::Dog( std::string input )
	: Animal(input)
{
	brain = new Brain;
	brain->ideas[0] = "I have no ideas";
	std::cout	<< "Dog constructor called\n";
}

Dog::Dog( const Dog &other )
	: Animal(other)
{
	brain = new Brain(*other.brain);
	std::cout	<< "Dog copy constructor called\n";
}

Dog&Dog::operator=( const Dog &other )
{
	if (this != &other)
	{
		delete(brain);
		brain = new Brain(*other.brain);
		Animal::operator=(other);
		std::cout	<< "Dog operator overload called\n";
	}
	return (*this);
}

Dog::~Dog()
{
	delete(brain);
	std::cout	<< "Dog destructor called\n";
}

void Dog::makeSound( void )
{
	std::cout << "Woof woof!\n";
}

std::string Dog::getIdea( void )
{
	return (brain->ideas[0]);
}

void Dog::setIdea( std::string input )
{
	brain->ideas[0] = input;
}

Animal* Dog::clone()
{
	return (new Dog(*this));
}

void Dog::whoAmI()
{
	std::cout	<< "I am a "
				<< this->getType()
				<< " who thinks: "
				<< 	this->getIdea()
				<< " and i make ";
	makeSound();
}