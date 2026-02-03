#pragma once

#include <iostream>
#include <climits>
#include "ScalarConverter.hpp"

class Double : public ScalarConverter {
	private:

	public:
	Double();
	Double( const Double &other );
	Double &operator=( const Double &other ) = delete;
	~Double();

	static void convert( std::string input );
	static bool ft_parse( std::string input );
	static int ft_atoi( std::string input, int *overflow, size_t dot, int flag );
};