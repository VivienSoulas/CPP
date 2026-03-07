#include "Span.hpp"

Span::Span( unsigned int N )
	: data(new std::vector<int>{}), size(N), last(0)
{
	data->reserve(N);
}

Span::Span( const Span &other )
	: data(other.data), size(other.size), last(other.last)
{}

Span &Span::operator=( const Span &other )
{
	if (this != &other)
	{
		data = other.data;
		size = other.size;
		last = other.last;
	}
	return (*this);
}

Span::~Span()
{
	delete data;
}

const unsigned int &Span::getSize() const
{
	return(size);
}

const unsigned int &Span::getLast() const
{
	return(last);
}

void Span::addNumber( int toAdd )
{
	if (getLast() == getSize())
		throw OutOfBoundException();
	data->push_back(toAdd);
	this->last++;
}

void Span::addMultiple( std::vector<int>::iterator first, std::vector<int>::iterator last )
{
	size_t count = std::distance(first, last);
	if (data->size() + count > getSize())
		throw OutOfBoundException();
	data->insert(data->end(), first, last);
	this->last += count;
}

int Span::shortestSpan()
{
	if (getLast() == 0 || getLast() == 1)
		throw ImpossibleSpan();
	int shortest = INT_MAX;
	std::sort(data->begin(), data->end());
	for (size_t i = 1; i < data->size(); i++)
	{
		int diff = (*data)[i] - (*data)[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (getLast() == 0 || getLast() == 1)
		throw ImpossibleSpan();
	int min = *std::min_element(data->begin(), data->end());
	int max = *std::max_element(data->begin(), data->end());
	return (max - min);
}

const char* Span::OutOfBoundException::what() const noexcept
{
	return ("Out of Bound");
}

const char* Span::ImpossibleSpan::what() const noexcept
{
	return ("Impossible Span");
}