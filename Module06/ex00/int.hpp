#pragma once

#include <iostream>
#include <climits>
#include "ScalarConverter.hpp"

class Int : public ScalarConverter {
	private:

	public:
	Int();
	Int( const Int &other );
	Int &operator=( const Int &other ) = delete;
	~Int();

	static void convert( std::string input );
	static bool ft_parse( std::string input );
	static int ft_atoi( std::string input, int *overflow, int dot );
};