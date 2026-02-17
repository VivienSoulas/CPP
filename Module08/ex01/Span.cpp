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
	int distance = 0;
	for (size_t i = 0; i < getLast(); i++)
	{
		for (size_t j = i + 1; j < getLast(); j++)
		{
			distance = std::abs((*data)[j] - (*data)[i]);
			if (distance < shortest)
				shortest = distance;
		}
	}
	return (shortest);
}

int Span::longestSpan()
{
	if (getLast() == 0 || getLast() == 1)
		throw ImpossibleSpan();
	int longest = INT_MIN;
	int distance = 0;
	for (size_t i = 0; i < getLast(); i++)
	{
		for (size_t j = i + 1; j < getLast(); j++)
		{
			distance = std::abs((*data)[j] - (*data)[i]);
			if (distance > longest)
				longest = distance;
		}
	}
	return (longest);
}

const char* Span::OutOfBoundException::what() const noexcept
{
	return ("Out of Bound");
}

const char* Span::ImpossibleSpan::what() const noexcept
{
	return ("Impossible Span");
}