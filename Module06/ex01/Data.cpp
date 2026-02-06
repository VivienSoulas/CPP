#include "Data.hpp"

Data::Data( std::string input, int number_init  )
	: datas(1, input), number(number_init)
{}

Data::Data( const Data &other )
{
	datas = other.datas;
	number = other.number
}

Data &Data::operator=( const Data &other )
{
	if (this != &other)
	{
		datas = other.datas;
		number = other.number;
	}
	return (*this);
}

Data::~Data()
{}



void Data::getDatas()
{
	for (const auto &str : datas)
		std::cout << str << "\n";
}

void Data::getNum()
{
	std::cout << number << "\n";
}

void Data::whoAmI()
{
	getDatas();
	getNum();
}