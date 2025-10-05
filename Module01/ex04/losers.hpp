#pragma once
#ifndef LOSERS_HPP
#define LOSERS_HPP

#include <iostream>
#include <string>
#include <fstream>

class Text
{
	private:
	std::string file_name;
	std::string new_file_name;
	std::string string1;
	std::string string2;

	public:
	Text( std::string filename, std::string string1, std::string string2 );
	~Text();
	std::string getFileName();
	std::string getNewFileName();
	std::string getString1();
	std::string getString2();
	std::string replacementFunction( std::string original );
	void Error( std::string string );
};

#endif