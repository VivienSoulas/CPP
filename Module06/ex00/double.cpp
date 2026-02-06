#include "ScalarConverter.hpp"

double convert_double( std::string input, int *overflow )
{
	if (input == "nan" || input == "nanf")
		return (std::numeric_limits<double>::quiet_NaN());
	if (input == "+inf" || input == "+inff")
		return (std::numeric_limits<double>::infinity());
	if (input == "-inf" || input == "-inff")
		return (-std::numeric_limits<double>::infinity());

	if (input.length() == 1 && !isdigit(input[0]))
		return (static_cast<double>(input[0]));

	if (input[input.length() - 1] == 'f')
		input = input.substr(0, input.length() - 1);


	double result = 0.0;
	double sign = 1.0;
	size_t i = 0;


	if (input[0] == '-')
	{
		sign *= -1;
		i++;
	}
	while (i < input.length() && isdigit(input[i]))
	{
		if ((result * 10 + (input[0] - '0')) > std::numeric_limits<double>::max())
			return (*overflow = -1);
		else
			result = result * 10 + (input[i] - '0');
		i++;
	}
	if (i < input.length() && input[i] == '.')
	{
		i++;
		double fraction = 0.1;
		while (i < input.length())
		{
			if ((result + (input[i] - '0') * fraction) > std::numeric_limits<double>::max())
				return (*overflow = -1);
			else
				result += (input[i] - '0') * fraction;
			fraction *= 0.1;
			i++;
		}
	}
	return (result * sign);
}
