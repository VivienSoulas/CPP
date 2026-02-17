#pragma once

#include <iostream>
#include <exception>
#include <stack>
#include <deque>

template<typename T, typename container = std::deque<T>>
class MutantStack : public std::stack<T, container>
{
	public:
		MutantStack();
		MutantStack( const MutantStack &stack );
		MutantStack &operator=( const MutantStack &other );
		~MutantStack();

		// declaration of iterator as iterator for container (aka iterator from deque)
		typedef typename container::iterator iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"