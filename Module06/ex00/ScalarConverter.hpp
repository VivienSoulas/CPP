#pragma once

#include <iostream>
#include <exception>

class ScalarConverter
{
	private:

	public:
	ScalarConverter();
	ScalarConverter( const ScalarConverter &other );
	ScalarConverter &operator=( const ScalarConverter &other ) = delete;
	virtual ~ScalarConverter();

	static void convert( std::string input );
};