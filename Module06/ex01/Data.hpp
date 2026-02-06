#pragma once

#include <iostream>
#include <vector>

class Data
{
	private:
	std::vector<std::string> datas;
	int number;

	public:
	Data( std::string input, int number_init );
	Data( const Data &other );
	Data &operator=( const Data &other );
	~Data();

	void getDatas();
	void getNum();
	void whoAmI();
};