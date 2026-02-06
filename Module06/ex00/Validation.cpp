#include "ScalarConverter.hpp"

bool ft_validation( std::string input)
{
	if (input.empty())
		return (false);
	if (input == "nan" || input == "nanf" || input == "-inf" || input == "-inff" || input == "+inf" || input == "+inff")
		return (true);
	if (!isalnum(input[0]) && input[0] != '-') 
		return (false);
	if (input[0] == '-' && ((!input[1]) || !isdigit(input[1])))
		return (false);
	if (isalpha(input[0]))
		return (input.length() == 1);
	size_t i;
	isdigit(input[0]) ? i = 0 : i = 1;
	while (i < input.length())
	{
		if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
			return (false);
		i++;
	}
	size_t dot = input.find('.');
	if (dot != std::string::npos) // found
	{
		size_t sec_dot = input.find('.', dot + 1);
		if (sec_dot != std::string::npos)
			return (false);
		if (!input[dot + 1] || !isdigit(input[dot + 1]))
			return (false);
	}
	size_t f_letter = input.find('f');
	if (f_letter != std::string::npos)
	{
		if (f_letter != 0 && input[f_letter - 2] != '.')
			return (false);
		size_t double_f = input.find('f', f_letter + 1);
		if (double_f != std::string::npos)
			return (false);
	}	
	return (true);
}