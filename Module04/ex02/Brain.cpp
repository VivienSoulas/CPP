#include "Brain.hpp"

Brain::Brain()
{
	std::cout	<< "Brain constructor called\n";
}

Brain::Brain( const Brain &other )
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout	<< "Brain copy constructor called\n";
}

Brain &Brain::operator=( const Brain &other )
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
		std::cout	<< "Brain operator overload called\n";
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout	<< "Brain destructor called\n";
}