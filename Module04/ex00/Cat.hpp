#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat( std::string input );
	Cat( const Cat &other );
	Cat &operator=( const Cat &other );
	~Cat();

	std::string type;
	void makeSound( void );
};

#endif