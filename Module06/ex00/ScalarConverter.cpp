#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}



void ScalarConverter::convert( std::string input )
{
	if (!ft_validation(input))
	{
		std::cout << "Char: Impossible\nInt: Impossible\nFloat: Impossible\nDouble: Impossible\n";
		return ;
	}

	int overflow = 0;
	double value = convert_double(input, &overflow);
	if (overflow != 0)
	{
		std::cout << "Char: Impossible\nInt: Impossible\nFloat: Impossible\nDouble: Impossible";
		return ;
	}

// char conversion
	int intValue = static_cast<int>(value);
	if (intValue < 0 || intValue > 127)
		std::cout << "Char: Impossible\n";
	else
	{
		char c = static_cast<char>(intValue);
		if (!isprint(c))
			std::cout << "Char: Non printable\n";
		else
			std::cout << "Char: '" << c << "'\n";
	}

// int conversion
	if (input == "nan" || input == "nanf")
		std::cout << "Int: Impossible\n";
	else if (value < INT_MIN || value > INT_MAX)
		std::cout << "Int: Impossible\n";
	else
		std::cout << "Int: " << static_cast<int>(value) << std::endl;

// float conversion
	if (value == std::numeric_limits<double>::infinity())
		std::cout << "Float: +inff\n";
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "Float: -inff\n";
	else if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max())
		std::cout << "Float: Impossible\n";
	else
		std::cout << "Float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f\n";

// double conversion
	std::cout << "Double: "	<< static_cast<double>(value) << std::endl;
}