#include "RPN.hpp"

RPN::RPN( const std::string& av )
{
	input = av;
	result = 0;
}

RPN::~RPN() {}

bool RPN::parse()
{
	if (input.empty())
		return (false);
	std::string word;
	std::stringstream ss(input);
	
	while (ss >> word)
	{
		if (word.length() > 1 || ((!isdigit(word[0]) &&(word[0] != '+' && word[0] != '-' && word[0] != '*' && word[0] != '/'))))
			return (false);
		tokens.push_back(word);
	}
	if (!check())
		return (false);
	return (true);
}

bool RPN::check()
{
	if (tokens.size() == 1)
	{
		if (!isdigit((*tokens.begin())[0]))
			return (false);
		result = std::stoi(*tokens.begin());
		return (true);
	}
	if (tokens.size() < 3)
		return (false);

	if (!isdigit((*tokens.begin())[0]))
		return (false);

	for (const auto &it : tokens)
	{
		if (isdigit(it.at(0)))
			nums.push(std::stoi(it));
		else
		{
			if (nums.size() < 2)
				return (false);
			switch_arithmetic(it.at(0));
		}
	}
	if (nums.size() != 1)
		return (false);
	return (true);
}

void RPN::switch_arithmetic( char c)
{
	int b = nums.top();
	nums.pop();
	int a = nums.top();
	nums.pop();
	switch (c)
	{
		case '+':
			result = a + b;
			nums.push(result);
			break ;
		case '-':
			result = a - b;
			nums.push(result);
			break ;
		case '*':
			result = a * b;
			nums.push(result);
			break ;
		case '/':
			if (b == 0)
				throw std::runtime_error("Division by 0 \n");
			result = a / b;
			nums.push(result);
			break ;
	}
}

int RPN::getResult()
{
	return (result);
}