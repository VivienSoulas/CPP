#pragma once

#include <iostream>
#include <deque>
#include <sstream>
#include <stack>

class RPN
{
	private:
	int result;
	std::string input;
	std::deque<std::string> tokens;
	std::stack<int> nums;

	public:
	RPN() = delete;
	RPN( const std::string& av );
	RPN( const RPN &other ) = delete;
	RPN &operator=( const RPN &other ) = delete;
	~RPN();
	
	bool parse();
	bool check();
	void switch_arithmetic( char c );
	int getResult();
};