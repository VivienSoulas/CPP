#include "char.hpp"

Char::Char()
{}

Char::Char( const Char &other )
	: ScalarConverter(other)
{
	(void)other;
}

Char::~Char()
{}



bool Char::ft_parse( std::string input )
{
	if (input.empty() || input[0] == '-')
		return (false);
	if (input == "nan" || input == "-inf" || input == "+inf")
		return (false);
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

void Char::convert( std::string input )
{
	if (ft_parse(input) == false)
	{
		std::cout << "Char: Impossible\n";
		return ;
	}
	if (input.length() == 1 && isalpha(input[0]))
	{
		std::cout << "Char: " << input[0] << "\n";
		return ;
	}
	int overflow = 0;
	int dot = input.find('.');
	int n = ft_atoi(input, &overflow, dot);

	if (overflow == -1)
	{
		std::cout << "Char: Impossible\n";
		return ;
	}
	if (!isascii(n))
	{
		std::cout << "Char: Impossible\n";
		return ;
	}

	char value = static_cast<char>(n);
	if (!isprint(value))
	{
		std::cout << "Char: Non Printable\n";
		return ;
	}
	else
		std::cout << "Char: " << value << "\n";
}

int Char::ft_atoi( std::string input, int *overflow, int dot )
{
	long long n = 0;

	for (long unsigned int i = 0; i < input.length(); i++)
	{
		if ((int)i == dot)
			return (n);
		n = n * 10 + (input[i] - '0');
		if (n > __INT_MAX__)
			return (*overflow = -1);
	}
	return ((int)n);
}