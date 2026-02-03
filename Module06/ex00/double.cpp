#include "double.hpp"

Double::Double()
{}

Double::Double( const Double &other )
	: ScalarConverter(other)
{
	(void)other;
}

Double::~Double()
{}



bool Double::ft_parse( std::string input )
{
	if (input.empty())
		return (false);
	if (input == "nan" || input == "-inf" || input == "+inf")
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

void Double::convert( std::string input )
{
	if (ft_parse(input) == false)
	{
		std::cout << "Double: Impossible\n";
		return ;
	}
	if (input == "nan" || input == "-inf" || input == "+inf")
	{
		std::cout << "Double: "<< input << "\n";
		return ;
	}
	if (input.length() == 1 && isalpha(input[0]))
	{
		std::cout << "Double: " << (int)input[0] << ".0\n";
		return ;
	}

	int overflow = 0;
	size_t dot = input.find('.');
	if (dot == std::string::npos) // not found
	{
		int n = ft_atoi(input, &overflow, 0, 1);
		if (overflow == -1)
		{
			std::cout << "Double: Impossible\n";
			return ;
		}
		std::cout << "Double: " << n << ".0\n";
	}
	else
	{
		int n_prev = ft_atoi(input, &overflow, dot, 0);
		int n_aft = ft_atoi(input, &overflow, dot, 1);
		if (overflow == -1)
		{
			std::cout << "Double: Impossible\n";
			return ;
		}
		std::cout << "Double: " << n_prev << "." << n_aft << "\n";
	}
}

int Double::ft_atoi( std::string input, int *overflow, size_t dot, int flag )
{
	long long n = 0;
	int sign = 1;
	size_t i = 0;

	if (dot == 0 && flag == 1)
	{
		if (input[0] == '-')
		{
			sign *= -1;
			dot++;
		}
		while (dot < input.length())
		{
			n = n * 10 + input[dot] - 48;
			dot++;
			if (n > INT_MAX || n < INT_MIN)
				return (*overflow = -1);
		}
	}
	else if (dot != 0 && flag == 0)
	{
		if (input[0] == '-')
		{
			sign *= -1;
			i++;
		}
		while (i < dot)
		{
			n = n * 10 + input[i] - 48;
			i++;
			if (n > INT_MAX || n < INT_MIN)
				return (*overflow = -1);
		}
	}
	else
	{
		dot++;
		while (dot < input.length() - 1)
		{
			n = n * 10 + input[dot] - 48;
			dot++;
			if (n > INT_MAX || n < INT_MIN)
				return (*overflow = -1);
		}
	}
	return ((int)n * sign);
}