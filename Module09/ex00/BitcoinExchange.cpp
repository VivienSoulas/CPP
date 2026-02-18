#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
{}

Bitcoin::Bitcoin( std::string av )
{
	std::ifstream file_in(av);
	if (!file_in)
		throw std::runtime_error("Failed to open file\n");
	std::string read;
	while (getline(file_in, read))
		lines.push_back(read);
}

Bitcoin::Bitcoin( const Bitcoin &other )
	: lines(other.lines)
{}

Bitcoin &Bitcoin::operator=( const Bitcoin &other )
{
	lines = other.lines;
	return (*this);
}

Bitcoin::~Bitcoin()
{}

void Bitcoin::parse()
{
	for (auto it = lines.begin(); it != lines.end(); ++it)
	{
		if (it == lines.begin())
			continue;
		validateDate();
		//validateAmount();
		//checkExchangeRate();
	}
}

bool Bitcoin::validateDate()
{
	int year;
	int month;
	int day;


	return (true);
}

//bool Bitcoin::validateAmount()
//{

//}

//void Bitcoin::checkExchangeRate()
//{

//}