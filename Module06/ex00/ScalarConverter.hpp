#pragma once

#include <iostream>
#include <exception>

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