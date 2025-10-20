#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
	std::string type;

	public:
	Animal();
	Animal( std::string input );
	Animal( const Animal &other );
	Animal &operator=( const Animal &other );
	virtual ~Animal();

	void makeSound( void );
	std::string getType( void );
};

#endif