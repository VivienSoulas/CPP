#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <exception>
#include <climits>
#include <random>
#include <algorithm>

class Span
{
	public:
	Span() = delete;
	Span ( unsigned int N );
	Span( const Span &other );
	Span &operator=( const Span &other );
	~Span();

	void addNumber( int toAdd );
	void addMultiple( std::vector<int>::iterator first, std::vector<int>::iterator last );
	int shortestSpan();
	int longestSpan();
	const unsigned int &getSize() const;
	const unsigned int &getLast() const;

	private:
	std::vector<int> *data;
	unsigned int size;
	unsigned int last;

	protected:
	class OutOfBoundException : public std::exception
	{
		public:
		virtual const char *what() const noexcept override;
	};

	class ImpossibleSpan : public std::exception
	{
		public:
		virtual const char *what() const noexcept override;
	};
};