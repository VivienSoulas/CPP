#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <string>

class Bitcoin
{
	public:
	Bitcoin();
	Bitcoin( std::string av );
	Bitcoin( const Bitcoin &other );
	Bitcoin &operator=( const Bitcoin &other );
	~Bitcoin();

	void parse();
	bool validateDate();
	//bool validateAmount();
	//void checkExchangeRate();

	private:
	std::stringstream ss;
	std::list<std::string> lines;
	std::string date;
	std::string amount;
};