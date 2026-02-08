#pragma once

#include <iostream>

template<typename T>
class Array
{
	public:
	Array();
	Array( unsigned int n );
	Array( const T &other );
	T &operator=( const T &other );
	T &operator[]( unsigned int index );
	~Array();

	private:
	T *data;
	unsigned int size;
};