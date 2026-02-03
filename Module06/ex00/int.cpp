#include "int.hpp"

Int::Int()
{}

Int::Int( const Int &other )
	: ScalarConverter(other)
{
	(void)other;
}

Int::~Int()
{}

bool Int::ft_parse( std::string input )
{
	if (input.empty())
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

void Int::convert( std::string input )
{
	if (ft_parse(input) == false)
	{
		std::cout << "Int: Impossible\n";
		return ;
	}
	if (input.length() == 1 && isalpha(input[0]))
	{
		std::cout << "Int: " << (int)input[0] << "\n";
		return ;
	}

	int dot = input.find('.');
	int overflow = 0;
	int n = ft_atoi(input, &overflow, dot);

	if (overflow == -1)
	{
		std::cout << "Int: Impossible\n";
		return ;
	}
	std::cout << "Int: " << n << "\n";
}

int Int::ft_atoi( std::string input, int *overflow, int dot )
{
	long long n = 0;
	int sign = 1;
	long unsigned int i = 0;

	if (input[0] == '-')
	{
		sign *= -1;
		i++;
	}
	while (i < input.length())
	{
		if ((int)i == dot)
			return (n * sign);
		n = n * 10 + input[i] - 48;
		i++;
		if (n > INT_MAX || n < INT_MIN)
			return (*overflow = -1);
	}
	return ((int)n * sign);
}