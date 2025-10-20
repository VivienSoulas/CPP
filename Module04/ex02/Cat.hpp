#pragma once
#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
	Brain *brain;
	
	public:
	Cat();
	Cat( std::string input );
	Cat( const Cat &other );
	Cat &operator=( const Cat &other );
	~Cat();

	void makeSound( void );
	std::string getIdea( void );
	void setIdea( std::string input );
	Animal* clone();
	void whoAmI();
};

#endif