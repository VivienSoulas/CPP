#include "Contact.hpp"
#include <cctype>

int	check_name(std::string* input)
{
	bool has_char = false;

	if (input->empty())
	{
		std::cout << "ERROR : Field cannot be empty" << std::endl;
		return (1);
	}
	for (int i = 0; i < (int)input->length(); i++)
	{
		if (!isspace((*input)[i]))
		{
			has_char = true;
			break ;
		}
	}
	if (has_char == false)
	{
		std::cout << "ERROR : Field cannot be empty" << std::endl;
		return (1);
	}
	for (int i = 0; i < (int)input->length(); i++)
	{
		if (!isalnum((*input)[i]) && (*input)[i] != '-' && (*input)[i] != ' ')
		{
			std::cout << "ERROR : Invalid character in field" << std::endl;
			return (1);
		}
	}
	return (0);
}

//check for empty field
int	check_input(std::string* input)
{
	if (input->empty())
	{
		std::cout << "ERROR : Field cannot be empty" << std::endl;
		return (1);
	}
	return (0);
}

// checks for numbers, length and starting +
int	check_number(std::string* input)
{
	int	i = 0;
	int	flag = 0;

	if (input->empty())
	{
		std::cout << "ERROR : Field cannot be empty" << std::endl;
		return (1);
	}
	if ((*input)[0] == '+')
	{
		flag = 1;
		i++;
	}
	while (i < (int)input->length())
	{
		if (!isdigit((*input)[i]))
		{
			std::cout << "ERROR : Phone number should be only numbers" << std::endl;
			return (1);
		}
		i++;
	}
	if ((flag && i != 12) || (!flag && i != 10))
	{
		std::cout << "ERROR : Invalid phone number length" << std::endl;
		return (1);
	}
	return (0);
}