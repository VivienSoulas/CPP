#pragma once

#include <iostream>
#include "ScalarConverter.hpp"

class Char : public ScalarConverter {
	private:

	public:
	Char();
	Char( const Char &other );
	Char &operator=( const Char &other ) = delete;
	~Char();

	static void convert( std::string input );
	static bool ft_parse( std::string input );
	static int ft_atoi( std::string input, int *overflow, int dot );
};