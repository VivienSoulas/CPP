#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

// forward declarations to avoid including Cat/Dog headers in this header
class Cat;
class Dog;

enum LoggerType
{
	CatType,
	DogType
};

class Animal
{
	private:

	protected:
	std::string type;
	LoggerType TYPE;

	public:
	Animal();
	Animal( std::string input );
	Animal( const Animal &other );
	Animal &operator=( const Animal &other );
	virtual ~Animal();

	void setLoggerType( LoggerType new_type );
	virtual void setIdea( std::string input );
	virtual std::string getIdea( void );
	virtual void makeSound( void );
	std::string getType( void );
	virtual Animal* clone();
	virtual void whoAmI() = 0;
};

#endif