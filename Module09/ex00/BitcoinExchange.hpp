#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <sstream>
#include <string>

#define DATABASE "data.csv"

class Bitcoin
{
	public:
		Bitcoin();
		Bitcoin( const std::string &av );
		Bitcoin( const Bitcoin &other );
		Bitcoin &operator=( const Bitcoin &other );
		~Bitcoin();

		void parse();
		bool validateDate();
		bool validateAmount();
		bool searchFile();
		void searchClosest();

	private:
		std::list<std::string> input;
		std::list<std::string> datas;
		std::string date;
		char dash = '-';
		char pipe = '|';
		char comma = ',';
		int year;
		int month;
		int day;
		float rate_float;
		float amount_float;
};