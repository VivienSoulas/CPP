#pragma once
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
	Dog( std::string input );
	Dog( const Dog &other );
	Dog &operator=( const Dog &other );
	~Dog();

	std::string type;
	void makeSound( void );
};

#endif