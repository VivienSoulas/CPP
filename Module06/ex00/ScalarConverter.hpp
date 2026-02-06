#pragma once

#include <iostream>
#include <climits>
#include <limits>
#include <iomanip>

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other) = delete;
	ScalarConverter &operator=(const ScalarConverter &other) = delete;
	~ScalarConverter();

	public:
	static void convert(std::string input);
};

bool ft_validation( std::string input );
double convert_double( std::string input, int *overflow );