#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin()
	: year(0), month(0), day(0), rate_float(0.0), amount_float(0.0)
{}

Bitcoin::Bitcoin( const std::string &av )
	: year(0), month(0), day(0), rate_float(0.0), amount_float(0.0)
{
	std::ifstream file_in(av);
	if (!file_in)
		throw std::runtime_error("Failed to open file\n");
	std::string read;
	while (getline(file_in, read))
		input.push_back(read);
}

Bitcoin::Bitcoin( const Bitcoin &other )
	: input(other.input), datas(other.datas), date(other.date),
	  year(other.year), month(other.month), day(other.day),
	  rate_float(other.rate_float), amount_float(other.amount_float)
{}

Bitcoin &Bitcoin::operator=( const Bitcoin &other )
{
	if (this != &other)
	{
		input = other.input;
		datas = other.datas;
		date = other.date;
		year = other.year;
		month = other.month;
		day = other.day;
		rate_float = other.rate_float;
		amount_float = other.amount_float;
	}
	return (*this);
}

Bitcoin::~Bitcoin()
{}

void Bitcoin::parse()
{
	for (auto it = input.begin(); it != input.end(); ++it)
	{
		if (it == input.begin())
			continue;
		std::stringstream ss(*it);
		std::string temp;
		int i = 0;

		while (getline(ss, temp, pipe))
		{
			if (i == 0)
			{
				date = temp;
				date.pop_back(); // removes the trailing space
			}
			else if (i == 1)
				amount_float = atof(temp.c_str());	
			i++;
		}
		if (i == 2)
		{
			if (validateDate())
				if (validateAmount())
					if (!searchFile())
						searchClosest();
		}
		else
			std::cout << "Error: formating => " << *it << "\n";
	}
}

bool Bitcoin::validateDate()
{
	std::stringstream ss(date);
	std::string temp;
	int i = 0;
	while(getline(ss, temp, dash))
	{
		switch (i)
		{
			case 0:
				year = atoi(temp.c_str());
				break ;
			case 1:
				month = atoi(temp.c_str());
				break ;
			case 2:
				day = atoi(temp.c_str());
				break ;
			default:
				std::cout << "Formating error\n";
				return (false);
		}
		i++;
	}
	if (year < 2008 || year > 2026 || month <= 0 || month > 12 || day <= 0 || day > 31)
	{
		std::cout << "Error: bad input => " << year << "-" << month << "-" << day << "\n";
		return (false);
	}
	return (true);
}

bool Bitcoin::validateAmount()
{
	if (amount_float < 0)
	{
		std::cout << "Error: not a positive number.\n";
		return (false);
	}
	else if (amount_float > 1000)
	{
		std::cout << "Error: too large a number.\n";
		return (false);
	}
	return (true);
}


bool Bitcoin::searchFile()
{
	if (datas.empty())
	{
		std::ifstream fileToCheck(DATABASE);
		if (!fileToCheck)
			throw std::runtime_error("Failed to open file\n");
		std::string read;
		getline(fileToCheck, read); // skip header
		while (getline(fileToCheck, read))
		{
			datas.push_back(read);
		}
		if (datas.empty())
			throw std::runtime_error("Database file is empty\n");
	}
	for (const auto &read : datas)
	{
		std::string data_base_date = read.substr(0, read.find(comma));
		if (data_base_date == date)
		{
			std::stringstream ss(read);
			std::string temp;
			getline(ss, temp, comma); // skipping the date field
			getline(ss, temp, comma);
			rate_float = atof(temp.c_str());
			float total = rate_float * amount_float;
			std::cout << date << " => " << amount_float << " = " << total << "\n";
			return (true);
		}
	}
	return (false);
}

void Bitcoin::searchClosest()
{
	for (auto it = datas.rbegin(); it != datas.rend(); ++it)
	{
		std::stringstream ss(*it);
		std::string data_date;
		std::string data_rate;
		getline(ss, data_date, comma);
		getline(ss, data_rate, comma);
		if (data_date <= date)
		{
			rate_float = atof(data_rate.c_str());
			float total = rate_float * amount_float;
			std::cout << date << " => " << amount_float << " = " << total << "\n";
			return ;
		}
	}
	std::cout << "Error: no exchange rate available before " << date << "\n";
}