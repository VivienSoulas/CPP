#pragma once
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat( std::string input );
	WrongCat( const WrongCat &other );
	WrongCat &operator=( const WrongCat &other );
	~WrongCat();

	std::string type;
	void makeSound( void );
};

#endif