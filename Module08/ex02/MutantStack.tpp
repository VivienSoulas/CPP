#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack()
{}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other)
{
	*this = other;
}

template<typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=( const MutantStack &other )
{
	*this = other;
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{}

// "typename MutantStack<T, Container>::iterator" is declaring the return value as a iterator declared in MutantStack.hpp
template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return (this->c.end());
}