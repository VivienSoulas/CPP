#pragma once

#include <iostream>
#include <climits>
#include "ScalarConverter.hpp"

class Float : public ScalarConverter {
	private:

	public:
	Float();
	Float( const Float &other );
	Float &operator=( const Float &other ) = delete;
	~Float();

	static void convert( std::string input );
	static bool ft_parse( std::string input );
	static int ft_atoi( std::string input, int *overflow, size_t dot, int flag );
};