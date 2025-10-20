#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
	Brain *brain;

	public:
	Dog();
	Dog( std::string input );
	Dog( const Dog &other );
	Dog &operator=( const Dog &other );
	~Dog();

	void makeSound( void );
	std::string getIdea( void );
	void setIdea( std::string input );
	Animal* clone();
	void whoAmI();
};

#endif